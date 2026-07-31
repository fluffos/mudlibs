inherit ROOM;
#include <ansi.h>

int do_install(string arg);

void create ()
{
  set ("short","春园");
  set ("long", @LONG
这里是九江的春园，来来往往行人很多，热闹的声音不绝于耳。旁
边还有一座阁楼，门前牌匾上“春在楼”三个金漆的大字在阳光照耀下
闪闪发光。楼上传来了喝酒、嬉笑、吵骂的声音，又给春园增添了一份
热闹。
LONG);

  set("exits", ([ 

  "up":__DIR__"chunzailou",
  "west":__DIR__"beidajie2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  set("cisha_job",1);
  setup();
 
}

