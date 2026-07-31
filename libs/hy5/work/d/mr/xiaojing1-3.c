// /u/beyond/mr/xiaojing1-3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"小径"NOR);
         set("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，东面是小径的延
伸。
long);
         set("outdoors","mr");
         set("exits",([
             "west" : __DIR__"cl5-4",
             "east" : __DIR__"xiaojing1-4",
]));
	setup();
	replace_program(ROOM);
}
