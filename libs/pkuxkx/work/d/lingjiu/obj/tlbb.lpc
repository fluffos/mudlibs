// Modified by iszt@pkuxkx, 2007-03-11

#include <ansi.h>
#include <skill.h>

inherit ITEM;

void create()
{       
        set_name(MAG"天龙八部"NOR,({ "tianlong", "babu" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", WHT"这是一脍炙人口的武侠小说，叙述了大量神妙的刀法剑法。\n高手通过阅读可以提高自己的功夫。\n"NOR);
                set("value", 5000);
                set("material", "paper");                       
        }
}

void init()
{
        add_action("do_read","read");
}                           

int do_read(string arg)
{
        object me = this_player(), where = environment(me);
        string book;
        int times, swordskill, bladeskill;

        if(!arg || (sscanf(arg, "%s %d",book,times) < 1 ))
        {
                return notify_fail("指令格式：read tianlong [次数]\n");
        }
        if (  ( book != "tianlong" && arg!= "babu") )
                return 0;
        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if ( (int)me->query_skill("literate", 1) < 100)
                return notify_fail("你的文化水平太低了，不能领会书中这么高深的功夫。\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(times>50)
                return notify_fail("你也太贪了，最多做50次！\n");
        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来研读新知！\n");
        swordskill = me->query_skill("sword",1);
        bladeskill = me->query_skill("blade",1);
        if (swordskill<100 || bladeskill<100)
                return notify_fail("你的基本功夫太低，不能通过阅读本书来进一步提高！\n");
        if ((int)me->query("jing") < 30 * times)
        {
                write("你已经很累了，歇歇再读吧，身体要紧。\n");
                return 1;
        }

        me->receive_damage("jing", 30 * times);
        message_vision("$N正专心阅读天龙八部。\n", me);

        switch( random(2) ) 
        {
        case 1:
                if( swordskill * swordskill * swordskill / 10 > (int)me->query("combat_exp") )
                        printf("也许是缺乏实战经验，你对天龙八部上面所描述的功夫总是无法领会。\n");
                else if ( (int)me->query_skill("sword", 1) < 180)
                {
                        me->improve_skill("sword", me->query("int") * times);
                        write("你思索着小说中关于剑法描述，对基本剑法有一些新的理解。\n");
                }
                else
                        write("你看着看着觉得书中人物的剑法也不过如此。\n");
                return 1;
        case 0:
                if( bladeskill * bladeskill * bladeskill / 10 > (int)me->query("combat_exp") )
                        printf("也许是缺乏实战经验，你对天龙八部上面所描述的功夫总是无法领会。\n");
                else if ( (int)me->query_skill("blade", 1) < 180)
                {
                        me->improve_skill("blade", me->query("int") * times);
                        write("你思索着小说中关于刀法的描述，对基本刀法有一些新的理解。\n");
                }
                else
                        write("你看着看着觉得书中人物的刀法也不过如此。\n");
                return 1;
        }

        write("你拿起天龙八部翻看了一会儿，觉得那里面描述的功夫也太一般了。\n");
        return 1;
}
