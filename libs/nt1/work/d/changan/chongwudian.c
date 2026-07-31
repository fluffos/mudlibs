// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "宠物店");
        set("long", @LONG
这里是关东大风堂设在长安东郊的一个宠物店，生意特别火暴，可能
是这里的宠物具有灵性的原因。
LONG );

        set("exits", ([
                "south" : __DIR__"road4",
        ]));
        set("objects", ([
                "/adm/npc/horseboss" : 1,
        ]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}



