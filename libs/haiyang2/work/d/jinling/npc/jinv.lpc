// yahuan.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("妓女", ({ "jinu","girl","ji" }) );
	set("gender", "女性" );
       set("str", 19);
	set("per", 27);
	set("age", 19);

	set("long",
		"一个身材苗条的妓女，她年纪轻轻，貌美如花，\n"
		"你的心跳加快了！\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"妓女很肉麻的说道：官人怎么不经常来呀。\n",
		"妓女小心翼翼的修着指甲。\n",
		"妓女很肉麻的说道：官人进来玩玩吧。\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk_bra")->wear();
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"不要嘛。\n");
        return 1;
}
 
