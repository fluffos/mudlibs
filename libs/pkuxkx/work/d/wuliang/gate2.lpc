// by paladin

inherit ROOM;
int do_push(string);

void create()
{
set("short","洞门");
        set("long", @LONG
越走越低。突然之间，右手碰到一件凉冰冰的圆物，一触之下，那圆
物当的一下，发出响声，声音清亮，伸手再摸，原来是个门环. 那门
(men)似是用铜铁铸成，甚是沉重，但里面并未闩上.
LONG
        );
set("outdoors", "dali");

        set("exits", ([
"westup" : __DIR__"droad2",
        ]));


        set("item_desc", ([
               "men" : "这是一扇铜门\n",
        ]) );


        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_push", "push");
 
}

int do_push(string arg)
{


        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men" ) {
                write("你要推什麽\n");
                return 1;
        }


        message_vision("$N深吸一口气，伸手推门. \n", this_player());

        if (n>=200) {
        message_vision("$N手上使劲，慢慢将门推开了，眼前陡然光亮\n", this_player());
        set("exits/east", __DIR__"shishi");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision("那门甚是沉重，$N怎麽推都推不开, 看来还是内力不够强。\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","铜门又幌了一下，挡住了石室。\n", room);
        room->delete("exits/east");
}


