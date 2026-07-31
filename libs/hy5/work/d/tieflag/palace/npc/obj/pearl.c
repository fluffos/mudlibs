 inherit ITEM;
void create()
{
        set_name("雷火珠", ({ "pearl" , "雷火珠"}) );
        set_weight(1);
        set("explosive",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个有强大爆炸力的雷火珠\n");
                set("value", 1000);
        }
}       
