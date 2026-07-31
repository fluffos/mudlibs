// wangyuan.c

inherit ITEM;

void create()
{
        set_name("ÍûÔ¶¾µ", ({ "wangyuan jing", "jing" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼Ü");
		set("value", 0);
        }
        setup();
}

