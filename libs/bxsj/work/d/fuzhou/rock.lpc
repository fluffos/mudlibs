// /d/fuzhou/rock.c 岩石(小岛)
// Lklv MOdify 2001.9.27

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",YEL"巨岩"NOR);
        set("long", @LONG
一块光秃秃的大岩石，四周长满了青苔。只有正中处凹了下去，似乎给什
么敲过。你走过去仔细一看，好象里面印着不少掌印似的。站在岩石上，极目
四望，远处点点灯火，好一个渔港夜灯。
LONG
        );
        set("outdoors","福州");

        set("exits",([
		"south" : __DIR__"island3",
		"enter" : __DIR__"mupeng",
        ]) );
        setup();
}

void init()
{
        add_action("do_strike","strike");
        add_action("do_za","za");
}

int do_strike(string arg)
{
	object me = this_player();
	int skl_impv,jingli_damage;

	if ( !(arg) || ((arg != "rock") && (arg != "yan")) )
		return 0;
	if ( me->is_busy() )
		return notify_fail("你现在正忙着呢！");
	if ( me->query("max_neili") <= 300 ) {
		message_vision("$N往岩石上一拍，谁知内力不够闷哼了一声，反而受了内伤。\n", me);
		me->receive_wound("qi", 100);
		return 1;
	}
	else {
		if ( me->query("jingli") < 150 ) {
			tell_object(me,"你太累了。\n");
			return 1;
		}
		message_vision("$N大喝一声，往岩上一击，只听见‘嗡...’，岩石摇了几下。\n",me);
		if ( me->query_skill("strike", 1) <= 101 ) {
			skl_impv = (me->query_str(1) / 2)+ me->query_con(1) / 2 + (me->query_condition("drunk") / 2) ;
			me->improve_skill("strike", skl_impv);
			jingli_damage = 80 - random(me->query_str())-random(me->query_int());
			if ( jingli_damage < 0 ) jingli_damage = 0;
			me->receive_damage("jingli", jingli_damage);
			return 1;
		}
		return 1;
	}
}

int do_za(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if (!weapon || weapon->query("skill_type") != "stick" )
		return notify_fail("你要用什么来砸？\n");

	if( !arg || arg!="yan" )
		return notify_fail("你要砸什么？\n");

	if ( me->query_skill("stick",1) > 100 ) {
		tell_object(me,"你发现这对你没什么用。\n");
		return 1;
	}
	if ( me->query("jingli") < 150 ) {
		tell_object(me,"你太累了。\n");
		return 1;
	}

	me->receive_damage("jingli",20 +random(20));
	write("你挥舞手中兵器，用力向岩石砸去。\n");
	me->improve_skill("stick", 15+me->query("str"));
	return 1;
}
