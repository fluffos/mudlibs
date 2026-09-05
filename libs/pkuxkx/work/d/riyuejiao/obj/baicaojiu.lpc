//baicaojiu.c	百草酒
//by bing
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("百草酒", ({"baicao jiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一葫芦只怕已有七十五年的百草酒。\n");
                set("unit", "葫芦");
                set("value", 6000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "百草酒",
                "remaining": 10,
                "drunk_apply": 40,
        ]));
}
