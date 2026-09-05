//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"富贵花圃"NOR);
        set("long", @LONG
未入此处，清新的花香已沁人心裨。苗铺中陈列着各种名花，玲琅满
目，令人目不暇接。其中虽不乏珍奇异种，但是最吸引人的还是一簇簇盛
放的牡丹，天下花卉以牡丹为王，而牡丹之中又以洛阳牡丹为尊，怪不得
这里的生意总是那么的兴旺，既有外来游客，也有当地居民，来客不分高
低贵贱，这里的主人总是笑脸相迎。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "east" : __DIR__"xipu",  
               "west" : __DIR__"beidajie2",            
        ]));
        set("objects", ([
        __DIR__"npc/hualaoban":1,
        __DIR__"npc/shenni":1,
        ]));

//        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

