# grep 基础教程

## 1. 什么是 grep？
`grep` 是一个强大的命令行工具，用于在文件中搜索指定的文本模式。它的名字来源于 "Global Regular Expression Print" 的缩写，意味着它会全局搜索正则表达式并打印出匹配的行。

---

## 2. 基本语法
`grep [选项] 模式 [文件名...]`

- **模式 (Pattern)**: 你想要搜索的文本或正则表达式。
- **文件名 (File(s))**: 你想要在哪个或哪些文件中进行搜索。如果未指定文件名，`grep` 会从标准输入（例如，通过管道 `|`）中读取内容。

---

## 3. 常用选项 (Options)

- `-i` (ignore-case): 忽略大小写。搜索时不区分模式和文件内容的大小写。
  - 示例: `grep -i 'apple' fruits.txt` 会匹配 "apple", "Apple", "APPLE" 等。

- `-v` (invert-match): 反向查找。只显示**不**匹配模式的行。
  - 示例: `grep -v 'error' log.txt` 会显示所有不包含 "error" 的日志行。

- `-n` (line-number): 显示行号。在每个匹配的行前面显示它在文件中的行号。
  - 示例: `grep -n 'main' program.c`

- `-r` 或 `-R` (recursive): 递归搜索。在指定目录及其所有子目录中搜索文件。
  - 示例: `grep -r 'config' /etc/` 会搜索 `/etc/` 目录下的所有文件和子目录中的文件。

- `-l` (files-with-matches): 只列出包含匹配项的文件名，而不是打印匹配的行。
  - 示例: `grep -l 'User' .` 会列出当前目录下所有包含 "User" 的文件名。

- `-c` (count): 统计匹配的行数。只显示每个文件中匹配的总行数。
  - 示例: `grep -c 'warning' system.log`

- `-w` (word-regexp): 匹配整个单词。确保模式作为一个独立的单词出现，而不是字符串的一部分。
  - 示例: `grep -w 'is' text.txt` 会匹配 "this is a test" 中的 "is"，但不会匹配 "this"。

- `-E` (extended-regexp): 使用扩展正则表达式。允许使用更强大、更灵活的元字符，如 `+`, `?`, `|`, `()` 等，而无需转义。
  - 示例: `grep -E 'error|warning' log.txt` 匹配包含 "error" 或 "warning" 的行。

---

## 4. 实践示例

- **在单个文件中搜索**: `grep 'hello' world.txt`

- **在多个文件中搜索**: `grep 'api_key' config.ini settings.py`

- **与管道 `|` 结合使用**: `ps aux | grep 'nginx'`
  - 这个命令会列出所有正在运行的进程，然后 `grep` 会从中筛选出包含 "nginx" 的行。

- **搜索所有以 'start' 开头的行**: `grep '^start' data.csv`
