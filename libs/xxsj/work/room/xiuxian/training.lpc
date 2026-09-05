// training.c - 修炼室

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "修炼室",
        "long": 
            "\n""-========================================-\n|""            修炼室                  ""|\n-========================================-\n""\n这是一间宽敞的修炼室，四周布满了""聚灵阵""。\n空气中弥漫着浓郁的灵气，非常适合打坐修炼。\n墙上刻着""「心静则灵通，意诚则道成」""的字样。\n\n""[提示]\n""  输入 ""xiulian"" 进行修炼\n  输入 ""tupo"" 尝试突破境界\n\n""[出口]\n""  ""south"" - 宗门广场\n\n",
        "exits": ([
            "south": "/room/xiuxian/square",
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
