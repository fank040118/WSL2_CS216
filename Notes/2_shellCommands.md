Shell命令完整指南——————————————————————————————————————————————————————————

基础文件和目录操作——————————————————————————————————————————————————————————

pwd (Print Working Directory) - 显示当前目录：
    pwd                        # 显示当前工作目录的完整路径

ls (List) - 列出文件和目录：
    ls                         # 列出当前目录内容
    ls -l                      # 显示详细信息（权限、大小、修改时间等）
    ls -a                      # 显示所有文件（包括隐藏文件）
    ls -la                     # 组合使用，显示所有文件的详细信息
    ls -h                      # 以人类可读格式显示文件大小
    ls -t                      # 按修改时间排序
    ls -r                      # 反向排序
    ls *.txt                   # 列出所有.txt文件
    ls -ld directory/          # 只显示目录本身的信息

cd (Change Directory) - 切换目录：
    cd /path/to/directory      # 切换到指定目录
    cd ~                       # 切换到家目录
    cd                         # 同上，切换到家目录
    cd ..                      # 返回上一级目录
    cd ../..                   # 返回上两级目录
    cd -                       # 返回上一个工作目录
    cd /                       # 切换到根目录

mkdir (Make Directory) - 创建目录：
    mkdir dirname              # 创建单个目录
    mkdir dir1 dir2 dir3       # 创建多个目录
    mkdir -p path/to/nested/dir # 创建多级目录（父目录不存在时自动创建）
    mkdir -m 755 dirname       # 创建目录并设置权限

rmdir - 删除空目录：
    rmdir dirname              # 删除空目录
    rmdir -p path/to/empty/dir # 删除多级空目录

基础文件操作——————————————————————————————————————————————————————————————————

touch - 创建文件或更新时间戳：
    touch filename.txt         # 创建空文件或更新现有文件的修改时间
    touch file1.txt file2.txt  # 创建多个文件
    touch -t 202301011200 file # 设置特定的时间戳

cp (Copy) - 复制文件或目录：
    cp source.txt dest.txt     # 复制文件
    cp source.txt /path/to/    # 复制文件到指定目录
    cp file1 file2 file3 dir/  # 复制多个文件到目录
    cp -r source_dir dest_dir  # 递归复制目录
    cp -i source dest          # 交互式复制（覆盖前询问）
    cp -v source dest          # 显示复制过程（verbose）
    cp -u source dest          # 只在源文件更新时才复制

mv (Move) - 移动/重命名文件或目录：
    mv oldname newname         # 重命名文件或目录
    mv file.txt /path/to/      # 移动文件到指定目录
    mv file1 file2 dir/        # 移动多个文件到目录
    mv -i source dest          # 交互式移动（覆盖前询问）
    mv -v source dest          # 显示移动过程

rm (Remove) - 删除文件或目录：
    rm filename.txt            # 删除文件
    rm file1 file2 file3       # 删除多个文件
    rm -i filename             # 交互式删除（删除前询问）
    rm -f filename             # 强制删除（不询问）
    rm -r dirname              # 递归删除目录
    rm -rf dirname             # 强制递归删除目录（危险命令！）
    rm *.txt                   # 删除所有.txt文件

文件内容查看——————————————————————————————————————————————————————————————————

cat (Concatenate) - 显示文件内容：
    cat filename.txt           # 显示整个文件内容
    cat file1 file2            # 显示多个文件内容
    cat -n filename            # 显示内容并添加行号
    cat -b filename            # 只对非空行添加行号
    cat > newfile.txt          # 创建新文件并输入内容（Ctrl+D结束）
    cat >> existing.txt        # 向现有文件追加内容

less/more - 分页查看文件：
    less filename.txt          # 分页查看文件（推荐）
    more filename.txt          # 分页查看文件（较老的工具）
    # 在less中的快捷键：
    # q - 退出, 空格 - 下一页, b - 上一页
    # /pattern - 搜索, n - 下一个匹配, N - 上一个匹配

head - 查看文件开头：
    head filename.txt          # 显示前10行
    head -n 20 filename.txt    # 显示前20行
    head -5 filename.txt       # 显示前5行
    head -c 100 filename.txt   # 显示前100个字符

tail - 查看文件结尾：
    tail filename.txt          # 显示后10行
    tail -n 20 filename.txt    # 显示后20行
    tail -5 filename.txt       # 显示后5行
    tail -f filename.txt       # 实时监控文件末尾（常用于日志文件）
    tail -F filename.txt       # 实时监控，即使文件被重建也继续

文件权限和属性——————————————————————————————————————————————————————————————————

chmod (Change Mode) - 修改文件权限：
    chmod 755 filename         # 设置权限为rwxr-xr-x
    chmod 644 filename         # 设置权限为rw-r--r--
    chmod u+x filename         # 为所有者添加执行权限
    chmod g-w filename         # 移除组的写权限
    chmod o=r filename         # 设置其他人只有读权限
    chmod +x script.sh         # 为所有用户添加执行权限

chown (Change Owner) - 修改文件所有者：
    chown user filename        # 改变文件所有者
    chown user:group filename  # 改变所有者和组
    chown -R user:group dir/   # 递归改变目录及内容的所有者

file - 查看文件类型：
    file filename.txt          # 显示文件类型信息
    file *                     # 显示当前目录所有文件的类型

stat - 显示文件详细信息：
    stat filename.txt          # 显示文件的详细统计信息

基础文本处理——————————————————————————————————————————————————————————————————

echo - 输出文本：
    echo "Hello World"         # 输出文本
    echo $HOME                 # 输出环境变量
    echo -n "No newline"       # 输出时不换行
    echo -e "Line1\nLine2"     # 解释转义字符

grep (Global Regular Expression Print) - 搜索文本：
    grep "pattern" filename    # 在文件中搜索模式
    grep -i "pattern" file     # 忽略大小写搜索
    grep -n "pattern" file     # 显示行号
    grep -v "pattern" file     # 显示不匹配的行
    grep -r "pattern" dir/     # 在目录中递归搜索
    grep -c "pattern" file     # 统计匹配行数
    grep -l "pattern" *.txt    # 只显示包含模式的文件名

man (Manual) - 查看命令手册：
    man ls                     # 查看ls命令的详细手册
    man 5 passwd               # 查看特定章节的手册
    man -k keyword             # 搜索包含关键字的手册页

help - 获取帮助：
    help cd                    # 获取内置命令的帮助
    ls --help                  # 大多数命令的帮助选项

历史和快捷操作——————————————————————————————————————————————————————————————————

history - 命令历史：
    history                    # 显示命令历史
    history 10                 # 显示最近10条命令
    !123                       # 执行历史中第123条命令
    !!                         # 执行上一条命令
    !grep                      # 执行最近的grep命令

快捷键：
    Ctrl+C                     # 终止当前命令
    Ctrl+Z                     # 暂停当前命令
    Ctrl+D                     # 退出当前shell或结束输入
    Ctrl+L                     # 清屏（等同于clear命令）
    Tab                        # 自动补全命令或文件名
    ↑↓                         # 浏览命令历史

clear - 清屏：
    clear                      # 清空终端屏幕

管道和重定向(Pipes and Redirection)——————————————————————————————————————————
管道 | 用于将一个命令的输出作为另一个命令的输入：
    ls -l | grep ".txt"        # 列出所有.txt文件的详细信息
    cat file.txt | sort        # 显示文件内容并排序
    ps aux | grep python       # 查找运行中的Python进程

输入重定向 <：
    sort < data.txt            # 将data.txt的内容作为sort命令的输入

输出重定向 > 和 >>：
    echo "Hello" > file.txt    # 将输出写入文件（覆盖）
    echo "World" >> file.txt   # 将输出追加到文件末尾
    ls -l > filelist.txt       # 将目录列表保存到文件

错误重定向 2> 和 2>>：
    command 2> error.log       # 将错误信息写入文件
    command > output.txt 2> error.txt  # 分别重定向输出和错误
    command > all.log 2>&1     # 将输出和错误都重定向到同一文件

文本处理命令——————————————————————————————————————————————————————————————————
sort - 排序文本行：
    sort file.txt              # 按字母顺序排序
    sort -n numbers.txt        # 按数字排序
    sort -r file.txt           # 反向排序
    sort -k2 data.txt          # 按第2列排序

uniq - 去除重复行：
    sort file.txt | uniq       # 先排序再去重
    uniq -c file.txt           # 统计每行出现次数
    uniq -d file.txt           # 只显示重复的行

wc - 统计字数：
    wc file.txt                # 显示行数、字数、字符数
    wc -l file.txt             # 只显示行数
    wc -w file.txt             # 只显示字数
    wc -c file.txt             # 只显示字符数

cut - 提取列：
    cut -d',' -f1 data.csv     # 提取CSV文件的第1列
    cut -c1-5 file.txt         # 提取每行的第1-5个字符
    cut -d' ' -f2,4 file.txt   # 提取第2列和第4列

tr - 字符转换：
    tr 'a-z' 'A-Z' < file.txt  # 将小写转为大写
    tr -d ' ' < file.txt       # 删除所有空格
    tr -s ' ' < file.txt       # 压缩连续空格为单个空格

sed - 流编辑器：
    sed 's/old/new/' file.txt  # 替换每行第一个"old"为"new"
    sed 's/old/new/g' file.txt # 替换所有"old"为"new"
    sed '2d' file.txt          # 删除第2行
    sed -n '1,5p' file.txt     # 只显示第1-5行

awk - 文本处理工具：
    awk '{print $1}' file.txt  # 打印第1列
    awk '{print NF}' file.txt  # 打印每行的字段数
    awk '{sum += $1} END {print sum}' numbers.txt  # 计算第1列的总和
    awk -F',' '{print $2}' data.csv  # 以逗号为分隔符，打印第2列

查找和搜索命令——————————————————————————————————————————————————————————————————
find - 查找文件和目录：
    find . -name "*.txt"       # 在当前目录查找所有.txt文件
    find /home -type f -name "config"  # 查找名为config的文件
    find . -type d -name "test*"  # 查找以test开头的目录
    find . -size +1M           # 查找大于1MB的文件
    find . -mtime -7           # 查找最近7天修改过的文件
    find . -name "*.log" -exec rm {} \;  # 查找并删除所有.log文件

locate - 快速查找文件：
    locate filename            # 快速查找文件（需先运行updatedb）
    locate -i filename         # 忽略大小写查找

which - 查找命令位置：
    which python3              # 查找python3命令的路径
    which -a gcc               # 查找所有gcc命令的路径

whereis - 查找二进制文件、源码和手册：
    whereis gcc                # 查找gcc的二进制文件、源码和手册

进程管理命令——————————————————————————————————————————————————————————————————
ps - 显示进程信息：
    ps                         # 显示当前终端的进程
    ps aux                     # 显示所有进程的详细信息
    ps -ef                     # 显示所有进程的完整信息
    ps aux | grep python       # 查找Python进程

top - 实时显示进程信息：
    top                        # 实时显示系统进程
    top -u username            # 只显示指定用户的进程

htop - 更友好的进程查看器（如果安装了）：
    htop                       # 彩色的交互式进程查看器

jobs - 显示后台任务：
    jobs                       # 显示当前shell的后台任务
    jobs -l                    # 显示任务的PID

bg 和 fg - 后台和前台控制：
    command &                  # 在后台运行命令
    Ctrl+Z                     # 暂停当前进程
    bg %1                      # 将任务1移到后台
    fg %1                      # 将任务1移到前台

kill - 终止进程：
    kill PID                   # 发送TERM信号终止进程
    kill -9 PID                # 强制终止进程（KILL信号）
    kill -l                    # 列出所有可用信号
    killall process_name       # 终止所有同名进程

nohup - 不挂起运行：
    nohup command &            # 即使终端关闭也继续运行命令

系统信息命令——————————————————————————————————————————————————————————————————
df - 显示磁盘空间使用情况：
    df                         # 显示所有挂载点的磁盘使用情况
    df -h                      # 以人类可读格式显示（KB, MB, GB）
    df -i                      # 显示inode使用情况

du - 显示目录空间使用：
    du                         # 显示当前目录及子目录的大小
    du -h                      # 以人类可读格式显示
    du -s                      # 只显示总和
    du -sh *                   # 显示当前目录下每个文件/目录的大小

free - 显示内存使用情况：
    free                       # 显示内存使用情况
    free -h                    # 以人类可读格式显示

uname - 显示系统信息：
    uname -a                   # 显示所有系统信息
    uname -r                   # 显示内核版本
    uname -m                   # 显示机器架构

whoami - 显示当前用户名：
    whoami                     # 显示当前登录的用户名

id - 显示用户和组ID：
    id                         # 显示当前用户的ID信息
    id username                # 显示指定用户的ID信息

uptime - 显示系统运行时间：
    uptime                     # 显示系统运行时间和负载

date - 显示或设置日期：
    date                       # 显示当前日期和时间
    date '+%Y-%m-%d %H:%M:%S'  # 自定义日期格式
    date -d "yesterday"        # 显示昨天的日期

网络命令——————————————————————————————————————————————————————————————————————
ping - 测试网络连接：
    ping google.com            # 测试与google.com的连接
    ping -c 4 google.com       # 只ping 4次

wget - 下载文件：
    wget https://example.com/file.zip  # 下载文件
    wget -O newname.zip https://...    # 下载并重命名

curl - 数据传输工具：
    curl https://api.example.com       # 获取网页内容
    curl -o file.html https://...      # 下载并保存为文件
    curl -X POST -d "data" https://... # 发送POST请求

实用技巧和组合命令——————————————————————————————————————————————————————————
命令历史：
    history                    # 显示命令历史
    !123                       # 执行历史中第123个命令
    !!                         # 执行上一个命令
    !grep                      # 执行最近的grep命令

命令组合：
    command1 && command2       # command1成功后执行command2
    command1 || command2       # command1失败后执行command2
    command1; command2         # 依次执行两个命令

后台执行：
    command &                  # 在后台执行命令
    nohup command > output.log 2>&1 &  # 在后台执行并重定向输出

查看大文件：
    less large_file.txt        # 分页查看大文件
    head -20 file.txt          # 查看前20行
    tail -f log_file.txt       # 实时查看文件末尾（适合日志文件）

快速创建文件结构：
    mkdir -p project/{src,bin,docs,tests}  # 创建多级目录结构
    touch project/src/{main.cpp,utils.cpp} # 创建多个文件

压缩和解压：
    tar -czf archive.tar.gz directory/     # 压缩目录
    tar -xzf archive.tar.gz                # 解压文件
    zip -r archive.zip directory/          # 创建zip压缩文件
    unzip archive.zip                      # 解压zip文件

常用别名(Aliases)建议——————————————————————————————————————————————————————
可以在 ~/.bashrc 或 ~/.zshrc 中添加这些别名：
    alias ll='ls -alF'                     # 详细列表
    alias la='ls -A'                       # 显示隐藏文件
    alias l='ls -CF'                       # 简洁列表
    alias grep='grep --color=auto'         # 彩色grep
    alias ..='cd ..'                       # 快速返回上级目录
    alias ...='cd ../..'                   # 快速返回上上级目录
    alias h='history'                      # 快速查看历史
    alias c='clear'                        # 快速清屏