#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short", HIC"澜沧江边"NOR);
         set("long",@LONG
你沿着山坡走到澜沧江边，朝阳初升，照得碧玉般的江面上犹如镶了一层黄金一般，
壮丽无比，你站在这里，心中什么也不愿意想，只希望就这样天长地久，时间永恒。
LONG
 );

        set("exits",([
	"northwest" : "/d/xinan/jiangbian",
             "eastup" : __DIR__"gaoshan",
]));
        
	set("outdoors", "大理");
	setup();
//	replace_program(ROOM);
}
void init()
{
       object me = this_player();
      
	  if (me->query_temp("duanyu/find2"))
	   {
	   me->set_temp("wait", 1);
       call_out("do_wait", 20 + random(10), me);
       }
       add_action("do_jump", "jump");
       add_action("do_tiao", "tiao");
    	add_action("do_look", "look");
    	add_action("do_look", "kan");
}

void do_wait(object me)
{
        
        if(environment(me) && me->query_temp("wait") ) 
          {
           write(HIY"\n你悄立江边，思涌如潮，心中思绪万千。突然眼角瞥处，见数十丈外一块大岩石（yan)上似乎有些古怪。\n"NOR);
           me->del_temp("wait");
		   me->set_temp("yan1",1);
           }
}

int do_look(string arg)
{
	object me = this_player();

	if (!me->query_temp("yan1")) {
		set("long", @LONG
你沿着山坡走到澜沧江边，朝阳初升，照得碧玉般的江面上犹如镶了一层黄金一般，
壮丽无比，你站在这里，心中什么也不愿意想，只希望就这样天长地久，时间永恒。
LONG
);
		me->look(arg);
	}
	else {
		if (!arg) {
			set("long", @LONG
你沿着山坡走到澜沧江边，朝阳初升，照得碧玉般的江面上犹如镶了一层黄金一般，
壮丽无比，你站在这里，心中什么也不愿意想，只希望就这样天长地久，时间永恒。
你悄立江边，思涌如潮，心中思绪万千。突然眼角瞥处，见数十丈外一块大岩石（yan)
上似乎有些古怪。
LONG
);
			me->look(arg);
		}
		else if (arg == "rock" || arg == "yanshi" || arg == "yan") {
			write("一块巨岩，不知道可不可以跳上去？\n");
			me->set_temp("yan2", 1);
			return 1;
		}
       }		
}
int do_jump(string arg)
{
               object me;
               me = this_player();
               if (arg !="yan"|| !me->query_temp("yan2")) 
                   return notify_fail("你要跳到那去？\n");
                if (me->query_skill("dodge",1)<80) 
                    write("你打量了下岩石和你之间的距离，似乎太远了，只好做罢。\n");
                else {
                    write("你一提气，纵身跳到了岩石上。\n");
                    message("vision",
                             me->name() + "一纵身跳到了几十丈远的大岩石上。\n",
                             environment(me), ({me}) );
                    me->delete_temp("wait");
				    me->delete_temp("yan1");
				    me->delete_temp("yan2");     
					me->move(__DIR__"yan");
                    message("vision",
                             me->name() + "从下面跃了上来。\n",
                             environment(me), ({me}) );
                return 1;
           }
}

int valid_leave(object me,string dir)
{
        if (me->query_temp("wait"))
                me->delete_temp("wait");
				me->delete_temp("yan1");
				me->delete_temp("yan2");     
        return ::valid_leave(me,dir);
}
