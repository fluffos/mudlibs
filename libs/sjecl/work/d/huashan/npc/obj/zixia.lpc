// ITEM: /d/huashan/npc/obj/zixia.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
    set_name( "紫霞秘籍", ({ "zixia miji", "miji", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册华山派的紫霞神功秘籍。\n");
              set("unique", 1);
		set("treasure",1);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
            "name": "zixia-gong",   // name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}
