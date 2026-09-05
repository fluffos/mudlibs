// liquan.c 沥泉灵
// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name(HIG"沥泉灵"NOR, ({"liquan ling", "ling"}));
	set_weight(500);
	set("preorder",0);
	set("robinterval",7200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long","一个灵光闪闪的东西。\n");
		set("value", 200000);
	//	set("no_drop", "这样东西不能离开你。\n");
		set("material", "steel");
	//	set("no_give_user", 1);
		set("no_store", 1);
		set("no_sell", 1);
		set("no_pawn", 1);
	}
}

void init()
{
	add_action("do_remake", "remake");
	::init(); //F_UNIQUE defines this
}

int do_remake(string arg)
{
	int i;
	object me = this_player();
	object ob = this_object();
	object weapon;
	string* weapons = ({"qiang", "jian", "dao", "chui", "bian", "zhang",
				"gun", "fu", "ji", "bi", "cha", "chu", });
	string* weapon_names = ({"枪", "剑", "刀", "锤", "鞭", "杖",
				"棍", "斧", "戟", "匕", "叉", "杵", });
	int id;
	string msg = "现在有如下种类的武器：\n";

	for(i=0; i<sizeof(weapons); i++)
		msg += weapon_names[i] + "(" + weapons[i] + ") ";
	msg += "\n";
	if (!arg
		|| ( member_array(arg, weapons)==-1
		&& member_array(replace_string(arg, "liquan ", ""), weapons)==-1 ) )
		return notify_fail("你要做什么？\n"+msg);

	if(me->is_fighting())
		return notify_fail("你正在战斗，无法使用沥泉灵。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢，无法使用沥泉灵。\n");
	if(me->query("neili") < 1000)
		return notify_fail("你的真气不足，无法使用沥泉灵。\n");

	me->add("neili", -1000);
	me->start_busy(4);

	if((id = member_array(arg, weapons)) == -1)
		id = member_array(replace_string(arg, "liquan ", ""), weapons);

	weapon = new(__DIR__"liquan"+weapons[id]);
	weapon->move(me);
	if(objectp(previous_object()))
		ob = previous_object();
	msg = HIY"$N手按"+ob->query("name")+HIY"，心念一动，真气源源不断输送过去，将"
		+ob->query("name")+HIY"变成了一把"+weapon->query("name")+HIY"！\n"NOR;
	message_vision(msg, me);

	if(objectp(previous_object()))
		destruct(previous_object());
	if(objectp(this_object()))
		destruct(this_object());

	return 1;
}