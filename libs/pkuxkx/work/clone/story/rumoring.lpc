// rumoring

#include <ansi.h>

int give_gift();


mixed *story = ({
        "某日，无欢正在春来茶馆悠闲地喝着牛皮酒袋。                               ",
        "......                                                                    ",
        "方舟上气不接下气地跑来，说：西....西门吹牛....跳楼了!                   ",
        "无欢大惊，满满一袋酒都撒在裤子上...                                   ",
        "......                                                           ",
        "方舟悠悠接着说：他在鼓楼练轻功。                              ",
        "无欢松了口气，又将牛皮酒袋灌满清水。                          ",
        "......                                                                  ",
        "方舟接着说：他有效轻功才110...                                            ",
        "无欢的眼睛睁得有鸡蛋大，满满一袋清水又都撒在裤子上...                     ",
        "......                                                                    ",
        "方舟又接着说：鼓楼下面有个干草堆...                                       ",
        "无欢又长出了口气，又将牛皮酒袋灌满清水。                                  ",
        "......                                                                    ",
        "方舟接着说：干草堆上有个大粪叉!                                           ",
        "无欢的嘴张得可以放下一个熟鸡蛋，满满一袋清水又都撒在裤子上...             ",
        "......                                                                    ",
        "方舟又接着说：他没落到大粪叉上。                                          ",
        "无欢又松了口气，又将牛皮酒袋灌满清水。                                    ",
        "......                                                                    ",
        "方舟接着说：他也没落到干草堆上。                                          ",
        "无欢：...                                                                 ",
        (: give_gift :),
});

string prompt() { return HIY "【武林奇遇】" NOR; }

void create()
{
        seteuid(getuid());
}



mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{

        int i, lev;
        object env,ob;
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
                if(!ob) return 1;
                if ( (lev = ob->query_skill("rumoring", 1)) < 100 )
                        ob->set_skill("rumoring", lev + 10);

                if (ob)
                {
                        tell_object(ob, HIC "你从领悟到了造谣的诀窍。\n" NOR);
                        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                                              "领悟到了造谣神功的精华。");
                }
                STORY_D->remove_story("rumoring");
        }
        return 1;
}
