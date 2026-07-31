//Room: hcazhengdian.c 华藏庵正殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵正殿");
      set("long",@LONG
这里是峨嵋山金顶华藏庵的正殿。华藏庵规模宏大，殿内青砖铺地，中间
有普贤菩萨像，两旁列有万佛。正前方放一红木供桌，陈列香烛，以供叩拜。
自此左右各有一间侧殿，是接待香客的地方。南面是通往一个大广场，只有峨
嵋弟子才能过去。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xin" : 1,
           __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"huacangan",
          "east"   : __DIR__"hcaeast", 
          "west"   : __DIR__"hcawest", 
          "south"  : __DIR__"hcaguangchang", 
      ]));
//      set("no_clean_up", 0);
      setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "峨嵋派")) && (dir == "south")
     &&  objectp(present("jingxin shitai", environment(me))))
      return notify_fail("静心师太说道:非峨嵋弟子，到此止步吧。\n");
    else  return 1;
}
