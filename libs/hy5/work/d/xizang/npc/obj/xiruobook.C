inherit ITEM;
void create()
{
        set_name( "庖丁解牛图册", ({ "xiruo book","book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是根据一代屠夫老祖宗庖丁杀牛而悟出来的刀法图解。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "xiruo-blade",             // name of the skill
                //"exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             200,                             // gin cost every time study this
                "difficulty":   200,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    200                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
