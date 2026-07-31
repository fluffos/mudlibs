// Room: /d/sandboy/zizhuan
inherit ROOM;

void create ()
{
  set ("short", "紫竹庵");
  set ("long", @LONG
竹林中的一座小尼庵，通体漆成淡青色，与四周的环境融为一体，庵
中隐隐传出兵器的相互撞击声。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laonigu.c" : 1,
]));
set("outdoors","/d/jiangnan");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhulin4",
  "enter" : __DIR__"inzizhuan",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
 ob=present("dubi shenni",this_object());
 if (objectp(ob)&&dir=="enter")  {
       if (ob->query("banghui")!=me->query("banghui"))  {
   message_vision("$N双手一拦,对$n道：这位施主，请留步.\n",ob,me);
     return notify_fail("");
                  }  
        }
return ::valid_leave(me,dir);
}
  
