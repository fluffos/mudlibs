#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "农舍里屋");
	set("long", "这里是一家普通农舍,简陋的土炕,陈旧的木桌,桌上放着几件衣服,象是给女孩子穿的.\n" + RED"                   有坏人!!! \n"NOR + "土炕上一个年轻姑娘正被一个大汉按住,一边哭喊一边挣扎!\n"
	);

	set("exits", ([
               "south" : __DIR__"wehouse",
            ]));
         set("objects", ([
                __DIR__"npc/cungu" : 1,
                __DIR__"npc/tufeitou" : 1,
        ]));
	
	setup();
}


