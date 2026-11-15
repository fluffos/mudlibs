// rank.h - 门派等级相关的常量、数据和函数
// 由familyd.c包含

// 玩家门派等级对应的职位名称
nosave string *rank_names = ({
    "杂役弟子", "外门弟子", "内门弟子", "真传弟子",
    "执事", "长老", "传功长老", "执法长老", "副掌门"
});

// 查询玩家的门派等级
public int query_family_player_level(object player)
{
    int level = player->query("gongxian");
    if (level > 60000)
        return 9;
    else if (level > 45500)
        return 8;
    else if (level > 35000)
        return 7;
    else if (level > 24500)
        return 6;
    else if (level > 17500)
        return 5;
    else if (level > 10500)
        return 4;
    else if (level > 7000)
        return 3;
    else if (level > 3500)
        return 2;
    else
        return 1;
}

// 查询玩家的门派职位名称
public string query_family_player_title(object player)
{
    int level = query_family_player_level(player);
    return rank_names[level - 1];
}

// 获取玩家门派等级对应的练功效果加成
public mapping get_practice_buff(int level)
{
    mapping buff_info = ([
        1: ([ "duration": 0, "effect": 0 ]),    // 杂役弟子
        2: ([ "duration": 1, "effect": 50 ]),   // 外门弟子
        3: ([ "duration": 1, "effect": 100 ]),  // 内门弟子
        4: ([ "duration": 1, "effect": 150 ]),  // 真传弟子
        5: ([ "duration": 2, "effect": 200 ]),  // 执事
        6: ([ "duration": 2, "effect": 250 ]),  // 长老
        7: ([ "duration": 3, "effect": 300 ]),  // 传功长老
        8: ([ "duration": 3, "effect": 350 ]),  // 执法长老
        9: ([ "duration": 4, "effect": 400 ]),  // 副掌门
    ]);
    
    return buff_info[level];
}

// 根据门派等级获取每日资源奖励
public mapping get_daily_resources(int level)
{
    mapping resources = ([
        1: ([ "potential": 0, "points": 0 ]),       // 杂役
        2: ([ "potential": 5000, "points": 50 ]),   // 外门弟子
        3: ([ "potential": 10000, "points": 100 ]), // 内门弟子
        4: ([ "potential": 20000, "points": 150 ]), // 真传弟子
        5: ([ "potential": 40000, "points": 200 ]), // 执事
        6: ([ "potential": 60000, "points": 250 ]), // 长老
        7: ([ "potential": 80000, "points": 300 ]), // 传功长老
        8: ([ "potential": 100000, "points": 400 ]),// 执法长老
        9: ([ "potential": 150000, "points": 500 ]),// 副掌门
    ]);

    return resources[level];
} 