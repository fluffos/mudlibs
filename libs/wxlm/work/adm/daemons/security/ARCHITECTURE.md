# Security Daemon 架构说明文档

## 目录
1. [系统概述](#系统概述)
2. [整体架构](#整体架构)
3. [运行机制](#运行机制)
4. [核心流程](#核心流程)
5. [数据流转](#数据流转)
6. [安全模型](#安全模型)
7. [扩展机制](#扩展机制)

---

## 系统概述

### 定位与职责

**Security Daemon (SECURITY_D)** 是MUD系统的核心安全守护进程,负责整个系统的权限控制和安全管理。它是一个**单例守护进程**,在系统启动时由 `master.c` 加载,并在整个游戏运行期间持续存在。

### 核心职责

```
┌─────────────────────────────────────────┐
│         Security Daemon (SECURITY_D)     │
├─────────────────────────────────────────┤
│ 1. 用户权限管理                          │
│    - 巫师等级管理 (player -> admin)      │
│    - 用户状态查询与设置                   │
│                                          │
│ 2. 文件访问控制                          │
│    - 文件读写权限验证                     │
│    - 目录递归权限检查                     │
│                                          │
│ 3. 命令授权管理                          │
│    - 命令权限验证                         │
│    - 显式授权/撤销                        │
│                                          │
│ 4. 对象安全验证                          │
│    - euid设置权限控制                     │
│    - 函数绑定权限验证                     │
│                                          │
│ 5. 站点特权管理                          │
│    - 站点特权信息的加密存储                │
│    - 特权信息的查询与验证                  │
└─────────────────────────────────────────┘
```

---

## 整体架构

### 系统层次结构

```
┌────────────────────────────────────────────────────────────┐
│                    MUD 驱动程序 (Driver)                    │
│  - 调用 master.c 的 valid_* 函数验证所有关键操作             │
└─────────────────────┬──────────────────────────────────────┘
                      │
                      ▼
┌────────────────────────────────────────────────────────────┐
│              Master Object (master.c)                       │
│  - 接收驱动程序的验证请求                                    │
│  - 委托给 SECURITY_D 进行实际权限验证                        │
│                                                             │
│  关键接口:                                                  │
│  ✓ valid_write()    → SECURITY_D->valid_write()           │
│  ✓ valid_read()     → SECURITY_D->valid_read()            │
│  ✓ valid_seteuid()  → SECURITY_D->valid_seteuid()         │
│  ✓ valid_bind()     → SECURITY_D->valid_bind()            │
└─────────────────────┬──────────────────────────────────────┘
                      │
                      ▼
┌────────────────────────────────────────────────────────────┐
│           Security Daemon (securityd.c)                     │
│                    主控制器 (67行)                          │
└─────────────────────┬──────────────────────────────────────┘
                      │
         ┌────────────┴────────────┐
         ▼                         ▼
┌─────────────────┐      ┌─────────────────┐
│  核心数据层      │      │   功能模块层     │
│  (data.h)       │      │   (8个模块)      │
└─────────────────┘      └─────────────────┘
```

### 模块化架构

```
securityd.c (主文件)
│
├─ security_data.h ...................... 数据结构和常量定义
│   ├─ 常量定义 (MAX_SITE_PRIVILEGE_SIZE等)
│   ├─ 全局变量 (wiz_status, trusted_read等)
│   └─ query_save_file()
│
├─ security_init.h ...................... 初始化与持久化
│   ├─ create()              # 创建守护进程
│   ├─ restore()             # 恢复数据
│   ├─ save()                # 保存数据
│   └─ calculate_privilege_checksum() [private]
│
├─ security_rules.h ..................... 安全规则管理
│   ├─ query_security()      # 查询规则
│   ├─ set_security()        # 设置规则
│   ├─ combine_rules()       # 合并规则
│   └─ reset_security()      # 重置规则
│
├─ security_wizard.h .................... 巫师等级管理
│   ├─ get_status()          # 获取用户状态
│   ├─ set_status()          # 设置用户状态
│   ├─ get_wiz_level()       # 获取等级数值
│   ├─ query_wiz_levels()    # 获取等级列表
│   └─ get_wizlist()         # 获取巫师列表
│
├─ security_permission.h ................ 文件权限验证 ⭐核心
│   ├─ valid_write()         # 验证写权限
│   ├─ valid_read()          # 验证读权限
│   ├─ check_directory_permission() [private]
│   └─ get_user_euid() [private]
│
├─ security_object.h .................... 对象安全验证
│   ├─ valid_seteuid()       # 验证euid设置
│   └─ valid_bind()          # 验证函数绑定
│
├─ security_command.h ................... 命令授权管理
│   ├─ valid_grant()         # 验证命令授权
│   ├─ grant()               # 授权命令
│   ├─ remove_grant()        # 撤销授权
│   ├─ query_grant()         # 查询用户授权
│   └─ query_grant_users()   # 查询被授权用户
│
├─ security_site.h ...................... 站点特权管理
│   ├─ set_site_privilege()  # 设置站点特权
│   └─ query_site_privilege() # 查询站点特权
│
└─ security_backup.h .................... 文件备份与销毁
    ├─ backup_file()         # 备份文件
    └─ remove()              # 销毁守护进程
```

---

## 运行机制

### 1. 系统启动流程

```
┌─────────────────────────────────────────────────────────┐
│ 第一阶段: 驱动程序启动                                    │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 1. 驱动程序加载 master.c                                 │
│    master.c->create() 被调用                             │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 2. master.c->check_daemons()                            │
│    读取 /adm/etc/preload 配置文件                        │
│    预加载列表中的守护进程 (包括 SECURITY_D)              │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 第二阶段: SECURITY_D 初始化                              │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 3. securityd.c 被加载                                    │
│    security_init.h->create() 被调用                      │
│    ├─ seteuid(getuid())  # 设置有效用户ID                │
│    └─ restore()          # 恢复持久化数据                │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 4. restore() 恢复数据                                    │
│    ├─ 读取 /data/securityd.o 数据文件                   │
│    ├─ 验证站点特权信息 (checksum校验)                    │
│    ├─ reset_security() 初始化安全规则                    │
│    ├─ 读取 /adm/etc/WIZLIST 恢复巫师列表                │
│    └─ 初始化授权信息映射                                 │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 5. reset_security() 合并规则                             │
│    ├─ trusted_read = default + extend                   │
│    ├─ exclude_read = default + extend                   │
│    ├─ trusted_write = default + extend                  │
│    └─ exclude_write = default + extend                  │
└─────────────────────┬───────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────┐
│ 第三阶段: 系统就绪                                        │
│ SECURITY_D 进入待命状态,等待权限验证请求                  │
└─────────────────────────────────────────────────────────┘
```

### 2. 权限验证流程 (以文件写入为例)

```
用户执行: write_file("/d/city/bank.c", "...")
│
├─ 第一步: 驱动程序拦截
│   驱动程序检测到文件写入操作
│   └─> 调用 master.c->valid_write(file, user, "write_file")
│
├─ 第二步: Master委托
│   master.c 找到 SECURITY_D 对象
│   └─> 调用 SECURITY_D->valid_write(file, user, "write_file")
│
├─ 第三步: SECURITY_D 验证 (security_permission.h)
│   │
│   ├─ 3.1 获取用户身份
│   │   user_euid = get_user_euid(user)
│   │   status = get_status(user)  # 例如: "(wizard)"
│   │
│   ├─ 3.2 检查特殊情况
│   │   ├─ 是否写入日志? (LOG_DIR) → 允许
│   │   ├─ 是否保存存档? (save_object) → 验证文件匹配
│   │   ├─ 是否ROOT或admin? → 允许
│   │   ├─ 是否临时巫师权限? (wizhood) → 允许
│   │   └─ 是否写入自己目录? (/u/用户名/) → 允许
│   │
│   ├─ 3.3 递归检查目录权限 (核心算法)
│   │   check_directory_permission(file, euid, status,
│   │                              trusted_write, exclude_write)
│   │   │
│   │   │   文件路径: "/d/city/bank.c"
│   │   │   分解路径: ["d", "city", "bank.c"]
│   │   │
│   │   │   从最深层向上检查:
│   │   │   ├─ /d/city/bank.c  → 无规则
│   │   │   ├─ /d/city         → 无规则
│   │   │   ├─ /d              → trusted_write["/d"] = ({ "(arch)" })
│   │   │   │                     exclude_write["/d"] = ?
│   │   │   │
│   │   │   │  用户状态: "(wizard)"
│   │   │   │  所需权限: "(arch)"
│   │   │   │  判断: "(wizard)" 不在 "(arch)" 列表中
│   │   │   │  结果: 权限不足
│   │   │   │
│   │   │   └─ 返回 valid = 0
│   │
│   ├─ 3.4 记录非法尝试
│   │   log_file("files", "用户 user(wizard) write attempt(write_file)
│   │                      on /d/city/bank.c failed.")
│   │
│   └─ 3.5 返回结果
│       return 0; (禁止写入)
│
├─ 第四步: Master接收结果
│   master.c->valid_write() 收到返回值 0
│   └─> 返回给驱动程序
│
└─ 第五步: 驱动程序执行
    驱动程序收到返回值 0
    ├─ 拒绝执行 write_file()
    └─ 向用户返回错误信息
```

---

## 核心流程

### 流程1: 文件权限验证 (valid_write/valid_read)

#### 验证策略

Security Daemon 采用**分层递归验证**策略:

```
验证层次 (从高到低优先级):
├─ 1. 特权用户 (ROOT/admin)      → 直接放行
├─ 2. 特殊情况 (日志/存档/自己目录) → 条件放行
├─ 3. 临时权限 (wizhood)          → 直接放行
└─ 4. 目录规则 (trusted/exclude)  → 递归检查
```

#### 递归检查算法

**核心原理**: 从文件所在目录逐级向上检查到根目录,**排除规则优先于信任规则**。

```python
# 伪代码演示
def check_directory_permission(file, euid, status, trusted, excluded):
    path = explode(file, "/")  # 分解路径
    valid = 0                   # 默认禁止
    i = sizeof(path)

    while i >= 0:
        # 构造当前检查的目录
        dir = "/" + implode(path[0..i], "/")

        # 获取该目录的规则
        exclude_rules = excluded[dir]  # 排除规则
        trusted_rules = trusted[dir]   # 信任规则

        # 优先检查排除规则 (黑名单优先)
        if euid in exclude_rules or status in exclude_rules:
            valid = 0
            break  # 立即禁止,不再向上检查

        # 检查信任规则 (白名单)
        if euid in trusted_rules or status in trusted_rules:
            valid = 1
            break  # 允许访问,不再向上检查

        i -= 1  # 向上一级目录检查

    return valid
```

**示例场景**:

```
文件: /d/shaolin/wangyuetai.c
用户: user123 (status: "(wizard)")

检查顺序:
1. /d/shaolin/wangyuetai.c  → 无规则
2. /d/shaolin               → 无规则
3. /d                       → trusted_write["/d"] = ({ "(arch)" })
                              exclude_write["/d"] = ?

   判断: "(wizard)" 不在 trusted 列表中
   结果: 向上继续检查

4. /                        → trusted_write["/"] = ({ "(admin)" })
                              exclude_write["/"] = ?

   判断: "(wizard)" 不在 trusted 列表中
   结果: 所有目录检查完毕

最终结果: valid = 0 (禁止写入)
```

### 流程2: 命令授权验证 (valid_grant)

```
用户执行: update /adm/daemons/securityd
│
├─ 第一步: 命令对象验证
│   命令文件: /cmds/arch/update.c
│   命令对象调用: SECURITY_D->valid_grant(user, "(arch)")
│
│   ├─ 1.1 验证调用链
│   │   previous_object()    = /cmds/arch/update.c  ✓
│   │   previous_object(1)   = user对象             ✓
│   │   this_player(1)       = user对象             ✓
│   │
│   └─ 1.2 提取命令名
│       cmd = "update"  (从路径 /cmds/arch/update 提取)
│
├─ 第二步: 权限检查
│   │
│   ├─ 2.1 ROOT特权检查
│   │   if geteuid(user) == ROOT_UID → 允许
│   │
│   ├─ 2.2 管理员检查
│   │   if is_root(user) → 允许
│   │
│   ├─ 2.3 等级检查
│   │   user_level = wiz_level(user)      # 例如: 3 (wizard)
│   │   required_level = wiz_level("(arch)")  # 4
│   │   if user_level >= required_level → 允许
│   │
│   └─ 2.4 显式授权检查
│       grant_commands = grant[user_euid]  # 查询授权映射
│       if "update" in grant_commands → 允许
│
└─ 第三步: 返回结果
    return 0 或 1
```

### 流程3: 数据持久化 (save/restore)

#### 保存流程

```
触发时机:
- 守护进程调用 save()
- 系统关闭前自动保存

执行流程:
1. 验证站点特权映射有效性
   └─ if !mapp(site_privilege) → 初始化为空映射

2. 删除临时校验和
   └─ map_delete(site_privilege, INTERMUD_MUD_NAME)

3. 计算新校验和
   ├─ sum = SEC_SEED (初始种子)
   ├─ foreach (item, val) in site_privilege:
   │   └─ sum = XOR加密(sum, item, val)  # 防篡改
   └─ site_privilege[INTERMUD_MUD_NAME] = crypt(sum, 0)

4. 调用父类save()
   └─ F_SAVE::save() → 写入 /data/securityd.o

保存的数据:
- extend_trusted_read/write
- extend_exclude_read/write
- grant (命令授权映射)
- site_privilege (站点特权映射 + 校验和)
```

#### 恢复流程

```
触发时机:
- create() 中调用 restore()
- 系统启动时自动执行

执行流程:
1. 调用父类restore()
   └─ F_SAVE::restore() → 读取 /data/securityd.o

2. 验证站点特权数据完整性
   ├─ 提取校验和: sec = site_privilege[INTERMUD_MUD_NAME]
   ├─ 重新计算校验和: sum = calculate_checksum(site_privilege)
   ├─ 验证: if crypt(sum, sec) != sec → 数据被篡改
   └─ 如果验证失败 → site_privilege = ([])

3. 重置安全规则
   └─ reset_security() → 合并默认规则和扩展规则

4. 恢复巫师列表
   ├─ 读取 /adm/etc/WIZLIST 文件
   ├─ 解析每一行: "用户名 等级"
   └─ wiz_status[用户名] = 等级

5. 确保授权信息存在
   └─ if !mapp(grant) → grant = ([])
```

---

## 数据流转

### 数据结构关系图

```
┌─────────────────────────────────────────────────────────┐
│                    持久化数据                            │
│                /data/securityd.o                         │
├─────────────────────────────────────────────────────────┤
│ • extend_trusted_read   : mapping                       │
│ • extend_exclude_read   : mapping                       │
│ • extend_trusted_write  : mapping                       │
│ • extend_exclude_write  : mapping                       │
│ • grant                 : mapping (用户→命令列表)       │
│ • site_privilege        : mapping (站点→特权+校验和)    │
└────────────────┬────────────────────────────────────────┘
                 │
                 │ restore() / save()
                 ▼
┌─────────────────────────────────────────────────────────┐
│                  内存运行时数据                          │
├─────────────────────────────────────────────────────────┤
│ nosave (不保存):                                         │
│ • wiz_status   : mapping (用户名→等级状态)              │
│ • wiz_levels   : string[] 等级列表                      │
│ • trusted_read : mapping (默认+扩展合并后)              │
│ • exclude_read : mapping (默认+扩展合并后)              │
│ • trusted_write: mapping (默认+扩展合并后)              │
│ • exclude_write: mapping (默认+扩展合并后)              │
│ • seq          : int 备份序号                           │
└────────────────┬────────────────────────────────────────┘
                 │
                 │ 读取
                 ▼
┌─────────────────────────────────────────────────────────┐
│                  外部配置文件                            │
├─────────────────────────────────────────────────────────┤
│ • /adm/etc/WIZLIST                                      │
│   格式: "用户名 (等级)"                                  │
│   示例:                                                 │
│     mud (admin)                                         │
│     builder (arch)                                      │
│     testuser (wizard)                                   │
└─────────────────────────────────────────────────────────┘
```

### 权限规则数据流

```
┌──────────────────┐      ┌──────────────────┐
│   默认规则       │      │   扩展规则       │
│ (硬编码)         │      │ (可修改)         │
├──────────────────┤      ├──────────────────┤
│ default_trusted  │      │ extend_trusted   │
│ default_exclude  │      │ extend_exclude   │
└────────┬─────────┘      └────────┬─────────┘
         │                         │
         │   combine_rules()       │
         └───────────┬─────────────┘
                     │
                     ▼
         ┌───────────────────────┐
         │    运行时规则         │
         ├───────────────────────┤
         │ trusted_read          │
         │ exclude_read          │
         │ trusted_write         │
         │ exclude_write         │
         └───────────┬───────────┘
                     │
                     ▼
         ┌───────────────────────┐
         │  权限验证函数使用      │
         ├───────────────────────┤
         │ valid_write()         │
         │ valid_read()          │
         └───────────────────────┘
```

---

## 安全模型

### 权限等级体系

```
等级层次 (从低到高):
┌──────────────┬──────────┬────────────────────────┐
│   等级名称   │ 数值索引  │        权限范围         │
├──────────────┼──────────┼────────────────────────┤
│ (player)     │    0     │ 普通玩家,无特殊权限     │
│ (immortal)   │    1     │ 不死者,基本巫师权限     │
│ (apprentice) │    2     │ 学徒,有限开发权限       │
│ (wizard)     │    3     │ 巫师,标准开发权限       │
│ (arch)       │    4     │ 大巫师,高级管理权限     │
│ (admin)      │    5     │ 管理员,最高权限         │
└──────────────┴──────────┴────────────────────────┘

特殊权限:
• ROOT_UID:   超越等级系统的最高权限 (系统对象)
• 临时wizhood: 通过 query_temp("wizhood") 临时提升权限
```

### 信任模型

Security Daemon 采用**分层信任模型**:

```
信任级别 (从高到低):
┌───────────────────────────────────────────┐
│ Level 1: ROOT_UID                         │
│ • 驱动程序级别的最高权限                   │
│ • 绕过所有检查                             │
│ • 只有系统核心对象拥有                     │
└───────────────┬───────────────────────────┘
                │
                ▼
┌───────────────────────────────────────────┐
│ Level 2: (admin) 管理员                   │
│ • 拥有几乎所有权限                         │
│ • 可以修改巫师列表                         │
│ • 可以销毁守护进程                         │
└───────────────┬───────────────────────────┘
                │
                ▼
┌───────────────────────────────────────────┐
│ Level 3: (arch) 大巫师                    │
│ • 标准的高级开发权限                       │
│ • 可以访问大部分系统目录                   │
│ • 不能修改核心系统文件                     │
└───────────────┬───────────────────────────┘
                │
                ▼
┌───────────────────────────────────────────┐
│ Level 4: (wizard) 巫师                    │
│ • 基本开发权限                             │
│ • 可以访问自己的工作目录                   │
│ • 需要显式授权才能使用高级命令              │
└───────────────┬───────────────────────────┘
                │
                ▼
┌───────────────────────────────────────────┐
│ Level 5: (player) 玩家                    │
│ • 无开发权限                               │
│ • 只能访问自己的存档文件                   │
│ • 受最严格的限制                           │
└───────────────────────────────────────────┘
```

### 防御机制

```
1. 防篡改机制
   ├─ 站点特权数据使用 checksum 校验
   ├─ 每次 save() 重新计算校验和
   └─ restore() 时验证数据完整性

2. 防提权机制
   ├─ 用户不能直接修改自己的等级
   ├─ 只有ROOT_UID可以调用 set_status()
   └─ 巫师列表写入文件,防止内存篡改

3. 防绕过机制
   ├─ 所有验证函数检查调用链
   ├─ previous_object() 必须合法
   └─ 排除规则优先于信任规则(黑名单优先)

4. 审计机制
   ├─ 记录所有失败的访问尝试
   ├─ log_file("files", ...) 记录非法操作
   └─ log_file("nosave/security", ...) 记录安全事件
```

---

## 扩展机制

### 如何扩展安全规则

#### 方法1: 使用扩展规则 (推荐)

```lpc
// 在其他代码中 (需要 ROOT 权限)
object security_d;
mapping new_rules;

security_d = load_object(SECURITY_D);

// 添加新的信任规则
new_rules = ([
    "/d/mynewarea" : ({ "(wizard)", "myuser" })
]);

security_d->set_security("extend_trusted_write", new_rules);
security_d->reset_security();  // 重新合并规则
security_d->save();            // 保存到磁盘
```

#### 方法2: 修改默认规则 (需要改代码)

编辑 `security_rules.h` 中的 `query_security()` 函数:

```lpc
case "default_trusted_write":
    return ([
        "/": 		({ "(admin)" }),
        "/d":		({ "(arch)" }),
        "/clone":   ({ "(arch)" }),
        "/kungfu":  ({ "(arch)", "(player)" }),
        // 添加新规则
        "/myadmin": ({ "(admin)" }),  // 只有admin可以写
    ]);
```

### 如何添加新的验证函数

#### 示例: 添加 valid_database() 支持

1. **在 security_data.h 添加数据结构**:
```lpc
// 数据库访问权限映射
private mapping database_access;
```

2. **创建新模块 security_database.h**:
```lpc
/**
 * @file security_database.h
 * @brief 数据库访问控制模块
 */

int valid_database(object caller, string func, mixed *info)
{
    string euid;

    euid = geteuid(caller);

    // ROOT 可以访问任何数据库
    if (euid == ROOT_UID) return 1;

    // 检查database_access映射
    if (func == "connect")
    {
        // 返回数据库密码或0(拒绝连接)
        return database_access[euid];
    }

    // 其他数据库操作
    return database_access[euid] ? 1 : 0;
}
```

3. **在 securityd.c 引入模块**:
```lpc
// 数据库访问控制模块
#include "/adm/daemons/security/security_database.h"
```

4. **在 master.c 中委托**:
```lpc
mixed valid_database(object caller, string func, mixed *info)
{
    object ob;

    if (ob = find_object(SECURITY_D))
        return ob->valid_database(caller, func, info);

    return 0;  // 默认禁止
}
```

---

## 常见问题与解决方案

### Q1: 为什么我的文件无法写入?

**排查步骤**:

1. 检查用户等级
```lpc
write(sprintf("我的等级: %O\n", wizhood(this_player())));
```

2. 检查目录规则
```lpc
mapping rules = SECURITY_D->query_security("trusted_write");
write(sprintf("写入规则: %O\n", rules));
```

3. 查看日志
```bash
cat /log/files  # 查看被拒绝的访问尝试
```

### Q2: 如何给用户临时提权?

```lpc
// 方法1: 设置临时巫师权限
this_player()->set_temp("wizhood", 1);

// 方法2: 使用命令授权
SECURITY_D->grant("username", "update");  // 授权update命令
```

### Q3: 如何备份安全配置?

```lpc
// 保存当前配置
SECURITY_D->save();

// 文件位置: /data/securityd.o
// 手动备份:
cp /data/securityd.o /backup/securityd_backup_YYYYMMDD.o
```

---

## 性能考虑

### 优化点

1. **缓存机制**: 巫师列表在内存中缓存,避免重复读文件
2. **短路求值**: 权限检查按优先级排序,高权限用户立即返回
3. **最小化磁盘IO**: 只在必要时调用 save(),大部分数据在内存

### 性能指标

```
典型操作耗时 (估算):
├─ get_status()      : <0.1ms  (内存查找)
├─ valid_write()     : 0.1-1ms (递归检查3-5层)
├─ valid_grant()     : 0.1-0.5ms (映射查找)
└─ save()/restore()  : 10-50ms (磁盘IO)
```

---

## 总结

Security Daemon 是MUD系统安全的核心,通过模块化设计实现了:

✅ **完整的权限控制体系** - 从用户等级到文件访问的全方位控制
✅ **灵活的扩展机制** - 支持动态添加规则而不修改核心代码
✅ **强大的安全防护** - 防篡改、防提权、审计追踪
✅ **清晰的代码结构** - 模块化设计,易于理解和维护

通过理解本文档,您应该能够:
- 理解整个安全系统的运行机制
- 正确配置和扩展安全规则
- 排查权限相关问题
- 安全地修改和维护 Security Daemon

---

**文档版本**: 2.0
**最后更新**: 2025-01-17
**作者**: Lu Dexiang
**联系方式**: 参见项目文档
