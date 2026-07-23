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
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if ( me->query_skill_mapped("force") != "yunu-xinjing"){
                me->add("max_neili", -10);
                message_vision(HIR "$N轻轻咬得一口圆球，只觉得肝肠寸断，口中奇苦难当。\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }
        if ( me->query("max_neili") < 400
          && me->query("max_neili") > 2){
                me->add("max_neili", -3);
                message_vision(HIR "$N轻轻咬得一口圆球，只觉汁液腥极苦极，难吃无比，原来功力还不足以抵挡药效。\n" NOR, me);
        }
        else if ((int)me->query_condition("medicine" ) > 0 ){
                me->add("max_neili", -5);
                message_vision(HIR "$N轻轻咬得一口圆球，只觉汁液腥极苦极，难吃无比，原来频繁吃药暂不能抵挡药效。\n" NOR, me);
        }
        else {
                me->add("max_neili", random(1) + 1);
                message_vision(HIG"$N轻轻咬得一下，圆球外皮便即破裂，登时满口苦汁。但过了一会，\n"+
                                  "略行运气，便觉呼吸顺畅，精神大旺，尤胜平时。 \n" NOR, me);
        }
        me->apply_condition("medicine", 25+random(10));
        destruct(this_object());
        return 1;
}
