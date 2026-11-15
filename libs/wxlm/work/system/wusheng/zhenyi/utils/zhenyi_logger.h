/**
 * @brief 武圣真意系统日志模块
 * @author LPC开发者
 * @date 2024
 * @details 统一的日志记录系统，支持所有模块使用
 */

#ifndef __ZHENYI_LOGGER_H__
#define __ZHENYI_LOGGER_H__

/**
 * @brief 记录真意系统日志
 * @param string module_name 模块名称（synthesis/decomposition/bag等）
 * @param string function_name 函数名称
 * @param string log_type 日志类型（info/error/warning/success/critical）
 * @param string message 日志消息
 * @details 统一的真意系统日志记录函数，支持多模块
 */
void log_zhenyi_info(string module_name, string function_name, string log_type, string message)
{
    string log_message, timestamp, log_file;

    if (!stringp(module_name) || !stringp(function_name) || !stringp(log_type) || !stringp(message))
        return;

    timestamp = ctime(time());
    log_message = sprintf("[%s] [ZHENYI_%s] [%s] %s",
        timestamp, upper_case(module_name), function_name, message);

    // 根据日志类型选择日志文件
    switch (log_type)
    {
        case "error":
            log_file = sprintf("/log/zhenyi_%s_error.log", module_name);
            break;
        case "warning":
            log_file = sprintf("/log/zhenyi_%s_warning.log", module_name);
            break;
        case "success":
            log_file = sprintf("/log/zhenyi_%s_success.log", module_name);
            break;
        case "critical":
            log_file = sprintf("/log/zhenyi_%s_critical.log", module_name);
            // 严重错误同时写入总错误日志
            write_file("/log/zhenyi_critical.log", log_message + "\n");
            break;
        default:
            log_file = sprintf("/log/zhenyi_%s.log", module_name);
            break;
    }

    write_file(log_file, log_message + "\n");
}

/**
 * @brief 记录合成系统日志（兼容旧接口）
 * @param string function_name 函数名称
 * @param string log_type 日志类型
 * @param string message 日志消息
 * @details 保持向后兼容，调用新的通用日志函数
 */
void log_synthesis_info(string function_name, string log_type, string message)
{
    log_zhenyi_info("synthesis", function_name, log_type, message);
}

/**
 * @brief 记录分解系统日志
 * @param string function_name 函数名称
 * @param string log_type 日志类型
 * @param string message 日志消息
 * @details 分解系统专用日志接口
 */
void log_decomposition_info(string function_name, string log_type, string message)
{
    log_zhenyi_info("decomposition", function_name, log_type, message);
}

/**
 * @brief 记录背包系统日志
 * @param string function_name 函数名称
 * @param string log_type 日志类型
 * @param string message 日志消息
 * @details 背包系统专用日志接口
 */
void log_bag_info(string function_name, string log_type, string message)
{
    log_zhenyi_info("bag", function_name, log_type, message);
}

/**
 * @brief 记录装备系统日志
 * @param string function_name 函数名称
 * @param string log_type 日志类型
 * @param string message 日志消息
 * @details 装备系统专用日志接口
 */
void log_equipment_info(string function_name, string log_type, string message)
{
    log_zhenyi_info("equipment", function_name, log_type, message);
}

#endif /* __ZHENYI_LOGGER_H__ */
