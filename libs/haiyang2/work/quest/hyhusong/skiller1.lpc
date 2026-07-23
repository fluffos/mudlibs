#include <ansi.h> 
inherit NPC;
 
void create()
{
	set_name("杀手", ({ "killer"}));
	set("gender", "男性");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -18000);
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3500);
	set("max_neili", 3500);
        set("jiali", 100);
	set("combat_exp", 10000);
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "finger.dianxue" :),
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
 
         }));
         set_skill("force", 280);
         set_skill("canhe-zhi", 280);
         set_skill("dodge", 200);
         set_skill("murong-jianfa", 280);
         set_skill("parry", 280);
        set_skill("shaolin-shenfa", 180);
        set_skill("finger", 280);
        set_skill("shenyuan-gong", 380);
        set_skill("literate", 250);
        set_skill("sword", 290);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "canhe-zhi");
        map_skill("sword", "murong-jianfa");
  	map_skill("parry", "murong-jianfa");
 
        prepare_skill("finger", "canhe-zhi");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield(); 
        add_money("silver", 20);
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	add_action("do_guard", "halt");
	add_action("do_guard", "guard");

	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
if( userp(ob[i]) && ob[i]->query("combat_exp") < 80000) continue;
if(!ob[i]->query_temp("hu_song")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
                set_leader(present("gong zi",ob[i]));
        }
}
#include "killer.h"
