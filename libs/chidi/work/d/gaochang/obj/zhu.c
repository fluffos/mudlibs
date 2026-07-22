//mingzhu.c
inherit ITEM;
void create()
{
        set_name(HIW "夜明珠" NOR, ({ "ming zhu" ,"zhu", }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long","这是一颗罕见的上好明珠，看来值不少钱。\n");
                set("value", 100000);
                set("material", "iron");
              }
}

