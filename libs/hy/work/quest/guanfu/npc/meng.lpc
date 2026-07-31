//  meng 孟正鹏
 
inherit NPC;
 
void create()
{
	set_name("孟正鹏", ({ "meng zhengpeng", "meng" }));
	set("nickname", "五凤刀掌门");
	set("long", 
        "五凤刀的掌门，一身刀法传说甚为了得。\n");
	set("gender", "男性");
	set("age", 52);
	set("attitude", "peaceful");
	set("shen", -5000);
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 480000); 
	 
         set_skill("force", 100);
         set_skill("hunyuan-yiqi", 100);
         set_skill("dodge", 120);
  

        set_skill("shaolin-shenfa", 100 + random(20));
        set_skill("cuff", 120 + random(20));
        set_skill("blade", 140);
        set_skill("wenjia-quan", 120);
        set_skill("parry", 140);
        set_skill("wenjia-daofa", 140);
        set_skill("literate", 90);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-daofa");
  	map_skill("blade", "wenjia-daofa");
        prepare_skill("cuff", "wenjia-quan");

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield();
  	add_money("silver", 20);
}
#include "/quest/guanfu/npc/npc.h"
