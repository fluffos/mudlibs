// doorkey.c 杨莲亭的钥匙
inherit ITEM;
void create()
{
        set_name("钥匙", ({ "door key", "key" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把黄铜做的钥匙。\n");
                set("material", "iron");
               }
}
