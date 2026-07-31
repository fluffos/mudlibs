// ROOM: /city/youju.c
// Date: 28/5/2000 by happy
#include <ansi.h>;
inherit ROOM;
void create()
{
  set ("short",HIG"四海货运店"NOR);
set ("long",@LONG
这里是扬州四海货运店,熙熙攘攘的人很多,非常繁忙。
此店正在招收江湖人士前来帮忙，以次获得一些报酬。墙上帖着一张布告(post)。
LONG
);
  set("objects",([
  "/quest/songhuo/postman":1,
]));
set("item_desc",([
"post":"布告上面写着:本店诚招送货员有意都请用quest来打听。\n",
]));
  set("exits",([
  "north": "d/city/youju",
]));
set("no_steal", "1");
set("no_fight", "1");
set("no_sleep_room", "1");
setup();
replace_program(ROOM);
}
