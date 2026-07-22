// 纪永河渡船

#define SHIP __DIR__"boat"

inherit ROOM;
void create()
{
	set("short", "黄河渡船");
	set("long", @LONG
黄河上的渡船大都是这种很简陋的小舟。一位年迈的艄公正站在船尾吃力
地掌舵，一位膀子壮硕的小伙子也在船头用劲地划水撑船。
LONG );

        set("no_fight", "1");
        set("no_sleep_room", 1); 
        set("side", "road3");

	set("outdoors", "兰州");
	setup();
}

int arrive(string arg)
{
	object room, ob;
     
	ob = this_object();

	if(!ob->query("start")) ob->set("start", 1);
	if(!(string)ob->query("side")) set("side", "road3");
	if(stringp(arg)) set("side", arg);
	if(!(room = find_object(__DIR__+ob->query("side"))))
		room = load_object(__DIR__+ob->query("side"));
	if(room = find_object(__DIR__+ob->query("side"))){
		ob->set("exits/out", __DIR__+ob->query("side"));
		room->set("exits/enter", SHIP);
		message("vision", "\n渡船猛地一震，已经靠岸，船夫说道：“请大伙儿下船吧！”\n", ob);
		message("vision", "说着将一块踏脚板搭上堤岸，形成一个出去(out)的阶梯。\n", ob);        
		message("vision", "\n一艘渡船缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下(enter)。\n", room);
		remove_call_out("on_board");
		call_out("on_board", 20);
	}
	return 1;
}

void on_board()
{
	object room, *obj, ob;
        int i;
        
        ob = this_object();
        
        if( !query("exits/out") ) return;

        if( room = find_object(__DIR__+ob->query("side")) ){
                obj = all_inventory(ob);
                for(i = 0; i < sizeof(obj); i++) {
                        if (userp(obj[i]) && obj[i]->query_temp("side") != ob->query("side")) {
                                if (!living(obj[i])) message_vision("艄公把$N抬下了船。\n", obj[i]);
                                obj[i]->move(room);
                                obj[i]->delete_temp("side");
                                if (!living(obj[i])) tell_room(room, obj[i]->name() + "被抬下了船。\n", ({obj[i]}));
                                else tell_room(room, obj[i]->name() + "走下了船。\n", ({obj[i]}));
                        }
                }
                room->delete("exits/enter");
                message("vision", "\n艄公们把踏脚板收了起来，长篙一点，渡船向河心驶去。\n", this_object());
                message("vision", "\n艄公们把踏脚板收起来，说了一声“坐稳喽”，长篙一点，渡船向河心驶去。\n", room);
                }
        delete("exits/out");
        if(ob->query("side") == "road3") ob->set("side", "road2");
        else ob->set("side", "road3");
        remove_call_out("arrive");
        call_out("arrive", 10+random(10));
}
