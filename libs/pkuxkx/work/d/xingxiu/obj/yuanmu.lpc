#include <ansi.h>.c
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( BLU "圆木" NOR, ({ "yuan mu","wood" }) );
    	set_weight(6000);
 	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根星宿后山出产的圆木，是制作兵器的好材料。\n");
                set("value", 0);
                set("material", "wood");
                set("no_get",1);
                set("ymhp", 6+random(6));
             }
     		init_staff(5);
        	setup();
            call_out("dest",360);
}

void init()
{
	add_action("do_tui", ({ "tui" }));
    add_action("do_xiao", ({ "xiao"}));
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
        return 1;
    }
}

int do_tui(string arg)
{
	string dir, roomfile, newroomfile;
	object me, ym, room, newroom;
	string dirname;
	me = this_player();
	ym = this_object();
	if (!(me->query_temp("xxnewbiejob/bpz1")))
		return notify_fail("你偷木头干吗？\n");
	if ((ym->query("owner"))!=(me->query("id")))
		return notify_fail("别人的圆木就不要拿了吧？\n");
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你刚推过一段路，要歇一会才能继续推圆木。\n");
	room = environment(ym);
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
		return notify_fail("你要往哪里推圆木？\n");
	newroomfile=room->query("exits/"+dir);
	if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);
	message_vision(HIW"$N推着圆木往"+newroom->query("short")+HIW"而去了。\n"NOR, me);
	ym->move(newroom);
    tell_room(newroom, me->query("name")+HIW"哼哧哼哧地推着圆木地过来了。\n"NOR);
    me->move(newroom);
	me->start_busy(random(3) + 2);
	
	return 1;
}

int do_xiao()
{
	object me = this_player();
	object sjd=present("suijin dao",me);
    object room=load_object("/d/xingxiu/mishi2");
    object zhang;
    if (environment()!=room)
    {
        return 0;
    }
    if (!(me->query_temp("xxnewbiejob/bpz1")))
		return notify_fail("我踏月色而来又没让你帮助制作冰魄杖，你想干吗？\n");
   
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呐！\n");
        }
    
	if(!present("suijin dao", me))
		{
			return notify_fail("没有碎金刀，你根本无法削动圆木。\n");
		}
    if (this_object()->query("owner")!=me->query("id"))
    {
        return notify_fail("这段圆木又不是你的，你想干嘛？\n");
    }
	else
		{
			if(sjd->query("equipped"))
				{
					message_vision("$N小心翼翼地削去圆木的枝叶，渐渐有了兵器的形状。\n", me);
                    if (this_object()->query("ymhp")<=0)
                    {
                        me->add_busy(1+random(2));
                        me->delete_temp("xxnewbiejob/bpz1");
                        me->set_temp("xxnewbiejob/bpz2",1);
                        message_vision("$N仔细看着手里已成型的木杖，非常得意。\n", me);
                        zhang=new(__DIR__"zhang");
                        zhang->set("owner",me->query("id"));
                        zhang->move(me);
                        tell_object(me,"碎金刀竟然不翼而飞了。\n");
                        destruct(sjd);
                        destruct(this_object());
                        return 1;
                    }
                    else
                    {
                        me->add_busy(1+random(2));
                        this_object()->add("ymhp",-1);
                        return 1;
                    }
				}
			else
				{		
					tell_object(me,"你有碎金刀而不用吗？\n");
                    return 1;
		        }
		}
}