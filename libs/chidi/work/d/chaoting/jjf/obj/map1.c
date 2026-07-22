inherit ITEM;

 int seteuid();
void create()
{
 set_name("羊皮地图第一卷", ({ "map1" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
   else {
               set("unit", "张");

set("long",  "这是一张前朝的军事总略图与七张分图，组成一份全国军事详分图.\n");

                set("value", 0);
                set("material", "copper");
                set("军事详图", "YES");
        }
}

