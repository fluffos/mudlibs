//table.c 梳妆台
inherit ITEM;
void create()
{
        set_name("大箱子", ({ "bigbox" , "big box", "box"}) );
        set_weight(5000);
        set_max_encumbrance(8000000);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("no_get", 1);
                set("long", "这是一个大箱子。\n");
                set("value", 0);
        }
}
int is_container() { return 1; }
