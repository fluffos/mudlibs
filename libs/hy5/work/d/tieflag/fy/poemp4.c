 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIY"探花阁四楼"NOR);
        set("long", 
"少年侠气，交结五都雄。肝胆洞，毛发耸。立谈中，死生同，一诺千金重。推
翘勇，矜豪纵，轻盖拥，联飞鞚，斗城东。轰饮酒垆，春色浮寒甕，吸海垂虹。闲
呼鹰嗾犬，白羽摘雕弓，狡穴俄空。乐匆匆。似黄梁梦，辞丹凤，明月共，漾孤篷。
官冗從，怀倥傯，落尘笼，簿书丛。鶡弁如云众，供粗用，忽奇功。笳鼓动，渔阳
弄，思悲翁，不请长缨，繋取天骄种，剑吼西风。恨登山临水，手动七弦洞，日送
归鸿。\n"NOR                                   
        );
        set("exits", ([ 
        "down" : __DIR__"poemp3",
        "up" : __DIR__"poemp5",
]));
        set("objects", ([
        __DIR__"npc/mother3" : 1,
                        ]) );
        set("no_death_penalty",1);
        set("NONPC", 1);
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",40);
        setup();
}    
