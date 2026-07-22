inherit ITEM;

void create()
{
        set_name("药袋", ({ "bag" }) );
        set_weight(100);
        set_max_encumbrance(5000);
	set_max_items(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一口寻常的药袋，可以用来装一些草药。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

