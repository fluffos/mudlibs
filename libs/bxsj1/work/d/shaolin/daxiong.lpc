//daxiong.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"大雄宝殿"NOR);
	set("long", @LONG
这里是少林寺的大雄宝殿。面阔五间，进深四间。正中供奉着如来三宝
，左右各是文殊、普贤诸位菩萨。一群僧侣正自焚香诵经，仰观我佛拈花微
笑的神态，令人顿感肃然起敬。这里殿堂宽大，亦是方丈大师召集阖寺群僧
议事之所。
LONG
	);
        set("no_fight",1);
       	
	set("exits", ([
		 "south" : __DIR__ "pingtai",
                 "north" : __DIR__ "stoneroad1",
       ]));

	
	set("coor/x",50);
  set("coor/y",300);
   set("coor/z",120);
   setup();
}



