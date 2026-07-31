// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+8;
void create()
{
        set_name("五行旗", ({ "wuxing qi"}));
        set("long", "一面五行旗,有了它的弟子一般负责协助(xiezhu)任务");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "面");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","xiezhu");
}
int do_shouzhang(string arg)
{
object ob,me=this_player(),obj;
string targ;
int maxpot;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("你要协助谁？\n");
if(!me->query_temp("mj2job"))
return notify_fail("你不能用这令旗做任务。\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("你想干什么!!那不是目标\n");
if ( targ != me->query_temp("mj2job") )
return notify_fail("这是叫你协助"+me->query_temp("mj2job")+"的五行旗!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的令旗!!\n");

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

message_vision(HIC"\n$N和$n为了反抗元兵，开始努力工作!\n"NOR,me,ob);
message_vision(HIG"\n$N边干活边喊着豪迈的号子：“反抗元兵，光我圣教。。。\n"NOR,me,ob);
                        me->add("jing",-10);
                        me->add("qi", -5);
                        me->start_busy(1);
me->add_temp("mjjob2",1);
if( !environment(me)->query("no_fight"))
{
if (random(60)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIC"元兵探子"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"附近突然，闪出一人！\n"NOR, obj);
message_vision(HIR"$N说道：你等私造武器，此等大罪，还不受降！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("mjjob2") >i)
{
message_vision(HIW"\n$n对$N说好了,今天的活终于做好了，休息去吧。\n"NOR,me,ob);
message_vision(HIG"$N任务完成，把令旗交给了$n。\n"NOR,me,ob); 
        me->set_temp("mjjob2",0);
        me->delete_temp("mjjob2");
me->start_busy(5);
call_out("destroying", 0, me);                       
}
        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=60+random(80);
pot=45+random(50);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
me->apply_condition("mj2_busy",2);
        me->delete_temp("mj2job");
        me->delete_temp("mjjob2");
        me->add("combat_exp",exp);
        me->add("potential",pot);
        destruct(this_object());
}