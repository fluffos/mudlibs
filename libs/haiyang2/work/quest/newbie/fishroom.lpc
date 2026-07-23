// fishroom.c
// 4/16/2000 by lag

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
你走进这里，哇，有好多的人在这里钓鱼呀！不时的传来兴
奋的喊叫声，这肯定又是有谁钓到了大鱼，看到他们忙忙碌碌、
兴奋的样子，你还有什么值得犹豫的，赶快收拾好你的鱼杠开始
钓鱼(diao)吧？里面是一间休息室。
LONG );
        set("exits", ([
//                "enter" : __DIR__"xiuxi",
                "west" : "d/shaolin/hanshui1",
        ]));
        set("no_steal", 1);
        set("no_sleep", 1);
        set("no_drop", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_fish", "fish");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

        object me;
        me = this_player();

        if (me->query("combat_exp") > 10000) {
                message_vision(HIG"江湖使者的身影突然出现在一阵烟雾之中。\n" +
            HIR "江湖使者冲着$N大喝：出去，别捣乱，这么大了还来钓鱼，你羞不羞呀！\n\n\n"NOR,me);
                    me->move("/d/shaolin/hanshui1");
                     return 1;
                                               } else
        if ( !arg || ( arg != "鱼" ) ) return 
                   notify_fail("你要钓什么啊?钓命？\n");
        else

        if (me->query("qi") < 20 )
                return notify_fail("你快支持不住了，先歇会儿吧！\n");
        else
                message_vision("$N拿着一把钓鱼杆坐在大石头上钓起鱼来……。\n", me);
        if (me->is_busy())
                return notify_fail ("你还是先装好鱼饵再说吧！\n");

                switch(random(10)) {  
                        case 0 :             
                             message_vision("$N一提杆，钓到了一条"+ HIR "大鲤鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                             me->add("potential",15+random(2));
                             me->add("combat_exp",20+random(7));
                             me->add("qi",-15);
                           break;
                        case 1 :
                             message_vision("$N猛一提杆，钓到了"+ CYN "一个破草帽"NOR +"，晦气，晦气。  \n",me);
                             message_vision(HIW "$N看着破草帽不由的发呆了。  \n\n" NOR,me);
                             me->add("qi",-5);
                           break;
                        case 2 :
                             message_vision("$N鱼漂晃动，$N心里一急，猛的一提杆，$N钓到了"+ RED "一件红色的肚兜。 \n"NOR,me);
                             message_vision(HIB "$N连声叫到：晦气，晦气。 \n\n" NOR,me);
                             me->add("qi",-7);
                           break;
                        case 3 :
                             message_vision("$N一提杆，钓到了一条"+ HIC "鲶鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                             me->add("potential",3+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("qi",-6);
                           break;
                        case 4 :
                             message_vision("$N一提杆，钓到了一条"+ HIG "鲑鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                             me->add("potential",11+random(2));
                             me->add("combat_exp",18+random(7));
                             me->add("qi",-12);
                           break;
                        case 5 :
                             message_vision("$N一提杆，钓到了一条草鱼，恭喜，恭喜。 \n\n",me);
                             me->add("potential",6+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("qi",-10);
                           break;
                        case 6 :
                             message_vision("$N一提杆，钓到了一条"+ HIB "鲟鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                             me->add("potential",7+random(2));
                             me->add("combat_exp",8+random(7));
                             me->add("qi",-5);
                           break;
                        case 7 :
                             message_vision("$N猛一提杆，钓到了"+ WHT "一个废旧的睡袋"NOR +"，晦气，晦气。 \n",me);
                             message_vision(HIY"$N看着废旧的睡袋，眼睛立刻红了。 \n\n"NOR,me);
                             me->add("qi",-3);
                           break;
                        case 8 :
                             message_vision("$N猛的一提杆，扯的太急了，线断了，鱼跑了，可惜，可惜。 \n",me);
                             message_vision(HIC "$N不由的在心里大骂:ダドパ。 \n\n" NOR,me);
                             me->add("qi",-7);
                           break;
                        default :
                             message_vision("$N一提杆，钓到了一条"+ HIM "娃娃鱼"NOR +"，恭喜，恭喜。 \n\n",me);
                             me->add("potential",10+random(2));
                             me->add("combat_exp",10+random(7));
                             me->add("qi",-8);
                           break;    
                                 }         
                         me->start_busy(2);

        return 1;
}

