// i2d.h

#define MUD                     0
#define STREAM                  1
#define DATAGRAM                2
#define STREAM_BINARY           3
#define DATAGRAM_BINARY         4
//-----------------------------------------------
#define I2D_MUD_SERVER          ({"59.37.59.254", 5004})
#define MUDLIST_UPDATE_INTERVAL 600
#define REFRESH_INCOMING_TIME   3*60*60
//----------------------位元运算用-------------------------
#define GB_CODE                 1       // gb站点
#define ANTI_AD                 2       // 有垃圾广告的站点
#define IGNORED                 4       // 被本站屏蔽信息站点
#define SHUTDOWN                8       // 关闭的站点
#define ONLINE                  16      // 可连接站点
#define DISCONNECT              32      // 失去联系的站点
#define ENCODE_CONFIRM          64      // 系统自动判定gb/big5码的站点

