 // seaside.c
inherit ROOM;
void create()
{
        set("short", "回廊");
        set("long", @LONG
一路朱红栏杆，院子遍植花树，却已凋零，花寒依稀梦，蝉语诉秋心。这儿只
有花香，只有虫声，莫说歌声无影，连酒气都没有，和鹦鹉阁里歌舞升平的气氛大
相径庭。抬头望去，空中一排人字形的大雁飞过，雁声嘹亮，凄凉。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"corridor2",
                "west": __DIR__"garden",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        object me,man;
        me=this_player();
        if( userp(me) && me->query("parrot/助三爷")==2 && !me->query("parrot/三爷刺客") ) {
                if (man=present("middle age man",this_object())) return;
                man=new(__DIR__"npc/assassin");
                if (man) {
                        man->move(this_object());
                        message_vision("$N叹了一口气，道：“你一定要找死，我们也没有办法。”\n",man);
                        man->kill_ob(me);
                        me->kill_ob(man);
                }       
                
        }
}             
