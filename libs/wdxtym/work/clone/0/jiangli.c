// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "击杀大奖" NOR, ({ "jisha jiangli"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "外国人挑战击杀大奖，使用可获得灵石和点券。\n");
		set("spectxt", "随机增加先天属性。\n");
		set("value", 500);
		set("jifeng", 500);
		set("unit", "颗");
            set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	int effect;
	 mapping my;

	log_file("static/using", sprintf("%s(%s) eat 击杀大奖 at %s.\n",
		 me->name(1), me->query("id"), ctime(time())));

	effect = 0;
	message_vision("$N打开了" + this_object()->name() +
		       "。\n", me);

	write(HIM "你获得100灵石、500点券。"NOR"\n");
	me->add("yuanbao", 100);
	me->add("jifeng", 500);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }