// database.h

// 是否采用永久连接
#define STATIC_LINK
// 是否调试状态
#define DEBUG
// 是否允许分站新玩家注册
// #define REFUSE_NEW_PLAYER
//对存入MYSQL的字符串做转换
#define DB_STR(x)    "'" + replace_string(x, "'", "''") + "'"
// 数据库服务器
#define DB_HOST "127.0.0.1"

protected mapping all_others_db = ([
        // "61.184.100.7" : "nitan.dx",
]);

protected mapping stations = ([
        "218.89.171.162" : "《泥潭·总站》",
        "61.184.100.7"   : "《泥潭·电信》",
        "202.110.119.87" : "《泥潭·网通》",
        "219.134.89.94"  : "《泥潭·深圳》",
]);

#ifndef DATABASE
protected string DATABASE               = "sun_data";
#endif
#ifndef DB_USER
protected string DB_USER                = "itwenwu";
#endif
protected string USER_TABLE             = "users";
protected string IP_TABLE               = "ip";
protected string NEWS_TABLE             = "news";
protected string ITEM_TABLE             = "item";
protected string ITEM_OWNER_TABLE       = "item_owner";
protected string ITEM_MAGIC_SAN_TABLE   = "item_magic_san";

// 采用的加密算法
protected string DB_CRYPT               = "PASSWORD";
