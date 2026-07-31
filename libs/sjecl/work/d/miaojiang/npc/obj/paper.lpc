inherit ITEM;
void create()
{
        set_name("两页刀法", ({ "liangye daofa", "paper","book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这似乎是一本书上残缺的几页关于刀法的书。\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
        }
}
