
# 学生管理系统

## 项目简介

学生管理系统是一个简单的基于C++的控制台应用程序，旨在帮助用户管理学生信息。该系统采用哈希表存储学生数据，支持添加、查找、修改、删除学生信息以及打印学生列表等功能。学生信息包括学生ID、姓名和成绩，用户可以通过命令行交互操作管理学生数据。

## 目录结构

```
├── CMakeLists.txt         # CMake构建文件
├── include
│   └── Student.hpp        # 学生类定义
├── README.md              # 项目说明文件
└── src
    ├── main.cpp           # 主程序入口
    └── testStudent.cpp    # 测试文件（未实现）
```

## 依赖项

- CMake 3.12或更高版本
- C++编译器，支持C++17标准

## 编译与运行

1. **编译项目**

   首先确保已经安装CMake和C++编译器。在项目根目录下运行以下命令：

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

   执行上述命令后，将生成名为`StudentSystem`的可执行文件。

2. **运行程序**

   进入`build`目录后，运行生成的可执行文件：

   ```bash
   ./StudentSystem
   ```

## 功能说明

程序提供以下功能，通过控制台菜单进行选择：

1. **添加学生**：输入学生ID、姓名和成绩。如果ID已存在，则提示用户重新输入。
2. **查找学生**：根据输入的学生ID查找学生信息。如果未找到，提示用户重新输入。
3. **修改学生**：根据输入的学生ID修改该学生的姓名和成绩。如果未找到该学生，提示用户重新输入。
4. **删除学生**：根据输入的学生ID删除学生信息。如果未找到该学生，提示用户重新输入。
5. **打印学生列表**：按学生ID降序打印所有学生的信息。
6. **退出程序**：输入`0`退出程序。

## 示例

运行程序后，用户会看到以下菜单：

```
学生管理系统
1. 添加学生
2. 查找学生
3. 修改学生
4. 删除学生
5. 打印学生列表
0. 退出
```

用户可以根据提示输入相应的选项，并按照提示完成操作。

## 代码结构

- **Student类**：定义在`include/Student.hpp`中，用于表示学生信息，包含学生ID、姓名和成绩，以及用于排序和输出的运算符重载。
- **main.cpp**：包含主程序逻辑，定义了学生管理系统的所有操作函数，包括添加、查找、修改、删除和打印学生信息。

## 注意事项

- 学生ID应为唯一值，若输入已存在的ID，程序将提示重新输入。
- 若学生列表为空时尝试查找、修改或删除学生信息，系统将提示列表为空。
- 程序内包含清屏函数，根据操作系统选择不同的清屏命令。

## 待办事项

- [ ] 添加单元测试（`testStudent.cpp`）。
- [ ] 支持更多学生信息字段，如年龄、班级等。
- [ ] 增加数据持久化功能，使得学生数据在程序重启后不丢失。

## 许可证

本项目使用 [MIT 许可证](LICENSE) 进行许可。

---

MIT License

Copyright (c) 2024 [Boranstars]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
