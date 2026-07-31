// fake_book.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("一叶秘籍", ({ "yiye book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封面上写著:一叶秘籍。\n");
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
	if (!arg="yiye book" || !arg="book")
		return notify_fail("你要读什么？\n");
	message_vision("$N边看边用手指蘸点唾沫，一页一页地翻看着一叶秘籍。\n",me);
	me->start_busy(5);
	remove_call_out("is_poisoned");
	call_out("is_poisoned", 10);
	return 1;
}

int is_poisoned()
{
	object me=this_player();
	
//      me->apply_condition("yangdu_poison",(int) me->query("kar")+ random(30));
	
	message("channel:chat",
			HIY"【旁白】"HIC"花府突然传来一阵喧闹声：“抓贼呀！有人偷入密室！\n"NOR,users());
	remove_call_out("mi_tan");
	call_out("mi_tan",10);
	return 1;
}

int mi_tan()
{
	message("channel:chat",
			HIY"【花府】"HIC"花府大弟子正在和花枯发禀告经过。花枯发马上到密室去查看。\n"NOR,users());
	call_out("zi_bai",10);
	return 1;
}

int zi_bai()
{
	message("channel:chat",
			HIY"【花府】"HIC"花枯发心有余悸的说：“幸好只偷去了那本假的。不过，我在那本假书上涂了温家的"HIR"恙毒。\n"HIC"            那位梁上君子现在恐怕毒发了，正忙着找解药呢。\n"NOR,users());
	call_out("zi_bai2",10);
	return 1;
}

int zi_bai2()
{
	message("channel:chat",
			HIY"【花府】"HIC"花枯发“嘿嘿”地笑了几声。\n"NOR,users());
	call_out("zi_bai3",10);
	return 1;
}

int zi_bai3()
{
	object me=this_player();
	object ob;
	ob=this_object();
	message("channel:chat",
			HIY"【梁上君子】"HIB+ me->query("name") +HIC"“啊”地大叫一声，口吐白沫，昏了过去。\n"NOR,users());
	destruct(ob);
	return 1;
}

