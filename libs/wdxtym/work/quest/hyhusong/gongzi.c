inherit NPC;
#include <ansi.h>
string *npc_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
void create()
{
	set_name(npc_name[random(sizeof(npc_name))]+"公子", ({"gong zi","zi","gongzi"}));
	set("nickname", HIY"官宦子弟"NOR);
	set("gender", "男性");
	set("age", 21+random(9));
 	set("attitude", "peaceful");
	set("per", 20);
	set("no_get", 1);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set("qi", 30000);
	set("max_qi", 30000);
	set("jing", 18500);
	set("max_jing", 18500);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 1);
	
	set("combat_exp", 80000);
	set("score", 200000);
	 
	set_skill("dodge", 300);		// 基本内功
	set_skill("force", 100);		// 基本内功
	set_skill("huntian-qigong", 100);	// 混天气功
	set_skill("unarmed", 100);		// 基本拳脚
	set_skill("xianglong-zhang", 100);	// 降龙十八掌
//	set_skill("dodge", 200);		// 基本躲闪
//	set_skill("xiaoyaoyou", 300);		// 逍遥游
	set_skill("parry", 300);		// 基本招架
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	
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

}

void unconcious()
{            
	::die();       
}	

int do_finish()
{	object ob,player;
    int exp,pot,base_exp,add_exp,count,i;
    ob=this_object();
	player=this_player();
	if (ob->is_fighting())
	return 0;
	if(player->query_temp("hu_song")
	&&ob->query_temp("host")==player->query("id")
	&&environment(ob)->query("short")==ob->query_temp("target"))
	{command("bye");
	 count=ob->query_temp("count");
	 if (count<=1) 	
	 { exp=660+random(880);
	   pot=exp/2+random(500);
       player->add("potential",pot);
       player->add("combat_exp",exp);
       player->delete_temp("hu_song");
       player->apply_condition("husong_busy",0);
	   tell_object(player,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
	   destruct(ob);
		return 1;
	 }	
		
		base_exp=300+random(600)+count;
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
		     exp=base_exp+random(50);//add_exp;
		     pot=exp/2+random(50);
             team[i]->add("potential",pot);
             team[i]->add("combat_exp",exp);
			 tell_object(team[i],HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
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
	if(objectp(present("killer", environment(this_object()))))
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

