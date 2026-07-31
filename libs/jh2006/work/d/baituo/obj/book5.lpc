inherit ITEM;

void create()
{
        set_name("易经", ({ "yi jing", "jing", "yi" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本易经。\n");
                set("value", 500);
                set("material", "paper");
                set("unique", 1);
                set("treasure", 1);
                set("skill", ([
                        "name": "qimen-bagua",      // name of the skill
                        "exp_required": 500,  // minimum combat experience required
                        "jing_cost":    15,     // jing cost every time study this
                        "difficulty":   18,     // the base int to learn this skill
                        "max_skill":    31      // the maximum level you can learn
                ]) );
        }
}
