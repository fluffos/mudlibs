// square.c - 宗门广场

#include <globals.h>

mapping room_data;
object quest_npc;

void create() {
    room_data = ([
        "short": "宗门广场",
        "long": 
            "\n========================================\n" +
            "|            宗门广场                |\n" +
            "========================================\n" +
            "\n这里是青云宗的中心广场，四周矗立着高耸的建筑。\n" +
            "广场中央有一座巨大的灵石雕像，散发着淡淡的灵气。\n" +
            "不时有弟子来往穿梭，讨论着修炼心得。\n" +
            "一位任务执事正站在广场边缘。\n\n" +
            "[出口]\n" +
            "  north - 修炼室\n" +
            "  south - 任务大厅\n" +
            "  east  - 藏经阁\n" +
            "  west  - 炼丹房\n" +
            "  up    - 灵药园\n" +
            "  down  - 武器坊\n\n",
        "exits": ([
            "north": "/room/xiuxian/training",
            "south": "/room/xiuxian/quest",
            "east": "/room/xiuxian/library",
            "west": "/room/xiuxian/alchemy",
            "up": "/room/xiuxian/garden",
            "down": "/room/xiuxian/weapon_shop",
        ]),
    ]);
    
    // 创建任务NPC（暂时禁用）
    // call_out("create_npc", 1);
}

void create_npc() {
    if (!quest_npc) {
        quest_npc = new("/npc/quest_master");
        if (quest_npc) {
            quest_npc->move(this_object());
        }
    }
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

void init() {
    add_action("do_look", "look");
    add_action("do_look", "l");
}

int do_look(string arg) {
    if (!arg || arg == "" || arg == "here") {
        write(query_long());
        return 1;
    }
    return 0;
}
