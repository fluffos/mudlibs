#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"浣花洗剑录"NOR, ({ "swordlu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         
            set("unit", "本");
            set("material", "paper");
            set("long", "神书之一。\n");
          }

    setup();
}
