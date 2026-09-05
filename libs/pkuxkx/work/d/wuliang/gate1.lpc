// by paladin

inherit ROOM;
int do_push(string);

void create()
{
set("short","谷底小路");
        set("long", @LONG
眼前一块巨石(stone), 岩高齐胸, 手掌沾到岩上青苔，但觉滑腻腻地，
那块岩石竟似微微摇幌. 大小岩石之间长满了蔓草葛藤.
LONG
        );
set("outdoors", "dali");

        set("exits", ([
"north" : __DIR__"hroad4",

        ]));

        set("item_desc", ([
               "stone" : "这是一块巨石\n",
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
        if( !arg || arg!="stone" ) {
                write("你要推什麽\n");
                return 1;
        }


        message_vision("$N深吸一口气，双手齐推岩石右侧. \n", this_player());

        if (n>=450) {
        message_vision("那岩石缓缓转动，便如一扇大门相似，只转到一半，便见岩石露出一个三尺来高的洞穴\n", this_player());
        set("exits/south", __DIR__"gate");
        this_player()->set("neili",n-450);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
"岩石又幌了一下，但一幌即回，石底发出藤萝之类断绝声音, 
看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","岩石又幌了一下，挡住了洞穴。\n", room);
        room->delete("exits/south");
}


