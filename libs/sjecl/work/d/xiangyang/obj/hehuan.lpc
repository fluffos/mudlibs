#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"阴阳合欢散"NOR, ({ "hehuan san","san" }) );
        set("long",HIB"这是血刀老祖秘制的药粉，只需要撒(sa)一点点就能发挥做用，hehehe\n"NOR);
        set("unit", "包");
        set("weight", 90);
        set("no_sell",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("do_sa","sa");
}

int do_sa(string arg)
{
        object me=this_player() , ob;

        if(!arg) return notify_fail("你要撒谁？\n");

        ob = present(arg, environment(me));
        if(!ob) return notify_fail("你要撒谁？\n");

        if(ob==me) return notify_fail("这要是真的用了.....\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("这个好像不是你的目标。\n");

        if(ob->query("id")!="guo fu" && ob->query("id")!="guo xiang" )
                return notify_fail("这个好像不是你的目标。\n");

        message_vision("$N轻轻的将药粉向$n撒去。\n",me, ob);
        if (random(me->query_skill("force",1)) < random(ob->query_con()*4))
        {
                message_vision(HIR"$N的药粉尚未及身，就被$n以内力振了开去！\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
       message_vision(HIB"$N"HIB"嘿嘿阴笑了几声，用指甲向$n"HIB"轻轻弹了点粉沫。\n"MAG"不一会儿，$n"MAG"就满面通红的晕了过去！\n",me, ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->unconcious();
        destruct(this_object());
        return 1;
        }
}
