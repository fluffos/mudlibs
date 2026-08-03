# 浴血江湖 (yxjh)

《浴血江湖3梦回江湖》，KMMUD.COM 出品，注册流程为英文 ID → 中文全
名（一次输入，不分姓和名）→ 管理密码/登陆密码双密码制 → 天赋菜单
（0 随机整组，y 接受）→ 电子邮件 → 性别。地图和"天涯"家族的
`wlhd`（武林浩荡/金庸梦II）几乎完全一致——`d/city/sj.lpc`（"世界之
巅"跳崖场景）逐字节相同，用的正是 `wlhd` 独立改写过的那个"jump"
版本，而不是 `tybxjh` 那个原始的、没加引号的版本，说明这份档案是
在 `wlhd` 基础上（或共同祖先）继续演化而来，此前没有任何档案互相
记录过这层关系。

## 内容亮点

- 地图目录结构和 `wlhd` 高度重合（`jerry`/`rock`/`tybang`/`xixia`
  等场景都在），是"天涯"家族里又一个确认成员，但具体用的是 `wlhd`
  独立改写过的"世界之巅"跳崖场景版本，而非 `tybxjh` 的原始版本。
- 本次修复中发现一个真正会让整个预载系统失效的隐蔽 bug：档案里根
  本没有 `adm/etc/preload` 这个文件（只有 `.bak`/`bb` 两个变体），
  还原后又发现它是 CRLF 换行——`update_file()` 不会去掉 `\r`，导致
  每一个精灵的路径都变成类似"...securityd\r.lpc"这种找不到的路
  径，**修好之前没有任何一个精灵被真正预载过**（`logind.lpc` 之所
  以还能工作纯属继承关系的意外巧合），详见下方 bug 修复第 1 条。

## 本次修复的关键 bug

1. **`adm/etc/preload` 这份档案原本压根不存在**（只有 `preload.bak`
   和内容略少的 `preloadbb` 两个变体）——从内容较完整的
   `preload.bak` 还原，结果发现这份档案本身是 CRLF 换行，而
   `update_file()` 的 `explode(str,"\n")` 不会去掉 `\r`，导致每一
   个精灵的路径都变成了类似 `/adm/daemons/securityd\r.lpc` 这种
   `file_size()` 永远找不到的路径——修好前**没有任何一个精灵真正被
   预载**，`logind.lpc` 之所以还能用，纯粹是因为
   `clone/user/login.lpc` 直接继承了它，属于意外巧合。换成 LF 后
   预载流程才真正生效。
2. **经典 §8.1 GBK 字节区间 `check_legal_name()`**（`i%2==0` 奇偶
   校验、`name[i..<0]` 后缀切片、字节数没减半的 2/10 上下限），只
   有真正生效的 `adm/daemons/logind.lpc` 需要修（`is_chinese()` 本
   身已经正确）——`clone/user/logind.lpc`（和 `login.lpc` 放一起的
   死档案）、`u/rock/`（某位巫师的整份个人备份目录，自带一整套
   `logind.lpc`/`master.lpc`/`user.lpc`）都确认不是配置文件指向的
   路径，没有修改。
3. **`master.lpc`（真正生效的 `adm/obj/master.lpc`，不是
   `u/rock/obj/master.lpc` 的死档案副本）的 `valid_read()`/
   `valid_write()`** 补上了标准的 `user == this_object()` 短路判
   断。
4. **`d/jerry/saveme.lpc` 的 `create()` 呼叫了
   `exert_function(10)`**——`exert_function(string func)`
   （定义在 `inherit/char/npc.lpc`）要的是技能名字符串，不是整
   数，导致这个 NPC 完全编译失败（`*No program in object`），连带
   整个城市房间的部分居民都没生成。这行呼叫的原始意图已经无法还
   原（不像本次会话其他修复那样能猜出合理的算术替代），所以直接
   删掉了，做法上参照了 `yhyxcs` 那次原生驱动上线时对"看不出用途
   的坏代码直接删除"的处理方式。
5. **`data/` 目录下 130 个存档档案中有 118 个是 CRLF 换行**，这台
   驱动的 `restore_object()` 对嵌套 mapping 结构的 `\r` 比较敏感，
   统一转成了 LF。这修好了大部分（但不是全部）的存档还原问题，详
   见下方"已知但未修复"。

`adm/daemons/httpd.lpc`、`adm/daemons/network/dns_master.lpc` 都不
在（还原后的）`preload` 列表里，也没有真正的外部呼叫者，属于完全
休眠，本次没有改动。

## 已知但未修复的问题

即使转成 LF 之后，`adm/daemons/named.lpc` 的 `restore_object()` 在
每次开机时仍然会报一次"Illegal mapping format while restoring
dbase"——存档本身的 mapping 字面量括号是配对的（已用脚本验证），
问题出在这台驱动更严格的 `restore_object()` 解析器的其它地方，没
有进一步深挖。这个错误被 `preload()` 的 `catch()` 拦截，只会让
`named.lpc` 的近似名字查重功能退化，不影响注册、进入游戏或其它已
观察到的功能——按 AGENTS.md §7.15 的精神记录在案，不算阻塞性问题。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`（这份档案的阶层一路到 `(ceo)`，为了
  和项目里其他档案保持一致，统一用 `(admin)` 这一级），通过
  `/adm/etc/wizlist` 授予，登录后自动显示"◇ 您目前权限：
  (admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

英文 ID → `y`（确认创建新角色）→ 中文全名 → 管理密码 + 确认 → 登
陆密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接受）→ 电子邮件 →
性别（m/f）→ 进入游戏（中央广场）。

## 本地运行

```
cd libs/yxjh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40148**。
