// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "孟婆驿");
        set("long", @LONG
一个小小的驿站，小店里很黑，只有东边的窗外有一丝亮光透过
发黄的窗纸射入店内。很多黑影在角落里晃动，有些一闪就不见了。
LONG
        );
        set("exits", ([
		"north" : __DIR__"aihe",
        ]) );
        set("objects", ([
                __DIR__"npc/mengpo" : 1,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-100);
	set("coor/z",-290);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
