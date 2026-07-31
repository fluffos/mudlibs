// place.c
// dzj
// new 1/29/02

#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }

int color_len(string str)
{
        int i;
        int extra;
        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}

int main(object me, string arg)
{
	int i, j;
	object env, room;
	mapping exits;
	string str, *dirs, describe;
	env = environment(me);
	if( !env )
		return notify_fail("你的四周灰蒙蒙地一片，什么也没有。\n");
	if( !env->query("exits") )
		return notify_fail("你的四周没有明显的出口。\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你现在正忙着呢。\n");
	if( mapp(exits = env->query("exits")) ) {
		dirs = sort_array(keys(exits), 1);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
	} else return notify_fail("这里没有任何明显的出路。\n");
	if( sizeof(dirs)==0 )
		return notify_fail("这里没有任何明显的出路。\n");
        me->start_busy(2);
	str = sprintf( CYN"这里是"HIR"%s"CYN"，共有%s个出口，分别通往：\n"NOR,
		env->query("short"),
		chinese_number(sizeof(dirs)));
	str += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";

       if( env->query("exits/northup") && !(int)env->query_door("northup", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/northup"))) room = load_object(env->query("exits/northup"));
	describe = room->query("short")+"(Nu)";
	j = 29-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	}

       if( env->query("exits/northdown") && !(int)env->query_door("northdown", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/northdown"))) room = load_object(env->query("exits/northdown"));
	describe = room->query("short")+"(Nd)";
	j = 29-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	}

       if( env->query("exits/northwest") && !(int)env->query_door("northwest", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/northwest"))) room = load_object(env->query("exits/northwest"));
	describe = room->query("short")+"(Nw)";
	str += sprintf("%"+(18+color_len(describe))+"s",describe);
	} else if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/north")&&!(int)env->query_door("north", "status") & DOOR_CLOSED)
	|| (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
	str += "                  ";

       if( env->query("exits/north") && !(int)env->query_door("north", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/north"))) room = load_object(env->query("exits/north"));
	describe = room->query("short")+"(N)";
	j = (24-(strlen(describe)-color_len(describe)))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
	str += "                       ";

       if( env->query("exits/northeast") && !(int)env->query_door("northeast", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/northeast"))) room = load_object(env->query("exits/northeast"));
	describe = room->query("short")+"(Ne)";
	str += describe+"\n";
	}
	else if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/northwest")&&!(int)env->query_door("northwest", "status") & DOOR_CLOSED)
	|| (env->query("exits/north")&&!(int)env->query_door("north", "status") & DOOR_CLOSED) )
	str += "\n";

	if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/northwest")&&!(int)env->query_door("northwest", "status") & DOOR_CLOSED)
	|| (env->query("exits/north")&&!(int)env->query_door("north", "status") & DOOR_CLOSED)
	|| (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
{
	str += "\n";

	if( (env->query("exits/northwest")&&!(int)env->query_door("northwest", "status") & DOOR_CLOSED) )
	str += "                ＼"; else str += "                  ";

	if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/north")&&!(int)env->query_door("north", "status") & DOOR_CLOSED) )
	str += "          ┃          "; else  str += "                      ";

	if( (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
	str += "／\n"; else str += "\n";

	if( (env->query("exits/northwest")&&!(int)env->query_door("northwest", "status") & DOOR_CLOSED) )
	str += "                  ＼"; else str += "                    ";

	if( (env->query("exits/northup")&&!(int)env->query_door("northup", "status") & DOOR_CLOSED)
	|| (env->query("exits/northdown")&&!(int)env->query_door("northdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/north")&&!(int)env->query_door("north", "status") & DOOR_CLOSED) )
	str += "        ┃        "; else str += "                  ";

	if( (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
	str += "／\n"; else str += "\n";
}

       if( env->query("exits/westup") && !(int)env->query_door("westup", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/westup"))) room = load_object(env->query("exits/westup"));
	describe = room->query("short")+"(Wu)";
	j = 10-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else str += "                    ";

	if( (env->query("exits/northwest")&&!(int)env->query_door("northwest", "status") & DOOR_CLOSED) )
	str += "＼"; else str += "  ";

       if( env->query("exits/up") && !(int)env->query_door("up", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/up"))) room = load_object(env->query("exits/up"));
	describe = room->query("short")+"(U)";
	j = (14-(strlen(describe)-color_len(describe)-1))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else str += "              ";

	if( (env->query("exits/northeast")&&!(int)env->query_door("northeast", "status") & DOOR_CLOSED) )
	str += "／"; else str += "  ";

       if( env->query("exits/eastup") && !(int)env->query_door("eastup", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/eastup"))) room = load_object(env->query("exits/eastup"));
	describe = room->query("short")+"(Eu)";
	j = 10-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	} else str += "\n";

// 上半身制作完成。

       if( env->query("exits/west") && !(int)env->query_door("west", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/west"))) room = load_object(env->query("exits/west"));
	describe = room->query("short")+"(W)";
	str += sprintf("%"+(15+color_len(describe))+"s",describe);
	str += " ━━━ ";
	} else str += "                      ";

	describe = env->query("short")+"";
	j = 7-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";

       if( env->query("exits/east") && !(int)env->query_door("east", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/east"))) room = load_object(env->query("exits/east"));
	describe = room->query("short")+"(E)";
	str += " ━━━ ";
	str += describe+"\n";
	} else str += "\n";

// 中间部分制作完成。

       if( env->query("exits/westdown") && !(int)env->query_door("westdown", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/westdown"))) room = load_object(env->query("exits/westdown"));
	describe = room->query("short")+"(Wd)";
	j = 10-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else str += "                    ";

	if( (env->query("exits/southwest")&&!(int)env->query_door("southwest", "status") & DOOR_CLOSED) )
	str += "／"; else str += "  ";

       if( env->query("exits/down") && !(int)env->query_door("down", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/down"))) room = load_object(env->query("exits/down"));
	describe = room->query("short")+"(D)";
	j = (14-(strlen(describe)-color_len(describe)-1))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else str += "              ";

	if( (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
	str += "＼"; else str += "  ";

       if( env->query("exits/eastdown") && !(int)env->query_door("eastdown", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/eastdown"))) room = load_object(env->query("exits/eastdown"));
	describe = room->query("short")+"(Ed)";
	j = 10-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	} else str += "\n";

	if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/southwest")&&!(int)env->query_door("southwest", "status") & DOOR_CLOSED)
	|| (env->query("exits/south")&&!(int)env->query_door("south", "status") & DOOR_CLOSED)
	|| (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
{
	if( (env->query("exits/southwest")&&!(int)env->query_door("southwest", "status") & DOOR_CLOSED) )
	str += "                  ／"; else str += "                    ";

	if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/south")&&!(int)env->query_door("south", "status") & DOOR_CLOSED) )
	str += "        ┃        "; else str += "                  ";

	if( (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
	str += "＼\n"; else str += "\n";

	if( (env->query("exits/southwest")&&!(int)env->query_door("southwest", "status") & DOOR_CLOSED) )
	str += "                ／"; else str += "                  ";

	if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/south")&&!(int)env->query_door("south", "status") & DOOR_CLOSED) )
	str += "          ┃          "; else  str += "                      ";

	if( (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
	str += "＼\n"; else str += "\n";

	str += "\n";
}

       if( env->query("exits/southwest") && !(int)env->query_door("southwest", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/southwest"))) room = load_object(env->query("exits/southwest"));
	describe = room->query("short")+"(Sw)";
	str += sprintf("%"+(18+color_len(describe))+"s",describe);
	} else if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/south")&&!(int)env->query_door("south", "status") & DOOR_CLOSED)
	|| (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
	str += "                  ";

       if( env->query("exits/south") && !(int)env->query_door("south", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/south"))) room = load_object(env->query("exits/south"));
	describe = room->query("short")+"(S)";
	j = (24-(strlen(describe)-color_len(describe)))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"";
	for(i=0;i<j;i++) str += " ";
	} else if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/southeast")&&!(int)env->query_door("southeast", "status") & DOOR_CLOSED) )
	str += "                       ";

       if( env->query("exits/southeast") && !(int)env->query_door("southeast", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/southeast"))) room = load_object(env->query("exits/southeast"));
	describe = room->query("short")+"(Se)";
	str += describe+"\n";
	}
	else if( (env->query("exits/southup")&&!(int)env->query_door("southup", "status") & DOOR_CLOSED)
	|| (env->query("exits/southdown")&&!(int)env->query_door("southdown", "status") & DOOR_CLOSED)
	|| (env->query("exits/southwest")&&!(int)env->query_door("southwest", "status") & DOOR_CLOSED)
	|| (env->query("exits/south")&&!(int)env->query_door("south", "status") & DOOR_CLOSED) )
	str += "\n";

       if( env->query("exits/southup") && !(int)env->query_door("southup", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/southup"))) room = load_object(env->query("exits/southup"));
	describe = room->query("short")+"(Su)";
	j = 29-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	}

       if( env->query("exits/southdown") && !(int)env->query_door("southdown", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/southdown"))) room = load_object(env->query("exits/southdown"));
	describe = room->query("short")+"(Sd)";
	j = 29-(strlen(describe)-color_len(describe))/2;
	for(i=0;i<j;i++) str += " ";
	str += describe+"\n";
	}

// 下体部分完成，下面是特殊部分。

	str += "\n";

       if( env->query("exits/enter") && !(int)env->query_door("enter", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/enter"))) room = load_object(env->query("exits/enter"));
	describe = room->query("short")+"(Enter)";
	str += "里面："+describe+"\n";
	}
       if( env->query("exits/out") && !(int)env->query_door("out", "status") & DOOR_CLOSED ) {
       if( !room = find_object(env->query("exits/out"))) room = load_object(env->query("exits/out"));
	describe = room->query("short")+"(Out)";
	str += "外面："+describe+"\n";
	}

// 下面是最特殊部分。

	if( mapp(exits = env->query("exits")) ) {
		dirs = sort_array(keys(exits), 1);
		for(i=0; i<sizeof(dirs); i++)
	if( dirs[i] != "northup" && dirs[i] != "northdown" && dirs[i] != "northwest"
	&& dirs[i] != "north" && dirs[i] != "northeast" && dirs[i] != "westup"
	&& dirs[i] != "up" && dirs[i] != "eastup" && dirs[i] != "west" && dirs[i] != "east"
	&& dirs[i] != "westdown" && dirs[i] != "down" && dirs[i] != "eastdown"
	&& dirs[i] != "southwest" && dirs[i] != "south" && dirs[i] != "southeast"
	&& dirs[i] != "southup" && dirs[i] != "southdown" && dirs[i] != "enter"
	&& dirs[i] != "out" ) {
       if( !room = find_object(env->query("exits/"+dirs[i]))) room = load_object(env->query("exits/"+dirs[i]));
	describe = room->query("short")+"("+capitalize(dirs[i])+")";
	str += "出口："+describe+"\n";}
	}


	str += "━━━━━━━━━━━━━━━━━━━━━━━━━━ "HIW"HY2 "NOR"━━\n";
	write(str);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : place

帮助你了解四周的地理。
HELP
	);
	return 1;
}
