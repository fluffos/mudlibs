// dead_ji.c

inherit ITEM;

void create()
{
        set_name("死鸡", ({ "dead ji", "ji" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只死了的老母鸡，脑袋软软的耷拉在一边。");
                set("value", 50);
        }
        call_out("decay", 180);
}
protected void decay()
{
        message_vision("$N发出一股难闻的恶臭，烂掉了 ... \n",this_object());
        destruct(this_object());
}
