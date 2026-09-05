// 杀手
// created by Zine 30 Sep 2010

inherit NPC;
#include <ansi.h>
#include <random_name.h>

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
	set("gender", "男性" );
	set("long", "这是一个朝廷派来暗杀铁匠的凶手。\n");
	set("str", 30);
	set("int", 30);
	set("dex", 30);
	set("kar", 30);       
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("eff_jingli", 5000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 10);
    set("random_npc",1);
	set("shen_type", 1);
    set("env/wimpy", 1);
	set("combat_exp", 3000000);
    set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("force",300);
	set_skill("claw",300);
	set_skill("longfeng-xiang",300);
	set_skill("bixue-xinfa",300);
	set_skill("kuihua-zhua",300);
	set_skill("kuangfeng-jian",300);
	set_skill("sword",300);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("claw", "kuihua-zhua");
	map_skill("parry", "kuihua-zhua");
	map_skill("sword", "kuangfeng-jian");
	prepare_skill("claw", "kuihua-zhua");
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/sword/qingfeng")->wield();
	call_out("dest",100,this_object());
}

void init()
{
	add_action("do_follow","follow");
	if(!query("is_killing_tj"))
	{
		this_object()->killtj();
	}
}

int start_busy(int busy) 
{return 0;}

int add_busy(int busy) 
{return 0;}

int killtj()
{
	
    object tj=present("tie jiang",environment());
	set("is_killing_tj",1);
    if (tj)
    {
        if (this_object()->query("killed"))
        {
            command("follow tie jiang");
            kill_ob(tj);
            return 1;
        }
        else
        {
            message_vision(RED+this_object()->query("name")+"大喝一声，开始对铁匠出手了！\n"NOR,this_object());
            this_object()->set("killed",1);
            command("follow tie jiang");
            kill_ob(tj);
            return 1;
        }
    }
    else
    {
        command("find");
        random_move();
    }
    remove_call_out("killtj");
    call_out("killtj",2);
	delete("is_killing_tj");
}


int dest()
{
	tell_room(environment(),this_object()->query("name")+"一闪身就不见了。\n");
	destruct(this_object());
	return 1;
}

int do_follow(string arg)
{
    object me=this_player();
    if (!arg)
    {
        tell_object(me,"你要跟随谁？\n");
        return 1;
    }
    else
    {
        if (arg=="tie jiang")
        {
            tell_object(me,"杀手来去如风，跑得飞快，你根本追不上！\n");
            return 1;
        }
    }
}