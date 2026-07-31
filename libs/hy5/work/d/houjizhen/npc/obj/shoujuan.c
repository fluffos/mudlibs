// shoujuan.c
// by dicky

inherit ITEM;

void create()
{
        set_name("手绢", ({ "nvren shoujuan", "shoujuan" }) );
	set("long", "这是一条女人用的手娟, 上面绣着两字鸳鸯。\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        }
        setup();
}

