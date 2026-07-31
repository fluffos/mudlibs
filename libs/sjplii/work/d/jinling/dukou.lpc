//jinling  dukou.c
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江渡口，联系着两大城市的交通。来往商贩络绎不绝，好一个
繁华所在。在这里你可以坐船去xxx。附近的农夫经常把他们种的蔬菜运到
那里卖，江上有几只小舟，只要你喊(yell)一声“过江”，他们就会把船
驶近。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"yuhuatai",

]));
 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
   //     replace_program(ROOM);
}
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
       set("exits/enter",__DIR__"boat");
	message_vision("船家对$N应道：来...啦.....\n", this_player());
	write("船来了，你可以上船(enter).\n");
	if( ob = find_object(__DIR__"boat")) ob->set("exits/out",__DIR__"jiangbei");
	call_out("kaichuan_nn",10);
	call_out("daoan_nn",20);
	return 1;
}
void kaichuan_nn()
{
	object ob;
	if( ob = find_object(__DIR__"boat")) {
                ob->delete("exits/out");
                message("vision", "船夫收起了跳板，把船缓缓驶出江心。\n",ob );
	}
       message("vision", "船夫收起了跳板，把船缓缓驶出江心。\n",this_object());
	delete("exits/enter");
	return;	
}
void daoan_nn()
{
	object ob;
	if( ob = find_object(__DIR__"boat")) {
                ob->set("exits/out",__DIR__"jiangbei");
                message("vision", "船夫放下跳板，大声叫道：“船到岸啦！客官请上岸。\n",ob );
	}
	return;	
}

