# 西游记2006之最终幻想 (xyj2006zzzhx)

AKAI Studio 的 Tomud 品牌版西游记的另一个分支——和 122 `xyj2006n`
是同宗档案（文件结构和 bug 完全一致），连线握手方式也一样：**第一
行必须是裸的 `2060`**（Tomud/"笑傲江湖"客户端的自动应答），任何其
他内容都会被判定为非法客户端并断线。

## 本次修复的关键 bug

和 `xyj2006n` 完全一样的 5 类 bug，这次借助本次会话新写的两个工
具（`scripts/lib_bulk_fix.py` 的新增规则、`scripts/scan_known_bugs.py`）
在第一次开机测试之前就提前抓出来了，不用再一次次靠开机报错慢慢找：

1. **4 处绝对路径 `#include </...>`**（`jitan.h`、`book-qujing.lpc`、
   `monk1.lpc`、`tongmingdian.lpc`）——改成双引号写法。
2. **经典 §6.6 convertd.lpc 希腊字母表漏斜杠错字**，45 处，同时存
   在于 `adm/daemons/convertd.lpc`（真正使用的）和一份没有引用的
   `daemons/convertd.lpc`——两份都修了。
3. **`adm/simul_efun/message.lpc` 的 `tell_room()` 转发未设定的
   exclude 参数**——`exclude || ({})`。
4. **两个原始 GBK 转档批次漏转的档案**（`beast1.lpc`、
   `shuijingqiu.lpc`）——用 `iconv -c -f GB18030 -t UTF-8` 补转。
5. **`adm/daemons/logind.lpc` 的 `check_legal_name()` 标准 §8.1
   奇偶校验/后缀切片写法**，改成逐码点检查；另外 6 处
   `is_killing(me)` 传对象给宣告成 `is_killing(string id)` 的函式
   （§7.50）也一并修正。

`httpd.lpc`/`ftpd.lpc`/`dns_master.lpc` 不在实际使用的 `preload`
列表里（休眠状态，只有巫师主动 `update` 才会触发），本次没有掏
空处理，作为已知的潜伏风险记录，和 `xyj2006n` 一致。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（账号密码 + 管理密码双密码机
  制，两者不能相同，管理密码至少 7 个字符且不能与英文 ID 太相似）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

第一行必须是 `2060`。之后依序：`new` → 英文 ID → 中文名字 → 管理
密码 + 确认 → 登陆密码 + 确认 → 电子邮件（`id@dtxy.net` 格式）→
性别（m/f）→ 天赋点数分配菜单（`9` 接受默认值，`y` 二次确认）→
进入游戏。

## 本地运行

```
cd libs/xyj2006zzzhx
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40159**。
