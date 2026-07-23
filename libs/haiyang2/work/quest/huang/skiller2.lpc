#include <ansi.h>
 
inherit NPC;
 
void create()
{
	set_name("强盗", ({ "robber"}));

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
         set_skill("force", 180);
         set_skill("hunyuan-yiqi", 180);
         set_skill("dodge", 180);
         set_skill("shaolin-shenfa", 180);
         set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
         set_skill("parry", 170);
         set_skill("literate", 150);
        set_skill("xue-dao", 150);



        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
         set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 220);
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("chat_chance_combat", 20);  
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
        add_money("gold", 1);
}
#include "killer.h"
