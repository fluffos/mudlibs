#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "小人物的工作室");
    set("long", "好地方。\n");

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc1" : 1,
  __DIR__"npc2" : 1,
  //__DIR__"tang2" : 1,
  __DIR__"long/long" : 1,
  //__DIR__"gboxt2" : 50,
  //"/adm/fubendoor" : 1,
  //"clone/misc/maze_doort" : 1,
  //"clone/box/gbox" : 50,
]));
//        set("objects", ([
//                "/clone/master/master"+random(24)+1 : 1,
//	]));

  set("exits", ([ /* sizeof() == 1 */

//"test" : "/p/migong/boss/vrm16/maze/entry",
"in" : "/u/hxsd/migong",
  "down" : "/u/hxsd/neishi",
 	
]));
//    set("objects",  ([
//    ]));
set("pingan",1);
  set("valid_startroom", 1);
  set("outdoors", "/u/lywin");

  setup();
}
void init()
{
        mixed *local;
        int  t;
string a="anpc"+random(17);
string b="anpc"+random(17);
string c="anpc"+random(17);
string d="anpc"+random(17);

        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
        add_action("do_look", "look");
                add_action("do_enter", "south");
}

/*
30-260        午夜
260-510       黎明
510-630       早晨
630-810       中午
810-990       傍晚
990-1170      下午
1170-1360     傍晚
1360-第二天30 夜晚
*/


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                set("exits/down", "/d/gaibang/inhole");
                message("vision",
			me->name() + "从洞里走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
int do_look()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];
      
        if( t > 30 && t < 260)
        {
                set("long", BLU"那繁星流转，日月迁移，黎明前最后的一丝黑暗。天明就要到来！小
人物沉睡于自已的床上，在美好的梦中找寻自己心中的天女。\n");
        }
        if( t > 260 && t < 510)
        {
                set("long", HIC"天光微明！花草带露！万物凄美！小人物的工作室里一片美好！那清晨
里清亮的鸟鸣送给小人物无限的希望。\n"NOR);
        }
        if( t > 510 && t < 630)
        {
                set("long", HIY"亮丽的上半天是一天中每好的开始， 勤劳的小人物早早的起来了，因为
他为了养活自己,马上要去上班了。上班去喽!!\n"NOR);
        }
        if( t < 810 && t > 630)
        {
                set("long", HIW"中午的到来让小人物不得不停下了手上的程序,肚子里咕咕乱叫,实在是
顶不住了,走!吃饭去,吃完饭后小大物便和几个朋友打起了乒乓球。\n"NOR);
        }
        if( t < 990 && t > 810)
        {
                set("long", HIG"转眼就到了要吃晚饭的时候，一天累劳的工作终于结束了,终于回到家的
小人物和家人围坐在一起边看动画片边吃晚饭,生活真是无限好。\n"NOR);
        }
        if( t < 1170 && t > 990)
        {
                set("long", HIR"由于小人物的文凭是在单位中最差的,所以小人物不得不坐一个多小时的
汽车,去市区读书,可是,成果却.......现在的上海真像一个大的拳击台,不
是你击倒我就是我击到你。唉!\n"NOR);
        }
        if( t < 1360 && t > 1170)
        {
                set("long", RED"天色已经很暗了，到这个时候，小人物终于到了交通大学,和朋友们做在
了一起,谈天说地.无说不为.看来这次英语和高数又要玩完了。\n"NOR);
        }
        if( t < 30 || t > 1360)
        {
                set("long", BLU"夜深人静了，小人物拖着快要倒下的身子回到了家,到了家已经不行了,往
床上一躺,在睡觉前躺在床上看武侠小说是小人物最好的休息。\n"NOR);
        }
}
