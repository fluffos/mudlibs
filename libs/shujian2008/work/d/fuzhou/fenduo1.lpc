// fenduo1.c 丐帮大义分舵(福州渔船)
// Modify by Looklove@SJ at 2000/9/26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","船舱");
	set("long", @LONG
这就是一个船舱，舱四周的窗都关得严严的，里面只点了一盏油灯，你依稀看
到地上满是鱼骨，鱼腥味，霉味混在一块，味道难闻死了。船舱正中的桌子旁围
坐着几个老乞丐，似乎正在商量着什么，一数他们背上的布袋就知道他们是丐帮
里很有地位的人物。这里是丐帮设在福州的大义分舵。
LONG
	);
	set("exits",([
		"out" : __DIR__"yuchuan5",
	]));
	set("objects", ([
                CLASS_D("gaibang") + "/jiang" : 1,
                CLASS_D("gaibang") + "/wu" : 1,
	]));

	set("valid_startroom",1);
	setup();
	call_other("/clone/board/gb_board", "???");
}