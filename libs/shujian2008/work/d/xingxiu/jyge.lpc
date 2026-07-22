// Room: /d/xingxiu/jyge.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "嘉峪关东城门");
	set("long", @LONG
这是长城最西的关隘嘉峪关东城门。再往西就进关了，这儿有军队驻扎，
不时盘问来往行人。你小心翼翼，急步离开这是非之地。出关向东，联结的便
是著名的“万里长城”。城门的墙上张贴着一纸告示(gaoshi)。
LONG);
	set("outdoors", "嘉峪关");
	set("exits", ([
		"eastup" : __DIR__"road5",
		"west" : __DIR__"jyg",
	]));

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("objects", ([
		__DIR__"npc/bing1" : 2,
		__DIR__"npc/wujiang1" : 1,               
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n全国通缉。\n";
}

void remove_check(object me)
{
	if (me)
		me->delete_temp("jyg_check");
}

void init()
{
	object me = this_player();

	if (!userp(me)) return;
	me->set_temp("jyg_check", 1);
	call_out("remove_check", 1, me);
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i, flag = 0;
	object bing = present("guan bing", this_object());

	if (me->query_temp("jyg_check") && bing && living(bing)) {
		ob = deep_inventory(me);
		i = sizeof(ob);
		while (i--)
		if (ob[i]->id("gold_money") && ob[i]->move(bing)) flag = 1;
		tell_object(me, bing->name()+"喝道："+RANK_D->query_rude(me)+"给我站住，跑那么快干什么？\n");
		if (flag)
		if( flag && me->query("combat_exp")>100000)
		message_vision(HIY "$N将$n身上的黄金搜了个精光。\n" NOR, bing, me);
		return notify_fail(bing->name()+"拦住了你。\n");
	}
	me->delete_temp("jyg_check");
	return ::valid_leave(me, dir);
}
