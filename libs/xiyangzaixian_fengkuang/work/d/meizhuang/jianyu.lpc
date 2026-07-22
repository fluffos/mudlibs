// jianyu.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", BLU"梅庄地牢"NOR);
        set("long", @LONG
这里黑黑暗暗，几乎伸手不见五指。唯一的光亮来自墙上忽明忽暗的
松油灯。地上和墙上布满了暗红色的血痕，散发出阵阵腥气。不断传来的
喘息声在死沉的地牢里回荡，令人毛骨耸然。从地牢的墙缝里透出几缕阳
光。
LONG
        );
        set("item_desc", ([
                "wall": "墙上的青石砖似乎以前有人动过什么手脚。\n",
        ]) );
        set("objects", ([
                "/d/heimuya/npc/renwoxing" : 1,
        ]) );
        set("valid_startroom","1");

        setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
        object room;
        if( (int)query("trigger")==8 && !query("exits/out") )
        {
message("vision", "墙壁被你推得裂开了一道缝隙，刚好可以容你钻出去。\n", this_object() );
                set("exits/out", __DIR__"xiaowu");
                if(!( room = find_object(__DIR__"xiaowu")) )
                     room = load_object(__DIR__"xiaowu");
                message("vision", "地下突然裂开一条窄缝。\n", room );
                room->set("exits/enter", __FILE__);
                delete("trigger");
                call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/out") ) return;
        message("vision",
"一片沙土落下来, 又将通道掩盖住了。\n", this_object());
//        if( room = find_object(__DIR__"east_castle") ) {
        if( room = find_object(__DIR__"xiaowu") )
        {
message("vision", "一片沙土落下来，又将通道掩盖住了。\n", room );
                room->delete("exits/enter");
        }
        delete("exits/out");
}

int do_push(string arg)
{
        string dir;

        if( !arg || arg=="" )
        {
                write("你要推什么？\n");
                return 1;
        }

        if( arg=="wall" || arg == "墙壁")
        {
                add("trigger", 1);
                write("你试著用力推着墙壁上的青砖，似乎有一点松动....\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}

