// backhill.c - 后山

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "后山",
        "long": 
            "\n""-========================================-\n|""            后山                    ""|\n-========================================-\n""\n这是宗门的后山，山势险峻，云雾缭绕。\n山上生长着各种""灵药""和""矿石""。\n偶尔能看到""妖兽""的踪迹。\n\n""[可采集]\n""  ""铁矿""     - 锻造武器的基础材料\n  ""铜矿""     - 锻造武器的材料\n  ""灵石""     - 珍贵的修炼资源\n\n""[妖兽]\n""  ""野狼""     - 等级1，掉落：兽皮\n  ""山猪""     - 等级2，掉落：兽皮、铁矿\n\n""[提示]\n""  输入 ""gather <材料>"" 采集材料\n  输入 ""kill <妖兽>"" 攻击妖兽\n\n""[出口]\n""  ""south"" - 灵药园\n\n",
        "exits": ([
            "south": "/room/xiuxian/garden",
        ]),
        "items": ([
            "铁矿": ([ "name": "铁矿", "type": "material", "desc": "普通的铁矿石" ]),
            "铜矿": ([ "name": "铜矿", "type": "material", "desc": "青铜矿石" ]),
            "灵石": ([ "name": "灵石", "type": "material", "desc": "蕴含灵力的石头" ]),
        ]),
        "monsters": ([
            "野狼": ([ 
                "name": "野狼", 
                "level": 1, 
                "hp": 50, 
                "attack": 8,
                "exp": 20,
                "drops": ([ "兽皮": 80 ]) // 80% 掉落率
            ]),
            "山猪": ([ 
                "name": "山猪", 
                "level": 2, 
                "hp": 80, 
                "attack": 12,
                "exp": 35,
                "drops": ([ "兽皮": 70, "铁矿": 50 ])
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
