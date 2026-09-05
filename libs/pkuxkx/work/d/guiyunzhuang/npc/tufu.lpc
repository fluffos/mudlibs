//tufu.c
//Made by:pingpang

inherit NPC;
void create()
{
	set_name("屠夫",({"tu fu","fu"}));
	set("long",@LONG
他是在太湖街上卖猪肉的一个屠夫。
LONG);
	set("gender","男性");
	set("shen_type",1);
	set("str",20);
	set("int",20);
	set("con",20);
	set("dex",20);
	set("combat_exp",3000);
	set_skill("unarmed",20);
	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("blade",30);
	set("chat_chance_combat",20);
	set("chat_chance",3);
	setup();
	set("chat_msg",({"大家想要买猪肉吗?\n",
	}));
	carry_object("/d/city/obj/cloth")->wear();
	carry_object(__DIR__"obj/tudao")->wield();
}
