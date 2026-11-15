#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
HTTP Request Parser for LPC external command.
读取包含完整 HTTP 请求报文的文件，解析后将结构化结果以 JSON 输出到 STDOUT。
结果格式示例：
{
  "method": "GET",
  "path": "/test/echo?name=abc",
  "version": "1.1",
  "headers": {"Host": "127.0.0.1:8092"},
  "body": "",
  "query": "name=abc"
}
"""
import sys, json, os
from typing import Dict


def parse_http(raw: str) -> Dict:
    # 统一行分隔符，兼容 CRLF 与 LF
    raw = raw.replace("\r\n", "\n")
    lines = raw.split("\n")

    if not lines or lines[0].strip() == "":
        return {"error": "empty request"}

    # 请求行
    try:
        method, path, version = lines[0].strip().split()
    except ValueError:
        return {"error": "bad request line", "raw": lines[0]}

    headers = {}
    i = 1
    while i < len(lines):
        line = lines[i]
        i += 1
        if line == "":  # 空行，头部结束
            break
        if ":" in line:
            k, v = line.split(":", 1)
            headers[k.strip()] = v.strip()

    # Body 剩余部分按原始换行组合
    body = "\n".join(lines[i:]) if i < len(lines) else ""

    raw_path = path
    query = ""
    if "?" in path:
        path, query = path.split("?", 1)

    return {
        "method": method,
        "path": path,          # 不含查询串，便于后端直接匹配
        "raw_path": raw_path,   # 保留完整 URI 供需要时使用
        "version": version.replace("HTTP/", "") if version.startswith("HTTP/") else version,
        "headers": headers,
        "body": body,
        "query": query,
    }


def main():
    if len(sys.argv) < 2:
        print(json.dumps({"error": "need file path"}, ensure_ascii=False))
        return
    file_path = sys.argv[1]
    try:
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            raw = f.read()
    except Exception as e:
        print(json.dumps({"error": "open fail", "msg": str(e)}, ensure_ascii=False))
        return

    result = parse_http(raw)
    print(json.dumps(result, ensure_ascii=False))


if __name__ == "__main__":
    main() 