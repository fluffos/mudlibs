# 三界神话「测试二区」(sjshv2578bb)

"三界神话"系列第三个档案（另见 `sjsh` 宝鸡站原始版、`sjshv150` 紫藤分站），测试二区的内容，和 `sjshv150` 共享同一套"三界神话"世界观——武当、古墓、蜀山、雪山等武侠门派场景与"十二宫""蟠桃""蓬莱""神殿"等神话地名并存，开封城依旧是成规模的解谜任务区；但文件级比对显示与 `sjshv150` 路径相同的档案里也只有约四分之一逐字节一致，两者是共享底层引擎的独立内容快照，而非近乎重复的部署。这份"测试二区"快照独有一片"迷宫"场景（四层以上、约 530 个场景），是这批分站里其它版本都没有的地图内容；`sited.lpc` 本身无条件放行本地回环地址连线，不像 `sjshv150` 需要专门打补丁，本地/WASM 环境下的注册流程也就天然更顺畅。

## 本次修复的关键 bug

和同系档案大部分相同（同源代码），另外还有一个这份档案独有的：

1. **§7.60** `master.lpc` 的 `log_error()`/`standard_trace()` 在
   `CHANNEL_D` 尚未加载时呼叫它——两处都补上
   `find_object(CHANNEL_D)` 判断。
2. **`channeld.lpc` 的 `do_channel()` 没检查 `environment(me)` 是否
   为空就直接 `->query("no_chat")`**：一旦上面的 §7.60 修好，
   `CHANNEL_D` 真的能加载了，`log_error()` 广播一条"err"频道消息时
   传入的 `me` 是 `master.lpc` 自己的 `this_object()`——它没有
   `environment()`（永远是 0），触发 `*Bad argument 1 to EFUN
   call_other()`。已加上 `environment(me) &&` 判断。
3. **§7.61** `message()` 模拟超越函式缺了 `exclude` 参数的兜底，和
   `sjshv150` 相同的修法。
4. **§7.41** 损坏的 `emoted.o` 存档，同样的 `catch(restore())` 修
   法。
5. **经典 §8.1 GBK 字节区间 `is_chinese()`**：这次分别出现在
   `adm/daemons/chinesed.lpc`（`CHINESE_D` 真正的实现）和
   `logind.lpc` 的 `check_legal_name()`（同样的 `i%2` 字节配对假
   设，UTF8 码点索引下对奇数字数的中文名字永远误判）——两处都已修
   正。这份档案没有 `convertd.lpc`（不存在这个文件）。
6. **§7.34** `logind.lpc` 的 `get_name()` 里有一行遗留的调试
   `printf("%O\n", ob)`，会把登录对象内部路径原样打印在中文名字
   确认和邮件地址注册提示之间——已删除。

深度功能测试（§10.7，见 NOTES.md）确认了本档案 §7.97（LISTNODES 宏
缺反斜杠导致的死亡死循环）**不适用**——本档案的 `LISTNODES` 反斜杠
本来就是对的；也确认了 `sjshv150` 上发现的 §8.13（WIZ 密码二次登录
死锁）**不适用**——本档案的 `logind.lpc` 早就用一个 `#define
NO_CHECK_WIZPWD` 开关规避了这个 bug 形状。完整的死亡→复活循环、留言
板 `post`/`read`、管理员写权限（`update`）均已现场验证通过。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: `Mud@2026`
- **普通密码 / Regular password**: `Mud@2027`（双密码机制，两者不能相同）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。
>
> 测试提示：本档案有一条"新建账号未连续在线满 10 分钟就退出会被
> 自动删档"的反小号规则，且巫师账号断线（net_dead）超时被设成 1
> 秒——用巫师账号测试时若要提前结束会话，务必用 `quit -lovesjsh`
> 正常退出（绕过 10 分钟限制），不要直接掐断连线，否则账号会被静
> 默删除（详见 NOTES.md）。

## 本地运行

```
cd libs/sjshv2578bb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40125**。
