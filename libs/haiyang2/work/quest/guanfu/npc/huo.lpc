//  huo
// by dubei
 
inherit NPC;
 
void create()
{
	set_name("霍元风", ({ "huo yuanfeng", "huo" }));
	set("long", 
        "一个江湖大盗，极其凶残，一般武林人非常惧怕。\n");
	set("gender", "男性");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -8000);
	set("str", 38);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 6800);
	set("max_jing", 6800);
	set("neili", 6800);
	set("max_neili", 6800);
	set("jiali", 100);
	set("combat_exp", 700000); 
	  
         set_skill("force", 165);
         set_skill("xuantian-wuji", 365);
         set_skill("dodge", 160);
  

        set_skill("kunlun-shenfa", 165);
        set_skill("strike", 160);
        set_skill("jinshe-zhang", 160);
        set_skill("parry", 160);
        set_skill("murong-daofa", 160);
        set_skill("blade", 150);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("blade", "murong-daofa");
        map_skill("strike", "jinshe-zhang");
  	map_skill("parry", "jinshe-zhang");
  	prepare_skill("strike", "jinshe-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
     
        add_money("silver", 100);
}
#include "/quest/guanfu/npc/npc.h"
