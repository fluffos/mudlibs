//midao

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        
        set("short", "秘室");
        set("long","这里是明教秘室，前方有一扇大石门，上面刻着:
                " + HIR "明教重地，非教主莫入" NOR + "
据说里边机关重重，危机四伏，数十年来，入内者除张无忌外再无人生还。\n");

        set("exits", ([    
              "out" : __DIR__"neishi",

        ]));


        setup();

}


void init()
{
        add_action("do_push","push");
        
}

do_push(string arg)
{

        string *midao=({
                                 __DIR__"midao0",
                                 __DIR__"midao1",
                                 __DIR__"midao2",
                                 __DIR__"midao3",
                                 __DIR__"midao4",
                                 __DIR__"midao5",
                                 __DIR__"midao6",
                                 __DIR__"midao7",
                        });

	object me;

        me=this_player();

        if( !arg || arg=="" )
		return notify_fail("push <物件>\n");

        if(arg=="men" || arg=="door")
	{
                if(me->query("force")>=300)
        	{
                	message_vision("$N运起内力朝石门推去,石门缓缓地开了。\n",me);
                	set("exits/enter", midao[random(8)]);

	                remove_call_out("close");
        	        call_out("close", 5, this_object());

	                return 1;
		}

		return notify_fail("你的内力不够。\n");

	}
	return notify_fail("你要推什么？\n");
}

void close(object room)
{
        message("vision","石门移回原地。\n", room);
        room->delete("exits/enter");
}

int valid_leave(object me,string dir)
{
        me->delete_temp("bagua/xiu");
        me->delete_temp("bagua/sheng");
        me->delete_temp("bagua/shang");
        me->delete_temp("bagua/du");
        me->delete_temp("bagua/jing");
        me->delete_temp("bagua/si");
        me->delete_temp("bagua/jing1");
        me->delete_temp("bagua/kai");

	return ::valid_leave(me,dir);
}