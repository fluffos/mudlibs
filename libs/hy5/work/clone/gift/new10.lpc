// story:shenzhao 凝血神爪

#include <ansi.h>

int give_gift();


mixed *story = ({
        "三军蜿蜒而行。",
        "“嗯？那写了什么？”",
        "小兵：报告军师，上面写着“落鸡坡”三个字。",
        "庞统：嗯... 不好！我的外号是小鸡，这里大大的不吉利，火速撤退！",
        "“轰！隆隆！”",
        "张任：嘿嘿！庞统，哪儿跑？以为我们四川这儿想来就来，想走就走？",
        "庞统：魏延将军呢？",
        "小兵：报告军师，魏延将军在前头，已经出谷了。",
        "庞统：黄忠将军呢？",
        "小兵：报告军师，黄老将军在后头，还没有入谷。",
        "庞统：他奶奶的，就我一个不紧不慢，恰好赶在中间！",
        "张任：放箭！",
        "箭如雨下",
        "庞统翻翻白眼，倒在地上，口中吐出两口鲜血，死了。",
        "......",
        "一年过去了...",
        "十年过去了...",
        "一百年过去了...",
        "一千年过去了...",
        "宏天漫步在山间... 咦？这是什么？",
        "乱堆从中一堆枯骨，中间好像有本书？",
        "宏天翻了出来，发现这本书似乎不是一般的材料书写的。",
        "“好像很值钱呀”，让我看看....",
        "“嗯？鬼谷神算？”",
        "宏天看了看说道：“什么破玩意，原来不值钱，随手把鬼谷神算给扔了”",
        (: give_gift :),
});

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
         
        int i;
        object env,ob;
        object *players;
                object gob;
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
        gob = new(__DIR__"obj/guigu");
        gob->move(ob, 1);
 if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "捡到了奇书《鬼谷神算》。");
}
        STORY_D->remove_story("new10");
      }
        return 1;
}