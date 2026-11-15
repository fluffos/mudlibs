/**
 * @file ui_layout.c
 * @author Lu dexiang
 * @brief 后端UI布局协议相关的模拟外部函数
 */

/**
 * @brief 生成世界对象按钮的JSON数据
 * @param mapping data 按钮数据
 * @return string JSON格式的按钮数据
 */
varargs string world_object_button(mapping data)
{
    mapping info;

    info = ([]);
    info["code"] = "world_object_button";
    info["data"] = data;

    return json_encode(info) + "\n";
}

/**
 * @brief 添加一个世界对象按钮
 * @param string name 按钮名称
 * @param string cmd 按钮命令
 * @param string type 按钮类型(player, npc, object)
 * @param string other_info 其他信息
 * @return string JSON格式的按钮数据
 */
varargs string add_world_object_button(string name, string cmd, string type, string other_info)
{
    mapping info;
    mapping *data, single_info;
    info = ([]);
    info["code"] = "world_object_button";

    data = ({});

    single_info = ([]);
    single_info["name"] = name;
    single_info["cmd"] = cmd;
    single_info["other_info"] = "";
    single_info["type"] = "";
    if (other_info)
        single_info["other_info"] = other_info;

    if (type)
        single_info["type"] = type;

    data += ({ single_info });

    info["data"] = data;

    return json_encode(info) + "\n";
}

/**
 * @brief 删除一个世界对象按钮
 * @param string cmd 要删除的按钮命令
 * @return string JSON格式的删除命令
 */
string remove_world_object_button(string cmd)
{
    mapping info;

    info = ([]);
    info["code"] = "remove_world_object_button";
    info["cmd"] = cmd;

    return json_encode(info) + "\n";
}
