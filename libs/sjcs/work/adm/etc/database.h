// database.h

// 是否采用永久连接
#define STATIC_LINK

protected mapping all_others_db = ([
	"10.16.2.214":"mhsj",
]);

protected string DB_HOST		= "localhost";
protected string DATABASE		= "suannai";
protected string DB_USER		= "suannai";
protected string REGISTERED_TABLE	= "reg_player";
protected string TEMP_TABLE		= "tmp_player";
protected string PAWN_TABLE		= "pawn_tb";
protected string FAIL_CMD_TABLE		= "fail_cmds";
protected int reg_time			= 86400*2;	// 两天
