// cave.c - 洞穴（BOSS区域）

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "神秘洞穴",
        "long": 
            "\n""-========================================-\n|""          神秘洞穴 (危险！)         ""|\n-========================================-\n""\n这是一个深不见底的洞穴，散发着诡异的气息。\n洞壁上镶嵌着""灵石""，发出微弱的光芒。\n洞穴深处传来""强大妖兽""的气息，让人心惊胆战。\n\n""[警告]此处有强大的BOSS，请谨慎！\n""\n""[可采集]\n""  ""灵石""     - 珍贵的修炼资源\n  ""火晶""     - 火属性宝石\n  ""灵铁""     - 锻造高级装备的材料\n\n""[BOSS]\n""  ""炎魔""     - 等级10，掉落：火晶x3、灵石x5、炎魔之心\n\n""[出口]\n""  ""west""  - 森林\n\n",
        "exits": ([
            "west": "/room/xiuxian/forest",
        ]),
        "items": ([
            "灵石": ([ "name": "灵石", "type": "material", "desc": "蕴含灵力的石头" ]),
            "火晶": ([ "name": "火晶", "type": "material", "desc": "火属性宝石" ]),
            "灵铁": ([ "name": "灵铁", "type": "material", "desc": "珍贵的锻造材料" ]),
        ]),
        "monsters": ([
            "炎魔": ([ 
                "name": "炎魔", 
                "level": 10, 
                "hp": 500, 
                "attack": 50,
                "exp": 500,
                "is_boss": 1,
                "drops": ([ "火晶": 100, "灵石": 100, "炎魔之心": 50 ])
            ]),
        ]),
    ]);
}

string query_short() {
    return room_data["short"];
}

string query_long() {
    return room_data["long"];
}

mapping query_exits() {
    return room_data["exits"];
}

mapping query_items() {
    return room_data["items"];
}

mapping query_monsters() {
    return room_data["monsters"];
}
