inherit ITEM;
void create()
{
        set_name( "道德经", ({ "daode book","book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "老子道德经，老子道经，唐易州龙兴观道德经碑本一章，道， 可道，\n非常道；名，可名，非常名，无名，天地始；有名，万物母。常无，\n欲观其妙；常有，欲观其徼。此两者同出而异名... 
\n");
        set("value", 200);
        set("skill", ([
                "name":                 "force",             // name of the skill
                //"exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "jing_cost":             49,                             // gin cost every time study this
                "difficulty":   49,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    49                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
