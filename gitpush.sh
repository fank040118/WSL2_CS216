#!/bin/bash

# 切换到正确的目录
cd /home/fank0/WSL2_CS216

# 检查是否使用HTTPS
REMOTE_URL=$(git remote get-url origin)
if [[ $REMOTE_URL == https://* ]]; then
    echo "检测到HTTPS URL，正在转换为SSH URL..."
    SSH_URL="git@github.com:$(echo $REMOTE_URL | sed 's|https://github.com/||')"
    git remote set-url origin "$SSH_URL"
    echo "已将远程URL更改为: $SSH_URL"
fi

# 显示当前更改
echo "当前更改的文件:"
git status -s

# 询问是否添加所有文件
read -p "是否添加所有更改的文件? (y/n): " add_all

if [[ "$add_all" == "y" ]]; then
    git add .
else
    echo "请输入要添加的文件路径(多个文件用空格分隔):"
    read files
    git add $files
fi

# 提示输入提交消息
echo "正在打开编辑器输入提交信息..."
temp_file=$(mktemp)
${EDITOR:-nano} "$temp_file"
commit_message=$(cat "$temp_file")
rm "$temp_file"

# 检查是否输入了提交信息
if [ -z "$commit_message" ]; then
    echo "未输入提交信息，脚本退出"
    exit 1
fi

# 提交更改
git commit -m "$commit_message"

# 推送到远程
echo "正在推送到 GitHub..."
git push origin main

echo "完成!"