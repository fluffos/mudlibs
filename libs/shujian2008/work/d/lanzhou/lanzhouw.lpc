// Room: /d/xingxiu/jyge.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "西城门");
	set("long", @LONG
这是就是兰州的西城门。再往东就进城了，这儿有军队驻扎，不时盘问来
往行人。你小心翼翼，急步离开这是非之地。出关向西，是通往纪永河的驿道。
城门的墙上张贴着一纸告示(gaoshi)。
LONG);

	set("outdoors", "兰州");

	set("exits", ([
		"northwest" : __DIR__"road6",
		"east" : __DIR__"lanzhou",
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
/*
void init()
{
	object me = this_player();

	if (!userp(me)) return;
	me->set_temp("check", 1);
	call_out((: call_other :), 1, me, "delete_temp", "check");
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i, flag = 0;
	object bing = present("guan bing", this_object());

	if (me->query_temp("check") && bing && living(bing)) {
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
	me->delete_temp("check");
	return ::valid_leave(me, dir);
}
*/