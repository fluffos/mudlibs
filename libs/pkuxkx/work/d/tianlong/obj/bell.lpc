#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"黄铜大钟"NOR, ({"da zhong", "zhong"}));
    set_weight(1000000);
    set("unit", "口");
    set("long","这是一口巨大的黄铜钟。\n");
    set("no_get",  "别做梦了，这口钟有上千斤，你搬不动它。\n");
    set("material", "bronze");
    setup();
}

void init()
{
    add_action("do_knock","knock");
}

int do_knock()
{
    object me=this_player();
    object *ob;
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (NATURE_D->get_current_day_phase()=="早晨"&&me->query("combat_exp")<10000&&me->query("family/family_name")=="天龙寺")
    {
        me->set_temp("tlnewbiejob/newbie/qiao",2);
    }
    message_vision("$N敲响了黄铜大钟。\n",me);
    me->add_busy(1+random(5));
    message( "channel:" + "chat",HIG "一声沉闷的钟声从天龙寺的钟楼上传出。\n" NOR, ob );
    return 1;
}


