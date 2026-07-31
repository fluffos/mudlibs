//xiaojing4.c
// this is made by hotjc for 2001.11.3

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","小径");
         set("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，南面是小径的延
伸。
long);
         set("outdoors","murong");
         set("exits",([
               "north" : __DIR__"xiaojing5",
             "south" : __DIR__"xiaojing4",
                         "west" : __DIR__"xiaojing4",
                         "east" : __DIR__"xiaojing4",
]));
        setup();
        replace_program(ROOM);
}

