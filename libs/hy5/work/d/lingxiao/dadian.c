//LUCAS 2000-6-18
// dadian.c
inherit ROOM;

string look_duilian();
#include <ansi.h>;

void create()
{
        set("short", "凌霄殿");
        set("long", 
"这里就是凌霄城的根本之地--凌霄殿。向来，不管凌霄城有
何大事，掌门都会在此召集门人，发号施令。大厅北墙上，挂着
一个老人的肖像，是当年凌霄城创派祖师的遗像。两边柱子上刻
着一幅对联(duilian)。旁边的兵器架上放满了寒光闪闪的长剑。
堂额挂着一张匾,上书四个大字。"HIB"

                       梅雪凌霄
\n"NOR
 );
        set("outdoors", "lingxiao");
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("item_desc",([
                "duilian"         :       (: look_duilian :),
        ]));
        set("exits", ([
                "east"  : __DIR__"fudian2",
                "west"  : __DIR__"fudian1",
                "north"  : __DIR__"qianyuan",
                "out"  : __DIR__"meiroad1",
        ]));
set("valid_startroom", "1");
        set("objects", ([
                __DIR__"npc/lu" : 1,
                __DIR__"npc/dizi" : 3,
                "quest/menpai/lingxiao/shi" : 1,
                "d/biwu/champion_lx" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        "/clone/board/lingxiao_b"->foo();
} 

string look_duilian()
{
        return
        "\n"
        "    ※※※※※※※※※※※※※※※※※\n"
        "    ※※※※　　　　　　　　  ※※※※\n"
        "    ※※※※　宝          梅　※※※※\n"
        "    ※※※※　剑          花　※※※※\n"
        "    ※※※※　锋          香　※※※※\n"
        "    ※※※※　自          自　※※※※\n"
        "    ※※※※　磨          苦　※※※※\n"
        "    ※※※※　砺          寒　※※※※\n"
        "    ※※※※　出          来　※※※※\n"
        "    ※※※※　　　　　　　　　※※※※\n"
        "    ※※※※※※※※※※※※※※※※※\n";
}

