//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;
#include <ansi.h>


void create ()
{
        set ("short", "金衣第二楼");
       set ("long",@LONG 
这是一个隐蔽的小楼，楼里的陈设富丽堂皇。除此之外，小楼里
只有一张很大的桌子。桌子上堆埋了各式各样的账册和卷宗。还有一
些似乎是武学秘籍，楼的左边有一扇小门，楼上就是金衣楼其余楼所在。
LONG);
	set("exits", ([
                "up"   : __FILE__,
                "down" : __FILE__,
        ]));
  	set("no_fight", 1);
  	set("no_magic", 1);
	set("no_clean_up", 0);
        setup();
}

int valid_leave(object who,string dir)
{
	if( dir!="up" && dir!="down" )
		return ::valid_leave(who,dir);
	if( !userp(who) )
		return 0;
	if(random(4)==1)
	{
		who->move("/d/luoyang/jinyi");
		return 2;
	}
	if( random(3)>0 )
		return notify_fail("你走来走去，累得浑身是汗。\n");
	return ::valid_leave(who,dir);	
}