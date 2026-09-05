#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIW "冰魄银针" NOR, ({ "bingpo yinzhen", "zhen", "needle", "yinzhen" }));
	set_weight(50);
	if (clonep())
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("base_unit", "根");
	        set("long", "一枚纯银的细针，针身镂刻花纹，打造得极是精致。针上喂了毒，不小心被刺到(stab)就麻烦了。\n");
	        set("value", 5000);
               set("material", "steel");
               set("base_weight", 50);
               set("wield_msg", "$N用拇指和食指从袖底拈出一枚$n。\n");
               set("unwield_msg", "$N将手中的$n放回袖中。\n");
        }
        set_amount(1);
        init_throwing(50);
        setup();
}

void init()
{
	add_action("do_zha", "stab");
}

int do_zha(string arg)
{
	object me=this_player();
	if (environment(this_object())!= me) return 0;
	if (!arg) return notify_fail("你要用冰魄银针扎谁？\n");
	if (arg!=me->query("id") && arg!="self") return notify_fail("不要乱玩这么危险的暗器，扎到别人就不好了。\n");
	tell_object(me, HIC"你犹豫了半天，一咬牙，用冰魄银针在自己手臂上刺了一下！\n"NOR);
	tell_object(me, RED"你突然感到一阵头晕，针上有毒！\n"NOR);
	F_POISON->poison_attack(me, me,"bing_poison", 50 + me->query_condition("bing_poison"));	
	return 1;
}