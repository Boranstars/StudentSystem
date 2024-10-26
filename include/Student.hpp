#ifndef STUDENT_HPP
#define STUDENT_HPP
// #include <cmath>
#include <ostream>
#include <string>

/**
 * @brief 学生类
 * 
 */
class Student
{
public:

    Student() = default;
    Student(Student &&) = default;
    Student(const Student &) = default;
    Student &operator=(Student &&) = default;
    Student &operator=(const Student &) = default;
    ~Student() = default;
    /**
     * @brief 含参构造函数，初始化学生信息
     * 
     * @param id 
     * @param name 
     * @param score 
     */
    Student(int id, std::string name, double score): id(id), name(name), score(score) {};

    // 对外的getter和setter接口
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getScore() const { return score; }

    void setId(int id) { this->id = id; }
    void setName(std::string name) { this->name = name; }
    void setScore(double score) { this->score = score; }


    // 重载比较运算符, 用于排序
    bool operator<(const Student &rhs) const { return this->id < rhs.id; }
    bool operator>(const Student &rhs) const { return this->id > rhs.id; }
    bool operator==(const Student &rhs) const { return this->id == rhs.id; }


    // 重载输出运算符
    friend std::ostream &operator<<(std::ostream &os, const Student &student)
    {
        os << student.id << " " << student.name << " " << student.score;
        return os;
    }
private:
    int id = 0;
    std::string name = "";
    double score = 0.0;
    
};

#endif // !STUDENT_HPP