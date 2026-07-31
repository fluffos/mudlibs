// ROOM:__DIR__"canyon1"

inherit ROOM;
void create()
{
        set("coor",({-200,4500,0}));
	set("short","黄石隘口尾");
	set("long",
"脚下为碎石黄土路，两侧是高耸入云的荒山，向上仰望乃似无边无际穹空，北缘为一山壁，\n"
"壁上有一长达十七、八丈的铁索(chain)，上面大概就是人家所谓的「关外绿洲－雪亭镇」\n"
"。\n"
); // eof(long)

	set("item_desc", ([
        	"chain" : @TEXT
    一长条铁索缘山壁而上，若无绝佳的体力就好不要轻意攀爬(climb)。
TEXT
	]) );
	
	set("exits",([ /* sizeof()==1 */
		"southwest" : __DIR__"canyon2",
	]) ); //eof(exits)
	
        set("outdoors","yanmen");
	setup();
	
} 

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{ 
        object me;
        
        me=this_player();
        
	if ( arg != "chain" ) return 0;

        message_vision("$N手脚并用，努力地沿著铁索向上攀缘上去了\n",me);
                       

	
	if ( ((int)me->query("qi") < 0) ||
	     ((int)me->query("jing") < 0) ||
	     ((int)me->query("neili") < 0) ) {   //判别式
           	tell_room("/d/xueting/path1",me->name()+"体力不支了。\n");
            	me->move("/d/xueting/path1");
	        return 1;
	}
        
        tell_room("/d/xueting/path1",me->name()+"平安的从下面爬了上来。\n");
	me->move("/d/xueting/path1");
        return 1;
}

