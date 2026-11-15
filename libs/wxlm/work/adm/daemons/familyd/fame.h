// fame.h - 门派声望相关的常量、数据和函数
// 由familyd.c包含

// 门派声望最大值
#define MAX_FAMILY_FAME     1000000000

// 门派声望数据
mapping family_fame = ([
    "少林寺"   : 10000000,
    "武当派"   : 8000000,
    "丐帮"     : 7000000,
    "全真教"   : 5000000,
    "华山派"   : 4500000,
    "段氏皇族" : 4000000,
    "慕容世家" : 4000000,
    "雪山寺"   : 3500000,
    "灵鹫宫"   : 3500000,
    "峨嵋派"   : 3000000,
    "桃花岛"   : 2500000,
    "神龙教"   : 2000000,
    "古墓派"   : 1500000,
    "星宿派"   : 1200000,
    "逍遥派"   : 1000000,
    "明教"     : 1000000,
    "日月神教" : 900000,
    "血刀门"   : 800000,
    "华山剑宗" : 600000,
    "欧阳世家" : 500000,
    "关外胡家" : 400000,
    "四象门"   : 300000,
    "白帝城"   : 200000,
    "魔教"     : 100000,
    "移花宫"   : 100000,
]);

// 缓存昨天的门派声望信息
mapping last_family_fame;

// 门派ID对应的门派名字
nosave mapping family_name = ([
    "shaolin"  : "少林寺",
    "wudang"   : "武当派",
    "gaibang"  : "丐帮",
    "quanzhen" : "全真教",
    "huashan"  : "华山派",
    "duan"     : "段氏皇族",
    "murong"   : "慕容世家",
    "xueshan"  : "雪山寺",
    "lingjiu"  : "灵鹫宫",
    "emei"     : "峨嵋派",
    "taohua"   : "桃花岛",
    "shenlong" : "神龙教",
    "gumu"     : "古墓派",
    "xingxiu"  : "星宿派",
    "xiaoyao"  : "逍遥派",
    "xuedao"   : "血刀门",
    "jianzong" : "华山剑宗",
    "ouyang"   : "欧阳世家",
    "hu"       : "关外胡家",
    "mingjiao" : "明教",
    "riyue"    : "日月神教",
    "sixiang"  : "四象门",
    "baidi"    : "白帝城",
    "wansong"  : "魔教",
    "yihua"    : "移花宫",
]);

// 返回门派声望：如果参数为空，返回mapping类型，包含了所有门
// 派的声望；如果参数是人物，则返回该人物所在的那个门派的声
// 望；如果参数是门派，则返回该门派的声望。
public mixed query_family_fame(mixed ob)
{
    string fname;

    if (stringp(ob))
        return family_fame[ob];

    if (objectp(ob))
    {
        if (stringp(fname = ob->query("family/family_name")))
            return family_fame[fname];
        else
            return 0;
    }

    return family_fame;
}

// 查询昨天的门派名望信息
public mapping query_all_last_family_fame()
{
    if (!mapp(last_family_fame))
        // 没有昨天的信息，返回今天的
        return family_fame;

    // 返回昨天的门派声望信息
    return last_family_fame;
}

// 变化门派声望：输入的ob可以是门派的名字，也可是门派中的人物
public void add_family_fame(mixed ob, int n)
{
    int new_fame;
    string fname;

    if (objectp(ob))
        fname = ob->query("family/family_name");
    else
    if (stringp(ob))
        fname = ob;
    else
        fname = 0;

    if (!stringp(fname) || undefinedp(family_fame[fname]))
        return;

    // 计算新的门派声望
    new_fame = family_fame[fname] + n;
    if (new_fame < 0) new_fame = 0;
    if (new_fame > MAX_FAMILY_FAME)
        new_fame = MAX_FAMILY_FAME;
    family_fame[fname] = new_fame;
}

// 查询门派名称
public string query_family_name(string fid)
{
    string fam;

    if (undefinedp(fam = family_name[fid]))
        fam = fid;
    return fam;
}

// 查询所有门派名称
public mapping query_all_family_name()
{
    return family_name;
}

// 更新门派声望缓存
public void update_family_fame_cache()
{
    string *all_fam;
    string fam;
    
    // 天数发生了变化：复制门派的名望信息
    all_fam = keys(family_fame) - ({ 0 });
    last_family_fame = family_fame;
    family_fame = ([ ]);

    foreach (fam in all_fam)
        family_fame[fam] = last_family_fame[fam];
} 