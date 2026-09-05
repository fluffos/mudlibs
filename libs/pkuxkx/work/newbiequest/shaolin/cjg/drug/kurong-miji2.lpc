// 醒神丹 补 有效精神的5% 仅藏经阁副本有效
// by seagate@pkuxkx 2011.02.18
#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
  add_action("do_read", "read");
}

void create()
{
	set_name(HIG"枯荣神功秘籍"NOR, ({"kurong miji", "book" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是来自于大理段家秘传的枯荣神功秘籍，学(read)可以入门枯荣神功。\n");
		set("value", 1000);
	}
}

int do_read(string arg)
{
	object me=this_player(), env=environment(me);
	int dur;
  
  if (!id(arg))
  	return 0;

  if ( me->query("family/family_name") !="天龙寺" && me->query("chushi/last_family") !="天龙寺" )
	{
	  tell_object(me, "你和天龙寺没有任何渊源，贸然学习别派的内功心法似乎有些不妥，你把秘籍又还回去了。\n");
	  destruct(this_object());
	  return 1;
	}
	
	if ( me->query_skill("kurong-shengong",1)>= 100 )
	{
	  tell_object(me, "这本秘籍对你来说过于浅显了。\n");
	  return 1;
	}
	
	me->set_skill("kurong-shengong", 100);
	tell_object(me, "你仔细阅读了这本秘籍，对枯荣神功有了初步地了解。\n");
	destruct(this_object());
	return 1;
}