#include "Student.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

inline void clearScreen()
{
#ifdef _WIN32
        system("pause");
        system("cls");
#else
        std::cout << "按Enter键继续...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        system("clear");
#endif
}
/**
 * @brief 对输入进行安全检查, 如果输入不是整数, 则提示用户重新输入
 * 
 * @param input 
 */
void safeInput(int &input) {
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效，请输入一个有效的整数: ";
    }
}
/**
 * @brief 对输入进行安全检查, 如果输入不是浮点数, 则提示用户重新输入
 * 
 * @param input 
 */
void safeInput(double &input) {
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效，请输入一个有效的数字: ";
    }
}
/**
 * @brief 添加学生, 如果学生id已存在, 则提示用户重新输入
 * 
 * @param students 
 */
void addStudent(std::unordered_map<int, Student> &students)
{   
    // 输入学生id, 如果学生id已存在, 则提示用户重新输入
    int id;
    std::string name;
    double score;
    std::cout << "请输入学生id: \n";
    safeInput(id);
    if (students.find(id) != students.end()) {
        std::cout << "该学生id已存在，请输入唯一的学生id。\n";
        return;
    }

    // 输入学生姓名和成绩
    std::cout << "请输入学生姓名: \n";
    std::cin >> name;
    std::cout << "请输入学生成绩: \n";
    safeInput(score);

    // 添加学生
    students[id] = Student(id, name, score);
    std::cout << "添加成功" << std::endl;

    // 清屏
    clearScreen();
}
/**
 * @brief 查找学生, 如果学生id不存在, 则提示用户重新输入
 * 
 * @param students 
 */
void searchStudent(const std::unordered_map<int, Student> &students)
{   
    // 如果学生列表为空, 则提示用户学生列表为空
    if (students.empty())
    {
        std::cout << "学生列表为空\n";
        clearScreen();
        return;
    }

    // 输入需要查找的学生id
    int id;
    std::cout << "请输入需要查找的学生id: \n";
    safeInput(id);

    // 查找学生
    auto it = students.find(id);
    if (it != students.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "未找到学生\n";
    }

    // 清屏
    clearScreen();
}
/**
 * @brief 修改学生, 根据学生id查找学生, 如果学生id不存在, 则提示用户重新输入
 * 
 * @param students 
 */
void modifyStudent(std::unordered_map<int, Student> &students)
{   
    // 如果学生列表为空, 则提示用户学生列表为空
    if (students.empty())
    {
        std::cout << "学生列表为空\n";
        clearScreen();
        return;
    }

    // 输入需要修改的学生id
    int id;
    std::cout << "请输入需要修改的学生id: \n";
    safeInput(id);
    auto it = students.find(id);

    // 修改学生信息
    if (it != students.end()) {
        std::string name;
        double score;       
        std::cout << "请输入学生姓名: \n";
        std::cin >> name;
        std::cout << "请输入学生成绩: \n";
        safeInput(score);
        it->second.setName(name);
        it->second.setScore(score);
        std::cout << "学生信息修改成功\n";
    } else {
        std::cout << "未找到学生\n";
    }

    // 清屏
    clearScreen();
}

/**
 * @brief 删除学生, 根据学生id查找学生, 如果学生id不存在, 则提示用户重新输入
 * 
 * @param students 
 */
void deleteStudent(std::unordered_map<int, Student> &students)
{   
    // 如果学生列表为空, 则提示用户学生列表为空
    if (students.empty())
    {
        std::cout << "学生列表为空\n";
        clearScreen();
        return;
    }

    // 输入需要删除的学生id
    int id;
    std::cout << "请输入需要删除的学生id: \n";
    safeInput(id);
    auto it = students.find(id);

    // 删除学生
    if (it != students.end()) {
        students.erase(it);
        std::cout << "学生删除成功\n";
    } else {
        std::cout << "未找到学生\n";
    }

    // 清屏
    clearScreen();
}

/**
 * @brief 打印学生列表
 * 
 * @param students 
 */
void printStudents(const std::unordered_map<int, Student> &students)
{    
    // 如果学生列表为空, 则提示用户学生列表为空
    if (students.empty())
    {
        std::cout << "学生列表为空\n";
        clearScreen();
        return;
    }
    
    // 将学生信息存储到vector中
    std::vector<Student> studentList;
    for (const auto& pair : students) {
        studentList.push_back(pair.second);
    }

    // 按照学生id降序排序
    std::sort(studentList.begin(), studentList.end(), std::greater<Student>());
    for (const auto& _student : studentList) {
        std::cout << _student << std::endl;
    }

    // 清屏
    clearScreen();
}

/**
 * @brief 主程序入口
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, const char** argv) {
    // 采用哈希表存储学生信息
    std::unordered_map<int, Student> students;

    // 主循环
    while (true)
    {   
        
        std::cout << "学生管理系统\n";
        std::cout << "1. 添加学生\n";
        std::cout << "2. 查找学生\n";
        std::cout << "3. 修改学生\n";
        std::cout << "4. 删除学生\n";
        std::cout << "5. 打印学生列表\n";
        std::cout << "0. 退出\n";

        // 选择操作
        int choice;
        safeInput(choice);
        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            searchStudent(students);
            break;
        case 3:
            modifyStudent(students);
            break;
        case 4:
            deleteStudent(students);
            break;
        case 5:
            printStudents(students);
            break;
        case 0:
            return 0;
        default:
            std::cout << "无效的选择，请重新输入。" << std::endl;
            break;
        }
    }
    return 0;
}
