// Room: /d/hainan/road4
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
陡峭的山路,有许多地方是从岩石中凿了洞,从树林中弯曲蜿蜒而出. 
两边是苍茫的黑松林.黑咕窿冬的,什么都看不清. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 2,
]));
  set("outdoors", "/d/hainan");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"road2",
  "east" : __DIR__"pubu",
]));

  setup();
}

int valid_leave(object me,string dir)
{
        string fam;
        object npc;

        fam=(string)me->query("family/family_name");
	npc=present("nv dizi",environment(me));
	if( fam && fam!="白云庵" && objectp(npc) &&
		dir=="east")
	return notify_fail(npc->query("name")+"说道：非本派弟子禁止上崖。\n");
        return ::valid_leave(me,dir);
}

