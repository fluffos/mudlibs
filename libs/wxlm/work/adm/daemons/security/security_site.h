/**
 * @file security_site.h
 * @brief 安全守护进程 - 站点特权管理模块
 * @details 负责站点特权信息的设置和查询
 */

//=============================================================================
// 站点特权管理
//=============================================================================

/**
 * @brief 设置站点特权信息
 * @param item 站点名称
 * @param desc 特权描述
 * @return int 是否设置成功,1成功,0失败
 * @details 只有ROOT权限才能设置站点特权
 */
varargs int set_site_privilege(string item, string desc)
{
	if (! previous_object() || ! is_root(previous_object()))
		return 0;

	if (! stringp(item))
		return 0;

	if (! stringp(desc))
		map_delete(site_privilege, item);
	else
		site_privilege[item] = desc;

	return 1;
}

/**
 * @brief 查询站点特权信息
 * @param item 站点名称,如果为空则返回所有特权信息
 * @return mixed 特权信息或特权映射
 * @details 只有ROOT权限才能查询所有特权信息
 */
varargs mixed query_site_privilege(string item)
{
	if (! stringp(item))
	{
		if (! previous_object() || ! is_root(previous_object()))
			return 0;

		return site_privilege;
	}

	return site_privilege[item];
}
