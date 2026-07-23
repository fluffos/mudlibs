#include <ansi.h>
inherit NPC;
 
void create()
{
	set_name("杀手", ({ "killer"}));
	set("gender", "男性");
	set("age", 36);
	set("attitude", "peaceful");
//	set("shen", -8000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 800000); 
         set_skill("force", 100);
         set_skill("xuantian-wuji", 140);
         set_skill("dodge", 280 + random(30));
  

        set_skill("huifeng-jian", 280);
        set_skill("kunlun-shenfa", 180);
        set_skill("strike", 220 + random(30));
        set_skill("kunlun-zhang", 320 + random(30));
        set_skill("parry", 340);
        set_skill("sword", 340);
        set_skill("linji-zhuang", 280);
        set_skill("literate", 280);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "strike.diezhang" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
 
        setup(); 
        carry_object("/clone/weapon/gangjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
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
