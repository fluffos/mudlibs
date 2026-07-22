inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name("帛卷", ({ "bo juan", "bo", "juan" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张帛卷，上面写满了娟秀的文字。\n");
                set("treasure", 1);
                set("value", 200000);
                set("material", "skin");
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
    add_action("do_study",({"yandu", "kan"}));
}

int do_study(string arg)
{
    int cost, my_skill;
    object me=this_player();
    object where = environment(me);
    if (!arg || !(arg=="bo juan" || arg=="bo" || arg=="juan"))
        return 0;
    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");
    if (where->query("sleep_room"))
        return notify_fail("卧室不能读书，会影响别人休息。\n");
    if( me->is_fighting() )
        return notify_fail("你无法在战斗中专心下来研读新知！\n");
    if( !me->query_skill("jiuyin-baiguzhua") )
        return notify_fail("你无法从这样东西学到任何东西。\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
    if (!random(5))
        message("vision", me->name() + "正专心地研读帛卷。\n", environment(me), me);
    if( (int)me->query("potential") < 1 )
        return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
    if( (int)me->query("combat_exp") < 650000 )
        return notify_fail("你的实战经验不足，再怎么读也没用。\n");
    if( me->query_int() < 38 )
        return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");
    cost = 40 * ( 1 + ( 38 - (int)me->query("int"))/20 );
    if (cost < 10) cost = 10; // minimum cost
    if( me->query_skill("jiuyin-baiguzhua", 1) < 140 )
        return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太深了，没有学到任何东西。\n");
    my_skill = me->query_skill("jiuyin-baiguzhua", 1);
    if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
        write("也许是缺乏实战经验，你对帛卷上面所说的东西总是无法领会。\n");
    else write("你研读着有关九阴白骨爪的技巧，似乎有些心得。\n");
    me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
    if (cost < 1) cost = 1;
    me->set_temp("last_damage_from", "研读高深武功，熬尽心机累");
    me->receive_damage("jing", cost );
if(me->query_skill("jiuyin-baiguzhua",1)<200)
    me->add("potential", - random(2));
    return 1;
}

int query_autoload()
{
        return 1;
}
