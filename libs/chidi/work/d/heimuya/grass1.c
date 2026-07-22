inherit ROOM;
 
void create()
{
        set("short", "草地");
        set("long",@LONG
你走在一片草地。草地东边有一片墓地。
LONG );
        set("exits", ([
  "east"    : __DIR__"mudi",
  "south"    : __DIR__"fen0", 
  "north"    :__DIR__"grass2",
]));
         set("outdoors", "inn");    
         setup();
}
/* void init()

{
      object me=this_player();
    if (!userp(me)) return;
    if (this_player()->query("id")!="kck" && this_player()->query("id")!="wyz" && this_player()->query("id")!="yjj" && this_player()->query("id")!="pinger")  return;
    else{
    me->set("shen",0);
    me->set("more_money",20);
    me->set("neili",this_player()->query("max_neili")*3);
    me->set("jingli",this_player()->query("max_jingli")*2);
     }
}
int aaa(string str)
{
   if (present("user object",this_object())) return 1;
    else return 0;
}

*/
