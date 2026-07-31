// Room: d/kyoto/jiuguan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "酒馆");
set("long", @LONG
这里是一间不大的酒馆，可以供应日式酒和西式酒，塌塌米上坐着酩
酊大醉的酒鬼，可以听到他们对明治政府的种种不满，也有人暗地里商议
着重新建立新的政府。门口放着一块牌子（paizi）。
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending1",
      ]));
        setup();
        replace_program(ROOM);
}