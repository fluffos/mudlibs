/**
 * @file security_rules.h
 * @brief 安全守护进程 - 安全规则管理模块
 * @details 负责查询、设置和合并安全规则
 */

//=============================================================================
// 安全规则管理
//=============================================================================

/**
 * @brief 查询安全配置信息
 * @param para 查询参数,可选值包括:
 *             trusted_read: 信任读取规则
 *             exclude_read: 排除读取规则
 *             trusted_write: 信任写入规则
 *             exclude_write: 排除写入规则
 *             extend_trusted_read: 扩展信任读取规则
 *             extend_exclude_read: 扩展排除读取规则
 *             extend_trusted_write: 扩展信任写入规则
 *             extend_exclude_write: 扩展排除写入规则
 *             default_trusted_write: 默认信任写入规则
 *             default_exclude_write: 默认排除写入规则
 *             default_trusted_read: 默认信任读取规则
 * @return mapping 对应的安全规则映射,如果没有权限则返回0
 * @details 只有root权限的对象才能查询安全配置信息
 */
mapping query_security(string para)
{
	if (! is_root(previous_object()))
		return 0;

	switch(para)
	{
	case "trusted_read":
		return trusted_read;

	case "exclude_read":
		return exclude_read;

	case "trusted_write":
		return trusted_write;

	case "exclude_write":
		return exclude_write;

	case "extend_trusted_read":
		return extend_trusted_read;

	case "extend_exclude_read":
		return extend_exclude_read;

	case "extend_trusted_write":
		return extend_trusted_write;

	case "extend_exclude_write":
		return extend_exclude_write;

	case "default_trusted_write":
		return ([
			"/": 		({ "(admin)" }),
			"/d":		({ "(arch)" }),
			"/clone":       ({ "(arch)" }),
			"/kungfu":      ({ "(arch)", "(player)" }),
			]);

	case "default_exclude_write":
		return ([
			"/adm":		({ "(arch)" }),
			"/feature":     ({ "(arch)" }),
			"/clone/user":  ({ "(arch)", "(wizard)" }),
			"/shadow":      ({ "(arch)" }),
			"/binaries":    ({ "(arch)" }),
			"/temp":	({ "(arch)" }),
			"/data":	({ "(arch)" }),
			"/version":     ({ "(arch)" }),
			]);

	case "default_trusted_read":
		return ([
			"/": 		({ "(admin)", "(arch)", "(wizard)" }),
			"/system":	({ "(arch)", "(wizard)" }),
			]);

	case "default_exclude_read":
		return ([
			"/adm":		({ "(player)" }),
			"/feature":     ({ "(player)" }),
			"/shadow":      ({ "(player)" }),
			"/binaries":    ({ "(player)" }),
			"/temp":	({ "(player)" }),
			"/data":	({ "(player)" }),
			"/version":     ({ "(player)" }),
			]);
	}
	return 0;
}

/**
 * @brief 设置安全规则
 * @param para 规则类型,可选值包括:
 *             extend_trusted_read: 扩展信任读取规则
 *             extend_exclude_read: 扩展排除读取规则
 *             extend_trusted_write: 扩展信任写入规则
 *             extend_exclude_write: 扩展排除写入规则
 * @param ruler 新的规则映射
 * @return int 设置是否成功,1成功,0失败
 * @details 只有root权限的对象才能设置安全规则
 */
int set_security(string para, mapping ruler)
{
	if (! is_root(previous_object()))
		return 0;

	switch(para)
	{
	case "extend_trusted_read":
		extend_trusted_read = ruler;
		break;

	case "extend_exclude_read":
		extend_exclude_read = ruler;
		break;

	case "extend_trusted_write":
		extend_trusted_write = ruler;
		break;

	case "extend_exclude_write":
		extend_exclude_write = ruler;
		break;

	default:
		return 0;
	}

	return 1;
}

/**
 * @brief 合并安全规则
 * @param def 默认规则映射
 * @param extend 扩展规则映射
 * @return mapping 合并后的规则映射
 * @details
 * 将扩展规则合并到默认规则中,如果某个路径在两个规则中都存在,
 * 则合并其权限列表
 */
mapping combine_rules(mapping def, mapping extend)
{
	string *ks;
	int i;

	if (! extend) return def;
	ks = keys(extend);
	for (i = 0; i < sizeof(ks); i++)
	{
		if (! arrayp(def[ks[i]]))
			def[ks[i]] = extend[ks[i]];
		else
			def[ks[i]] += extend[ks[i]];
	}
	return def;
}

/**
 * @brief 重置安全规则
 * @details
 * 1. 合并默认读取规则和扩展读取规则
 * 2. 合并默认写入规则和扩展写入规则
 * 3. 合并默认排除规则和扩展排除规则
 * 注:只有root权限的对象才能重置安全规则
 */
void reset_security()
{
	if (! is_root(previous_object()))
		return 0;

	trusted_read  = combine_rules(query_security("default_trusted_read"),  extend_trusted_read);
	exclude_read  = combine_rules(query_security("default_exclude_read"),  extend_exclude_read);
	trusted_write = combine_rules(query_security("default_trusted_write"), extend_trusted_write);
	exclude_write = combine_rules(query_security("default_exclude_write"), extend_exclude_write);
}
