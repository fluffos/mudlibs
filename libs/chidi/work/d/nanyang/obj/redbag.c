// mabudai.c 麻布袋
inherit ITEM;
void create()
{
        set_name( RED "红  包" NOR, ({ "red bag", "bag" }));
        set_weight(500);
        set_max_encumbrance(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一只用来装礼金的红包。\n");
                set("value", 100);
        }
}
int is_container() { return 1; }


