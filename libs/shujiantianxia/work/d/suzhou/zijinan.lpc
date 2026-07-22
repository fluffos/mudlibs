inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"紫金庵"NOR);
        set("long", @LONG
这是一座苏州城里有名的寺庵，庵中正面是释加摩尼佛眼，似乎在注视
前来礼佛之人；右壁一尊诸天用三个手指托起一块轻柔的绣花经盖和后壁观
音菩萨头上的一顶刻着牡丹花的紫红色华盖。左壁的每尊罗汉塑像造型生动，
各具特征，到达了以神人话、精神超忽、呼之欲活的艺术境界，令人叹为观
止。
LONG
);
        set("exits", ([ 
	"east" : __DIR__"beidajie2",
	]));
        set("objects",([
        __DIR__"npc/nigu"  : 2,
 __DIR__"obj/box" : 1,
]));
        set("coor/x",100);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
//      设想把少林的丝绢放在菩萨上，然后磕头会加经验！(put silk on xxx)
}

