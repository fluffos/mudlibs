// Room: d/kyoto/kuiwu
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "葵屋");
set("long", @LONG
这里就是葵屋，是一间不大的旅店，店内也有供应茶水，酒类和餐饭
。据说这里是京都著名的忍者组织御番庭的秘密联络处。御番庭的成员在
这里交换情报或是接受任务。
LONG );
set("exits",  ([
        "south"  : __DIR__"qianbending3",
      ]));
        setup();
        replace_program(ROOM);
}