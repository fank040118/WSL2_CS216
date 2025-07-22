#!/bin/bash

# 切换到正确的目录
cd /home/fank0/CS216

# 检查是否使用HTTPS
REMOTE_URL=$(git remote get-url CS216)
if [[ $REMOTE_URL == https://* ]]; then
    echo "检测到HTTPS URL，正在转换为SSH URL..."
    SSH_URL="git@github.com:$(echo $REMOTE_URL | sed 's|https://github.com/||')"
    git remote set-url CS216 "$SSH_URL"
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
read -p "请输入提交信息: " commit_message

# 提交更改
git commit -m "$commit_message"

# 推送到远程
echo "正在推送到 GitHub..."
git push CS216 master

echo "完成!"