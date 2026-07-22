inherit ITEM;

void create()
{
        set_name("周天宝箱", ({ "box" }) );
        set_weight(500);
        set_max_encumbrance(8000);
		set_max_items(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个宝箱，打开可能会有惊喜哦。\n");
                set("value", 50);
        }
}
