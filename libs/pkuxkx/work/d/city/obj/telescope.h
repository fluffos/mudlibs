#include <ansi.h>
mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);
int do_look(string dir)
{
	int layers=2;
	object ori_room,room,me=this_player(),ob=this_object();
	mapping exits;
	ori_room=environment(me);
	if (!ori_room->query("exits"))
	return 0;
	exits=ori_room->query("exits");
	if (member_array(dir,keys(exits))==-1)
	return 0;
	message_vision(HIG+"$N举起了$n，向"+default_dirs[dir]+"望去。\n"+NOR,me,ob);
	if (query("layers"))
	layers=query("layers");
	for (int i=0;i<layers;i++)
	{
		room=load_object(ori_room->query("exits/"+dir));
		ori_room=room;
		"/cmds/std/look.lpc"->mudlook_room(me,room,0);
	}
	return 1;
}

void init()
{
	add_action("do_look","look");
	add_action("do_look","l");
}