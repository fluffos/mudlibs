// weapon_shop.c - 武器坊

#include <globals.h>

mapping room_data;

void create() {
    room_data = ([
        "short": "武器坊",
        "long": 
            "\n""-========================================-\n|""            武器坊                  ""|\n-========================================-\n""\n这是宗门的武器坊，墙上挂满了各种""法器""和""武器""。\n一位""铁匠""正在打造武器，火花四溅。\n柜台上陈列着各种装备，散发着灵光。\n\n""[武器]\n""  ""木剑""     - 攻击+5  (需要：铁矿x2)\n  ""青铜剑""   - 攻击+15 (需要：铜矿x3, 灵石x1)\n  ""赤炎剑""   - 攻击+30 (需要：火晶x2, 灵石x3)\n\n""[防具]\n""  ""布衣""     - 防御+3  (需要：布料x2)\n  ""皮甲""     - 防御+10 (需要：兽皮x3)\n  ""灵甲""     - 防御+20 (需要：灵铁x2, 灵石x2)\n\n""[提示]\n""  输入 ""craft <物品>"" 合成装备\n\n""[出口]\n""  ""north"" - 宗门广场\n\n",
        "exits": ([
            "north": "/room/xiuxian/square",
        ]),
        "recipes": ([
            "木剑": ([ 
                "name": "木剑", 
                "type": "weapon",
                "attack": 5,
                "materials": ([ "铁矿": 2 ]),
                "desc": "普通的木剑，适合初学者"
            ]),
            "青铜剑": ([ 
                "name": "青铜剑", 
                "type": "weapon",
                "attack": 15,
                "materials": ([ "铜矿": 3, "灵石": 1 ]),
                "desc": "青铜打造的宝剑，锋利无比"
            ]),
            "赤炎剑": ([ 
                "name": "赤炎剑", 
                "type": "weapon",
                "attack": 30,
                "materials": ([ "火晶": 2, "灵石": 3 ]),
                "desc": "蕴含火焰之力的神剑"
            ]),
            "布衣": ([ 
                "name": "布衣", 
                "type": "armor",
                "defense": 3,
                "materials": ([ "布料": 2 ]),
                "desc": "简单的布衣"
            ]),
            "皮甲": ([ 
                "name": "皮甲", 
                "type": "armor",
                "defense": 10,
                "materials": ([ "兽皮": 3 ]),
                "desc": "兽皮制成的护甲"
            ]),
            "灵甲": ([ 
                "name": "灵甲", 
                "type": "armor",
                "defense": 20,
                "materials": ([ "灵铁": 2, "灵石": 2 ]),
                "desc": "蕴含灵力的护甲"
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

mapping query_recipes() {
    return room_data["recipes"];
}
