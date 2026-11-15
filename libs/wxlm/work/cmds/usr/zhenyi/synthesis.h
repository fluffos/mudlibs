/**
 * @file synthesis.h
 * @brief 武圣真意系统合成模块
 * @author LPC开发者
 * @date 2024
 * @details 包含真意合成界面、选择、预览、确认、执行等功能
 */

/**
 * @brief 用于合成界面的真意排序比较函数
 * @param string id1 真意ID1
 * @param string id2 真意ID2
 * @param mapping filtered_bag 筛选后的背包映射
 * @return int 若 <0 表示 id1 排在前面
 * @details 按等级分组排序，同一等级范围内按获得时间排序
 */
int synthesis_zhenyi_cmp(string id1, string id2, mapping filtered_bag)
{
    mapping data1, data2;
    int level1, level2, base1, base2;

    data1 = filtered_bag[id1];
    data2 = filtered_bag[id2];

    if (!data1 || !data2)
        return 0;

    level1 = data1["level"];
    level2 = data2["level"];

    // 计算等级范围基数（向下取整到百位）
    base1 = (level1 / 100) * 100;
    base2 = (level2 / 100) * 100;

    // 先按等级范围排序
    if (base1 != base2)
        return base1 - base2;

    // 同等级范围内按获得时间降序
    return data2["create_time"] - data1["create_time"];
}

/**
 * @brief 用于等级范围排序的比较函数
 * @param string key1 等级范围键1
 * @param string key2 等级范围键2
 * @param mapping quality_level_stats 品质等级统计映射
 * @return int 若 <0 表示 key1 排在前面
 * @details 按等级范围升序排列
 */
int level_range_cmp(string key1, string key2, mapping quality_level_stats)
{
    int base1, base2;

    if (!quality_level_stats[key1] || !quality_level_stats[key2])
        return 0;

    base1 = quality_level_stats[key1]["base_level"];
    base2 = quality_level_stats[key2]["base_level"];

    return base1 - base2;
}

/**
 * @brief 显示合成系统主界面
 * @param object me 玩家对象
 * @return int 成功返回1
 * @details 显示可合成品质统计和合成入口
 */
int show_synthesis_interface(object me)
{
    mapping bag, synthesis_config, quality_level_stats;
    string *zhenyi_ids, zhenyi_id, quality, msg, *button_list;
    string *allowed_qualities, level_range_key;
    mapping zhenyi_data, quality_config;
    int level, zhenyi_level, base_level;
    
    level = me->query("level");
    
    if (level < 100)
    {
        tell_object(me, popup_title("你的修为尚浅，需要达到100级才能进行真意合成。"));
        return 1;
    }
    
    // 清理之前的合成会话数据（取消操作的处理逻辑）
    ZHENYI_MASTER->clear_synthesis_session(me);
    
    // 获取合成配置
    synthesis_config = ZHENYI_MASTER->query_synthesis_config();
    allowed_qualities = synthesis_config["allowed_qualities"];
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();
    
    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);
    
    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title("你的真意背包是空的，无法进行合成。"));
        return 1;
    }
    
    // 统计各品质和等级范围的真意数量
    quality_level_stats = ([]);
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];
        zhenyi_level = zhenyi_data["level"];
        
        if (member_array(quality, allowed_qualities) != -1)
        {
            // 计算等级范围（向下取整到百位）
            base_level = (zhenyi_level / 100) * 100;
            level_range_key = sprintf("%s_%d", quality, base_level);
            
            if (!quality_level_stats[level_range_key])
            {
                quality_level_stats[level_range_key] = ([
                    "quality": quality,
                    "base_level": base_level,
                    "count": 0
                ]);
            }
            quality_level_stats[level_range_key]["count"]++;
        }
    }
    
    msg = HIC"【武圣真意合成系统】"NOR"\n\n";
    msg += "将3个相同品质的真意合成为1个新的同品质真意\n";
    msg += HIR"注意：合成操作不可逆转！"NOR"\n";
    msg += HIG"合成要求：只有蓝色品质（灵犀真意）及以上的真意才能合成"NOR"\n\n";
    msg += HIY"可合成品质统计："NOR"\n";
    
    button_list = ({});
    
    // 按品质顺序显示统计信息
    foreach (quality in allowed_qualities)
    {
        string *level_keys;
        mapping quality_data;
        int total_count = 0, total_groups = 0;
        
        // 找出该品质的所有等级范围
        level_keys = filter(keys(quality_level_stats), (: sscanf($1, $(quality) + "_%*d") == 1 :));
        
        if (sizeof(level_keys) > 0)
        {
            quality_data = quality_config[quality];
            msg += sprintf("\n%s%s%s：\n", quality_data["color"], quality, NOR);
            
            // 按等级排序显示
            level_keys = sort_array(level_keys, "level_range_cmp", this_object(), quality_level_stats);
            
            foreach (level_range_key in level_keys)
            {
                mapping stats = quality_level_stats[level_range_key];
                int count = stats["count"];
                int groups = count / 3;
                base_level = stats["base_level"];
                
                total_count += count;
                total_groups += groups;
                
                msg += sprintf("  %d-%d级：%d个（可合成%d组）\n", 
                    base_level, base_level + 99, count, groups);
            }
            
            // 如果有可合成的组数，添加按钮
            if (total_groups > 0)
            {
                button_list += ({ sprintf("合成%s:wusheng_zhenyi synthesis_quality %s", quality, quality) });
            }
        }
    }
    
    if (!sizeof(button_list))
    {
        msg += "\n"HIG"当前没有足够的真意进行合成。"NOR"\n";
        msg += "每种品质需要至少3个相同等级范围的真意才能合成。";
    }
    
    button_list += ({ 
        "返回主界面:wusheng_zhenyi main",
        "查看帮助:help zhenyi_synthesis"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示指定品质的真意选择界面
 * @param object me 玩家对象
 * @param string quality 品质名称
 * @param int page 页码
 * @param string selected_ids 已选择的真意ID（用逗号分隔）
 * @return int 成功返回1
 * @details 显示指定品质的真意列表，支持多选和分页
 */
varargs int show_zhenyi_selection_for_synthesis(object me, string quality, int page, string selected_ids)
{
    mapping bag, filtered_bag, session_data;
    string *zhenyi_ids, zhenyi_id, msg, *button_list;
    string *selected_array, *page_ids;
    mapping zhenyi_data;
    int total_items, total_pages, start_index, end_index;
    int selected_count, items_per_page = 8;
    
    // 创建或更新合成会话
    session_data = ZHENYI_MASTER->query_synthesis_session(me);
    if (!mapp(session_data) || session_data["selected_quality"] != quality)
    {
        session_data = ZHENYI_MASTER->create_synthesis_session(me, quality);
    }
    
    // 更新会话状态
    ZHENYI_MASTER->update_synthesis_session(me, ([
        "step": "zhenyi_selecting",
        "current_page": page
    ]));
    
    if (!quality)
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    if (page < 1) page = 1;
    
    // 获取玩家背包数据
    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    if (!mapp(bag))
    {
        tell_object(me, popup_title("背包数据异常。"));
        return 1;
    }
    
    // 解析已选择的真意ID
    selected_array = ({});
    if (selected_ids && selected_ids != "")
    {
        selected_array = explode(selected_ids, ",");
    }
    selected_count = sizeof(selected_array);
    
    // 验证已选择的真意是否仍然有效
    if (selected_count > 0)
    {
        string *valid_selected = ({});
        string selected_id;
        
        foreach (selected_id in selected_array)
        {
            if (bag[selected_id] && bag[selected_id]["quality"] == quality)
            {
                valid_selected += ({ selected_id });
            }
        }
        
        // 如果有无效的选择，更新选择列表
        if (sizeof(valid_selected) != selected_count)
        {
            selected_array = valid_selected;
            selected_count = sizeof(selected_array);
            selected_ids = implode(selected_array, ",");
        }
    }
    
    // 更新会话中的选择状态
    ZHENYI_MASTER->update_synthesis_session(me, ([
        "selected_zhenyi": selected_array
    ]));
    
    // 筛选指定品质的真意
    filtered_bag = ZHENYI_MASTER->filter_zhenyi_by_criteria(me, quality, 0, 0);
    if (!mapp(filtered_bag))
    {
        tell_object(me, popup_title("筛选真意时出现错误。"));
        return 1;
    }
    
    zhenyi_ids = keys(filtered_bag);
    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title(sprintf("背包中没有%s品质的真意。", quality)));
        return 1;
    }
    
    // 按等级分组排序（同一等级范围内按获得时间排序）
    zhenyi_ids = sort_array(zhenyi_ids, "synthesis_zhenyi_cmp", this_object(), filtered_bag);
    
    total_items = sizeof(zhenyi_ids);
    total_pages = (total_items + items_per_page - 1) / items_per_page;
    if (total_pages < 1) total_pages = 1;
    
    if (page > total_pages) page = total_pages;
    
    start_index = (page - 1) * items_per_page;
    end_index = start_index + items_per_page - 1;
    if (end_index >= total_items) end_index = total_items - 1;
    
    page_ids = zhenyi_ids[start_index..end_index];
    
    if (selected_count == 3)
    {
        msg = sprintf(HIC"【已选择%s进行合成】"NOR"\n", quality);
    }
    else
    {
        msg = sprintf(HIC"【选择%s进行合成】"NOR" "HIY"第%d/%d页"NOR"\n", quality, page, total_pages);
    }
    
    // 显示选择进度条
    {
        string progress_bar = "";
        int i;
        for (i = 0; i < 3; i++)
        {
            if (i < selected_count)
                progress_bar += HIR"●"NOR;
            else
                progress_bar += HIG"○"NOR;
        }
        msg += sprintf("选择进度：%s (%d/3)\n", progress_bar, selected_count);
        
        if (selected_count == 3)
        {
            msg += HIG"选择完成！点击真意可以取消选择，或直接预览合成。"NOR"\n\n";
        }
        else
        {
            msg += HIR"注意：只能选择相同等级范围（如200-299级）的真意进行合成"NOR"\n\n";
        }
    }
    
    // 显示等级分组信息（只在选择未满时显示）
    if (selected_count < 3 && sizeof(page_ids) > 0)
    {
        mapping level_groups = ([]);
        string level_range;
        int base_level;
        
        // 统计当前页面的等级分组
        foreach (zhenyi_id in page_ids)
        {
            if (filtered_bag[zhenyi_id])
            {
                zhenyi_data = filtered_bag[zhenyi_id];
                base_level = (zhenyi_data["level"] / 100) * 100;
                level_range = sprintf("%d-%d级", base_level, base_level + 99);
                
                if (!level_groups[level_range])
                    level_groups[level_range] = 0;
                level_groups[level_range]++;
            }
        }
        
        if (sizeof(keys(level_groups)) > 1)
        {
            string *ranges = keys(level_groups);
            msg += HIY"当前页面等级分组："NOR"\n";
            foreach (level_range in ranges)
            {
                msg += sprintf("  %s：%d个\n", level_range, level_groups[level_range]);
            }
            msg += "\n";
        }
    }
    
    button_list = ({});
    
    if (selected_count == 3)
    {
        // 选择已满，只显示已选择的真意
        string selected_id;
        foreach (selected_id in selected_array)
        {
            if (bag[selected_id])
            {
                string button_text,new_selected;
                zhenyi_data = bag[selected_id];
                button_text = sprintf(HIR"✓ %s(Lv%d)"NOR, zhenyi_data["name"], zhenyi_data["level"]);
                new_selected = implode(selected_array - ({ selected_id }), ",");
                button_list += ({ sprintf("%s:wusheng_zhenyi synthesis_select %s %s %d", 
                    button_text, quality, new_selected, page) });
            }
        }
    }
    else
    {
        // 选择未满，显示当前页面的真意
        foreach (zhenyi_id in page_ids)
        {
            string button_text, new_selected;
            
            if (!filtered_bag[zhenyi_id])
                continue;
                
            zhenyi_data = filtered_bag[zhenyi_id];
            
            if (member_array(zhenyi_id, selected_array) != -1)
            {
                // 已选择，显示为取消选择
                button_text = sprintf(HIR"✓ %s(Lv%d)"NOR, zhenyi_data["name"], zhenyi_data["level"]);
                new_selected = implode(selected_array - ({ zhenyi_id }), ",");
                button_list += ({ sprintf("%s:wusheng_zhenyi synthesis_select %s %s %d", 
                    button_text, quality, new_selected, page) });
            }
            else
            {
                // 未选择且可以选择
                button_text = sprintf("%s%s(Lv%d)%s", zhenyi_data["color"], zhenyi_data["name"], zhenyi_data["level"], NOR);
                new_selected = implode(selected_array + ({ zhenyi_id }), ",");
                button_list += ({ sprintf("%s:wusheng_zhenyi synthesis_select %s %s %d", 
                    button_text, quality, new_selected, page) });
            }
        }
    }
    
    // 分页按钮（只在选择未满时显示）
    if (selected_count < 3)
    {
        if (page > 1)
            button_list += ({ sprintf("上一页:wusheng_zhenyi synthesis_select %s %s %d", quality, selected_ids ? selected_ids : "", page - 1) });
    }
    
    // 如果选择了3个真意，检查是否可以合成并显示预览按钮
    if (selected_count == 3)
    {
        mapping validation_result = ZHENYI_MASTER->validate_synthesis_conditions(me, selected_array);
        if (validation_result["valid"])
        {
            button_list += ({ sprintf("预览合成:wusheng_zhenyi synthesis_preview %s", selected_ids) });
        }
        else
        {
            // 显示错误信息，但仍允许重新选择
            msg += sprintf("\n"HIR"选择错误：%s"NOR"\n", validation_result["error"]);
        }
    }
    else if (selected_count > 0)
    {
        // 显示已选择真意的等级范围提示
        string selected_id;
        int min_level = 9999, max_level = 0;
        
        foreach (selected_id in selected_array)
        {
            if (bag[selected_id])
            {
                int level = bag[selected_id]["level"];
                if (level < min_level) min_level = level;
                if (level > max_level) max_level = level;
            }
        }
        
        if (min_level != 9999)
        {
            int min_base = (min_level / 100) * 100;
            int max_base = (max_level / 100) * 100;
            
            if (min_base == max_base)
            {
                msg += sprintf(HIG"已选择真意等级范围：%d-%d级"NOR"\n", min_base, min_base + 99);
            }
            else
            {
                msg += sprintf(HIR"警告：已选择的真意不在同一等级范围内！"NOR"\n");
            }
            
            // 显示已选择的真意列表
            msg += HIY"已选择的真意："NOR"\n";
            foreach (selected_id in selected_array)
            {
                if (bag[selected_id])
                {
                    mapping selected_zhenyi = bag[selected_id];
                    msg += sprintf("  %s%s%s (Lv%d)\n", 
                        selected_zhenyi["color"],
                        selected_zhenyi["name"],
                        NOR,
                        selected_zhenyi["level"]
                    );
                }
            }
        }
    }
    
    // 添加智能选择和清除选择按钮
    if (selected_count > 0)
    {
        button_list += ({ sprintf("清除选择:wusheng_zhenyi synthesis_select %s  %d", quality, page) });
    }
    
    // 如果选择数量少于3个，添加智能选择按钮
    if (selected_count < 3 && sizeof(page_ids) > 0)
    {
        // 找到当前页面第一个未选择的真意的等级范围
        string first_unselected_id = 0;
        int target_base_level = 0;
        
        foreach (zhenyi_id in page_ids)
        {
            if (member_array(zhenyi_id, selected_array) == -1 && filtered_bag[zhenyi_id])
            {
                first_unselected_id = zhenyi_id;
                target_base_level = (filtered_bag[zhenyi_id]["level"] / 100) * 100;
                break;
            }
        }
        
        if (first_unselected_id)
        {
            // 统计同等级范围的未选择真意
            string *same_level_ids = ({});
            foreach (zhenyi_id in zhenyi_ids)
            {
                if (member_array(zhenyi_id, selected_array) == -1 && filtered_bag[zhenyi_id])
                {
                    int base_level = (filtered_bag[zhenyi_id]["level"] / 100) * 100;
                    if (base_level == target_base_level && sizeof(same_level_ids) < (3 - selected_count))
                    {
                        same_level_ids += ({ zhenyi_id });
                    }
                }
            }
            
            if (sizeof(same_level_ids) > 0)
            {
                string auto_selected = implode(selected_array + same_level_ids, ",");
                button_list += ({ sprintf("智能选择(%d-%d级):wusheng_zhenyi synthesis_select %s %s %d", 
                    target_base_level, target_base_level + 99, quality, auto_selected, page) });
            }
        }
    }
    
    button_list += ({ "返回合成界面:wusheng_zhenyi synthesis" });
    
    // 下一页按钮（只在选择未满时显示）
    if (selected_count < 3 && page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi synthesis_select %s %s %d", quality, selected_ids ? selected_ids : "", page + 1) });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示合成预览界面
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（用逗号分隔）
 * @return int 成功返回1
 * @details 显示将要合成的真意详情和确认选项，包含详细的真意信息展示
 */
int show_synthesis_preview(object me, string selected_ids)
{
    mapping bag, zhenyi_data, validation_result, effects, effect_info;
    mapping quality_config, quality_data;
    string *selected_array, zhenyi_id, msg, *button_list;
    string quality, *effect_types, effect_type;
    int target_level, i, effect_value;
    
    if (!selected_ids || selected_ids == "")
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    selected_array = explode(selected_ids, ",");
    if (sizeof(selected_array) != 3)
    {
        tell_object(me, popup_title("必须选择3个真意进行合成。"));
        return 1;
    }
    
    // 验证合成条件
    validation_result = ZHENYI_MASTER->validate_synthesis_conditions(me, selected_array);
    if (!validation_result["valid"])
    {
        tell_object(me, popup_title(validation_result["error"]));
        return 1;
    }
    
    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    if (!mapp(bag))
    {
        tell_object(me, popup_title("背包数据异常。"));
        return 1;
    }
    
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();
    
    msg = HIC"【合成预览确认】"NOR"\n\n";
    msg += HIR"即将消耗以下3个真意："NOR"\n\n";
    
    // 显示每个真意的详细信息
    for (i = 0; i < sizeof(selected_array); i++)
    {
        zhenyi_id = selected_array[i];
        
        if (!bag[zhenyi_id])
        {
            tell_object(me, popup_title(sprintf("真意 %s 不存在或已被移除。", zhenyi_id)));
            return 1;
        }
        
        zhenyi_data = bag[zhenyi_id];
        
        if (i == 0)
        {
            quality = zhenyi_data["quality"];
            target_level = (zhenyi_data["level"] / 100) * 100;
        }
        
        msg += sprintf(HIY"真意%d："NOR" %s%s%s (Lv%d)\n", 
            i + 1,
            zhenyi_data["color"],
            zhenyi_data["name"],
            NOR,
            zhenyi_data["level"]
        );
        
        // 显示真意效果
        effects = zhenyi_data["effects"];
        effect_types = keys(effects);
        
        if (sizeof(effect_types) > 0)
        {
            msg += "  效果：";
            foreach (effect_type in effect_types)
            {
                effect_info = effects[effect_type];
                effect_value = effect_info["value"];
                msg += sprintf("%s +%d  ", 
                    ZHENYI_MASTER->get_effect_name(effect_type), 
                    effect_value
                );
            }
            msg += "\n";
        }
        msg += "\n";
    }
    
    // 显示合成结果预览
    quality_data = quality_config[quality];
    msg += HIY"合成结果预览："NOR"\n";
    msg += sprintf("品质：%s%s%s\n", quality_data["color"], quality, NOR);
    msg += sprintf("等级：%d级\n", target_level);
    msg += sprintf("效果：随机生成（%d-%d个效果）\n", 
        quality_data["effects_min"], quality_data["effects_max"]);
    msg += sprintf("效果强度：%d%%-%d%%\n\n", 
        quality_data["power_min"], quality_data["power_max"]);
    
    msg += HIR"重要提醒："NOR"\n";
    msg += "• 合成操作"HIR"不可逆转"NOR"，原真意将永久消失\n";
    msg += "• 新真意的具体效果将随机生成\n";
    msg += "• 请确认后再进行合成操作\n\n";
    
    button_list = ({
        sprintf("最终确认合成:wusheng_zhenyi synthesis_confirm %s", selected_ids),
        sprintf("返回选择:wusheng_zhenyi synthesis_quality %s", quality),
        "取消合成:wusheng_zhenyi synthesis",
        "查看帮助:help zhenyi_synthesis"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示合成最终确认对话框
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（用逗号分隔）
 * @return int 成功返回1
 * @details 显示最终确认对话框，确保玩家了解操作的不可逆性
 */
int show_synthesis_confirmation(object me, string selected_ids)
{
    mapping validation_result;
    string *selected_array, msg, *button_list, quality;
    
    if (!selected_ids || selected_ids == "")
    {
        tell_object(me, popup_title("参数错误。"));
        return 1;
    }
    
    selected_array = explode(selected_ids, ",");
    if (sizeof(selected_array) != 3)
    {
        tell_object(me, popup_title("必须选择3个真意进行合成。"));
        return 1;
    }
    
    // 再次验证合成条件（防止在预览过程中真意被其他操作影响）
    validation_result = ZHENYI_MASTER->validate_synthesis_conditions(me, selected_array);
    if (!validation_result["valid"])
    {
        tell_object(me, popup_title(validation_result["error"]));
        return 1;
    }
    
    quality = validation_result["quality"];
    
    msg = HIR"【最终确认】"NOR"\n\n";
    msg += "你即将进行武圣真意合成操作！\n\n";
    msg += HIY"操作详情："NOR"\n";
    msg += sprintf("• 消耗：3个 %s 品质真意\n", quality);
    msg += sprintf("• 获得：1个 %s 品质真意（随机效果）\n", quality);
    msg += sprintf("• 等级：%d级\n\n", validation_result["target_level"]);
    
    msg += HIR"重要警告："NOR"\n";
    msg += "• 此操作"HIR"完全不可逆转"NOR"！\n";
    msg += "• 原有的3个真意将"HIR"永久消失"NOR"！\n";
    msg += "• 新真意的效果将"HIY"完全随机"NOR"！\n";
    msg += "• 可能获得比原真意更差的效果！\n\n";
    
    msg += "请再次确认你要进行此操作：\n";
    
    button_list = ({
        sprintf("我确认要合成:wusheng_zhenyi synthesis_execute %s", selected_ids),
        sprintf("返回预览:wusheng_zhenyi synthesis_preview %s", selected_ids),
        "取消操作:wusheng_zhenyi synthesis",
        "查看帮助:help zhenyi_synthesis"
    });
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 执行合成操作
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（用逗号分隔）
 * @return int 成功返回1
 * @details 执行实际的合成操作并显示详细结果
 */
int execute_synthesis_action(object me, string selected_ids)
{
    mapping synthesis_result, new_zhenyi, consumed_zhenyi, validation_result;
    string *selected_array, msg, *button_list, *consumed_ids;
    string consumed_id, error_msg;
    int total_synthesis_count, start_time;
    
    start_time = time();
    
    // 基础参数验证
    if (!me || !objectp(me))
    {
        return 0;
    }
    
    if (!selected_ids || selected_ids == "")
    {
        tell_object(me, popup_title("参数错误：未选择任何真意。"));
        return 1;
    }
    
    // 检查玩家状态
    if (me->query("level") < 100)
    {
        tell_object(me, popup_title("你的修为尚浅，需要达到100级才能进行合成。"));
        return 1;
    }
    
    // 解析真意ID并进行安全检查
    catch {
        selected_array = explode(selected_ids, ",");
    };
    
    if (!arrayp(selected_array))
    {
        tell_object(me, popup_title("真意ID解析失败，请重新选择。"));
        return 1;
    }
    
    if (sizeof(selected_array) != 3)
    {
        tell_object(me, popup_title(sprintf("必须选择3个真意进行合成，当前选择了%d个。", sizeof(selected_array))));
        return 1;
    }
    
    // 预验证合成条件（快速检查，避免无效操作）
    validation_result = ZHENYI_MASTER->validate_synthesis_conditions(me, selected_array);
    if (!mapp(validation_result) || !validation_result["valid"])
    {
        error_msg = validation_result["error"] || "验证失败";
        
        msg = HIR"【合成条件不满足】"NOR"\n\n";
        msg += sprintf("无法进行合成：%s\n\n", error_msg);
        
        // 根据错误类型提供具体建议
        if (stringp(error_msg))
        {
            if (strsrch(error_msg, "品质") != -1)
            {
                msg += HIG"提示：只有蓝色品质（灵犀真意）及以上的真意才能合成。"NOR"\n";
            }
            else if (strsrch(error_msg, "等级") != -1)
            {
                msg += HIG"提示：参与合成的真意必须在同一等级范围内（如200-299级）。"NOR"\n";
            }
            else if (strsrch(error_msg, "冷却") != -1)
            {
                msg += HIG"提示：合成操作有冷却时间，请稍后再试。"NOR"\n";
            }
        }
        
        button_list = ({
            "重新选择:wusheng_zhenyi synthesis",
            "查看背包:wusheng_zhenyi bag",
            "返回主界面:wusheng_zhenyi main"
        });
        
        tell_object(me, popup_comb(msg, button_list));
        return 1;
    }
    
    // 显示合成进行中的提示
    tell_object(me, HIC"正在进行合成操作，请稍候..."NOR"\n");
    
    // 清理合成会话数据
    catch {
        ZHENYI_MASTER->clear_synthesis_session(me);
    };
    
    // 执行合成操作
    catch {
        synthesis_result = ZHENYI_MASTER->execute_synthesis(me, selected_array);
    };
    
    // 检查合成结果
    if (!mapp(synthesis_result))
    {
        msg = HIR"【系统异常】"NOR"\n\n";
        msg += "合成操作遇到系统异常，请稍后重试。\n";
        msg += "如果问题持续存在，请联系管理员。\n\n";
        msg += sprintf("错误时间：%s", ctime(time()));
        
        button_list = ({
            "重新尝试:wusheng_zhenyi synthesis",
            "查看背包状态:wusheng_zhenyi bag",
            "返回主界面:wusheng_zhenyi main"
        });
        
        // 记录异常日志
        log_file("synthesis_error", sprintf("[%s] 玩家 %s 合成操作返回异常结果: %O\n", 
            ctime(time()), me->query("id"), synthesis_result));
    }
    else if (synthesis_result["success"])
    {
        new_zhenyi = synthesis_result["new_zhenyi"];
        
        if (!mapp(new_zhenyi))
        {
            msg = HIR"【合成异常】"NOR"\n\n";
            msg += "合成操作完成，但新真意数据异常。\n";
            msg += "请检查你的真意背包或联系管理员。";
            
            button_list = ({
                "查看背包:wusheng_zhenyi bag",
                "返回主界面:wusheng_zhenyi main"
            });
        }
        else
        {
            // 安全地获取消耗真意信息
            catch {
                consumed_zhenyi = new_zhenyi["consumed_zhenyi"];
                consumed_ids = keys(consumed_zhenyi);
            };
            
            if (!arrayp(consumed_ids))
                consumed_ids = ({});
            
            catch {
                total_synthesis_count = me->query("zhenyi_synthesis/total_count") || 0;
            };
            
            msg = HIC"【合成成功！】"NOR"\n\n";
            msg += HIY"合成统计："NOR"\n";
            msg += sprintf("• 消耗真意：%d个\n", sizeof(consumed_ids));
            msg += sprintf("• 获得真意：1个\n");
            msg += sprintf("• 累计合成：%d次\n", total_synthesis_count);
            msg += sprintf("• 合成耗时：%d秒\n\n", time() - start_time);
            
            if (sizeof(consumed_ids) > 0)
            {
                msg += HIY"消耗的真意："NOR"\n";
                foreach (consumed_id in consumed_ids)
                {
                    mapping consumed_data = consumed_zhenyi[consumed_id];
                    if (mapp(consumed_data))
                    {
                        msg += sprintf("• %s%s%s (Lv%d)\n", 
                            consumed_data["color"] || "",
                            consumed_data["name"] || "未知真意",
                            NOR,
                            consumed_data["level"] || 0
                        );
                    }
                }
                msg += "\n";
            }
            
            msg += HIY"获得的新真意："NOR"\n";
            
            // 安全地格式化真意信息
            catch {
                msg += ZHENYI_MASTER->format_zhenyi_info(new_zhenyi);
            };
            
            // 播放成功音效提示
            tell_object(me, sprintf("%s合成成功！新真意已添加到背包中。%s\n", 
                HIC, NOR));
            
            button_list = ({
                "继续合成:wusheng_zhenyi synthesis",
                "查看背包:wusheng_zhenyi bag",
                "返回主界面:wusheng_zhenyi main",
                "查看帮助:help zhenyi_synthesis"
            });
            
            // 记录成功日志
            log_file("synthesis_success", sprintf("[%s] 玩家 %s 合成成功: %s (耗时%d秒)\n", 
                ctime(time()), me->query("id"), new_zhenyi["name"] || "未知真意", time() - start_time));
        }
    }
    else
    {
        error_msg = synthesis_result["error"] || "未知错误";
        
        msg = HIR"【合成失败】"NOR"\n\n";
        msg += sprintf("合成失败原因：%s\n\n", error_msg);
        
        // 根据错误类型提供具体的解决建议
        if (strsrch(error_msg, "冷却") != -1)
        {
            msg += HIG"解决方案："NOR"\n";
            msg += "• 等待冷却时间结束后再次尝试\n";
            msg += "• 合成操作有短暂的冷却时间以确保系统稳定\n";
        }
        else if (strsrch(error_msg, "锁定") != -1)
        {
            msg += HIG"解决方案："NOR"\n";
            msg += "• 稍等片刻后重新尝试\n";
            msg += "• 确保没有其他合成操作正在进行\n";
        }
        else if (strsrch(error_msg, "数据") != -1)
        {
            msg += HIG"解决方案："NOR"\n";
            msg += "• 重新登录游戏后再试\n";
            msg += "• 检查网络连接是否稳定\n";
            msg += "• 如问题持续，请联系管理员\n";
        }
        else if (strsrch(error_msg, "不存在") != -1)
        {
            msg += HIG"解决方案："NOR"\n";
            msg += "• 检查背包中的真意是否仍然存在\n";
            msg += "• 重新选择要合成的真意\n";
        }
        else
        {
            msg += HIG"通用解决方案："NOR"\n";
            msg += "• 检查背包中的真意状态\n";
            msg += "• 确认选择的真意符合合成条件\n";
            msg += "• 重新选择符合条件的真意进行合成\n";
            msg += "• 如问题持续，请联系管理员\n";
        }
        
        button_list = ({
            "重新选择真意:wusheng_zhenyi synthesis",
            "查看背包状态:wusheng_zhenyi bag",
            "返回主界面:wusheng_zhenyi main"
        });
        
        // 记录失败日志
        log_file("zhenyi/synthesis_failure", sprintf("[%s] 玩家 %s 合成失败: %s\n", 
            ctime(time()), me->query("id"), error_msg));
    }
    
    tell_object(me, popup_comb(msg, button_list));
    return 1;
}