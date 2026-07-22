// mysqj.h

// 是否采用永久连接
#define STATIC_LINK

protected mapping all_others_db = ([
	"182.16.0.230":"hell_xajh",
]);

protected string DB_HOST		= "localhost";
protected string DATABASE		= "hell";
protected string DB_USER		= "sldb";
protected string REGISTERED_TABLE	= "players";
protected string FAIL_CMD_TABLE		= "fail_cmds";

protected string local_station = "server";

protected mapping stations = ([
	"server" : "《网际寻宝宝》内部网(182.16.0.230 7000)",
]);
