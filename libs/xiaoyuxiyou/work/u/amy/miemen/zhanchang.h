inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  int x, y;
  int north, south, east, west;

  y = (int)(POS / 37);
  x = POS % 37;

  north = (y+1)*37 + x;
  south = (y-1)*37 + x;
  west = POS - 1;
  east = POS + 1;

  set ("short", "门派战场");
  set ("long", @LONG

周围杀气腾腾，烟雾弥漫，尸骨累累，古来多少英雄
在这儿成名，多少将士在这儿流芳。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhanchang"+north,
  "south" : __DIR__"zhanchang"+south,
  "east"  : __DIR__"zhanchang"+east,
  "west"  : __DIR__"zhanchang"+west,
]));

  if( y == 0 ) delete("exits/south");
  if( y == 26 ) delete("exits/north");
  if( x == 0 ) delete("exits/west");
  if( x == 36 ) delete("exits/east");

  set("killer",3+random(2));
  set("outdoors","zhanchang");
  setup();
}
void init()
{
	add_action("block_cmd", "", 1);
	add_action("do_tiaozhan", "tiaozhan");
}
int block_cmd(string args)
{
	string verb;
	verb = query_verb();

    	if (verb == "bian") return 1;
    	if (verb == "xiudao") return 1;
    	if (verb == "ji") return 1;
    	return 0;
}
int do_tiaozhan()
{
	object room ,me ,newob ,ob;
	int i ,max_level ,nkf;
	mapping skill;
	string* key;
	string dir;
	int menpai;

	me=this_player();
	ob=this_object();

	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你正忙着打架呢。\n");
	if( query("killer") < 3 )
		return notify_fail("这附近没什么敌人。\n");
	if( time() - (int)me->query_temp("tiaozhan_time") < 10 )
		return notify_fail("这附近没什么敌人。\n");
    if(!( room = find_object("/d/miemen/job/entrance")) )
            room = load_object("/d/miemen/job/entrance");
	if( room->query("miemen/killer") < 1 )
		return notify_fail("敌人已经被全部歼灭了。\n");
	if( room->query("miemen/miemen") == 1 )
		return notify_fail("敌人好象已经失踪了。\n");


	if (me->query("family/family_name") == room->query("miemen/family11"))
	{
		message_vision("$N仔细在附近搜寻"+room->query("miemen/family21")+"门人的行踪。\n", me);
        switch(room->query("miemen/family21"))
        {
	        case "阎罗地府"		: menpai = 1; break;
	        case "盘丝洞"		: menpai = 2; break;
	        case "东海龙宫"		: menpai = 3; break;
	        case "火云洞"		: menpai = 4; break;
	        case "大雪山"		: menpai = 5; break;
	        case "陷空山无底洞"	: menpai = 6; break;
			default : return 0;
		}
		dir = "/d/miemen/npc2/";
		if (random(10) == 1)
    	   	dir += "master";
		else
    	   	dir += "killer";

		newob = new(dir+menpai);
		newob->move(ob);

		message_vision(HIR"一个"+room->query("miemen/family21")+"门徒冲了出来对你叫道：纳命来吧！\n"NOR, me);
    	me->set_temp("tiaozhan_time",time());
    	ob->add("killer",-1);
    	room->add("miemen/killer",-1);
    	room->add("miemen/killed2", 1);
  		return 1;
	}
	if (me->query("family/family_name") == room->query("miemen/family21"))
	{
		message_vision("$N仔细在附近搜寻"+room->query("miemen/family11")+"门人的行踪。\n", me);
         switch(room->query("miemen/family11"))
        {
 	        case "南海普陀山"	: menpai = 1; break;
	        case "月宫"			: menpai = 2; break;
	        case "五庄观"		: menpai = 3; break;
	        case "蜀山派"		: menpai = 4; break;
	        case "方寸山三星洞"	: menpai = 5; break;
	        case "将军府"		: menpai = 6; break;
			default : return 0;
		}
		dir = "/d/miemen/npc1/";
		if (random(10) == 1)
    	   	dir += "master";
		else
    	   	dir += "killer";

		newob = new(dir+menpai);
		newob->move(ob);

		message_vision(HIR"一个"+room->query("miemen/family11")+"门徒冲了出来对你叫道：纳命来吧！\n"NOR, me);
        me->set_temp("tiaozhan_time",time());
        ob->add("killer",-1);
        room->add("miemen/killer",-1);
    	room->add("miemen/killed1", 1);
  		return 1;
	}
  	return 1;
}	