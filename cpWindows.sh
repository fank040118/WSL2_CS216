#!/bin/bash

# 定义目标目录
TARGET_DIR="/mnt/c/WSL2Files/CS216"

# 检查目标目录是否存在，如不存在则创建
if [ ! -d "$TARGET_DIR" ]; then
    echo "目标目录不存在，正在创建..."
    mkdir -p "$TARGET_DIR"
fi

# 确认操作
echo "警告：此操作将清空目标目录 $TARGET_DIR 中的所有文件和文件夹！"
read -p "确定要继续吗？(y/n): " confirm

if [[ "$confirm" != "y" ]]; then
    echo "操作已取消"
    exit 0
fi

# 清空目标目录中的所有文件和文件夹，但保留目标目录本身
echo "正在清空目标目录..."
rm -rf "$TARGET_DIR"/*

# 复制当前目录下的所有非隐藏文件和文件夹到目标目录
echo "正在复制文件到目标目录..."
cp -r /home/fank0/WSL2_CS216/* "$TARGET_DIR"/

echo "文件复制完成！文件已复制到 $TARGET_DIR"