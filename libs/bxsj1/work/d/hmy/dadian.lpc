// /d/hmy/dadian.c

inherit ROOM;

void create()
{
	set("short", "大殿");
	set("long", @LONG
进得大殿，只见殿堂阔不过三十来尺，纵深却有三百来尺，长端彼端高
设一座椅，那座椅套以淡黄锦缎制成，金黄色丝线绣了九条金龙，捧着中间
一个刚从大海之中升起的太阳。那九条金龙张牙舞爪，神采如生，周围缀了
不少明珠、钻石，和诸般翡翠宝石，满堂尽是珠光宝气。
LONG
	);

	set("exits", ([ 
          "north" : __DIR__"cddian",
	  "west" : __DIR__"changlang",
	  "east" : __DIR__"changlang6",
	  "south" : __DIR__"changlang5", 
]));

	setup();
}

/*
void init()
{


    object book, me;
    me = this_player();
    add_action("do_move", "move");
    if ((objectp(book=present("dadian",me)))) {
        remove_call_out("buqun_rob");
        call_out("buqun_rob", 1, me, book);
    }
}

int do_move(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="chair" ) {
                write("你认为你可以搬的动这张大座椅吗？\n");
                return 1;
        }


        message_vision(
        "$N运足内劲，运力往大座椅一搬。\n", this_player());

        if (n>=1000) {
        message_vision(
        "忽然嘭的一声响，大座椅下原来有个地道！\n", this_player());
        set("exits/down", __DIR__"dedao");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声，双手拼命猛搬大座椅，但好象搬不动，看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","那座椅忽然复位，又堵住了地道。\n", room);
        room->delete("exits/east");
}
*/
