// story:shenzhao 凝血神爪

#include <ansi.h>

int give_gift();


mixed *story = ({
        "某日，北侠补习班的发呆站着不练功，班主任冰冰问他为什么不练？",
        "发呆答说：“为什么练功？”                               ",
        "练厉害了都一把年纪了，                                     ",
        "「方舟开始不安」，                                         ",
        "练到一把年纪也不一定经验值高，                             ",
        "「伪钞不好意思的看了发呆一眼」，                         ",
        "经验值高了又不一定厉害，                                 ",
        "「扣肉背后响起闷雷」，                                 ",
        "厉害会了又不一定会TASK，                                 ",
        "「石中玉身边秋风吹过阵阵凄凉的落叶」，                   ",
        "会TASK了又不一定会快，                                   ",
        "「铭文脸色都一变」，                                     ",
        "TASK快了又不一定会完整，                                 ",
        "「安妮的脸开始抽筋」，                                   ",
        "完整的又不一定找得到好门派，                             ",
        "「发财默默不语」，                                       ",
        "找得到好门派又不一定不叛师，                             ",
        "「大浩心中一痛」，                                       ",
        "叛师又不一定能偷学到技能，                               ",
        "「无缺冷冷地看着发呆」，                                 ",
        "偷得到技能又不一定能用绝招，                             ",
        "「燕丹脸上一红」，                                       ",
        "能用的技能又不一定是能练，                               ",
        "「猪皇拔出无影剑，准备修理人」，                         ",
        "所以啊....干嘛要练功?”                                  ",
        "......                                                   ",
        "...                                                      ",
        "现场沉默了三秒钟，众人联手开扁发呆。                     ",
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
        	if ( (lev = ob->query_skill("parry", 1)) < 100 )
                	ob->set_skill("parry", lev + 10);

		if (ob)
		{
		        tell_object(ob, HIC "你从群殴中领悟到了招架的奥义。\n" NOR);
		        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
		                              "从群殴中领悟到了招架的奥义。");
		}
		STORY_D->remove_story("fadai");
	}
        return 1;
}
