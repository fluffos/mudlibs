//xj4.c
// this is made by hotjc

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"小径"NOR);
         set("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，往北面看去是一
片柳树林，南面是后院，北面是一条小径。
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"xj2",
             "south" : __DIR__"houyuan",
]));
        setup();
        replace_program(ROOM);
}
