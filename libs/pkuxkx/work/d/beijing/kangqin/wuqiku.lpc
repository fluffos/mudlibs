// Room: /d/beijing/kangqin/wuqiku.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"兵器库"NOR);
	set("long",
MAG"这里是武器库，架上摆满了各种武器,任由武士门挑选。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"garden",
]));
        set("objects", ([
                "/d/village/npc/obj/hammer" : 1,
                "/d/xingxiu/npc/obj/tiegun" : 1,
                "/d/gumu/obj/changbian" : 1,
                "/d/city/obj/changjian" : 1,
                "/d/city/obj/gangdao" : 1,
                "/d/quanzhou/obj/fuchen" : 1,
                "/d/yuewangmu/obj/changqiang":1,
        ]));
	setup();
	replace_program(ROOM);
}
