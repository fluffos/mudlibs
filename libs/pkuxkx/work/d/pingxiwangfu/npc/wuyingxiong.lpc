//made by goodtaste
// date: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
void re_rank(object);   

void create()
{
        set_name("吴应雄", ({ "wu yingxiong" , "yingxiong","wu"  }));
set("title",GRN"无根公子"NOR);
	set("long",
	"他是一个长的象女人的花花公子，他是平西王吴三桂的儿子\n"
         );
	
	set("gender", "男性");
	set("age", 27);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 19);
	set("con", 20);
	set("dex", 20);
	set("per", 20);
        set("qi", 400);
	set("max_qi", 400);
	set("max_jing", 100);
        set("max_jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 80000);
	set_skill("sword",60);
        set_skill("force", 70);
set_skill("pixie-jian",81);
	set_skill("xiantian-gong", 70);
	set_skill("dodge", 70);
	set_skill("fx-step", 70);
	set_skill("literate",80);

        map_skill("sword","pixie-jianfa");
	map_skill("dodge","fx-step");
	map_skill("parry","pixie-jianfa");
	map_skill("force","xiantian-gong");
        set_temp("apply/attack", 70);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 70);
	set("inquiry", ([
			
  "公主" :"她有我漂亮吗? 哼...",
	        "韦小宝" :"我一定要宰了这个小子!!\n",
               
	]) );
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
         "吴应雄转过身去，却又偷偷的回头看了你一眼，好象含情脉脉哦.....\n",
        }) );

	
	carry_object("/d/city/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}



