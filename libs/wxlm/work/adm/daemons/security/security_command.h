/**
 * @file security_command.h
 * @brief 安全守护进程 - 命令授权管理模块
 * @details 负责命令权限验证、授权和撤销
 */

//=============================================================================
// 命令授权管理
//=============================================================================

/**
 * @brief 验证命令授权
 * @param ob 要执行命令的对象
 * @param min_level 命令要求的最低权限等级
 * @return int 是否允许执行,1允许,0禁止
 * @details
 * 1. 验证调用对象的合法性
 * 2. 检查是否为ROOT对象调用
 * 3. 检查权限等级是否满足要求
 * 4. 检查是否有显式授权
 */
int valid_grant(object ob, string min_level)
{
	object cmd_ob;
	string cmd;
	string *gr;
	object call_ob;

	if (! objectp(ob))
		return notify_fail("没有对象呼叫这个命令。\n");

	if (! objectp(cmd_ob = previous_object()))
		return notify_fail("必须是命令调用授权函数。\n");

	cmd = base_name(cmd_ob);
	if (sscanf(cmd, "/cmds/%*s/%s", cmd) != 2)
		return notify_fail("必须是命令调用授权函数。\n");

	// 检查调用对象的合法性
	call_ob = previous_object(1);
	if ((! call_ob || call_ob != this_player(1) && geteuid(call_ob) != ROOT_UID) && base_name(call_ob) != "/external_system_package/http/controller/player_command")
	{
		log_file("nosave/security",
			 sprintf("%s want to call cmd:%s with %s\n",
				 (call_ob ? geteuid(call_ob) : "null"),
				 cmd,
				 (this_player(1) ? geteuid(this_player(1)) : "null")));
		return 0;
	}

	// ROOT对象调用命令
	if (geteuid(ob) == ROOT_UID && call_ob == ob)
		return 1;

	if (ob != this_player(1))
		return notify_fail("不是本人呼叫这个命令。\n");

	// 管理员可以执行任何命令
	if (is_root(ob))
		return 1;

	// 权限等级满足要求
	if (wiz_level(ob) >= wiz_level(min_level))
		return 1;

	// 检查是否有显式授权
	if (arrayp(gr = grant[geteuid(ob)]) && member_array(cmd, gr) != -1)
		return 1;

	return 0;
}

/**
 * @brief 授权命令
 * @param user 被授权的用户ID
 * @param cmd 被授权的命令
 * @return int 是否授权成功,1成功,0失败
 * @details 只有ROOT权限才能进行授权操作
 */
int grant(string user, string cmd)
{
	string *gr;

	if (! previous_object() || ! is_root(previous_object()))
		return 0;

	if (! arrayp(gr = grant[user]))
		gr = ({ cmd });
	else
	if (member_array(cmd, gr) == -1)
		gr += ({ cmd });
	else
		return 0;

	grant[user] = gr;
	return 1;
}

/**
 * @brief 收回命令授权
 * @param user 用户ID
 * @param cmd 要收回的命令,如果为"*"则收回所有授权
 * @return int 是否成功收回,1成功,0失败
 * @details 只有ROOT权限才能收回授权
 */
int remove_grant(string user, string cmd)
{
	string *gr;

	if (! previous_object() || ! is_root(previous_object()))
		return 0;

	if (cmd == "*")
	{
		if (undefinedp(grant[user]))
			return 0;

		map_delete(grant, user);
		return 1;
	}

	if (! arrayp(gr = grant[user]) ||
	    member_array(cmd, gr) == -1)
		return 1;

	gr -= ({ cmd });
	if (sizeof(gr) < 1)
		map_delete(grant, user);
	else
		grant[user] = gr;

	return 1;
}

/**
 * @brief 查询用户的授权命令
 * @param user 用户ID
 * @return string* 授权命令列表
 * @details 只有ROOT权限才能查询授权信息
 */
string *query_grant(string user)
{
	if (! previous_object() || ! is_root(previous_object()))
		return 0;

	return grant[user];
}

/**
 * @brief 查询所有被授权的用户
 * @return string* 被授权用户列表
 * @details 只有ROOT权限才能查询授权用户
 */
string *query_grant_users()
{
	if (! previous_object() || ! is_root(previous_object()))
		return 0;

	return keys(grant);
}
