#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("信件", ({"xin", "letter"}));
        set("long",
               "这是信使托付你的信件，你可以用songxin <id>来送给别人。\n");
        set("unit", "封");
        set("weight", 5);
        set("no_put",1);
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_songxin","songxin");
}

int do_songxin(string arg)
{
object ob=this_object(),me=this_player();
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要把信送给谁？\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("这是送给"+me->query("quest/quest")+"的信，你怎么能随便乱给呢？\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n"); //玩家可能有相同于NPC的名字
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"冷冷地说：“你来晚了,耽误了我的大事，你还有脸来见我！”\n");
        }
        tell_object(me,"你把信交给了"+targ+"。\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
        tell_object(me,HIW""+targ+"大喜道：多谢您及时送信给我，你被奖励了：\n"
        +chinese_number(exp)+"点经验值。\n"
        +chinese_number(pot)+"点潜能。\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest",0);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
        me->delete("songxin");
        destruct(present("xin",me));
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

