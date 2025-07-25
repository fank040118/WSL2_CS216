# Shell 脚本编程核心笔记

本文档整合了 Shell 脚本编程的基础知识、核心概念和常用技巧，旨在为初学者提供一份清晰、全面的学习指南。

---

## 一、Shell 脚本入门

### 1.1 什么是 Shell 脚本？

Shell 脚本 (Shell Script) 是一个包含一系列命令的文本文件。它允许你将终端中手动、依次输入的命令集合起来，通过一次性执行脚本来自动化完成复杂的任务。

### 1.2 创建与执行脚本

**1. 创建脚本文件**

脚本文件通常以 `.sh` 结尾。第一行需要使用 `#!` (称为 Shebang 或 Hashbang) 来指定用于执行该脚本的解释器路径。

**`hello.sh` 示例:**
```bash
#!/bin/bash

# 这是一条注释
echo "Hello, World!"
```

**2. 赋予执行权限**

在执行脚本之前，必须为其添加执行权限。
```bash
# u+x 表示为当前用户(user)添加执行(execute)权限
chmod u+x hello.sh
```

**3. 运行脚本**

使用 `./` 来执行当前目录下的脚本。
```bash
./hello.sh
```
**输出:**
```
Hello, World!
```

---

## 二、变量与参数

### 2.1 用户定义变量

在 Shell 中，变量是存储数据的基本单位。

- **定义变量**: `变量名=值`。**注意：等号两边不能有空格。**
- **访问变量**: 在变量名前加上 `$` 符号，例如 `$变量名` 或 `${变量名}`。

```bash
# 正确的定义
name="Alice"
age=30

# 访问变量
echo "User: $name, Age: $age"
```

### 2.2 引号的区别

- **单引号 (`'`)**: **强引用**。其中的所有字符都按其字面意思处理，变量和命令不会被展开。
  ```bash
  echo 'My name is $name'  # 输出: My name is $name
  ```
- **双引号 (`"`)**: **弱引用**。会进行变量扩展和命令替换，但会保留空格。这是最常用的引号。
  ```bash
  echo "My name is $name"  # 输出: My name is Alice
  ```
- **反引号 (`` ` ``)**: **命令替换**。用于执行包含在其中的命令，并将其输出结果作为值。**推荐使用 `$(...)` 替代。**

### 2.3 命令替换

将一个命令的输出结果赋值给变量。

- **推荐语法**: `$(command)`
- **旧式语法**: `` `command` ``

```bash
current_date=$(date +%Y-%m-%d)
file_count=$(ls -l | wc -l)

echo "Today is: $current_date"
echo "Number of files in this directory: $file_count"
```

### 2.4 算术运算

Shell 默认将变量视为字符串。要进行数学计算，需要使用特定的语法。

- **语法**: `$((...))`

```bash
x=10
y=5

# 不需要用 $ 访问括号内的变量
sum=$((x + y))
echo "Sum: $sum" # 输出: Sum: 15

# 也支持自增/自减
((x++))
echo "New x: $x" # 输出: New x: 11

# 幂运算
power=$((2**3))
echo "2^3 is: $power" # 输出: 2^3 is: 8
```

### 2.5 位置参数与特殊参数

脚本可以接收在命令行上传递的参数。

- **`$0`**: 脚本本身的名称。
- **`$1`, `$2`, ... `$9`**: 第 1 到第 9 个位置的参数。
- **`${10}`**: 超过 9 个的参数需要用花括号括起来。
- **`$#`**: 传递给脚本的参数总数。
- **`$@`**: 所有参数列表，每个参数都被视为一个独立的字符串（推荐使用）。
- **`$*`**: 所有参数列表，所有参数被视为一个单一的字符串。
- **`$?`**: 上一个命令执行后的**退出状态码 (Exit Status)**。`0` 通常表示成功，非 `0` 表示失败。

**`params.sh` 示例:**
```bash
#!/bin/bash
echo "Script name: $0"
echo "First parameter: $1"
echo "Second parameter: $2"
echo "Total number of parameters: $#"
echo "All parameters as a list: $@"

# 检查上一个命令的状态
ls /nonexistent-directory
echo "Exit status of last command: $?" # 会输出一个非零值
```
**运行:**
```bash
./params.sh arg1 "hello world"
```

---

## 三、控制流

### 3.1 `if` 语句

用于条件判断。基本结构是 `if ... then ... elif ... then ... else ... fi`。

- **基本语法**: `if [ condition ]; then ... fi`
- **注意**: `[` 和 `]` 与其中的条件之间必须有空格。

**比较运算符:**

**整数比较:**
- `-eq`: 等于 (equal)
- `-ne`: 不等于 (not equal)  
- `-gt`: 大于 (greater than)
- `-ge`: 大于等于 (greater than or equal)
- `-lt`: 小于 (less than)
- `-le`: 小于等于 (less than or equal)

**字符串比较:**
- `==` 或 `=`: 等于
- `!=`: 不等于
- `<`: 小于（按字母顺序）
- `>`: 大于（按字母顺序）

**逻辑运算:**
- `-a` 或 `&&`: 与 (AND)
- `-o` 或 `||`: 或 (OR)

**基本示例:**
```bash
#!/bin/bash
echo "请输入一个整数"
read number

if [ $number -gt 0 ]; then
    echo "$number 是正数"
elif [ $number -eq 0 ]; then
    echo "$number 是零"
else
    echo "$number 是负数"
fi
```

**复合条件示例:**
```bash
# 与运算
if [ $a -eq 10 ] && [ $b -eq 20 ]; then
    echo "a等于10且b等于20"
fi

# 或运算
if [ "$1" == "3" ] || [ "$1" == "4" ]; then
    echo "参数是3或4"
fi

# 字符串比较
if [ $person != "steve" ]; then
    echo "不是steve"
fi
```

### 3.2 `case` 语句

用于匹配一个变量的多个可能值，是 `if/elif` 结构的一个简化。

**基本语法:**
```bash
case 变量 in
    模式1) 
        statements;;
    模式2) 
        statements;;
    模式3)
        statements;;
    ...
    *)
        默认命令;;
esac
```

**重要语法特点:**
- `case` 语句以 `esac` 结尾（case的倒写）
- 每个分支用 `)` 结尾
- 每个命令块都需要 `;;` 结束
- `*` 表示默认情况（类似于其他语言的 default）

**示例:**
```bash
#!/bin/bash
read -p "请输入 'start', 'stop', 或 'restart': " action

case "$action" in
  start)
    echo "正在启动服务..."
    ;;
  stop)
    echo "正在停止服务..."
    ;;
  restart)
    echo "正在重启服务..."
    ;;
  *)
    echo "用法: $0 {start|stop|restart}"
    ;;
esac
```

### 3.3 `for` 循环

用于遍历一个列表或范围。

**基本语法:**
```bash
# 遍历列表
for 变量 in 列表
do
    statements
done

# 或者遍历命令输出
for 变量 in $(unix命令)
do
    statements
done

# C风格循环
for ((i=0; i < 条件; i++))
do
    statements
done
```

**1. 遍历固定列表:**
```bash
#!/bin/bash
for num in {4,3,2,1}; do 
    echo "Number: $num"
done

# 或者使用字符串列表
for fruit in "Apple" "Banana" "Cherry"; do
  echo "I like $fruit"
done
```

**2. C 风格的 `for` 循环:**
```bash
for ((i = 1; i <= 5; i++)); do
  echo "Iteration $i"
done
```

**3. 遍历命令输出:**
```bash
for file in $(ls *.txt); do
  echo "Processing $file..."
done
```

### 3.4 `while` 循环

当条件为真时，重复执行代码块。

**基本语法:**
```bash
while [ 条件 ]
do
    statements
done
```

**示例:**
```bash
#!/bin/bash
counter=1
while [ $counter -le 5 ]; do
  echo "Count: $counter"
  ((counter++))
done
```

---

## 四、函数与数组

### 4.1 函数 (Functions)

用于封装可重用的代码块。

- **定义**: `function_name() { ... }` 或 `function function_name { ... }`。
- **调用**: `function_name arg1 arg2`。
- **参数**: 在函数内部，使用 `$1`, `$2` 等位置参数来访问传递的参数。
- **返回值**:
  - **退出状态码**: 使用 `return` 返回一个 0-255 的整数。
  - **数据**: 在函数中使用 `echo` 输出结果，在调用时通过命令替换 `$(...)` 来捕获。

**示例:**
```bash
#!/bin/bash

# 返回数据的函数
get_greeting() {
  local name=$1 # local 关键字使变量仅在函数内可见
  echo "Hello, $name!"
}

# 返回退出状态码的函数
check_file_exists() {
  if [ -f "$1" ]; then
    return 0 # 成功
  else
    return 1 # 失败
  fi
}

# 调用并捕获数据
message=$(get_greeting "World")
echo $message

# 调用并检查退出状态码
if check_file_exists "/etc/hosts"; then
  echo "File exists."
else
  echo "File not found."
fi
```

### 4.2 数组 (Arrays)

用于存储一组值。

- **定义**: `array_name=(value1 value2 ...)`
- **访问单个元素**: `${array_name[index]}` (索引从 0 开始)
- **访问所有元素**: `${array_name[@]}`
- **获取数组长度**: `${#array_name[@]}`

```bash
#!/bin/bash
fruits=("Apple" "Banana" "Orange")

# 访问元素
echo "First fruit is: ${fruits[0]}"

# 遍历数组
for fruit in "${fruits[@]}"; do
  echo "Fruit: $fruit"
done

# 获取长度
echo "Total number of fruits: ${#fruits[@]}"
```

---

## 五、调试技巧

### 5.1 语法检查和跟踪

- **`bash -n script.sh`**: 检查脚本的语法错误，但不执行。
- **`bash -x script.sh`**: **跟踪模式 (Trace Mode)**。在执行前打印出每一行命令及其参数，非常适合调试。

### 5.2 在脚本中启用/禁用跟踪

```bash
set -x # 开启调试输出
# ... some commands ...
set +x # 关闭调试输出
```

### 5.3 使用 echo 进行调试

在关键位置打印变量的值来检查程序流程：
```bash
echo "DEBUG: 变量值为 $variable"
```

### 5.4 常见错误和注意事项

1. **等号两侧不能有空格:**
   - 正确: `name="John"`
   - 错误: `name = "John"`

2. **访问变量时要加 $ 符号:**
   - 正确: `echo $name`
   - 错误: `echo name`

3. **文件权限问题:**
   - 记得给脚本添加执行权限: `chmod +x script.sh`

4. **路径问题:**
   - 使用相对路径时要注意当前工作目录
   - 推荐使用绝对路径或者 `$PWD` 变量

5. **条件语句中的空格:**
   - 正确: `if [ $a -eq $b ]`
   - 错误: `if [$a -eq $b]`（缺少空格）
