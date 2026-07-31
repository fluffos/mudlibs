#include <ansi.h>

inherit NPC;

void create()
{
	set_name("庄允城", ({ "zhuang yuncheng", "zhuang","yuncheng" }) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("long",
		"这是个饱读诗书，却手无搏鸡之力的书生。\n"
	     +"因编辑‘明史辑略’，被吴之荣告发，全家逮入京中。\n" );

	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("noget", "庄允城叹道：我不行了，你走吧。唉，我担心我家里人啊。\n");
	set("chat_chance", 5);
	set("chat_msg", ({
		"\n庄允城说道：只怪我当初好心，在书中夹了金叶送与他，\n"
		"谁想这狼心狗肺的家伙竟然就去告发了我。唉...\n",
		"\n庄允城说道：谁要把吴之荣抓到庄府就好了。\n",
		"庄允城突然说道: 江湖威望很重要，威望高大有好处啊。\n",
		"\n庄允城叹了口气，说道：我知道鳌拜书房的秘密，只可惜我出不去啊。\n",
		"庄允城说道：谁要救了我，我一定把我知道的都告诉他。\n",
	}));
	set("inquiry", ([
		"吴之荣" :  "把他送到庄府去有好处。",
	]) );
	setup();
	carry_object( __DIR__"obj/cloth")->wear();
}

void init()
{
	object ob; 
	int i;

	ob = this_player();
	if (! userp(ob)) return;
	if (interactive(ob) && !is_fighting())
		say("庄允城哈哈笑道：终于有人来救我了！\n");

	i = ob->query("weiwang");
	if (i < 20)
	{
		i+= 10;
		ob->set("weiwang", i);
		tell_object(ob, HIC "你的江湖威望提高了！"NOR"\n");
	}
}
