// wild.c - 野外

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "野外",
        "long": 
            "\n""-========================================-\n|""            野外                    ""|\n-========================================-\n""\n这是宗门外的野外，到处是荒草和乱石。\n远处可以看到""森林""的影子。\n这里经常有""妖兽""出没，需要小心。\n\n""[妖兽]\n""  ""野狗""     - 等级1，掉落：兽皮、布料\n  ""毒蛇""     - 等级2，掉落：蛇胆、毒囊\n  ""山贼""     - 等级3，掉落：铜矿、灵石\n\n""[出口]\n""  ""north"" - 山门外\n  ""east""  - 森林\n\n",
        "exits": ([
            "north": "/room/xiuxian/gate",
            "east": "/room/xiuxian/forest",
        ]),
        "monsters": ([
            "野狗": ([ 
                "name": "野狗", 
                "level": 1, 
                "hp": 40, 
                "attack": 6,
                "exp": 15,
                "drops": ([ "兽皮": 60, "布料": 40 ])
            ]),
            "毒蛇": ([ 
                "name": "毒蛇", 
                "level": 2, 
                "hp": 60, 
                "attack": 10,
                "exp": 25,
                "drops": ([ "蛇胆": 50, "毒囊": 30 ])
            ]),
            "山贼": ([ 
                "name": "山贼", 
                "level": 3, 
                "hp": 100, 
                "attack": 15,
                "exp": 50,
                "drops": ([ "铜矿": 60, "灵石": 20 ])
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

mapping query_monsters() {
    return room_data["monsters"];
}
