// place.c
// Created by snowman@SJ 16/02/2000
// Modified by snowman@SJ 30/10/2000
// Modified by snowman@SJ 05/02/2001

#include <ansi.h>
#include <room.h>
inherit F_CLEAN_UP;

#define LINE  		"\n━━━━━━━━━━━━━━━━━━━━━━━━━━"
#define NO_NORTH 	221..<1
#define NO_SOUTH 	0..442
#define NO_NORTH_SOUTH 	221..442

string dir = "
                      (     nu     )
      (     nw     )  (     nr     )  (     ne     )
                      (     nd     )            
                \\          !!          ##
                  \\        !!        ##
(     wu     )      \\(     up     )##      (     eu     )
(     we     ) ______ (    room    ) ------ (     ea     )
(     wd     )      ++(     do     )..      (     ed     )
                  ++        ??        ..
                ++          ??          ..
               	      (     su     )
      (     sw     )  (     so     )  (     se     ) 
	       	      (     sd     )  \n";

string *dirs = ({ 
	"northwest", "northeast", "north", "northup", "northdown", "enter",
	"westup", "up", "eastup", "west", "east", "westdown", "down", "eastdown",
	"southwest", "southeast", "south", "southup", "southdown", "out",
});

int main(object me, string arg)
{
        string my_room, *other, str = "", def = "";
	int i, j, nw,n,ne,w,e,sw,s,se;
        object room;
        mapping exits;
        
        if( me->is_busy() || me->is_fighting())
        	return notify_fail("你现在正忙着呢。\n");
        	
        if(!objectp(room = environment(me)))
        	return notify_fail("你目前所在奇特，无法显示地图，请通知巫师。\n");

        if( !mapp(exits = room->query("exits")) ) 
        	return notify_fail("这里没有任何明显的出路。\n");

 	my_room = HIR+room->query("short")+NOR;
 	
        str += dir;
        for(i=0; i<sizeof(dirs); i++){
        	if( !exits[dirs[i]] ) j = 0;
        	else if( !objectp(room = find_object(exits[dirs[i]])) ){
        		if( objectp(room = load_object(exits[dirs[i]])) ) 
        			j = 1;
        	}
        	else j = 1;
                switch(dirs[i]){
                	case "northwest": nw = (j)?1:0; str = replace_string( str, "(     nw     )", (j)?sprintf("%|14s", room->query("short")+"(Nw)"):"              "); break;
                	case "northeast": ne = (j)?1:0; str = replace_string( str, "(     ne     )", (j)?sprintf("%|14s", room->query("short")+"(Ne)"):"              "); break;
                	case "north":     n = (j)?1:0;  str = replace_string( str, "(     nr     )", (j)?sprintf("%|14s", room->query("short")+"(N)"):"              "); break;
                	case "northup":	  if(!n) n = (j)?1:0;  str = replace_string( str, "(     nu     )", (j)?sprintf("%|14s", room->query("short")+"(Nu)"):"              "); break;
                	case "northdown": if(!n) n = (j)?1:0;  str = replace_string( str, "(     nd     )", (j)?sprintf("%|14s", room->query("short")+"(Nd)"):"              "); break;
                	case "southwest": sw = (j)?1:0; str = replace_string( str, "(     sw     )", (j)?sprintf("%|14s", room->query("short")+"(Sw)"):"              "); break;
                	case "southeast": se = (j)?1:0; str = replace_string( str, "(     se     )", (j)?sprintf("%|14s", room->query("short")+"(Se)"):"              "); break;
                	case "south":     s = (j)?1:0;  str = replace_string( str, "(     so     )", (j)?sprintf("%|14s", room->query("short")+"(S)"):"              "); break;
                	case "southup":	  if(!s) s = (j)?1:0;  str = replace_string( str, "(     su     )", (j)?sprintf("%|14s", room->query("short")+"(Su)"):"              "); break;
                	case "southdown": if(!s) s = (j)?1:0;  str = replace_string( str, "(     sd     )", (j)?sprintf("%|14s", room->query("short")+"(Sd)"):"              "); break;
                	case "west": 	  w = (j)?1:0;  str = replace_string( str, "(     we     )", (j)?sprintf("%14s", room->query("short")+"(W)"):"              "); break;
                	case "westup":	  if(!w) w = (j)?1:0;  str = replace_string( str, "(     wu     )", (j)?sprintf("%14s", room->query("short")+"(Wu)"):"              "); break;
                	case "westdown":  if(!w) w = (j)?1:0;  str = replace_string( str, "(     wd     )", (j)?sprintf("%14s", room->query("short")+"(Wd)"):"              "); break;
                	case "east":      e = (j)?1:0;  str = replace_string( str, "(     ea     )", (j)?sprintf("%-14s", room->query("short")+"(E)"):"              "); break;
                	case "eastup":	  if(!e) e = (j)?1:0;  str = replace_string( str, "(     eu     )", (j)?sprintf("%-14s", room->query("short")+"(Eu)"):"              "); break;
                	case "eastdown":  if(!e) e = (j)?1:0;  str = replace_string( str, "(     ed     )", (j)?sprintf("%-14s", room->query("short")+"(Ed)"):"              "); break;
                	case "up":        str = replace_string( str, "(     up     )", (j)?sprintf("%|14s", room->query("short")+"(U)"):"              "); break;
                	case "down":      str = replace_string( str, "(     do     )", (j)?sprintf("%|14s", room->query("short")+"(D)"):"              "); break;
                	case "enter":     (j)?def += "\n里面："+room->query("short")+"(Enter)":""; break;
                	case "out":       (j)?def += "\n外面："+room->query("short")+"(Out)":""; break;
                }
	}

	other = keys(exits);
	for(i=0; i<sizeof(other); i++){
		if( member_array(other[i], dirs) != -1) continue;
		if( !objectp(room = find_object(exits[other[i]])) ){
			if( !objectp(room = load_object(exits[other[i]])) )
				continue;
		}
		def += "\n"+other[i]+"："+room->query("short");
	}
		
// For test	
/*
	write("ALL -> "+ strlen(str)+"\n");
	write("NORTH -> " + strsrch(str, "\\        !!        ##") + " + " + strlen("\\        !!        ##") +"\n");
	write("SOUTH -> " + strsrch(str, "++        ??        ..") + " + " + strlen("++        ??        ..") +"\n");
*/	
   	str = replace_string( str, "(    room    )", sprintf("%|14s",my_room));
   	str = replace_string( str, "\\", (nw)?"＼":"  ");
        str = replace_string( str, "##", (ne)?"／":"  ");
        str = replace_string( str, "!!", (n)?"┃":"  ");
       	str = replace_string( str, "..", (se)?"＼":"  ");
        str = replace_string( str, "++", (sw)?"／":"  ");
        str = replace_string( str, "??", (s)?"┃":"  ");
        str = replace_string( str, "______", (w)?"━━━":"  ");
        str = replace_string( str, "------", (e)?"━━━":"  ");
        
   	if( !nw && !ne && !n ){
   		if( !sw && !se && !s )
   			str = str[NO_NORTH_SOUTH];
   		else	str = str[NO_NORTH];
   	}
        else if( !sw && !se && !s )
   			str = str[NO_SOUTH];
   	str += def;
        write(HIC"\n这里是"+my_room+HIC"，共有"+chinese_number(sizeof(keys(exits))) + 
        "个出口，分别通往："NOR+LINE+"━━━━" + str + LINE + HIW" SJ "NOR"━━\n");
        
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
