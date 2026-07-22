// wuqiku.c 武器库
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","武器库");
	set("long",
          "这里是血河派的武器房，进来后就只看到房间里全是武器，靠墙的兵
器架上摆放的都是长兵器：枪，矛，戟，棍，铲，叉，耙，槌等。你可以
挑自己喜欢的武器，向师傅请教。当然你也可以先拜师，再来拿相应的武
器。\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
                  "south" : __DIR__"chufang",
     	]));
     	set("objects",([
		"/clone/weapon/dandao" : 1,
		"/d/longmen/xuehepai/obj/tiegong" : 1,
		"/clone/weapon/changjian" : 1,
                 "/clone/weapon/tielianzi" : 2,
		"/clone/weapon/changbian" : 1,
     	]));
     	setup();
     	replace_program(ROOM);
}
     
