// garden.c - 灵药园

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "灵药园",
        "long": 
            "\n""-========================================-\n|""            灵药园                  ""|\n-========================================-\n""\n这是宗门的灵药园，种植着各种珍贵的""灵药""。\n空气中弥漫着淡淡的药香，让人心旷神怡。\n园中有""灵芝""、""雪莲""、""火灵草""等灵药。\n\n""[可采集]\n""  ""灵芝""     - 炼制回血丹的材料\n  ""雪莲""     - 炼制回灵丹的材料\n  ""火灵草""   - 炼制筑基丹的材料\n  ""青木藤""   - 炼制防御丹的材料\n\n""[提示]\n""  输入 ""gather <灵药>"" 采集灵药\n\n""[出口]\n""  ""south"" - 宗门广场\n  ""north"" - 后山\n\n",
        "exits": ([
            "south": "/room/xiuxian/square",
            "north": "/room/xiuxian/backhill",
        ]),
        "items": ([
            "灵芝": ([ "name": "灵芝", "type": "material", "desc": "珍贵的灵药，可炼制回血丹" ]),
            "雪莲": ([ "name": "雪莲", "type": "material", "desc": "寒冰属性的灵药" ]),
            "火灵草": ([ "name": "火灵草", "type": "material", "desc": "火属性的灵药" ]),
            "青木藤": ([ "name": "青木藤", "type": "material", "desc": "木属性的灵药" ]),
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
