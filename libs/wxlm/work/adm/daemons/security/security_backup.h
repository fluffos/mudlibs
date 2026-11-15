/**
 * @file security_backup.h
 * @brief 安全守护进程 - 文件备份功能模块
 * @details 负责文件备份和守护进程销毁控制
 */

//=============================================================================
// 文件备份功能
//=============================================================================

/**
 * @brief 备份文件
 * @param file 要备份的文件路径
 * @details
 * 1. 只有非ROOT和非admin用户修改的文件才需要备份
 * 2. 备份文件按年月日和序号命名
 * 3. 备份目录结构为/log/file/用户ID/年-月-日/序号-文件名
 */
void backup_file(string file)
{
	string euid;
	mixed lt;
	string* str;
	string bname;

	euid = geteuid(previous_object());
	if (euid == ROOT_UID || get_status(euid) == "(admin)")
		return;

	if (file_size(file) <= 0)
		return;

	lt = localtime(time());
	str = explode(file, "/");
	seq++;
	seq %= BACKUP_SEQ_MAX;
	bname = sprintf("/log/file/%s/%d-%d-%d/%d-%s",
			euid,
			lt[LT_YEAR], lt[LT_MON] + 1, lt[LT_MDAY],
			seq, str[sizeof(str) - 1]);
	assure_file(bname);
	cp(file, bname);
}

//=============================================================================
// 守护进程销毁控制
//=============================================================================

/**
 * @brief 销毁安全守护进程
 * @param euid 尝试销毁的用户ID
 * @details 只有ROOT用户或admin权限才能销毁安全守护进程
 */
varargs void remove(string euid)
{
	if (euid != ROOT_UID && get_status(euid) != "(admin)")
		error("Only root can destruct SECURITY daemon.\n");

	return;
}
