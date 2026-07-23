inherit ROOM;


void create()
{
    set("short", "长江南岸");
    set("long", @LONG
面前是一条波涛翻滚的大江(river)。浊流滚滚，万舟竞发。
两岸渡船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸
边，几个破萝支一块木板，板上摆满了活蹦乱跳的汉江鲤鱼。过
去不远，是有名的老河口，不少过江客都在这里等待渡船摆渡。
LONG
    );

    set("exits", ([
        "south" : __DIR__"guanroad3",
        "east" : __DIR__"jiangdao5",
    ]));

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "jinling");
    setup();
}


/*在此付钱摆渡或买鱼吃*/
/*（等）渡船靠了岸，付了钱，船家一声吆喝，客人们一涌
 * 而入，小小渡船片刻间便越过波澜涛涛的汉江，靠上北岸
 */

void init()
{
         add_action("do_jiaochuan", ({"yell"}) );
}

int do_jiaochuan(string arg)
{
	object ob,ob1;
	if(!arg || (arg!="过江" && arg!="boat" )) {
	     if(!arg) arg = " ? ? ? ";	
	     message_vision("$N对着江面喊道: " + arg + "......\n", this_player());
	     return 1;	
	}
	message_vision("$N对着江面喊道: 船..家...渡我过江...\n", this_player());
	if( query("exits/enter") )
		return notify_fail("船已经在这儿了, 你可以上船(enter).\n");
       set("exits/enter",__DIR__"duchuan");
	message_vision("船家对$N应道：来...啦.....\n", this_player());
	write("船来了，你可以上船(enter).\n");
	if( ob = find_object(__DIR__"duchuan")) ob->set("exits/out",__DIR__"boat_south");
	call_out("kaichuan_ss",10);
	call_out("daoan_ss",20);
	return 1;
}
void kaichuan_ss()
{
	object ob;
	if( ob = find_object(__DIR__"duchuan")) {
                ob->delete("exits/out");
                message("vision", "船夫收起了跳板，把船缓缓驶出江心。\n",ob );
	}
       message("vision", "船夫收起了跳板，把船缓缓驶出江心。\n",this_object());
	delete("exits/enter");
	return;	
}
void daoan_ss()
{
	object ob;
	if( ob = find_object(__DIR__"duchuan")) {
                ob->set("exits/out",__DIR__"boat_north");
                message("vision", "船夫放下跳板，大声叫道：“船到岸啦！客官请上岸。\n",ob );
	}
	return;	
}


