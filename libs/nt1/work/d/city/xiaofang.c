// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小房");
        set("long",
"这是一个非常简陋的房子，一床一几，床上挂了纱帐，墙上挂着一副\n"
"似是名家的画(picture),此外别无他物。\n"
        );
        set("exits", ([
                "east" : "/d/city/zzroad2",
        ]));

        set("objects", ([
                __DIR__"npc/guisan" : 1,
        ]));
        set("item_desc", ([
                "picture" : "下雨天的名画。\n",
        ]));

        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "enter") 
        {
                say (me->name() + "走进暗洞。鬼三又把暗门关起来。\n");
                me->set_temp("new_valid_dest", "/d/city/didao");
                me->move("/d/city/didao");
                delete("exits/enter");
                me->set_temp("search", 0);
        }
        return ::valid_leave(me, dir);
}

