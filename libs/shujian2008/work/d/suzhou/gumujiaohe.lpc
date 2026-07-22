#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"古木交诃"NOR);
	set("long", @LONG
古木交诃在荷花厅的西面，一排不同图案的漏窗，使你透过漏窗隐隐看
到中部的水光山色和高低错落的楼阁，此处赏景，有“移步幻影”之妙。向
西窗孔可以遥望绿荫轩、明瑟楼，给人一种“庭院深深深几许”和空间不尽
之感。
LONG	);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
        set("exits", ([ 
	"southwest" : __DIR__"chitang",
	"east" : __DIR__"hehuating",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",80);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}