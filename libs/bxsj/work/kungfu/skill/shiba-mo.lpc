#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

string  *msg = ({
RED"$N低声哼道：“一呀摸，摸到姐姐的头发边。。。”"NOR,
GRN"$N低声哼道：“二呀摸，摸到姐姐的眼睛旁。。。”"NOR,
YEL"$N低声哼道：“三呀摸，摸到姐姐的脸蛋上。。。”"NOR,
BLU"$N低声哼道：“四呀摸，摸到姐姐的香肩上。。。”"NOR,
MAG"$N低声哼道：“五呀摸，摸到姐姐的颈子上。。。”"NOR,
CYN"$N低声哼道：“六呀摸，摸到姐姐的玉手上。。。”"NOR,
HIR"$N低声哼道：“七呀摸，摸到姐姐的胸口上。。。”"NOR,
HIG"$N低声哼道：“八呀摸，摸到姐姐的纤腰边。。。”"NOR,
HIY"$N低声哼道：“九呀摸，摸到姐姐的小肚旁。。。”"NOR,
HIB"$N低声哼道：“十呀摸，摸到姐姐的後背上。。。”"NOR,
HIM"$N低声哼道：“十一摸，摸到姐姐的樱唇边。。。”"NOR,
HIC"$N低声哼道：“十二摸，摸到姐姐的纤指旁。。。”"NOR,
HIW"$N低声哼道：“十三摸，摸到姐姐的大腿上。。。”"NOR,
HBRED"$N低声哼道：“十四摸，摸到姐姐的小腿上。。。”"NOR,
HBYEL"$N低声哼道：“十五摸，摸到姐姐的小屁股。。。”"NOR,
HBGRN"$N低声哼道：“十六摸，摸到姐姐的手腕旁。。。”"NOR,
HBBLU"$N低声哼道：“十七摸，摸到姐姐的鼻子上。。。”"NOR,
HBMAG"$N低声哼道：“十八摸，摸完了姐姐全身上下。。。”"NOR,
});

int valid_enable(string usage)
{
        return usage == "hand" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage_type": "摸伤",
                "dodge": 10,
                "parry": 10,
                "force": 10,
        ]);
}
