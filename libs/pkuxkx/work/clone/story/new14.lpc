// story:baguadao 紫金八卦刀

#include <ansi.h>

nosave string char_id;
nosave string char_name;
nosave string family_name;

int give_gift();
object select_character();


mixed *story = ({
        "胡一刀大笑道：“商剑鸣，到了此时你还是束手就擒吧！”",
        "商剑鸣：“商某与阁下无冤无仇，今日苦苦相逼究是为何？”",
        "胡一刀：“苗家一家上下数十口性命，他们又和你有什么仇？受死吧！”",
        "商剑鸣只见对方剑锋一闪，暗道：“我命休矣！”",
        "——镪——",
        "只见一柄长剑飞插上了横梁。",
        "胡一刀虎目圆瞪，道：“你是谁？为何插手此事？”",
        "商剑鸣睁开双眼，只见一人左手负后，右手提一柄单刀，面色沉着。",
        "那人谈谈的道：“阁下技胜一筹，何必又非要赶尽杀绝？”",
        "胡一刀：“他欠苗人凤几十条性命，今天此仇不能不报。”",
        "那人道：“苗人凤是你朋友？”",
        "胡一刀：“不是，我也是他的仇人。”",
        "那人冷笑一声道：“原来阁下是怕了苗人凤，想拿商剑鸣的人头来换你自己的人头！”",
        "那人又接着道：“既然如此，我不插手好了！”",
        "胡一刀大怒道：“呸！我胡一刀岂是这种卑鄙下流之人！”",
        "那人冷冷的道：“原来你就是人称‘辽东大侠’的胡一刀？”",
        "胡一刀：“正是在下！”",
        "那人又冷笑一声，道：“我生平最恨的就是你们这些所谓的大侠，这事我管定了。”",
        "胡一刀怒极，拔出了腰间单刀，喝道：“好！我就领教你的高招！进招吧！”",
        "那人哼了一声，身形一展，扑了上去。",
        "呛！",
        "镪！",
        "~嗤啦！~",
        "~~~啊！~~~",
        "…………",
        "那人道：“现在阁下还有什么话说？”",
        "只见胡一刀右手血流不断，看着地上的两根断指，一张黑脸涨得通红，半天说不出话。",
        "胡一刀摇了摇头，苦笑道：“胡某只得今日才知‘天外有天，人外有人’八字。”",
        "那人也不理睬，谈谈的道：“既然如此，那么阁下请便吧。”",
        "…………",
        "商剑鸣：“请问恩人尊性大名？今日之恩，商某今生难以回报！”",
        "那人道：“哼！你是什么东西，也配我的姓名？今日是你运气好而已，也别谢我。”",
        "那人顿了一顿，接着道：“告诉你也无妨，在下便是北侠十大杰出青年---无欢。”",
        "商剑鸣：“这套紫金八卦刀法乃我商家祖传秘绝，绝不输于他胡家刀法，恩人可以参详一翻。”",
        (: give_gift :),
});

string prompt() { return HIG "【武林奇遇】" NOR; }

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
        if ((lev = ob->query_skill("blade", 1)) < 100)
                ob->set_skill("blade", lev + 10);

if (ob)
{
tell_object(ob, HIC "你感到基本刀法有所长进。\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "从商剑鸣那里学习到了刀法的运用。");
}
        STORY_D->remove_story("new14");
      }
        return 1;
}

