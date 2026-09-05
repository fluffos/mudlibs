// File		: letter.c
// Created By	: iszt@pkuxkx, 2007-04-15

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"密函"NOR, ({ "mi han", "han", "xin", "letter" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","这是一封盖着火漆印戳的密函，封面上却没有写是谁寄出的。\n");
		set("value", 0);
		set("material", "paper");
		set("no_drop", 1);
		set("no_store", 1);
	}
	call_out("dest",random(200)+1200);
}

void init()
{
	add_action("do_give", "songxin");
	add_action("do_look", "look");
}

void do_init(object me)
{
	set("target_name", me->query_temp("hsnewbiejob/songxin/target_name"));
	set("target_id", me->query_temp("hsnewbiejob/songxin/target_id"));
	set("owner", me);
	set("start_time", time());
	if(random(2))
		call_out("killer", me->query_kar()+random(40)+10, me);
	else
		call_out("stealer", me->query_kar()+random(40)+10, me);
}

void killer(object me)
{
	object killer;
	if(environment()!=me)
		return;
	killer = new(__DIR__"killer2");
	killer->do_copy(me);
	killer->move(environment(me));
	killer->set_leader(me);
	message_vision(HIR"\n$N仰首狂笑道：「$n，把密函给我乖乖交出来吧！」\n"NOR, killer, me);
	return;
}
void stealer(object me)
{
	object stealer;
	if(environment()!=me)
		return;
	stealer = new(__DIR__"killer2");
	stealer->do_copy(me);
	this_object()->move(stealer);
	stealer->move(environment(me));
	stealer->set_leader(me);
	message_vision(HIR"\n$n伸手向怀中一摸，发现密函已经不翼而飞！\n"NOR, stealer, me);
	return;
}
int do_give(string arg)
{
	object me = this_player();
	object target;

	if( me->is_busy() || me->is_fighting() ) 
		return notify_fail("你正忙着呢。\n");
	if(!arg)
		return notify_fail("你要送给谁？\n");
	if(!objectp(target = present(arg, environment(me)))) 
		return notify_fail("你要送给谁？\n");
	if(query("owner") != me)
		return notify_fail("这是你的信么？\n");
	if( !living(target) ) 
		return notify_fail("看清楚点，那是活人吗？！\n");
	if( userp(target) ) 
		return notify_fail("嘿嘿，想作弊？！\n");
	if(target->query("name") != query("target_name"))
		return notify_fail("不是这人的信吧？\n");
	if(target->query("id") != query("target_id"))
		return notify_fail("不是这人的信吧？\n");

	message_vision(HIY"$N从怀中掏出信交给$n"HIY"，道：「这是岳不群先生托"
		+RANK_D->query_self(me)+HIY"送给您的信，请收好。」\n"NOR, me, target);
	
	write(HIW"你的任务完成，快回去复命吧。\n"NOR);
	me->set_temp("hsnewbiejob/songxin/finish", 1);
	destruct(this_object());
	return 1;
}
int do_look(string arg)
{

	set("long",RED"这是一封盖着火漆印戳的密函，封面上却没有写是谁寄出的。\n\n"NOR);
	add("long",HIC"           收信人："+query("target_name")+HIG"("
		+capitalize(query("target_id"))+")\n\n"NOR);
}

void dest()
{
	if(!this_object())
		return;
	destruct(this_object());
}
