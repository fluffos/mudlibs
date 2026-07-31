#include <ansi.h>
inherit HUFA;

varargs void setskills(int i)
{
	object who;
	string *order = ({"长", "短", "金", "卷"});
	set_name((order[random(4)]) + "毛虱", ({ "niu shi","niushi","shi"}) );
	set("long", "没见过虱子吗？去牛和猴子身上仔细找找。\n");
	set("gender","男性");
	set("look_msg","没见过虱子吗？去牛和猴子身上仔细找找。\n");
	set_skill("unarmed", i);
       	set_skill("dodge", i);
       	set_skill("force", i);
       	set_skill("parry", i);
       	set_skill("moyun-shou", i);
       	map_skill("unarmed","moyun-shou");
       	map_skill("parry","huoyun-shou");
       	set_skill("moshenbu", i);
       	map_skill("dodge","moshenbu");

	who = this_object()->query_owner();
	if( !who )
		return;
	set_level(who->query_level());
	set("heal_up_time",1);
	set("time",who->query_skill("spells")/10);		
	set("env/msg_min",RED "只听啪！的一声，一团红光爆开，一个面目狰狞的牛虱掉到了地上。\n$N"RED"说道：我们是害虫，我们是害虫！\n" NOR);
	set("env/msg_mout",RED"$N"RED"说道：搞掂，回家吸血去咯！\n$N"RED"蹭的跳回到"+who->name()+RED"的身上去鸟。\n" NOR);
}

mixed hit_ob(object me, object target, int damage)
{
	string str;
	object who;
	if( !me || !living(me) )
		return 0;
	if( !target || !me->is_fighting(target) )
		return 0;
	who = me->query_owner();
	if( !who || !living(who) || !present(who,environment(me)) )
		return 0;
	if( who->query("mana")<10 )
		return 0;
	if( damage<10 )
		return 0;
	damage = damage/10;	
	if( who->receive_curing("kee",damage) )
	{
		me->add("time",-damage);
		return HIG"$N"HIG"吱吱乱叫，”"+who->name()+HIG"老大，小的给你吸到血了！“\n"NOR;
	}
	else if( who->receive_heal("kee",damage) )
	{
		me->add("time",-damage);
		return "$N吱吱乱叫，”"+who->name()+"老大，小的给你吸到血了！“\n"NOR;
	}	
	else	return 0;	
}