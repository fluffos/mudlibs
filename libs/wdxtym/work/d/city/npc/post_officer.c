// post_officer.c 

inherit NPC;
string send_mail();
string receive_mail();
string give_quest();
void create()
{
	set_name("杜宽", ({ "post officer", "post","officer" }) );
	set("title", "驿长");
	set("gender", "男性" );
	set("age", 43);
	set("long",
		"杜宽担任雪亭镇的驿长已经有十几年了，虽然期间有几次升迁的\n"
		"机会，但是他都因为舍不得离开而放弃了，这次应angelus的邀请，\n"
		"终于来到love，在这里当驿站站长，angelus对他很是感激。\n");
	set("combat_exp", 800);
	 set("level", 9);
	 set("icon", "05015");
	set("attitude", "friendly");
	set("inquiry", ([
		"驿站" : "是啊... 这里就是扬州驿，你要寄信吗？",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
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
	||      base_name(environment()) != query("startroom") )
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
	||      base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
void init()
{
    if( !environment()  ||  base_name(environment()) != query("startroom") )
	    return;

}


