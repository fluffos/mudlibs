//edity by rock
//log 系统
//记录玩家装备经验等走向
//方便以后查找

#include "localtime.h"

#ifndef LOG_H
#define LOG_H

#define LOG_AUTODOC		"autodoc"
#define LOG_BANISH		"banish"
#define LOG_BUG			"bug"
#define LOG_CHANNEL		"channel"
#define LOG_FEEDBACK		"feedback"
#define LOG_FORCE		"force"
#define LOG_FTP			"ftp"
#define LOG_HELP_MISS		"help miss"
#define LOG_I3_ERROR		"i3 error"
#define LOG_IDEA		"idea"
#define LOG_LOGIN		"login"
#define LOG_LOGIN_FAILURE	"login failure"
#define LOG_MAIL_ERROR		"mail error"
#define LOG_NEW_PLAYERS         "new players"
#define LOG_QUEST		"quest"
#define LOG_QUESTION		"question"
#define LOG_QUIT		"quit"
#define LOG_SHUTDOWN		"shutdown"
#define LOG_SNOOP		"snoop"
#define LOG_SOCKET		"socket"
#define LOG_TODO		"todo"
#define LOG_TYPO		"typo"
#define LOG_WALL		"wall"

/* these are logged to directly */
#define LOG_FILE_CATCH		"/log/catch"
#define LOG_FILE_RUNTIME	"/log/runtime"
#define LOG_FILE_ERROR		"/log/log"

#endif /* LOG_H */

int make_log(object player,string type,string msg)
{
	string file,player_id,file_msg;
	mixed time;
	int year,mon,day,hour,min,sec;
	
	if(!objectp(player) && !type && !msg) return 0;

	time = localtime(time());
	year = time[LT_YEAR];   //年份 (必须大於 1900)
	mon = time[LT_MON];     //月数 (0..11)
	day = time[LT_MDAY];    //日数 (1..31)
	hour = time[LT_HOUR];   //小时 (0..23)
	min = time[LT_MIN];     //分钟 (0..59)
	sec = time[LT_SEC];     //秒数 (0..59)

	switch(type)
	{
		//经验
		case "exp" :
			file = sprintf("exp/%s",player->query("id"));
			break;
		//潜能
		case "pot" :
			file = sprintf("pot/%s",player->query("id"));
			break;
		//金钱
		case "money" :
			file = sprintf("money/%s",player->query("id"));
			break;
		//交易
		case "jiaoyi" :
			file = sprintf("jiaoyi/%s",player->query("id"));
			break;
		//装备
		case "equip" :
			file = sprintf("equip/%s",player->query("id"));
			break;
	}
	file_msg = sprintf("%s (%d年%d月%d日%d时%d分%d秒)\n",msg,year,mon,day,hour,min,sec);
	log_file(file,file_msg);
	return 1;
}