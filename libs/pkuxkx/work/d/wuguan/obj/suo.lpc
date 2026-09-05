//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIW"石锁"NOR, ({ "shi suo","suo"}));
	set_weight(50000);
	set("long", "这是一具石锁，份量不轻。\n");
	set("material", "stone");
	set("unit", "具");
	set("value", 1);
    set("is_shisuo",1);
	setup();
}

void init()
{
    add_action("do_ju","ju");
}

int do_ju()
{
    object room,me=this_player();
    if (!me->query_temp("wg/permit"))
    {
        tell_object(me,"你没和武馆教头打过招呼，怎么能用人家的东西？\n");
        return 1;
    }
    if (!present(this_object(),me))
    {
        tell_object(me,"你至少要把"+this_object()->query("name")+"拿起来再举吧？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (base_name(environment(me))!="/d/wuguan/wuguan_liangong")
    {
        tell_object(me,"石锁怎么被你带到了这里？快还回去。\n");
        return 1;
    }
    message_vision(HIW"$N缓缓举起石锁，再缓缓放下。\n"NOR,me);
    me->add_busy(2);
    if (!random(10)&&environment(me))
    {
        room=environment(me);
        this_object()->move(room);
    }
    if (random(2))
    {
        me->add("statistics/newbie_target/wg_suo_degree",1);
    }
    if (me->query("statistics/newbie_target/wg_suo_degree")>250)
    {
        tell_object(me,"你觉得自己已经把身体练得很棒了，可以去找郭大侠从军了。\n");
    }
    return 1;
}