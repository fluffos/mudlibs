// Room: /u/dubei/u/gumu/jqg/ht1
// by dubei
 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "潭中");
	set("long", @LONG
四周蓝森森的都是玄冰，冰冷的潭水，让人感到透骨的寒冷。
远处有一丝的亮光。
LONG
	);
        setup();
}
void init()
{
        add_action("do_fu", "fu");
        add_action("do_qian", "qian");
}
int do_fu(string arg)
{
       object me = this_player();

       if( !arg || arg == "" || arg !=  "up") return 0;
  
        message_vision("$N一个狗刨，浮了上去。\n", me);
       me->move(__DIR__"gd1");
       tell_room(environment(me), me->name() + "湿淋淋的从潭中钻了出来。\n", ({ me }));
       return 1;
       
}
int do_qian(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "liang guang" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;
       message_vision("$N向着亮光游了过去，越潜越深，过不多时，“波”的一响，冲出了水面。\n", me);
       me->move(__DIR__"gd2");
       tell_room(environment(me), me->name() + "从潭水中冒了出来。\n", ({ me }));
       return 1;
}