// File		: xueguan.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
	set("short", HIW"雪关"NOR);
	set("long", @LONG
雪地之上，建起了一座雪关：几名雪山弟子正在关前走来走去，不知是不是
有什么任务。这里也没什么人过往，所以只有你引起了他们的注意。远处山上就
是凌霄城了，在一片白茫中闪耀着光芒。
LONG);

	set("outdoors", "凌霄城");
	set("valid_startroom", 1);

	set("item_desc", ([
		"snow": (: snow :),
	]));

	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));

	set("exits", ([
		"southwest" : __DIR__"xuepo1",
		"east" : __DIR__"xuedi3",
		"northup" : __DIR__"xuepo4",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	mapping fam = (mapping)me->query("family");
	int shen = me->query("shen");
	object *ob;

	if( shen > -10000 || dir != "northup")
		return ::valid_leave(me, dir);
	if( fam && fam["family_name"] == "雪山派" && fam["generation"] > 7 )
		return ::valid_leave(me, dir);

	ob = all_inventory( environment(me) );
	for(i=0; i<sizeof(ob); i++) 
	{
		if( living(ob[i]) && ob[i]->query("id") == "xueshan dizi" )
			return notify_fail("一名雪山弟子对你拔剑怒目相视，冷冷的道：\n凌霄城岂容你等邪魔外道踏足，请回吧！\n");
	}

	return ::valid_leave(me, dir);
}