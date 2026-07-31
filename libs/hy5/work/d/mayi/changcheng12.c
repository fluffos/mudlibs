// /d/gaoli/fenghuotai
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "长城");
	set("long", @LONG
这里就是用于抵御游牧民族的长城了，战国时燕、赵、秦分别修城
墙抵御匈奴，后秦始皇将所有的城墙连接起来叫做长城，可惜现在天下
大乱，烽烟四起，而突厥日益强大，长城失去了他的作用。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
	        "westdown" : __DIR__"changcheng11",
            	"northeast" : __DIR__"changcheng13",
	]));
       setup();
	replace_program(ROOM);
}
