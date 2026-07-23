#include <ansi.h>
inherit NPC;

int do_copy(int flag);
int do_back(object me);

void create()
{
        string weapon;
        set_name("杀手", ({ "killer"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个满脸横肉的家伙。\n");
        set("combat_exp", 80000 + random(40000)); 
       set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("cuff", 250);
        set_skill("blade", 250);
//        set_skill("taizu-quan", 250);
// //       set_skill("qingmang-jian", 250); 
        set_skill("wind-blade", 80+random(180));
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
//        map_skill("cuff", "taizu-quan");
//        prepare_skill("cuff", "taizu-quan");         
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
                set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
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
