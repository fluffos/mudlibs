// edit by row on June 1999
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit TORCH;
inherit M_VALUABLE;

void setup() {
    set_id("incense", "%^CYAN%^香%^RESET%^");
    set_unit("枝");
    set_long( (: "一枝细细的香火，一般求神拜佛，祭天祀地都要用到。\n" + (query_is_lit() ? "它已经被点燃了，香尖冒出淡淡的烟。\n" : "") :) );
    set_light_msgs("$N恭恭敬敬地将$O凑到火苗上，小心翼翼地点着。\n", "$n恭敬地将$o点燃，顿时空气中多了一种舒心的香味。\n");
//    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 : "火焰的颜色似乎不对...\n" :) );
    set_fuel(-1); // never runs out
set_value(100);
}
