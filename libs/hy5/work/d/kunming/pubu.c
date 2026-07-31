// /d/kunming/pubu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "黄果树大瀑布");
        set("long", @LONG
穿过花从，一个巨大的瀑布跃入眼前，水流如同白色的彩绸一般
直泻下来，发出震耳的声音，水气向你扑面而来，你只觉的凉爽无比，
在水流的冲击之下，瀑布底部形成了一个深不见底的水潭，碧绿清亮，
看到如此美景，就仿佛到了世外桃源一样。
LONG
        );
        set("outdoors", "kunming");
	set("exits", ([
                          "east"      : "/d/guizhou/shanlu3",
		
	]));            
        setup();
       
}


void init()
{
        add_action("do_enter", "poke");
	UPDATE_D->check_user(this_player());
}


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="huacong" ) 
	{
		message("vinson", HIY "你拔开花丛走了出去\n\n" NOR, this_player());

                me->move(__DIR__"yunnan5");
                
		return 1;
	}
}	


