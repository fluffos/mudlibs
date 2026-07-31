// by 无名英雄
// 为了 yeju@SJ

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_for(string verb);
string ask_title();
string ask_prise();

void create()
{
	set_name("萧老板", ({ "xiao laoban", "xiao", "laoban" }));
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 40);
	set("long", "这位老板显然养尊处优，脸蛋和手掌都肥肥胖胖的。\n");
	set_skill("unarmed", 25);
	set_skill("dodge", 22);
	set_temp("apply/damage", 20);

	set_skill("literate", 150);
	set_skill("string", 200);
	set_skill("flute", 200);

	set("inquiry", ([
		"琴技" : (: ask_for, "string" :),
		"string" : (: ask_for, "string" :),
		"箫技" : (: ask_for, "flute" :),
		"flute" : (: ask_for, "flute" :),
         	"头衔" : (: ask_title :),
		"学费" : (: ask_prise :),
	]) );

	set("combat_exp", 9000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		(["name":__DIR__"obj/xiao","number":10]),
		(["name":__DIR__"obj/pipa","number":8]),
		(["name":__DIR__"obj/yqin","number":8]),
		(["name":__DIR__"obj/dongbula","number":5])
	}));
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/armor/shoes")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

string ask_for(string verb)
{
	object me = this_player();

	int money;
	int improve;

	if( !verb ) return 0;
	if( is_busy() ) return 0;

	if( me->query_skill(verb, 1) < 30 )
		return "你和蛮力一样，粗俗无文，可以说丝毫没有礼乐基础，恐怕学不到什么东西。";

	if( me->query_skill(verb, 1) >= 200 )
		return RANK_D->query_respect(me) + "已经是海内知名的大乐师，居然还来请教小弟，这如何敢当？！";

	if( me->query("potential") < 5 )
		return RANK_D->query_respect(me) + "，你的潜能不够，恐怕学不到什么东西。";

	money = 200;
	if( me->query_skill(verb, 1) > 60 ) money = 500;
	if( me->query_skill(verb, 1) > 90 ) money = 1000;
	if( me->query_skill(verb, 1) > 120 ) money = 1500;
	if( me->query_skill(verb, 1) > 150 ) money = 2000;
	if( me->query_skill(verb, 1) > 180 ) money = 2500;

	switch( MONEY_D->player_pay(me, money) ) {
		case 0:
		case 2:
		command("beg2 "+me->query("id"));
		return 0;				
	}

	improve = random(me->query_int() * 3 / 4) + random(me->query_skill(verb, 1) / 10) + me->query_int() / 4;
	improve = improve*3.5;	// 参考成高道人的比例
	improve = improve*2;		// 100% 小于 280 level

	if( me->query("registered") == 3 && me->query_temp("ggs/started") && me->query("ggs/started") ) {
		improve = improve*2;
		if( !random(4) ) message_vision("$N参照自己在"HIG"鬼谷算术"NOR"上的修为，运神通数，觉得自己学习起来事半功倍。\n",me);
	}

	me->add("potential", -5);	
	message_vision(CYN"$N兴奋的说道：「老夫正有兴趣与人研究探讨音韵呢……」\n"NOR,this_object());
	switch( random(5) ) {
                case 0:tell_object(me, CYN"萧老板指点了你一些关于"HIG"『徵』"NOR); break;
                case 1:tell_object(me, CYN"萧老板指点了你一些关于"HIW"『宫』"NOR); break;
                case 2:tell_object(me, CYN"萧老板指点了你一些关于"HIM"『羽』"NOR); break;
                case 3:tell_object(me, CYN"萧老板指点了你一些关于"HIY"『商』"NOR); break;
                case 4:tell_object(me, CYN"萧老板指点了你一些关于"MAG"『角』"NOR); break;
                case 5:tell_object(me, CYN"萧老板指点了你一些关于"BLU"『混音』"NOR); break;
        }
	if( verb == "string" ) tell_object(me, CYN"弹奏之法。\n"NOR);
	else tell_object(me, CYN"吹奏之法。\n"NOR);
	me->improve_skill(verb, improve);
	return "";
}

string ask_prise()
{
	int m, n, i , j;

	i = this_player()->query_skill("string", 1);
	j = this_player()->query_skill("flute", 1);
	m = 200;
	if( i > 60 ) m = 500;
	if( i > 90 ) m = 1000;
	if( i > 120 ) m = 1500;
	if( i > 150 ) m = 2000;
	if( i > 180 ) m = 2500;

	n = 200;
	if( j > 60 ) n = 500;
	if( j > 90 ) n = 1000;
	if( j > 120 ) n = 1500;
	if( j > 150 ) n = 2000;
	if( j > 180 ) n = 2500;

	return "你现在如果要向我请教呢，学费是：
		乐理琴技 每次" + MONEY_D->money_str(m) + "
		乐理箫技 每次" + MONEY_D->money_str(n) + 
		"\n请自己备好零钱。\n";
}

string ask_title()
{
	object me = this_player();
	string title, newtitle;
	int level;

	level = me->query_skill("string", 1);

	if( me->query_skill("flute", 1) > level )
		level = me->query_skill("flute", 1);

	if( !level || level < 1 ) return 0;

	if( level < 30 )
		newtitle = HIG"乐理学徒"NOR;
	else if( level < 50 )
		newtitle = HIY"司乐工"NOR;
	else if( level < 100 )
		newtitle = YEL"司乐师"NOR;
        else if( level < 150 )
		newtitle = GRN"知音雅客"NOR;
	else if( level < 200 )
		newtitle = HIW"礼乐大师"NOR;
	else if( level < 300 )
		newtitle = HIR"空山凤鸣"NOR;
	else if( level < 380 )
		newtitle = CYN"九霄龙吟"NOR;
	else newtitle = HIM"千古绝唱"NOR;

	title =  newtitle + " " + me->query("name") + "(" + capitalize(me->query("id")) + ")";
	me->set_temp("apply/short", ({title}));
	return "依老夫看，阁下的乐理修为，可以称呼为"+newtitle+"。";
}
