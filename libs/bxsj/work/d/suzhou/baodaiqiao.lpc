#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
set("short",HIY"宝带桥"NOR);
set("long", @LONG
宝带桥横跨于苏州的运河之上，又因桥形宛若长带，被称为长桥。桥面
宽阔，行人在桥上来往，桥边有城里的小贩吆喝、叫卖着，熙熙攘攘，热闹
非凡。宝带桥卧于碧波之上，相应生辉，分外多骄。这里是中秋赏月的一处
绝佳之地。
LONG
);
 set("outdoors", "suzhou");
 set("objects",([
          __DIR__"npc/xiaofan" :  1,
       ]));

  set("exits",([
    "north" : __DIR__"canglangting",
    "south" : __DIR__"nandajie1",
    "northeast" : __DIR__"dongdajie3",
    "northwest" : __DIR__"xidajie1",
    ]));
	set("coor/x",110);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}
