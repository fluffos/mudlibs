#include <ansi.h>
inherit BHNPC;
 
void create()
{
	set_name("ÍÁ·Ë", ({ "tu fei","fei"}));
	set("gender", "ÄÐÐÔ");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -8000);
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
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duan" :),
         })); 
         set_skill("force", 100);
         set_skill("taixuan-gong", 140);
         set_skill("dodge", 120 + random(30));
  

        set_skill("piaomiao-shenfa", 140);
        set_skill("strike", 120 + random(30));
        set_skill("wuhu-duanmendao", 120 + random(30));
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "taixuan-gong");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("blade", "wuhu-duanmendao");
  	map_skill("parry", "wuhu-duanmendao");  	
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "killer.h"
