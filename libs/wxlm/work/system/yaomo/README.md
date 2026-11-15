# 妖魔系统使用说明

## 快速开始

### 1. 创建妖魔配置

在 `/system/yaomo/config/` 目录下创建 JSON 配置文件，例如 `yaomo_003.json`：

```json
{
  "id": "yaomo_003",
  "name": "雷魔",
  "name_id": ["lei mo", "leimo", "mo"],
  "title": "雷霆",
  "long": "妖魔的详细描述...",
  "level": 20,
  "gender": "男性",
  "age": 1000,
  "attitude": "aggressive",

  "base_attributes": {
    "str": 35,
    "int": 30,
    "con": 40,
    "dex": 30
  },

  "combat_attributes": {
    "qi": 100000,
    "jing": 10000,
    "neili": 2000,
    "jiali": 200
  },

  "basic_skills": {
    "force": 200,
    "dodge": 200,
    "parry": 200
  },

  "skills": [
    {
      "id": "leimo_skill_001",
      "name": "雷霆万钧",
      "description": "$N召唤雷霆之力，无数雷电轰向$n！",
      "damage_type": "perform",
      "base_damage": 20000,
      "damage_ratio": {
        "level": 200,
        "str": 100
      },
      "cooldown": 4,
      "priority": 12,
      "condition": {
        "hp_percent": 100,
        "enemy_count": 1
      }
    }
  ],

  "drops": {
    "exp": 200000,
    "potential": 100000,
    "items": [
      {
        "path": "/clone/money/gold",
        "name": "黄金",
        "chance": 70,
        "amount": 20
      }
    ]
  }
}
```

### 2. 在房间中生成妖魔

在房间文件的 `create()` 或 `reset()` 函数中：

```c
void create()
{
    // ... 房间设置 ...

    // 生成妖魔
    object yaomo;
    yaomo = load_object("/system/yaomo/yaomo_daemon")->create_yaomo("yaomo_001");
    if (objectp(yaomo))
    {
        yaomo->move(this_object());
    }
}
```

### 3. 测试妖魔

进入测试房间：
```
goto /d/yaomo_test/yaomo_test_room
```

查看可用妖魔列表：
```
list
```

召唤妖魔进行测试：
```
summon yaomo_001
```

### 4. 管理命令

```c
// 加载守护进程
load_object("/system/yaomo/yaomo_daemon")

// 创建妖魔
->create_yaomo("yaomo_001")

// 查看所有妖魔配置
->query_all_yaomo()

// 重新加载配置
->reload_config("yaomo_001")

// 重新加载所有配置
->reload_all_configs()

// 清除缓存
->clear_cache("yaomo_001")
->clear_all_cache()
```

## 配置字段说明

### 伤害类型

- `perform`: 标准技能伤害，受护甲完整计算
- `ignore_armor`: 真实伤害，无视护甲但仍受破甲影响
- `jing`: 精神伤害，攻击精神值

### 技能优先级

- 1-5: 低优先级（常规技能）
- 6-10: 中优先级（主要技能）
- 11-15: 高优先级（强力技能）
- 16-20: 最高优先级（终极技能）

### 冷却时间

单位为心跳数（通常 1 心跳 = 2 秒）：
- 3-5: 短冷却（常规技能）
- 6-8: 中等冷却（强力技能）
- 9-15: 长冷却（终极技能）

## 注意事项

1. **配置 ID 必须唯一**
2. **技能 ID 必须唯一**（建议格式：`妖魔ID_skill_序号`）
3. **掉落物品路径必须存在**
4. **attitude 设为 "aggressive" 会主动攻击**
5. **等级计算**：基础技能等级建议为妖魔等级 × 10
6. **物品掉落机制**：
   - 物品会直接掉落到击杀玩家的背包中
   - 对于可叠加物品（如黄金），配置中的 `amount` 会自动设置为物品的堆叠数量
   - 对于不可叠加物品，`amount` 字段会被忽略，只掉落一个

## 已有示例

- `yaomo_001` - 血魔 (Lv.10)
- `yaomo_002` - 冰魄 (Lv.15)

测试房间：`/d/yaomo_test/yaomo_test_room`
