// Room: d/kyoto/shizhengting
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "市政厅");
set("long", @LONG
这里就是市政厅，是维新政府的官员办公的地方，守卫森严。维新运
动已经过去十年，老百姓总算摆脱了战乱的日子，但是依旧有些人对维新
政府表示强烈不满，近年来暗杀和爆炸等恐怖事件不断，究竟是何人所为
呢？
LONG );
set("exits",  ([
        "west"  : __DIR__"shangyuan5",
      ]));
        setup();
        replace_program(ROOM);
}