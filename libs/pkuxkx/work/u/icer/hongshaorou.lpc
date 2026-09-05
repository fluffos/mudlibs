#include <ansi.h>

inherit ITEM;

string *names = ({
      HIG + "红烧肉" + NOR,
      MAG + "红烧肉" + NOR,
      HIY + "红烧肉" + NOR,
      HIW + "红烧肉" + NOR,
      
});


void init()
{
      add_action("do_eat","eat");
}

void create()
{
    set_name( names[random(sizeof(names))] , ({ "hongshao rou","rou" }) );
    set("unit","块");
    set("long", HIW"这是一大块红烧肉，是icer做来向我们伟大祖国50周年华诞献礼的。\n它闻起来很香很香，你的肚子不禁开始咕咕地叫了。\n"NOR);
    set("value",100000);
    set("count",2);
    setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!(arg == "hongshao rou" || arg == "rou"))
         return notify_fail("你要吃什么?\n");
    this_player()->add_temp("rou/eaten",1);
    if ( this_player()->query_temp("rou/eaten") > 3) 
    {
        message_vision(HIR"$N虽然已经腻得不得了，但还是鼓起勇气又咬了一大口红烧肉，立刻开始「哇哇」的吐啊吐，\n把刚才吃的红烧肉全都吐出来了。\n",me);
        me->set("qi",1);
        me->set("jing",1);
        destruct(this_object());
        return 1;
    }
    if (query("count") == 2)
    {
            message_vision(HIG"$N咬了一口" + this_object()->query("name") + NOR + HIG + "，发现又香又烂，香甜可口，真不愧是icer的手艺。\n"NOR,me);
            set("count",1);
            return 1;
    }
    else if (query("count") == 1)
         {
                message_vision(HIR"$N迫不及待地一口把剩下的" + this_object()->query("name") + NOR + HIR + "全吃了下去，只觉得肚子充实多了，而且人也精神了许多。\n"NOR,me);
                destruct(this_object());
                return 1;
         }
    return 1;

}

