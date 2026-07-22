inherit ITEM;

void create()
{
 set_name("羊皮地图第三卷", ({ "map3" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "张");
 set("long",  "这是一张前朝的扬州军事图，标有许多秘密，对朝廷非常有用。\n");
      set("value", 40000);
                set("material", "copper");
                set("军事详图", "YES");
        }
}

