/**
 * @brief 武蕴兑换功能模块
 * @author LPC开发者
 * @date 2024
 * @details 实现武蕴兑换五脏材料和潜能功能
 */

/**
 * @brief 显示武蕴兑换主界面
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int show_wuyun_exchange_interface(object me)
{
    int current_wuyun;
    string msg, *button_list;
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    msg = HIC"【武蕴兑换系统】"NOR"\n\n";
    msg += sprintf("当前武蕴："HIY"%d点"NOR"\n\n", current_wuyun);
    
    msg += HIR"兑换项目："NOR"\n";
    msg += "• 5点武蕴 → 随机五脏材料（1个）\n";
    msg += "• 1点武蕴 → 1万潜能\n\n";
    
    msg += HIG"五脏材料包括："NOR"\n";
    msg += YEL"地脾黄"NOR"、"GRN"龙肝草"NOR"、"WHT"天肺莲"NOR"、"BLU"仙肾石"NOR"、"RED"血参果"NOR"\n\n";
    
    button_list = ({});
    
    // 材料兑换按钮
    if (current_wuyun >= 5) {
        button_list += ({ "兑换材料(5武蕴):wusheng_zhenyi exchange_material" });
    } else {
        button_list += ({ HIC"兑换材料(武蕴不足)"NOR":wusheng_zhenyi exchange_material" });
    }
    
    // 潜能兑换按钮
    if (current_wuyun >= 1) {
        button_list += ({ "兑换潜能(输入数量):wusheng_zhenyi exchange_potential_input" });
    } else {
        button_list += ({ HIC"兑换潜能(武蕴不足)"NOR":wusheng_zhenyi exchange_potential_input" });
    }
    
    button_list += ({
        "查看武蕴状态:wusheng_zhenyi wuyun_status",
        "返回主界面:wusheng_zhenyi main"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 获取五脏材料池
 * @return string* 材料路径数组
 */
string *get_material_pool()
{
    return ({
        "/system/wusheng/obj/dipi",      // 地脾黄
        "/system/wusheng/obj/longgan",   // 龙肝草  
        "/system/wusheng/obj/tianfei",   // 天肺莲
        "/system/wusheng/obj/xianshen",  // 仙肾石
        "/system/wusheng/obj/xuecanguo"  // 血参果
    });
}

/**
 * @brief 获取材料显示名称
 * @param string material_path 材料路径
 * @return string 显示名称
 */
string get_material_display_name(string material_path)
{
    switch(material_path) {
        case "/system/wusheng/obj/dipi":
            return YEL"地脾黄"NOR;
        case "/system/wusheng/obj/longgan":
            return GRN"龙肝草"NOR;
        case "/system/wusheng/obj/tianfei":
            return WHT"天肺莲"NOR;
        case "/system/wusheng/obj/xianshen":
            return BLU"仙肾石"NOR;
        case "/system/wusheng/obj/xuecanguo":
            return RED"血参果"NOR;
        default:
            return "未知材料";
    }
}

/**
 * @brief 兑换材料处理
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int exchange_material_action(object me)
{
    int current_wuyun;
    string msg, *button_list;
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    if (current_wuyun < 5) {
        msg = HIR"武蕴不足！"NOR"\n\n";
        msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
        msg += "兑换随机五脏材料需要5点武蕴。\n\n";
        
        button_list = ({
            "返回兑换界面:wusheng_zhenyi wuyun_exchange",
            "查看武蕴状态:wusheng_zhenyi wuyun_status"
        });
        
        tell_object(me, popup_comb(msg, button_list));
        return 1;
    }
    
    msg = HIY"确认兑换材料"NOR"\n\n";
    msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
    msg += sprintf("兑换后武蕴："HIY"%d点"NOR"\n\n", current_wuyun - 5);
    msg += "消耗：5点武蕴\n";
    msg += "获得：随机五脏材料1个\n\n";
    msg += HIG"确认要进行兑换吗？"NOR;
    
    button_list = ({
        HIY"确认兑换"NOR":wusheng_zhenyi exchange_material_confirm",
        "取消:wusheng_zhenyi wuyun_exchange"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 确认兑换材料
 * @param object me 玩家对象  
 * @return int 成功返回1
 */
int exchange_material_confirm(object me)
{
    int current_wuyun;
    string *material_pool, selected_material;
    object material_obj;
    string msg, *button_list, material_name;
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    if (current_wuyun < 5) {
        tell_object(me, popup_title("武蕴不足，无法完成兑换！"));
        return 1;
    }
    
    // 扣除武蕴
    me->set("wuyun", current_wuyun - 5);
    
    // 随机选择材料
    material_pool = get_material_pool();
    selected_material = material_pool[random(sizeof(material_pool))];
    
    // 克隆材料到玩家背包
    material_obj = new_bind(selected_material);
    if (!material_obj) {
        // 材料克隆失败，退还武蕴
        me->set("wuyun", current_wuyun);
        tell_object(me, popup_title("系统错误，兑换失败！武蕴已退还。"));
        return 1;
    }
    
    if (!material_obj->move(me)) {
        // 移动到玩家失败，销毁对象并退还武蕴
        destruct(material_obj);
        me->set("wuyun", current_wuyun);
        tell_object(me, popup_title("背包空间不足，兑换失败！武蕴已退还。"));
        return 1;
    }
    
    material_name = get_material_display_name(selected_material);
    
    msg = HIG"兑换成功！"NOR"\n\n";
    msg += sprintf("消耗武蕴：5点\n");
    msg += sprintf("获得材料：%s\n", material_name);
    msg += sprintf("当前武蕴：%d点\n", current_wuyun - 5);
    
    button_list = ({
        "继续兑换材料:wusheng_zhenyi exchange_material",
        "返回兑换界面:wusheng_zhenyi wuyun_exchange",
        "查看背包:wusheng_zhenyi bag"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示潜能兑换输入界面
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int exchange_potential_input(object me)
{
    int current_wuyun;
    string msg;
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    if (current_wuyun < 1) {
        msg = HIR"武蕴不足！"NOR"\n\n";
        msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
        msg += "兑换潜能需要至少1点武蕴。\n\n";
        
        tell_object(me, popup_comb(msg, ({
            "返回兑换界面:wusheng_zhenyi wuyun_exchange",
            "查看武蕴状态:wusheng_zhenyi wuyun_status"
        })));
        return 1;
    }
    
    msg = HIY"兑换潜能"NOR"\n\n";
    msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
    msg += "兑换比例：1点武蕴 = 1万潜能\n\n";
    msg += sprintf("你最多可以兑换%d万潜能\n\n", current_wuyun);
    msg += HIG"请输入要兑换的武蕴数量："NOR;
    
    tell_object(me, popup_input(msg, "wusheng_zhenyi exchange_potential "));
    return 1;
}

/**
 * @brief 兑换潜能处理
 * @param object me 玩家对象
 * @param string amount 兑换数量
 * @return int 成功返回1
 */
int exchange_potential_action(object me, string amount)
{
    int wuyun_amount, current_wuyun, potential_gain;
    string msg, *button_list;
    
    if (!amount || !sscanf(amount, "%d", wuyun_amount)) {
        tell_object(me, popup_title("请输入有效的数字！"));
        return 1;
    }
    
    if (wuyun_amount <= 0) {
        tell_object(me, popup_title("兑换数量必须大于0！"));
        return 1;
    }
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    if (wuyun_amount > current_wuyun) {
        msg = HIR"武蕴不足！"NOR"\n\n";
        msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
        msg += sprintf("需要武蕴："HIY"%d点"NOR"\n", wuyun_amount);
        
        tell_object(me, popup_comb(msg, ({
            "重新输入:wusheng_zhenyi exchange_potential_input",
            "返回兑换界面:wusheng_zhenyi wuyun_exchange"
        })));
        return 1;
    }
    
    potential_gain = wuyun_amount * 10000;
    
    msg = HIY"确认兑换潜能"NOR"\n\n";
    msg += sprintf("当前武蕴："HIY"%d点"NOR"\n", current_wuyun);
    msg += sprintf("兑换后武蕴："HIY"%d点"NOR"\n", current_wuyun - wuyun_amount);
    msg += sprintf("消耗武蕴："HIY"%d点"NOR"\n", wuyun_amount);
    msg += sprintf("获得潜能："HIY"%s"NOR"\n\n", chinese_number(potential_gain));
    msg += HIG"确认要进行兑换吗？"NOR;
    
    button_list = ({
        HIY"确认兑换"NOR":wusheng_zhenyi exchange_potential_confirm " + wuyun_amount,
        "取消:wusheng_zhenyi wuyun_exchange"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 确认兑换潜能
 * @param object me 玩家对象
 * @param string amount 兑换数量
 * @return int 成功返回1
 */
int exchange_potential_confirm(object me, string amount)
{
    int wuyun_amount, current_wuyun, potential_gain;
    string msg, *button_list;
    
    if (!amount || !sscanf(amount, "%d", wuyun_amount)) {
        tell_object(me, popup_title("参数错误！"));
        return 1;
    }
    
    current_wuyun = ZHENYI_MASTER->query_player_wuyun(me);
    
    if (wuyun_amount > current_wuyun) {
        tell_object(me, popup_title("武蕴不足，无法完成兑换！"));
        return 1;
    }
    
    // 扣除武蕴
    me->set("wuyun", current_wuyun - wuyun_amount);
    
    // 添加潜能
    potential_gain = wuyun_amount * 10000;
    me->add("potential", potential_gain);
    
    msg = HIG"兑换成功！"NOR"\n\n";
    msg += sprintf("消耗武蕴：%d点\n", wuyun_amount);
    msg += sprintf("获得潜能：%s\n", chinese_number(potential_gain));
    msg += sprintf("当前武蕴：%d点\n", current_wuyun - wuyun_amount);
    msg += sprintf("当前潜能：%s\n", chinese_number(me->query("potential")));
    
    button_list = ({
        "继续兑换潜能:wusheng_zhenyi exchange_potential_input",
        "返回兑换界面:wusheng_zhenyi wuyun_exchange",
        "查看武蕴状态:wusheng_zhenyi wuyun_status"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}