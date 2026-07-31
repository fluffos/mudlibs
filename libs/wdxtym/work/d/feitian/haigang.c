// Room: /u/diabio/feitian/feitian/haigang.c
#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create()
{
  set ("short", "海港");
  set ("long", @LONG
这里是京都唯一通往外地的海港,不过眼见之处是一片废墟.
这是幕府的部队为了能安全撤出而放的火.不过那边似乎有船
可以走，船上的人正在大声吆喝~~~要去东土的快点上船啊.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object me, ob,room;
	int level;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 上哪里去？\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/feitian/dahai"))
    room=load_object("/d/feitian/dahai");
    me = this_player () ;
    message_vision("船老大一见有人上船，忙叫了一声：开船喽！\n", me);
    message_vision("船夫升起帆，船就向东土行去。\n", me);
    me->move(room) ;
    tell_object(me, BLU "你在海上航行了很久很久.......\n" NOR ) ;
if (random(10) > 7)
{
		message_vision(HIB"突然海面上出现了一般海盗船，一个海盗爬上了船.......\n"NOR, me);
		message_vision(HIB"海盗大喝一声：所有的人通通的死啦，死啦！！！\n"NOR, me);

		ob = new(__DIR__"npc/wokou");
              ob->set("combat_exp",me->query("combat_exp") * 8 / 10);
		ob->set("max_qi",me->query("max_qi")* 3 / 4);
		ob->set("eff_qi",me->query("max_qi")* 3 / 4);
		ob->set("qi",me->query("max_qi")* 3 / 4);
		ob->set("max_jing",me->query("max_jing")* 3 / 4);
		ob->set("eff_jing",me->query("max_jing")* 3 / 4);
		ob->set("jing",me->query("max_jing")* 3 / 4);

	level = (int)me->query_skill("force",1) * 5 / 6;
  if (level <=50) level=50;
  if (!level) level=50;
if (level <=50) level=50;
  if (!level) level=50;
		ob->set_skill("feitian-yujianliu", level); 
		ob->set_skill("force", level);
		ob->set_skill("unarmed", level);
		ob->set_skill("xuanhualiu-quanfa",level);
		ob->set_skill("dodge", level); 
                ob->set_skill("blade", level); 
		ob->set_skill("aikido", level); 
		ob->set_skill("wuxing-dun", level); 
		ob->set_skill("shayi-xinfa", level);
		ob->set_skill("parry", level); 
		ob->set_skill("literate", level); 
		ob->set_skill("feitian-yujianliu", level); 
                        ob->map_skill("parry", "aikido");
                        ob->map_skill("unarmed", "aikido");
                        ob->map_skill("dodge", "wuxing-dun");
                        ob->map_skill("force", "shayi-xinfa");
                        ob->map_skill("blade", "feitian-yujianliu");

		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->start_busy(1);
call_out("rfeitian", 60 , me );
}
else    call_out("rfeitian", 20 , me );
    return 1 ;
}

void rfeitian( object me )
{
    if (!me || me->is_ghost()) return;
  tell_object(me , "船航行了这么久终于抵达了一个到达了东土泉洲。\n" ) ;
  me->move ("/d/quanzhou/haigang.c") ;
}


int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;
if (level <=30) level=30;
	return level;
}
