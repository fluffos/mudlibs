#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", CYN"小门"NOR);
	set("long", "西花园的围墙上开着一扇青色小门，站在门口向墙外望去，地势渐
高之处有一座阁楼，楼下以青石铺地，开辟了四个不大的比武场。有几
个锦衣武士正在比武场上往来比试，场边还有数人围观。\n"NOR);
	set("exits", ([
		"south" : __DIR__"xihuayuan",
		"north" : __DIR__"biwulouxia",
	]));
	set("outdoors", "lvliu");
	setup();
}



