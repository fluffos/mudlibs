// shiwei.c 锦衣卫

inherit NPC;
#include <ansi.h>
#include "/d/beijing/autok.h"

int consider();

void create()
{
	string *skills = ({"kongling-jian", "fengyun-jian"});
	string *pfm = ({"blade.kuang", "claw.three", "claw.xiaofeng"});
	
        set_name(HIB"锦衣卫"NOR, ({ "jin yiwei", "jin", "wei" }));
        set("gender", "男性");
        set("age", random(20) + 20);
        set("str", random(20) + 20);
        set("dex", random(20) + 20);
        set("long", "这些人在京城侍卫中小有名气，武功也十分了得\n");
        set("combat_exp", 3000000 + random(7000000));
        set("shen_type", -1);
        set("attitude", "peaceful");
 
				set_skill("force", 100 + random(200));
				set_skill("dodge", 100 + random(200));
				set_skill("claw", 100 + random(200));
				set_skill("strike",100 + random(200));
				set_skill("parry", 100 + random(200));
				set_skill("blade", 100 + random(200));
				set_skill("sword", 100 + random(200));
        set_skill("throwing", 100 + random(200));
        
				set_skill("bixue-xinfa", 100 + random(200));
				set_skill("longfeng-xiang", 100 + random(200));
				set_skill("kuihua-zhua", 100 + random(200));
        set_skill("kuangfeng-dao", 200 + random(100));
//        set_skill("kongling-jian", 200 + random(100));
//        set_skill("wulong-quan", 100 + random(200));

        map_skill("dodge", "longfeng-xiang");
        map_skill("parry", "kuangfeng-dao");
        map_skill("force", "bixue-xinfa");
				map_skill("blade", "kuangfeng-dao");
//				map_skill("strike", "shizi-zhan");
				map_skill("claw", "kuihua-zhua");
	
//				prepare_skill("strike", "shizi-zhan");
				prepare_skill("claw", "kuihua-zhua");

        set("neili", 8400);
        set("max_neili", 8400);
        set("eff_jingli", 8200);
        set("max_jingli", 8200);
        set("jingli", 8200);
				set("max_qi", 5800);
				set("eff_qi", 5800);
				set("qi", 5800);

     		set("chat_chance", 100);
     		set("chat_msg", ({
                (: consider :),
                            }) );
                             							
     		set("chat_chance_combat", 100);
     		set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, pfm[random(2)] :),
                            }) );
        setup();
        carry_object("/d/beijing/dongchang/obj/xiuchundao")->wield();
        carry_object("/d/beijing/dongchang/obj/feiyufu")->wear();
}

void init()
{
		object me = this_player();
    auto_kill(this_player());
    if(me->query("class") == "officer" && me->query("pin") < 6)
    	message_vision("$n向$N致敬道：“大人好！卑职向大人请安！”\n", me, this_object());
    if(me->query("class") == "eunuch" && me->query("pin") < 6)
    	message_vision("$n向$N致敬道：“公公好！卑职向公公请安！”\n", me, this_object());
}

/*
void kill_ob(object me)
{
   object ob;
   if(!this_object()->is_killing(me->query("id")))
   {
    ::kill_ob(me);
    if(objectp(ob = present("jin yiwei 2", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei 3", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei 4", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    }
}
*/

int consider()
{
	object me, room, *player;
	int i;
	
	me = this_object();
	room = environment(me);
	
	player = all_inventory(room);
	for(i = 0; i < sizeof(player); i++)
	{
		if(userp(player[i]) && player[i]->query_condition("bjkiller"))
			{
				kill_ob(player[i]);
				break;
			}
	}
	return 1;
}





