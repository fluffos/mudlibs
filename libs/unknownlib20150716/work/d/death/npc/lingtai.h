#include <ansi.h>

void unconcious()
{
	object me = this_object();
	if( query("eff_kee") < this_object()->query_maxkee() )
		QUEST_D->addEffKee(me);
	if( query("kee") < query("eff_kee") )
        	QUEST_D->addKee(me);
	if( query("sen") < query("eff_sen") )
        	QUEST_D->addSen(me);
	if( query("eff_sen") < this_object()->query_maxsen() )
        	QUEST_D->addEffSen(me);
        if( query("kee")<1 || query("sen")<1 
         || query("eff_kee")<1 || query("eff_sen")<1 )
	{
		die();
		return;
	}
}

void die()
{
	object who;
	if( environment() )
	{
		message("vision","\n"+name()+"大喝一声：可恼，浑浑噩噩数年，一朝灵台清明，却落得如此下场！ \n",environment() );
		message("vision",name()+"惨叫一声，顿时化作一道青烟消失不见了。\n\n",environment() );
	}
	who = query_temp("last_damage_from");
	if( !who || !query("owner_ob") || who!=query("owner_ob") )
	{
		destruct(this_object());
		return;
	}
	who->add_temp("pendding/fc_visite_hellsha",1);
	tell_object(who,HIY"【灵台观礼】你成功助地藏菩萨度灭一个孤魂野鬼。\n"NOR);
	if( who->query_temp("pendding/fc_visite_hellsha")>=6 )
		tell_object(who,HIY"【灵台观礼】你完成了地藏菩萨交代的任务，可以请他参加灵台观礼了。\n"NOR);
	destruct(this_object());
}