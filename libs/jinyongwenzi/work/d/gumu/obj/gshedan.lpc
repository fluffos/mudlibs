// gshedan.c 毒蟒胆

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
        set_name(MAG"毒蟒胆"NOR, ({"dumang dan", "mangdan", "dan" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "一颗深紫色腥臭圆球。\n");
                set("no_drop", 1);                
                set("no_give", 1);
                set("no_sell", 1);
                set("drug", 1);
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit, i,improve;
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");
        i = (me->query("str") + 10) * 10; 

        if (!id(arg)) return notify_fail("你要吃什么？\n");

        if(this_object()->query("owner") != me->query("id"))       
            return notify_fail("这颗毒蟒胆好象不是你得到的吧？\n");

        if ( me->query("max_neili") < 400 
          && me->query("max_neili") > 2){
                me->add("max_neili", -3);
                message_vision(HIR "$N轻轻咬得一口圆球，只觉汁液腥极苦极，难吃无比，原来功力还不足以抵挡药效。\n" NOR, me);
                log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力三点。\n",
                           ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));

        }
        else if ((int)me->query_condition("medicine" )){
                me->add("max_neili", -10);
                message_vision(HIR "$N轻轻咬得一口圆球，只觉汁液腥极苦极，难吃无比，原来频繁吃药暂不能抵挡药效。\n" NOR, me);
                log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力十点。\n",
                           ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));
        }
        else {
             if( neili_limit <= force_limit) {
             	improve = random(2);
                me->add("max_neili", improve);
                me->apply_condition("medicine", me->query_condition("medicine")+ 60);                
                message_vision(HIG"$N轻轻咬得一下，圆球外皮便即破裂，登时满口苦汁。\n"+
                                  "但过了一会，略行运气，便觉呼吸顺畅，精神大旺，尤胜平时。 \n" NOR, me);
                log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
             }
             else {
        	me->add("food", 200);
        	if( me->query("food") >= i)
        	me->set("food", i + 50);
                message_vision(HIG"$N轻轻咬得一下，圆球外皮便即破裂，登时满口苦汁。\n"NOR,me);
             }
        }
        destruct(this_object());
        return 1;
}
