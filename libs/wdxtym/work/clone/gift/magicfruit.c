// xiandan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "魔界佛心果" NOR, ({ "magic fruit", "magic", "fruit" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗同时泛着奇异魔光和佛光的果实，不知道吃了会有什么效果。\n");
                set("value", 10000);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

        if (me->query("gift/int/fail"))
        {
                me->add("gift/int/fail", -1);
                if (me->query("gift/int/all"))
                {
                        me->add("gift/int/all", -1);
                        if (me->query("gift/int/all") < 1)
                                me->delete("gift/int/all");
                }
                else
                        me->add("gift/xiandan", -1);
                if (me->query("gift/int/fail") < 1)
                        me->delete("gift/int/fail");
        } else
        if (me->query("gift/str/fail"))
        {
                me->add("gift/str/fail", -1);
                if (me->query("gift/str/all"))
                {
                        me->add("gift/str/all", -1);
                        if (me->query("gift/str/all") < 1)
                                me->delete("gift/str/all");
                }
                else
                        me->add("gift/shenliwan", -1);                
                if (me->query("gift/str/fail") < 1)
                        me->delete("gift/str/fail");
        } else
        if (me->query("gift/con/fail"))
        {
                me->add("gift/con/fail", -1);
                if (me->query("gift/con/all"))
                {
                        me->add("gift/con/all", -1);
                        if (me->query("gift/con/all") < 1)
                                me->delete("gift/con/all");
                }
                else
                        me->add("gift/xisuidan", -1);                
                if (me->query("gift/con/fail") < 1)
                        me->delete("gift/con/fail");
        } else  
        if (me->query("gift/dex/fail"))
        {
                me->add("gift/dex/fail", -1);
                if (me->query("gift/dex/all"))
                {
                        me->add("gift/dex/all", -1);
                        if (me->query("gift/dex/all") < 1)
                                me->delete("gift/dex/all");
                }
                else
                        me->add("gift/unknowdan", -1);
                if (me->query("gift/dex/fail") < 1)
                        me->delete("gift/dex/fail");
        } 
        
        tell_object(me, HIG "一股火热蓦然从全身升起，"
                            "你全身欲裂，恰在此时一股舒坦之意"
                            "油然而起，顿感全身舒服多了。\n" NOR);

        destruct(this_object());
        return 1;
}


