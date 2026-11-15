// tianjige.h - 天机阁比武大会和积分排名相关的数据和函数
// 由familyd.c包含

// 比武大会数据
mapping fight_classify = ([  // 比武大会分级
    "潜龙":({}),
    "宗师":({}),
    "尊者":({}),
]);

mapping fightPointList = ([]);       // 比武积分列表
mapping fight_chinese_name = ([]);   // 比武积分中文名字缓存

// 返回比武大赛分类信息
public mapping query_fight_classify()
{
    return fight_classify;
}

// 返回比武积分列表
public mapping query_fight_point_list()
{
    return fightPointList;
}

// 查询指定ID的比武积分
public mixed query_fight_point(string id)
{
    if(!id || !mapp(fightPointList) || undefinedp(fightPointList[id]))
        return 0;
    return fightPointList[id];
}

// 设置比武积分
public int set_fight_point(mapping data)
{
    if(!mapp(data) || !sizeof(data))
        return 0;

    // 缓存这些名字
    fight_chinese_name = ([]);
    foreach(string id in keys(data))
    {
        object ob;
        if(!objectp(ob = find_player(id)))
        {
            fight_chinese_name[id] = "隐退高手";
            continue;
        }
        fight_chinese_name[id] = ob->name(1);
    }

    fightPointList = data;
    save();
    return 1;
}

// 设置比武大会参赛选手分类
public int set_fight_classify(mapping data)
{
    if(!mapp(data) || !sizeof(data))
        return 0;
    fight_classify = data;
    save();
    return 1;
}

// 读取缓存的中文名字
public string query_wudao_chinese_name(string id)
{
    if(!id || !mapp(fight_chinese_name) || undefinedp(fight_chinese_name[id]))
        return "隐退高手";
    return fight_chinese_name[id];
}

// 查询指定ID在某个榜单中的排名
public int query_fight_rank(string id, string type)
{
    //原先的数组已经排序
    if (!sizeof(fight_classify[type]))
        return 0;

    if (member_array(id, fight_classify[type]) == -1)
        return 0;
    
    return member_array(id, fight_classify[type]) + 1;
}

// 初始化天机阁数据
private void init_tianjige_data()
{
    if (!mapp(fightPointList))
        fightPointList = ([]);
    if (!mapp(fight_chinese_name))
        fight_chinese_name = ([]);
    if (!mapp(fight_classify))
        fight_classify = ([
            "潜龙":({}),
            "宗师":({}),
            "尊者":({}),
        ]);
}
