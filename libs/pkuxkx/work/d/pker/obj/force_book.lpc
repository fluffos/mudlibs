//chuforce_book

inherit ITEM;

void create()
{
        set_name("楚家内功秘籍", ({ "book",}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"楚家内功秘籍----是练习归魂剑法的基础");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
      "name": "chuforce",                // name of the skill
      "exp_required": 1000000,   // minimum combat experience required
        // to learn this skill.
       "jing_cost": 30,   // jing cost every time study this
       "difficulty":   30, // the base int to learn this skill
        // modify is jing_cost's (difficulty - int)*5%
        "max_skill":    250 // the maximum level you can learn
        // from this object.
                ]) );
        }
}

