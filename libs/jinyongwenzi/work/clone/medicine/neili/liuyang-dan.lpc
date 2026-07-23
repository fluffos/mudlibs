//wuchangdan.c
#include <ansi.h>
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"六阳正气丹"NOR, ({"zhengqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", HIR"这是一颗殷红如血的六阳正气丹，经药王院高僧精心练制，\n"+
			       "解寒毒，疗绝症有起死回生之功。\n"NOR);
		set("no_get",1);
		set("no_give",1);
	}
	setup();
}

int do_eat(string arg)
{

	int force_limit, neili_limit,improve;
	object me = this_player();
	force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
	neili_limit = me->query("max_neili");

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if (query("owner") != me->query("id"))       
	    return notify_fail("这颗六阳正气丹好象不是你得到的吧？\n");

	if (me->query_condition("medicine") > 0 ){
	 message_vision(HIR "$N吃下一颗六阳正气丹，只觉得热气直冲头顶，原来与$P以前所服丹药药性相左！\n" NOR, me);
	 me->set("jing",me->query("max_jing")/10);
	 me->set("eff_jing",me->query("max_jing")/10);
	 me->set("qi",me->query("max_qi")/10);
	 me->set("eff_qi",me->query("max_qi")/10);
	 me->add("max_neili",-10);
	 log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力十点。\n",
	    ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));
	} else {  
	  if( neili_limit < force_limit) {
		message_vision(HIR"$N吃下一颗六阳正气丹，顿时一股热气直透心底！\n"NOR,me);
		improve = random(2);
		me->apply_condition("medicine", 30 * improve);
		me->add("max_neili", improve);
		log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
		ctime(time())[4..19],me->name(1),capitalize(me->query("id")),name(),chinese_number(improve)));
	  } else {
		me->set("jing",me->query("max_jing"));
		me->set("eff_jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("neili", me->query("max_neili") * 2);
		me->clear_conditions_by_type("poison");
	  	me->apply_condition("medicine", 60);
	  }
       }
	destruct(this_object());
	return 1;
}
