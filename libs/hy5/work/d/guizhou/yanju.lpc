
#include <ansi.h>
inherit ROOM;

#define JOBNAME "贵阳"

void create ()
{
  set ("short","阳明祠");
  set ("long", @LONG
阳明先生逝世后，贵阳人为纪念他而修建该祠。祠内殿堂中，
有王阳明先生汉白玉坐像，两侧为先生手书：“壮思风飞冲情云上
，和光春霭爽气秋高”木刻对联。殿堂外碑廊有王阳明先生手书《
矫亭记》和家书文稿及燕服画像。
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie",
       ]));
  set("objects",([
	  "/clone/npc/man":2,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

