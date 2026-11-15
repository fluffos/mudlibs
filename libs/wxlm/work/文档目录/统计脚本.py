#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
日志统计脚本 - 统计每个玩家获得各物品的数量
"""

import re
from collections import defaultdict

def parse_log_file(file_path):
    """
    解析日志文件，提取玩家和物品信息
    
    @param file_path: 日志文件路径
    @return: 玩家物品统计字典
    """
    # 玩家物品统计字典
    player_items = defaultdict(lambda: defaultdict(int))
    
    # 正则表达式匹配日志格式
    # 匹配格式: 时间戳 玩家名(ID) 抽到物品 [颜色码]物品名[颜色码]×数量
    pattern = r'\w+\s+\w+\s+\d+\s+\d+:\d+:\d+\s+\d+\s+(.+?)\((.+?)\)\s+抽到物品\s+\[.+?m(.+?)\[.+?m×(\d+)'
    
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            total_lines = 0
            matched_lines = 0
            
            for line_num, line in enumerate(file, 1):
                line = line.strip()
                total_lines += 1
                if not line:
                    continue
                    
                match = re.search(pattern, line)
                if match:
                    matched_lines += 1
                    player_name = match.group(1).strip()
                    player_id = match.group(2).strip()
                    item_name = match.group(3).strip()
                    item_count = int(match.group(4))
                    
                    # 使用玩家名(ID)作为键
                    player_key = f"{player_name}({player_id})"
                    player_items[player_key][item_name] += item_count
                    
                    if matched_lines <= 3:  # 显示前3个匹配的调试信息
                        print(f"匹配成功: {player_key} -> {item_name} x{item_count}")
                else:
                    if line_num <= 3:  # 显示前3个不匹配的调试信息
                        print(f"第{line_num}行格式不匹配: {line}")
            
            print(f"总共处理 {total_lines} 行，匹配成功 {matched_lines} 行")
                    
    except FileNotFoundError:
        print(f"错误: 找不到文件 {file_path}")
        return {}
    except Exception as e:
        print(f"错误: 读取文件时发生异常 {e}")
        return {}
    
    return dict(player_items)

def generate_statistics_report(player_items):
    """
    生成统计报告
    
    @param player_items: 玩家物品统计字典
    @return: 格式化的统计报告字符串
    """
    if not player_items:
        return "没有找到有效的统计数据。"
    
    report_lines = []
    report_lines.append("=" * 60)
    report_lines.append("玩家物品获得统计报告")
    report_lines.append("=" * 60)
    report_lines.append("")
    
    # 按玩家名排序
    sorted_players = sorted(player_items.items())
    
    for player_key, items in sorted_players:
        report_lines.append(f"【{player_key}】")
        report_lines.append("-" * 40)
        
        # 按物品名排序
        sorted_items = sorted(items.items())
        total_items = 0
        
        for item_name, count in sorted_items:
            report_lines.append(f"  {item_name}: {count}个")
            total_items += count
            
        report_lines.append(f"  总计: {total_items}个物品")
        report_lines.append("")
    
    # 添加汇总统计
    report_lines.append("=" * 60)
    report_lines.append("汇总统计")
    report_lines.append("=" * 60)
    
    # 统计所有物品总数
    all_items = defaultdict(int)
    total_players = len(player_items)
    total_all_items = 0
    
    for items in player_items.values():
        for item_name, count in items.items():
            all_items[item_name] += count
            total_all_items += count
    
    report_lines.append(f"参与玩家数: {total_players}人")
    report_lines.append(f"物品总数: {total_all_items}个")
    report_lines.append("")
    report_lines.append("各物品总计:")
    
    # 按物品总数降序排列
    sorted_all_items = sorted(all_items.items(), key=lambda x: x[1], reverse=True)
    for item_name, total_count in sorted_all_items:
        report_lines.append(f"  {item_name}: {total_count}个")
    
    return "\n".join(report_lines)

def main():
    """
    主函数
    """
    # 日志文件路径
    log_file_path = "日志.txt"
    
    print("开始解析日志文件...")
    player_items = parse_log_file(log_file_path)
    
    if not player_items:
        print("没有找到有效数据，程序退出。")
        return
    
    print(f"解析完成，共找到 {len(player_items)} 个玩家的记录。")
    
    # 生成统计报告
    report = generate_statistics_report(player_items)
    
    # 输出到控制台
    print("\n" + report)
    
    # 保存到文件
    output_file = "玩家物品统计报告.txt"
    try:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(report)
        print(f"\n统计报告已保存到: {output_file}")
    except Exception as e:
        print(f"保存报告时发生错误: {e}")

if __name__ == "__main__":
    main()