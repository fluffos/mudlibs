// Room: /hangzhou/paozhang.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";

void create()
{
	set("short", "兴隆炮仗店");
	set("long", @LONG
这是一个炮仗店，卖着各种烟花炮仗，每到逢年过节这里的生意特别兴旺。
店老板王兴隆据说也和红花会有些瓜葛。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaorenfang",
                "west" : __DIR__"paozhang2",
		
	]));
	
  set("objects", ([
"/d/hangzhou/npc/wangxinglong" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{

    if (me->query_temp("hhh_wt1") == 5)
    	  return ::valid_leave(me, dir); 
    	  	
    if ((me->query_temp("hhh_wt1") != 5)&& dir == "west"
    && objectp(present("wang xinglong", environment(me)))
    && living(present("wang xinglong", environment(me))))
        return notify_fail("王兴隆说道：“后面是我家，没事别瞎转悠。”\n");
    return ::valid_leave(me, dir);
}

