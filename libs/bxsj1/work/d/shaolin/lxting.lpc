//lxting.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", MAG"立雪亭"NOR);
	set("long", @LONG
你沿台阶拾阶而上，眼前出现一座亭子一般的殿堂。殿前横匾上写着『
立雪亭』三个大字。这里又名达摩亭。殿内佛龛供奉达摩铜像和二祖，三祖
，四祖，五祖的立像。相传这是神光立雪断臂得授达摩真传衣钵的地方。殿
内正中的蒲团上坐着一位白眉白须的老僧。
LONG
	);

	set("exits", ([
		"north" : __DIR__"sblu-2",
                "southdown" : __DIR__"taijie",
       ]));
        set("objects",([
		CLASS_D("shaolin") + "/hui-guang" : 1,
	]));

	set("coor/x",50);
  set("coor/y",360);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",360);
   set("coor/z",130);
   setup();
	
}

int valid_leave(object me, string dir)
{
     mapping myfam;
     myfam = (mapping)me->query("family");
    

    if (!me->query("luohan_winner") &&
       (!myfam || myfam["family_name"] == "少林派" ) &&
       objectp(present("huiguang zunzhe", environment(me))) &&
       dir == "north" ) 
    {
     return notify_fail("慧光伸手拦住你躬身说道：后面乃是本寺重地，你的辈份"
              "不够，不能擅入！\n");
    }
    if (!me->query("luohan_winner") &&
       (!myfam || myfam["family_name"] != "少林派" ) &&
       objectp(present("huiguang zunzhe", environment(me))) &&
       dir == "north" ) 
    {
          return notify_fail("慧光伸手拦住你躬身说道：后面乃是我寺重地，你非本寺"
              "弟子，不能擅入！\n");
    }

    return ::valid_leave(me, dir);
}

