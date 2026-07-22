// wu1.c 练武场
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",CYN"练武场"NOR);
       set("long", @LONG
这里是明教的练武场。地面是坚硬结实的黄土，已有百多年的践踢使得地
面光滑平整。练武场中间竖立着不少用来练暗器的木靶。很多明教教众正在练
习武艺。东面是明教的药房，而西边就是书院了。
LONG);    
	set("exits", ([
		"east" : __DIR__"yaofang",
                "west" : __DIR__"shuyuan",
                "south" : __DIR__"guangc",
		"north" : __DIR__"xting",
	]));             
	set("objects",([
		__DIR__"npc/f-dizi" : 1,
		__DIR__"npc/m-dizi" : 1,
                CLASS_D("mingjiao") + "/zhang" : 1,
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-290);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",200);
   set("coor/z",120);
   setup();
}

int valid_leave(object me, string dir)
{
        
        object ob;        
        /*
        mapping myfam;
        myfam = (mapping)me->query("family");        
       	if ((!myfam || myfam["family_name"] != "明教") && dir == "west" 
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n张中把手一伸拦住你的去路，你不是明教的不能进去！！\n\n"NOR);
	if ((!myfam || myfam["family_name"] != "明教") && dir == "east"
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n张中把手一伸拦住你的去路，你不是明教的不能进去！！\n\n"NOR);
          */
	if ( me->query_temp("marks/院1") && dir=="west"
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n张中把手一伸拦住你的去路，你已拿过书了还要拿呀！！\n\n"NOR);
        return ::valid_leave(me, dir);
}
