// created by Keepon
// modified by Darken
// 改成非出家人也能静坐，不过花的时间更多，报酬更少。
// 经验上限提高到 3000000，不过经验越高，得到的潜能越少。
// Modify By River@SJ 2000/3/14 
// Exp 上限 1M ,pot得到 略调。
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me);

int main(object me)
{
        object where;
        seteuid(getuid());
        where = environment(me);
        if(!where->query("jingzuo"))
              return notify_fail("这里不是静坐的地方。\n");

        if(me->query("family/family_name") != "峨嵋派")
              return notify_fail("不是峨嵋派弟子在这里瞎捣什么乱？\n");

        if(me->query("class")!="bonze" && me->query_skill("dacheng-fofa",1) < 200)
              return notify_fail("你身为俗家弟子，大乘佛法需要极高的修为才能静坐。\n");

        if((int)me->query_skill("dacheng-fofa", 1) < 30 )
              return notify_fail("你大乘佛法未到火候，不能静坐修练。\n");

        if(me->is_busy() || me->is_fighting())
              return notify_fail("你正忙着哪！\n");

        if( me->query("combat_exp") > 1000000 )
              return notify_fail("以你现在的修为，已经不能通过静坐修炼了。\n");
        
        if(me->query_temp("pending/jingzuo"))
              return notify_fail("你正在静坐中。\n");

        if ((int)me->query("jingli", 1) < 30 )
              return notify_fail("你太累了，还是好好休息吧。\n");

        message_vision(HIW"$N现出略有所悟的神情，先侧头想了一会，然后，在地上坐了下来，盘起了腿。\n"NOR, me);
        me->set_temp("pending/jingzuo", 1);
        me->set_temp("exercise_cost", 50+random(60));
// 不是出家人，时间较长
        if (me->query("class")!="bonze")
          me->set_temp("exercise_cost", 100+random(50));
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
        object where;
        int gps;
        int exercise = (int)me->query_temp("exercise_cost");
        where = environment(me);
        me->set_temp("exercise_cost", exercise -= 1);
        if( where && me->query_temp("pending/jingzuo")){
          if (exercise == 80)
          write(GRN"
不多久，你就自然而然闭上了眼，但绝不是睡着，而是思路十分清楚，
你只觉得听到了许多古怪的声音，而这些古怪的声音，全是来自你自己
身体之内的，心跳声，呼吸声，肠脏所发出的咕咕声，甚至于，连血液
在流动的声音，也可以感觉得出来——不说听到了自己体内血液流动
的声音，因为那实在不可能，可是却又实实在在，有血在流动出声的感
觉 。 \n"NOR);          

          if (exercise == 60)
          write(CYN"
在听着自己的身体之内，发出那么多怪异声音的同时，渐渐地，你起了
一种十分奇妙的感觉，那种感觉，由于是前所未经的，所以也十分难以
形容。呼吸声，听来象是风声；心跳声，听来象是不知道什么物件的碰
击声；血流声，听来象是有一条清溪在身体不远外潺潺流过，而咕咕声，
象是小溪的石上，有着蛙群在鸣叫。。。
\n"NOR);

          if (exercise == 40)
          write(BLU"
过了一会，你意念转变了一下，不知道是由于什么原因，你忽然想到了
高山积雪的融化。于是，一下子，你听到的声音，就与你所想到的风景
相配合了，融了的雪，汇成了一股股的水流向下淌，有时经过悬岩，就
滴下来，发出滴答的声音，风声依旧，可是再也不是小溪边的轻风，而
是掠过山岩的劲风。 
\n"NOR);

          if (exercise == 20)
          write(RED"
本来来自身体内的声音，化为大自然中所发出的一切声音，而你整个人，
反倒被这些声音所包围，象是置身在这些声音所形成的环境之中。而且，
更奇妙的是，环境，可以全然随着自己的意念而改变，一下子在清溪之
旁，一下子在高山之巅，一下子又在大海之滨，简直是千变万化，随心
所欲。现在的那种奇妙的感觉，宛若人已经离开了自己的身体，或者是
身体忽然无限地变大，而人的思想，则在变大了的身体之内活动一样。 
\n"NOR);

          if (exercise == 1)
          write(HIW"
不知过了多久，你由于感觉的奇妙，早已全神贯注去体会那种感觉，而
浑然忘却了时间。。。
猛然一下震动，把你的意念，一下子拉了回来，像是离开了身体的你，
又回到了身体之中一样，令得你就在那时，睁开眼来，发现自己还在那
圆顶的石室内，也还维持着盘腿而坐的姿势。  
\n"NOR);

        }
        if (exercise <= 1) {
           message_vision(HIY"$N已经和大自然容为一体，过了片刻，精神抖擞的站了起来。\n"NOR, this_player());
           me->delete_temp("pending/jingzuo");
           me->delete_temp("exercise_cost");
//经验越高，得到的潜能越少
           gps=(((int)me->query_skill("dacheng-fofa", 1))/8+random(20));
           gps-=((int)me->query("combat_exp",1))/200000;
           if ( gps < 1 ) gps = 1;
           if( ((int)me->query("potential", 1) + gps) > (int)me->query("max_pot", 1) ) {
              me->set("potential", (int)me->query("max_pot", 1));
              return 0;
           }
me->add("potential",gps);
           return 0;
        }
        return 1;
}

int halt_exercise(object me)
{
        if(environment(me) && me->query_temp("pending/jingzuo")) { 
          message_vision(HIY"$N已经略显疲倦，拍了拍身上的灰尘，站了起来。\n"NOR, me);
          me->receive_damage("jingli", 20);
          me->delete_temp("pending/jingzuo");               
          me->delete_temp("exercise_cost");
          return 1;
        }
        else return 0;
}
