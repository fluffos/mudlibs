// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIG"无色台"NOR);
       set("long", @LONG
这里是无色禅师的灵台内部，灵室十分空旷。正中有一张灵案(lingan)，
上书“洛钟东应”四个大字，乃是无色大师生前亲手所书。笔势遒劲，大舒
大展如同一套极高明的拳法。虽然置身暗室，你却觉的灵台一片空明，似有
光芒自心底发出。
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_study","study");
}
int do_study(string arg)
{
	object me;
	me=this_player();
	if (arg!="lingan") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"正在专心的学习灵案上的书法。\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("cuff",1)<30){
		write(HIR"你看着案上的书法，心中似有所悟，但毕竟拳法修为尚浅，什么也没领悟到。\n"NOR);
 	return 1;
	}
	if ((int)me->query_skill("cuff",1)>100){
		      write("你已尽数领悟透了案上书法的含义。\n");
	return 1;
	}
        if ((int)me->query_skill("cuff", 1) >= 30 
        && (int)me->query_skill("cuff", 1) <= 100&&arg=="lingan" ){
                 if ((int)me->query("jing")<30)
               {
                me->unconcious();     
                return 0;
                 }
  
                me->receive_damage("jing", 30);
                me->improve_skill("cuff", (me->query("int"))*3/2);
                write("你看着案上那笔走龙蛇般的大字，心中对基本拳法有所领悟。\n");
	return 1;
	}
}

