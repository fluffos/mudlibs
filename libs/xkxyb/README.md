# 侠客行一百 (xkxyb)

厦门热线一百分支，MudOS V22pre11。这份档案和 110 `xkx100` 标题相
同（都叫"侠客行一百"），但内容是真正不同的、更小的一份快照
（6456 对 14255 个 `.lpc` 文件，目录结构也不一样，有 `ftp`/
`mudos.etc`/`www` 这些 `xkx100` 没有的目录），不是重复压缩包，所
以没有标记 `duplicate_of`。

## 本次修复的关键 bug

1. **§7.52 从零手写的 HTTP 服务器**：`adm/daemons/httpd.lpc`（经典
   的 Truilkan/Jacques Interstice `httpd.c`，档案自己的注释里写明
   由 xiaobao/ken@XAJH 移植到 XAJH mudlib 底座）直接呼叫
   `socket_create()`/`socket_bind()`/`socket_close()`，没有任何存
   在性判断，导致整个档案在 WASM 下编译失败。确认没有任何其他文件
   呼叫这个精灵，所以按 §7.52 的默认做法，把每一个碰 socket 的函
   式（`setup()`、`write_data_retry()`、`store_client_info()`、
   `listen_callback()`、`close_connection()`/`remove()` 里的
   `socket_close`）都掏空成空函式。

这份档案没有 `is_chinese()`/`check_legal_name()` bug——"小浮侠"
（三个字）第一次尝试就通过了，和这一轮的其他几个手足档案不同，不
用修。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份
  档案的 `securityd.lpc` 真的会在开机时读取 `WIZLIST`），`wizlist`
  命令确认显示"目前权限：(admin)"，且 `fluffos` 出现在最高权限组
  里。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkxyb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40152**。
