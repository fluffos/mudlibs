#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "兵器室");
  set ("long", @LONG
这里是神古活心流的武器室了。正前方的墙上写着一行字(zi)。在四周的墙边
整齐的放着一些木剑腾甲等东西，你如果需要练习也可以在这里拿取你需要的
东西，但请不要多拿为其他人留一些。
LONG);

  set("objects", ([ /* sizeof() == 2 */
           __DIR__"obj/zhujian.c" : 2,
           __DIR__"obj/tengjia.c" : 2,
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "武道是用来帮助人而不是用来伤人，门下弟子切记",
]));

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"daochang",
]));

  setup();
  replace_program(ROOM);
}
