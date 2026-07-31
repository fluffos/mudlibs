#include <ansi.h>
 
inherit NPC;
 
void create()
{
	set_name("杀手", ({ "killer"}));

	set("gender", "男性");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen", -15000);
	set("str", 35);
	set("int", 20);
      set("con", 35);
	set("dex", 27);
	
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 10000); 
         set_skill("force", 280);
         set_skill("hunyuan-yiqi", 280);
         set_skill("dodge", 180);
         set_skill("shaolin-shenfa", 180);
         set_skill("cuff", 280);
         set_skill("jingang-quan", 210);
         set_skill("parry", 270);
         set_skill("literate", 250);
        set_skill("xue-dao", 250);



        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
	set("chat_chance_combat", 30);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "cuff.jingang" :),
	}) );
 	prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
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
