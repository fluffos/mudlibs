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
		"eastup" : __DIR__"dong1"+(random(3)+5),
		"southdown" : __DIR__"dong2"+(random(2)+6),
                "westsouth" : __DIR__"dong2"+(random(2)+6),
                "northup" : __DIR__"dong0"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong2"+(random(3)+5),
		"eastdown" : __DIR__"dong1"+(random(3)+5),
                "southup" : __DIR__"dong2"+(random(2)+6),
                "northdown" : __DIR__"dong1"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong2"+(random(3)+5),
                "eastnorth" : __DIR__"dong2"+(random(2)+6),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
