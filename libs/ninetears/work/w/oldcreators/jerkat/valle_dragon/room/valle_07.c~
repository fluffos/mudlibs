inherit "/w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);

// mirar para que sirve el do_desc(1) este...  //

add_exit("sur","/w/jerkat/valle_dragon/room/valle_05","road");
add_exit("este","/w/jerkat/valle_dragon/room/valle_07","road");
//add_clone("/w/jerkat/valle_dragon/nopc/mosquito",random(2));
}

void init()
{
	::init();
	add_action("ver", "jarl");
}

int ver(string str)
{
	object tmp;
	
	tmp = find_object("/w/jerkat/valle_dragon/room/valle_07");
	if(!tmp) {
	  tell_object(TP, "Va a ser que no.\n");
	  load_object("/w/jerkat/valle_dragon/room/valle_07");
	}
	else
	tell_object(TP, "Va a ser que si.\n");
	return 1;
}