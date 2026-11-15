// shouxi.h - 首席弟子相关的数据和函数
// 由familyd.c包含

// 首席弟子数据
mapping family_leader = ([]);         // 门派首席弟子记录
mapping family_leader_bouns = ([]);   // 门派首席弟子奖励记录

// 返回门派竞技报名时间
public mapping query_family_jj_sign_time()
{
    mapping jj_sign_time = ([
        "day": 6,     // 周六
        "hour": 20,   // 20点
        "pre": 9,     // 提前9小时报名
        "time": 20,   // 持续20分钟
    ]);

    return jj_sign_time;
}

// 设置门派首席弟子
public void set_family_leader(string fname, string id)
{
    family_leader[fname] = id;
    save();
}

// a 
public string query_family_leader(string fname)
{
    if(!fname || !mapp(family_leader) || undefinedp(family_leader[fname]))
        return "";
    return family_leader[fname];
}

//判断是否是门派首席弟子
public int is_family_leader(object player)
{
    string family_name = player->query("family/family_name");
    
    //如果门派名称为空，返回0
    if (!family_name)
        return 0;

    //如果门派名称在family_leader中，返回1
    if (family_leader[family_name] == player->query("id"))
        return 1;

    //否则返回0
    return 0;
}

// 初始化首席弟子数据
private void init_shouxi_data()
{
    if(!mapp(family_leader))
        family_leader = ([]);
    if(!mapp(family_leader_bouns))
        family_leader_bouns = ([]);
}

// 清理首席弟子数据（每周六执行）
public void reset_shouxi_data()
{
    family_leader = ([]);
}
