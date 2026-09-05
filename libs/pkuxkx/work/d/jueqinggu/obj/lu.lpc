#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"炼丹炉"NOR, ({ "liandu lu", "lu" }) );
        set_weight(3000000);
        set("unit", "座");
        set("long", "这是一座巨大的炼丹炉。轻易不可接触(touch)。\n");
        
        set("value", 1000);
        set("material", "stone");
        set("no_get",1);
        set("no_drop",1);
               
        setup();
}

void init()
{
    add_action("do_mo", ({"mo","touch"}));
}

int do_mo()
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    message_vision(MAG"$N用手摸了摸炼丹炉，瞬间$N的脸变成了猪肝色，太烫了！\n"NOR,me);
    me->apply_condition("tangshang", 2+random(4));
    if (me->query("qi")<1000)
    {
        message_vision("$N疼痛难忍，晕了过去。",me);
        me->unconcious();
        return 1;
    }
    else
    {
        me->add("qi",-1000);
        tell_object(me,RED"你吹了吹被烫红的手，可是还是钻心地疼！\n"NOR);
        return 1;
    }
}