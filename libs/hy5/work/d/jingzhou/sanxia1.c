// Room: /d/chengdu/sanxia1
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "西陵峡" NOR );
        set("long", @LONG
这里是长江三峡的西陵峡，两岸高山耸立，遮天蔽日，真可谓是
猿猴愁末攀啊！由于这里河道比较窄，河水变的不安起来，发出阵阵
咆哮声，不时翻滚着旋涡向东流去。
LONG
        );
        set("exits", ([
  "southwest" :  __DIR__"sanxia2",
  "east" : __DIR__"shudao10",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

