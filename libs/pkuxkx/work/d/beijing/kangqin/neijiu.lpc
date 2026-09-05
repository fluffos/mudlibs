// Room: /d/beijing/kangqin/neijiu.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"内厩"NOR);
	set("long",
MAG"这里比外面的马厩要干净得多，饲料槽里的饲料也要
精细得多。地上铺了厚厚的干草。旁边有扇门，但已经给锁
死了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"east" : __DIR__"majiu",
]));
        create_door("east", "小门", "west", DOOR_CLOSED);
        set("objects",([
                "/d/beijing/npc/yucongma":1,
        ]));

	setup();
	replace_program(ROOM);
}
