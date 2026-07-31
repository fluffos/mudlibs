// book_two.c
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("百草经(下部)", ({ "book_two"  }) );
    set("unit", "本");
    set("long","这是一部封皮已经发黄的书。\n");
    set_weight(50);
    setup();
}