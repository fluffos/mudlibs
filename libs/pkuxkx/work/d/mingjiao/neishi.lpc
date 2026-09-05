// neishi
// yuer 

inherit ROOM;

int do_push(string arg);

void create()
{
	set("short", "闺房");
	set("long", @LONG
这是杨不悔小姐的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂着细纱。
四面墙壁上挂了好些刀剑。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houhuayuan1",
	]));
	set("no_mj_newbie",1);
	setup();
	
}
void init()
{
       
	add_action("do_push", "push");
}

int do_push(string arg)
{

        if( !arg || arg=="" ) return 0;

        if( arg=="绣榻")
        {
                write("只听床下发出几声响。\n");
		message("vision", "看见床下有个洞。\n", this_player());
                set("exits/down", __DIR__"midao");

                remove_call_out("close");
                call_out("close", 5, this_object());

                return 1;
        }
}

void close(object room)
{
        message("vision","绣榻移回原地。\n", room);
        room->delete("exits/down");
}




