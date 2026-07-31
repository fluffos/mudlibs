// Room: peitian-fang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"配天作镇坊"NOR);
	set("long", @LONG
往上行便是位于嵩山之巅的封禅台。向北望去，遥见成皋玉门，黄
河有如一线，西向隐隐见到洛阳伊阙，东南两方皆是重重叠叠的山峰。
LONG);
	set("exits", ([
		"southdown" : __DIR__"shidao3",
		"northup" : __DIR__"fengchantai",
	]));
	set("outdoors", "嵩山");
	setup();
}

void init()
{
	object me = this_player();

	if ( me->query("family/family_name") == "嵩山派"
	&& me->query("title") == "嵩山派第四代弟子")
		me->set("title", HIC"五岳盟主亲传弟子"NOR);
}
