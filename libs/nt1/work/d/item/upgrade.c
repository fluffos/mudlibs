// Upgrade Armor: upgrade.c
// Created by Lonely@nitan(1)
// At 12/7/2002

#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_promote(string arg);

void create()
{

        set("short", HIR "防具升级室" NOR);
        set("long",
		"这里是欧冶子升级防具的地方。屋子里有一个烧得通红的火炉，闪动\n"
                "着鲜艳的火苗，火炉边坐着一位赤着上身的大汉，盯着火炉不言不语。\n\n"
	);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_sleep_room",1);

        set("objects", ([
                "/adm/npc/ouyezi" : 1,
        ]));
        set("exits", ([
                "north" : __DIR__"road5", 
        ]));
        
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("upgrade"))
        {
        	this_player()->delete_temp("upgrade");
                message_vision("欧冶子对$N喊道：不要到处乱走，否则道具弄丢了我可不负责啊。\n", me);
        }

        return ::valid_leave(me, dir);
}
