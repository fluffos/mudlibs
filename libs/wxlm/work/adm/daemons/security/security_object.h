/**
 * @file security_object.h
 * @brief 安全守护进程 - 对象安全验证模块
 * @details 负责对象euid设置和函数绑定的安全验证
 */

//=============================================================================
// 对象安全验证
//=============================================================================

/**
 * @brief 验证设置euid的权限
 * @param ob 要设置euid的对象
 * @param uid 要设置的euid值
 * @return int 是否允许设置,1允许,0禁止
 * @details
 * 1. 允许设置为0(清除euid)
 * 2. 允许设置为自己的uid
 * 3. ROOT用户可以设置任意euid
 * 4. 系统对象(/adm/和/system/下的对象)可以设置任意euid
 * 5. admin用户可以设置非admin的euid
 */
int valid_seteuid(object ob, string uid)
{
	if (uid == 0) return 1;
	if (uid == getuid(ob)) return 1;
	if (getuid(ob) == ROOT_UID) return 1;
	if (sscanf(file_name(ob), "/adm/%*s")) return 1;
	if (sscanf(file_name(ob), "/system/%*s")) return 1;
	if (wiz_status[uid] != "(admin)" &&
	    wiz_status[getuid(ob)] == "(admin)")
		return 1;
	return 0;
}

/**
 * @brief 验证函数绑定权限
 * @param binder 执行绑定的对象
 * @param old_owner 原函数所有者
 * @param new_owner 新函数所有者
 * @return int 是否允许绑定,1允许,0禁止
 * @details
 * 1. ROOT用户可以绑定任何函数
 * 2. 如果绑定者没有发生变化则允许
 * 3. 允许绑定到玩家对象
 */
int valid_bind(object binder, object old_owner, object new_owner)
{
	// ROOT可以绑定任何函数
	if (geteuid(binder) == ROOT_UID) return 1;

	// 如果绑定者没有发生变化
	if (binder == new_owner) return 1;

	// 允许绑定到玩家对象
	if (playerp(new_owner))
		return 1;

	// 不同意绑定
	return 0;
}
