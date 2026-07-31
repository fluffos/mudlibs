// chai.c
inherit ITEM;
void create()
{
        set_name( "长藤", ({ "chang teng"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "捆");
                set("long","这是一捆长藤。\n");
                set("value", 0);
                set("material", "wood");
              }
}
