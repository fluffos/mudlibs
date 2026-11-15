// 控制层基本类

// 预定义宏
#define RequestType(f_name,http_type) string f_name = http_type;

mapping function_dict;

mapping update_function_dict();
mapping get_function_dict();
mapping get_function_info(string function_name);
string *get_all_function_names();
void reset_function_dict();
int is_valid_http_type(string http_type);
string get_function_request_type(string function_name);

/**
 * @brief 更新函数字典
 * @return mapping 返回当前对象的函数字典
 * @details 该函数重新扫描当前对象可调用函数，并缓存函数参数数量、返回类型和参数列表信息。
 */
mapping update_function_dict()
{
    mixed function_info_list;
    mixed *single_function_info;
    mapping data;
    string function_name;
    string function_return_type;
    string *function_parameter_list;
    int function_parameter_count;
    mapping function_data;

    function_info_list = functions(this_object(), 1);
    data = ([]);

    foreach (single_function_info in function_info_list)
    {
        function_name = single_function_info[0];
        function_parameter_count = single_function_info[1];
        function_return_type = single_function_info[2];
        function_parameter_list = single_function_info[2..];
        function_data = ([]);

        function_data["parameter_count"] = function_parameter_count;
        function_data["return_type"] = function_return_type;
        function_data["parameter_list"] = function_parameter_list;
        data[function_name] = function_data;
    }

    function_dict = data;
    return data;
}

/**
 * @brief 获取函数字典
 * @return mapping 返回当前缓存的函数字典
 * @details 当缓存为空时会自动重新扫描当前对象函数信息，避免重复构建。
 */
mapping get_function_dict()
{
    if (!function_dict)
    {
        update_function_dict();
    }

    return function_dict;
}

/**
 * @brief 获取指定函数信息
 * @param string function_name 目标函数名称
 * @return mapping 返回对应函数信息，不存在时返回0
 * @details 该函数直接从已缓存的函数字典中读取目标函数的元数据。
 */
mapping get_function_info(string function_name)
{
    return get_function_dict()[function_name];
}

/**
 * @brief 获取全部函数名
 * @return string * 返回当前对象所有已缓存的函数名列表
 * @details 该函数用于向外暴露统一的函数名访问入口。
 */
string *get_all_function_names()
{
    return keys(get_function_dict());
}

/**
 * @brief 重置函数字典缓存
 * @return void 无返回值
 * @details 该函数清空当前对象的函数字典缓存，后续查询时会重新构建。
 */
void reset_function_dict()
{
    function_dict = 0;
}

/**
 * @brief 检查HTTP方法是否合法
 * @param string http_type 待校验的HTTP方法
 * @return int 合法返回1，不合法返回0
 * @details 该函数使用固定白名单校验常见HTTP请求方法，并统一按大写比较。
 */
int is_valid_http_type(string http_type)
{
    string *valid_types;

    valid_types = ({"GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS"});
    return member_array(upper_case(http_type), valid_types) != -1;
}

/**
 * @brief 获取函数绑定的请求方法
 * @param string function_name 目标函数名称
 * @return string 存在时返回请求方法，不存在时返回0
 * @details 该函数通过变量表检查控制器中是否声明了同名请求方法标记。
 */
string get_function_request_type(string function_name)
{
    string *my_variables;

    my_variables = variables(this_object());
    if (member_array(function_name, my_variables) == -1)
    {
        return 0;
    }

    return fetch_variable(function_name);
}

