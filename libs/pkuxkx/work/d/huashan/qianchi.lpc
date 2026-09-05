// qianchi.c

inherit ROOM;

void create()
{
        set("short", "千尺幢");
        set("long", @LONG
前面有一斜如天垂石梯的山阶，这就是赫赫有名的千尺幢，千尺幢是
依一陡峭岩脊的裂缝开凿而成，斜度约七十度，高约二十米，仅容一人上
落。如果不是精气十足，还是不要冒险攀登的好。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"qingke",
  "southup" : __DIR__"baichi",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("room","room15");
        setup();
}

int valid_leave(object me, string dir)
{
    
	if (dir == "southup") 
	{
        if (me->query_temp("hsnewbiejob/xunshan")&&(int)me->query_skill("dodge", 1) > 15)
        {
            return 1;
        }
	        if  ((int)me->query_skill("dodge", 1) < 30 )
        	{
        	        me->add("jing", -10);
                	me->add("qi", -10);
                        if ( me->query("combat_exp") >= me->query_skill("dodge", 1) * me->query_skill("dodge", 1) * me->query_skill("dodge", 1) / 10 )
				me->improve_skill("dodge", me->query("int"));
        	}
	}
        return 1;
}
