//ROOM neishi.c
inherit ROOM;
void create()
{
        set("short", "小舍内室");
        set("long", @LONG
这里是小舍内室。收拾得精细异常。你一进去，就发现床沿
坐着一个打扮妖艳的人。那人也诧异地抬头，你发现他居然是个
男人，手里执着一枚绣花针！
LONG    );
        set("exits", ([
             "west" : "/d/heimuya/xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
             __DIR__"npc/renwoxing": 1,
             __DIR__"npc/xiang": 1,
        ]));
        setup();
	replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("fighting", 1, who);  
}

void fighting(object who)
{
	object where = environment(who);
	object dongfang = present("dongfang bubai",where);
	object ren = present("ren woxing",where);
	object xiang = present("xiang wentian",where);
	if(dongfang && ren && xiang) 
	{
		dongfang->fight_ob(ren);
		xiang->fight_ob(dongfang);
		ren->fight_ob(dongfang);
		dongfang->fight_ob(xiang);
	}
}
