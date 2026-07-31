// Room: d/kyoto/shenguangyuan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "神光院");
set("long", @LONG
这里就是神光院，不如其他神社，这里平和自然，一进入人的心情就自
然放松，幽幽清泉流过石间，宁静而致远。和着颂经之声入耳，顿觉精神放
松，仿佛已经来到极乐世界。
LONG );
set("exits",  ([
        "south"  : __DIR__"heyuanting1",
      ]));
        setup();
        replace_program(ROOM);
}