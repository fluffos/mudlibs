// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIB"无相牌"NOR);
       set("long", @LONG
通过无相牌进入无相禅师生前修真的密室，室内颇为灰暗，密不透光。
密室中摆着一个大铜缸，缸中盛满净水，波光粼粼。为室内添加一点光亮
据说无相大师当年受挫于昆仑高人之后，又寻张君宝不遇，愤懑归寺，既
隐居于此练掌(strike)，将掌法练到登峰造极之地步。其一生武学秘奥尽
藏于此斗室之中。
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_strike","strike");
}
int do_strike(string arg)
{
	object me;
	me=this_player();
	if (arg!="shui") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"对准铜缸中的水面发掌击出。\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("strike",1)<30){
		write(HIR"你功力太浅，铜缸中连水花也没溅出一点。\n"NOR);
 	return 1;
	}
	if ((int)me->query_skill("strike",1)>100){
		      write(HIR"你掌力沉雄，铜缸内净水为你掌力所激，已回应之力。\n"NOR);
	return 1;
	}
        if ((int)me->query_skill("strike", 1) >= 30 
        && (int)me->query_skill("strike", 1) <= 100&&arg=="shui" ){
                 if ((int)me->query("jing")<30)
               {
                me->unconcious();     
                return 0;
                 }
  
                me->receive_damage("jing", 30);
                me->improve_skill("strike", (me->query("int"))*3/2);
                write(HIB"你对着水面遥遥发掌，缸内激起片片水花。你觉的掌力颇有精进。\n"NOR);
	return 1;
	}
}

