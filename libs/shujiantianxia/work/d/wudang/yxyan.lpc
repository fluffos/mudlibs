// /area/jiangbei/wudang/yxyan.c 隐仙岩
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"隐仙岩"NOR);
        set("long", @LONG
隐仙岩是武当山三十六岩中的一座大型岩洞，在中国道教历史上久负盛名。
据史料记载，汉代著名方士尹轨就在此修行。尹轨在道教史上有着很高的地位，
传说老子曾授他《道德五千言》。史书上说尹轨“既明天文星气，又精河图洛
书，既能用丹药为人治病，又擅长烧炼金银”。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"langmei",
                "westup" : __DIR__"wulong",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        setup();
}
