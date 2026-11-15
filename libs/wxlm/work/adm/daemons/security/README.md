# Security Daemon 模块化结构说明

## 概述

`securityd.c` 已从原来的1065行单一文件重构为模块化结构,拆分为9个功能模块,提高代码可读性和可维护性。

## 版本信息

- **原版本**: 1.0 (单文件1065行)
- **新版本**: 2.0 (主文件67行 + 9个模块)
- **重构日期**: 2025-01-17
- **兼容性**: 100%向后兼容,所有公共接口保持不变

## 文件结构

```
/adm/daemons/
├── securityd.c                    # 主文件(67行)
├── securityd_old_backup.c         # 原版本备份
└── security/                      # 子模块目录
    ├── security_data.h            # 数据结构和常量定义
    ├── security_init.h            # 初始化与数据持久化
    ├── security_rules.h           # 安全规则管理
    ├── security_wizard.h          # 巫师等级管理
    ├── security_permission.h      # 文件权限验证(核心)
    ├── security_object.h          # 对象安全验证
    ├── security_command.h         # 命令授权管理
    ├── security_site.h            # 站点特权管理
    └── security_backup.h          # 文件备份功能
```

## 模块说明

### 1. security_data.h - 数据结构和常量定义
**功能**:
- 定义所有常量(MAX_SITE_PRIVILEGE_SIZE, CHECKSUM_LENGTH等)
- 定义全局变量(wiz_status, wiz_levels, trusted_read等)
- query_save_file() 函数

**关键常量**:
- `MAX_SITE_PRIVILEGE_SIZE`: 1024
- `CHECKSUM_LENGTH`: 32
- `BACKUP_SEQ_MAX`: 10000
- `SEC_SEED`: 加密种子

### 2. security_init.h - 初始化与数据持久化
**功能**:
- create() - 创建守护进程
- restore() - 恢复数据
- save() - 保存数据
- calculate_privilege_checksum() - 校验和计算(私有)

**关键流程**:
1. 验证站点特权信息合法性
2. 重置安全信息
3. 恢复巫师列表
4. 确保授权信息存在

### 3. security_rules.h - 安全规则管理
**功能**:
- query_security() - 查询安全配置
- set_security() - 设置安全规则
- combine_rules() - 合并规则
- reset_security() - 重置规则

**权限要求**: 所有函数需要 ROOT 权限

### 4. security_wizard.h - 巫师等级管理
**功能**:
- query_wiz_levels() - 获取等级列表
- query_wizlist() - 获取巫师列表
- get_status() - 获取用户状态
- get_wiz_level() - 获取等级数值
- set_status() - 设置用户状态
- get_wizlist() - 获取巫师列表(推荐)

**等级顺序**:
```
(player) < (immortal) < (apprentice) < (wizard) < (arch) < (admin)
```

### 5. security_permission.h - 文件权限验证(核心)
**功能**:
- valid_write() - 验证写权限
- valid_read() - 验证读权限
- check_directory_permission() - 递归检查目录权限(私有)
- get_user_euid() - 获取用户ID(私有)

**验证流程**:
1. 获取用户有效ID
2. 检查特殊情况(日志、存档等)
3. 递归检查目录权限
4. 记录非法访问尝试

### 6. security_object.h - 对象安全验证
**功能**:
- valid_seteuid() - 验证euid设置权限
- valid_bind() - 验证函数绑定权限

**安全策略**:
- ROOT可以设置任意euid
- 系统对象可以设置任意euid
- admin可以设置非admin的euid

### 7. security_command.h - 命令授权管理
**功能**:
- valid_grant() - 验证命令授权
- grant() - 授权命令
- remove_grant() - 收回授权
- query_grant() - 查询用户授权
- query_grant_users() - 查询被授权用户

**授权机制**:
1. 检查权限等级是否满足
2. 检查是否有显式授权
3. ROOT和admin可执行任何命令

### 8. security_site.h - 站点特权管理
**功能**:
- set_site_privilege() - 设置站点特权
- query_site_privilege() - 查询站点特权

**权限要求**: ROOT权限

### 9. security_backup.h - 文件备份功能
**功能**:
- backup_file() - 备份文件
- remove() - 销毁守护进程

**备份策略**:
- 只备份非ROOT和非admin用户修改的文件
- 备份路径: `/log/file/用户ID/年-月-日/序号-文件名`

## 重构优势

### 1. 可读性提升
- **重构前**: 1065行单文件,难以快速定位功能
- **重构后**: 每个模块职责清晰,平均100-200行

### 2. 可维护性提升
- 模块间解耦,修改某个功能不影响其他模块
- 每个模块都有清晰的文档注释
- 函数原型声明集中管理

### 3. 代码复用
- 提取了私有辅助函数:
  - `check_directory_permission()` - 消除40+行重复代码
  - `get_user_euid()` - 统一用户ID提取逻辑
  - `calculate_privilege_checksum()` - 统一校验和计算

### 4. 性能无损
- 编译时所有模块内联到主文件
- 运行时性能与原版完全相同
- 无额外函数调用开销

## 测试验证

所有核心功能已通过测试:
```bash
# 编译测试
echo "file_name=/adm/daemons/securityd" | curl --noproxy "*" -X POST http://localhost:8092/update_code/update_file --data @-
✅ 编译成功

# 功能测试
- get_status() ✅
- query_wiz_levels() ✅
- query_wizlist() ✅
- valid_write() ✅
- valid_read() ✅
```

## 回滚方案

如需回滚到原版本:
```bash
cd /adm/daemons/
rm securityd.c
cp securityd_old_backup.c securityd.c
```

## 开发指南

### 修改某个模块
1. 编辑对应的 `.h` 文件
2. 重新编译 `securityd.c`
3. 测试相关功能

### 添加新功能
1. 在对应模块中添加函数
2. 如需暴露给外部,在主文件中添加函数声明
3. 编译测试

### 注意事项
- 所有私有函数使用 `private` 修饰符
- 保持函数接口向后兼容
- 修改后必须测试核心功能

## 联系方式

如有问题,请联系:
- **作者**: Lu Dexiang
- **日期**: 2025-01-17
