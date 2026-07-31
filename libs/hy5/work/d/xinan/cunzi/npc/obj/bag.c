inherit ITEM;
void create()
{
        set_name("Âé´ü", ({ "ma dai", "bag" }));
        set_weight(200);
        set_max_encumbrance(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ö»");
                set("value", 20);
        }
}
int is_container() { return 1; }

