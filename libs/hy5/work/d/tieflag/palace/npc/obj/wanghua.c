 inherit ITEM;
void create()
{
        set_name("Íü»ê»¨", ({ "wanghua" , "Íü»ê»¨"}) );
        set_weight(5);
        set_max_encumbrance(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Ã");
                set("prep", "on");
                set("long", "Ò»¿Ã±ÌÂÌµÄ²Ý\n");
                set("value", 1);
        }
} 
int is_container() { return 1; }
