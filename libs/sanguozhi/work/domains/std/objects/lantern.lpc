// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_SWITCHABLE;
inherit M_LIGHTABLE;

void setup() {
    m_switchable::create();

    set_adj("黄铜");
    set_id("lantern","灯笼");
    set_unit("盏");
    set_gettable(1);
    set_size(MEDIUM);
    set_long("不知怎的，这个黄铜灯笼看起来很眼熟。\n");

    set_fuel(3600);
        
    add_hook("prevent_turn_on", (: check_fuel :));
    add_hook("extinguish", (: set_is_on, 0 :));
    add_hook("turn_on", (: light :));
    add_hook("turn_off", (: extinguish :));
 }

void create()
{
    object::create();
    m_switchable::create();
}
