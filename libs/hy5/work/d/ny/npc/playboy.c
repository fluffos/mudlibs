
// crazy_dog.c

inherit NPC;

void create()
{
	set_name("富家公子", ({ "playboy", "boy" }) );
	set("race", "人类");
	set("age", 20);
	set("long", "这位公子一身江南书生的打扮，但是从他气质可以看出这是一个纨绔子弟。\n");
    set("shen_type",-1);
	set("attitude", "friendly");
	set("per", 5);	
	set("str", 26);
	set("cor", 30);
	set("rank_info/respect","公子爷");
	set("gender","男性");
	set_skill("unarmed",20);
	set_skill("dodge",30);
	set_skill("parry",20);
	set("combat_exp", 3000);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"富家公子说道：小生文武双全，才高八斗，定能号召天下才子异人，"+"\n"+"创下一番盛世！！\n",
	}) );
	set("inquiry",([
		"作诗":
	"你说老子不会作诗！今儿个小爷就作一首！....嗯.....\n"+
"怎说泥巴无娇娘？\n眼前美人赛武皇；\n若能携得共连理，\n谁要先前那几房！？\n"
	]));
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"呔，小爷从未怕过谁！\n",
		"富家公子突然跳了起来，双手乱抓乱打，却不知道是在打谁。\n"
	}) );
	setup();
	add_money("silver",5);
}
