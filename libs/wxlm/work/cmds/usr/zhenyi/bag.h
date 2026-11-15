/**
 * @file bag.h
 * @brief 武圣真意系统背包模块
 * @author LPC开发者
 * @date 2024
 * @details 包含真意背包管理、查看、对比、遗弃等功能
 */

/**
 * @brief 管理真意背包
 * @param object me 玩家对象
 * @param int page 页码
 * @return int 成功返回1
 * @details 显示真意背包界面，支持分页浏览，按品质排序
 */
varargs int manage_bag(object me, int page)
{
    mapping bag;
    string *zhenyi_ids, zhenyi_id, msg, *button_list;
    mapping zhenyi_data;
    string *quality_order;
    mapping qrank;
    int qi;
    int total_items, total_pages, start_index, end_index;
    string *page_ids;
    int items_per_page = 9;

    if (page < 1) page = 1;

    me->set_temp("wusheng_zhenyi_last_page", page);

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);

    if (!sizeof(zhenyi_ids))
    {
        msg = HIC"【真意背包】"NOR"\n\n背包是空的，通过战斗或任务获得真意吧！";
        tell_object(me, popup_comb(msg, ({ "返回:wusheng_zhenyi main" })));
        return 1;
    }

    // 根据品质排序：品质高排前
    quality_order = ({ "真武真意", "无我真意", "玄奥真意", "灵犀真意", "通明真意", "凡尘真意" });
    qrank = ([]);
    for (qi = 0; qi < sizeof(quality_order); qi++)
        qrank[quality_order[qi]] = qi;

    zhenyi_ids = sort_array(zhenyi_ids, "zhenyi_quality_cmp", this_object(), bag, qrank);
    
    total_items = sizeof(zhenyi_ids);
    total_pages = (total_items + items_per_page - 1) / items_per_page;
    if (total_pages < 1) total_pages = 1;

    if (page > total_pages) page = total_pages;

    start_index = (page - 1) * items_per_page;
    end_index = start_index + items_per_page - 1;
    if (end_index >= total_items) end_index = total_items - 1;

    page_ids = zhenyi_ids[start_index..end_index];

    msg = sprintf(HIC"【真意背包】 "HIY"第%d/%d页"NOR" (共%d个)\n\n", page, total_pages, total_items);
    
    button_list = ({});
    
    foreach (zhenyi_id in page_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        button_list += ({ sprintf("%s%s%s:wusheng_zhenyi view %s", zhenyi_data["color"], zhenyi_data["name"], NOR, zhenyi_id) });
    }
    
    // 分页按钮
    if (page > 1)
        button_list += ({ sprintf("上一页:wusheng_zhenyi bag %d", page - 1) });

    button_list += ({ 
        "返回:wusheng_zhenyi main",
        "真意合成:wusheng_zhenyi synthesis"
    });

    if (page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi bag %d", page + 1) });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 查看真意详情
 * @param object me 玩家对象
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 * @details 显示指定真意的详细信息，包括属性、效果等
 */
int view_zhenyi_detail(object me, string zhenyi_id)
{
    mapping bag, zhenyi_data;
    string msg;
    int last_page;

    if (!zhenyi_id)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);

    if (!bag[zhenyi_id])
    {
        tell_object(me, popup_title("背包中没有找到该真意。"));
        return 1;
    }

    zhenyi_data = bag[zhenyi_id];
    last_page = me->query_temp("wusheng_zhenyi_last_page");
    if (last_page < 1) last_page = 1;

    msg = HIC"【真意详情】"NOR"\n\n";
    msg += ZHENYI_MASTER->format_zhenyi_info(zhenyi_data);

    tell_object(me, popup_comb(msg, ({
        "装备真意:wusheng_zhenyi select_slot " + zhenyi_id,
        "与已装备对比:wusheng_zhenyi compare " + zhenyi_id,
        "遗弃真意:wusheng_zhenyi discard_confirm " + zhenyi_id,
        "分解真意:wusheng_zhenyi decompose_preview " + zhenyi_id,
        "真意合成:wusheng_zhenyi synthesis",
        sprintf("返回背包:wusheng_zhenyi bag %d", last_page),
        "返回主界面:wusheng_zhenyi main"
    })));

    return 1;
}

/**
 * @brief 遗弃真意确认
 * @param object me 玩家对象
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 * @details 显示遗弃确认界面，防止误操作
 */
int discard_confirm_action(object me, string zhenyi_id)
{
    mapping bag, zhenyi_data;
    string msg;

    if (!zhenyi_id) return 1;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    if (!bag[zhenyi_id])
    {
        tell_object(me, popup_title("背包中没有找到该真意。"));
        return 1;
    }

    zhenyi_data = bag[zhenyi_id];
    msg = HIC "【确认遗弃真意】" NOR "\n\n";
    msg += "你确定要遗弃下面的真意吗？\n";
    msg += "此操作" HIR "无法恢复" NOR "！\n\n";
    msg += ZHENYI_MASTER->format_zhenyi_info(zhenyi_data);

    tell_object(me, popup_comb(msg, ({
        "确认遗弃:wusheng_zhenyi discard_execute " + zhenyi_id,
        "返回详情:wusheng_zhenyi view " + zhenyi_id,
    })));

    return 1;
}

/**
 * @brief 执行遗弃真意
 * @param object me 玩家对象
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 * @details 实际执行遗弃操作，从背包中移除指定真意
 */
int discard_execute_action(object me, string zhenyi_id)
{
    mapping zhenyi_data;
    string msg;
    int last_page;

    if (!zhenyi_id) return 1;

    zhenyi_data = ZHENYI_MASTER->remove_zhenyi_from_bag(me, zhenyi_id);
    last_page = me->query_temp("wusheng_zhenyi_last_page");
    if (last_page < 1) last_page = 1;

    if (mapp(zhenyi_data))
    {
        msg = sprintf("你成功遗弃了 %s%s%s。",
            zhenyi_data["color"],
            zhenyi_data["name"],
            NOR
        );
        tell_object(me, popup_comb(msg, ({ sprintf("返回背包:wusheng_zhenyi bag %d", last_page) })));
    }
    else
    {
        tell_object(me, popup_title("遗弃失败，可能该真意已不存在。"));
    }

    return 1;
}

/**
 * @brief 显示词条描述
 * @param object me 玩家对象
 * @param string effect_name 词条名称
 * @return int 成功返回1
 * @details 显示真意词条的详细描述和效果说明
 */
int show_effect_desc(object me, string effect_name)
{
    mapping base_effects, effect_data;
    string msg;
    int last_page;
    
    if (!effect_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    // 从配置中获取词条信息
    base_effects = ZHENYI_MASTER->query_zhenyi_effects_by_level(100);
    
    if (!base_effects || !base_effects[effect_name])
    {
        tell_object(me, popup_title("找不到该词条的信息。"));
        return 1;
    }
    
    effect_data = base_effects[effect_name];
    last_page = me->query_temp("wusheng_zhenyi_last_page");
    if (last_page < 1) last_page = 1;
    
    msg = sprintf(HIC"【%s】"NOR"\n\n", effect_name);
    msg += sprintf("词条描述：%s\n", effect_data["desc"]);
    msg += sprintf("效果类型：%s\n", ZHENYI_MASTER->get_effect_name(effect_data["type"]));
    
    tell_object(me, popup_comb(msg, ({ sprintf("返回背包:wusheng_zhenyi bag %d", last_page) })));
    
    return 1;
}

/**
 * @brief 真意与已装备对比
 * @param object me 玩家对象
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 * @details 对比背包中的真意与当前已装备真意的属性差异
 */
int compare_zhenyi_action(object me, string zhenyi_id)
{
    mapping bag, equipped, zhenyi_data, bag_effects;
    string msg;
    int slots, i, last_page;
    
    if (!zhenyi_id)
        return 1;
        
    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    if (!bag || !bag[zhenyi_id])
    {
        tell_object(me, popup_title("背包中没有找到该真意。"));
        return 1;
    }

    zhenyi_data  = bag[zhenyi_id];
    bag_effects  = zhenyi_data["effects"];
    equipped     = ZHENYI_MASTER->query_equipped_zhenyi(me);
    slots        = ZHENYI_MASTER->query_zhenyi_slots(me);
    last_page    = me->query_temp("wusheng_zhenyi_last_page");
    if (last_page < 1) last_page = 1;

    msg = HIC"【真意属性对比】"NOR"\n\n";
    msg += sprintf("背包真意：%s%s%s\n", zhenyi_data["color"], zhenyi_data["name"], NOR);

    for (i = 1; i <= slots; i++)
    {
        mapping eq_data, eq_effects;
        string *union_types, effect_type, diff_str;
        int bag_val, eq_val, diff;
        
        if (equipped[i])
        {
            eq_data     = equipped[i];
            eq_effects  = eq_data["effects"];
            msg += sprintf("\n槽位%d 当前：%s%s%s\n", i, eq_data["color"], eq_data["name"], NOR);
        }
        else
        {
            eq_data    = 0;
            eq_effects = ([]);
            msg += sprintf("\n槽位%d 当前：%s（空）%s\n", i, HIG, NOR);
        }

        union_types = keys(bag_effects) | keys(eq_effects);
        foreach (effect_type in union_types)
        {
            bag_val = (bag_effects[effect_type]) ? bag_effects[effect_type]["value"] : 0;
            eq_val  = (eq_effects[effect_type]) ? eq_effects[effect_type]["value"] : 0;
            if (!bag_val && !eq_val) continue;
            diff = bag_val - eq_val;
            diff_str = sprintf("%s(%+d)%s", (diff >= 0 ? HIG : HIR), diff, NOR);
            msg += sprintf("  %s：%d ---> %d %s\n", 
                ZHENYI_MASTER->get_effect_name(effect_type), 
                eq_val, 
                bag_val, 
                diff_str);
        }
    }

    tell_object(me, popup_comb(msg, ({
        "装备真意:wusheng_zhenyi slots",
        sprintf("返回背包:wusheng_zhenyi bag %d", last_page)
    })));
    return 1;
}

/**
 * @brief 为指定真意显示可装备槽位
 * @param object me 玩家对象
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 * @details 显示可以装备指定真意的槽位选择界面
 */
int show_equip_slots_for_item(object me, string zhenyi_id)
{
    mapping bag, equipped, zhenyi_data;
    string msg, *button_list;
    int slots, i;

    if (!zhenyi_id)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    if (!bag[zhenyi_id])
    {
        tell_object(me, popup_title("背包中没有找到该真意。"));
        return 1;
    }

    zhenyi_data = bag[zhenyi_id];
    slots = ZHENYI_MASTER->query_zhenyi_slots(me);
    equipped = ZHENYI_MASTER->query_equipped_zhenyi(me);

    msg = sprintf(HIC"【选择装备槽位】"NOR"\n\n将 %s%s%s 装备到哪个槽位？\n\n", 
        zhenyi_data["color"], zhenyi_data["name"], NOR);

    button_list = ({ });

    for (i = 1; i <= slots; i++)
    {
        if (equipped[i])
        {
            mapping eq = equipped[i];
            msg += sprintf("槽位%d：%s%s%s（已装备）\n", 
                i, eq["color"], eq["name"], NOR);
            // 若未来需要支持替换，可在此加入按钮
        }
        else
        {
            msg += sprintf("槽位%d：%s（空）%s\n", i, HIG, NOR);
            button_list += ({ sprintf("装备到槽位%d:wusheng_zhenyi equip %d %s", i, i, zhenyi_id) });
        }
    }

    button_list += ({ "返回详情:wusheng_zhenyi view " + zhenyi_id });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 用于 sort_array 的真意品质比较函数
 * @param string id1 真意ID1
 * @param string id2 真意ID2
 * @param mapping bag 玩家背包映射
 * @param mapping qrank 品质排名映射
 * @return int 若 <0 表示 id1 排在前面
 * @details 按品质优先级排序，同品质按获得时间降序排列
 */
int zhenyi_quality_cmp(string id1, string id2, mapping bag, mapping qrank)
{
    int r1, r2;

    r1 = undefinedp(qrank[bag[id1]["quality"]]) ? 999 : qrank[bag[id1]["quality"]];
    r2 = undefinedp(qrank[bag[id2]["quality"]]) ? 999 : qrank[bag[id2]["quality"]];

    if (r1 != r2)
        return r1 - r2;

    // 同品质按获得时间降序
    return bag[id2]["create_time"] - bag[id1]["create_time"];
}