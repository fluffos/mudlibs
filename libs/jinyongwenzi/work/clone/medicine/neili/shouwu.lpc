// shouwu.c 何首乌
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(GRN"何首乌"NOR, ({"heshou wu", "wu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一棵初具人形的何首乌。\n");
                set("value", 10000);
                set("drug", 1);
                set("no_sell", 1);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}
 
int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit,improve;
        if (!id(arg)) return notify_fail("你要吃什么？\n");
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");
  
        if(this_object()->query("owner") != me->query("id"))
            return notify_fail("这棵何首乌好象不是你得到的吧？\n");

        if (me->query_condition("medicine")){
           me->add("max_neili", -10);
           message_vision(HIR"$N吃下一株何首乌，只觉浑身发涨，气血翻涌。\n"
                             "原来服食太急太多，药效适得其反！\n" NOR, this_player());
           log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力十点。\n",
              ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));
           me->unconcious();
        }
        else if ( neili_limit <= force_limit ){
             improve = random(2);
             me->add("max_neili", improve);
             message_vision(HIG"$N吃下一棵何首乌，顿时间觉得全身充满了活力 !\n" NOR, me);
             me->apply_condition("medicine", me->query_condition("medicine")+ 60);
             log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
             ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
        }
        else {
              message_vision(HIY "$N不顾内力修为已经到了极限，吃下一颗何首乌。\n" NOR, me);
              me->unconcious();
        }
        destruct(this_object());
        return 1;
}
