
 
#include "ansi.h"

inherit "/inherit/misc/bbsboard";

void create()
{
        set_name(HIG"江湖风云"NOR+"新闻组", ({ "newsgroup" }) );
        set("location", "/d/wizard/snow_room");
        set("board_id", "jhfy_b");
        set("long", "这是一个供各位交流讨论的"+HIC+" BBS "+NOR+"板。\n\n巫师可以用"+HIW"mkgroup"NOR+" 和 "+HIW"rmgroup"NOR+"去
创建和删除一个新闻组,玩家可以用\n"
+HIW"read board"NOR+"指令阅读\n" );
        setup();
        set("capacity", 500);
        replace_program("/inherit/misc/bbsboard");
}

