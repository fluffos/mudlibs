/**
 * @file security_data.h
 * @brief 安全守护进程 - 数据结构定义模块
 * @details 定义所有数据结构、常量和全局变量
 */

//=============================================================================
// 常量定义
//=============================================================================

#define MAX_SITE_PRIVILEGE_SIZE 1024    // 站点特权映射最大条目数
#define CHECKSUM_LENGTH         32      // 校验和字符串长度
#define BACKUP_SEQ_MAX          10000   // 备份文件序号最大值
#define SEC_SEED                "12345678901234567890123456789012"  // 加密种子

//=============================================================================
// 数据结构定义
//=============================================================================

/**
 * @brief 获取守护进程数据存储文件路径
 * @return string 数据文件路径
 */
string query_save_file()
{
	return DATA_DIR "securityd";
}

/**
 * @brief 巫师等级状态映射
 * @details
 * 这是一个"有效"的访问状态映射,用于直接决定巫师的访问权限。
 * 它与登录对象中的"status"属性相对应,对于高于普通巫师的用户
 * (如贤者、大巫师和管理员)来说,确保status属性与此映射匹配非常重要。
 * 对于未在此映射中出现的用户名,系统会使用wizardp()和interactive()
 * 将其分为三组:(wizard)、(player)和(object)。
 * 注:使用括号是为了防止玩家通过将自己命名为"admin"来破解安全系统。
 */
private nosave mapping wiz_status = ([ ]);

/**
 * @brief 巫师等级列表
 * @details 定义了系统中所有可能的权限等级,从低到高排列
 */
private nosave string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});

private nosave int seq = 0;

/**
 * @brief 文件访问权限规则
 * @details
 * 文件写入权限验证需要通过两个检查:
 * 1. 用户的uid或status不在"exclude"(排除)列表中
 * 2. 用户的uid或status在目录的"trusted"(信任)列表中
 * 系统会从当前目录向上递归检查到根目录,且排除检查优先于信任检查
 */

// ultra rules
private nosave mapping trusted_read;
private nosave mapping exclude_read;
private nosave mapping trusted_write;
private nosave mapping exclude_write;

// extend rules save in diskette
private mapping extend_trusted_read;
private mapping extend_exclude_read;
private mapping extend_trusted_write;
private mapping extend_exclude_write;

// grant information for command
private mapping grant;

// grant information for sites
private mapping site_privilege;
