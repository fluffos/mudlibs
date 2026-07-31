#include <ansi.h>
inherit NPC;

string ask_huijia();
string ask_daojia();
#include "/quest/menpai/givegift.c"
void create()
{
   set_name("武林人物",({"wulin renwu"}));
   set("long","武林人物，被人追杀!\n");
   set("score",5000);
   set("combat_exp",160000);
set("str",35);   
set("dex",35);   
set("per",random(20)+10);
set("age",random(30)+14);
        set("attitude", "friendly");
if (random(2)==0)
        set("gender", "女性");
else      set("gender", "男性");
        set("age", 12);
	set("no_get", 1);
   set("jing",12800);
   set("max_jing",12800);
set("env/wimpy", 40);
   set("qi",12800);
   set("max_qi",12800);
set("isteamjob",1);
set("moveok",1);
set("no_get",1);
set("food",550);
set("water",550);
   set("neili",5000);
   set("max_neili",5000);
   //set("force_factor",10);
        set("inquiry", ([
        "到达" : (:ask_daojia:) ,
        "over" : (:ask_daojia:) ,
         ]) );
   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("whip",120);

   setup();

carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        object ob = this_object();

if(ob->query("hsr")==this_player()->query("id") )
	this_player()->start_busy(1);
        remove_call_out("leave");
        call_out("leave",1200);

}



void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIG "武林人物自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}


string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
	int i;
	object fang,who,where;
        int count,add_exp;
        object *team,boss;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);

if (ob->query("hsr")!=me->query("id"))
		return "你是谁啊，我不认识你! \n"; 

 if( environment(ob)->query("short")==ob->query("hstarget")
 || domain_file(base_name(environment(ob)))==ob->query("hsfile")
 )
         {
          set_leader(0);


        fang = present("sha shou",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败强敌吧。\n",this_object(),who);
		return "小心了! \n";  
	}

        fang = present("boss killer",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败强敌吧。\n",this_object(),who);
		return "小心了! \n";  
	}

      if(!query("iskillok") && (random(20)==0 || wizardp(me)))
      {
      message_vision("突然突然杀进一个武林高手 对$n说道： 把你的小命交出来吧!\n",this_object(),who);	
      	fang = load_object(__DIR__"boss");
	fang->move(environment(who));	
	fang->initlvl(me->query_skill("force",1)+50);
        fang->set("combat_exp",me->query("combat_exp",1));
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (!i) i=1;
        fang->set("qi",fang->query("max_qi")*i);
        fang->set("eff_qi",fang->query("max_qi")*i);
        fang->set("max_qi",fang->query("max_qi")*i);

        fang->set("jing",fang->query("max_jing")*i);
        fang->set("eff_jing",fang->query("max_jing")*i);
        fang->set("max_jing",fang->query("max_jing")*i);

        fang->set("neili",fang->query("max_neili")*i);
        fang->set("max_neili",fang->query("max_neili")*i);
      
        
        fang->set("str", me->query("str"));
        fang->set("dex", me->query("dex"));
        fang->set("per", me->query("per"));
        
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return "小心了! \n";  
      }	
          write("终于安全了，多谢相送.\n");
  count=me->query_temp("team_count");
		if (count<2) count=2;	
               
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
if (!count)
{
		     exp=random(1888)+1888;
		     pot=exp*2/3+random(200);


me->clear_condition("mjb2_busy");		
me->clear_condition("mp2_kill");
me->delete("quest");
me->delete("task_time");
me->delete("mjb2job");
me->delete_temp("team_count");	
addnl(me,"exp",exp);
if (random(3)==0) addnl(me,"mpgx",1);
}	
if (count>1)
{
		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("mjb2_busy"))
			{ 
			 add_exp=100;
		     exp=random(1888)+1888;
		     pot=exp*2/3+random(200);
		     team[i]->delete_temp("team_count");
             if (environment(me)==environment(team[i])) addnl(team[i],"exp",exp);
 		       

team[i]->clear_condition("mjb2_busy");		
team[i]->clear_condition("mp2_kill");
team[i]->delete("quest");
team[i]->delete("task_time");
team[i]->delete("mjb2job");
team[i]->delete_temp("team_count");
			}
			} 
		}

}		  		


        call_out("leavet",1);
	  
           return "咱们就此分别吧! \n";  
      }
        else {
                return "还没到"+ob->query("hstarget")+"呢!你想不管了吗?\n";
        }
}



void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	