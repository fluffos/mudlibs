/**
 * @file security_init.h
 * @brief 安全守护进程 - 初始化与数据持久化模块
 * @details 负责守护进程的创建、数据加载和保存
 */

//=============================================================================
// 私有辅助函数
//=============================================================================

/**
 * @brief 计算站点特权校验和(私有辅助函数)
 * @param mapping privilege 站点特权映射
 * @return string 计算的校验和
 */
private string calculate_privilege_checksum(mapping privilege)
{
	string item, val, sum;
	int i;

	sum = SEC_SEED;
	foreach (item in keys(privilege))
	{
		if (! stringp(item) || ! stringp(val = privilege[item]))
		{
			map_delete(privilege, item);
			continue;
		}

		for (i = 0; i < strlen(item) && i < CHECKSUM_LENGTH; i++)
			sum[i] = ((sum[i] - 48 + item[i]) & 0x7F) + 48;

		for (i = 0; i < strlen(val) && i < CHECKSUM_LENGTH; i++)
			sum[i] = ((sum[i] - 48 + val[i]) & 0x7F) + 48;
	}

	return sum;
}

//=============================================================================
// 初始化与数据持久化
//=============================================================================

/**
 * @brief 创建安全守护进程
 * @details 初始化进程并加载保存的数据
 */
void create()
{
	seteuid(getuid());
	restore();
}

/**
 * @brief 恢复安全守护进程数据
 * @return int 恢复是否成功
 * @details
 * 1. 验证站点特权信息的合法性
 * 2. 重置安全信息
 * 3. 恢复巫师列表
 * 4. 确保授权信息存在
 */
int restore()
{
	string item, val;
	string sum, sec;
	string *wizlist, wiz_name, wiz_level;
	int res;
	int i;

	res = ::restore();

	// check valid of site privilege
	while (1)
	{
		if (! res)
			break;

		if (! mapp(site_privilege) || sizeof(site_privilege) > MAX_SITE_PRIVILEGE_SIZE ||
		    ! stringp(sec = site_privilege[INTERMUD_MUD_NAME]))
		{
			// illegal data, empty privilege information
			site_privilege = 0;
			break;
		}

		map_delete(site_privilege, INTERMUD_MUD_NAME);

		sum = SEC_SEED;
		foreach (item in keys(site_privilege))
		{
			if (! stringp(item) ||
			    ! stringp(val = site_privilege[item]))
			{
				map_delete(site_privilege, item);
				continue;
			}

			for (i = 0; i < strlen(item) && i < CHECKSUM_LENGTH; i++)
				sum[i] = ((sum[i] - 48 + item[i]) & 0x7F) + 48;

			for (i = 0; i < strlen(val) && i < CHECKSUM_LENGTH; i++)
				sum[i] = ((sum[i] - 48 + val[i]) & 0x7F) + 48;
		}

		if (crypt(sum, sec) != sec)
		{
			log_file("nosave/security", "site_privilege information encrypted.\n");
			site_privilege = 0;
			break;
		}

		break;
	}

	// assure site_privilege
	if (! mapp(site_privilege))
		site_privilege = ([ ]);

	// reset the security information
	reset_security();

	// restore wizlist
	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for (i = 0; i < sizeof(wizlist); i++)
	{
		if (wizlist[i][0]=='#' ||
		    sscanf(wizlist[i], "%s %s", wiz_name, wiz_level) != 2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}

	// assure grant information
	if (! mapp(grant)) grant = ([ ]);

	return res;
}

/**
 * @brief 保存安全守护进程数据
 * @return int 保存是否成功
 * @details
 * 1. 验证并清理站点特权信息
 * 2. 重新计算安全校验和
 * 3. 加密并保存数据
 */
int save()
{
	string item;
	string val;
	string sum;
	int i;

	if (! mapp(site_privilege))
		site_privilege = ([ ]);

	map_delete(site_privilege, INTERMUD_MUD_NAME);

	sum = SEC_SEED;
	foreach (item in keys(site_privilege))
	{
		if (! stringp(item) ||
		    ! stringp(val = site_privilege[item]))
		{
			map_delete(site_privilege, item);
			continue;
		}

		for (i = 0; i < strlen(item) && i < CHECKSUM_LENGTH; i++)
			sum[i] = ((sum[i] - 48 + item[i]) & 0x7F) + 48;

		for (i = 0; i < strlen(val) && i < CHECKSUM_LENGTH; i++)
			sum[i] = ((sum[i] - 48 + val[i]) & 0x7F) + 48;
	}

	site_privilege[INTERMUD_MUD_NAME] = crypt(sum, 0);

	return ::save();
}
