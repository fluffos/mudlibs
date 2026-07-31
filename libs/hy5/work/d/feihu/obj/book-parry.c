// sword_book.c

inherit ITEM;

void create()
{
	set_name("闯王格斗秘诀", ({ "parrybook", "shu","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
                "封面上什么都没有。\n");
		set("no_put", 1);
//		//set("value", 100000);

		set("material", "paper");
		set("skill", ([
			"name": "parry",		
			"exp_required":	50000,
											// to learn this skill.
			"jing_cost":80,	
			"difficulty":80,
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":  380
											// from this object.
		]) );
	}
}
