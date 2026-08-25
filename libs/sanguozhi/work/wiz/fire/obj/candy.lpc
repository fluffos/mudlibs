// candy.c 大白兔奶糖 by fire on Jan 7, 1998
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="fire")||(p_use=="tuotuo")||(p_use=="yue")||(p_use=="lily"))
		this_body()->simple_action("$N拿起大白兔奶糖吃了几口，真甜呀。\n");
	else
		this_body()->simple_action("$N拿起大白兔奶糖吃了几口，牙痛得满地打滚。\n");
}
void eat_last_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="fire")||(p_use=="tuotuo")||(p_use=="yue")||(p_use=="lily"))
this_body()->simple_action("$N把剩下的大白兔奶糖一把放到嘴里，真甜呀。\n");
	else
this_body()->simple_action("$N把剩下的大白兔奶糖一把放到嘴里，牙痛得满地打滚。\n");
}
void setup()
{   set_id("candy", "大白兔奶糖", "tang");
    set_long("几粒诱人的大白兔奶糖。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(3);
    set_unit("粒");
    set_value(1);
    set_currency_type("gold");
    set_eat_action((: eat_tan :));
    set_last_eat_action( (: eat_last_tan :));
}
mixed can_sell() {
return 0;
}
