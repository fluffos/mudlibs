#include <ansi.h>

inherit ITEM;

string *names = ({
      BNK + HIG + "芙蓉月饼" + NOR,
      BNK + MAG + "枣泥月饼" + NOR,
      BNK + HIY + "蛋黄月饼" + NOR,
      BNK + HIW + "莲蓉月饼" + NOR,
      
});


void init()
{
      add_action("do_eat","eat");
}

void create()
{
    set_name( names[random(sizeof(names))] , ({ "moon cake","cake" }) );
    set("unit","个");
    set("long", HIW"这是一块圆圆的月饼，上面写着“天涯共此时”五个字，\n让你不禁想起远在天边的家人和那个谁。\n"NOR);

    set("value",0);
    set("count",3);
    setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!(arg == "moon cake" || arg == "cake"))
         return notify_fail("你要吃什么?\n");
    this_player()->add_temp("mooncake/eaten",1);
    if ( this_player()->query_temp("mooncake/eaten") > 5 ) 
    {
        message_vision(HIR"$N冒着撑死的巨大危险，又吃了一口月饼，结果肚子剧烈疼痛，在地上直打滚。\n",me);
        me->set("qi",1);
        me->set("jing",1);
        destruct(this_object());
        return 1;
    }
    if (query("count") == 3)
    {
            message_vision(HIG"$N轻轻咬了一口" + this_object()->query("name") + NOR + HIG + "，只觉得香甜可口，忍不住要再咬一口。\n"NOR,me);
            set("count",2);
            return 1;
    }
    else if (query("count") == 2)
         {
                message_vision(HIR"$N又咬了一口" + this_object()->query("name") + NOR + HIR + "，只觉得满口生香，忍不住又要咬第三口。\n"NOR,me);
                set("count",1);
                return 1;
         }
         else if (query("count") == 1)
                {
                        message_vision(HIW"$N狠了狠心，一个大口把剩下的" + this_object()->query("name") + NOR + HIW + "全都吃了下去，噎得直打嗝。\n"NOR,me);
                        destruct(this_object());
                }
    return 1;

}

