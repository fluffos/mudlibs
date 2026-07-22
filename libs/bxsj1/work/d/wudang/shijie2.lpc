// /d/wudang/shijie2.c 石阶
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"石阶"NOR);
        set("long", @LONG
你走在一条坚实的石阶上，不时地有游人或进香客从你的身边走过。一边
是悬崖，一边是峭壁，抬头隐约可见山雾环绕的天柱峰，山风拂面，鸟鸣声声，
令人心旷神怡。再往前就是展旗峰了。
LONG
        );
        set("exits", ([
                "southup" : __DIR__"zhanqi",
                "eastdown" :__DIR__"fuzhen",
        ]));

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));

        set("outdoors","武当");        
        setup();
}
