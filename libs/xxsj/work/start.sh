#!/bin/bash
# MUD 游戏启动脚本

# 获取脚本所在目录
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

# 驱动程序路径
DRIVER="../fluffos/build/bin/driver.exe"

# 检查驱动是否存在
if [ ! -f "$DRIVER" ]; then
    echo "错误：找不到驱动程序 $DRIVER"
    echo "请先编译 FluffOS"
    exit 1
fi

# 检查配置文件
if [ ! -f "config.cfg" ]; then
    echo "错误：找不到配置文件 config.cfg"
    exit 1
fi

# 创建日志目录
mkdir -p log

echo "========================================="
echo "  启动 MUD 游戏服务器"
echo "========================================="
echo ""
echo "配置文件: config.cfg"
echo "日志目录: log/"
echo ""
echo "连接方式："
echo "  网页客户端: http://localhost:8080"
echo "  Telnet: localhost:4000"
echo ""
echo "按 Ctrl+C 停止服务器"
echo "========================================="
echo ""

# 启动驱动
"$DRIVER" config.cfg
