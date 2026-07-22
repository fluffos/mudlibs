// 裁缝铺
// caifengpu1.c
// augx@sj 10/9/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIC"裁缝铺"NOR);
	set("long",
"这是家装璜豪华的裁缝铺，店堂里到处挂满了刚刚做好的衣服、帽子、鞋
子等等物件。这家裁缝铺的名扬长安城，达官贵人络绎不绝，十分兴旺。在屋
角还放着张很大的裁缝桌，不少年轻的裁缝正在桌子边忙碌着。
");

	set("objects",([
		__DIR__"npc/caifeng" : 1,
		__DIR__"obj/caifengzhuo" : 1,
	]));

	
	set("exits",([
		"east" : "/d/changan/northjie2",
	]));
	
	set("indoors", "长安城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
