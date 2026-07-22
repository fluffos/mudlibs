#include <ansi.h>
inherit NPC;

void create()
{
	mapping name;
	name = NAME_D->random_name("male");
	set_name(name["name"],name["id"]);
	create_family("将军府",4,"");
	set_level(20+random(20));
	set("class","fighter");
	set("env/wimpy",0);
	set("title",({"齐","建",})[random(2)]+"王府老兵");
	set("long","一位"+query("title")+"，乃是王府残余的近身护卫。感恩旧主恩泽，不忍离去，就在醉星楼打理日常。\n"); 
	set("env/test",({"","","","HIY","HIB","HIR",})[random(5)]);
	setup();
}

void set_skills(object who)
{
	int j,level;
	if( !who )
		return;
	level = who->query_level();	
	if( level<this_object()->query_level() )
		level = this_object()->query_level();
	set_level(level);	
	j = level*10;
	j = level*4/5+random(level/5);	
        set_skill("unarmed", j);
        set_skill("dodge", j);
        set_skill("parry", j);
        set_skill("force", j);
        set_skill("spells", j);
 	switch(random(3))
 	{
        	case 0 :
        		set_skill("spear", j);
        		set_skill("bawang-qiang", j);
        		map_skill("spear","bawang-qiang");
        		map_skill("parry", "bawang-qiang");
        		carry_object(0,"spear",1)->wield();	
			break;
        	case 1 :
        		set_skill("axe",j);
        		set_skill("sanban-axe",j);
        		map_skill("axe","sanban-axe");
        		map_skill("parry", "sanban-axe");
        		carry_object(0,"axe",1)->wield();	
			break;
		default :
        		set_skill("bawang-qiang", j);
        		map_skill("parry", "bawang-qiang");
        		carry_object(0,"unarmed",1)->wield();	
			break;
	}		        		
        set_skill("yanxing-steps", j);
        set_skill("changquan", j);
        set_skill("lengquan-force", j);
        set_skill("baguazhou", j);

        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
	setup();
	carry_object(0,"armor",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"pifeng",1)->wear();
	carry_object(0,"kui",1)->wear();
	carry_object(0,"shoes",1)->wear();
	powerup(0,1);
}

int is_qinbing(){return 1;}

void cure_me()
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
}

void do_kill(object who)
{
	object me = this_object();
	remove_call_out("do_kill");
	cure_me();
	if( !who || !living(who) || !present(who,environment()) )
	{
		delete_temp("my_killer");
		this_object()->clear_condition();
		if( query("force")<query_maxforce()*2 )
			add("force",500);
		return;
	}
	if( me->is_fighting(who) )
		QUEST_D->randomPfm(me);
	call_out("do_kill",random(5),who);	
}

void kill_ob(object who)
{
	if( !userp(who) && who->is_qinbing() )
	{
		remove_killer(who);
		who->remoev_killer(this_object());
	}
	if( this_object()->is_fighitng() )
	{
		if( this_object()->is_fighitng(who) )
			return;
		else
		{
			message_vision("$N大骂道：泼娘贼，依仗人多？！老子不怕！\n",this_object());
			cure_me();
			if( query("force")<query_maxforce()*2 )
				add("force",500);
		}	
	}
	set_temp("my_killer",who);
	::kill_ob();	
	remove_call_out("do_kill");
	call_out("do_kill",random(5),who);
}