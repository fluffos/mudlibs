inherit ITEM;
void create()
{
        set_name(HIC"地界牌"NOR, ({ "dijie pai","pai"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "往北方走是扬州城,往西南走是武当派,往西北走是襄阳城,往东南走是黑木崖,往东走是逍遥派迷阵!!\n");
                set("unit", "个"); 
                set("no_get",1);
                set("no_drop",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",10000000);
        }
    setup();
}

