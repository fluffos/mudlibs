// jiuyang1.c

inherit ITEM;

void create()
{
        set_name("九阳真经", ({ "jiuyang miji" ,"miji"}));
        set_weight(600);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一卷羊皮纸的残卷，上面有一些深奥的字句，似乎\n"
                        "提到一些呼吸方法什麽的。\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "force",                // name of the skill
                        "exp_required": 100,                              // minimum combat experien
                                                                                    // to learn this skill.
                        "jing_cost":             20,                             // gin cost every time study this
                        "difficulty":   30,                             // the base int to learn this skill
                                                                                    // modify is gin_cost's (difficulty - int)*5%
                       "max_skill":    40,                              // the maximum level you can learn
                                                                                    // from this object.
                ]) );
        }
}


