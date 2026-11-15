# 主线任务系统 - 切磋任务类型

## 功能概述

切磋任务是主线任务系统的一种新任务类型，玩家需要与指定门派的NPC进行切磋，并在切磋中获胜才能完成任务。

## 实现原理

1. 在任务配置中定义切磋任务类型（SPAR_TARGET）
2. 当玩家提交任务时，检查是否为切磋任务
3. 如果是切磋任务且未完成，提示玩家是否开始切磋
4. 创建切磋房间，生成NPC，并将玩家传送到切磋房间
5. 玩家与NPC进行切磋，当玩家获胜时，NPC的lost函数会被调用，增加任务完成计数
6. 切磋结束后，玩家返回原来的位置，可以提交任务获取奖励

## 使用方法

### 定义切磋任务

在 `main_task_config.h` 中使用 `SPAR_TARGET` 宏定义切磋任务：

```c
// 示例：定义一个与华山派切磋的任务，战斗力为500，使用默认NPC模板
SPAR_TARGET("华山派", 500)

// 示例：定义一个与华山派切磋的任务，战斗力为500，使用自定义NPC模板
SPAR_TARGET("华山派", 500, "/adm/special_ob/main_task_doc/npc/huashan_master")
```

### 完整任务配置示例

```c
30: TASK_CONFIG(
    "主线任务1-2-1",
    "为了提升自己的武学修为，你决定与华山派高手切磋一番。",
    ATTR_REWARD((["combat_exp": 5000, "potential": 10000])),
    SPAR_TARGET("华山派", 500),
    "与华山派高手切磋，提升自己的武学修为。",
    TASK_PLACE("华山派广场", "/d/huashan/square"),
    TASK_REQUIREMENTS((["level": 200]))
),
```

### 任务流程

1. 玩家查看任务：`main_task`
2. 玩家提交任务：`main_task submit`
3. 系统提示是否开始切磋
4. 玩家选择"开始切磋"或输入`main_task start_spar <任务ID>`
5. 系统创建切磋房间，生成NPC，开始切磋
6. 玩家在切磋中获胜，任务完成
7. 玩家返回原来的位置，可以继续提交任务获取奖励

## 注意事项

1. 切磋任务可以在同一节点的任务中多次出现
2. 切磋任务的难度由门派和战斗力参数决定
3. 切磋使用游戏内置的战斗系统，通过fight命令进行
4. 切磋失败可以重新尝试

## 技术实现

主要文件：
- `main_task_doc/h/main_task_target.h`：定义切磋任务类型
- `main_task_doc/map/spar_room.c`：切磋房间实现
- `main_task_doc/npc/combat/base/sparring_base.c`：切磋NPC基类
- `main_task_master.c`：主任务管理器，处理切磋任务逻辑
- `cmds/quest/main_task.c`：主任务命令，添加切磋任务处理

## 扩展建议

1. 可以为不同门派的切磋对手设置不同的技能组合
2. 可以根据玩家的门派和等级动态调整切磋难度
3. 可以添加切磋奖励，如额外的经验或潜能
4. 可以记录玩家的切磋历史，作为成就系统的一部分

## 主线任务系统

本系统是武侠黎明游戏的主线任务系统，负责管理玩家的主线任务流程。

### 系统架构

主线任务系统采用模块化设计，分为以下几个部分：

1. **主入口模块** (`main_task_master.c`)
   - 负责协调各个子模块
   - 提供对外接口
   - 作为模块间通信的中心枢纽

2. **核心管理模块** (`main_task_core.c`)
   - 任务状态管理
   - 任务条件检查
   - 任务发布与提交

3. **UI显示模块** (`main_task_ui.c`)
   - 任务界面显示
   - 任务信息转译
   - 任务进度展示

4. **战斗模块** (`main_task_combat.c`)
   - 战斗房间创建
   - 切磋系统
   - 战斗NPC管理

5. **奖励模块** (`main_task_reward.c`)
   - 任务奖励发放
   - 属性奖励处理
   - 物品奖励处理

6. **配置模块** (`h/main_task_config.h`)
   - 任务配置数据
   - 任务目标定义
   - 任务奖励定义

### 模块间调用关系

为了降低模块间的耦合度，各个模块之间不直接相互调用，而是通过主入口模块 `main_task_master.c` 进行调度：

1. 每个模块在初始化时加载主入口模块：
   ```c

   // 初始化函数
   void create()
   {
       seteuid(getuid());
   }
   ```

2. 当需要调用其他模块的功能时，通过主入口模块进行调用：
   ```c
   // 例如，在UI模块中调用核心模块的函数
   quest_id = main_task_master->get_player_current_quest(me);
   ```

3. 主入口模块负责将调用转发到对应的模块：
   ```c
   // 在main_task_master.c中
   int get_player_current_quest(object me)
   {
       return "/adm/special_ob/main_task_doc/main_task_core"->get_player_current_quest(me);
   }
   ```

这种设计模式类似于"中介者模式"，主入口模块作为中介者，协调各个子模块之间的通信，降低了模块间的直接依赖关系。

### 目录结构

```
adm/special_ob/main_task_doc/
├── README.md                 # 本文档
├── main_task_core.c          # 核心管理模块
├── main_task_ui.c            # UI显示模块
├── main_task_combat.c        # 战斗模块
├── main_task_reward.c        # 奖励模块
├── h/
│   ├── main_task_config.h    # 任务配置
│   ├── main_task_core.h      # 核心模块头文件
│   ├── main_task_ui.h        # UI模块头文件
│   ├── main_task_combat.h    # 战斗模块头文件
│   ├── main_task_reward.h    # 奖励模块头文件
│   └── main_task_target.h    # 任务目标定义
├── map/
│   ├── combat_room.c         # 战斗房间
│   └── spar_room.c           # 切磋房间
└── npc/
    └── ...                   # 任务相关NPC
```

### 使用方法

在游戏中，可以通过以下方式使用主线任务系统：

1. 显示当前任务：`main_task show`
2. 提交任务：`main_task submit`
3. 开始切磋任务：`main_task start_spar <任务ID>`

### 开发说明

1. 添加新任务类型时，需要在核心模块中添加相应的处理逻辑
2. 修改任务配置时，只需修改 `h/main_task_config.h` 文件
3. 添加新的任务奖励类型时，需要在奖励模块中添加相应的处理逻辑
4. 添加新模块时，需要在主入口模块中添加相应的接口函数

### 维护者

- Lu dexiang

### 更新日志

- 2024-06-01: 系统重构，采用模块化设计，优化模块间调用关系
- 2024-02-26: 添加切磋任务类型
- 2024-02-24: 添加奖励系统
- 2024-02-23: 系统初始版本 