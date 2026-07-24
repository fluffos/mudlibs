// feng.h 
// by Marz 

#include <ansi.h>

int look_feng(string arg);

int look_feng(string arg)
{
        object me = this_object();
        int lucky;
//      object me    原始的 leos 2000.03.31

        if( !arg || arg!="feng" ) return 0;
        write("

                      ^
                     ^ ^
                   @@@__^    
                    ^ @@@__
                   ^   ^  ^

抬眼望去，流云片片，煙霧繚繞，天柱峰若隱若現，似遙不可既…\n\n");

        me = this_player();
        lucky = random(me->query_dex() + me->query_kar()) + me->query_dex();

        if (lucky > 58)
        {
                write("突然間，有個黑點在云霧中一掠而過，好象是一只大雕！\n"
                        +"可是那么高的地方，怎么可能呢？ｈｍｍ．．．也許是一時花了眼。\n\n");
        
        }else if(lucky >= 45)
        {
                // do nothing here
        }else if(lucky >= 30)
        {
                message_vision(HIY"$N光顧著看天，一不留神腳下踏了個空，... 啊...！\n\n"NOR, me);
                message_vision(HIY"$N一個趔趄摔了一跤！還好，只傷了些皮骨，沒有滾下去。\n\n"NOR, me);
                me->receive_damage("qi", 30+4*random((int)me->query("age")));
                me->receive_damage("jing", 50);
        }else // bad luck 
        {
                message_vision(HIR"$N光顧著抬頭看天，一不留神腳下踏了個空，... 啊...！\n\n"NOR, me);
                tell_object(me, HIR"你控制不住地直往山下滾，只覺得渾身無處不疼，痛得要暈死過去。\n\n"NOR);
                me->move(__DIR__"tyroad8");
                message("vision", HIR"只見" + me->query("name")
                        + "從山上骨碌碌地滾了下來，躺在地上半天爬不起來！\n\n"NOR,
                        environment(me));
                me->receive_damage("qi", 60+4*random((int)me->query("age")));
                me->receive_damage("jing", 80);
        }
        return 1;
}
// NOTE: original archive file was truncated mid-statement (raw feng.c ends
// inside the final message() call); closed with a minimal sensible body.
