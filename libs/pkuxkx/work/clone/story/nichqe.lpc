// story:nichqe 妙手空空

#include <ansi.h>

int give_gift();


mixed *story = ({
        "七月十五，",
        "深夜。",
        "扬州首富，人称“乐善好施“的伪钞豪宅。",
        "大厅房檐上蜷缩着一个黑影。",
        "他在等待。",
        "他不怕等待。",
        "干他们这一行，一生中绝大部分时间都在等待。",
        "他是这一行中最棒的，他是“天下第一神偷”！",
        "他已经等了很长时间。",
        "一滴露水滴在他那瘦如枯骨深陷的面颊上。",
        "他裹紧身上的林黛玉，下意识地去想握住颜如玉却摸了个空，才想起上次去丽春院时已经当掉了。",
        "......",
        "...",
        "又过了良久，他丰富的职业经验告诉他时机已到。",
        "于是他像一只灵猫般无声地潜入了漆黑的大厅。",
        "那伶俐轻便的动作令人不得不佩服，他----确实是最棒的！",
        "他此行的目的是皇上钦赐的镏金酒壶。",
        "他相信此行决不会落空，他对自己的身手充满自信。",
        "良久，黑暗中传来一声闷在嗓子眼中的惨嚎，随后一切都归于沉寂……",
        "俺不愧是“天下第一神偷”。",
        "一瘸一拐走在回家的路上，他不禁得意地想。虽然受了点儿伤，但毕竟是值得的。",
        "俺这身本领一定让人晓得才好，于是他不顾周围NPC诧异的目光，拉住毫毛絮絮叨叨的讲解起来...",
        (: give_gift :),
        "  *   *   *",
        "第二天，伪钞家的下人发现铜夜壶失踪了，床下有个合上的老鼠夹子，却没有打着老鼠...",        
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
        if ((lev = ob->query_skill("stealing", 1)) < 100)
                ob->set_skill("stealing", lev + 10);

if (ob)
{
        tell_object(ob, HIC "你从天下第一神偷那里学习到了妙手空空的绝技。\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "从天下第一神偷那里学习到了妙手空空的绝技。");
}
        STORY_D->remove_story("nichqe");
      }
        return 1;
}
