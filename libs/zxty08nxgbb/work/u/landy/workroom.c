#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "Work room" NOR);
        set("long",
"你轻轻地打开铁门，走了进来，一个空旷的大厅映入你的眼帘\n"
"这里想必就是传说中的天尊圣殿了。整个大殿的地板和台阶竟\n"
"全为白金所铸。殿中灯火辉煌，灼热的气息竟使得你透不过气\n"
"来。正对大门的一个三丈来高的高台上刻着「天尊圣殿」四个\n"
"大字，高台上四方天神拥簇着一位二十岁左右的青年高高而立。\n"
);

        set("exits", ([
                "down" : "/d/city/guangchang",
        ]));

set("no_fight", 1);
        set("valid_startroom", 1);
        set("sleep_room", 1);

        setup();
}
