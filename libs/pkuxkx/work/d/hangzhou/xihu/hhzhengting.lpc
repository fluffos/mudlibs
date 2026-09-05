// Room: /hangzhou/hhqianting.c
// hubo 2008/4/19

#include <ansi.h>

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
        set("short", "正厅");
        set("long", @LONG
这里就是著名的红花会杭州分舵的正厅，在厅正中供着红花老祖的画像，两侧
有一副对联（duilian），侧墙上挂着一张木牌（mupai），上面写着密密麻麻的红
字。几位当家的正在此议事。
LONG);
       
        set("exits", ([     
                "east" : __DIR__"hhqianting",
                "north" : __DIR__"hhzoulang1",
                "south" : __DIR__"hhzoulang2",
]));

        set("item_desc", ([
"mupai" :
HIR "\n  只见木牌上写道：\n"
"三敬：一敬桃园义刘关张，二敬瓦岗寨上众儿郎，三敬水泊梁山一百零八将。\n"
"四救：一救仁人义士，二救孝子贤孙，三救节妇贞女，四救受苦黎民。\n"
"四杀：一杀大清国奴，二杀贪官污吏，三杀土豪恶霸，四杀凶徒恶棍。\n"
"四戒：投降清廷者杀，犯上叛会者杀，出卖朋友者杀，淫人妻女者杀。\n" NOR,
"duilian":
//HIC "\n天下万水俱同源 红花绿叶是一家\n" NOR +
                HIC"    天" + HIG"              红\n" +
                HIC"    下" + HIG"              花\n" +
                HIC"    万" + HIG"              绿\n" +
                HIC"    水" + HIG"              叶\n" +
                HIC"    俱" + HIG"              是\n" +
                HIC"    同" + HIG"              一\n" +
                HIC"    源" + HIG"              家\n" +NOR,
        ]));

     
     set("objects", ([
		CLASS_D("honghua")+"/wuchen":1,
		CLASS_D("honghua")+"/zhao":1,
		CLASS_D("honghua")+"/luo":1,	
		"/d/hangzhou/npc/xu" : 1,
        ]));     
   setup();
}

