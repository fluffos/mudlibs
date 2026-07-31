// caiji@SJ 8/25/2000
// for a job

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_guo();

void create ()
{
	set ("short", "药庐");
	set ("long", @LONG
这里是星宿派的药庐。星宿弟子性格凶残者极多，经常打家劫舍，所以
也经常受伤，这里准备了一些金疮药，放在柜子上。屋子角落处摆着一口大
铁锅（guo），是星宿弟子自己熬毒药用的。
LONG);

	set("item_desc", (["guo" : (: look_guo :) ]));

	set("exits", ([ //sizeof() == 4
		"south" : __DIR__"ryd",
	]));
	
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	 ]));

	setup();
}


void init()
{					     
	add_action("do_add", "fang");
	add_action("do_add", "add");
	add_action("do_jian", "jian");
	add_action("do_jian", "ao");
}

int do_add(string arg)
{
	string item_name;
	object who = this_player();
	object item;
	mapping fam=who->query("family");

	if (who->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");

	if (!fam || fam["family_name"] !="星宿派")
		return notify_fail("你不是星宿弟子，不能在这里熬药。\n");

	if(!arg) 
		return notify_fail("你要将什么东西加进锅里？\n");

	if( sscanf(arg, "%s in guo", item_name)!=1 )
		return notify_fail("用法：fang <东西> in guo。\n");

	if (item_name=="water") {
		message_vision( "$N往锅里舀了一勺水。\n",who);
		who->set_temp("cook/allow", 1);
		return 1;
	}

	item = present(item_name, who);

	if (! present(item_name, who)) 
		return notify_fail("你身上没有这东西。\n");

	if ( item->query("cook/allow") !=1 ) 
		return notify_fail("这锅是用来熬药的，别什么东西都往里扔。\n");

	if ( !item->query("cook/owner") || item->query("cook/owner") != who) 
		return notify_fail("你这是偷了谁的东西，想往锅里藏啊。\n");

	message_vision(HIC"$N将一"+item->query("unit")+item->query("name")+HIC"扔进锅里。\n"NOR,who);

	if ( who->query_temp("cook/"+item->query("cook/type")) < item->query("cook/value"))
		who->set_temp("cook/"+item->query("cook/type"), item->query("cook/value"));

	who->set_temp("last_put", 1);
	destruct(item);
	return 1;
}

int do_jian(string arg)
{
	object who = this_player();
	object gao;
	mapping fam=who->query("family");
	int prices;
	if (who->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (!fam || fam["family_name"] !="星宿派")
		return notify_fail("你不是星宿弟子，不能在这里熬药。\n");

	if(!arg || arg != "yao") return notify_fail("熬啥？\n");

	if ( !who->query_temp("cook/allow"))
		return notify_fail("锅里连水都没有，怎么熬药？\n");

	if (!who->query_temp("last_put"))
		return notify_fail("你在铁锅里放东西了没有啊？\n");

	prices = who->query_temp("cook/xiezi") * who->query_temp("cook/shachong") * who->query_temp("cook/zhizhu") * who->query_temp("cook/wugong");

	if(!prices ) 
		gao=new("/d/xingxiu/obj/yao");
	else {
		gao=new("/d/xingxiu/obj/gao");
		if(prices<10 && prices>0 )
			prices=10+random(10);
		if(prices>200)
			prices=200+random(100);
		gao->set("xx/owner",who);
		gao->set("prices",prices);
		gao->set("long",gao->query("long")+"好象是星宿派的"+who->name()+"从药庐熬出来的！\n");
	}
	message_vision(HIY"$N在锅里胡乱搅了搅，然后熬啊，熬啊，熬啊，终于熬成了"+gao->query("name")+HIY"。\n"NOR,who);
	who->start_busy(2+random(3));
	gao->move(who);

	who->delete_temp("cook/allow");
	who->delete_temp("cook/wugong");
	who->delete_temp("cook/zhizhu");
	who->delete_temp("cook/shachong");
	who->delete_temp("cook/xiezi");
	who->delete_temp("last_put");

	return 1;
}

string look_guo()
{
	object me = this_player();
	if ( me->query_temp("last_put"))
		return "一口大铁锅，熬药用(ao yao)，里面乱七八糟的不知放(fang)了些什么。\n";
	else
		return "一口大铁锅，往里面加东西用(add)，熬药用(ao yao)。\n";
}
