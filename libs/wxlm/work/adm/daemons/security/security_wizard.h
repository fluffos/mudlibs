/**
 * @file security_wizard.h
 * @brief 安全守护进程 - 巫师等级管理模块
 * @details 负责巫师状态、等级的查询和设置
 */

//=============================================================================
// 权限等级管理
//=============================================================================

/**
 * @brief 获取巫师等级列表
 * @return string* 巫师等级列表数组
 */
string *query_wiz_levels() { return wiz_levels; }

/**
 * @brief 获取巫师列表
 * @return string* 所有巫师的名字数组
 * @details 与 get_wizlist() 功能相同,为兼容性保留
 */
string *query_wizlist() { return keys(wiz_status); }

/**
 * @brief 获取对象的状态
 * @param ob 要查询的对象或用户ID
 * @return string 对象的状态字符串
 * @details
 * 如果参数是对象,则获取其euid或uid
 * 如果参数是字符串,则直接作为用户ID使用
 * 返回该ID在系统中的状态等级
 */
string get_status(mixed ob)
{
	string euid;

	if (objectp(ob))
	{
		euid = geteuid(ob);
		if (! euid) euid = getuid(ob);
	}
	else if (stringp(ob)) euid = ob;

	if (! undefinedp(wiz_status[euid]))
		return wiz_status[euid];
	else if (member_array(euid, wiz_levels) != -1)
		return euid;
	else
		return "(player)";
}

/**
 * @brief 获取巫师等级数值
 * @param ob 要查询的对象或用户ID
 * @return int 巫师等级的数值索引
 * @details 返回对象在巫师等级列表中的位置索引,数值越大权限越高
 */
int get_wiz_level(mixed ob)
{
	return member_array(get_status(ob), wiz_levels);
}

/**
 * @brief 设置用户状态
 * @param ob 要设置的对象或用户ID
 * @param status 要设置的状态
 * @return int 设置是否成功,1成功,0失败
 * @details
 * 1. 只有ROOT权限才能调用此函数
 * 2. 如果设置为(player)则删除其巫师状态
 * 3. 更新WIZLIST文件
 * 4. 记录升级日志
 */
int set_status(mixed ob, string status)
{
	string uid, *wiz, wizlist;
	int i;

	if (geteuid(previous_object()) != ROOT_UID) return 0;

	if (objectp(ob))	uid = getuid(ob);
	else if (stringp(ob))   uid = ob;
	else return 0;

	if (wizhood(ob) == status)
		return 1;
	if (status == "(player)")
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wiz = keys(wiz_status);
	for (wizlist = "", i = 0; i < sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file("nosave/promotion", log_time() + " " + capitalize(uid) +
		 " become a " + status + " by " +
		 (this_player() ? geteuid(this_player()) : "SYSTEM") + "\n");
	return 1;
}

/**
 * @brief 获取巫师列表
 * @return string* 所有巫师的名字数组
 * @details 推荐使用此函数,query_wizlist() 为兼容性保留
 */
string *get_wizlist() { return keys(wiz_status); }
