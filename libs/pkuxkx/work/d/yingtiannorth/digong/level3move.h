#define NPC_MOVE 2
#define PLAYER_MOVE 3
int valid_leave(object me,string dir)
{
	mapping cdir=(["north":"北面","south":"南面","east":"东面","west":"西面"]);
	if (dir=="out"&&!userp(me)) return 0;
	if (time()-me->query_temp("karma/level3/move")<NPC_MOVE&&!userp(me)) return 0;
	if (time()-me->query_temp("karma/level3/move")<PLAYER_MOVE&&userp(me)&&dir!="out") return notify_fail("在甬道里，看不清楚太远，你一步步向"+cdir[dir]+"移去。\n");
	me->set_temp("karma/level3/move",time());
	if (me->is_KARMA_THIEF())
	{
		environment(me)->delete("thief_place");
		environment(me)->query("exits/"+dir)->set("thief_place",1);
	}
	return ::valid_leave(me,dir);
}

void init()
{
	add_action("do_checkMap","localmap");
	::init();
}

int do_checkMap()
{
	string local="";
	string * places=({"a1","a2","a3","a4","b1","b2","b3","b4","c1","c2","c3","c4","d1","d2","d3","d4"});
	string map="甲一--甲二--甲三--甲四\n |     |     |     |\n乙一--乙二--乙三--乙四\n |     |     |     |\n丙一--丙二--丙三--丙四\n |     |     |     |\n丁一--丁二--丁三--丁四\n";
	for (int i=0;i<sizeof(places);i++)
	if (load_object(__DIR__"level3"+places[i])->query("thief_place"))
	local=replace_string(COLOR_D->uncolor(load_object(__DIR__"level3"+places[i])->query("short")),"甬道","");
	if (local=="") 
	{
		write(map);
		return 2;
	}
	map=replace_string(map,local," ¤ ");
	write(map);
	return 1;
}