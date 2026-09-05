// quest.c - 任务大厅

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "任务大厅",
        "long": 
            "\n""-========================================-\n|""            任务大厅                ""|\n-========================================-\n""\n这是宗门的任务大厅，墙上贴满了各种任务告示。\n许多弟子在这里接取任务，赚取""贡献点""。\n大厅中央站着一位""执事""，负责发放任务。\n\n""[任务]\n""  ""1."" 采集灵草 - 奖励：50修为\n  ""2."" 击败妖兽 - 奖励：100修为\n  ""3."" 护送商队 - 奖励：200修为\n\n""[出口]\n""  ""north"" - 宗门广场\n  ""south"" - 山门外\n\n",
        "exits": ([
            "north": "/room/xiuxian/square",
            "south": "/room/xiuxian/gate",
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
