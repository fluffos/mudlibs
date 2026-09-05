// ping.c 平一指

inherit NPC;
string ask_gift();

void create()
{
	set_name("度每", ({ "dum" }));
	set("title", "礼物发放者");
	set("gender", "女性");
     set("start_room","/d/city/guangcgang");
	set("long", "她就是5.1节礼物发放者，她面无表情地站在这里。\n");
	set("age", 15);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
	set("inquiry",([
		"礼物":(:ask_gift:),
		"大礼包":(:ask_gift:),
		"gift":(:ask_gift:),
		]));
	setup();
}

void init()
{
//add_action("do_buy", "buy");
}

string ask_gift()
{
    object me;
    object gift;
    me = this_player();
    if ( (int)me->query("giftbox" ) > 0 ) return ("你已经拿过礼物了，为人不能贪得无厌，是不是？\n");
    gift=new("/u/dum/giftbox");
    gift->move(me);
	return "祝你节日快乐！";
 
 }


