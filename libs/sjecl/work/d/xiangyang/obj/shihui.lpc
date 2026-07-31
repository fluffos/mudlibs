#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"石灰粉"NOR, ({ "shihui fen","fen" }) );
        set("long",HIW"武林中无耻之徒使的石灰粉。可以撒(sa)向敌人的眼睛。\n"NOR);
        set("unit", "小包");
        set("weight", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("blind","sa");
}

int blind(string arg)
{
        object me=this_player();
        object ob;

        if(!arg) return notify_fail("你要撒谁？\n");

        ob = present(arg, environment(me));

        if(!ob) return notify_fail("你要撒谁？\n");

        if(ob == me) return notify_fail("眼药水会比较适合。\n");

        if((ob->query("id") != "cheng ying")&&
            (ob->query("id") != "wu tianfeng")&&
            (ob->query("id") != "feng mofeng"))
                 return notify_fail("这个好像不是你的目标。\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("这个好像不是你的目标。\n");

        message_vision("$N突然向着$n撒出一堆粉末！\n",me, ob);
        if (random(me->query_skill("throwing",1)) < random(ob->query_dex()*4))
        {
                message_vision(HIR"$n对着$N闷哼一声：“无耻小贼！”\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
        message_vision(HIR"$n被$N撒中眼睛，登时眼睛剧痛，目不识物！\n"NOR,me,ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->start_busy(5);
        ob->add("dex",-20);
        ob->add("str",10);
        ob->kill_ob(me);
        destruct(this_object());
        return 1;
        }
}
