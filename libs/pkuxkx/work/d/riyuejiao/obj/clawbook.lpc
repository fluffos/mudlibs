// clawbook.c
// by bing


inherit ITEM;

void create()
{
        set_name("鹰爪功秘诀", ({ "yingzhua-gong mijue", "mijue", "book" }));
        set_weight(600);
        set("value",600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是一本叙述鹰爪功精要所在的武功密笈，对提高你的爪法很有好处。\n");
                set("mingjiao", 1);
                set("material", "paper");
                set("skill", ([
       "name":                 "claw",        // name of the skill
       "exp_required": 10000,         // minimum combat experience required
                                                                               
// to learn this skill.
      "jing_cost":            50,       // jing cost every time study this
      "difficulty":   35,               // the base int to learn this skill
                                                                               
// modify is jing_cost's (difficulty - int)*5%
"max_skill": 150 //max skill
                                                                               
// from this object.
                ]) );
        }
}
