// story:advent

#include <ansi.h>

string give_gift();
mixed *story = ({
      "十一月初四。                                                        ",
      "扬州。                                                              ",
      "醉仙楼。                                                            ",
      "行云六十大寿，各路江湖豪杰均来祝寿。                                ",
      "......                                                              ",
      "...                                                                 ",
      "众人喝酒划拳，热闹非凡。                                            ",
      "门外角落里，蜷着一个黑衣人，他呆在阴影里已有四个时辰！              ",
      "他在等待时机！                                                      ",
      "他很能等！                                                          ",
      "因为他是最好的杀手！                                                ",
      "...                                                                 ",
      "他习惯性地摸了摸手上的瘊子……                                        ",
      "这时，行云端起酒杯，一仰头，又灌下一杯，他已有几分醉意。            ",
      "时机到了！                                                          ",
      "拔刀。                                                              ",
      "黑衣人扑进饭庄。身形一晃，被门槛拌了个跟头。         ",
      "手里的刀掼出去老远，从窗口飞了出去。                                ",
      (: give_gift :),
      "大厅中鸦雀无声，几十只眼睛都看着那人。",                                                
      "那人爬起来，悻悻道：“嘿嘿，嘿嘿嘿，俺…俺是杂烩饭…俺是来看看有没有人要买菜刀。”",
      "边说一边往门口蹭去……",                                                            
});


void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        
        int i;
        object env,ob;
        object ob1;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        
                                
                }
                if(!ob) return "";
                tell_object(ob,"一件不明物体从天而降，你眼前一黑，被砸晕了过去！\n");
                if(random(10)==0)
                ob->unconcious();
                msg="一件不明物体从天而降，将"+ob->name()+"给砸晕了.......\n";
                env=environment(ob);
                ob1=new("/clone/story/obj/caidao");
                ob1->move(env);
                if (objectp(env))
                        tell_room(env, msg);
        }

if (ob)
{
        CHANNEL_D->do_channel( this_object(),"rumor",HIM"好像有人被砸晕了....................\n"NOR);
}
        return HIM "好像有人被砸晕了....................\n" NOR;
}
