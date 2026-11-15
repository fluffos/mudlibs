#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
极简版AI角色扮演工具 - 用户自定义提示词版本
只有一个功能：将用户输入的提示词直接发送给AI获取回复
"""

import sys
import json
import os
import argparse

# 设置标准输出编码为UTF-8
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
sys.stderr = io.TextIOWrapper(sys.stderr.buffer, encoding='utf-8')

try:
    from zhipuai import ZhipuAI
except ImportError:
    print("❌ 错误：请先安装智谱AI SDK")
    print("📦 安装命令：pip install zhipuai")
    sys.exit(1)

class SimpleAIRole:
    def __init__(self):
        self.api_key = ""
        self.client = None
        
        # 加载配置
        self.load_config()
        
        if not self.api_key:
            print("❌ 未找到API密钥，请先设置")
            print("🔧 设置方法：")
            print("   1. 访问 https://bigmodel.cn/ 获取API密钥")
            print("   2. 创建 config.json 文件，内容：{\"api_key\": \"你的密钥\"}")
            sys.exit(1)
    
    def load_config(self):
        """加载配置文件"""
        try:
            if os.path.exists('config.json'):
                with open('config.json', 'r', encoding='utf-8') as f:
                    config = json.load(f)
                    self.api_key = config.get('api_key', '')
                    if self.api_key:
                        self.client = ZhipuAI(api_key=self.api_key)
        except Exception as e:
            print(f"❌ 加载配置失败: {e}")
    
    def generate_response(self, user_prompt):
        """根据用户提示词生成回复"""
        if not self.client:
            return "❌ API客户端未初始化"
        
        try:
            # 调用API，不保留聊天记录
            response = self.client.chat.completions.create(
                model="GLM-4-Flash-250414",
                messages=[
                    {"role": "user", "content": user_prompt}
                ],
                temperature=0.8,
                max_tokens=2048,
                stream=False
            )
            
            # 获取回复
            reply = response.choices[0].message.content
            return reply
            
        except Exception as e:
            error_msg = str(e)
            # 确保错误信息能正确显示中文
            if hasattr(e, 'message'):
                error_msg = e.message
            return f"❌ API调用失败：{error_msg}"

def main():
    # 设置命令行参数解析
    parser = argparse.ArgumentParser(
        description="极简版AI角色扮演工具 - 用户自定义提示词",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
使用示例：
  python ai_role_simple_custom.py "你是一名武侠小说中的大侠，请用武侠小说的语气介绍你自己"
  python ai_role_simple_custom.py "扮演一名科学家，解释量子力学的基本原理"
  python ai_role_simple_custom.py "你是一名江湖郎中，为我推荐一些治疗感冒的方子"
        """
    )
    
    parser.add_argument("prompt", help="自定义提示词，将直接发送给AI")
    parser.add_argument("-v", "--version", action="version", version="极简版AI角色扮演工具 v1.0")
    
    # 解析参数
    args = parser.parse_args()
    
    try:
        # 初始化工具
        role_tool = SimpleAIRole()
        
        # 生成回复
        result = role_tool.generate_response(args.prompt)
        print(result)
        
    except Exception as e:
        print(f"❌ 程序运行出错: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main() 