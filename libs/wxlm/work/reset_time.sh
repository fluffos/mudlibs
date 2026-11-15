#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# reset_time.sh
# ------------------------------------------------------------------------------
# 功能:
#   每隔 1 分钟向百度服务器请求当前北京(UTC+8)时间，通过解析 HTTP
#   响应头中的 "Date" 字段获取标准 GMT 时间戳，然后使用 Ubuntu 自带的
#   timedatectl 命令强制更新系统时间，并同步到硬件时钟。
# 
# 使用方法:
#   1. 赋予脚本可执行权限: chmod +x reset_time.sh
#   2. 单次同步:      sudo ./reset_time.sh
#   3. 后台持续同步: sudo ./reset_time.sh --loop &
#   4. 若使用 cron，每分钟调用一次脚本即可，无需 --loop 参数。
# 
# 注意:
#   - 确保系统已设置为亚洲/上海时区 (timedatectl set-timezone Asia/Shanghai)。
#   - 建议关闭系统自带的 NTP 同步, 本脚本会在每次同步前临时关闭 NTP 以避免冲突。
# ------------------------------------------------------------------------------

set -euo pipefail

BAIDU_URL="https://www.baidu.com"
SLEEP_SECONDS=60

log() {
  echo "[$(date '+%F %T')] $*"
}

sync_time() {
  # 从百度获取 Date 头 (GMT)
  local gmt_date
  gmt_date=$(curl -sI "$BAIDU_URL" | grep -i '^Date:' | cut -d' ' -f2-)
  if [[ -z "$gmt_date" ]]; then
    log "未能获取百度时间戳，跳过本次同步。"
    return 1
  fi

  # 转换为本地时间 (假定时区已正确设置为 Asia/Shanghai)
  local local_datetime
  local_datetime=$(date -d "$gmt_date" '+%Y-%m-%d %H:%M:%S' 2>/dev/null || true)
  if [[ -z "$local_datetime" ]]; then
    log "时间格式转换失败: $gmt_date"
    return 1
  fi

  log "同步时间到 $local_datetime"

  # 关闭系统 NTP, 避免与手动设置冲突
  timedatectl set-ntp false 2>/dev/null || true

  # 设置系统时间
  timedatectl set-time "$local_datetime"

  # 同步到硬件时钟 (如果命令存在)
  if command -v hwclock >/dev/null 2>&1; then
    hwclock --systohc
  else
    log "hwclock 命令不存在，跳过硬件时钟同步。"
  fi

  # 重新开启 NTP (可选, 若需要继续与 NTP 同步可打开)
  # timedatectl set-ntp true
}

main() {
  local mode="once"
  if [[ ${1:-} == "--loop" || ${1:-} == "-l" ]]; then
    mode="loop"
  fi

  if [[ "$mode" == "loop" ]]; then
    while true; do
      sync_time || true
      sleep "$SLEEP_SECONDS"
    done
  else
    sync_time
  fi
}

main "$@"
