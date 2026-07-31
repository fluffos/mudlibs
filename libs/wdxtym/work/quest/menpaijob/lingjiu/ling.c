// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("灵鹫宫令牌", ({ "lj lingpai"}));
        set("long", "一块灵鹫宫令牌,有了它的弟子一般负责讨贡品任务(shougongpin)");
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
        add_action("do_shouzhang","shougongpin");
}

int do_shouzhang(string arg)
{
object ob,me=this_player(),obj,obn;
string targ;
int maxpot;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("你要向谁收贡品？\n");
if(!me->query_temp("ljjob2"))
return notify_fail("你不能用这令牌做任务。\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("不能向玩家讨!\n");
if ( ob->query("family/family_name") != me->query_temp("ljjob2") )
return notify_fail("这是叫你向"+me->query_temp("ljjob2")+"讨贡品的令牌!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("这不是你的令牌!!\n");
if( !living(ob))
return notify_fail("人家正昏着呢！\n");
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
        if (ob->query("combat_exp")*2/3 > me->query("combat_exp"))
        {  
          tell_object(me,"那个人武功看来比你高的多，向他要不太好吧！\n");
          return 1;
        }
        if (ob->query("startroom") != base_name(environment(ob)))
        {  
          tell_object(me,"那个人说：东西不在这里，等会，跟他回去再给你！\n");
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

message_vision(HIC"\n$N对$n说：你们为童姥准备的东西好了没有?\n"NOR,me,ob);
message_vision(HIG"\n$n一看是灵鹫宫的$N马上说道：贡品已经准备好了。并给了$N一个大盒子  。\n"NOR,me,ob);
                        me->add("jing",-me->query("jing")/10);
                        me->add("qi", -me->query("qi")/10);
                        me->start_busy(6);

message_vision(HIW"$N看了看对$n说,东西还不错。\n"NOR,me,ob);
message_vision(HIG"$N把令牌给了$n。\n$N说道：生死符解药就用这个去领吧\n"NOR,me,ob); 
          obn=new(__DIR__"gongpin");
          obn->set("ljby",me->query("name"));
          obn->move(me);

        destruct(this_object());
        return 1;

}
