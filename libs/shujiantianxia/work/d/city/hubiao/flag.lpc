// OBJ: flag.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

string* dir_alias = ({
        "n","north","e","east",
        "w","west","s","south",
        "nu","northup","eu","eastup",
        "wu","westup","su","southup",
        "nd","northdown","ed","eastdown",
        "wd","westdown","sd","southdown",
        "ne","northeast","se","southeast",
        "nw","northwest","sw","southwest",
        "u","up","d","down","out"
});

void setup()
{}

void init()
{
        add_action("do_here", "here");
        add_action("do_lead", "lead");
}

void create()
{
        set_name("镖旗", ({"biao qi", "qi", "flag"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "面");
              set("long", HIY "这是一面龙门镖局的镖旗，一般的强盗见了，由于害怕镖局的威名，早远远躲开了。\n");
              set("value", 1000);
              set("no_drop", 1);
              set("no_give", 1);
              set("no_get", 1);
        }
        setup();
}

int do_here(string str)
{
        object ob,ob_mubiao,my_object,me = this_player();
        if (!str)
                return notify_fail("你要把人家女眷往这里一扔就不管么？！\n");
        if (!(my_object = present(str, environment(me))))
                return notify_fail("你要找的人不在这里。去别处找找看吧。\n");

        if (!(ob_mubiao = present("nv juan", environment(me))))
                return notify_fail("人都让你弄丢了，跑这里领什么功劳!\n");

        if (my_object->query("name") != me->query_temp("mubiao"))
                return notify_fail(my_object->query("name")+"说道："+RANK_D->query_respect(me)+"你开什么玩笑？这不是我的家眷！\n");
        if (!living(my_object))
                return notify_fail("哦，你得先把他弄醒在说。\n");
        tell_object(me, HIW + my_object->query("name")+"惊讶地「啊！」了一声。\n");
        tell_object(me, HIW + RANK_D->query_respect(me)+"使我们夫妻团聚，恩同再造！请受在下一拜！\n" NOR);
        tell_object(me, HIW "这是在下一点小小的意思，大师一定要收下。\n" NOR);

        me->delete_temp("mubiao");
        me->delete_temp("killed");

        me->add("potential",80+random(50));
        me->add("combat_exp",160+random(100));
        ob = present("gold_money", me);
        if (!ob)
        {
                ob = new("/clone/money/gold");
                ob->move(me);
                ob->set_amount(5+random(5));
        }
        else
        {
                ob->add_amount(5+random(5));
        }

        me->apply_condition("husong_job", 0);
        destruct(this_object());
        destruct(me->query_temp("husongjob"));
        me->delete_temp("pass");
        me->delete_temp("mubiao");
        me->delete_temp("husongjob");
        me->delete_temp("killed");

        return 1;
}

int do_lead(string str)
{
        object ob_mubiao,me = this_player();
        int i, flag = 0;
        if (!str)
                return notify_fail("你要把人家女眷往什么地方领？！\n");

	for ( i = 0; i<sizeof(dir_alias); i++)
		if (str == dir_alias[i]) { flag = 1; break;}
	if (!flag) return notify_fail("你要把人家女眷往什么地方领？！\n");

        if (!(ob_mubiao = present("nv juan", environment(me))))
                return notify_fail("你带的女眷不在这里啊!\n");
        if (me->query_temp("mubiao") != ob_mubiao->query_temp("mubiao"))
        	return notify_fail("不要乱领哦，小心出事。\n");

	ob_mubiao->force_me(str);

        return 1;
}
