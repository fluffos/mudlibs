// jingzuo.h

void init()
{
   add_action("do_action", ({"dazuo", "tuna", "learn", "du", "study", "xue", }));
       add_action("do_halt", "halt");
       add_action("do_lian", "lian");
       add_action("do_lian", "practice");
       add_action("do_jingzuo", "jingzuo");
}
int do_action(string arg)
{
   write("这里是禅房不能做与静坐无关的事情！\n");
   return 1;
}
int do_lian()
{
       object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")) { 
       write("你正忙着呢。\n", me);
       return 1; }
}
int do_jingzuo(string arg)
{
        object me;
        int lvl;     
        me = this_player();
        lvl = (int)me->query_skill("dacheng-fofa", 1);

       if( me->query("family/family_name") != "峨嵋派" || me->query("class") != "bonze" )
        return notify_fail("不是峨嵋派佛门弟子在这里瞎捣什么乱？\n");

        if( lvl < 30 )
        return notify_fail("你大乘佛法未到火候，不能静坐修练。\n");

        if( me->query("combat_exp") > 300000 )
        return notify_fail("以你现在的修为，已经不能通过静坐修炼了。\n");

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if (me->query_temp("jingzuo"))
        return notify_fail("你正在静坐中。\n");

       if((int)me->query("jingli", 1) < 30 )
       return notify_fail("你太累了，还是好好休息吧。\n");
       
       if(random(10) < 4 ) {
       switch(random(5) ) {
       case 0: {
       write("忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，
              只好改去别庵禅房继续修行。\n", me); 
       me->move(__DIR__"chanfang3"); }  
       break;

       case 1: { 
       write("忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，
               只好改去别庵禅房继续修行。\n", me);
       me->move(__DIR__"chanfang2"); }
       break;
       
       case 2: { 
       write("忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，
               只好改去别庵禅房继续修行。\n", me);
       me->move(__DIR__"chanfang"); }
       break;

       case 3: { 
       write("忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，
               只好改去别庵禅房继续修行。\n", me);
       me->move(__DIR__"huazangancf"); }
       break; 

       case 4: { 
       write("忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，
               只好改去别庵禅房继续修行。\n", me);
       me->move(__DIR__"baoguosicf"); }
       break; 
       } return 1;
     }
       else {
        message_vision(HIW"$N现出略有所悟的神情，先侧头想了一会，然后，在地上坐了下来，盘起了腿。\n"NOR, me);
        me->set_temp("jingzuo", 1);
        call_out("do_wait", 20, me);
        return 1;  }
}

void do_wait()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(GRN"
不多久，你就自然而然闭上了眼，但绝不是睡着，而是思路十分清楚，
你只觉得听到了许多古怪的声音，而这些古怪的声音，全是来自你自己
身体之内的，心跳声，呼吸声，肠脏所发出的咕咕声，甚至于，连血液
在流动的声音，也可以感觉得出来——不说听到了自己体内血液流动
的声音，因为那实在不可能，可是却又实实在在，有血在流动出声的感
觉 。 \n"NOR);          
          me->disable_player("<静坐中>");
//    me->set("disable_type","<静坐中>")
          call_out("do_wait1", 15, me);       
          }
}

void do_wait1()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(CYN"
在听着自己的身体之内，发出那么多怪异声音的同时，渐渐地，你起了
一种十分奇妙的感觉，那种感觉，由于是前所未经的，所以也十分难以
形容。呼吸声，听来象是风声；心跳声，听来象是不知道什么物件的碰
击声；血流声，听来象是有一条清溪在身体不远外潺潺流过，而咕咕声，
象是小溪的石上，有着蛙群在鸣叫。。。
\n"NOR);
          me->disable_player("<静坐中>");
          call_out("do_wait2", 15, me);       
          }
}

void do_wait2()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(BLU"
过了一会，你意念转变了一下，不知道是由于什么原因，你忽然想到了
高山积雪的融化。于是，一下子，你听到的声音，就与你所想到的风景
相配合了，融了的雪，汇成了一股股的水流向下淌，有时经过悬岩，就
滴下来，发出滴答的声音，风声依旧，可是再也不是小溪边的轻风，而
是掠过山岩的劲风。 
\n"NOR);
          me->disable_player("<静坐中>");
          call_out("do_wait3", 15, me);       
          }
}

void do_wait3()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(RED"
本来来自身体内的声音，化为大自然中所发出的一切声音，而你整个人，
反倒被这些声音所包围，象是置身在这些声音所形成的环境之中。而且，
更奇妙的是，环境，可以全然随着自己的意念而改变，一下子在清溪之
旁，一下子在高山之巅，一下子又在大海之滨，简直是千变万化，随心
所欲。现在的那种奇妙的感觉，宛若人已经离开了自己的身体，或者是
身体忽然无限地变大，而人的思想，则在变大了的身体之内活动一样。 
\n"NOR);
//          me->clear_condition();
          me->disable_player("<静坐中>");
          call_out("do_wait4", 15, me);       
          }
}

int do_wait4()
{      
       int lvl,gps;     
        object me = this_player();
       lvl = (int)me->query_skill("dacheng-fofa", 1);
        if(environment(me) && me->query_temp("jingzuo")){
        write(HIW"
不知过了多久，你由于感觉的奇妙，早已全神贯注去体会那种感觉，而
浑然忘却了时间。。。
猛然一下震动，把你的意念，一下子拉了回来，像是离开了身体的你，
又回到了身体之中一样，令得你就在那时，睁开眼来，发现自己还在那
圆顶的石室内，也还维持着盘腿而坐的姿势。  
\n"NOR);
message_vision(HIY"$N已经和大自然容为一体，过了片刻，精神抖擞的站了起来。\n"NOR, this_player());
          me->delete_temp("jingzuo");               
            gps=(random(lvl/8)+20);
         if( ((int)me->query("potential", 1) + gps) > (int)me->query("max_pot", 1) ) {
         me->set("potential", (int)me->query("max_pot", 1));
         return 1;
        }
         me->add("potential", gps);
         return 1;
        }
       return 0;
}

int do_halt()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")) { 
       message_vision(HIY"$N已经略显疲倦，拍了拍身上的灰尘，站了起来。\n"NOR, me);
       remove_call_out("do_wait");
       remove_call_out("do_wait1");
       remove_call_out("do_wait2");
       remove_call_out("do_wait3");
       remove_call_out("do_wait4");
       me->receive_damage("jingli", 20);
        me->delete_temp("jingzuo");               
       return 1;
          }
         else return 0;
} 
int valid_leave(object me, string dir)
{
       if(environment(me) && me->query_temp("jingzuo")) 
       return notify_fail("你正忙着呢。\n");
       return ::valid_leave(me, dir);
}

