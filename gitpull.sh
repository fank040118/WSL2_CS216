#!/bin/bash

# 切换到正确的目录
cd /home/fank0/WSL2_CS216

# 显示当前本地状态
echo "当前本地状态:"
git status -s

# 从远程仓库拉取更新
echo "正在从GitHub拉取更新..."
git pull WSL2_CS216 master

# 检查上一条命令的退出状态
if [ $? -eq 0 ]; then
    echo "更新完成!"
else
    echo "更新过程中发生错误，可能存在冲突。"
    echo "请手动解决冲突后，使用 git add 标记已解决，然后 git commit 完成合并。"
fi
