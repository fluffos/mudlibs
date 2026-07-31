//by diabio
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("飞天御剑流宝典", ({ "bao dian", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"飞天御剑流的不传之书。\n");
		set("value", 0);
		set("material", "paper");
		}
}


void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
}

int do_study(string arg)
{
	object me;
	me=this_player();
	if (!arg="bao dian" || !arg="book")
		return notify_fail("你要读什么？\n");
        message_vision("$N边看边用手指蘸点唾沫，一页一页地翻看着飞天御剑流宝典,嘴巴还忍不住的吧唧吧唧的砸了几下\n",me);
	me->start_busy(5);
     remove_call_out("yapian_poison");
      call_out("yapian_poison", 40);
	return 1;
}

int yapian_poison()
{
	object me=this_player();
	message("channel:chat",
			HIY"【道场】"HIC"神古活心流道场突然传来一阵喧闹声：“不好了，御剑流宝典不见了!
\n"NOR,users());
	call_out("mi_tan",10);
	return 1;
}

int mi_tan()
{
	message("channel:chat",
			HIY"【飞天御剑流】"HIC"比古清十郎正在叫弟子绯村剑心去调查事情经过。
\n"NOR,users());
	call_out("zi_bai",10);
	return 1;
}

int zi_bai()
{
	message("channel:chat",
                        HIY"【药铺】"HIC"高和惠急道:“那怎么得了，那可是我以前被人逼迫做鸦片时用来垫锅底的，上面有"HIR"鸦片毒。\n
"HIC"            左之助骂道：你是怎么搞的，不是叫你放好的吗？现在那位只怕.....\n"NOR,users());
	call_out("zi_bai2",10);
	return 1;
}

int zi_bai2()
{
	message("channel:chat",
                        HIY"【飞天御剑流】"HIC"某人深深叹了口气，真可怜啊！\n"NOR,users());
	call_out("zi_bai3",10);
	return 1;
}
int zi_bai3()
{
	object me=this_player();
	object ob;
	ob=this_object();
	message("channel:chat",
			HIY"【梁上君子】"HIB+ me->query("name") +HIC"“啊”地大叫一声，真是.T.M.D.说完口吐白白沫，昏了过去。\n"NOR,users());
	destruct(ob);
	return 1;
}
