// forest.c - 森林

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "森林",
        "long": 
            "\n""-========================================-\n|""            森林                    ""|\n-========================================-\n""\n这是一片茂密的森林，树木参天，遮天蔽日。\n林中传来""妖兽""的吼叫声，让人不寒而栗。\n地上散落着一些""灵药""和""矿石""。\n\n""[可采集]\n""  ""青木藤""   - 木属性灵药\n  ""金叶草""   - 金属性灵药\n  ""寒冰花""   - 冰属性灵药\n\n""[妖兽]\n""  ""黑熊""     - 等级4，掉落：熊胆、兽皮\n  ""灵狐""     - 等级5，掉落：狐皮、妖丹\n\n""[出口]\n""  ""west""  - 野外\n  ""east""  - 洞穴\n\n",
        "exits": ([
            "west": "/room/xiuxian/wild",
            "east": "/room/xiuxian/cave",
        ]),
        "items": ([
            "青木藤": ([ "name": "青木藤", "type": "material", "desc": "木属性灵药" ]),
            "金叶草": ([ "name": "金叶草", "type": "material", "desc": "金属性灵药" ]),
            "寒冰花": ([ "name": "寒冰花", "type": "material", "desc": "冰属性灵药" ]),
        ]),
        "monsters": ([
            "黑熊": ([ 
                "name": "黑熊", 
                "level": 4, 
                "hp": 150, 
                "attack": 20,
                "exp": 80,
                "drops": ([ "熊胆": 70, "兽皮": 90 ])
            ]),
            "灵狐": ([ 
                "name": "灵狐", 
                "level": 5, 
                "hp": 120, 
                "attack": 25,
                "exp": 100,
                "drops": ([ "狐皮": 60, "妖丹": 30 ])
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
