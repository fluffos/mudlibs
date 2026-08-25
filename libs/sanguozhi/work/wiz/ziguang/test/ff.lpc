inherit TORCH
void setup(){
set_id("huoba", "火把")
    set_unit("根")
set_long( (: "一根破旧的火把，头上有些松油。\n" + 
(query_is_lit() ?
"它上面燃烧着淡红的火焰。\n" : "") :) )
 set_light_msgs("当$N把$O点着的时候，一股红色的火苗烧了起来。\n",
 "当$N把$O点燃的时候，冒出一股呛人的烟。\n")
set_source( 1 )
 set_fuel(500)
// never runs out
 set_value(2)
set_currency_type("silver")
}
}
