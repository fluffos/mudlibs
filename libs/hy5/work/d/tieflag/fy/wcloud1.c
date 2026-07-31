 inherit ROOM;
void create()
{
        set("short", "广场西");
        set("long", @LONG
风云广场在东，长乐坊在西，这里是风云城中风骚文人丛聚之地。据说天下赫
赫有名的小李探花就是在这里中的秀才。南边的考场每年都举行一次选拔考试，前
三名送入京都再试。北面则是探花诗台，是风骚文人们留下他们得意之作的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/song": 1,
        __DIR__"npc/xiwei": 4,
                        ]) );  
        set("outdoors", "fengyun");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob,room;
        int i;
        mapping condition;
        string *type;
        if( userp(me) && dir == "north")
        {
                
        condition = me->query_all_condition();
        if( mapp(condition) ) {
                type=keys(condition);
                for (i=0;i<sizeof(type);i++) {
                        if (type[i]!="drunk" && type[i]!="buffed")
                           return notify_fail("探花诗台不是你的坟场。\n");
                } 
        }        
        if(me->query("eff_sen")<me->query("max_sen")*95/100
                ||me->query("eff_kee")<me->query("max_kee")*95/100
                ||me->query("eff_gin")<me->query("max_gin")*95/100 )
                return notify_fail("探花诗台不是你的坟场。\n");
                
        if(objectp(ob = present("qinwei",this_object())) && random (3))
                return notify_fail(ob->name()+"向你喝道：＂皇公子所到之处，闲杂人等不可入内！\n");       
        }       
        return 1;
} 
