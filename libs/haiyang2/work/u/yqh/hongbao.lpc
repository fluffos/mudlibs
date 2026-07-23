// 红包

#include <ansi.h>
inherit ITEM;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});
void create()
{
	set_name(HIR"红包"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "一个用红纸制作而成的"+HIR"红包，"NOR+"似乎可以撕开(opengift)。\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
object ob;
	this_player()->add("combat_exp", 1088);
	this_player()->add("potential",588);
if (this_player()->query("max_neili") < 1000)
	this_player()->add("max_neili",18);
	this_player()->start_busy(50);
        this_player()->apply_condition(du[random(sizeof(du))], 3);
//        this_player()->apply_condition("feidian_poison", 5);
	message_vision("$N打开了红包，只觉得自己又变利害了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}