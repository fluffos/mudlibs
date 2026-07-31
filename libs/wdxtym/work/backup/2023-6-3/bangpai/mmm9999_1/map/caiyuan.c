inherit ROOM;

#define PLANT "/d/bangpai/plant/plant"
#define FARM "/d/bangpai/farm/farm"

void create()
{
	set("short", "菜园");
	set("long", "菜园子。\n");
	
	set("action_list", ([
		"菜地" : "look_caidi",
		]));
	set("objects", ([
		"/d/bangpai/plant/laonong" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"chufang",
		"east" : __DIR__"muchang",
		]));
		
	set("no_fight", 1);
	set("outdoors", 1);
	set("bangpai_room","1");
	set("bangpai/caiyuan",1);
	setup();
}

void init()
{
	add_action("do_look_caidi", "look_caidi");
	add_action("do_lookveg", "lookveg");
	add_action("do_plantveg", "plantveg");
	add_action("do_shouveg", "shouveg");
	add_action("do_chanveg", "chanveg");
}

int do_look_caidi(string arg)
{
	object who = this_player();
	PLANT->look_caidi(who, arg);
	return 1;
}

int do_plantveg(string arg)
{
	object who = this_player();
	PLANT->plantveg(who, arg);
	return 1;
}

int do_lookveg(string arg)
{
	object who = this_player();
	PLANT->lookveg(who, arg);
	return 1;
}

int do_shouveg(string arg)
{
	object who = this_player();
	PLANT->shouveg(who, arg);
}

int do_chanveg(string arg)
{
	object who = this_player();
	PLANT->chanveg(who, arg);
}


int valid_leave(object me, string dir)
{
	string fb_id;
	object room;
	
	if (userp(me) && dir == "east")
	{
	    FARM_D->sort_farmd(me);
	    room = new(query("exits")["east"]);
	    FARM->init_muchang(me, room);
	    me->move(room);
	    write("你来到了牧场。\n");
	    return 1;
	}
	
	return ::valid_leave(me, dir);
}