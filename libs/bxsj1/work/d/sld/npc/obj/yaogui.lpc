//yaogui.c
inherit ITEM;

void create()
{
        set_name("药柜", ({ "yaogui", "gui"}) );
        set_weight(5000);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "in");
                set("unit", "只");
                set("long", "一只药柜。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }
