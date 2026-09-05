// alchemy.c - 炼丹房

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "炼丹房",
        "long": 
            "\n""-========================================-\n|""            炼丹房                  ""|\n-========================================-\n""\n这是宗门的炼丹房，空气中弥漫着药香。\n房间中央摆放着一个巨大的""丹炉""，炉火正旺。\n墙边的架子上摆满了各种""灵药""和""丹药""。\n\n""[丹药]\n""  ""回血丹"" - 恢复生命值\n  ""回灵丹"" - 恢复灵力值\n  ""筑基丹"" - 增加修为\n\n""[出口]\n""  ""east"" - 宗门广场\n\n",
        "exits": ([
            "east": "/room/xiuxian/square",
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
