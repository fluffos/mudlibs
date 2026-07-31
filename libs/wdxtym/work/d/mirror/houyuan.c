// houyuan.c 财主后院
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "财主后院");
	set("long", @LONG
	这里是财主后院，各种古玩琳琅满目，商周青铜、汉瓦当、唐三彩……，
应有尽有，只要拥有一件，就够你吃一辈子了。崔员外正坐在琉璃榻上，慢幽幽
地喝着参汤。东侧有一扇门(men)。
LONG
	);
	set("item_desc", ([
		"men" : "这扇门似乎通向一间密室。\n",
	]));
	set("exits", ([
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));

	setup();
}
//是镜像
int is_mirror() { return 1; }