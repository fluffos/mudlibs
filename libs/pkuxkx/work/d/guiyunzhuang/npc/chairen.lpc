// Modified by iszt@pkuxkx, 2007-04-20

inherit NPC;
string ask_me();

void create()
{
	set_name("砍柴人",({"kanchai ren", "chairen", "ren"}));
        set("gender", "男性");
        set("age", 48);
	set("long",
		"他满面愁容，非常凄苦的样子。\n");
	set("combat_exp", 10000); 
	set("attitude","peaceful");
	set_skill("unarmed",30);
	set_skill("dodge",10);
	set("chat_chance_combat",100);
	set("inquiry",([
		"手印" : (: ask_me() :),
	]));

	set("shen_type",1);set("score",200);setup();
	set("chat_chance",1);
        set("chat_msg", ({
                "砍柴人摇着头说：「前几天陆大人来柴房，丢了他的贴身金手印。」\n",
		"砍柴人摇着头说：「吩咐我们下人找，可是我们还没有找到。」\n",
        }) ); 
        carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	object ob;
	if(this_player()->query_temp("been_get"))
		return "我已经把它送给陆大人了。\n";
	this_player()->set_temp("been_get",1);
	ob=new(__DIR__"obj/shouyin");
	ob->move(this_player());
	return "我们刚找到手印,还没来得及送给陆大人，你给我们代劳吧。\n";
}