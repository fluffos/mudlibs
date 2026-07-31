// Room: /d/city/winmo.c

#include <ansi.h>
inherit ROOM;

#define WU "/d/city/npc/wudapeng"
#define WANG "/d/city/npc/wangtan"
#define SHI "/d/city/npc/shisong"

void create()
{
        set("short", "得胜山");
        set("long", @LONG
得胜山在扬州城西北三十里的大仪乡，山只有七八丈高，不过是个小丘，
南宋绍兴年间，韩世忠曾在此处大破金兵，因此山名“得胜”。
LONG    );
        set("exits", ([
                "southeast" : __DIR__"wroad1",
                "west" : __DIR__"miao",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wudapeng" : 1,
                __DIR__"npc/wangtan" : 1,
	]));
        set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}

void init()
{
	object me = this_player();
	
	if (!me->query_temp("mao18/passed4")) return;
	
	remove_call_out("do_start");
	call_out("do_start", 2, me);
}

int do_start(object me)
{
	object here = this_object();
	object ob, ob1, ob2;
	
	if (!me) return 1;
	if (!(ob = present("mao shiba",here))) {
		me->delete_temp("mao18");
		return 1;
	}
	if (!(ob1 = present("wu dapeng",here))) {
		ob1 = new(WU);
		ob1->move(here);
	}
    if (!(ob2 = present("wang tan",here))) {
		ob1 = new(WANG);
		ob1->move(here);
	}
	tell_object(me,HIY"
    你们刚来到得胜山，却见一个秃顶汉子和一个白须老人已等待多时了，原来那两人便

是「摩天手」吴大鹏和「铁笔开山」王潭。\n"NOR);
    	call_out("do_happen",2, me, ob);
    	return 1;
}

int do_happen(object me, object ob)
{
	object ob1;
	
	ob1 = new(SHI);
	ob1->move(this_object());
	tell_object(me,CYN"
    茅十八刚上去和两人打了个寒暄，却听后面一个军官走了过来，大声说道：“

茅朋友，你在扬州城里做下你天大的案子，好汉一人做事一人当，乖乖的跟我们走罢！”

    吴大鹏道：“请教阁下尊姓大名？”那军官在腰间一条黑黝黝的软鞭上一拍，说道：

“在下'黑龙鞭'史松，奉了鳌少保将令，擒拿天地会反贼。”\n"NOR);
	call_out("do_fight",2, me, ob, ob1);
}

int do_fight(object me, object ob, object ob1)
{
	tell_object(me,HIG"
    茅十八拍了拍手中钢刀冲上前去，和史松打了起来。\n"NOR);
    	ob->fight_ob(ob1);
    	ob1->fight_ob(ob);
//    	call_out("do_end",20, me, ob, ob1);
    	return 1;
}
/*
void do_end(object me, object ob, object ob1)
{
	if (!me)
		return;
	if (!ob || !ob1)
		call_out("do_fail",1, me);
	if (!ob1->query_temp("be_signed"))
		call_out("do_fail",1, me);
	
*/	
