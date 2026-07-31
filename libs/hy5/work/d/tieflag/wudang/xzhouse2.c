 inherit ROOM;
void create()
{
        object con, item; 
        set("short", "农家");
        set("long", @LONG
房门虚掩著，屋内空无一人。屋内摆设非常简朴，只有几样生活
必需品，但正面墙上挂著的一柄铁剑和屋里的摆设极其不和。你不仅
开始猜想此屋主人的来历身份。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xzroad3",
        ]));
        set("objects", ([
                __DIR__"obj/wall": 1,
        ]));
        set("coor/x",90);
        set("coor/y",-60);
        set("coor/z",0);
        setup();
} 
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword2");
                item->move(con);
        }
}   
