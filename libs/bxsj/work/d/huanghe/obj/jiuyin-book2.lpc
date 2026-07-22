#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;

int query_autoload(){return 1;}

void create()
{
        set_name(HIB"九阴真经下卷"NOR, ({ "jiuyin zhenjing", "xiajuan", "book"}));
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "卷");
                set("long",
"这是名震江湖之九阴真经的下卷。你可以研读以下的技能：\n"
"催心掌         (cuixin-zhang) \n""九阴白骨爪 (jiuyin-baiguzhua) \n"
);
                set("treasure", 1);
                set("unique", 1);
                set("value", 0);
                set("material", "skin");
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
    add_action("do_study",({"study", "du", "read"}));
}

int do_study(string arg)
{
    int cost, my_skill;
    object me=this_player();
    object where = environment(me);
    if (!arg) return notify_fail("你要读什么？\n");
    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");
    if (where->query("sleep_room"))
        return notify_fail("卧室不能读书，会影响别人休息。\n");
    if( me->is_fighting() )
        return notify_fail("你无法在战斗中专心下来研读新知！\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
    if( (int)me->query("potential") < 1 )
        return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
    if( (int)me->query("combat_exp") < 1000000 )
        return notify_fail("你的实战经验不足，再怎么读也没用。\n");
    if( me->query_int() < 35 )
        return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");

    cost = 40 * ( 1 + ( 35 - (int)me->query("int"))/20 );
    if (cost < 20) cost = 20;
    me->set_temp("last_damage_from", "研读高深武功，熬尽心机累");

    switch (arg) {
         case "jiuyin-baiguzhua":
              my_skill = me->query_skill("jiuyin-baiguzhua", 1);
              if( my_skill >=150)
                 write("你觉得这经书上所写的已经太浅了，不能学到什么东西。\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 write("也许是缺乏实战经验，你对经书上面所说的东西总是无法领会。\n");
              else write("你研读着有关九阴白骨爪的技巧，似乎有些心得。\n");
          me->improve_skill("jiuyin-baiguzhua", ((int)me->query_skill("literate", 1)/5+1) );
          me->receive_damage("jing", cost );
          if(me->query_skill("jiuyin-baiguzhua",1)<150)
               me->add("potential", - random(2));
         break;             
         case "cuixin-zhang":
              my_skill = me->query_skill("cuixin-zhang", 1);
              if( my_skill >=150)
                 write("你觉得这经书上所写的已经太浅了，不能学到什么东西。\n");
              if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                 write("也许是缺乏实战经验，你对经书上面所说的东西总是无法领会。\n");
              else write("你研读着有关催心掌的技巧，似乎有些心得。\n");
          me->improve_skill("cuixin-zhang", ((int)me->query_skill("literate", 1)/5+1) );
          me->receive_damage("jing", cost );
          if(me->query_skill("cuixin-zhang",1)<150)
               me->add("potential", - random(2));
         break;
    }
    return 1;
}

