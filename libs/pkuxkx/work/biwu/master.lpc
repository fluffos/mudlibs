#include <ansi.h>

inherit NPC;
int ask_rumor();
int ask_reward();
int ask_family_repute();
int ask_family_dadizi();
int ask_biwu_records();
string ask_canguan();

string* rumors = ({
    "ICER从来都没有用服务器下过A片，他只看日本动作文艺片。",
    "PICEWOLF有七个老婆。",    
    "降龙十八掌其实是十九掌，第十九掌失传了。",    
    "铁掌峰上下隐藏了两个秘密，不过不是机缘极好，就算武功天高也没机会。",    
    "其实少林还是比武当要强不少的。",        
});
void create()
{	
	set_name("天天好味道", ({ "jason npc", "goodtaste" }) );
	set("title", HIY "武林大会主持" NOR);
	set("gender", "男性" );
	set("age", 22);
	set("long", "他就是武林大会的主持，有什么不明白的可以问他。\n");

	set("str", 99);
	set("con", 99);
	set("int", 99);
	set("dex", 99);

	set("max_qi", 600000);
	set("max_jing", 600000);
	set("neili", 600000);
	set("max_neili", 600000);	

	set_temp("apply/attack",  2000);
    set_temp("apply/dodge",  2000);	
	set_temp("apply/defense", 2000);

	set("combat_exp", 1000000000);

	set_skill("force", 2000); 
	set_skill("unarmed", 2000);
	set_skill("sword", 2000);
	set_skill("dodge", 2000);
	set_skill("parry", 2000);
	set_skill("taiji-quan", 2000); 
	set_skill("taiji-jian", 2000); 
	set_skill("taiji-shengong", 2000); 
	set_skill("tiyunzong", 2000);

	map_skill("force", "taiji-shengong");
	map_skill("unarmed","taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("dodge", "tiyunzong");
    
    set("inquiry", ([
            "name" : "我年轻的时候还有一个名字叫残叶。",
            "rumors" : (:ask_rumor:),            
            "奖励" : (: ask_reward :),
            "reward" : (: ask_reward :), 
		    "门派威望" : (: ask_family_repute :), 
			"掌门大弟子" : (: ask_family_dadizi :), 
			"比武战况" : (: ask_biwu_records :), 
           "参观比武"   : (:ask_canguan:),	      
        ]) );

	set("chat_chance",2);
	set("chat_msg",({
		"请用help task-mpbiwu学习如何参加门派比武。\n",
		"掌门大弟子权利极大，仅次于掌门人。\n",
	}));
            	
	setup();		        
}

int ask_family_repute()
{
	string* fams;
	int i;
	fams = FAMILY_D->get_repute_top(100);
	write(HIY"                北大侠客行门派威望排行榜\n"NOR);
	for(i=0;i<sizeof(fams);i++)
	{
		write("        ");
		if(i<3)
		{
			write(BRED+HIY);
		}
		else
		{
			write(HIW);
		}
		write(sprintf("天下第%-10s %-15s %d",chinese_number(i+1),fams[i],FAMILY_D->get_repute(fams[i])));
		write("\n"NOR);
	}
	return 1;
}

int ask_family_dadizi()
{
	mapping data;
	string* fams;
	int i;

	data = FAMILY_D->query("dadizi");
	if(!mapp(data))
	{
		command("say 宇宙初现，混沌未开。");
	}
	else
	{
		fams = keys(data);
		write(HIY"           天下门派掌门大弟子\n"NOR);
		for(i=0;i<sizeof(fams);i++)
		{
			write("        ");
			
			write(HIW);

			write(sprintf("%-15s %s(%s)",fams[i],FAMILY_D->get_dadizi_name(fams[i]),FAMILY_D->get_dadizi(fams[i])));
			write("\n"NOR);

		}
	}
	return 1;
}

int ask_rumor()
{
    int i = random(sizeof(rumors));
    if(random(10) == 0) 
    {
        command("say "+rumors[i]);
    }
    else
    {
        command("consider");
    }
    return 1;
}

int ask_reward()
{
    object pl = this_player();
    int exp,pot,rep;
    
    if(!pl->query("family_biwu/lastscore"))
    {
        command("?");        
    }
    else
    {
        if(pl->query("mud_age") > 86400 * 11)
        {
            command("say 你已经成年了，为门派争光是你的责任和荣耀，不要考虑个人的奖励了。");
            pl->delete("family_biwu/lastscore");
        }
        else
        {
            exp = pl->query("family_biwu/lastscore") * 5000;
            pot = pl->query("family_biwu/lastscore") * 2000;
            rep = pl->query("family_biwu/lastscore") * 200;
            exp = REWARD_D->add_exp(pl,exp);
            pot = REWARD_D->add_pot(pl,pot);
            rep = REWARD_D->add_rep(pl,rep);
            message_vision(sprintf("$N为门派立下了功劳，获得了%d点经验，%d点潜能和%d声望的奖励！\n",exp,pot,rep),pl);
            pl->delete("family_biwu/lastscore");            
        }
    }
    return 1;
}

int ask_biwu_records()
{
	int i=0;
	string* records;
	string data;
	data = "";
	if(this_player()->is_busy())
	{
		command("shake");
		return 1;
	}
	records = BIWU_D->getrecords();
	for(i=0;i<sizeof(records);i++)
	{
		data += records[i];
	}
	if(stringp(data) && sizeof(data) > 0)
	{
		this_player()->start_more(data);
	}
	else
	{
		command("say 天下太平。。。");
	}
	this_player()->add_busy(2);
	return 1;
}

string ask_canguan() 
{
	      object me=this_player();

        if (me->query_combatgrade() < 10)   
              {     
               tell_object(me, "你经验太低，看热闹很危险的！\n");      
               return "你的经验太低了。";  
             }
        else
        	  {     
                command("nod");   
                tell_object(me, "好好学习学习吧，以后参加门派比武也许有用。\n");                      
                message("vision","天天好味道在你眼前一拂袖，你发现自己来到了一座看台！ \n",me);        
                me->move("/biwu/kantai");  
                return ""; 
                           
              }     
}	

void unconcious()
{
    fullme();
}

void die()
{
    fullme();
}
