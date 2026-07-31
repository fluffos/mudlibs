// cloth.c
//
// This is the basic equip for players just login.

//#include <armor.h>

inherit ROOM;
// CLOTH;

void create()
{
        set("short",
"木筏");
//  set("short", "小路");
        set("long", @LONG
一条木筏.
LONG );
/*        set_weight(3000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "skin");
               set("value",30);
               set("armor_prop/armor", 3);
        } */
        setup();
}

