
// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("家丁", ({ "waiter" }) );
	set("title", "");
	set("gender", "男性" );
	set("age", 18);
	set("long",
		"杜宽担任雪亭驿的驿长已经有十几年了，虽然期间有几次升迁的\n"
		"机会，但是他都因为舍不得离开这个小山村而放弃了，雪亭镇的\n"
		"居民对杜宽的风评相当不错，常常会来到驿站跟他聊天。\n");
    set("max_kee",300);
    set("kee",300);
    set("max_force",200);
    set("force",200);
    set("con",30);
    set("cor",30);
    set("str",15);
	set("combat_exp", 8000);
	set("attitude", "friendly");
	set("inquiry", ([
		"驿站" : "是啊... 这里就是雪亭驿，你要寄信吗？",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
