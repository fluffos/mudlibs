// wu3.c 练武场
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",CYN"练武场"NOR);
       set("long", @LONG
这里是明教的练武场。地面是坚硬结实的黄土，已有百多年的践踢使得地
面光滑平整。练武场中间竖立着不少用来练暗器的木靶。很多明教教众正在练
习武艺。东西面是一条长长的长廊，北边是广场，南边是光明顶。
LONG);    
	set("exits", ([
           "west"  :  __DIR__"cl1",
           "east"  :  __DIR__"cl2",
           "southdown" : __DIR__"gmd",
           "north" : __DIR__"guangc",
	]));
	set("objects",([
		__DIR__"npc/m-dizi" : 1,
		__DIR__"npc/f-dizi" : 1,
                CLASS_D("mingjiao") + "/wushou" : 1,
	]));             
        set("outdoors", "明教光明顶");
        set("coor/x",-290);
  set("coor/y",180);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",180);
   set("coor/z",120);
   setup();
}

int valid_leave(object me, string dir)
{
       mapping myfam;
       object ob;
       myfam = (mapping)me->query("family");
       if ((!myfam || myfam["family_name"] != "明教") && dir != "southdown" 
        && objectp(ob=present("yin wushou", environment(me))) && living(ob))
          return notify_fail(YEL"殷无寿把手一伸拦住你的去路，你不是明教弟子，不能进去！\n"NOR);	
       return ::valid_leave(me, dir);
}
