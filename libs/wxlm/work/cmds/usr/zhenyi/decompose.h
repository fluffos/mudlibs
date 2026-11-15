/**
 * @file decompose.h
 * @brief 武圣真意系统分解模块
 * @author LPC开发者
 * @date 2024
 * @details 包含真意分解界面、选择、预览、确认、执行等功能
 */

/**
 * @brief 用于分解界面的真意排序比较函数
 * @param string id1 真意ID1
 * @param string id2 真意ID2
 * @param mapping bag 背包映射
 * @param mapping quality_config 品质配置映射
 * @return int 若 <0 表示 id1 排在前面
 * @details 按品质优先级排序，同品质内按等级降序，同等级按获得时间降序
 */
int decompose_zhenyi_cmp(string id1, string id2, mapping bag, mapping quality_config)
{
    mapping data1, data2;
    string quality1, quality2;
    int level1, level2, priority1, priority2, create_time1, create_time2;

    data1 = bag[id1];
    data2 = bag[id2];

    if (!data1 || !data2)
        return 0;

    quality1 = data1["quality"];
    quality2 = data2["quality"];
    level1 = data1["level"];
    level2 = data2["level"];
    create_time1 = data1["create_time"];
    create_time2 = data2["create_time"];

    // 获取品质优先级
    priority1 = quality_config[quality1]["priority"];
    priority2 = quality_config[quality2]["priority"];

    // 先按品质优先级排序（低品质在前）
    if (priority1 != priority2)
        return priority1 - priority2;

    // 同品质按等级降序
    if (level1 != level2)
        return level2 - level1;

    // 同等级按获得时间降序（新获得的在前）
    return create_time2 - create_time1;
}

/**
 * @brief 显示分解系统主界面
 * @param object me 玩家对象
 * @return int 成功返回1
 * @details 显示分解功能入口和武蕴状态
 */
int show_decompose_interface(object me)
{
    mapping bag, quality_config;
    string *zhenyi_ids, zhenyi_id, quality, msg, *button_list;
    mapping zhenyi_data, quality_stats;
    int current_wuyun, total_decomposable, total_wuyun_value;

    if (!me)
        return 0;

    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();

    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title("你的真意背包是空的，无法进行分解。"));
        return 1;
    }

    // 统计各品质真意数量和可获得武蕴
    quality_stats = ([]);
    total_decomposable = 0;
    total_wuyun_value = 0;

    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];

        if (!quality_stats[quality])
        {
            quality_stats[quality] = ([
                "count": 0,
                "wuyun_value": 0
            ]);
        }

        quality_stats[quality]["count"]++;
        quality_stats[quality]["wuyun_value"] += ZHENYI_MASTER->get_decompose_wuyun_amount(quality);
        total_decomposable++;
        total_wuyun_value += ZHENYI_MASTER->get_decompose_wuyun_amount(quality);
    }

    msg = HIC"【武圣真意分解系统】"NOR"\n\n";
    msg += "将真意分解为武蕴，武蕴可用于其他系统功能\n";
    msg += HIR"注意：分解操作不可逆转！"NOR"\n\n";
    msg += HIY"当前武蕴："HIW + current_wuyun + NOR"\n";
    msg += HIG"可分解真意："HIW + total_decomposable + "个"NOR"\n";
    msg += HIG"可获得武蕴："HIW + total_wuyun_value + "点"NOR"\n\n";

    msg += HIY"分解规则："NOR"\n";
    msg += "白色真意：1点武蕴    绿色真意：2点武蕴\n";
    msg += "蓝色真意：5点武蕴    红色真意：10点武蕴\n";
    msg += "金色真意：15点武蕴   紫色真意：20点武蕴\n\n";

    msg += HIY"背包真意统计："NOR"\n";
    foreach (quality in keys(quality_stats))
    {
        mapping qdata;
        mapping stats;
        
        qdata = quality_config[quality];
        stats = quality_stats[quality];
        msg += sprintf("%s%s%s：%d个（可获得%d点武蕴）\n",
            qdata["color"], quality, NOR,
            stats["count"], stats["wuyun_value"]);
    }

    button_list = ({
        "逐个选择分解:wusheng_zhenyi decompose_single",
        "按品质批量分解:wusheng_zhenyi decompose_batch",
        "查看武蕴状态:wusheng_zhenyi wuyun_status",
        "返回主界面:wusheng_zhenyi main"
    });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示单个分解的真意选择界面
 * @param object me 玩家对象
 * @param int page 页码
 * @return int 成功返回1
 * @details 显示所有可分解真意的分页列表
 */
varargs int show_decompose_selection(object me, int page)
{
    mapping bag, quality_config;
    string *zhenyi_ids, zhenyi_id, quality, msg, *button_list;
    mapping zhenyi_data;
    int total_count, start_index, end_index, per_page, total_pages;
    int current_wuyun;

    if (!me)
        return 0;

    if (!page || page < 1)
        page = 1;

    per_page = 8;
    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();

    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title("你的真意背包是空的，无法进行分解。"));
        return 1;
    }

    // 排序真意列表
    zhenyi_ids = sort_array(zhenyi_ids, "decompose_zhenyi_cmp", this_object(), bag, quality_config);

    total_count = sizeof(zhenyi_ids);
    total_pages = (total_count + per_page - 1) / per_page;

    if (page > total_pages)
        page = total_pages;

    start_index = (page - 1) * per_page;
    end_index = start_index + per_page - 1;
    if (end_index >= total_count)
        end_index = total_count - 1;

    msg = HIC"【选择要分解的真意】"NOR"\n\n";
    msg += HIY"当前武蕴："HIW + current_wuyun + NOR"\n";
    msg += sprintf("第%d页，共%d页（共%d个真意）\n\n", page, total_pages, total_count);

    button_list = ({});

    for (int i = start_index; i <= end_index; i++)
    {
        mapping qdata;
        int wuyun_amount;
        
        zhenyi_id = zhenyi_ids[i];
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];

        qdata = quality_config[quality];
        wuyun_amount = ZHENYI_MASTER->get_decompose_wuyun_amount(quality);

        msg += sprintf("%d. %s%s%s Lv.%d（+%d武蕴）\n",
            i - start_index + 1,
            qdata["color"], zhenyi_data["name"] || (zhenyi_data["base_name"] + "·" + quality), NOR,
            zhenyi_data["level"], wuyun_amount);

        button_list += ({ sprintf("分解第%d个:wusheng_zhenyi decompose_preview %s", i - start_index + 1, zhenyi_id) });
    }

    // 分页按钮
    if (page > 1)
        button_list += ({ sprintf("上一页:wusheng_zhenyi decompose_single %d", page - 1) });
    if (page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi decompose_single %d", page + 1) });

    button_list += ({ "返回分解界面:wusheng_zhenyi decompose" });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示批量分解界面
 * @param object me 玩家对象
 * @return int 成功返回1
 * @details 按品质分类显示批量分解选项
 */
int show_batch_decompose_interface(object me)
{
    mapping bag, quality_config, quality_stats;
    string *zhenyi_ids, zhenyi_id, quality, msg, *button_list;
    mapping zhenyi_data;
    int current_wuyun;

    if (!me)
        return 0;

    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();

    if (!sizeof(zhenyi_ids))
    {
        tell_object(me, popup_title("你的真意背包是空的，无法进行分解。"));
        return 1;
    }

    // 统计各品质真意数量
    quality_stats = ([]);
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];

        if (!quality_stats[quality])
        {
            quality_stats[quality] = ([
                "count": 0,
                "wuyun_value": 0
            ]);
        }

        quality_stats[quality]["count"]++;
        quality_stats[quality]["wuyun_value"] += ZHENYI_MASTER->get_decompose_wuyun_amount(quality);
    }

    msg = HIC"【批量分解真意】"NOR"\n\n";
    msg += HIY"当前武蕴："HIW + current_wuyun + NOR"\n";
    msg += "选择要批量分解的真意品质：\n\n";

    button_list = ({});

    foreach (quality in keys(quality_stats))
    {
        mapping qdata;
        mapping stats;
        
        qdata = quality_config[quality];
        stats = quality_stats[quality];

        msg += sprintf("%s%s%s：%d个（可获得%d点武蕴）\n",
            qdata["color"], quality, NOR,
            stats["count"], stats["wuyun_value"]);

        button_list += ({ sprintf("分解%s(%d个):wusheng_zhenyi decompose_quality %s", quality, stats["count"], quality) });
    }

    button_list += ({ "返回分解界面:wusheng_zhenyi decompose" });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示指定品质的分解界面
 * @param object me 玩家对象
 * @param string quality 品质名称
 * @param int page 页码
 * @return int 成功返回1
 * @details 显示指定品质的真意列表，支持多选
 */
varargs int show_decompose_by_quality(object me, string quality, int page)
{
    mapping bag, quality_config, qdata;
    string *zhenyi_ids, *filtered_ids, zhenyi_id, msg, *button_list;
    mapping zhenyi_data;
    int total_count, per_page, total_pages, start_index, end_index;
    int current_wuyun, total_wuyun_value, wuyun_per_item;
    string all_ids;
    if (!me)
        return 0;

    if (!page || page < 1)
        page = 1;

    per_page = 10;
    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    zhenyi_ids = keys(bag);
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();

    // 筛选指定品质的真意
    filtered_ids = ({});
    total_wuyun_value = 0;

    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        if (zhenyi_data["quality"] == quality)
        {
            filtered_ids += ({ zhenyi_id });
            total_wuyun_value += ZHENYI_MASTER->get_decompose_wuyun_amount(quality);
        }
    }

    if (!sizeof(filtered_ids))
    {
        tell_object(me, popup_title(sprintf("你没有%s品质的真意。", quality)));
        return 1;
    }

    // 排序
    filtered_ids = sort_array(filtered_ids, "decompose_zhenyi_cmp", this_object(), bag, quality_config);

    total_count = sizeof(filtered_ids);
    total_pages = (total_count + per_page - 1) / per_page;

    if (page > total_pages)
        page = total_pages;

    start_index = (page - 1) * per_page;
    end_index = start_index + per_page - 1;
    if (end_index >= total_count)
        end_index = total_count - 1;

    qdata = quality_config[quality];
    wuyun_per_item = ZHENYI_MASTER->get_decompose_wuyun_amount(quality);

    msg = sprintf(HIC"【分解%s%s%s真意】"NOR"\n\n", qdata["color"], quality, NOR);
    msg += HIY"当前武蕴："HIW + current_wuyun + NOR"\n";
    msg += sprintf("共%d个%s真意，可获得%d点武蕴\n", total_count, quality, total_wuyun_value);
    msg += sprintf("第%d页，共%d页\n\n", page, total_pages);

    button_list = ({});

    // 显示当前页的真意
    for (int i = start_index; i <= end_index; i++)
    {
        zhenyi_id = filtered_ids[i];
        zhenyi_data = bag[zhenyi_id];

        msg += sprintf("%s%s%s Lv.%d（+%d武蕴）\n",
            qdata["color"], zhenyi_data["name"] || (zhenyi_data["base_name"] + "·" + quality), NOR,
            zhenyi_data["level"], wuyun_per_item);
    }
    
    all_ids = implode(filtered_ids, ",");
    button_list += ({ sprintf("分解全部%s:wusheng_zhenyi decompose_preview %s", quality, all_ids) });

    // 分页按钮
    if (page > 1)
        button_list += ({ sprintf("上一页:wusheng_zhenyi decompose_quality %s %d", quality, page - 1) });
    if (page < total_pages)
        button_list += ({ sprintf("下一页:wusheng_zhenyi decompose_quality %s %d", quality, page + 1) });

    button_list += ({ "返回批量分解:wusheng_zhenyi decompose_batch" });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示分解预览界面
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（逗号分隔）
 * @return int 成功返回1
 * @details 显示即将分解的真意详情和获得的武蕴
 */
int show_decompose_preview(object me, string selected_ids)
{
    mapping bag, quality_config, preview_result;
    string *zhenyi_ids, zhenyi_id, quality, msg, *button_list;
    mapping quality_stats;
    int current_wuyun, total_wuyun_gain;

    if (!me)
        return 0;

    if (!selected_ids || selected_ids == "")
    {
        tell_object(me, popup_title("没有选择要分解的真意。"));
        return 1;
    }

    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    zhenyi_ids = explode(selected_ids, ",");
    bag = ZHENYI_MASTER->query_zhenyi_bag(me);
    quality_config = ZHENYI_MASTER->query_zhenyi_quality_config();

    // 验证所有真意是否存在
    foreach (zhenyi_id in zhenyi_ids)
    {
        if (!bag[zhenyi_id])
        {
            tell_object(me, popup_title("选择的真意中包含无效项目，请重新选择。"));
            return 1;
        }
    }

    // 预览分解结果
    preview_result = ZHENYI_MASTER->preview_decompose_result(me, zhenyi_ids);
    if (!preview_result["success"])
    {
        tell_object(me, popup_title(preview_result["error"]));
        return 1;
    }

    quality_stats = preview_result["quality_stats"];
    total_wuyun_gain = preview_result["total_wuyun"];

    msg = HIC"【分解预览】"NOR"\n\n";
    msg += HIY"当前武蕴："HIW + current_wuyun + NOR"\n";
    msg += HIY"分解后武蕴："HIW + (current_wuyun + total_wuyun_gain) + NOR"\n";
    msg += HIY"武蕴增加："HIW"+" + total_wuyun_gain + NOR"\n\n";

    msg += HIY"即将分解的真意："NOR"\n";
    foreach (quality in keys(quality_stats))
    {
        mapping qdata;
        mapping stats;
        
        qdata = quality_config[quality];
        stats = quality_stats[quality];

        msg += sprintf("%s%s%s：%d个（+%d武蕴）\n",
            qdata["color"], quality, NOR,
            stats["count"], stats["wuyun_value"]);
    }

    msg += "\n"HIR"确认分解吗？此操作不可逆转！"NOR;

    button_list = ({
        sprintf("确认分解:wusheng_zhenyi decompose_confirm %s", selected_ids),
        "取消分解:wusheng_zhenyi decompose"
    });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示分解确认界面
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（逗号分隔）
 * @return int 成功返回1
 * @details 最终确认分解操作
 */
int show_decompose_confirmation(object me, string selected_ids)
{
    string msg, *button_list;

    if (!me)
        return 0;

    msg = HIR"【最终确认】"NOR"\n\n";
    msg += "你确定要分解选中的真意吗？\n";
    msg += HIR"此操作将永久删除这些真意，无法恢复！"NOR"\n\n";
    msg += "请再次确认你的选择。";

    button_list = ({
        sprintf("确定分解:wusheng_zhenyi decompose_execute %s", selected_ids),
        "取消操作:wusheng_zhenyi decompose"
    });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 执行分解操作
 * @param object me 玩家对象
 * @param string selected_ids 选中的真意ID（逗号分隔）
 * @return int 成功返回1
 * @details 执行实际的分解操作并显示结果
 */
int execute_decompose_action(object me, string selected_ids)
{
    mapping decompose_result;
    string *zhenyi_ids, msg, *button_list;
    int old_wuyun, new_wuyun, wuyun_gained;

    if (!me)
        return 0;

    if (!selected_ids || selected_ids == "")
    {
        tell_object(me, popup_title("没有选择要分解的真意。"));
        return 1;
    }

    old_wuyun = me->query("wuyun");
    if (!old_wuyun)
        old_wuyun = 0;

    zhenyi_ids = explode(selected_ids, ",");

    // 执行分解
    decompose_result = ZHENYI_MASTER->batch_decompose_by_ids(me, zhenyi_ids);

    if (!decompose_result["success"])
    {
        tell_object(me, popup_title(decompose_result["error"]));
        return 1;
    }

    new_wuyun = me->query("wuyun");
    wuyun_gained = decompose_result["total_wuyun"];

    msg = HIC"【分解成功】"NOR"\n\n";
    msg += HIY"分解完成！"NOR"\n";
    msg += sprintf("分解了%d个真意\n", sizeof(zhenyi_ids));
    msg += sprintf("获得武蕴：%d点\n", wuyun_gained);
    msg += sprintf("当前武蕴：%d点\n", new_wuyun);

    button_list = ({
        "继续分解:wusheng_zhenyi decompose",
        "查看武蕴:wusheng_zhenyi wuyun_status",
        "返回主界面:wusheng_zhenyi main"
    });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}

/**
 * @brief 显示武蕴状态界面
 * @param object me 玩家对象
 * @return int 成功返回1
 * @details 显示当前武蕴数量和相关统计信息
 */
int show_wuyun_status(object me)
{
    mapping decompose_history;
    string msg, *button_list;
    int current_wuyun, total_decomposed, total_gained;

    if (!me)
        return 0;

    current_wuyun = me->query("wuyun");
    if (!current_wuyun)
        current_wuyun = 0;

    // 获取分解统计
    decompose_history = ZHENYI_MASTER->query_decompose_statistics(me);
    total_decomposed = decompose_history["total_decomposed"];
    total_gained = decompose_history["total_wuyun_gained"];

    msg = HIC"【武蕴状态】"NOR"\n\n";
    msg += HIY"当前武蕴："HIW + current_wuyun + "点"NOR"\n\n";
    msg += HIY"历史统计："NOR"\n";
    msg += sprintf("累计分解真意：%d个\n", total_decomposed);
    msg += sprintf("累计获得武蕴：%d点\n", total_gained);

    if (total_decomposed > 0)
    {
        msg += sprintf("平均每个真意：%.1f点武蕴\n", (float)total_gained / total_decomposed);
    }

    msg += "\n"HIG"武蕴可用于其他系统功能，请合理使用。"NOR;

    button_list = ({
        "分解真意:wusheng_zhenyi decompose",
        "返回主界面:wusheng_zhenyi main"
    });

    tell_object(me, popup_comb(msg, button_list));
    return 1;
}