#include <ansi.h>

inherit NPC;
int about_he();
string summon_more(object me);

void create()
{
	set_name("裘逸", ({ "qiu yi","qiu" }));
	set("long",
	    "这是一个四十五六岁的中年人, 浓眉大眼,\n"+
	    "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
	    "他神色凛然.\n");
	set("title", HIR"南北双鹰"NOR);
	set("gender", "男性");
	set("age", 46);
	set("nickname", HIC "飞鹰" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

        set("str", 60);
        set("int", 30);
        set("dex", 50);
        set("cps", 30);
        set("spi", 30);
	set("kee", 5000);
	set("max_kee", 5000);
	set("sen", 5000);
	set("max_sen", 5000);

        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 50);

        set("atman", 2000);
        set("max_atman", 2000);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 50);



        set("combat_exp", 3000000);
        set("score", 20000);

        set_skill("literate", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dagger", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
  
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
