// mafang.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "马房");
	set("long", @LONG
你现在正站在大理城西边的一家马房里，别看岭南马体型不是很魁武，可
跑起来很有长力。来自中原的旅人和要去中原的人们总在这里挑选一匹好马，
靠近门口的地方方有一块木雕成的招牌(sign)。
LONG
	);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
           "east" : __DIR__"qsjie2",
        ]));

        set("objects", ([
            __DIR__"npc/mafu" : 1,
        ]));

	set("coor/x",-320);
  set("coor/y",-450);
   set("coor/z",-20);
   set("coor/x",-320);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/mafang",1);
      }
}

string look_sign(object me)
{
	if( wizardp(me) )
	return "招牌写著：专卖母马。\n";
	else
	return "招牌写著：专卖良马。\n";
}
