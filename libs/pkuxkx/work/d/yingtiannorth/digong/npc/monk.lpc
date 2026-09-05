// By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();


void create()
{
	set_name("老和尚", ({ "lao heshang","heshang","monk"}));
        
	set("long",
	"他是一个老和尚，胡子眉毛全白了。\n"
         );
	set("gender", "男性");
	
	set("age", 100);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
	set("qi", 1000);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000);
	
    set("inquiry", ([
			"六层" : (: ask_quest :),
            "six" : (: ask_quest :),
            
       	]) );    
        setup();
        carry_object("/d/shaolin/npc/obj/xuan-cloth")->wear();
	

}
int ask_quest()
{
	int word=0,count=1;
	object *players,rm=load_object("/d/yingtiannorth/digong/level5path4"),me=this_player();
	string *passwds=({"唵","嘛","呢","叭","咪","吽"}),tmp,passwd="";
	if (!rm)
	{
		command("say 报错啦，快去找巫师。");
		return 1;
	}
	if (rm->query("passwd"))
	{
		command("say 我已经告诉过你们了。");
		return 1;
	}
	while (sizeof(passwds)>0)
	{
		tmp=passwds[random(sizeof(passwds))];
		passwd+=tmp;
		passwds-=({tmp});
	}
	if (environment(me)->query("player_num")<6)
	{
		command("say 至少要六个人在场，才能传法诀。");
		return 1;
	}
	players=all_inventory(environment(this_object()));
	players=filter(players,(:userp:));
	players=filter(players,(:living:));
	if (sizeof(players)<6)
	{
		command("say 至少要六个人在场，才能传法诀。");
		return 1;
	}
	rm->set("passwd",passwd);
	for (int i=0;i<sizeof(players);i++)
	{
		if (word<12)
		{
			command("whisper "+players[i]->query("id")+" "+"第"+chinese_number(count)+"个字是"+passwd[word..word+1]);
			word+=2;
			count+=1;
		}
		else
		break;
	}
	command("buddhi");
	return 1;
}