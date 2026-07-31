// staff_book.c

inherit ITEM;

void create()
{
        set_name("棒法密籍", ({ "staff book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"「棒法密籍 -- 卷一（入门）」\n----------洪七公著");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
      "name": "staff",                // name of the skill
      "exp_required": 1000,   // minimum combat experience required
        // to learn this skill.
       "jing_cost": 20,   // jing cost every time study this
       "difficulty":   20, // the base int to learn this skill
        // modify is jing_cost's (difficulty - int)*5%
        "max_skill":    110 // the maximum level you can learn
        // from this object.
                ]) );
        }
}

