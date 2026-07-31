// jianshi.c 剑室
// by chenww

inherit ROOM;

void create()
{
        set("short", "长江剑室");
        set("long", @LONG
长江剑室是浣花剑派的兵器房,浣花剑派收集的很多兵器都堆放在
这里.所有外出办事的弟子都在这里取兵器.
LONG
        );
        set("exits", ([
                "west" : __DIR__"xiaoxuan",
                "east" : __DIR__"zhenmei" ,
        ]));
        set("objects", ([
"/clone/weapon/changjian" : 2,	
                __DIR__"npc/xioagang" : 1,
                       ]));
  
        set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

