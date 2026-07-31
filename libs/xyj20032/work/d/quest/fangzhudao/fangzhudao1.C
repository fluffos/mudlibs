//放逐岛 fangzhudao1

#include <ansi.h>
#include <room.h>
inherit FANGZHU_ROOM; //放逐岛继承文件，不是普通的room

void create (int num)
{
  set ("short","放逐岛");
  set ("long", @LONG

这里是人迹罕至的放逐岛，荆棘丛生，一片荒芜，只有豺狼猛兽，
极难见到半个人影。
LONG);

	num = 0;
	set("outdoors", "fangzhudao");
  	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"fangzhudao2",
  		"south" : __DIR__"fangzhudao3",
  		"east" : __DIR__"kezhan",
	]));
	
  	set("objects", ([ /*     */   
  	]));
  
        set("alternative_die",1); 
        set("fangzhuroom",1); 
//放逐岛房间标志，cmds npc 判断所需！
        set("npc_num",num);//自己可以设定！
        setup();
        setup2();
}

void init2()
{
}