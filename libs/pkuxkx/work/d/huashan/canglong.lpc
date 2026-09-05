// canglong.c

inherit ROOM;

void create()
{
        set("short", "苍龙岭");
	set("long", @LONG
华山五峰中最惊险的是北峰，北峰之上最陡峭的则是苍龙岭。此岭高
约百米，宽仅一米，而登山之路则在其山脊之上，两侧脊坡光滑挺拔，其
下悬崖深邃，云涛隐伏。岭侧有一石碑(shibei)。
    从这里往北是下山的路，往南是上其它四峰的路，西面是华山极险处
之一，叫做“舍身崖”。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"husun",
  "southdown" : __DIR__"zhenyue",
  "westup" : __DIR__"sheshen",
  "north" : "/d/changan/shanlu3",
]));
        set("item_desc", ([
		"shibei" :
"石碑刻着几个大字：「韩退之投书处」，据说当年韩愈爬上此岭之后，再\n"
"也不敢下来，自以为要死在山上，就在山上写信投下来，和家人诀别。后\n"
"来还是华阴县的县官派人上山拿绳子把他捆着吊下来的。\n"
])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("room","room9");
        setup();
        
}
 

/*
int valid_leave(object me, string dir)
{
        mixed *local;
        object *ob;
        int i;

        if( dir == "westup" ) {
                local = localtime(time());
                if( local[LT_HOUR] != 19)
                        return notify_fail("四周云雾飞绕，你根本看不清路！也许要换个时间来才行！\n");
                else {
                        ob = all_inventory(environment(me));
                        for(i=0; i<sizeof(ob); i++){
                                if( ob[i]->query("rider") == me )
                                me->move("/d/jinshe/ziqitai");
                        tell_object(me, "正值正午时分，阳光猛烈，借着阳光，你摸索着穿过了迷雾！\n");
                        }
                        return 1;
                }
        }

        return ::valid_leave(me, dir);
}

*/

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (!userp(me)&&!me->query_temp("rider"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}