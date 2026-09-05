// punk.c
// Rewrote by iszt@pkuxkx, 2007-02-12

inherit NPC;

string ask_me();

void create()
{
	set_name("王二愣", ({"wang erleng", "wang", "erleng"}) );
	set("gender", "男性" );
	set("age", 28);
	set("long", "这是一个穷苦的大汉。\n");

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 500);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude", "heroism");
	set("inquiry", ([
		"土匪" : (: ask_me :),
		"救人" : (: ask_me :),
		"翠姑" : "翠姑是我老婆，她被土匪抢跑了，我又没本事，唉！",
	]) );
	set("shen_type",1);set("score",200);setup();
	set("chat_chance", 14);
	set("chat_msg", ({
		"王二愣哽咽道：「我不活了，翠姑……」\n"
	}) );
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	if ( this_player()->query_temp("liquan/ask_wang") )
		return "你还有完没完? 不救就算了，还看笑话呀。";

	say("王二愣哽咽道：「这几天闹土匪，我老婆被抢走了。真希望有人能救她回家。」\n");

	this_player()->set_temp("liquan/ask_wang", 1);
	return "土匪就在村后面的山上。";
}