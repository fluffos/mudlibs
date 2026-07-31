
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"海之礁岛"NOR);
	set("long", GRN @LONG
     一个大浪打在岩礁上，溅起□天的水花，你闪避不及被淋个正著
海风吹来，远远眺望，几艘渔船正随波载浮载沈；晦暗不明的天空，乌
云团簇好似一只只正在张牙舞爪的野兽。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong56",
		"east" : __DIR__"dong5"+(random(6)+1),
		"south" : __DIR__"dong5"+(random(6)+1),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(4)+3),
		"north" : __DIR__"dong5"+(random(5)+5),
	]));
        set("objects", ([
              __DIR__"npc/lev7" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

