#define 1 north
#define 2 south
#define 3 west
#define 4 east
#define 5 up
#define 6 down

mixed *room_list;

object r_room()
{
int i;
object room;
room_list = get_dir("/d/hs/city/tu/");
i = sizeof(room_list);
if ( !i || i<=0 )
	room = load_object(__DIR__"road1");
else	{
	for ( i=0;i<sizeof(room_list);i++ )
		{
		room = load_object(room_list[i]);
		if ( room->query("changed") )
			continue;
		break;
		}
	}
return room;
}

void r_map()
{
int i,out;
object room = r_room();
object room2 = r_room();
room->delete("exits");
for ( i=0;i<(1+random(3));i++ )
	{
	out = (1+random(5))/2*2;
	if ( room->query("exits/"+out) )
		continue;
	room->set("exits/"+out,room2);
	room2->set("exits/"+(out+1),room);
	}
room->set("changed",1);
room2->set("changed",1);
room->save();
room2->save();
call_out("resets",300+random(300),room);
call_out("resets",300+random(300),room2);
message("channel:sys",HIR"【"NOR WHT"系统"NOR HIR"】"NOR WHT"四相迷宫动态地图启动。\n"NOR,users());  
remove_call_out("r_map");
call_out("r_map",600); //10分钟一变
}

void resets(object env)
{
if ( env->query("changed") )
	env->delete("changed");
return;
}
