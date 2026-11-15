/**
 * @file friend_master.c
 * @author Lu dexiang
 * @brief 好友系统管理类
 * @version 1.0
 * @date 2024-01-10
 */



inherit F_DBASE;
inherit F_SAVE;

// 存储所有玩家的好友关系
private mapping friend_relations = ([]);
// 存储所有待处理的好友申请
private mapping friend_requests = ([]);
// 存储离线消息
private mapping offline_messages = ([]);
// 存储好友昵称
private mapping friend_nicknames = ([]);

void create()
{
    seteuid(getuid());
    restore();
}

string query_save_file()
{
    return DATA_DIR + "friend/friend_data";
}

/**
 * @brief 获取指定玩家的好友列表
 * @param string user_id 玩家ID
 * @return string* 好友ID数组
 */
string *query_friends(string user_id)
{
    if (nullp(friend_relations[user_id]))
        return ({});
    return friend_relations[user_id];
}

/**
 * @brief 发送好友申请
 * @param string from_id 申请人ID
 * @param string to_id 被申请人ID
 * @return int 0:失败 1:成功
 */
int request_friend(string from_id, string to_id)
{
    object target;
    
    if (!from_id || !to_id)
        return 0;
        
    if (from_id == to_id)
        return 0;
        
    if (nullp(friend_requests[to_id]))
        friend_requests[to_id] = ({});
        
    // 检查是否已经发送过申请
    if (member_array(from_id, friend_requests[to_id]) != -1)
    {
        tell_object(UPDATE_D->global_find_player(from_id), HIR"你已经发送过好友申请给 " + UPDATE_D->global_find_player(to_id)->query("name") + "了。\n" + NOR);
        return 0;
    }
        
    friend_requests[to_id] += ({from_id});
    
    // 如果对方在线，发送通知
    if (target = find_player(to_id))
    {
        tell_object(target, HIR + UPDATE_D->global_find_player(from_id)->query("name") + "申请添加你为好友。\n" + NOR);
    }
    
    save();
    return 1;
}

/**
 * @brief 获取待处理的好友申请列表
 * @param string user_id 玩家ID
 * @return string* 申请人ID数组
 */
string *query_requests(string user_id)
{
    if (nullp(friend_requests[user_id]))
        return ({});
    return friend_requests[user_id];
}

/**
 * @brief 发送好友消息
 * @param string from_id 发送者ID
 * @param string to_id 接收者ID
 * @param string message 消息内容
 * @return int 0:失败 1:成功
 */
int send_message(string from_id, string to_id, string message)
{
    object target;
    mapping msg;
    
    if (!from_id || !to_id || !message)
        return 0;
        
    // 检查是否为好友关系
    if (nullp(friend_relations[from_id]) || member_array(to_id, friend_relations[from_id]) == -1)
        return 0;
        
    // 如果对方在线
    if (target = find_player(to_id))
    {
        mapping notify_data = ([
            "code" : "online_friend_message",
            "from" : from_id,
            "message" : message,
            "time" : time()
        ]);
        
        // 发送JSON格式消息通知
        tell_object(target, json_encode(notify_data) + "\n");
        return 1;
    }
    
    // 对方离线，存储离线消息
    if (nullp(offline_messages[to_id]))
        offline_messages[to_id] = ({});
        
    msg = ([
        "from" : from_id,
        "message" : message,
        "time" : time()
    ]);
    
    offline_messages[to_id] += ({msg});
    save();
    return 1;
}

/**
 * @brief 获取并清除玩家的离线消息
 * @param string user_id 玩家ID
 * @return mapping* 消息数组
 */
mapping *get_offline_messages(string user_id)
{
    mapping *msgs;
    
    if (nullp(offline_messages[user_id]))
        return ({});
        
    msgs = offline_messages[user_id];
    map_delete(offline_messages, user_id);
    save();
    
    return msgs;
}

/**
 * @brief 获取玩家离线消息并转换为JSON格式
 * @param string user_id 玩家ID
 * @return string JSON格式的离线消息
 */
string get_offline_messages_json(string user_id)
{
    mapping notify_data = ([]);
    mapping *msgs = get_offline_messages(user_id);
    
    if (!sizeof(msgs))
    {

        return 0;

        // notify_data = ([
        //     "code" : "offline_friend_messages",
        //     "count" : 0,
        //     "messages" : ({})
        // ]);
    }
    else
    {
        notify_data = ([
            "code" : "offline_friend_messages",
            "count" : sizeof(msgs),
            "messages" : msgs
        ]);
    }
    
    return json_encode(notify_data);
}

/**
 * @brief 设置好友昵称
 * @param string user_id 用户ID
 * @param string friend_id 好友ID
 * @param string nickname 昵称
 * @return int 0:失败 1:成功
 */
int set_friend_nickname(string user_id, string friend_id, string nickname)
{
    if (nullp(friend_relations[user_id]) || member_array(friend_id, friend_relations[user_id]) == -1)
        return 0;
        
    if (nullp(friend_nicknames[user_id]))
        friend_nicknames[user_id] = ([]);
        
    friend_nicknames[user_id][friend_id] = nickname;
    save();
    return 1;
}

/**
 * @brief 获取好友昵称
 * @param string user_id 用户ID
 * @param string friend_id 好友ID
 * @return string 昵称，如果未设置则返回好友ID
 */
string query_friend_nickname(string user_id, string friend_id)
{
    if (nullp(friend_nicknames[user_id]) || nullp(friend_nicknames[user_id][friend_id]))
        return friend_id;
        
    return friend_nicknames[user_id][friend_id];
}

/**
 * @brief 接受好友申请
 * @param string user_id 接受者ID
 * @param string friend_id 申请者ID
 * @return int 0:失败 1:成功
 */
int accept_friend_request(string user_id, string friend_id)
{
    object user_ob, friend_ob;
    string user_name, friend_name;
    
    if (nullp(friend_requests[user_id]) || member_array(friend_id, friend_requests[user_id]) == -1)
        return 0;
        
    // 建立双向好友关系
    if (nullp(friend_relations[user_id]))
        friend_relations[user_id] = ({});
    if (nullp(friend_relations[friend_id]))
        friend_relations[friend_id] = ({});
        
    friend_relations[user_id] += ({friend_id});
    friend_relations[friend_id] += ({user_id});
    
    // 从申请列表中移除
    friend_requests[user_id] -= ({friend_id});
    
    // 设置双方默认昵称
    user_ob = UPDATE_D->global_find_player(user_id);
    friend_ob = UPDATE_D->global_find_player(friend_id);
    
    // 设置申请者对接受者的默认昵称
    if (user_ob)
        user_name = user_ob->query("name");
    else
        user_name = user_id;
    
    // 设置接受者对申请者的默认昵称
    if (friend_ob)
        friend_name = friend_ob->query("name");
    else
        friend_name = friend_id;
    
    // 如果没有设置过昵称，则设置默认昵称
    if (nullp(friend_nicknames[friend_id]))
        friend_nicknames[friend_id] = ([]);
    if (nullp(friend_nicknames[friend_id][user_id]))
        friend_nicknames[friend_id][user_id] = user_name;
        
    if (nullp(friend_nicknames[user_id]))
        friend_nicknames[user_id] = ([]);
    if (nullp(friend_nicknames[user_id][friend_id]))
        friend_nicknames[user_id][friend_id] = friend_name;
    
    // 如果对方在线，发送通知
    if (friend_ob)
    {
        mapping notify_data = ([
            "code" : "friend_request_accepted",
            "from" : user_id,
            "time" : time()
        ]);
        tell_object(friend_ob, json_encode(notify_data) + "\n");

        // 通知双方
        tell_object(UPDATE_D->global_find_player(user_id), HIG"你已经成功添加 " + UPDATE_D->global_find_player(friend_id)->query("name") + "为好友。\n" + NOR);
        tell_object(UPDATE_D->global_find_player(friend_id), HIG"你已经成功添加 " + UPDATE_D->global_find_player(user_id)->query("name") + "为好友。\n" + NOR);
    }
    
    save();
    return 1;
}

/**
 * @brief 拒绝好友申请
 * @param string user_id 拒绝者ID
 * @param string friend_id 申请者ID
 * @return int 0:失败 1:成功
 */
int reject_friend_request(string user_id, string friend_id)
{
    object target;
    
    if (nullp(friend_requests[user_id]) || member_array(friend_id, friend_requests[user_id]) == -1)
        return 0;
        
    // 从申请列表中移除
    friend_requests[user_id] -= ({friend_id});
    
    // 如果对方在线，发送通知
    target = find_player(friend_id);
    if (target)
    {
        mapping notify_data = ([
            "code" : "friend_request_rejected",
            "from" : user_id,
            "time" : time()
        ]);
        tell_object(target, json_encode(notify_data) + "\n");
    }
    
    save();
    return 1;
}

/**
 * @brief 判断两个用户是否为好友关系
 * @param string user_id 用户ID
 * @param string friend_id 好友ID
 * @return int 1:是好友 0:不是好友
 */
int is_friend(string user_id, string friend_id)
{
    // 参数检查
    if (!user_id || !friend_id)
        return 0;
        
    // 检查好友关系
    if (nullp(friend_relations[user_id]))
        return 0;
        
    return (member_array(friend_id, friend_relations[user_id]) != -1);
}
