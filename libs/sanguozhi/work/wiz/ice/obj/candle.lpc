// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <sanguo.h>
inherit TORCH;
inherit M_VALUE; // modified by fire
void setup() {
    set_adj("生日");
    set_id("candle", "蜡烛");
    set_long( (: "一根生日蜡烛，据说拥有魔法，只有生日的人才能许愿。\n" + (query_is_lit() ?
"它上面燃烧着奇异的蓝色火焰，只有当蜡烛熄灭了之后，愿望才会实现。\n" : "") :) );
    set_light_msgs("当$N把$O点着的时候，一股蓝色的火苗烧了起来。\n",
"当$n把$o点燃的时候，发出奇异的蓝色火光。\n");
    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 :
"火焰的颜色似乎不对...\n" :) );
    set_fuel(60); // never runs out
set_value(2);
set_currency_type("gold");
}
