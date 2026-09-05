#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", HIM"西花园"NOR);
	set("long", "这是绿柳山庄后院的西花园，占地极大，山石古拙，溪池清澈，花
卉不多，却极是雅致，显得这花园的主人实非庸夫俗流，胸中大有丘壑。
花园里各色花卉正含苞待放，沿着香气幽幽的小径往北走不多远有一道
围墙，开着一扇青色小门，远远地便可听到墙外传来一阵阵呼喝叫好声。\n"NOR);
	set("exits", ([
		"east" : __DIR__"zoulang2",
		"north" : __DIR__"xixiaomen",
	]));
	set("outdoors", "lvliu");
	setup();
}



