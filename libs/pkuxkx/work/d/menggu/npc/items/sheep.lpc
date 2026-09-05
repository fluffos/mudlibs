#include <ansi.h>
#include <room.h>

inherit NPC;
void create()
{
    set_name(HIW"小羊羔" NOR,({ "xiao yang", "yang", "sheep" }) );
	set("race", "野兽");
	set("age", 1+random(2));
    set("long", "这是一只很可爱的小羊。你可以赶(gan)着它到小山坡，到了之后，输入(arrive)就可以了。\n");
    set("limbs", ({ "头部", "身体", "前蹄", "后蹄" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 10000);
	set("no_get","别猥琐了，连羊你也要？？？！！！\n");
	setup();
    call_out("check",5);
}

int check()
{
    object ob=this_object();
    object me;
    if (!query("owner"))
    {
        message_vision("$N越跑越远，渐渐没了踪迹。\n",ob);
        destruct(ob);
        return 1;
    }
    me=find_player(ob->query("owner"));
    if (!me||!me->query_temp("lpjob"))
    {
        message_vision("$N越跑越远，渐渐没了踪迹。\n",ob);
        destruct(ob);
        return 1;
    }
    remove_call_out("check");
    call_out("check",3,ob);
    return 1;
}

void init()
{
	add_action("do_driver", ({"gan", "qu"}));
	add_action("do_arrive", "arrive");
}

int do_driver(string arg)
{
	string dir, roomfile, newroomfile;
	object me, sheep, room, newroom, myb;
	string dirname;
	me = this_player();
	sheep = this_object();
	if (!(me->query_temp("lpjob/start")))
		return notify_fail("李萍又没让你帮忙牧羊，你要偷羊吗？\n");
	if(!present("muyang bian", me))
		return notify_fail("没有牧羊鞭，你要怎么去牧羊？\n");
	myb=present("muyang bian",me);
	if(!(myb->query("equipped")))
		return notify_fail("你要拿着牧羊鞭，才可以牧羊。\n");
	if ((sheep->query("owner"))!=(me->query("id")))
		return notify_fail("你从哪里偷来的羊？\n");
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你现在很累，要歇一会才能继续赶羊。\n");
	room = environment(sheep);
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
	if (!dir||member_array(dir,keys(room->query("exits")))==-1)
		return notify_fail("赶羊的命令是gan <方向>。\n");
	if(!room || !room->query("exits/"+dir))
		return notify_fail("你要往哪里赶羊？\n");
	newroomfile=room->query("exits/"+dir);
	if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);
	message_vision(HIW"$N赶着羊儿往"+newroom->query("short")+HIW"而去了。\n"NOR, me);
	move(newroom);
	tell_room(newroom, me->query("name")+HIW"赶着羊儿轻快地过来了。\n"NOR);
	me->move(newroom);
	me->start_busy(random(3) + 2);
    return 1;
}

int do_arrive(string arg)
{
	object me, sheep, place;
	me = this_player();
	sheep = this_object();
	if (!(me->query_temp("lpjob/start")))
		return notify_fail("没人请你帮忙放羊啊，你来干吗的？\n");
	if ((sheep->query("owner"))!=(me->query("id")))
		return notify_fail("你哪偷来的羊？\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	place = environment(me);
	if(("/d/menggu/hill") != file_name(place))
		return notify_fail("这里有草吗？没草怎么放牧？\n");
	else
		{
			message_vision("$N把小羊羔赶到了一片长满绿草的山坡上了，小羊羔跑到了山坡的另一边。\n",me);
			tell_object(me,"你放心的躺了下来，只要每隔一段时间观察(guancha)一下就可以了。\n");
			me->set_temp("lpjob/step2",1);
			destruct(sheep);
			return 1;
		}
}

