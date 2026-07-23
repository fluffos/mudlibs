
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","九江茶馆");
  set ("long", @LONG
这里是一家茶馆。由于九江来往的行人很多，所以茶馆的生意很好。
有几个客人在那里一边喝茶，一边评论着当今的大事。旁边还有几个便衣
的官兵在旁边窃听。茶馆老板识相地远远地躲到了一边。
LONG);

  set("exits", ([ 

  "east":__DIR__"beidajie1",
        ]));
   set("objects",([
	   __DIR__"npc/cha":1,
	   __DIR__"npc/chake":2,
	   __DIR__"npc/mitan":1,
	   ]));
   set("resource/water",1); 
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   object ob;
   ob=previous_object();
   if((userp(ob)&&!query("fight_flag")&&
      random(10)+random(10)>=14)){
   	set("fight_flag",1);
   	call_out("auto_fight",0);}
}

void auto_fight()
{
  object ob1,ob2;
  object *ob;
  int i;
  ob=all_inventory(this_object());
  for(i=0;i<sizeof(ob);i++){
    if(ob[i]->query("kill_npc"))
      ob1=ob[i];
    if(ob[i]->query("target"))
      ob2=ob[i];}
  if(!ob1||!ob2) return;

  if(environment(ob1)!=environment(ob2)||
     environment(ob1)!=this_object()||
     environment(ob2)!=this_object())
  return;
  message_vision(HIW"$N朝$n冷笑道：你谈论的事情未免过多了！！\n"NOR,ob1,ob2);
  ob1->kill_ob(ob2);
  return;
}
