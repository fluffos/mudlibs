#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"留园"NOR);
	set("long", @LONG
留园是苏州的一大名景之一，它以结构布局紧密、厅堂华丽宏敝、装饰
精美典雅而享有“吴中第一名园”之誉。
LONG	);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
        set("exits", ([ 
	"west" : __DIR__"hehuating",
	"east" : __DIR__"nandajie2",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",100);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}