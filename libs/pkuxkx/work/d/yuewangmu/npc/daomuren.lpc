inherit NPC;
//盗墓高手
#include <ansi.h>

void auto_perform();
void heal();
string kill_you();
void create()  
{    
	string weapon;
	   set_name(HIC"盗墓高手"NOR, ({ "daomu gaoshou","gaoshou" }));
	set("gender", "男性");
        set("age", random(10) + 50);
        set("shen", -50000);
        set("str", 85);
        set("dex", 96);
        set("long",HIW"此人以盗墓为生,身怀盗墓绝技,传说此人是侠客岛上的弃徒。\n这种人还是少惹为妙!\n"NOR);
        set("combat_exp", random(3000000) + 5000000);
        set("shen_type", -1);
        set("attitude", "heroism");

        set_skill("unarmed", random(200)+200);
        set_skill("force", random(200)+200);
        set_skill("strike", random(200)+200);
        set_skill("xiake-quanjiao", random(200)+100);
        set_skill("dodge", random(200)+200);
        set_skill("parry", random(200)+200);
        set_skill("xiake-strike", random(200)+100);
        set_skill("xiake-jianfa", random(200)+100);
        set_skill("xiake-daofa", random(200)+100);
        set_skill("xiake-shenfa", random(200)+100);
        set_skill("xiake-shengong", random(200)+100);

        map_skill("unarmed", "xiake-quanjiao");
        map_skill("strike", "xiake-trike");
        map_skill("sword", "xiake-jianfa");
        map_skill("blade", "xiake-daofa");
        map_skill("parry", "xiake-jianfa");
        map_skill("force", "xiake-shengong");
        map_skill("dodge", "xiake-shenfa");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 150);

   prepare_skill("unarmed","xiake-quanjiao");
   prepare_skill("strike","xiake-strike");

        set("neili", 8000); 
        set("max_neili", random(3000)+2000);
      set("max_qi",random(2000)+2000);
      set("max_jing",random(1000)+1000);
	  set("jingli",2000);
      set("max_jingli",2000);
        set("jiali", random(200)+100);

		set("env/wimpy",60);
        
        set("inquiry",([
                "盗墓"  : (: kill_you :),
        ]));
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("chat_chance", 8);
        set("chat_msg", ({
"听包打听说岳家枪还在人世,看来最近又要好好干一票了.\n",
"不过包打听那小子也太黑了,就这么点消息收了我那么多银子!哼!\n",
"要不我在这里等,等到看有谁盗了岳王的墓,我在这里杀他抢枪谱,以我的身手,嘿嘿....\n",
	        (: heal :),
	        (: heal :),
	        (: heal :),
	        (: heal :),
        }) );
        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/yuewangmu/obj/tieqiao");
        carry_object("/d/yuewangmu/obj/tiejia")->wear();
//        carry_object("/d/yuewangmu/obj/tieqiao");

}

void init()
{
	object ob=this_player();
	::init();
if(ob->query_skill("yuejia-qiangfa")>0)
{
 message_vision (HIW"盗墓高手见$N居然会岳家枪法,顿生歹意,喝道:啊,你居然会岳家枪?是盗墓来的吧?快把枪谱给我!\n"NOR,ob);
   call_out("kill_you1",10,ob);
// command("kill "+ob->query("id"));
}

}


string kill_you()
{
        object me,ob,room,thisplayer;
	me=this_player();
	ob=this_object();
room=load_object("/d/yuewangmu/xiaodao3");
 if( !objectp( thisplayer = present(me->query("id"), room) ))
return("");
	ob->kill_ob(me);
	me->kill_ob(ob);
return (HIR"你是官府来的么?那咱们就来个你死我活吧!"NOR);
}

int kill_you1(object me)
{
object ob,room,thisplayer;
	
		if (!me) return 1;
        ob=this_object();
room=load_object("/d/yuewangmu/xiaodao3");
if( !objectp( thisplayer = present(me->query("id"), room) ))
return 1;
        ob->kill_ob(me);
        me->kill_ob(ob);
message_vision (HIR"不肯给?那我就抢了!\n"NOR,me);
return 1;
}
 
void auto_perform()
{
		object me = this_object();
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
		command("exert powerup");

		if ( !objectp(target) ) return 0;
		if (me->query("qi") < me->query("eff_qi"))      
 		command("exert recover"); 
 		if (me->query("jing") < me->query("eff_jing"))  
		command("exert regenerate");  

		if (random(5)==1)
		{

            command("unwield blade");
            command("unwield jian");
            command("perform sword.feijian " +target->query("id"));
            command("wield jian");
            command("wield blade");

		}
}

void heal()                                             
{                                                       
	object ob=this_object();                        
	                                                
	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{                                               
		command("exert heal");                  
		command("enforce 200");                 
		return;                                 
	}                                               
                                                        
	if (ob->query("qi") < ob->query("eff_qi"))      
	{                                               
		command("exert recover");               
		return;                                 
	}                                               
                                                        
	if (ob->query("jing") < ob->query("eff_jing"))  
	{	command("exert regenerate");            
                                                        
               return;
               }    
       
}

