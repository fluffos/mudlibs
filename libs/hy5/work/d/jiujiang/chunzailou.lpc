inherit ROOM;

int do_install(string arg);

void create ()
{
  set ("short","春在楼");
  set ("long", @LONG
这里是九江的春园旁的春在楼。这里是九江最有名的妓院，这里的
女子虽不上国色天香，但也称得上是沉鱼落雁了。有几个打扮得花枝招
展的女子正在门口招呼着客人。里面的房间不时传来嬉笑的声音。春在
楼的里面还有一个小饭店，供应各种特色的美食。
LONG);

  set("exits", ([ 

  "down":__DIR__"chunyuan",
         ]));
  set("objects",([
     __DIR__"npc/jiuke":1,
     __DIR__"npc/jianke":1,
     __DIR__"npc/zhanggui":1,
     __DIR__"npc/girl":1,
     	__DIR__"npc/xiang":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}

