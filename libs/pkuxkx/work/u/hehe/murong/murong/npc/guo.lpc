//guo.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("过彦之", ({ "guo yanzhi", "guo"}));
    set("gender", "男性");
    set("age", 30);      
	set("title",WHT"追魂手"NOR);
	set("str", 25);
    set("int", 26);
    set("con", 26);
    set("dex", 26);
    set("combat_exp", 50000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",1000);
    set("max_jing",1000);
    set("neili",1000);
    set("max_neili",1000);
	set("jiali",30);
	set("score", 8000);

	set_skill("cuff", 70);
	set_skill("parry",70);
	set_skill("yanling-shenfa",70);
    set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);
    set_skill("blade",70);
	
	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");
        
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);
//	carry_object(__DIR__"obj/shoes1")->wear();
//    carry_object(__DIR__"obj/cloth")->wear(); 
    setup();
     
}
