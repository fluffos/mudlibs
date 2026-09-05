inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", "扎陵湖畔");
        set("long", @LONG
这里是扎陵湖畔，西北面有一条山涧(creek)通往黄羊滩。
LONG
        );
		set("item_desc",(["creek":"一道不宽的山涧，随意都能走过去。\n"]));
        set("exits", ([
                "northwest" : __DIR__"huangyangtan",
                "east" : __DIR__"zhaling1",
        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "dalunsi");
		set("no_task",1);
        setup();
        set("no_clean_up", 0);
		set("entry_direction","east");
		set("migong","/d/lingzhou/zhaling");
		set("migong_posi","west");
		set("look_refuse_msg","扎陵湖升腾起一片雾气，你什么也看不清。\n");
		set("enter_refuse_msg","扎陵湖升腾起一片雾气，你什么也看不清，稍等再进吧。\n");
        setup();
        
}


