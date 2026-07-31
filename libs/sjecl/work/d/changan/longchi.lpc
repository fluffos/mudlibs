// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/longchi.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "龙池");
        set("long", @LONG
一入门，热气扑面，白白的水气立刻包围了你。你依稀看到一个巨大的檀
木水池，水呈碧绿，散发着一种奇特的药香，水面上还漂着一片片红红的花瓣
儿，你真想快点下去洗(wash)个澡，闭上眼睛好好的放松一下。
LONG
        );
        set("exits", ([
                "east" : __DIR__"qingchi",
        ]));
        set("objects", ([
                __DIR__"npc/luotiman": 1,
        ]) );
        set("no_fight", 1);
        set("incity",1);
	setup();

}

void init()
{
	add_action("action", ({
		"dazuo",
		"du",
		"exercise",
		"lian",
		"practice",
		"respirate",
		"study",
		"tuna"
	}));
	add_action("do_wash", "wash");
}

int do_wash()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	object *inv;
	int i;

	if (me->query_temp("ca_wash")>0) return notify_fail("你已经泡在水池中了！\n");
	if (weapon) 
		return notify_fail("不要那么紧张啊，洗澡还拿着武器？\n");

	inv= all_inventory(me);
	i = sizeof(inv);
	while (i--)
	if( inv[i]->query("equipped") && (! inv[i]->query_autoload() && inv[i]->query("id") != "bu dai"))
		return notify_fail("身上穿着衣服怎么洗澡？\n"); 
	message_vision("$N走进浴池，将全身都浸泡到水中。\n",me);
	me->set_temp("ca_wash",1);
	tell_object(me,"你感到无比的舒泰……\n");
	me->start_busy(20);
	call_out("overwash",10+random(5), me);
	return 1;
}

int action()
{
	write("你还是先洗澡吧。\n");
	return 1;
}

void overwash(object me)
{
	int jing,qi,neili;
	if(!me) return;

        qi=(int)me->query("max_qi");
        jing=(int)me->query("max_jing");
        neili=(int)me->query("max_neili");

        if( me && environment(me) == this_object()) {
		message_vision("$N精神抖擞的从浴池中走了出来！\n", me);
		me->delete_temp("ca_wash",1);
		//me->set("eff_qi",qi);
		//me->set("eff_jing",jing);
		me->set("neili",neili);
		me->set("qi",me->query("eff_qi")+me->query_temp("apply/qi"));
		me->set("jing",me->query("eff_jing")+me->query_temp("apply/jing"));
		me->start_busy(-1);
	}
	return;
}

int valid_leave(object me,string dir)
{
        if (dir == "east") {
		write("地面很滑，你小心翼翼的从里面走出来！\n");
		me->delete_temp("pay_wash");
	}
	return ::valid_leave(me,dir);
}
