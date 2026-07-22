inherit ITEM;

void create()
{
        set_name( "全真剑谱", ({ "book","jian pu" }));
        set_weight(100);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本全真剑谱，上面画着一些纷繁复杂的招式及修练法门。\n");
                set("material", "paper");
                set("skill", ([
                         "name": "quanzhen-jianfa",        
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost": 30,        // jing cost every time study this
                        "difficulty": 30,       // the base int to learn this skill
                        "max_skill":    150,    // the maximum level you can learn
                ]) );
        }
}

