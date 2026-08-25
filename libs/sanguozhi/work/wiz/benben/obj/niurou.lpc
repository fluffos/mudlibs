// niurou.c 五香牛肉干 by benben
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="benben")||(p_use=="fire"))
		this_body()->simple_action("$N拿起五香牛肉干吃了几口，好香呀，看$n咯吱咯吱嚼的这么香，你
忍不住咽了口口水。\n");
	else
		this_body()->simple_action("$N拿起五香牛肉干吃了几口，只听到“喀嚓”一声，$n的牙被嘣掉
了，原来咬了口牛筋。\n");
}
void eat_last_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="benben")||(p_use=="fire"))
this_body()->simple_action("$N把剩下的五香牛肉干一把放到嘴里，好过瘾呀，再来一包。\n");
	else
this_body()->simple_action("$N把剩下的五香牛肉干一把放到嘴里，“我的妈呀！”，$N惨叫
一声，吐出满口碎牙。\n");
}
void setup()
{   set_id("niurou","五香牛肉干");
    set_long("一包城隍庙的五香牛肉干。");
    set_adj("城隍庙");
    set_unit("袋");
    set_gettable(1);
    set_num_eats(2);
    set_value(1);
    set_currency_type("gold");
    set_eat_action((: eat_tan :));
    set_last_eat_action( (: eat_last_tan :));
}
