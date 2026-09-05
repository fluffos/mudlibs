inherit NPC;
//大内高手
#include <ansi.h>
#include "autok.h"
void auto_perform();
void heal();

void create()  
{  
	string weapon;
	set_name(HIC"大内高手"NOR, ({ "danei gaoshou","gaoshou" }));
	set("gender", "男性");
        set("age", random(20) + 20);
        set("shen", -100000);
        set("str", 20+random(15));
        set("dex", 20+random(15));
     set("long",HIW"这就是朝廷的鹰犬。为人及其心狠手辣\n他们负责看守风波亭,对擅闯风波亭的人格杀勿论,这种人还是少惹为妙!\n"NOR);
        set("combat_exp", (random(10)+1)*1000000);
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
        
        set("inquiry",([
                "风波亭"  : ("问这个干什么?快滚!"),
                "岳飞"  : ("再废话,小心我宰了你!!"),
        ]));
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("chat_chance", 4);
        set("chat_msg", ({
"秦臣相有命令,擅入风波亭者,死!.\n",
"滚开滚开!不要命了?\n",
"你再不滚,小心我对你不客气!\n",
	        (: heal :),
	        (: heal :),
	        (: heal :),
	        (: heal :),
        }) );

        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/yuewangmu/obj/tiejia")->wear();

}

void init()
{
	object ob=this_player();
	::init();
if(present("wumu yishu",ob))
{
 message_vision (HIW"大内高手见喝道:啊,武穆遗书?大胆!竟敢私藏反书!赶快拿下!\n"NOR,ob);
//   call_out("kill_ob",1,ob);
this_object()->kill_ob(ob);
}

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