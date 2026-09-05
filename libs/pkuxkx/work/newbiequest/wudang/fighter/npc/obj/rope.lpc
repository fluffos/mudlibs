// rope.c
//麻绳，剿匪任务用
//seagate@pkuxkx 2010/11/06
#include <ansi.h>
#include "/newbiequest/combat.h"
inherit ITEM;

void in_kun(object,object);

void create()
{
	set_name(YEL"麻绳"NOR, ({ "ma sheng", "rope" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根碗口粗的麻绳，可以用来捆(kun)人。\n");
		set("value", 3000);
		set("material", "rope");
	}
	
	setup();
}

void init()
{
	add_action("do_kun", "kun");
}

int do_kun(string arg)
{
	object en,me;
	function f_kun;
	
	me=this_player();
	if(!arg)
		return notify_fail("你想捆谁啊？\n");
	else if(!(en=present(arg,environment(me)))||userp(en)||!living(en))
		return notify_fail("麻绳只能捆绑npc角色！\n");
	else if(environment()!=me)
		return notify_fail("你身上没有麻绳，捆不了人！\n");
	else if(en->query("qi")*100/en->query("max_qi")>50)
		return notify_fail(en->name()+"轻松地躲开了你扔过去的绳子。\n");
	else if(!me->is_fighting()&&!en->is_fighting())
		return notify_fail("麻绳只能捆绑战斗中的对手！\n");
	else if(!en->query("can_kun"))
		return notify_fail("麻绳只能作为完成任务使用。\n");
	
	if(!combat_ratio(combat_coef(me->query("combat_exp"),0),combat_coef(en->query("combat_exp"),0),700-en->query("qi")*1000/en->query("eff_qi"))) {
		call_out("destroying", 1, this_object());
		return notify_fail("你虽然捆住了"+en->name()+"，但是"+en->name()+"很轻松的就把绳子给挣断了。\n");
	}
		
	message_vision("$N拿出绳子捆在$n身上，$n挣扎了几下，没有挣扎开捆绑在身上的绳子。\n",me,en);
	f_kun=bind((:call_other, __FILE__,"in_kun",me,en:),en);
	evaluate(f_kun);
	me->remove_killer(en);
	en->remove_killer(me);
	call_out("destroying", 1, this_object());
	return 1;
}

void in_kun(object me,object en)
{
	if(en&&living(en)&&environment(me)==environment(en)) {
		if(en->query("in_kun")<0)
			return;
		en->set("in_kun",1);
		en->start_busy(5);
	  tell_room(environment(me),en->name()+"挣扎了几下，没有挣扎开捆绑在身上的绳子。\n");
		call_out("in_kun",4,me,en);
	}
	else if(en)
		en->delete("in_kun");
}

void destroying(object ob)
{
	destruct(ob);
}