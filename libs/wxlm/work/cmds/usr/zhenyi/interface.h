/**
 * @brief 武圣真意界面显示模块
 * @author LPC开发者
 * @date 2024
 */

/**
 * @brief 显示武圣真意系统主界面
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int show_main_interface(object me)
{
    mapping equipped;
    string msg, *button_list;
    int slots, level, i;
    mapping zhenyi_data;
    
    level = me->query("level");
    
    if (level < 100)
    {
        tell_object(me, popup_title("你的修为尚浅，需要达到100级才能感悟武圣真意。"));
        return 1;
    }
    
    slots = ZHENYI_MASTER->query_zhenyi_slots(me);
    equipped = ZHENYI_MASTER->query_equipped_zhenyi(me);
    
    msg = HIC"【武圣真意系统】"NOR"\n\n";
    msg += sprintf("当前等级：%d级\n", level);
    msg += sprintf("可用槽位：%d个\n\n", slots);
    
    msg += HIY"已装备真意："NOR"\n";
    
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
        }
        else
        {
            msg += sprintf("槽位%d："HIG"（空）"NOR"\n", i);
        }
    }
    
    button_list = ({
        "装备真意:wusheng_zhenyi slots",
        "卸下真意:wusheng_zhenyi select_unequip", 
        "真意背包:wusheng_zhenyi bag",
        "查看加成:wusheng_zhenyi bonus",
        "方案管理:wusheng_zhenyi scheme_management",
        "真意合成:wusheng_zhenyi synthesis",
        "真意分解:wusheng_zhenyi decompose",
        "武蕴兑换:wusheng_zhenyi wuyun_exchange"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 查看真意加成
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int view_bonus(object me)
{
    mapping bonus;
    string *effect_types, effect_type, msg;
    int effect_value;
    
    bonus = ZHENYI_MASTER->calculate_zhenyi_bonus(me);
    effect_types = keys(bonus);
    
    msg = HIC"【武圣真意总加成】"NOR"\n\n";
    
    if (!sizeof(effect_types))
    {
        msg += "当前没有装备任何真意，无属性加成。";
    }
    else
    {
        msg += "当前真意提供的属性加成：\n\n";
        
        foreach (effect_type in effect_types)
        {
            effect_value = bonus[effect_type];
            msg += sprintf("%s：+%d\n", 
                ZHENYI_MASTER->get_effect_name(effect_type), 
                effect_value
            );
        }
    }
    
    tell_object(me, popup_comb(msg, ({ "返回:wusheng_zhenyi main" })));
    return 1;
}