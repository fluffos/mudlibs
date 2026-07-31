 // taoism_book.c
inherit ITEM; 
void create()
{
        set_name("天师正道入门", ({ "taoismbook" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        
"这是一本天师正道的入门，只有学了天师正道，你才能进一步提高茅山术的等级.\n"
                );
                set("value", 8260);
                set("material", "taoism");
		set("skill", ([
			"name":	      "literate",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29
	
		]) );
        }
        setup();
}
    
