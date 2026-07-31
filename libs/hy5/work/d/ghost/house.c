 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "小白屋");
        set("long", @LONG
在外面看这屋子已经小得可怜了，走进去之后，更象是走进间鸽
子笼。可是鸽子虽小，五脏俱全，这屋子也一样，别人家里有什么，
这屋子里几乎也一样不缺，甚至还有个金漆马桶。
LONG
        );
        set("exits", ([
                "south" : __DIR__"ghost",
        ]));
        set("objects", ([
                __DIR__"npc/yeling" : 1,
                __DIR__"obj/toilet" : 1,
        ]));
        set("coor/x",-1170);
        set("coor/y",-90);
        set("coor/z",-20);
        setup();
} 
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("toilet", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 2) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"npc/butterfly");
                item->move(con);
                item = new(__DIR__"npc/yanzi");
                item->move(con);
        }
}      
