//made by goodtaste
// data: 1998.12.11
// 借用平西王府的护院头npc。
               
#include <ansi.h> 
inherit NPC; 
void re_rank(object);   

void create()
{
	set_name("保镖", ({ "bao biao" , "bao", "biao" }));
        
	set("long",
	"他是鳌拜重金聘来的保镖，据说以前是武当派的弟子，因为
投靠鳌拜被赶出师门\n"
         );
	  set("chat_chance", 10);
        set("chat_msg", ({
          
"保镖说道:哪里来的狂徒，还不快快受死.\n"
        }));


	set("gender", "男性");
	set("age", 35);
	set("attitude", "aggressive");
	set("shen_type", -1);
        set("shen",-100);
  set("str",50);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
  set("qi",2500);
        set("jing",1200);
  set("max_qi",2500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
        set("combat_exp", 2200000);
        set_skill("sword",200);
 set("jiali",150);
        set_skill("taiji-jian",200);
        set_skill("force", 190);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 200);
        set_skill("tiyunzong",220);
        set_skill("parry", 200);
        map_skill("sword","taiji-jian");
	map_skill("dodge","tiyunzong");
	map_skill("parry","taiji-jian");
	map_skill("force","taiji-shengong");
        
        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}



