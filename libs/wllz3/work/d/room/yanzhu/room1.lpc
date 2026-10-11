// rouw_home 梦庭院

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short","客厅");
	set("long",@LONG
这里是主人家的大厅，只见大厅之上装饰华丽，宽阔非常。大厅的地
面铺设着红色的花岗石，地面擦拭的非常干净，隐约可以看见地面上呈现
着你的倒影。大厅中央有一张紫色桃木制成的八仙桌。大厅两旁挂着一些
出自于名人手笔的字画。大厅的南面穿过一条两旁种满鲜花和青草的小石
路就到了卧室。
LONG
);
	set("playerhouse",1);
/**/	set("default_long", "这里是主人家的大厅，只见大厅之上装饰华丽，宽阔非常。大厅的地面铺设着红色的花岗石，地面擦拭的非常干净，隐约可以看见地面上呈现着你的倒影。大厅中央有一张紫色桃木制成的八仙桌。大厅两旁挂着一些出自于名人手笔的字画。大厅的南面穿过一条两旁种满鲜花和青草的小石路就到了卧室。");
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
		"west"  : __DIR__"room2",
	]));
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");
	create_door("south", "木门", "north", DOOR_CLOSED);
	setup();
}
