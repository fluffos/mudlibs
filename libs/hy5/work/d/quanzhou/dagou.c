// Room: /d/quanzhou/dagou.c
// Date: May 7, 96   Jay
#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create()
{
	set("short", "打狗港");
	set("long", @LONG
打狗港位于台湾南部，港域口小腹大，外有岛链环抱，
内具曲折峡湾，诚全台第一良港。
    城外海港，有商船(chuan)前往东瀛。
LONG );
	set("exits", ([
                "east" : "/d/taiwan/dagougang",
                "north" : __DIR__"chiqian",
	]));
	set("item_desc", ([
                "chuan" : "一条商船，可以用(shangchuan)去东瀛。\n",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 4,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object me, ob,room,obj;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 上哪里去？\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/feitian/dahai"))
    room=load_object("/d/feitian/dahai");
    me = this_player () ;
if (me->is_busy())
       {
         tell_object(this_player() , "你正忙着呢!\n" ) ;
         return 1 ;
       }
if (me->is_fighting())
       {
         tell_object(this_player() , "你正打着呢!\n" ) ;
         return 1 ;
       }
    message_vision("船老大一见有人上船，忙叫了一声：开船喽！\n", me);
    message_vision("船夫升起帆，船就向东瀛行去。\n", me);
		obj=present(me->query("id")+" "+"wulin renwu", environment(me));
        if (obj) obj->move (room);
        
    me->move(room) ;
    tell_object(me, BLU "你在海上航行了很久很久.......\n" NOR ) ;
if (random(10) > 7)
{
		message_vision(HIB"突然海面上出现了一般海盗船，一个海盗爬上了船.......\n"NOR, me);
		message_vision(HIB"海盗大喝一声：所有的人通通的死啦，死啦！！！\n"NOR, me);

		ob = new("/d/feitian/npc/wokou");
              ob->set("combat_exp",me->query("combat_exp") * 8 / 10);
		ob->set("max_qi",me->query("max_qi")* 3 / 4);
		ob->set("eff_qi",me->query("max_qi")* 3 / 4);
		ob->set("qi",me->query("max_qi")* 3 / 4);
		ob->set("max_jing",me->query("max_jing")* 3 / 4);
		ob->set("eff_jing",me->query("max_jing")* 3 / 4);
		ob->set("jing",me->query("max_jing")* 3 / 4);

		ob->set_skill("force", consider_lv(ob, 8));
		ob->set_skill("unarmed", consider_lv(ob, 8));
		ob->set_skill("xuanhualiu-quanfa",consider_lv(ob, 8));
		ob->set_skill("dodge", consider_lv(ob, 8)); 
                ob->set_skill("blade", consider_lv(ob, 8)); 
		ob->set_skill("aikido", consider_lv(ob, 8)); 
		ob->set_skill("wuxing-dun", consider_lv(ob, 8)); 
		ob->set_skill("shayi-xinfa", consider_lv(ob, 8));
		ob->set_skill("parry", consider_lv(ob, 8)); 
		ob->set_skill("literate", consider_lv(ob, 8)); 
		ob->set_skill("feitian-yujianliu", consider_lv(ob, 8)); 
                        ob->map_skill("parry", "aikido");
                        ob->map_skill("unarmed", "aikido");
                        ob->map_skill("dodge", "wuxing-dun");
                        ob->map_skill("force", "shayi-xinfa");
                        ob->map_skill("blade", "feitian-yujianliu");
		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->start_busy(1);
call_out("rfeitian", 50 , me,obj );
}
else    call_out("rfeitian", 20 , me,obj );
    return 1 ;
}

void rfeitian( object me,object obj )
{
    if (!me || me->is_ghost()) return;
  tell_object(me , "船航行了这么久终于抵达了一个到达了东瀛的一个港口。\n" ) ;
  me->move ("/d/japan/haigang.c") ;
if (obj) obj->move("/d/japan/haigang");   
}


int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}
