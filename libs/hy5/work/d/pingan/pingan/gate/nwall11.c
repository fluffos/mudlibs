inherit ROOM;
void create()
{
        set("short", "北城墙4");
        set("long", @LONG
丈许宽的城墙又高又厚，给人一种安全的感觉。遥望城外，绿色的田野一望无垠，
一座座小小的农房星星点点的点缀着宽广的田野，傍晚时，炊烟袅袅，夕阳斜照，美
不胜收。远处连绵的群山更是令人感到威武壮观。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nupgate",
  "east"  : __DIR__"nwall10", 
]));
        set("outdoors", "pingan");
	setup();
}

 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>8 && dir == "west" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/nwall11");
 	return notify_fail("忽然从城中爬上一个黑影！\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

