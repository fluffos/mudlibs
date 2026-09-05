// by yuer
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIM "华山论剑报名处" NOR);
    set("long",@LONG 
此乃华山论剑报名之处，凡是要参加华山论剑的高手必须要在此处 
报名(baoming)才能参加比武。比武者必须要有相当的资格。4 M 经验
是最低的要求了。
LONG        
       );

    set("exits", ([ /* sizeof() == 1 */
                "eastdown" : "/d/huashan/zhenyue" ,
                "up" : "/hslj/biwu",
                ]));

    set("no_fight", "1");
    set("no_clean_up", 0);
    setup();

    call_other("/clone/board/hslj_b", "???");
    replace_program(ROOM);
}
