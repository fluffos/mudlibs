//  mianbing.c
//  面饼
//  created by tset 1/17/98
//  last updated by tset 1/17/98

#include <sanguo.h>

inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;

void setup() {
        set_id("mianbing", "面饼", "bing");
        set_long("一块又香又甜的面饼");
        set_unit("块");
        set_gettable(1);
        set_value(50);
        set_currency_type("coin");
        set_num_eats(2); 
  set_eat_action((: this_body()->simple_action("$N拿起面饼来吃了几口。"+
        "\n") :));
  set_last_eat_action((: this_body()->simple_action("$N把剩下的面饼"+
        "吃得干干净净。\n") :));
}

