
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"众神之失乐园"NOR);
	set("long", HIW @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+1),
		"south" : __DIR__"dong"+(random(15)+1),
                "west" : __DIR__"dong"+(random(10)+1),
                "north" : __DIR__"dong"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"eastup" : __DIR__"dong"+(random(15)+1),
		"southdown" : __DIR__"dong"+(random(20)+1),
                "westup" : __DIR__"dong"+(random(5)+1),
                "northdown" : __DIR__"dong"+(random(10)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(6),
//              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
