// npc: /d/city/npc/libailv.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name( YEL "彭宝现" NOR, ({ "peng baoxian","peng","baoxian" }) );
	set("gender", "男性" );
	set("title", "彭记鲜果店老板");
	set("age", 49);
	set("attitude", "friendly");
	set("rank_info/respect", "老哥");
	set("rank_info/rude","老王八蛋");
	set("long", @LONG
彭老板的这家彭记鲜果店在扬州城也是颇有名气，来采买果品的顾客很
多，以致于人手总是很紧张，这不，连老板都亲自上阵了。老彭一边给
一个顾客算帐，一边回答另外一个顾客的问讯，还不时回头对伙计吩咐
些什么。
LONG);
	set("chat_chance", 30);
	set("chat_msg", ({
		"彭老板道：怎么样？客官，不来二斤桃子尝尝么？\n",
		"彭老板道：来啊客官，这西瓜不甜不要钱！\n",
		"彭老板道：您等等，我这儿忙完了就过来。\n",
		"彭老板：瞧一瞧罢，客官，连知府老爷家的果品都是小店供应的。\n",
	}));
	set("inquiry", ([
		"鲜果" : "啊，是啊是啊，小店各种鲜果应有尽有，看看吧！",
		"here" : "咦！您家看了，「彭记鲜果铺」这大招牌不是明摆着的么？",
	]) );
	set("vendor_goods", ({
		__DIR__"obj/banana",
		__DIR__"obj/banli",
		__DIR__"obj/boluo",
		__DIR__"obj/caomei",
		__DIR__"obj/foshou",
		__DIR__"obj/ganzhe",
		__DIR__"obj/guiyuan",
		__DIR__"obj/hamigua",
		__DIR__"obj/hetao",
		__DIR__"obj/hongzao",
		__DIR__"obj/juzi",
		__DIR__"obj/lemon",
		__DIR__"obj/laiyangli",
		__DIR__"obj/lizhi",
		__DIR__"obj/lizi",
		__DIR__"obj/mangguo",
		__DIR__"obj/pipa",
		__DIR__"obj/putao",
		__DIR__"obj/shiliu",
		__DIR__"obj/shizi",
		__DIR__"obj/taozi",
		__DIR__"obj/xianggua",
		__DIR__"obj/xigua",
		__DIR__"obj/xingzi",
		__DIR__"obj/yali",
		__DIR__"obj/yangmei",
		__DIR__"obj/yingtao",
	}) );
	set("combat_exp", 10000);
	set_skill("unarmed", 22);
	setup();
	carry_object("/clone/cloth/male1-cloth")->wear();
}

void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("彭老板大声吆喝道：“时新鲜果，样样都有，价钱公道，童叟无欺！”\n",ob);
	return;
}
