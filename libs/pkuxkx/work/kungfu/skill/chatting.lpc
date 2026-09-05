#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":
"$N张开大口白沫翻天的瞎扯,$n听的心服气燥，恨不得一头撞死。",
                "dodge":                -5,
                "parry":                -10,
                "damage":               0,
                "damage_type":  "心理问题",
                "parry_msg":    "$n假装昏过去，总算躲过一劫",
        ]),
        ([      "action":
"$N开始不厌其烦的讲解唐僧的人生志向,听得$n坐立不安,汗流浃背。",
                "dodge":                -5,
                "parry":                -10,
                "damage":               0,
                "damage_type":  "心脏病",
                "parry_msg":    "$n对$N说道，你算了吧！你又不是唐僧!",
        ]),
        ([      "action":
"$N苦口婆心的劝说$n要注意保护环境,$n拿出一副苍蝇拍挥来挥去。",
                "dodge":                -5,
                "parry":                -10,
                "damage":               0,
                "damage_type":  "高血压",
                "parry_msg":    "$n视而不见，随口答道:はいはい、わかりました",
        ]),
        });
        
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int valid_enable(string usage)
{
        return  usage=="unarmed";
}
int practice_skill(object me)
{
        return notify_fail("聊天神功只能通过在聊天室聊天才能提升。\n"); 
}
string type() { return "knowledge"; }
