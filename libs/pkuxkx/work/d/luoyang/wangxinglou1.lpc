//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"望"HIY"星"HIC"楼"NOR);
        set("long", @LONG
望星楼共四层，高达三十余米，乃洛阳城中的一绝。方圆数百里内提
起望星楼可以说是无人不知，无人不晓。楼下为望星楼的大厅，非常的宽
广，玲珑八角，青砖砌地，好不气派。大厅西首一檀木制阶梯直通望星楼
的楼上的雅座。
LONG
        );

        set("exits", ([
               "east" : __DIR__"beidajie1",            
               "up" : __DIR__"wangxinglou2",            
        ]));
        set("objects", ([

        __DIR__"npc/xiaoer-wxl":1,
         "/d/riyuejiao/npc/ry-welcomer" : 1,
        ]));

        setup();
        
        "/clone/board/ct_b"->foo(); 
}
