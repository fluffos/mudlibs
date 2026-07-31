// jiashan
// by chenww
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "假山");
	set("long", @LONG
这里是是一处假山群,是浣花剑派里的能工巧匠设计的.从这里再往
东走,就是萧家的祖祠--见天洞.祠堂前有一个老头正低着头,弯着腰在
扫地.
LONG
	);
        set("outdoors", "huanhua");

	set("exits", ([
		"west" : __DIR__"changlang",
		"east" : __DIR__"jiantiand",
	]));
      set("objects", ([
               __DIR__"npc/yabo" : 1]));
                

	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	}


int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "浣花剑派") && dir == "east" &&
                objectp(present("ya bo", environment(me))))
           return notify_fail("哑伯缓缓地伸出手来拦住你,笑道：见天洞是浣花剑派的禁地,不得入内。\n");
                
        return ::valid_leave(me, dir);
}
