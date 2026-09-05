//Zine 艄公，长江边收钱的，钱多船就快
#include <localtime.h>
inherit NPC;
#include <ansi.h>
int ask_river();
#include "die.h"
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1],"shao gong"}));	
        set("title", color[random(sizeof(color))]+"老艄公"+NOR);
        set("gender", "男性");
        set("age", 60+random(10));
        set("str", 20);
        set("dex", 20);
        set("long", "他是黄河边的老艄公，撑渡船几十年了。\n");
        set("combat_exp", 2000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("random_npc",1);
        set_skill("unarmed", 10);
        set_skill("force", 10);
        set_skill("sword", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);

        set("neili", 200); 
        set("max_neili", 200);
        set("jiali", 1);
        set("inquiry", ([
            
            "过河" : (: ask_river :),
			"huanghe" : (: ask_river :),
           
		]) );
        set("shen_type",1);set("score",200);setup();
       	carry_object("/clone/armor/cloth")->wear();
}

void destroy(object ob)
{
        if(ob) destruct(ob);
        return;
}

void kill_ob(object ob)
{
      ob->remove_killer(this_object());
      remove_killer(ob);
}

int ask_river()
{
    object who=this_player();
    int amount;
    object room=environment(who);
    mixed* timeinfos;
    int wday;
    object statistic;
    string moneygiven;
    timeinfos = localtime(time());
    wday = timeinfos[LT_WDAY];
    if (room)
    {
        amount=room->query("boatvalue");
    }
    if (wday==6||wday==7)
    {
        amount=amount*(2+random(2));
    }
    if (time()<1327939199&&time()>1327161661)
    {
        amount=1;
    }
    if (time()<who->query("river_pass"))
	{
		tell_object(who,this_object()->query("name")+"道：你老人家快请上船。\n");
        command("yell boat");
		return 1;
	}
    else if (MONEY_D->player_pay(who,amount))
    {
        statistic=load_object("/d/changjiang/cjn1");
        statistic->add("hh_income",amount);
        statistic->add("hh_guest",1);
        moneygiven=MONEY_D->money_str(amount);
		tell_object(who,this_object()->query("name")+"接过你递给的船资"+moneygiven+"。\n");
        command("welcome " + who->query("id"));
        who->set_temp("hhallowed",room->query("ticket"));
        tell_object(who,this_object()->query("name")+"道：你老人家快请上船。\n");
        command("yell boat");
        return 1;
    }
    else
    {
        command("hate " + who->query("id"));
        tell_object(who,this_object()->query("name")+"道：没钱？没钱怎么坐船？\n");
        return 1;
    } 
}

int accept_object(object me,object ob)
{
	if (ob->query("is_river_pass")&&ob->query("valid_period"))
	{
		message_vision("$N接过$n手中的"+ob->query("name")+"。\n",this_object(),me);
		if (me->query("river_pass")<time())
		{
			me->set("river_pass",time()+ob->query("valid_period"));
		}
		else
		{
			me->add("river_pass",ob->query("valid_period"));
		}
		command("say "+me->query("name")+"，在"+ctime(me->query("river_pass"))+"之前，你在长江黄河乘船都不用给钱了。");
		set("uni_target",1);
		call_out("destory",1,ob);
		return 1;
	}
	return notify_fail("");
}