//  ada 阿二
 
inherit NPC;
 
void create()
{
	set_name("阿二", ({ "a er", "a" }));
//	set("nickname", "");
	set("long", 
        "金刚门的高手，一身外功出神入化，出手极其狠毒。\n");
	set("gender", "男性");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen", -15000);
	set("str", 35);
	set("int", 20);
      set("con", 35);
	set("dex", 27);
	
	set("max_qi", 6500);
	set("max_jing", 6500);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 120);
	set("combat_exp", 1500000+random(900000)); 
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.fumo" :),
         })); 
         set_skill("force", 180);
        set_skill("shenyuan-gong", 380);
         set_skill("dodge", 180);
  

        set_skill("shaolin-shenfa", 380);
        set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
        set_skill("parry", 170);
        set_skill("literate", 150);
//        set_skill("sword", 190);

      
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
  	map_skill("parry", "jingang-quan");
  	prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "/quest/guanfu/npc/npc.h"
