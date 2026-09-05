// sanqi.c

inherit ITEM;

void create()
{
        set_name("三七", ({ "san qi","sanqi" }) );
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
		set("unit", "棵");
        	set("long", "这是一棵三七草，叶似菊而茎有赤棱，乃止血化淤的良药。\n");
		set("value", 500);
		set("medicine", 1);
	}
	setup();
}
