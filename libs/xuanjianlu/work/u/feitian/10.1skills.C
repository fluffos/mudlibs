// 国庆节武功大使

#include <ansi.h>

inherit NPC;

int ask_skills();

void create()
{
	set_name("国庆节大使", ({"guoqing dashi", "guoqing", "dashi"}));
	set("long", "过十一国庆节了，国庆节大使来为大家服务了，（skills）\n");
	
	set("gender", "男性");
	set("age", 50);
	set("shen_type", 1);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("inquiry", ([
	"国庆节奖励" : (:ask_skills:),
	]));
	
	setup();
	carry_object(__DIR__"xifu.c")->wear();
}

void init()
{
	object ob = this_player();
	
	::init();
	if (interactive(ob)) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
        {
        	return;
        }
        
        say(HIY"大使慈祥地说道：“" + RANK_D->query_respect(ob) + "国庆节快乐。“\n"NOR);
}

int ask_skills()
{
	object ob = this_player();
	int i;
	mapping skill_status;
	string *sname;
	
	if (ob->query("liwu/shiyi"))
	{
		say(CYN"国庆大使皱皱眉，说道：你已经问过了，大家都可以作证，还问什么？！\n"NOR);
		return 1;
	}
	else if (mapp(skill_status = ob->query_skills())) 
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			skill_status[sname[i]] = skill_status[sname[i]] + 20;
		}
		tell_object(ob, "你感觉变厉害了一点。\n");
		CHANNEL_D->do_channel( this_object() , "wiz", ob->query("name") + "(" + ob->query("id") + ")获得了国庆节奖励。\n");
	        ob->set("liwu/shiyi", 1);
	}
	
	
	
	return 1;
}
