// Room: /d/jjf/gate.c

inherit ROOM;


void create()
{
set("short", "演武场入口");
set("long", @LONG
在傲来国演武场的入口，站立着几个威武的禁军教头，
守卫着这里。里面不时传来雄壮的号角声。
LONG
	);

set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fight_room",
  "west"  : __DIR__"northgate",
]));
set("out_doors", "aolai");
set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/jiaotou" : 2,
]));

setup();
}

