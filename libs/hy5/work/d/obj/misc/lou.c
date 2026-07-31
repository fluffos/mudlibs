inherit ITEM;

void create()
{
        set_name("青丝篓", ({ "qingsi lou","lou" }) );
        set_weight(1000);
        set_max_encumbrance(180000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "相传这是猪八戒用来装食物而专门制作的,这东西的容量大的惊人,据说可以装天呢!\n");
                set("value", 5000);
        }
}
int is_container() { return 1; }
