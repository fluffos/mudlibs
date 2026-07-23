//  wu 吴六破
 
inherit NPC;
 
void create()
{
	set_name("吴六破", ({ "wu liupo", "wu" }));
	set("nickname", "神箭八雄");
	set("long", 
        "原是武林中的巨寇，后来为躲避官府和仇家，随便起了个假名字。\n");
	set("gender", "男性");
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
	set("combat_exp", 500000); 
	  
         set_skill("force", 150);
         set_skill("xuantian-wuji", 150);
         set_skill("dodge", 150);
  

        set_skill("kunlun-shenfa", 150);
        set_skill("cuff", 140);
        set_skill("wenjia-quan", 150);
        set_skill("parry", 140);
        set_skill("murong-daofa", 150);
        set_skill("blade", 150);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("blade", "murong-daofa");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "murong-daofa");
  	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield(); 
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
