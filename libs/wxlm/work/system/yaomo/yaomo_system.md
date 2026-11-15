# 妖魔系统开发文档

## 一、系统概述

妖魔系统是一个基于 JSON 配置的自动化 NPC 生成系统,通过读取 JSON 配置文件自动创建妖魔 NPC 对象,无需为每个妖魔单独创建 `.c` 文件。该系统简化了妖魔 NPC 的创建流程,便于批量管理和配置。

### 核心特性

- **JSON 驱动**: 所有妖魔数据通过 JSON 配置文件定义
- **自动生成**: 系统自动根据配置创建完整的妖魔 NPC 对象
- **简化武功**: 妖魔仅配置三大基础武功(内功、轻功、招架),无需复杂的特殊武功
- **独立技能**: 妖魔技能独立于武学系统,通过统一接口读取 JSON 配置
- **智能战斗 AI**: 基于优先级的技能释放系统
- **灵活掉落**: 支持经验、潜能、物品掉落的完整配置

---

## 二、目录结构

```
system/yaomo/
├── yaomo_system.md          # 本开发文档
├── yaomo_daemon.c           # 妖魔系统守护进程
├── yaomo_npc.c              # 妖魔 NPC 基类
├── config/                  # JSON 配置文件目录
│   ├── yaomo_001.json      # 妖魔配置示例
│   ├── yaomo_002.json
│   └── ...
└── skills/                  # 妖魔技能处理
    └── yaomo_skill.c       # 妖魔技能统一接口
```

---

## 三、JSON 配置规范

### 3.1 完整配置示例

```json
{
  "id": "yaomo_001",
  "name": "血魔",
  "name_id": ["xue mo", "xuemo", "mo"],
  "title": "嗜血",
  "long": "一只浑身散发着血腥气息的魔物,双眼猩红,獠牙毕露。\n它的身体仿佛被鲜血浸透,每一次呼吸都带着令人窒息的杀意。",
  "level": 10,
  "gender": "男性",
  "age": 500,
  "attitude": "aggressive",

  "base_attributes": {
    "str": 30,
    "int": 20,
    "con": 35,
    "dex": 25
  },

  "combat_attributes": {
    "qi": 50000,
    "jing": 5000,
    "neili": 1000,
    "jiali": 100
  },

  "basic_skills": {
    "force": 100,
    "dodge": 100,
    "parry": 100
  },

  "skills": [
    {
      "id": "xuemo_skill_001",
      "name": "血爆术",
      "description": "$N仰天长啸,浑身血气爆发,化作无数血刃向$n袭去!",
      "damage_type": "perform",
      "base_damage": 10000,
      "damage_ratio": {
        "level": 100,
        "str": 50
      },
      "cooldown": 3,
      "priority": 10,
      "condition": {
        "hp_percent": 100,
        "enemy_count": 1
      }
    },
    {
      "id": "xuemo_skill_002",
      "name": "血魔狂暴",
      "description": "$N双眼血光大盛,血色气息笼罩全场!",
      "damage_type": "jing",
      "base_damage": 1000,
      "damage_ratio": {
        "level": 50,
        "int": 30
      },
      "cooldown": 5,
      "priority": 8,
      "condition": {
        "hp_percent": 50,
        "enemy_count": 1
      }
    },
    {
      "id": "xuemo_skill_003",
      "name": "血魔献祭",
      "description": "$N燃烧自身精血,爆发出恐怖的力量!",
      "damage_type": "ignore_armor",
      "base_damage": 15000,
      "damage_ratio": {
        "level": 150,
        "con": 80
      },
      "cooldown": 10,
      "priority": 15,
      "condition": {
        "hp_percent": 20,
        "enemy_count": 1
      }
    }
  ],

  "drops": {
    "exp": 100000,
    "potential": 50000,
    "items": [
      {
        "path": "/clone/yaomo/xuemo_jingxue",
        "name": "血魔精血",
        "chance": 20,
        "amount": 1
      },
      {
        "path": "/clone/misc/gold",
        "name": "黄金",
        "chance": 50,
        "amount": 10
      }
    ]
  }
}
```

### 3.2 配置字段详解

#### 基础信息

| 字段 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `id` | string | 是 | 妖魔唯一标识符 |
| `name` | string | 是 | 妖魔名称 |
| `name_id` | array | 是 | ID 数组,用于识别命令 |
| `title` | string | 否 | 妖魔称号 |
| `long` | string | 是 | 妖魔详细描述 |
| `level` | int | 是 | 妖魔等级 (影响属性计算) |
| `gender` | string | 是 | 性别: "男性" / "女性" / "无性" |
| `age` | int | 是 | 年龄 |
| `attitude` | string | 是 | 态度: "aggressive" / "peaceful" |

#### 属性配置

**base_attributes (基础四维属性)**

| 字段 | 类型 | 说明 |
|------|------|------|
| `str` | int | 臂力 (影响物理攻击) |
| `int` | int | 悟性 (影响精神攻击) |
| `con` | int | 根骨 (影响生命值) |
| `dex` | int | 身法 (影响闪避) |

**combat_attributes (战斗属性)**

| 字段 | 类型 | 说明 | 计算规则 |
|------|------|------|----------|
| `qi` | int | 气血 | 基础: level * 5000 |
| `jing` | int | 精神 | 基础: level * 500 |
| `neili` | int | 内力 | 基础: level * 100 |
| `jiali` | int | 加力 | 基础: level * 10 |

> **注意**: 配置中的数值为基础值,实际值会根据等级和属性自动计算调整。

#### 基础技能配置

**basic_skills (三大基础技能)**

妖魔只需要配置三个基础技能的等级,不需要具体的武功名称:

| 字段 | 类型 | 说明 |
|------|------|------|
| `force` | int | 基本内功等级 |
| `dodge` | int | 基本轻功等级 |
| `parry` | int | 基本招架等级 |

**等级计算规则**: 基础技能等级 = 妖魔等级 × 10

示例:
- 1 级妖魔 → 10 级基础技能
- 10 级妖魔 → 100 级基础技能
- 50 级妖魔 → 500 级基础技能

> **重要**: 妖魔不需要学习具体武功,也不需要激发(enable)武功。妖魔的战斗技能完全通过下方的 `skills` 配置独立实现,这三个基础技能仅影响妖魔的基础战斗属性(命中、闪避、招架等)。

#### 技能配置

**skills (技能列表)**

每个技能包含以下字段:

| 字段 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `id` | string | 是 | 技能唯一标识 |
| `name` | string | 是 | 技能名称 |
| `description` | string | 是 | 技能描述 (支持 $N/$n 变量) |
| `damage_type` | string | 是 | 伤害类型 (见下表) |
| `base_damage` | int | 是 | 基础伤害值 |
| `damage_ratio` | object | 是 | 伤害加成比例 |
| `cooldown` | int | 是 | 冷却时间 (心跳数) |
| `priority` | int | 是 | 优先级 (越高越优先) |
| `condition` | object | 是 | 释放条件 |

**伤害类型 (damage_type)**

| 类型 | 说明 | 实现接口 | 特点 |
|------|------|----------|------|
| `perform` | 单招伤害 | `COMBAT_D->do_damage()` | 标准技能伤害,受护甲完整计算,同时造成damage和wound |
| `ignore_armor` | 真实伤害 | `COMBAT_D->real_damage()` | 无视护甲但仍受破甲影响,固定伤害,wound为damage的一半 |
| `jing` | 精神伤害 | `receive_damage("jing")` | 攻击精神值,护甲减免降低,由于玩家气血:精神通常为10:1,同等伤害值对精神影响更大 |

**伤害计算公式**

```
最终伤害 = base_damage + (妖魔等级 × damage_ratio.level) + (对应属性 × damage_ratio.属性)
```

示例:
```json
{
  "base_damage": 10000,
  "damage_ratio": {
    "level": 100,
    "str": 50
  }
}
```

对于 10 级妖魔 (臂力 30):
```
最终伤害 = 10000 + (10 × 100) + (30 × 50) = 10000 + 1000 + 1500 = 12500
```

**释放条件 (condition)**

| 字段 | 类型 | 说明 |
|------|------|------|
| `hp_percent` | int | 血量百分比阈值 (0-100) |
| `enemy_count` | int | 最少敌人数量 |

#### 掉落配置

**drops (掉落奖励)**

| 字段 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `exp` | int | 是 | 击败妖魔获得的经验值 |
| `potential` | int | 是 | 击败妖魔获得的潜能值 |
| `items` | array | 否 | 掉落物品列表 |

**items 物品配置**

| 字段 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `path` | string | 是 | 物品文件路径 |
| `name` | string | 是 | 物品名称 (用于提示) |
| `chance` | int | 是 | 掉落概率 (0-100) |
| `amount` | int | 是 | 掉落数量 |

---

## 四、系统实现

### 4.1 妖魔守护进程 (yaomo_daemon.c)

负责加载和管理所有妖魔配置。

**核心函数**

```c
/**
 * @brief 加载妖魔配置文件
 * @param string config_id 妖魔配置 ID
 * @return mapping 配置数据
 */
mapping load_yaomo_config(string config_id);

/**
 * @brief 创建妖魔 NPC 对象
 * @param string config_id 妖魔配置 ID
 * @return object 妖魔 NPC 对象
 */
object create_yaomo(string config_id);

/**
 * @brief 获取所有妖魔配置列表
 * @return string* 配置 ID 列表
 */
string* query_all_yaomo();
```

### 4.2 妖魔 NPC 基类 (yaomo_npc.c)

所有妖魔 NPC 的基础类。

**核心功能**

1. **属性初始化**: 根据 JSON 配置自动设置属性
2. **技能系统**: 集成妖魔独立技能系统
3. **战斗 AI**: 基于优先级的智能技能释放
4. **掉落处理**: 自动处理经验、潜能、物品掉落

**关键函数**

```c
/**
 * @brief 根据配置初始化妖魔
 * @param mapping config 配置数据
 */
void setup_yaomo(mapping config);

/**
 * @brief 心跳函数,处理战斗 AI
 */
void heart_beat();

/**
 * @brief 选择并释放技能
 * @param object* enemy 敌人列表
 */
void cast_skill(object* enemy);

/**
 * @brief 死亡处理,发放奖励
 */
void die();
```

### 4.3 妖魔技能接口 (yaomo_skill.c)

统一处理妖魔技能的读取和释放。

**核心函数**

```c
/**
 * @brief 从 JSON 读取技能数据
 * @param string config_id 妖魔配置 ID
 * @return mapping* 技能列表
 */
mapping* load_skills(string config_id);

/**
 * @brief 计算技能伤害
 * @param object caster 施法者
 * @param mapping skill 技能数据
 * @return int 最终伤害值
 */
int calculate_damage(object caster, mapping skill);

/**
 * @brief 检查技能释放条件
 * @param object caster 施法者
 * @param mapping skill 技能数据
 * @param object* enemy 敌人列表
 * @return int 是否满足条件
 */
int check_condition(object caster, mapping skill, object* enemy);

/**
 * @brief 执行技能效果
 * @param object caster 施法者
 * @param mapping skill 技能数据
 * @param object* target 目标列表
 */
void perform_skill(object caster, mapping skill, object* target);
```

---

## 五、战斗 AI 设计

### 5.1 技能释放逻辑

```
每次心跳 (heart_beat):
1. 检查是否有敌人
2. 遍历所有技能:
   - 检查冷却时间
   - 检查释放条件 (血量/敌人数量)
   - 计算优先级
3. 选择优先级最高且可用的技能
4. 执行技能效果
5. 记录冷却时间
```

### 5.2 优先级系统

- **优先级范围**: 1-20
- **推荐配置**:
  - 普通技能: 5-10
  - 重要技能: 11-15
  - 必杀技: 16-20

### 5.3 冷却时间

- 单位: 心跳数 (通常 1 心跳 = 2 秒)
- 建议: 普通技能 3-5,强力技能 8-15

### A. 常用宏定义

```c
#define YAOMO_D       "/system/yaomo/yaomo_daemon"
#define YAOMO_NPC     "/system/yaomo/yaomo_npc"
#define YAOMO_SKILL   "/system/yaomo/skills/yaomo_skill"
#define YAOMO_CONFIG  "/system/yaomo/config/"
```