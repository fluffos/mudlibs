/**
 * @brief 武圣真意装备管理模块
 * @author LPC开发者
 * @date 2024
 */

/**
 * @brief 装备真意
 * @param object me 玩家对象
 * @param int slot 槽位号
 * @param string zhenyi_id 真意ID
 * @return int 成功返回1
 */
int equip_zhenyi_action(object me, int slot, string zhenyi_id)
{
    mapping bag, zhenyi_data;
    string msg;
    
    if (!slot || !zhenyi_id)
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
    
    if (ZHENYI_MASTER->equip_zhenyi(me, zhenyi_data, slot))
    {
        ZHENYI_MASTER->remove_zhenyi_from_bag(me, zhenyi_id);
        
        msg = sprintf("成功将 %s%s%s 装备到槽位%d！",
            sprintf("%s", zhenyi_data["color"]),
            zhenyi_data["name"],
            NOR,
            slot
        );
        
        tell_object(me, popup_comb(msg, ({
            "返回主界面:wusheng_zhenyi main",
            "继续装备:wusheng_zhenyi slots"
        })));
    }
    else
    {
        tell_object(me, popup_title("装备失败，请检查槽位是否可用或等级是否满足要求。"));
    }
    
    return 1;
}

/**
 * @brief 显示装备槽位选择
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int show_equip_slots(object me)
{
    mapping equipped;
    string msg, *button_list;
    int slots, i;
    mapping zhenyi_data;
    
    slots = ZHENYI_MASTER->query_zhenyi_slots(me);
    equipped = ZHENYI_MASTER->query_equipped_zhenyi(me);
    
    msg = HIC"【选择装备槽位】"NOR"\n\n";
    
    button_list = ({});
    
    for (i = 1; i <= slots; i++)
    {
        if (equipped[i])
        {
            zhenyi_data = equipped[i];
            msg += sprintf("槽位%d：%s%s%s（已装备）\n",
                i,
                sprintf("%s", zhenyi_data["color"]),
                zhenyi_data["name"],
                NOR
            );
            // button_list += ({ sprintf("替换槽位%d:wusheng_zhenyi select_equip %d", i, i) });
        }
        else
        {
            msg += sprintf("槽位%d："HIG"（空）"NOR"\n", i);
            button_list += ({ sprintf("装备到槽位%d:wusheng_zhenyi select_equip %d", i, i) });
        }
    }
    
    button_list += ({ "返回:wusheng_zhenyi main" });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示背包选择真意装备
 * @param object me 玩家对象
 * @param int slot 槽位号
 * @param int page 页码
 * @return int 成功返回1
 */
varargs int show_bag_for_equip(object me, int slot, int page)
{
    mapping bag;
    string *zhenyi_ids, zhenyi_id, msg, *button_list;
    mapping zhenyi_data;
    int total_items, total_pages, start_index, end_index;
    string *quality_order, *page_ids;
    mapping qrank;
    int qi;
    int items_per_page = 9;

    if (!slot)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    if (page < 1) page = 1;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);

    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title("你的真意背包是空的，请先感悟一些真意。"));
        return 1;
    }

    // 排序
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
    
    msg = sprintf(HIC"【选择装备到槽位%d的真意】 "HIY"第%d/%d页"NOR"\n", slot, page, total_pages);
    
    button_list = ({});
    
    foreach (zhenyi_id in page_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        button_list += ({ sprintf("%s%s%s:wusheng_zhenyi equip %d %s", zhenyi_data["color"], zhenyi_data["name"], NOR, slot, zhenyi_id) });
    }
    
    // 分页按钮
    if (page > 1)
        button_list += ({ sprintf("上一页:wusheng_zhenyi select_equip %d %d", slot, page - 1) });

    button_list += ({ "返回:wusheng_zhenyi slots" });

    if (page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi select_equip %d %d", slot, page + 1) });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 卸下真意
 * @param object me 玩家对象
 * @param int slot 槽位号
 * @return int 成功返回1
 */
int unequip_zhenyi_action(object me, int slot)
{
    mapping zhenyi_data;
    string msg;
    
    if (!slot)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    zhenyi_data = ZHENYI_MASTER->unequip_zhenyi(me, slot);
    
    if (mapp(zhenyi_data))
    {
        ZHENYI_MASTER->add_zhenyi_to_bag(me, zhenyi_data);
        
        msg = sprintf("成功卸下槽位%d的 %s%s%s！\n真意已放回背包。",
            slot,
            sprintf("%s", zhenyi_data["color"]),
            zhenyi_data["name"],
            NOR
        );
        
        tell_object(me, popup_comb(msg, ({
            "返回主界面:wusheng_zhenyi main",
            "继续卸下:wusheng_zhenyi select_unequip"
        })));
    }
    else
    {
        tell_object(me, popup_title("该槽位没有装备真意。"));
    }
    
    return 1;
}

/**
 * @brief 显示可卸下的槽位
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int show_unequip_slots(object me)
{
    mapping equipped;
    string msg, *button_list;
    int slots, i;
    mapping zhenyi_data;
    
    slots = ZHENYI_MASTER->query_zhenyi_slots(me);
    equipped = ZHENYI_MASTER->query_equipped_zhenyi(me);
    
    msg = HIC"【选择要卸下的真意】"NOR"\n\n";
    
    button_list = ({});
    
    for (i = 1; i <= slots; i++)
    {
        if (equipped[i])
        {
            zhenyi_data = equipped[i];
            msg += sprintf("槽位%d：%s%s%s\n",
                i,
                sprintf("%s", zhenyi_data["color"]),
                zhenyi_data["name"],
                NOR
            );
            button_list += ({ sprintf("卸下槽位%d:wusheng_zhenyi unequip %d", i, i) });
        }
        else
        {
            msg += sprintf("槽位%d："HIG"（空）"NOR"\n", i);
        }
    }
    
    if (!sizeof(button_list))
    {
        tell_object(me, popup_title("没有已装备的真意可以卸下。"));
        return 1;
    }
    
    button_list += ({ "返回:wusheng_zhenyi main" });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}