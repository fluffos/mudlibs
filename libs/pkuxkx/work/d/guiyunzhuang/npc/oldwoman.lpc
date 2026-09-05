#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老妇人", ({"oldwoman" }) );
        set("gender", "女性");
        set("age", 68);
	set("long",
		"她满面愁容,非常凄苦的样子，却只是呆呆的出神。\n");
	set("combat_exp", random(50000)); 
	set("per",50);
	set("attitude","peaceful");
	set_skill("unarmed",20);
	set_skill("dodge",10);
	set("chat_chance_combat",100);
	set("shen_type",1);set("score",200);setup();
	set("chat_chance",5);
        set("chat_msg", ({
                "前几天我的儿子和儿媳去[黑风山]坎柴，至今未归。\n",
		"听说[黑风山]上住着两个杀人狂。呜呜呜呜.....\n",
		"我的儿啊，咳!我的命怎么这么苦，我就这么一个儿啊!\n",
        }) ); 
        carry_object("/d/city/obj/cloth")->wear();
	
}
