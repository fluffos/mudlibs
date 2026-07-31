//tangshixuan.c

inherit ITEM;

void create()
{
        set_name("唐诗选注", ({ "tangshi xuanzhu", "xuanzhu" }));
        set_weight(600); 
        set("unique", 1); 
	if( clonep() )
		set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本唐诗选注，你仔细看了看，里面好象夹着个蝴蝶形的鞋样。\n");
                set("value", 500);
                set("material", "paper");
	     }
 
}

