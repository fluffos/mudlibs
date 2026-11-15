# Security Daemon 权限调试日志说明

## 概述

为了准确定位 `keju_d` 保存权限被拒绝的问题,在 `valid_write()` 函数的所有 `return 0` 分支添加了详细的中文调试日志。

## 日志位置

所有调试日志写入文件: `/log/files`

## 日志格式

```
[权限拒绝-X] 时间戳 函数:xxx 文件:xxx 用户信息:xxx 原因:xxx
```

## 6个拒绝检查点

### 检查点1: user不是对象

**触发条件**:
- `func == "save_object"`
- `user` 不是对象类型(不是 `objectp(user)`)

**日志示例**:
```
[权限拒绝-1] 2025-01-17 15:30:00 函数:save_object 文件:/data/keju_d 用户信息:字符串:keju_d 原因:user不是对象,无法通过系统对象检查
```

**分析**:
- 如果看到这个日志,说明 `user` 参数传入的是字符串而不是对象
- 这会导致无法检查 `base_name(user)` 来判断是否是系统对象

---

### 检查点2: uid与euid不匹配

**触发条件**:
- `func == "save_object"`
- 玩家存档检查通过
- `euid` 与 `getuid(user)` 不一致

**日志示例**:
```
[权限拒绝-2] 2025-01-17 15:30:00 函数:save_object 文件:/data/user/demo222 用户信息:对象:/clone/user/user#123 base_name:/clone/user/user euid:demo222 getuid:demo111 原因:用户标识不匹配
```

**分析**:
- 这是为了防止用户篡改自己的 ID
- 正常情况下 `euid` 和 `uid` 应该一致

---

### 检查点3: 玩家ID不匹配

**触发条件**:
- `func == "save_object"`
- 玩家存档检查通过
- 对象是 `USER_OB` 但 `getuid(user)` 与 `user->query("id")` 不一致

**日志示例**:
```
[权限拒绝-3] 2025-01-17 15:30:00 函数:save_object 文件:/data/user/demo222 用户信息:对象:/clone/user/user#123 base_name:/clone/user/user getuid:demo222 query_id:demo111 原因:玩家ID不匹配
```

**分析**:
- 这是为了防止玩家数据损坏
- 玩家对象的 `uid` 应该和存储的 `id` 属性一致

---

### 检查点4: euid为空 ⭐ 最可能的原因

**触发条件**:
- `euid` 为空字符串、0 或 undefined

**日志示例**:
```
[权限拒绝-4] 2025-01-17 15:30:00 函数:save_object 文件:/data/keju_d 用户信息:对象:/adm/special_ob/keju/keju_d base_name:/adm/special_ob/keju/keju_d 原因:euid为空或0
```

**分析**:
- **这是最关键的检查点!**
- 如果 `keju_d` 的 `euid` 没有正确设置,就会在这里被拒绝
- 即使对象在 `/adm/` 路径下,如果 `euid` 为空也会被拒绝

**可能原因**:
1. `keju_d->create()` 中的 `seteuid(ROOT_UID)` 失败
2. 对象重新加载后 `euid` 被重置
3. `geteuid(user)` 返回了 0

---

### 检查点5: ls/dest命令静默拒绝

**触发条件**:
- `func` 是 `"ls"` 或 `"dest"`
- 用于静默拒绝这些命令,不记录详细日志(避免刷屏)

**日志示例**:
```
[权限拒绝-5] 2025-01-17 15:30:00 函数:ls 文件:/adm/ 用户信息:对象:/clone/user/user#123 base_name:/clone/user/user euid:demo222 status:(wizard) 原因:ls/dest命令静默拒绝
```

**分析**:
- 这些命令的权限拒绝是正常的
- 不需要特别关注

---

### 检查点6: 所有权限检查均未通过

**触发条件**:
- 所有其他检查都未通过
- 包括: ROOT权限、admin权限、临时巫师权限、用户目录、递归目录权限

**日志示例**:
```
[权限拒绝-6] 2025-01-17 15:30:00 函数:save_object 文件:/data/keju_d 用户信息:对象:/adm/special_ob/keju/keju_d base_name:/adm/special_ob/keju/keju_d euid:Root status:(player) 原因:所有权限检查均未通过
```

**分析**:
- 这是最后的兜底检查
- 如果到达这里,说明对象虽然有 `euid`,但权限仍然不足

---

## 使用方法

### 1. 触发问题

等待所有玩家下线,让 `keju_d` 自动触发保存操作(每30秒一次)

### 2. 查看日志

```bash
tail -f /log/files
# 或者
cat /log/files | grep "权限拒绝"
```

### 3. 分析日志

根据日志中的 `[权限拒绝-X]` 编号,对照上面的说明分析问题原因。

### 示例分析

**如果看到**:
```
[权限拒绝-4] 2025-01-17 15:30:00 函数:save_object 文件:/data/keju_d 用户信息:对象:/adm/special_ob/keju/keju_d base_name:/adm/special_ob/keju/keju_d 原因:euid为空或0
```

**说明**:
- `keju_d` 对象存在且路径正确 (`/adm/special_ob/keju/keju_d`)
- 但是 `euid` 为空
- 虽然代码第94行有 `seteuid(ROOT_UID)`,但实际运行时 `euid` 没有被设置

**解决方向**:
1. 检查 `keju_d->create()` 是否正确执行
2. 检查 `ROOT_UID` 常量是否正确定义
3. 检查 `seteuid()` 是否返回成功

---

**如果看到**:
```
[权限拒绝-6] 2025-01-17 15:30:00 函数:save_object 文件:/data/keju_d 用户信息:对象:/adm/special_ob/keju/keju_d base_name:/adm/special_ob/keju/keju_d euid:Root status:(admin) 原因:所有权限检查均未通过
```

**说明**:
- `euid` 是 `Root`
- `status` 是 `(admin)`
- 但是**仍然被拒绝了!**

**这说明**:
- 第195行的检查 `if (euid == ROOT_UID || status == "(admin)") return 1;` **没有生效**
- 可能原因: `ROOT_UID` 常量定义与实际 `euid` 不匹配

---

## 预期结果

正常情况下, `keju_d` 调用 `save()` **不应该**出现任何 `[权限拒绝]` 日志。

如果出现日志,我们就能精确知道是哪个检查点拒绝了保存操作。

---

## 临时解决方案

如果确认是 **检查点4** (euid为空) 导致的问题,可以临时修改代码:

### 方案A: 在 save_object 分支提前返回

```lpc
if (func == "save_object")
{
    // 系统对象和管理对象可以保存
    if (objectp(user))
    {
        string bn = base_name(user);
        if (sscanf(bn, "/system/%*s") || sscanf(bn, "/adm/%*s"))
        {
            // 直接允许,不再检查 euid
            return 1;
        }
    }

    // ... 其他检查
}
```

### 方案B: 修改 euid 检查逻辑

```lpc
// 获取用户的euid和状态
if (! euid)
{
    // 对于系统对象,即使 euid 为空也允许
    if (objectp(user))
    {
        string bn = base_name(user);
        if (sscanf(bn, "/system/%*s") || sscanf(bn, "/adm/%*s"))
            return 1;
    }

    // 其他情况拒绝
    log_file("files", sprintf("[权限拒绝-4] ...\n"));
    return 0;
}
```

---

## 下一步

1. ✅ 编译成功,调试日志已生效
2. ⏳ 等待下一次 `keju_d` 保存触发
3. ⏳ 查看 `/log/files` 中的调试日志
4. ⏳ 根据日志编号定位具体问题

---

**文档版本**: 1.0
**创建日期**: 2025-01-17
**用途**: 排查 keju_d 保存权限问题
