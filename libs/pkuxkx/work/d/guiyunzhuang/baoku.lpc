// Room: baoku.c
//Made By:pingpang

#include <ansi.h>
inherit ROOM;

int do_catch(string arg);


void create()
{
	set("short",YEL"宝库"NOR);
        set("long", @LONG
 宝库里有个木棺(coffin),这里是昔日皇储藏宝的地方。
LONG
        );
set("exits", ([
                
		"south" : __DIR__"guiyunting",
        ]));

    set("item_desc", ([
                "coffin": "看起来你可以打开它（open）。\n",
                "木棺" : "看起来你可以打开它(open)。\n",
               ]));
	set("objects",([__DIR__"obj/coffin":1,]));
        setup();
}


