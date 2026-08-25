// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

void setup()
{   set_id("bottle", "瓶子", "flask");
    set_long("看起来象是个普通的瓶子。");
    set_gettable(1);
    set_num_drinks(5);
    set_drink_action( (: this_body()->simple_action("$N拿起瓶子喝了几口。\n$N") :));
    set_last_drink_action( (: this_body()->simple_action("$N拿起瓶子喝了几口，把最后一口也喝光了。\n") :));
}
