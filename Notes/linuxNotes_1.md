# Linux 基础笔记

本文档记录了常用的 Linux 命令和概念，包括文件操作、权限管理和一些高级命令。

---

## 一、文件的创建与查看

### 1.1 创建文件

有多种方法可以创建新文件：

- **`touch`**: 创建一个空文件。如果文件已存在，则更新其修改时间。
  ```bash
  touch filename.txt
  ```

- **`>` (重定向)**: 创建一个新文件。**注意：如果文件已存在，此操作会覆盖原有内容。**
  ```bash
  > filename.txt
  ```

- **`echo`**: 创建文件并写入内容。
  - `>`: 覆盖模式，会清空文件原有内容再写入。
    ```bash
    echo "一些内容" > filename.txt
    ```
  - `>>`: 追加模式，会在文件末尾添加新内容。
    ```bash
    echo "另一些内容" >> filename.txt
    ```

- **`cat >`**: 从标准输入创建文件。输入内容后，按 `Ctrl + D` 保存并退出。
  ```bash
  cat > filename.txt
  # 在这里输入内容...
  # 按下 Ctrl + D
  ```

### 1.2 命令行文本编辑器

- **`vim`**: 功能强大，是 Linux 中最常见的编辑器之一。
- **`nano`**: 操作简单，对新手友好。
- **`gedit`**: 图形化编辑器，通常在桌面环境中使用。

### 1.3 查看文件内容

- **`cat`**: 显示文件的全部内容。
  ```bash
  cat filename.txt
  ```

- **`less`**: 分页浏览文件内容，更适合查看大文件。
  ```bash
  less filename.txt
  ```

- **`head`**: 查看文件的开头部分。
  ```bash
  # 查看前 10 行 (默认)
  head filename.txt

  # 查看指定行数
  head -n 20 filename.txt
  ```

- **`tail`**: 查看文件的结尾部分。
  ```bash
  # 查看后 10 行 (默认)
  tail filename.txt

  # 查看指定行数
  tail -n 20 filename.txt
  ```

---

## 二、文件与目录管理

### 2.1 目录切换 (cd)

- **`cd <路径>`**: 切换到指定目录。
  ```bash
  cd /var/log
  ```

- **`cd ~`** 或 **`cd`**: 返回当前用户的家目录(Home Directory)。

- **`cd -`**: 返回上一个工作目录。

- **`cd ..`**: 返回上一级目录。
  ```bash
  # 返回上两级目录
  cd ../..
  ```

- **`pwd`**: 显示当前工作目录的绝对路径。

### 2.2 列出文件 (ls)

- **`ls`**: 显示当前目录下的文件和文件夹。

- **常用选项**:
  - `-l`: 显示详细列表信息 (权限、所有者、大小、修改日期等)。
  - `-a`: 显示所有文件，包括以 `.` 开头的隐藏文件(hidden files)。
  - `-h`: 与 `-l` 结合使用，以人类可读的格式显示文件大小 (例如 `4.0K`, `1.2M`)。
  - `-t`: 按修改时间排序，最新的在前。

  ```bash
  # 显示所有文件的详细信息
  ls -la
  ```

### 2.3 移动和重命名 (mv)

- **重命名文件**:
  ```bash
  mv old_name.txt new_name.txt
  ```

- **移动文件或目录**:
  ```bash
  mv my_file.txt /path/to/destination/
  mv my_directory/ /path/to/other_destination/
  ```

### 2.4 复制 (cp)

- **复制文件**:
  ```bash
  # 在当前目录复制
  cp source_file.txt destination_file.txt

  # 复制到其他目录
  cp source_file.txt /path/to/destination/
  ```

- **复制目录**: 需要使用 `-r` 或 `-R` 选项进行递归(recursive)复制。
  ```bash
  cp -r source_directory/ destination_directory/
  ```

### 2.5 删除 (rm)

- **删除文件**:
  ```bash
  rm filename.txt
  ```

- **删除目录**: 需要使用 `-r` 选项。
  ```bash
  rm -r directory_name/
  ```

- **常用选项**:
  - `-i`: 交互式(interactive)删除，在删除前进行确认。
  - `-f`: 强制(force)删除，不进行任何提示。**请谨慎使用！**

  ```bash
  # 交互式地递归删除目录
  rm -ri old_stuff/
  ```

---

## 三、WSL 文件互操作

Windows Subsystem for Linux (WSL) 允许在 Windows 和 Linux 子系统之间轻松访问文件。

- **Windows 盘符挂载点**: Windows 的盘符被挂载在 `/mnt/` 目录下。例如，`C:` 盘对应 `/mnt/c/`。

- **从 Windows 复制到 WSL**:
  ```bash
  # 将 C 盘下的文件复制到 WSL 的家目录
  cp /mnt/c/Users/YourUser/Documents/file.txt ~/
  ```

- **从 WSL 复制到 Windows**:
  ```bash
  # 将 WSL 家目录的文件复制到 Windows 桌面
  cp ~/my_document.txt /mnt/c/Users/YourUser/Desktop/
  ```

- **复制目录**: 同样使用 `-r` 选项。
  ```bash
  cp -r ~/my_project/ /mnt/d/backups/
  ```

---

## 四、输入/输出重定向与管道

- **`<` (输入重定向)**: 将文件内容作为命令的输入。
  ```bash
  # sort 命令会读取 text.txt 的内容并排序
  sort < text.txt
  ```

- **`|` (管道)**: 将一个命令的输出作为另一个命令的输入。
  ```bash
  # cat 的输出通过管道传给 sort 进行排序
  cat text.txt | sort
  ```

---

## 五、文本搜索 (grep)

`grep` (Global Regular Expression Print) 用于在文件中搜索匹配指定模式的行。

- **基本语法**:
  ```bash
  grep "search_term" filename.txt
  ```

- **常用选项**:
  - `-i`: 忽略大小写。
  - `-n`: 显示匹配行的行号。
  - `-w`: 只匹配整个单词。
  - `-v`: 反向匹配，显示不包含模式的行。
  - `-r` 或 `-R`: 递归搜索目录下的所有文件。
  - `-C <num>`: 显示匹配行及其上下文(Context)的前后 `num` 行。

  ```bash
  # 在所有 .log 文件中递归搜索 "Error"，忽略大小写并显示行号
  grep -rin "Error" . --include="*.log"
  ```

---

## 六、权限管理

### 6.1 用户与用户组

Linux 文件权限围绕三类身份展开：

- **所有者 (user/owner)**: 文件的创建者。
- **所属组 (group)**: 文件所属的用户组。
- **其他人 (others)**: 除所有者和所属组成员之外的任何用户。

### 6.2 权限类型

每类身份都有三种基本权限：

- **`r` (read)**: 读取文件内容或查看目录中的文件列表。
- **`w` (write)**: 修改文件内容或在目录中创建/删除文件。
- **`x` (execute)**: 执行文件（如脚本）或进入目录。

### 6.3 查看权限

使用 `ls -l` 可以看到类似 `-rwxr-xr--` 的权限字符串。

- 第 1 位: 文件类型 (`-` 代表普通文件, `d` 代表目录)。
- 2-4 位: **所有者**的权限 (`rwx`)。
- 5-7 位: **所属组**的权限 (`r-x`)。
- 8-10 位: **其他人**的权限 (`r--`)。

### 6.4 修改权限 (chmod)

`chmod` (Change Mode) 命令用于修改文件或目录的权限。

#### 1. 数字法 (八进制)

每个权限对应一个数字：`r=4`, `w=2`, `x=1`。将每组的权限数字相加。

- `rwx` = 4 + 2 + 1 = `7`
- `r-x` = 4 + 0 + 1 = `5`
- `r--` = 4 + 0 + 0 = `4`

```bash
# 设置权限为 rwxr-xr-x (所有者读写执行，组用户和其他人读和执行)
chmod 755 script.sh

# 设置权限为 rw-r--r-- (所有者读写，其他人只读)
chmod 644 config.txt
```

#### 2. 符号法

使用 `u` (user), `g` (group), `o` (others), `a` (all) 结合 `+` (添加), `-` (移除), `=` (设置) 来修改权限。

```bash
# 为所有者添加执行权限
chmod u+x script.sh

# 移除所属组的写权限
chmod g-w data.txt

# 为其他人设置只读权限
chmod o=r public_info.txt

# 为所有用户添加读权限，移除写权限
chmod a+r,-w shared_file
```
