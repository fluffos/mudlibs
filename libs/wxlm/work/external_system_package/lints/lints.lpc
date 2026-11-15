/**
 * @brief lints.c - 编译及运行时错误记录守护进程
 * @details 负责记录编译时错误信息 (供 update 命令查询)
 *          以及处理、缓存、记录运行时错误。
 * @author Lu dexiang (基于原有结构修改)
 * @date YYYY-MM-DD
 */

// 缓存编译时错误 (用于 update 命令)
mapping update_msg = ([]);

// 缓存运行时错误及其计数
mapping runtime_error_cache = ([]);

/**
 * @brief 设置指定文件的编译时错误信息
 * @details 由 master.c 的 log_error 调用，记录最新的编译错误信息。
 *          供 update 命令查询。
 * @param string file 发生编译错误的文件路径。
 * @param string err_msg 错误信息。
 */
public void set_err(string file, string err_msg)
{
    // 如果文件路径无效，则直接返回
    if (!stringp(file) || file == "") return;
    
    // 确保该文件的条目是映射
    if (!mapp(update_msg[file])) 
    {
        update_msg[file] = ([]);
    }
    update_msg[file]["time"] = time();
    update_msg[file]["err"] = err_msg;
}

/**
 * @brief 查询指定文件的最新编译时错误信息
 * @details 主要供 update 命令调用，显示上次编译失败的原因。
 * @param string file 要查询的文件路径。
 * @return string 最新的编译错误信息，如果无记录则返回 "未知错误"。
 */
public string query_err(string file)
{
    if (!stringp(file) || !mapp(update_msg[file]))
        return "未知错误";

    return update_msg[file]["err"];
}

/**
 * @brief 查询所有记录的编译时错误信息
 * @details 返回包含所有文件及其最新编译错误的映射。
 * @return mapping 错误信息映射，键为文件路径，值为包含时间和错误信息的映射。
 */
public mapping query_all_err()
{
    return update_msg;
}

/**
 * @brief 查询运行时错误缓存
 * @details 返回包含所有运行时错误及其发生次数的映射。
 * @return mapping 运行时错误缓存映射，键为 "错误信息|文件路径|行号"，值为发生次数。
 */
public mapping query_runtime_error_cache()
{
    return runtime_error_cache;
}

/**
 * @brief 处理运行时错误的核心逻辑
 * @details 由 master.c 的 error_handler 调用。负责缓存、计数、日志记录和通知。
 * @param mapping error 驱动程序传递的错误信息映射表。
 * @param int caught 标记错误是否被 catch 语句捕获。
 * @return string 详细的错误追踪信息 (首次) 或重复错误标识。
 */
public string handle_runtime_error(mapping error, int caught)
{
    object who, master_ob;
    string error_key;
    int current_count;
    string detailed_trace;
    string brief_msg; // For channel msg

    // 验证 error 映射的有效性
    if (!mapp(error) || !stringp(error["error"]) || !stringp(error["program"]) || !intp(error["line"])) {
        log_file("lints_error", sprintf("Invalid error mapping received at %s\n%O\n", ctime(time()), error));
        return "错误：接收到无效的错误信息映射表。";
    }

    // 生成错误唯一标识符
    error_key = sprintf("%s|%s|%d", error["error"], error["program"], error["line"]);

    // 增加错误计数
    runtime_error_cache[error_key]++;
    current_count = runtime_error_cache[error_key];

    // 仅在第一次遇到此错误时记录完整信息
    if (current_count == 1)
    {
        // 获取详细的错误追踪信息 (调用 master 的工具函数)
        master_ob = find_object(MASTER_OB);
        if (!master_ob) {
             log_file("lints_error", sprintf("Master object not found at %s\n", ctime(time())));
             return "错误：无法找到 Master 对象来格式化追踪信息。\n";
        }
        detailed_trace = master_ob->standard_trace(error, caught, current_count);

        // 记录错误信息到玩家身上
        if (who = this_player(1))
        {
            who->set_temp("runtime_error", error); // Use a different temp var name?
            if (wizardp(who))
            {
                tell_object(who, replace_string(detailed_trace, "\"", "“"));
            }
            else
            {
                tell_object(who, HIY "这里发现了臭虫，请用 SOS 指令将详细情况报告给巫师。"NOR"\n");
            }
        }
        else if (who = this_player()) // Error in non-interactive context, but player exists
        {
             if(wizardp(who))
                tell_object(who, "(后台错误) " + replace_string(detailed_trace, "\"", "“"));
        }

        // 格式化简要错误信息用于频道
        brief_msg = sprintf("%s @ %s:%d", error["error"], error["program"], error["line"]);

        // 发送到debug频道
        message("channel:debug", WHT "【系统首次出错】" + brief_msg + NOR"\n", users());

        // 日志文件处理 (轮转备份)
        // 使用 efun:: 开头确保调用的是 efun 而不是可能被覆盖的 simul_efun
        if (efun::file_size(LOG_DIR + "debug.log") > 100000)
        {
            efun::rename(LOG_DIR + "debug.log", LOG_DIR + "debug.bak");
        }

        // 写入标准错误日志 (写入详细追踪)
        efun::write_file(LOG_DIR + "debug.log", detailed_trace);

        // 返回标准错误追踪信息
        return detailed_trace;
    }
    else
    {
        // 对于重复的错误，仅在 debug 频道提示错误重复发生及其次数
        message("channel:debug", GRN "【系统重复出错】" + error_key + " (已触发 " + current_count + " 次)" NOR"\n", users());

        // 返回一个简单的标识符，表示错误已被处理（缓存）
        return sprintf("Repeated Runtime Error: %s (Total Count: %d)", error_key, current_count);
    }
}

/**
 * @brief 清除所有已记录的错误信息
 * @details 该函数将重置编译时错误缓存和运行时错误缓存，
 *          通常用于在系统维护或调试会话开始时清理旧的错误记录。
 */
public void clear_all_errors()
{
    update_msg = ([]);
    runtime_error_cache = ([]);
}

/**
 * @brief 清除指定文件的编译时错误
 * @details 从缓存中移除特定文件的编译时错误记录。
 * @param string file 要清除错误记录的文件路径。
 */
public void clear_file_error(string file)
{
    if (stringp(file) && !undefinedp(update_msg[file]))
    {
        map_delete(update_msg, file);
    }
}

/**
 * @brief LINT_D 对象创建时的初始化函数
 */
void create()
{
    // 可以在这里添加 LINT_D 特有的初始化代码
    seteuid(getuid()); // 确保有合适的 euid
}



