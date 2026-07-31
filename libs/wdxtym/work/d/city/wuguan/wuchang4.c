//wuchang4.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "东武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫，墙边放着几个练功用的木人（muren）。
LONG);
        
	set("item_desc",([
		"【牌子】" :
		HIY"
※※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　　※※※※
※※※※　                  ※※※※
※※※※   东  练  武  场   ※※※※
※※※※　                  ※※※※     
※※※※　　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※※"NOR"\n",
		]));

	set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
               "west" : __DIR__"wuchang3",               
        ]));
        
        set("objects", ([
                   __DIR__"npc/muren" : 1,
        ]));

        setup();
}
