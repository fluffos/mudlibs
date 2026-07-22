// neishi.c 内室

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "内室");
        set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写
着大大的一个『静』字。一位慈眉善目的灰衣老道正端坐于蒲团
上打坐。两个小道童站在床边。
LONG
        );
       
        set("exits", ([
                "east" : __DIR__"zhongtang",
             ]));

        set("objects", ([
                __DIR__"npc/mayu" : 1, 
   ]));

        create_door("east", "竹门", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

