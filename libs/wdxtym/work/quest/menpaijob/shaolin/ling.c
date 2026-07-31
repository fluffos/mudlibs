// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(11)+5;
void create()
{
        set_name("武僧堂令牌", ({ "ling pai"}));
        set("long", "一块少林寺常用的武僧堂令牌,你可以用它和别的武僧zuanyan武功");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "块");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","zuanyan");
}
int do_shouzhang(string arg)
{
object ob,me=this_player();
string targ;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("你要和谁钻研武学？\n");
if(!me->query_temp("wsdjob"))
return notify_fail("你不能用这块令牌做任务。\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("你想干什么!!那不是目标\n");
if ( targ != me->query_temp("wsdjob") )
return notify_fail("这是叫你和"+me->query_temp("wsdjob")+"钻研武学的令牌!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的武僧堂令牌!!\n");

        if (me->is_busy())
        {
          tell_object(me,"你正忙着呢！\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再说吧，！\n");
          return 1;
        }

        if ((me->query("jing") < 50))
        {  
          tell_object(me,"你的精力不能集中！\n");
          return 1;
        }
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"你的身体状态太差!\n");
          return 1;
        }

message_vision(HIW"\n$N和$n一招一试的钻研起少林奇功--"+me->query_temp("wsdskl") + "!\n"NOR,me,ob);
                        me->add("jing",-10);
                        me->add("qi", -5);
                        me->start_busy(1);
me->add_temp("wsjob",1);
if (me->query_temp("wsjob") >i)
{
message_vision(HIW"\n$n对$N说够了,今天就练到这里吧，我也累了。\n"NOR,me,ob);
message_vision(HIG"$N任务完成，把令牌交给了$n。\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}
        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=80+random(80);
pot=60+random(60);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
me->apply_condition("slwsd_busy",2);
        me->delete_temp("wsdjob");
        me->delete_temp("wsdskl");
        me->delete_temp("wsjob");
        me->add("combat_exp",exp);
        me->add("potential",pot);
        destruct(this_object());
}