#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"东客房"NOR);
	set("long",
CYN"一进门，只见六个喇嘛手持戒刀，围着一白衣女尼拼命砍杀，
只是给白衣女尼的袖力掌风逼住了，欺不近身。但那白衣女子头顶
已冒出丝丝白气，显然已尽了全力。她只一条臂膀，再支持下去恐
怕难以抵敌。地上斑斑点点都是血迹。\n"NOR
);
	set("exits", ([
		"west" : __DIR__"kedian5",
	]));
	set("objects", ([
		"/d/beijing/npc/dubi":1,
		"/d/beijing/npc/lama":6,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{

	object ob;
	ob = this_player();
	if(objectp(present("dubi shenni", this_object())))
	tell_object(ob,"你踏进屋来，只见一个女尼倒在地上，喘息不止。\n");
}



