#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "移花宫宫主卧室");
	set("long", @LONG
这里是移花宫两位宫主的卧室。这里到处都充满了花香，使你陶醉其中。
床铺也是装饰的像花床一样。你仔细的看了一下床(bed)，似乎有点不对劲，
你凑上前去看了一下。
LONG
	);
        set("sleep_room", 1);   
        set("exits", ([
        "northwest" : __DIR__"yaoyue",
        "northeast" : __DIR__"lianxing",
	]));
	set("item_desc", ([
        "bed": "一张普普通通的床，但是你仔细的看了一下，似乎能移动。。\n"
	]) );

	setup();
}

void init()
{
	add_action("do_push", "push");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==8
        &&  (int)query("right_trigger")==5
	&&	!query("exits/down") ) {
        message("vision", "床板忽然发出轧轧的声音，缓缓向两边移动著，露出一个向下的阶梯。\n",
			this_object() );
        set("exits/down", __DIR__"midao");
        if( room = find_object(__DIR__"midao") ) {
			room->set("exits/up", __FILE__);
            message("vision", "忽然发出轧轧的声音，缓缓向两边移动著，露出一个向上的阶梯。\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
    message("vision", "床板忽然发出轧轧的声音，缓缓合拢，将向下的通道盖住了。\n",
		this_object() );
    if( room = find_object(__DIR__"midao") ) {
		room->delete("exits/up");
        message("vision", "床板忽然发出轧轧的声音，缓缓合拢，将向上的通道盖住了。\n"
                        HIY "你脑海中闪过一个念头：坏了！出不去了！\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="bed" ) {
		write("你试著推动许多鲜花铺成的床板，发现它可以左右移动....\n");
		return 1;
	}
	if( sscanf(arg, "bed %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N将床板往右移...，忽然轧轧几声床板又移回原位。\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N将床板往左移...，忽然轧轧几声床板又移回原位。\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将床板移向那个方向？\n");
			return 1;
		}
	}
}
void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
