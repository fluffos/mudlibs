// siguoya.c
// Dec.11 1997 by Venus
inherit ROOM;
void quarter_pass();
void create()
{
        set("short", "思过崖");
        set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚禁
受罚之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来自来相传
是玉女发钗上的一颗珍珠，当年华山派的祖师以此危崖为惩罚弟子之所，
主要是此处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，不致为外
物所扰，心有旁鹜。
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));

        set("objects", ([
		"/d/jinyong/book8/huashan/npc/tao1" : 1,
		"/d/jinyong/book8/huashan/npc/tao2" : 1,
		"/d/jinyong/book8/huashan/npc/tao3" : 1,
		"/d/jinyong/book8/huashan/npc/tao4" : 1,
		"/d/jinyong/book8/huashan/npc/tao5" : 1,
		"/d/jinyong/book8/huashan/npc/tao6" : 1,
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        setup();
	quarter_pass();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/siguo", 1);
        return;
}
void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚禁受罚
之所。崖上光秃秃的寸草不生，更无一株树木。天色灰暗，你已看不清四周的
景物。
LONG
		);
		delete("exits/zuan");
	}
	else {
		set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚禁受罚
之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来自来相传是玉女发
钗上的一颗珍珠，当年华山派的祖师以此危崖为惩罚弟子之所，主要是便此一
处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，不致为外物所扰，心有
旁鹜。
LONG
		);
		set("exits/zuan", __DIR__"hole");
	}
	call_out("quarter_pass", 30);
}

int valid_leave(object me, string dir)
{
	if(objectp(present("taogen xian", environment(me))) && (dir =="enter" || dir=="zuan")&& ((int)me->query("jinyong/book8")==3))
	{
		return notify_fail("桃根仙伸手一拦：此山是我开，此洞是我管，打赢了我才能进去。\n");
	}
	
  	if (me->query("fengset") && dir=="zuan" && random(10) > 7)
	{
		me->move(__DIR__"luoyan");
		return notify_fail("你循着高速的捷径一下子进入了夹山壁。\n");
	}
	return ::valid_leave(me, dir);
}
