#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"蒙汗药"NOR, ({ "menghan yao","yao" }) );
        set("long",HIG"武林中无耻之徒使的蒙汗药。趁人不备时下药(xiayao)。\n"NOR);
        set("unit", "小包");
        set("weight", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("poison","xiayao");
}

int poison(string arg)
{
        object me=this_player();
        object ob;

        if(!arg) return notify_fail("你要对谁下药？\n");

        ob = present(arg, environment(me));

        if(!ob) return notify_fail("你要对谁下药？\n");

        if((ob->query("id") != "wu dunru")&&
            (ob->query("id") != "wu xiuwen")&&
            (ob->query("id") != "yelv yan")&&
            (ob->query("id") != "wanyan ping"))
                 return notify_fail("这个好像不是你的目标。\n");

        if(ob == me) return notify_fail("虽然看起来很好吃，不过还是小心点吧。\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("这个好像不是你的目标。\n");

        message_vision("见到$N趁著没人注意，突然手向着$n的杯子抖了一下。\n",me, ob);
        if (random(me->query_skill("poison",1)) < random(ob->query_int()*4))
        {
                message_vision(HIR"$n对着$N大喝一声：“做什么！？”\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
        message_vision(HIR"$n不经意的拿起杯子喝了一口，眼前陡然一黑。\n"NOR,me,ob);
        message_vision(HIR"$N趁机把$n拉到一边。$n身子一晃，就倒在地上。\n"NOR,me,ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->unconcious();
                destruct(this_object());
        return 1;
        }
}
