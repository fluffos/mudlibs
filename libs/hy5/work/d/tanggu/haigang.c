#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "塘沽口");
	set("long", @LONG
这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群海
鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大
船(chuan)，船上坐着几个渔夫打扮的人，乘船可渡过大海到达海的另一端。
西面过天津城就是北京了，东面是一望无际的大海。海边还有一般小快船!
你可以进去(enter)看看!!
LONG );
	set("exits", ([
                "west" : __DIR__"stdongjie1",
	]));
	set("item_desc", ([
                "chuan" : "一艘大帆船，造得很结实，看来可以出远海的。\n",
	]));
	set("objects", ([
                "/d/city2/npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" :1,
		//"/d/binghuodao/npc/chuanfu" :1,

	]));
//	set("no_clean_up", 0);
	set("outdoors", "tanggu");
	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "神龙教")
{
     message_vision("$N这是神龙教的快船,你不能上!\n",  ob);
    return 1;
}
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，快船就向东方航行。\n", ob);
    ob->move("/d/shenlong/haitan") ;
    tell_object(ob, BLU "你在海上航行了一会就到了一个岛上!\n" NOR ) ;
    return 1 ;
}