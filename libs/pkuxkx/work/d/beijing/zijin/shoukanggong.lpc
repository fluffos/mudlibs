// Room: /d/beijing/zijin/shoukang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"寿康宫"NOR);
	set("long",
HIC"这里是皇太后的住所，前殿悬挂的匾额上书“令德淑仪”四字。
黄琉璃瓦歇山式顶，檐里装修，明间前后檐开门，次间、梢间槛墙
、槛窗，双交四棂花隔扇门、窗。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"houdian",
  	"east" : __DIR__"cininggong",
]));
        set("objects", ([
                "/d/beijing/npc/jianning" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
