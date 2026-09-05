#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("樟木桶", ({"zhangmu tong", "mu tong", "tong"}));
    set_weight(1300);
    set("unit", "个");
    set("long","这是一个樟木桶，挑(tiao)好水后，你可以灌(guan)进后院的缸里。。\n");
	set("material", "wood");
    set("full",0);
    setup();
}

void init()
{
    add_action("do_tiao","tiao");
    add_action("do_guan","guan");
}

int do_tiao()
{
    object ob=this_object();
    object me=this_player();
    object env=environment(me);
    if (ob->query("full"))
    {
        tell_object(me,"桶已经满了。\n");
        return 1;
    }
    if (env->query("couldfish")||base_name(env)=="/d/tianlong/foothill")
    {
        ob->set("full",1);
        message_vision("$N打下了满满一桶水。\n",me);
        return 1;
    }
    tell_object(me,"此处并无水源，你要怎么挑水？\n");
    return 1;
}

int do_guan()
{
    object ob=this_object();
    object me=this_player();
    object env=environment(me);
    if (me->query("family/family_name")!="天龙寺")
    {
        tell_object(me,"本寺不需要外人帮手。\n");
        return 1;
    }
    if (!ob->query("full"))
    {
        tell_object(me,"你要用空桶灌什么？\n");
        return 1;
    }
    if (base_name(env)=="/d/tianlong/houyuan")
    {
        ob->delete("full");
        message_vision("$N把桶里的水都倒进了水缸里。\n",me);
        if (NATURE_D->get_current_day_phase()=="下午"&&me->query("combat_exp")<10000)
        {
            me->set_temp("tlnewbiejob/newbie/tiaoshui",2);
            return 1;
        }
        return 1;
    }
    else
    {
        ob->delete("full");
        message_vision("$N把桶里的水随意地倒在了地上。\n",me);
        return 1;
    }
}


