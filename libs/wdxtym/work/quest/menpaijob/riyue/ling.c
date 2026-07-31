// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+8;
void create()
{
        set_name("传单", ({ "chuan dan"}));
        set("long", "一些传单,有了它的日月弟子一般负责游说(youshuo)任务");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "些");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","youshuo");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot,b;

if (!environment(me))  return notify_fail("这里不是要你做游说的地方!\n");
if (me->query_temp("ryjob2/changxi") < 1)
return notify_fail("没人现在叫你做这个任务!\n");
if (!environment(me)->query("outdoors"))
return notify_fail("请到户外人多的地方做游说!\n");
if (environment(me)->query("outdoors") !=me->query_temp("ryjob2/where"))
return notify_fail("不是叫你到"+me->query_temp("ryjob2/cx")+"去做游说的吗!\n");
if (me->query_temp("ryjob2/done") >= 1)
{
        tell_object(me,"你已做完游说了，回去领功吧。\n");
         return 1;
}


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

        if ((me->query("jing") < 30))
        {  
          tell_object(me,"你的精力不能集中！\n");
          return 1;
        }
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"你的身体状态太差!\n");
          return 1;
        }
b=random(4);
message_vision(HIY"\n$N在"+me->query_temp("ryjob2/cx") + "派附近做起了游说!\n"NOR,me);
if (b==0)
message_vision(CYN"\n$N说，你们这些所谓的明门正派哪里我们日月神教的对手!\n"NOR,me);
else if (b==1)
message_vision(RED"\n$N说，日月神教一江湖，及众望所归也!\n"NOR,me);
else if (b==2)
message_vision(WHT"\n$N说，日月神教，日出东方，唯我不败!\n"NOR,me);
else message_vision(GRN"\n$N说，日月神教，千秋万载，一统江湖!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("ryjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(50)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIM"五岳剑派护法"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"附近突然，闪出一人！\n"NOR, obj);
message_vision(HIR"$N说道：魔教妖人，尽敢在此胡说八道，我要替天行道！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}

if ((int)me->query_temp("ryjob") >i && 
!me->is_fighting())
{
message_vision(HIM"$N的游说工作好像做的很好,附近的门派人物好像对自己的门派有所失望。\n"NOR,me);
message_vision(HIC"$N任务完成，把所有的传单发给了众人。\n"NOR,me,ob); 
me->set_temp("ryjob2/done",1);
me->set_temp("ryjob",0);
me->delete_temp("ryjob");
me->start_busy(3);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
if (!me) return;
        me->delete_temp("ryjob");
        destruct(this_object());
}
