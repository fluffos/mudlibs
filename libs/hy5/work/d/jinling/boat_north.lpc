inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_yell(string arg);

void create()
{
	set("short", "长江北岸");
	set("long", @LONG
长江北岸也是相当热闹，自北岸渡口往北，一条笔直的官道
直通南阳。此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一
面大大的「酒」旗迎风飘扬，蔚为壮观。也有不少小贩沿路叫买，
语多难辨，却也令人盛情难却。
LONG
	);

    set("exits", ([
		"northwest" : "/d/nanyang/yidao3",
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
	if( ob = find_object(__DIR__"duchuan")) ob->set("exits/out",__DIR__"boat_north");
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
                ob->set("exits/out",__DIR__"boat_south");
                message("vision", "船夫放下跳板，大声叫道：“船到岸啦！客官请上岸。\n",ob );
	}
	return;	
}



