
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是东大街。北面是一家赌场，南面有一家客栈。赌场中喊叫的
声音远远的传了过来，不时有赌徒从里面垂着头走了出来，也有赌徒被
人从赌场用棍棒打了出来。南边有一家客栈，店小二正在门口热情地招
呼着客人。
LONG);

  set("exits", ([ 

 "east":__DIR__"dongdajie3",
  "west":__DIR__"dongdajie1",
  "north":__DIR__"duchang",
  "south":__DIR__"kezhan",
         ]));
          set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

