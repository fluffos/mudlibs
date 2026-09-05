// Room: /u/cuer/emei/shanmen.c
//cuer
// Rewrote by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", CYN"石洞"NOR);
	set("long", CYN @LONG
这里是土匪密洞的入口，门口有几个土匪在盘查过往行人。
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong01",
		"south" : __DIR__"dong10",
		"enter" :__DIR__"mishi",
	]));
    set("no_task",1);
//	set("no_clean_up", 0);
	set("objects",([
		__DIR__"npc/xiaotufei" : 4,  
		"/clone/npc/camel1" : 0,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object *ob;

	if( dir != "enter" )
		return ::valid_leave(me, dir);

	ob = all_inventory( environment( me ));
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i]->query("id") == "xiao tufei")
			return notify_fail("小土匪嘿嘿一笑，拦住了你的去路。\n");

	return ::valid_leave(me, dir);
}