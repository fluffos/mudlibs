inherit TORCH;
inherit M_VALUABLE;
void setup() {
    set_adj("写作专用");
    set_id("pen", "派克钢笔");
    set_long( (: "一支派克钢笔，一看就给人以灵感。\n" + (query_is_lit() ?
"似乎又是一只打火机。\n" : "") :) );
    set_light_msgs("当$N把$O点着的时候，一股蓝色的火苗烧了起来。\n",
"当$n把$o点燃的时候，发出蓝色的火光。\n");
    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 :
"火焰的颜色似乎不对...\n" :) );
    set_fuel(-1); // never runs out
set_value(15);
}
