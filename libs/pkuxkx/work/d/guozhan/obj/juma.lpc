//拒马
#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("拒马",({ "ju ma", "juma"}) );
        set_weight(5000000);
        set("long","这是一副拒马，放在路上可以有效延缓骑兵的移动，你可以试试推推(tui)它。\n");
        set("unit", "副");
        set("value", 1);
        set("no_get",1);
        set("material", "steel");
        set("guozhan",1);
        set("is_juma",1);
        setup();
}

void init()
{
    add_action("do_push","tui");
    add_action("do_push","push");
}

int consume(object me)
{
    int neili=100000/(int)me->query_str();
    me->add("neili",-neili);
    tell_object(me,"你消耗了"+chinese_number(neili)+"点内力才把拒马挪动到这里。\n");
    me->add_busy(2);
    return 1;
}

int do_push(string arg)
{
    string dir,dirname, roomfile, newroomfile;
	object me, ob, room, newroom;
	me = this_player();
	ob = this_object();
	
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。。\n");
	if ((int)me->query("neili")*(int)me->query_str()<400000)
        return notify_fail("你现在体力太弱，推不动拒马。\n");
    room = environment(ob);
	roomfile = file_name(room);
	switch(arg) 
	{
		case "e":	dir="east";		dirname="东面";		break;
		case "w":	dir="west";		dirname="西面";		break;
		case "n":	dir="north";		dirname="北面";		break;
		case "s":	dir="south";		dirname="南面";		break;
		case "ne":	dir="northeast";	dirname="东北";		break;
		case "nw":	dir="northwest";	dirname="西北";		break;
		case "se":	dir="southeast";	dirname="东南";		break;
		case "sw":	dir="southwest";	dirname="西南";		break;
		case "u":	dir="up";		dirname="上面";		break;
		case "up":	dir="up";		dirname="上面";		break;
		case "d":	dir="down";		dirname="下面";		break;
		case "down":	dir="down";		dirname="下面";		break;
		case "nu":	dir="northup";		dirname="北边";		break;
		case "eu":	dir="eastup";		dirname="东边";		break;
		case "su":	dir="southup";		dirname="南边";		break;
		case "wu":	dir="westup";		dirname="西边";		break;
		case "nd":	dir="northdown";	dirname="北边";		break;
		case "ed":	dir="eastdown";		dirname="东边";		break;
		case "sd":	dir="southdown";	dirname="南边";		break;
		case "wd":	dir="westdown";		dirname="西边";		break;
		case "enter":	dir="enter";		dirname="里面";		break;
		case "out":	dir="out";		dirname="外面";		break;
		default:	dir=arg;		dirname="一边";		break;
	}
	if(!room || !room->query("exits/"+dir))
		return notify_fail("你要往哪个方向推动拒马？\n");
	newroomfile=room->query("exits/"+dir);
	if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);
	message_vision("$N推着拒马往"+newroom->query("short")+"而去了。\n", me);
	ob->move(newroom);
	tell_room(newroom, me->query("name")+"推着拒马哼哧哼哧地过来了。\n"NOR);
	me->move(newroom);
    consume(me);
    return 1;
}