//Obj:/u/pingpang/obj/table.c
//Made by:pingpang
inherit ITEM;

void create()
{
        set_name("八仙桌", ({ "table","desk","八仙桌"}) );
        set_weight(500); 
		set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("prep", "under");
                set("unit", "张");
                set("long", "一张石制的八仙桌。\n");
                set("value", 1);
        }
}
int is_container() { return 1; }

