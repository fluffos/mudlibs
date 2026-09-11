// fish.c (鲜鱼)
#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;

void setup()
{
        set_id("fish", "鲜鱼");
        set_unit("条");
        set_gettable(1);
        set_num_eats(1);
set_last_eat_action((: this_body()->simple_action("$N捞起一条生鱼吃了下去。"+
        "\n") :));
        return;
}

void modify(int size) {
	if ( size < 3 )
                set_long("一条活蹦乱跳的小鱼");
	else
                set_long("一条新鲜大鱼");
}
