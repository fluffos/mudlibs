inherit ITEM;

void create()
{
        set_name("饭盒", ({ "fan he", "he" }));
        set("weight", 5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("no_drop",1);
                set("no_get",1);
                set("unit", "个");
                set("value", 10);
                set("material", "wood");
        }
        setup();
}       

