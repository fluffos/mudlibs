// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+10;
void create()
{
        set_name("宣传资料", ({ "xuanchuan ziliao"}));
        set("long", "一些宣传资料,有了它的云龙弟子一般负责宣传(xuanchuan)任务");
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
        add_action("do_shouzhang","xuanchuan");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot,b;

if (!environment(me))  return notify_fail("这里不是要你做宣传的地方!\n");
if (me->query_temp("yljob2/changxi") < 1)
return notify_fail("没人现在叫你做这个任务!\n");
if (!environment(me)->query("outdoors"))
return notify_fail("请到户外人多的地方做宣传!\n");
if (environment(me)->query("outdoors") !=me->query_temp("yljob2/where"))
return notify_fail("不是叫你到"+me->query_temp("yljob2/cx")+"去做宣传吗!\n");
if (me->query_temp("yljob2/done") >= 1)
{
        tell_object(me,"你已做完宣传了，回去领功吧。\n");
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

message_vision(HIY"\n$N在"+me->query_temp("yljob2/cx") + "做起了宣传!\n"NOR,me);
b=random(4);
if (b==0)
message_vision(CYN"\n$N说，我等都是汉人，怎能在满人统冶下生活!\n"NOR,me);
else if (b==1)
message_vision(RED"\n$N说，满人在扬州屠城，不知死了多少百姓!\n"NOR,me);
else if (b==2)
message_vision(WHT"\n$N说，满人为了震压汉人，搞文字狱不知害死了多少有识之士!\n"NOR,me);
else message_vision(GRN"\n$N说，我等天地会，遍布天地之间，定能反清复明!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("yljob",1);
if( !environment(me)->query("no_fight"))
{
if (random(50)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIM"清廷爪牙"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"附近突然，闪出一人！\n"NOR, obj);
message_vision(HIR"$N说道：天地会反贼，快快受死！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}

if ((int)me->query_temp("yljob") >i && 
!me->is_fighting())
{
message_vision(HIM"$N的宣传工作好像做的很好,附近的众人均表示支持反清复明。\n"NOR,me);
message_vision(HIC"$N任务完成，把所有的宣传资料发给了众人。\n"NOR,me,ob); 
me->set_temp("yljob2/done",1);
me->set_temp("yljob",0);
me->delete_temp("yljob");
me->start_busy(3);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
if (!me) return;
        me->delete_temp("yljob");
        destruct(this_object());
}