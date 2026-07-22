// qibook.c
inherit ITEM;
void create()
{
    set_name("棋道", ({ "bo juan", "bo", "juan" }));
    set_weight(50);
    set("no_drop", "这样东西不能离开你。\n");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
        set("long",
            "这是一本旧书，画着横七竖八的许多线条。\n");
        set("value", 500);
        set("material", "silk");
        set("skill", ([
            "name": "force",    // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    19  // the maximum level you can learn
        ]) );
    }
}

