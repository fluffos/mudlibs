//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include "study_subject.h"
string look_gaoshi();

void create()
{
        set("short", "国子学堂");
        set("long", @LONG
这是国子学里面博士传授知识的地方，最近几天的课程表可以看
课堂旁边墙上的告示(gaoshi)。
LONG);
        set("exits", ([
           "northwest" : __DIR__"guozixue",
        ]));
        
        set("item_desc", ([
		       "gaoshi" : (:look_gaoshi:),
	      ]));
        
        set("locate_level",7);          //长安城活动区域级别
        set("subject_level",3);         //国子监授课点级别
        set("no_fight", 1);
        set("no_perform", 1);
        set("no_clean_up", 1);
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        choice_subject();
        listen_subject(subjects[0]);   
}

void init()
{
	add_action("do_listen","listen");
	add_action("do_none","exert");
}

string look_gaoshi()
{
	string msg;
	
	msg=HIC"本学堂内博士近期教授课程如下表所列：\n"NOR;
	msg+=show_subject();
	msg+=HIC"如果有对上述课程感兴趣的可以坐下来听讲(listen)，每节课程讲授\n"+
	     "15分钟，中间休息1分钟，本学堂最多容纳10人听讲。\n"NOR;
	return msg;
}

int do_none()
{
  write("国子监附近的金吾卫过来阻止了一场争斗。\n");
  return 1;
}

int valid_leave(object me,string dir)
{
	me->delete_temp("changan/listen");
	me->delete_temp("changan/listens");
  return ::valid_leave(me, dir);
}