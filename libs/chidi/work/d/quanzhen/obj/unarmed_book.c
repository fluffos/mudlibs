inherit ITEM;

void create()
{
        set_name( "空明拳谱", ({ "book","quan pu" }));
        set_weight(100);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是空明拳谱，上面画着一些纷繁复杂的招式及修练法门。\n");
                set("material", "paper");
                set("skill", ([
                         "name": "kongming-quan", 
                        "exp_required": 10000,  // minimum combat experience required
                        "jing_cost": 25,        // jing cost every time study this
                        "difficulty":   30,     // the base int to learn this skill
                        "max_skill":    150,    // the maximum level you can learn
                ]) );
        }
}

