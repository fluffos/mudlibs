#ifndef RACE_H
#define RACE_H

/* 
   物種 (Species/Race) 定義 
   格式：([ "id" : ([ "name": "名稱", "desc": "說明", "stats": ([ "str": 0, ... ]) ]) ])
*/

#define RACE_DATA ([ \
    "human" : ([ \
        "name" : "人類", \
        "desc" : "適應力強，各項屬性均衡，是世界的主要種族。", \
        "stats" : ([ "str": 2, "dex": 2, "int": 2, "con": 2, "wis": 2, "cha": 2 ]) \
    ]), \
    "elf" : ([ \
        "name" : "精靈", \
        "desc" : "優雅且長壽，擅長魔法與敏捷行動，但體力較弱。", \
        "stats" : ([ "str": -1, "dex": 4, "int": 3, "con": -1, "wis": 3, "cha": 4 ]) \
    ]), \
    "dwarf" : ([ \
        "name" : "矮人", \
        "desc" : "堅韌且強壯，擅長鍛造與戰鬥，不擅長魔法。", \
        "stats" : ([ "str": 4, "dex": -1, "int": -1, "con": 5, "wis": 1, "cha": 0 ]) \
    ]), \
    "orc" : ([ \
        "name" : "獸人", \
        "desc" : "充滿力量與狂氣，擁有驚人的體魄，但智力低下。", \
        "stats" : ([ "str": 6, "dex": 2, "int": -4, "con": 4, "wis": -2, "cha": -2 ]) \
    ]) \
])

/* 
   天性 (Nature/Personality) 定義 
   影響初始技能或微幅屬性修正
*/
#define NATURE_DATA ([ \
    "brave" : ([ \
        "name" : "勇猛", \
        "desc" : "無所畏懼，戰鬥時更有力量。", \
        "stats" : ([ "str": 3, "con": 1 ]), \
        "skills": ({ "power_strike" }) \
    ]), \
    "wise" : ([ \
        "name" : "睿智", \
        "desc" : "洞察世事，精神力極高。", \
        "stats" : ([ "int": 3, "wis": 1 ]), \
        "skills": ({ "meditation" }) \
    ]), \
    "agile" : ([ \
        "name" : "靈動", \
        "desc" : "身輕如燕，難以被擊中。", \
        "stats" : ([ "dex": 3, "cha": 1 ]), \
        "skills": ({ "dodge" }) \
    ]), \
    "tough" : ([ \
        "name" : "堅毅", \
        "desc" : "耐打耐磨，擁有極強的生存能力。", \
        "stats" : ([ "con": 3, "str": 1 ]), \
        "skills": ({ "endurance" }) \
    ]) \
])

#endif
