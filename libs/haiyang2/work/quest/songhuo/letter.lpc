#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"货物"NOR, ({"huo wu", "huo wu"}));
        set("long",
               "这是陈老板要你送的货物。\n");
        set("unit", "包");
        set("weight", 200);
        set("no_steal",1);
        set("no_beg", 1);
        set("no_put",1);
        set("no_drop", 1);
        set("no_get", 1);

        setup();
}

void init()
{
        add_action("do_sendto","sendto");
	remove_call_out("go");
	call_out("go",3);	
}

int do_sendto(string arg)
{
object ob=this_object(),me=this_player();
object obn;
int i;
string targ;
int exp,pot;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要把货物送给谁？\n");
        targ=ob->query("name");
if ( targ != me->query("quest/quest") ) return notify_fail("这是送给"+me->query("quest/quest")+"的货物，你怎么能随便乱给呢？\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n"); //玩家可能有相同于NPC的名字
        if ( (int) me->query("task_time") < time() )
        {
             return notify_fail(targ+"冷冷地说：“你来晚了,坏了我的大事！”\n");
        }
        tell_object(me,"你把货物交给了"+targ+"。\n" NOR );
        exp=me->query("quest/exp_bonus");
        pot=me->query("quest/pot_bonus");
        tell_object(me,HIW""+targ+"大喜道：多谢您及时送货物给我，你被奖励了：\n"        +chinese_number(exp)+"点经验值。\n"
        +chinese_number(pot)+"点潜能。\n\n"NOR);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest",0);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
        me->delete("tzjob");
	destruct(this_object());
//        destruct(present("huo wo",me));
        return 1;
}
void owner_is_killed() { destruct(this_object()); }

