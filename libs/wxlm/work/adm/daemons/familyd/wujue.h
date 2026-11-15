// wujue.h - 五绝相关的常量、数据和函数
// 由familyd.c包含

// 五绝相关常量定义
#define WUJUE_TITLES ({"中神通", "东邪", "西毒", "南帝", "北丐"})
#define WUJUE_WEAPONS ({\
    "/clone/weapon/wushuang",\
    "/clone/weapon/dongxie",\
    "/clone/weapon/xidu",\
    "/clone/weapon/nandi",\
    "/clone/weapon/beigai"\
})

// 添加新秀组五绝称号前缀
#define NON_ULTRA_PREFIX "新秀"

// 添加武尊组五绝称号前缀
#define WUZUN_PREFIX "武魁"

// 五绝数据
mapping lunjian_leader = ([]);    // 宗师组五绝持有者记录
mapping lunjian_leader_bouns = ([]);  // 宗师组五绝奖励记录
mapping non_ultra_lunjian_leader = ([]);    // 新秀组五绝持有者记录
mapping non_ultra_lunjian_leader_bouns = ([]);  // 新秀组五绝奖励记录
mapping wuzun_lunjian_leader = ([]);    // 武尊组五绝持有者记录
mapping wuzun_lunjian_leader_bouns = ([]);  // 武尊组五绝奖励记录

// 返回论剑报名时间
public mapping query_lunjian_sign_time()
{
    mapping lunjian_sign_time = ([
        "day": 0,      // 周日
        "hour": 22,    // 22点
        "pre": 9,      // 提前9分钟报名
        "time": 30,    // 持续30分钟
    ]);
    return lunjian_sign_time;
}

// 返回新秀组论剑报名时间
public mapping query_non_ultra_lunjian_sign_time()
{
    mapping lunjian_sign_time = ([
        "day": 0,      // 周日
        "hour": 22,    // 21点
        "pre": 9,      // 提前9分钟报名
        "time": 30,    // 持续30分钟
    ]);
    return lunjian_sign_time;
}

/**
 * @brief 返回武尊组论剑报名时间
 * @return mapping 武尊组论剑报名时间配置
 * @details 与其他组同时进行，周日22点开始报名
 */
public mapping query_wuzun_lunjian_sign_time()
{
    mapping lunjian_sign_time = ([
        "day": 0,      // 周日
        "hour": 22,    // 22点
        "pre": 9,      // 提前9分钟报名
        "time": 30,    // 持续30分钟
    ]);
    return lunjian_sign_time;
}

// 销毁五绝武器
private void destroy_wujue_weapons()
{
    foreach (string weapon_path in WUJUE_WEAPONS)
    {
        object *clones = children(weapon_path); // 获取所有该武器的复制对象

        foreach (object clone in clones)
        {
            object owner;

            if (!objectp(clone)) continue; // 跳过无效对象

            owner = environment(clone);
            
            if (objectp(owner) && playerp(owner))
            {
                // 通知持有者
                tell_object(owner, clone->short() + HIY "化作一道流光飞走了" NOR "。\n");
                // 销毁对象会触发 remove 函数，通常会自动处理卸下装备的逻辑
            }
            // 销毁复制的对象
            destruct(clone);
        }
    }
}

// 设置论剑领袖(五绝)
public void set_lunjian_leader(string fname, string id)
{
    lunjian_leader[fname] = id;
    save();
}

// 设置新秀组论剑领袖(五绝)
public void set_non_ultra_lunjian_leader(string fname, string id)
{
    non_ultra_lunjian_leader[fname] = id;
    save();
}

/**
 * @brief 设置武尊组论剑领袖(五绝)
 * @param fname string 五绝称号名称
 * @param id string 玩家ID
 * @return void
 * @details 设置指定五绝称号的武尊组持有者并保存数据
 */
public void set_wuzun_lunjian_leader(string fname, string id)
{
    wuzun_lunjian_leader[fname] = id;
    save();
}

// 查询论剑领袖(五绝)
public string query_lunjian_leader(string fname)
{
    if(!fname || !mapp(lunjian_leader) || undefinedp(lunjian_leader[fname]))
        return "";
    return lunjian_leader[fname];
}

// 查询新秀组论剑领袖(五绝)
public string query_non_ultra_lunjian_leader(string fname)
{
    if(!fname || !mapp(non_ultra_lunjian_leader) || undefinedp(non_ultra_lunjian_leader[fname]))
        return "";
    return non_ultra_lunjian_leader[fname];
}

/**
 * @brief 查询武尊组论剑领袖(五绝)
 * @param fname string 五绝称号名称
 * @return string 持有该称号的玩家ID，如果没有则返回空字符串
 * @details 根据五绝称号名称查询当前的武尊组持有者
 */
public string query_wuzun_lunjian_leader(string fname)
{
    if(!fname || !mapp(wuzun_lunjian_leader) || undefinedp(wuzun_lunjian_leader[fname]))
        return "";
    return wuzun_lunjian_leader[fname];
}

/**
 * @brief 检查玩家是否为五绝领袖 (宗师组、新秀组或武尊组)
 * @param id string 玩家ID
 * @return int 如果是五绝领袖返回1，否则返回0
 * @details 检查玩家在任意一个组别中是否持有五绝称号
 */
public int is_wujue_leader(string id)
{
    if (!stringp(id) || id == "")
        return 0;

    if (mapp(lunjian_leader)) {
        foreach(string title in keys(lunjian_leader)) {
            if (lunjian_leader[title] == id)
                return 1;
        }
    }

    if (mapp(non_ultra_lunjian_leader)) {
        foreach(string title in keys(non_ultra_lunjian_leader)) {
            if (non_ultra_lunjian_leader[title] == id)
                return 1;
        }
    }

    if (mapp(wuzun_lunjian_leader)) {
        foreach(string title in keys(wuzun_lunjian_leader)) {
            if (wuzun_lunjian_leader[title] == id)
                return 1;
        }
    }

    return 0;
}

// 查询所有五绝ID
public string *query_lunjian_leader_ids()
{
    string *ids = ({ });
    
    if (!mapp(lunjian_leader))
        return ({ });
        
    foreach (string title in WUJUE_TITLES) {
        if (lunjian_leader[title])
            ids += ({ lunjian_leader[title] });
    }
    
    return ids;
}

// 查询所有新秀组五绝ID
public string *query_non_ultra_lunjian_leader_ids()
{
    string *ids = ({ });
    
    if (!mapp(non_ultra_lunjian_leader))
        return ({ });
        
    foreach (string title in WUJUE_TITLES) {
        if (non_ultra_lunjian_leader[title])
            ids += ({ non_ultra_lunjian_leader[title] });
    }
    
    return ids;
}

/**
 * @brief 查询所有武尊组五绝ID
 * @return string* 武尊组五绝持有者ID数组
 * @details 返回当前所有武尊组五绝称号持有者的ID列表
 */
public string *query_wuzun_lunjian_leader_ids()
{
    string *ids = ({ });
    
    if (!mapp(wuzun_lunjian_leader))
        return ({ });
        
    foreach (string title in WUJUE_TITLES) {
        if (wuzun_lunjian_leader[title])
            ids += ({ wuzun_lunjian_leader[title] });
    }
    
    return ids;
}

// 获取五绝武器路径
private string get_wujue_weapon_path(string title)
{
    int idx = member_array(title, WUJUE_TITLES);
    if (idx == -1) return "";
    return WUJUE_WEAPONS[idx];
}

/**
 * @brief 发放五绝奖励（支持三个组别：宗师组、新秀组、武尊组）
 * @param me object 玩家对象
 * @return string 奖励发放结果信息
 * @details 根据玩家的组别身份和持有的五绝称号发放相应奖励
 */
public string bouns_lunjian_leader(object me)
{
    object ob, obj;
    string title, msg, prefix;
    int t;
    string weapon_path;
    
    if(localtime(time())[6] == 0 && localtime(time())[2] < 21)
        return "新一轮论剑竞技就要开始了，赶紧准备准备参加今天的华山论剑吧！\n";

    msg = "";
    title = "";
    prefix = "";
    
    // 查找玩家的五绝称号
    foreach(string single_title in WUJUE_TITLES)
    {
        // 检查宗师组称号
        if(lunjian_leader[single_title] == me->query("id"))
        {
            title = single_title;
            prefix = "";
            break;
        }
        
        // 检查新秀组称号
        if(non_ultra_lunjian_leader[single_title] == me->query("id"))
        {
            title = single_title;
            prefix = NON_ULTRA_PREFIX;
            break;
        }
        
        // 检查武尊组称号
        if(wuzun_lunjian_leader[single_title] == me->query("id"))
        {
            title = single_title;
            prefix = WUZUN_PREFIX;
            break;
        }
    }
    
    if(!title || title == "")
        return "你没有五绝称号，领什么奖励？\n";

    // 根据组别判断奖励发放状态
    if(me->query("sanhua_done") && wuzun_lunjian_leader[title] == me->query("id")) // 武尊组
    {
        if((t = wuzun_lunjian_leader_bouns[title]))
            return msg + WUZUN_PREFIX + title + "的奖励已经发放过了！\n";
        
        // 发放奖励
        wuzun_lunjian_leader_bouns[title] = time();
    }
    else if(me->query("opinion/ultra")) // 宗师组
    {
        if((t = lunjian_leader_bouns[title]))
            return msg + title + "的奖励已经发放过了！\n";
        
        // 发放奖励
        lunjian_leader_bouns[title] = time();
    }
    else // 新秀组
    {
        if((t = non_ultra_lunjian_leader_bouns[title]))
            return msg + NON_ULTRA_PREFIX + title + "的奖励已经发放过了！\n";
        
        // 发放奖励
        non_ultra_lunjian_leader_bouns[title] = time();
    }

    // 获取对应的武器
    weapon_path = get_wujue_weapon_path(title);
    if(weapon_path != "")
    {
        obj = new(weapon_path);

        if(!present(obj, me))
        {
            msg += "你得到了" + obj->short() + "。\n";
            obj->move(me);
        }
    }
    
    // 发放九转金丹奖励
    ob = new_bind("/clone/vip/dan_jiuzhuan");
    if(title == "中神通") ob->set_amount(2);
    msg += "你得到了" + ob->short() + "。\n";
    ob->move(me);
    
    // 记录日志
    log_file("bouns_lunjian_leader", sprintf("%s：%s(%s)领取了%s%s奖励。\n", 
                                        ctime(time()), me->query("name"), 
                                        me->query("id"), prefix, title));
    save();
    return msg;
}

/**
 * @brief 初始化五绝数据（包含所有三个组别）
 * @return void
 * @details 初始化宗师组、新秀组和武尊组的五绝数据结构
 */
private void init_wujue_data()
{
    if(!mapp(lunjian_leader))
        lunjian_leader = ([]);
    if(!mapp(lunjian_leader_bouns))
        lunjian_leader_bouns = ([]);
    if(!mapp(non_ultra_lunjian_leader))
        non_ultra_lunjian_leader = ([]);
    if(!mapp(non_ultra_lunjian_leader_bouns))
        non_ultra_lunjian_leader_bouns = ([]);
    if(!mapp(wuzun_lunjian_leader))
        wuzun_lunjian_leader = ([]);
    if(!mapp(wuzun_lunjian_leader_bouns))
        wuzun_lunjian_leader_bouns = ([]);
}

/**
 * @brief 清理五绝数据（每周日执行，包含所有三个组别）
 * @return void
 * @details 清空所有组别的五绝称号和奖励记录，销毁五绝武器
 */
public void reset_wujue_data()
{
    lunjian_leader = ([]);
    lunjian_leader_bouns = ([]);
    non_ultra_lunjian_leader = ([]);
    non_ultra_lunjian_leader_bouns = ([]);
    wuzun_lunjian_leader = ([]);
    wuzun_lunjian_leader_bouns = ([]);
    destroy_wujue_weapons();
}

/**
 * @brief 获取五绝称号完整名称（包括组别前缀）
 * @param title string 基础称号名称
 * @param group_type int 组别类型：0=新秀组，1=宗师组，2=武尊组
 * @return string 带前缀的完整称号名称
 * @details 根据不同组别添加相应前缀，宗师组无前缀，新秀组和武尊组有对应前缀
 */
public string get_wujue_full_title(string title, int group_type)
{
    switch(group_type)
    {
        case 0: // 新秀组
            return NON_ULTRA_PREFIX + title;
        case 1: // 宗师组
            return title;
        case 2: // 武尊组
            return WUZUN_PREFIX + title;
        default:
            return title;
    }
}
