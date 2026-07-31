 // this is made by beyond
// /u/beyond/mr/shangyuezhai.c
// update 1997.6.20
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIY"赏月斋"NOR);
         set("long",@long
赏月斋是为慕容家每到中秋之夜而建造的。里面富丽堂皇，瓜果应有尽
有，旁边有丫鬟伺候着，每到赏月之时，一家老小都在这里赏月，在赏月的
同时，也念念不忘复兴大燕的使命。西面是内堂，东面和南面是一条长廊。
long);
         set("exits",([
		"west" : __DIR__"neitang",
		"east" : __DIR__"cl5-2",
		"south" : __DIR__"cl5-5",
	]));
        setup();
}

