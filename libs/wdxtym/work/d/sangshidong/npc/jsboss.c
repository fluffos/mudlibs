#include <ansi.h>
inherit NPC;

//int skillk = 100 + random(200);

void create()
{
      set_name(HIW"尸王"NOR, ({ "shiwang"}));
	set("gender", "无性");
	set("age",26);
	set("long", "一只尸王。\n");
        set("attitude", "aggressive");
        set("no_update", 1);
        set("str", 3000 + random(1000));
        set("int", 3000 + random(1000));
        set("con", 3000 + random(1000));
        set("dex", 3000 + random(1000));
        set("kar", 3000 + random(1000));
	    set("shen_type", -1);
        set("qi", 10000000 + random(1000000));
        set("max_qi", 10000000+ random(1000000));
        set("jing", 100000000 + random(300000));
        set("max_jing", 10000000 + random(300000));
        set("neili", 20000000 + random(300000));
        set("max_neili", 20000000 + random(300000));
        set("max_jingli", 20000000 + random(300000));
        set("jingli", 12000000 + random(300000));
        set("jym_level/level",20);
        set("jiali", 5000 + random(150));
        set("combat_exp", 2000000 + random(30000));
        set_skill("force", 500 + random(1500));
        set_skill("dodge", 500 + random(1500));
        set_skill("parry", 500 + random(1500));
        set_skill("sword", 500 + random(1500));
        set_skill("unarmed", 500 + random(1500));
		set_skill("cuff", 500 + random(1500));		
        set_skill("yinyang-shiertian", 500 + random(1500));	 
        map_skill("unarmed", "yinyang-shiertian");   
        map_skill("dodge", "yinyang-shiertian");
        map_skill("parry", "yinyang-shiertian");
        map_skill("sword", "yinyang-shiertian");
        prepare_skill("sword","yinyang-shiertian");

        setup();
}
void init()
{
	object me,ob;
	::init();
	if (interactive(me = this_object()))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, me);
	}
}

void die()
{
         object nvh;//设置出现任务npc
         object ob =  this_object()->query_last_damage_from();
         object *players;
         int w,i;
		 int xiuwei;
		 int qianneng;
		  if(!objectp(this_object())) return;//如果 对象玩家不存在 停止
		 xiuwei =ob->query("combat_exp")/4000;//修为除以3000等于获得的修为
		 qianneng=(xiuwei/1000)*15;//潜能除以1000乘以15等于获得的潜能
		 

          ob->start_busy(1);
		 players = ob->query_team();
		 w = sizeof(players);
		 if (sizeof(ob->query_team()) >= 2)//组队人数大于等于2组队奖励
		 {
         
           for(i = 0; i<sizeof(players); i++)
         {
		 
         players[i]->add("combat_exp", xiuwei);//组队
		 players[i]->add("potential", qianneng);//组队	
		
		 tell_object(players[i],HIC"\n你获得了"+xiuwei+"点修为"+qianneng+"点潜能\n"NOR"\n");
		 
        
         }

		 }
	    else//否则
        //if (sizeof(ob->query_team()) > 1)
        {
      
		
		ob->add("combat_exp", xiuwei);//单人
		ob->add("potential", qianneng);//单人	
	
        tell_object(ob,HIC"\n你获得了"+xiuwei+"点修为"+qianneng+"点潜能\n"NOR"\n");
		
       
       
        }
        /*else
        {
         //players = users();
        // players->add("combat_exp", 10000);
		 tell_object(players,HIR"修为一万\n"NOR);
         }*/     
       ::die();
}
//函数：寻敌
/*void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;

	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);

	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}*/
