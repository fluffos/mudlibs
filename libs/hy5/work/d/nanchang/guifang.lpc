
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","闺房门口");
  set ("long", @LONG
这里是李财主女二的闺房的门口，这里放着几盆鲜花。最近李财主
的女儿就要出嫁了，她正在里面好好的打扮。
LONG);

  set("exits", ([ 

  "north":__DIR__"tingyuan",
  "enter":__DIR__"room",
     ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("defence_girl")&&dir=="enter")
		return notify_fail("你还是在门外保护李小姐吧！\n");
	if(me->query("gender")=="男性"&&dir=="enter")
		return notify_fail("男人还是不要进去了！\n");
	return ::valid_leave(me,dir);
}
		
void init()
{
	object *ob,where;int i;
	where=find_object(__DIR__"guifang");
	ob=all_inventory(where);
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("defence_girl")&&!ob[i]->query_temp("defence_flag"))
		{	ob[i]->set_temp("defence_flag",1);
		call_out("bing_come",30+random(10),ob[i]);}
	}
	return;
}

void bing_come(object me)
{
	object killer;
	if(!objectp(me)||!me->query_temp("defence_girl"))
	{ remove_call_out("bing_come");return;}
	killer=new(__DIR__"npc/guanbing");
	killer->set("combat_exp",me->query("combat_exp"));
	killer->kill_ob(me);
	killer->set_name("官兵",({"bing"}));
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("title");
	killer->delete("shili");
	killer->move(environment(me));
	tell_object(environment(me),"一个官兵走了过来。\n");
	message_vision("$N刚要进门，被$n拦住了！\n",killer,me);
	message_vision("$N朝$n叫道：我是奉王命行事，你是活够了！\n",killer,me);
	killer->kill_ob(me);
    remove_call_out("bing_come");return;
}
