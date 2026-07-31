//Cracked by Roath
// Room: /d/xiyou/nanhai/guangchan
inherit ROOM;
int block_cmd(string); 

void create ()
{
  set ("short", "落迦岩");
  set ("long", @LONG

这是南海普陀山上一快比较平整的土地，普陀山门人弟子们经
常在这里切磋武艺，宣讲佛法，交流心得。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huian" : 1,
//    __DIR__"npc/zhangmen" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("valid_startroom", 1);
  set("no_fight", 1);   
  set("no_magic", 1);   
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaoyuan",
  "west" : __DIR__"road11",
  "east" : __DIR__"road1",
  "enter" : __DIR__"chaoyindong",
]));

  setup();
}

void init() 
{
  add_action("block_cmd", "", 1); 
}

int block_cmd(string args) 
{
string verb; 
verb = query_verb(); 
if (verb == "bian") return 1;
if (verb == "cast") return 1; 
return 0; 
}
//object zhangmen = 0;
/*
void init ()
{

  if (! zhangmen)
  {
// zhangmen = present("zhang men",this_object());

zhangmen = new ("/d/npc/zhangmen");

    zhangmen->create_identity(__DIR__"npc/guanyin",this_object());
  }
}
*/
