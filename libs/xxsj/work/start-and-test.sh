#!/bin/bash
# 启动驱动并测试

echo "========================================="
echo "  启动 MUD 驱动"
echo "========================================="
echo ""

cd /d/Mudproject/mymud

# 检查是否有旧的驱动进程
OLD_PID=$(ps aux | grep driver.exe | grep -v grep | awk '{print $2}')
if [ ! -z "$OLD_PID" ]; then
    echo "发现旧的驱动进程 (PID: $OLD_PID)，正在停止..."
    kill -9 $OLD_PID
    sleep 1
fi

echo "启动驱动..."
echo ""

# 启动驱动
/d/Mudproject/fluffos/build/bin/driver.exe config.cfg

echo ""
echo "驱动已停止"
