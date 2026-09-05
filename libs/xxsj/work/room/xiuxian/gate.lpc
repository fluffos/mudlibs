// gate.c - 山门外

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "山门外",
        "long": 
            "\n""-========================================-\n|""            山门外                  ""|\n-========================================-\n""\n这是""青云宗""的山门外，一条石阶通往宗门。\n山门上刻着""「青云宗」""三个大字，气势磅礴。\n两侧站着""守门弟子""，警惕地注视着来往的人。\n\n""[出口]\n""  ""north"" - 任务大厅\n  ""south"" - 野外\n\n",
        "exits": ([
            "north": "/room/xiuxian/quest",
            "south": "/room/xiuxian/wild",
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
