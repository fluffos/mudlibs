//room: /d/tangmen/kefang.c
//restroom
inherit ROOM;

void create()
{
  set("short","客房");
  set("long", @LONG
  这里是唐门供访客住宿休息的地方。处在花园之中，推窗往外望,便能看见满园
鲜花灿烂，闻到阵阵幽香，甚是心旷神怡。
LONG       
     );

  set("exits",([
        "east" : __DIR__"huayuan7",
	"west" : __DIR__"huayuan6",
	"south" : __DIR__"chashi",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}





