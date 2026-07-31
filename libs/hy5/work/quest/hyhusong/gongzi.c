inherit NPC;
#include <ansi.h>
string *npc_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
#include "/quest/givegift.c"
string ask_huijia();

void create()
{
	set_name(npc_name[random(sizeof(npc_name))]+"公子", ({"gong zi","zi","gongzi"}));
	set("nickname", HIY"官宦子弟"NOR);
	set("gender", "男性");
	set("age", 21+random(9));
 	set("attitude", "peaceful");
	set("per", 20);
	set("no_get", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 35);
	set("qi", 39000);
	set("max_qi", 39000);
	set("jing", 39500);
	set("max_jing", 39500);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	
	set("combat_exp", 80000);
	set("score", 200000);
	         set("inquiry", ([
        "护送" : (:ask_huijia:) ,
        "start" : (:ask_huijia:) ,        
         ]) );
	set_skill("dodge", 300);		// 基本内功
	set_skill("force", 100);		// 基本内功
	set_skill("huntian-qigong", 100);	// 混天气功
	set_skill("unarmed", 100);		// 基本拳脚
	set_skill("xianglong-zhang", 100);	// 降龙十八掌
//	set_skill("dodge", 200);		// 基本躲闪
//	set_skill("xiaoyaoyou", 300);		// 逍遥游
	set_skill("parry", 300);		// 基本招架
		set_temp("apply/defense",150);
	set_temp("apply/armor",1500);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	//carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	add_action("do_finish", "finish");
	add_action("do_go", "go");
	add_action("do_guard", "halt");
    if(this_player()->query("id")==this_object()->query_temp("host"))
//	this_object()->interrupt_me();
	this_player()->start_busy(1);
call_out("do_back", 800,  this_object());  
}

string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

	
if(me->query("id")!=ob->query_temp("host") )
return "我不需要你护送。\n";

set_leader(me);
ob->set_leader(me);
return "多谢大侠护送我去目的地.\n";
}

void unconcious()
{ 
	object me;
if(objectp(present(this_object()->query_temp("host"), environment(this_object()))))
{
	me=present(this_object()->query_temp("host"), environment(this_object()));
	 me->clear_condition("hu_song");
	 me->apply_condition("zzz_busy",30);
         me->apply_condition("menpai_busy",30);
}	           
	::die();       
}	

int do_finish()
{	object ob,player;
    int exp,pot,base_exp,add_exp,count,i,j;
    ob=this_object();
	player=this_player();
	if (ob->is_fighting())
	return 0;
	if(player->query_temp("hu_song")
	&&ob->query_temp("host")==player->query("id")
	&&environment(ob)->query("short")==ob->query_temp("target"))
	{command("bye "+player->query("id"));
	 count=ob->query_temp("count");
	 if (count<=1) 	
	 { exp=600+random(100);
	   //pot=exp/2+random(500);

exp=exp/2+108;




addnl(player,"exp",exp);  
player->add_temp("mpjobn7",1);
       player->delete_temp("hu_song");
       player->apply_condition("husong_busy",0);
//player->apply_condition("menpai_busy",3);
player->apply_condition("hu_busy",0);
player->clear_condition("hu_song");
	   destruct(ob);
		return 1;
	 }	
		
		base_exp=700+random(100)+count;
		team=player->query_team();
		count=sizeof(team);
		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("husong_busy")
			&& environment(player)==environment(team[i]))
			{//if(!team[i]->query("zzz_job_count"))
		     //team[i]->set("zzz_job_count",1);
             //else
                    team[i]->delete_temp("hu_song");
                    team[i]->apply_condition("husong_busy",0);
		     //team[i]->add("zzz_job_count",1);  
			 //add_exp=team[i]->query("zzz_job_count")/10;
		     exp=base_exp+random(20);//add_exp;
		     pot=exp/2+random(20);
exp=exp/2+158;
addnl(team[i],"exp",exp);  
team[i]->add_temp("mpjobn7",1);
team[i]->clear_condition("hu_song");
//team[i]->apply_condition("menpai_busy",3);
			} 
		}
	 	}
	 destruct(ob);
	 return 1;
	}
     
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用halt！\n");
        return 1;
}

int do_go(string arg)
{
	if(this_player()->query_temp("hu_song")==1)
{
	if(objectp(present(this_player()->query("id")+" killer", environment(this_object()))))
	{
        write(this_object()->query("name")+"，的附近还有杀手，你不能走！\n");
        return 1;
//	obj->kill_ob(present("gong zi",environment(this_player())));
// 	present("gong zi",environment(this_player()))->kill_ob(obj);
// 	present("gong zi",environment(this_player()))->start_busy(6);
//        obj->set_leader(present("gong zi",me));
//        obj->kill_ob(present("gong zi",me));
 	}
}
}

              
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"突然有事，匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}             