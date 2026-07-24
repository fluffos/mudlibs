// lingxu-bu 凌虛步

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「雪地蓮花」，身子掣忽一轉，$N只覺的眼前一花，失去了目
標。\n",
        "dodge"  : 40
]),
([      "action" : "$n一式「一狐沖天」，雙腳點地，身子突然拔高了丈許\，緩緩飄落在
$N身后。\n",
        "dodge"  : 60
]),
([      "action" : "$n一式「移行幻影」，身行一晃，頓時無數條身影一下子出現在$N的
面前。\n",
        "dodge"  : 80
]),
([      "action" : "$n一式「狡兔三窟」，飄然向后一退，躲開$N的凌厲攻勢。\n",
        "dodge"  : 100
]),
([      "action" : "$n一式「煙雨飄渺」，身體急轉，化為一道白光，虛幻不定的出現在
$N的周圍。\n",
        "dodge"  : 120
]),
});


int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

