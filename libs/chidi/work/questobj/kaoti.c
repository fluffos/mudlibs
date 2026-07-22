#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"¿û»¨±¦¾í" NOR, ({ "kuihua-baojuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¾í");
            set("material", "paper");
            set("long", "Ò»¾íÎäÁÖÃØ¼®¡£\n");
          }

    setup();
}

