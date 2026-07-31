 inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
继续向前，唯有双手过顶，以便缩小肩头的尺寸，两足撑在高低不平
的山壁之上，一路推进，在那狭窄的洞穴之中，一寸一寸的向前挨去。所幸
暗道至此便不再变窄。
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"tunnel3",
                "down" : __DIR__"tunnel1",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object who,string dir)
{
        if(userp(who) && random(5))        {
                who->move(this_object());
                return notify_fail("");
        }
        return 1;
}   
