// cracked by vikee 2/09/2002   vikee@263.net
// bigeye.c
// 1996/12/06 by cglaem

inherit NPC;

string send_mail();
string receive_mail();
int send_dianbo();

void create()
{
	set_name("千里眼", ({"qianli yan", "bigeye", "youchai","chai" }) );
	set("title", "邮差");
	set("gender", "男性" );
	set("age", 30);
	set("str", 40);
	set("long",
		"前玉皇大帝亲信。因为偷看玉女出浴而被罚为邮差。\n他本来是和顺风耳一起呆在花果山仙石处的，\n后因嫌不够热闹跑到长安来了。\n");
	set("combat_exp", 8000);
  set("daoxing", 100000);

	set("attitude", "friendly");
	set("inquiry", ([
                        "name":"连我你都不认识？大名鼎鼎的千里眼就是我。", 
		"here" : "鬼知道这是什么地方！我只负责收信发信。",
                        "玉女" : "嘿嘿．．．不错。就算砍头我也划算了。",
                        "玉皇大帝" : "你别提他！一提我就有气．．．只许州官放火，不许百姓点灯。",
		"发信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"信件" : (: receive_mail :),
		"信" : (: receive_mail :),
		//"mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
		"mail" : (: receive_mail :),
		"mailbox" : (: receive_mail :),
		"小喇叭" : (: send_dianbo :),
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	set("per", 15);
            set("max_kee", 500);
            set("max_gin", 100);
            set("max_sen", 300);
            set("force", 150);
            set("max_force", 300);
            set("force_factor", 0);
	setup();
	if(clonep()) {
	  add_money("coin", 70);
	  carry_object("/d/ourhome/obj/linen")->wear();
	  carry_object("/d/wiz/npc/caishen"); //note, here is a NPC.
	}
}

int send_dianbo()
{
	object me=this_player();
	if(! me->query("xiaolaba_member")) {

message_vision("$N想了一会儿，说道：对不起，你问的事我实在没有印象。\n",
this_object());
		return 1;
	} else {
message_vision("$N对着$n点了点头。\n", this_object(), me);
		me->move("/u/bula/diantai");
tell_room(environment(me), me->name()+"来啦！\n", ({me, me}));
		return 1;
	}
}
string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到南城客栈来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦．．．要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到南城客栈来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找．．．有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}

