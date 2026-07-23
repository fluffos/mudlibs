#include <ansi.h>
inherit ROOM;
void check_trigger();
void on_board();

void create()
{
        set("short", "溪口");
        set("long", @LONG
你迎着阵阵海风来到了溪口，这里是自古代以来兵家必挣之地，这里连
接着与海外的贸易，岸边停泊着的几艘大帆船在夕阳的照射下，船帆显得分
外美丽。岸边有几个老艄公正等着拉客人，也许你上前询问一下就能雇船出
海。
LONG);
        set("outdoors", "宁波");
        set("exits",([
        "west" : __DIR__"aywsi",
        "south" : __DIR__"dongqianhu",
        ]));
       
        setup();
}

