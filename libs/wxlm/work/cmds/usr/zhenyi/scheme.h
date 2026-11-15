/**
 * @brief 武圣真意方案管理界面模块
 * @author 一壶茶叶
 * @date 2025
 */

/**
 * @brief 显示方案管理主界面
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int show_scheme_management(object me)
{
    mapping schemes, stats;
    string *scheme_names, msg, *button_list;
    string current_scheme;
    int i;
    schemes = ZHENYI_MASTER->query_all_schemes(me);
    stats = ZHENYI_MASTER->query_scheme_statistics(me);
    current_scheme = ZHENYI_MASTER->query_current_scheme(me);

    msg = HIC"【方案管理】"NOR"\n\n";
    
    // 安全检查stats是否为有效的mapping
    if (!mapp(stats))
    {
        return 1;
    }
    
    msg += sprintf("已保存方案：%d/%d个\n", stats["total"], stats["max_schemes"]);
    
    if (current_scheme)
        msg += sprintf("当前方案："HIY"%s"NOR"\n", current_scheme);
    else
        msg += "当前方案："HIG"无"NOR"\n";
        
    msg += "\n";
    
    button_list = ({});
    
    if (sizeof(schemes))
    {
        msg += HIB"最近使用的方案："NOR"\n";
        scheme_names = keys(schemes);
        scheme_names = sort_array(scheme_names, (: $(schemes)[$2]["last_used"] - $(schemes)[$1]["last_used"] :));
        
        for (i = 0; i < sizeof(scheme_names) && i < 4; i++)
        {
            string name = scheme_names[i];
            
            msg += sprintf("• %s", name);
            if (name == current_scheme)
                msg += HIY" ★"NOR;
            msg += "\n";
            
            button_list += ({ sprintf("切换到%s:wusheng_zhenyi load_scheme %s", name, name) });
        }
        
        msg += "\n";
    }
    else
    {
        msg += "暂无保存的方案\n\n";
    }
    
    button_list += ({
        "保存当前方案:wusheng_zhenyi save_scheme_input",
        "方案列表:wusheng_zhenyi scheme_list 1",
        "返回主界面:wusheng_zhenyi main"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示方案列表界面
 * @param object me 玩家对象
 * @param int page 页码
 * @return int 成功返回1
 */
varargs int show_scheme_list(object me, int page)
{
    mapping schemes;
    string *scheme_names, msg, *button_list;
    string current_scheme;
    int total_schemes, total_pages, start_index, end_index, i;
    int items_per_page = 8;
    
    if (page < 1) page = 1;
    
    schemes = ZHENYI_MASTER->query_all_schemes(me);
    if (!mapp(schemes)) schemes = ([]);
    scheme_names = keys(schemes);
    current_scheme = ZHENYI_MASTER->query_current_scheme(me);
    
    total_schemes = sizeof(scheme_names);
    total_pages = (total_schemes + items_per_page - 1) / items_per_page;
    if (total_pages < 1) total_pages = 1;
    if (page > total_pages) page = total_pages;
    
    start_index = (page - 1) * items_per_page;
    end_index = start_index + items_per_page - 1;
    if (end_index >= total_schemes) end_index = total_schemes - 1;
    
    msg = sprintf(HIC"【方案列表】 "HIY"第%d/%d页"NOR"\n\n", page, total_pages);
    
    button_list = ({});
    
    if (total_schemes == 0)
    {
        msg += "暂无保存的方案\n";
    }
    else
    {
        // 按最后使用时间排序
        scheme_names = sort_array(scheme_names, (: $(schemes)[$2]["last_used"] - $(schemes)[$1]["last_used"] :));
        
        for (i = start_index; i <= end_index; i++)
        {
            string name = scheme_names[i];
            mapping scheme_data = schemes[name];
            
            msg += sprintf("%d. %s", i + 1, name);
            if (name == current_scheme)
                msg += HIY"（当前）"NOR;
            msg += sprintf("  "HIG"[%s]"NOR"\n", ZHENYI_MASTER->format_time_display(scheme_data["last_used"]));
            
            button_list += ({ sprintf("%s:wusheng_zhenyi scheme_detail %s", name, name) });
        }
    }
    
    // 分页按钮
    if (page > 1)
        button_list += ({ sprintf("上一页:wusheng_zhenyi scheme_list %d", page - 1) });
        
    button_list += ({ "返回方案管理:wusheng_zhenyi scheme_management" });
    
    if (page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi scheme_list %d", page + 1) });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示方案详情界面
 * @param object me 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1
 */
int show_scheme_detail(object me, string scheme_name)
{
    mapping schemes, scheme_data, slots;
    string msg, *button_list;
    string current_scheme;
    string *slot_keys;
    
    if (!scheme_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    schemes = ZHENYI_MASTER->query_all_schemes(me);
    if (!mapp(schemes) || !schemes[scheme_name])
    {
        tell_object(me, popup_title("找不到指定的方案。"));
        return 1;
    }
    
    scheme_data = schemes[scheme_name];
    slots = scheme_data["slots"];
    current_scheme = ZHENYI_MASTER->query_current_scheme(me);
    
    msg = sprintf(HIC"【方案详情】%s"NOR"\n\n", scheme_name);
    msg += sprintf("创建时间：%s\n", ZHENYI_MASTER->format_time_display(scheme_data["create_time"]));
    msg += sprintf("最后使用：%s\n", ZHENYI_MASTER->format_time_display(scheme_data["last_used"]));
    
    if (scheme_name == current_scheme)
        msg += "状态："HIY"当前方案"NOR"\n";
    else
        msg += "状态："HIG"已保存"NOR"\n";
        
    msg += "\n"HIB"装备配置："NOR"\n";
    
    if (!sizeof(slots))
    {
        msg += "无装备真意\n";
    }
    else
    {
        slot_keys = keys(slots);
        slot_keys = sort_array(slot_keys, (: to_int($1) - to_int($2) :));
        
        foreach (string key in slot_keys)
        {
            mapping zhenyi;
            string color_str, name_str;
            mixed name_value;

            zhenyi = slots[key];

            if (!mapp(zhenyi))
            {
                msg += sprintf("槽位%s：数据错误\n", key);
                continue;
            }

            // 安全获取颜色和名称
            color_str = "";
            if (stringp(zhenyi["color"]))
                color_str = zhenyi["color"];
            
            name_str = "未知真意";
            name_value = zhenyi["name"];
            if (stringp(name_value))
                name_str = (string)name_value;
            msg += sprintf("槽位%d：%s%s%s\n",
                key,
                color_str,
                name_str,
                NOR
            );
        }
    }
    
    button_list = ({});
    
    if (scheme_name != current_scheme)
        button_list += ({ sprintf("切换到此方案:wusheng_zhenyi load_scheme %s", scheme_name) });
        
    button_list += ({
        sprintf("重命名方案:wusheng_zhenyi rename_scheme_input %s", scheme_name),
        sprintf("删除方案:wusheng_zhenyi delete_scheme_confirm %s", scheme_name),
        "返回方案列表:wusheng_zhenyi scheme_list 1"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 保存方案输入界面
 * @param object me 玩家对象
 * @return int 成功返回1
 */
int save_scheme_input(object me)
{
    mapping equipped;
    string msg;
    
    equipped = ZHENYI_MASTER->query_equipped_zhenyi(me);
    if (!sizeof(equipped))
    {
        tell_object(me, popup_title("当前没有装备任何真意，无法保存方案。"));
        return 1;
    }
    
    msg = "请输入要保存的方案名称：\n";
    msg += HIG"（长度1-12个字符）"NOR;
    
    tell_object(me, popup_input(msg, "wusheng_zhenyi save_scheme_execute "));
    return 1;
}

/**
 * @brief 执行保存方案
 * @param object me 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1
 */
int save_scheme_execute(object me, string scheme_name)
{
    string msg;
    
    if (!scheme_name || scheme_name == "")
    {
        tell_object(me, popup_title("方案名称不能为空。"));
        return 1;
    }
    
    if (strlen(scheme_name) > 12 || strlen(scheme_name) < 1)
    {
        tell_object(me, popup_title("方案名称长度必须在1-12个字符之间。"));
        return 1;
    }
    
    if (ZHENYI_MASTER->save_current_scheme(me, scheme_name))
    {
        msg = sprintf("成功保存方案：%s", scheme_name);
        tell_object(me, popup_comb(msg, ({
            "返回方案管理:wusheng_zhenyi scheme_management",
            "返回主界面:wusheng_zhenyi main"
        })));
    }
    else
    {
        tell_object(me, popup_title("保存方案失败，请检查是否已达到最大方案数量限制。"));
    }
    
    return 1;
}

/**
 * @brief 加载方案操作
 * @param object me 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1
 */
int load_scheme_action(object me, string scheme_name)
{
    string msg;
    
    if (!scheme_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    if (ZHENYI_MASTER->load_scheme(me, scheme_name))
    {
        msg = sprintf("成功切换到方案：%s", scheme_name);
        tell_object(me, popup_comb(msg, ({
            "查看加成:wusheng_zhenyi bonus",
            "返回方案管理:wusheng_zhenyi scheme_management",
            "返回主界面:wusheng_zhenyi main"
        })));
    }
    else
    {
        tell_object(me, popup_title("切换方案失败，请检查背包中是否有相应的真意。"));
    }
    
    return 1;
}

/**
 * @brief 重命名方案输入界面
 * @param object me 玩家对象
 * @param string old_name 原方案名
 * @return int 成功返回1
 */
int rename_scheme_input(object me, string old_name)
{
    string msg;
    
    if (!old_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    msg = sprintf("请输入新的方案名称：\n原名称：%s", old_name);
    msg += "\n"HIG"（长度1-12个字符）"NOR;
    
    tell_object(me, popup_input(msg, sprintf("wusheng_zhenyi rename_scheme_execute %s ", old_name)));
    return 1;
}

/**
 * @brief 执行重命名方案
 * @param object me 玩家对象
 * @param string old_name 原方案名
 * @param string new_name 新方案名
 * @return int 成功返回1
 */
int rename_scheme_execute(object me, string old_name, string new_name)
{
    string msg;
    
    if (!old_name || !new_name || new_name == "")
    {
        tell_object(me, popup_title("方案名称不能为空。"));
        return 1;
    }
    
    if (strlen(new_name) > 12 || strlen(new_name) < 1)
    {
        tell_object(me, popup_title("方案名称长度必须在1-12个字符之间。"));
        return 1;
    }
    
    if (ZHENYI_MASTER->rename_scheme(me, old_name, new_name))
    {
        msg = sprintf("成功将方案 %s 重命名为 %s", old_name, new_name);
        tell_object(me, popup_comb(msg, ({
            sprintf("查看方案详情:wusheng_zhenyi scheme_detail %s", new_name),
            "返回方案管理:wusheng_zhenyi scheme_management"
        })));
    }
    else
    {
        tell_object(me, popup_title("重命名失败，新名称可能已存在。"));
    }
    
    return 1;
}

/**
 * @brief 删除方案确认界面
 * @param object me 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1
 */
int delete_scheme_confirm(object me, string scheme_name)
{
    string msg;
    
    if (!scheme_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    msg = sprintf(""HIR"确定要删除方案 %s 吗？"NOR"\n删除后无法恢复！", scheme_name);
    
    tell_object(me, popup_comb(msg, ({
        sprintf("确定删除:wusheng_zhenyi delete_scheme_execute %s", scheme_name),
        sprintf("取消:wusheng_zhenyi scheme_detail %s", scheme_name)
    })));
    
    return 1;
}

/**
 * @brief 执行删除方案
 * @param object me 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1
 */
int delete_scheme_execute(object me, string scheme_name)
{
    string msg;
    
    if (!scheme_name)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    if (ZHENYI_MASTER->delete_scheme(me, scheme_name))
    {
        msg = sprintf("成功删除方案：%s", scheme_name);
        tell_object(me, popup_comb(msg, ({
            "返回方案管理:wusheng_zhenyi scheme_management",
            "返回主界面:wusheng_zhenyi main"
        })));
    }
    else
    {
        tell_object(me, popup_title("删除方案失败。"));
    }
    
    return 1;
}