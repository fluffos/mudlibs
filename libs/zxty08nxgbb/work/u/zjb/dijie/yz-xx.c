inherit ITEM;
void create()
{
        set_name(HIC"地界牌"NOR, ({ "dijie pai","pai"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这里是扬州和西域的交界处,特设此牌提示!!\n");
                set("unit", "个"); 
                set("no_get",1);
                set("no_drop",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",10000000);
        }
    setup();
}

