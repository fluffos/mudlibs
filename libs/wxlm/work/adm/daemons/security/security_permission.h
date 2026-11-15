/**
 * @file security_permission.h
 * @brief 安全守护进程 - 文件权限验证模块
 * @details 负责文件读写权限的核心验证逻辑
 */

//=============================================================================
// 私有辅助函数
//=============================================================================

/**
 * @brief 递归检查目录权限(私有辅助函数)
 * @param string file 文件路径
 * @param string euid 用户有效ID
 * @param string status 用户权限状态
 * @param mapping trusted 信任规则映射
 * @param mapping excluded 排除规则映射
 * @return int 是否允许访问,1允许,0禁止
 * @details 从文件所在目录向上递归检查到根目录,排除检查优先于信任检查
 */
private int check_directory_permission(string file, string euid, string status,
                                       mapping trusted, mapping excluded)
{
	string *path, dir;
	string *arre, *arrt;
	int i, valid;

	path = explode(file, "/");
	valid = 0;
	i = sizeof(path);

	while ((i--) >= 0)
	{
		dir = "/";
		if (i >= 0) dir += implode(path[0..i], "/");

		arre = excluded[dir];
		arrt = trusted[dir];

		// 排除检查优先
		if (arre && member_array(euid, arre) != -1)
		{
			valid = 0;
			break;
		}

		if (arrt && member_array(euid, arrt) != -1)
		{
			valid = 1;
			break;
		}

		if (arre && member_array(status, arre) != -1)
		{
			valid = 0;
			break;
		}

		if (arrt && member_array(status, arrt) != -1)
		{
			valid = 1;
			break;
		}
	}

	return valid;
}

/**
 * @brief 获取用户有效ID(私有辅助函数)
 * @param mixed user 用户对象或字符串
 * @return string 用户有效ID,如果无法获取则返回0
 */
private string get_user_euid(mixed user)
{
	string euid;

	if (! objectp(user))
	{
		if (stringp(user))
			euid = user;
		else
			error("SECURITY_D: Invalid argument type of user.\n");
	} else
		euid = geteuid(user);

	return euid;
}

//=============================================================================
// 文件权限验证(核心功能)
//=============================================================================

// valid_write - 由主对象调用,用于判断用户是否有权限写入特定文件
// 注意:
//     根据驱动程序源代码,user参数应该是一个对象类型。
// 但在发布的文档中它被定义为mixed类型。这里我们假定在正常情况下它是一个对象,
// 如果不是对象类型则抛出错误。                                    - Annihilator

/**
 * @brief 验证文件写入权限
 * @param file 要写入的文件路径
 * @param user 尝试写入的用户对象或ID
 * @param func 写入操作的函数名
 * @return int 是否允许写入,1允许,0禁止
 * @details
 * 1. 验证用户身份和权限
 * 2. 检查特殊情况(如日志写入、存档等)
 * 3. 递归检查目录权限
 * 4. 记录非法写入尝试
 */
int valid_write(string file, mixed user, string func)
{
	string euid, status;
	string user_info;

	// 构造用户信息字符串用于日志
	if (objectp(user))
		user_info = sprintf("对象:%O base_name:%s", user, base_name(user));
	else if (stringp(user))
		user_info = sprintf("字符串:%s", user);
	else
		user_info = sprintf("未知类型:%O", user);

	// 获取用户有效ID
	euid = get_user_euid(user);

	// 允许写入日志文件
	if (sscanf(file, LOG_DIR + "%*s") && func=="write_file") return 1;

	// 允许用户保存自己的存档
	if (func == "save_object")
	{
		// 系统对象和管理对象可以保存 (优先检查,避免euid为空时被拒绝)
		if (objectp(user))
		{
			if (sscanf(base_name(user), "/system/%*s"))
				return 1;

			if (sscanf(base_name(user), "/adm/%*s"))
				return 1;
		}
		else
		{
			// 【调试日志1】user不是对象
			log_file("files", sprintf("[权限拒绝-1] %s 函数:%s 文件:%s 用户信息:%s 原因:user不是对象,无法通过系统对象检查\n",
				log_time(), func, file, user_info));
		}

		// 玩家存档检查
		if ((stringp(user) ? sscanf(user, "/clone/%*s")
				   : sscanf(file_name(user), "/clone/%*s"))
		&&	sscanf(file, "/data/%*s")
		&&	(file == (string)user->query_save_file() +  __SAVE_EXTENSION__ ||
			 file == (string)user->query_save_file()) )
		{
			// 检查对象的文件与id在数据库中是否匹配
			if (euid && euid != getuid(user))
			{
				write(sprintf(HIR "【保护】你的用户标识(%s)和有效用"
					      "户标识(%s)不同,档案不正常,不能保存。"NOR"\n",
					      getuid(user), geteuid(user)));
				// 【调试日志2】uid与euid不匹配
				log_file("files", sprintf("[权限拒绝-2] %s 函数:%s 文件:%s 用户信息:%s euid:%s getuid:%s 原因:用户标识不匹配\n",
					log_time(), func, file, user_info, euid, getuid(user)));
				return 0;
			}

			if ((base_name(user) == USER_OB) &&
			    getuid(user) != user->query("id"))
			{
				write(sprintf(HIR "【保护】你的用户标识(%s)和数据中"
					      "的标识(%s)不同,档案不正常,不能保存。"NOR"\n",
					      getuid(user), user->query("id")));
				// 【调试日志3】玩家对象ID不匹配
				log_file("files", sprintf("[权限拒绝-3] %s 函数:%s 文件:%s 用户信息:%s getuid:%s query_id:%s 原因:玩家ID不匹配\n",
					log_time(), func, file, user_info, getuid(user), user->query("id")));
				return 0;
			}
			return 1;
		}
	}

	// 获取用户的euid和状态
	if (! euid)
	{
		// 【调试日志4】euid为空
		log_file("files", sprintf("[权限拒绝-4] %s 函数:%s 文件:%s 用户信息:%s 原因:euid为空或0\n",
			log_time(), func, file, user_info));
		return 0;
	}
	status = get_status(user);

	// ROOT和admin拥有所有写权限
	if (euid == ROOT_UID || status == "(admin)") return 1;

	// 临时巫师权限
	if (stringp(user)) user = find_player(user);
	if (objectp(user) && user->query_temp("wizhood"))
		return 1;

	// 允许用户写入自己的目录
	if (sscanf(file, "/u/" + euid + "/%*s"))
		return 1;

	// 递归检查目录权限
	if (check_directory_permission(file, euid, status, trusted_write, exclude_write))
		return 1;

	// 记录非法写入尝试
	if (! func) func = "null";
	if (member_array(func, ({ "ls", "dest" })) != -1)
	{
		// 【调试日志5】ls或dest命令被静默拒绝
		log_file("files", sprintf("[权限拒绝-5] %s 函数:%s 文件:%s 用户信息:%s euid:%s status:%s 原因:ls/dest命令静默拒绝\n",
			log_time(), func, file, user_info, euid, status));
		return 0;
	}

	// 【调试日志6】所有检查都未通过
	log_file("files", sprintf("[权限拒绝-6] %s 函数:%s 文件:%s 用户信息:%s euid:%s status:%s 原因:所有权限检查均未通过\n",
		log_time(), func, file, user_info, euid, status));
	return 0;
}

/**
 * @brief 验证文件读取权限
 * @param file 要读取的文件路径
 * @param user 尝试读取的用户对象或ID
 * @param func 读取操作的函数名
 * @return int 是否允许读取,1允许,0禁止
 * @details
 * 1. ROOT用户拥有所有读取权限
 * 2. 允许用户读取自己的存档
 * 3. 允许用户读取自己的目录
 * 4. 递归检查目录权限
 * 5. 记录非法读取尝试
 */
int valid_read(string file, mixed user, string func)
{
	string euid, status, *path;
	string *arrt;
	string dir;

	// 获取用户有效ID
	euid = get_user_euid(user);

	// ROOT拥有所有读权限
	if (euid == ROOT_UID) return 1;

	// 允许用户读取自己的存档
	if (func == "restore_object")
	{
		if (sscanf(base_name(user), "/clone/%*s") &&
		    sscanf(file, "/data/%*s") &&
		    (file == (string)user->query_save_file() +  __SAVE_EXTENSION__ ||
		     file == (string)user->query_save_file()))
			return 1;

		// 系统对象和管理对象可以读取
		if (sscanf(base_name(user), "/system/%*s"))
			return 1;

		if (sscanf(base_name(user), "/adm/%*s"))
			return 1;
	}

	// 允许查询文件大小
	if (func == "file_size") return 1;

	// 获取用户的euid和状态
	if (! euid) return 0;
	status = get_status(user);

	// admin拥有所有读权限
	if (status == "(admin)") return 1;

	// 临时巫师权限
	if (objectp(user) && user->query_temp("wizhood"))
		return 1;

	// 允许用户读取自己的目录
	if (sscanf(file, "/u/" + euid + "/%*s") ||
	    file == "/u/" + euid)
		return 1;

	// 禁止读取其他用户的日志
	if (sscanf(file, "/log/user/%*s/" + euid))
		return 0;

	// 递归检查目录权限
	if (sscanf(file, "%*s/"))
		path = explode(file, "/");

	if (check_directory_permission(file, euid, status, trusted_read, exclude_read))
		return 1;

	// 检查是否可以访问更深层目录(用于ls和cd命令)
	if ((func == "ls" || func == "cd") &&
	    file_size(file) == -2)
	{
		file = "/" + implode(path, "/") + "/";
		if (file == "/u") return 1;
		foreach (dir in keys(trusted_read))
		{
			if (! sscanf(dir, file + "%*s"))
				continue;

			if (! arrayp(arrt = trusted_read[dir]))
				continue;

			if (member_array(euid, arrt) != -1 ||
			    member_array(status, arrt) != -1)
				return 1;
		}
	}

	// 记录非法读取尝试
	if (! func) func = "null";
	if (member_array(func, ({ "ls", "clone" })) != -1)
		return 0;

	log_file("files", sprintf("%s  %s%s read attempt(%s) on %s failed.\n",
		 log_time(), euid, wizhood(user), func, file));
	return 0;
}
