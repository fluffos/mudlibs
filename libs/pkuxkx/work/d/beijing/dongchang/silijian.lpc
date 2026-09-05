#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"司礼监"NOR);
	set("long",
HIC"这里便是太监官署中地位最为显赫的司礼监，大堂内左右各站立
了四名内侍，虽然身份低下，但其对其余各监的人并不显得格外谦卑，
反而有种傲慢的神情显现在面上，足以见司礼监的权势之大。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"yumajian",
		"north" : __DIR__"neitang",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/liujin" : 1,
               __DIR__"npc/wangzhen" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
