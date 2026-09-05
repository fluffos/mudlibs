// story:dodge

#include <ansi.h>

int give_gift();


mixed *story = ({
       "襄阳。",
       "大军压境。",
       "雪峰脚下。",
       "一人背对着浴血夕阳,手执倚天屠龙。",
       "灰布袈裟飘荡风中,一颗点着九个香疤的秃头在夕阳掩映下褶褶放光，那神情气度皆已完美到了极点。",
       "这人凛然道：佛陀一定与襄阳共存亡！！说罢仰天长笑, 声震四方。",
       "旁边挖沟的民工大郝，添伢，韩饼，石忠裕，明文，阿憨，阿土，方舟都不禁停下了手中的镢头。",
       "他们用无限仰慕的眼光看着这个救世主般的和尚。",
       "这个传说中神一样的保卫第一僧。",
       "他心中有着坚定的信念，这种信念给了大家希望，让大家看到襄阳美好的未来。",
       "虽然他们没有文化，但有执著的信念。。。",
       "他们高举着锄头，木棒，还有铁锹，南腔北调扯着脖子喊着:",
       "“誓死保卫襄阳!”“baowei”“baowei　when”“north”“捡鱼”......",
       "群情激昂,斗志高涨...",
       "蒙古开始发兵。",
       "...",
       "一道青影双手抱着光溜溜的秃头跳着钻进草坑里，闪电般地全速逃命。",
       "襄阳守军，汝州城站岗的官兵...",
       "杨女，马钰，王处一，邱处机...",
       "尹志平、程瑶迦、打谷场玩耍的小孩...",
       "野狗，扬州城门的官兵...",
       "北大街的流氓头，南大街的托钵僧...",
       "他们看到眼前一道青影闪过。",
        (: give_gift :),
       "风中远远的传来一句：“别挡道，都给佛陀闪开，还是让会跑的人跑吧。”",
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
        if ( (lev = ob->query_skill("dodge", 1)) < 100 )
                ob->set_skill("dodge", lev + 10);


if (ob)
{
        tell_object(ob, HIC "你看到眼前一道青影闪过，你深受启发，学会了高深的轻功。\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "深受启发，学会了高深的轻功。");
}
        STORY_D->remove_story("lastone");
      }
        return 1;
}
