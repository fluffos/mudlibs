#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"混沌之神殿"NOR);
	set("long", @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG CYN);
	set("exits", ([
		"down" : __DIR__"dong99",
                	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/bossz3" : 1,
              __DIR__"npc/lev8" : 2,
              __DIR__"npc/lev9" : 2,
              "/d/migong/lev15/npc/boss" : 2,
              "/clone/box/gboxm" : 3,
         ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
