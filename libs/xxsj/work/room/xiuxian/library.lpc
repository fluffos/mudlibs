// library.c - 藏经阁

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "藏经阁",
        "long": 
            "\n""-========================================-\n|""            藏经阁                  ""|\n-========================================-\n""\n这是宗门的""藏经阁""，收藏着无数功法秘籍。\n书架上摆满了各种典籍，散发着古老的气息。\n一位""白发长老""正在整理书籍。\n\n""[功法]\n""  ""《基础剑诀》"" - 入门剑法\n  ""《御风术》""   - 身法功法\n  ""《炼气心法》"" - 修炼功法\n\n""[出口]\n""  ""west"" - 宗门广场\n\n",
        "exits": ([
            "west": "/room/xiuxian/square",
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
