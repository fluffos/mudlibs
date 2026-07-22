// caiji@SJ 8/24/2000
// Modify by Lklv 2001.10.16

inherit ROOM;

void create ()
{
	set ("short", "虫谷入口");
	set ("long", @LONG
又走了一程，越走越荒凉，转入了一处阴森森的山谷之中，眼见四下里阴
沉沉的，似乎有毒雾弥漫，不是久留之所。面前有一个木制的大门，上面有一
把金制大锁，还有一名星宿派的弟子在这里做守卫，不许外人随便进去。在路
旁边，竖着一块木制的牌子，牌子由上到下写着「毒虫谷」三个字，你不由得
惊讶地啊了一声，怎么闯到了这个地方。
LONG);
	set("outdoors", "星宿");
	set("exits",([
		"southwest" : __DIR__"xx1",

	]));
	set("objects",([
		__DIR__"npc/kanshou" : 1,
	]));
        setup();
}

void open_enter1(){
	call_out("open_enter", 2);
}

void close_enter1(){
	call_out("close_enter", 2);
}

void open_enter()
{
	//this open_down() will be called by the NPC "kanshou".
	object downroom;

	if( !(downroom = find_object(__DIR__"duchonggu-out")) )
		downroom = load_object(__DIR__"duchonggu-out");

	set("exits/north", __DIR__"duchonggu-out");
	downroom->set("exits/south", __FILE__);
	message("vision","大门发出轧轧的声音，慢慢打开，你现在可以进去了。\n", this_object() );
	message("vision","大门发出轧轧的声音，慢慢打开，你现在可以出去了。\n", downroom );

	call_out("close_enter", 20);
}

void close_enter()
{
	object downroom;

	if( !query("exits/north") ) return;

	message("vision","大门发出轧轧的声音，重新又关上了。\n", this_object() );

	if( downroom = find_object(__DIR__"duchonggu-out") ){
		message("vision","大门发出轧轧的声音，重新又关上了。\n", downroom );
		downroom->delete("exits/south");
	}
	delete("exits/north");
}
