 inherit ROOM;
void create()
{
        set("short", "饿虎岗山路"); 
        set("long", @LONG
一条坑坑洼洼的石子山路，两旁怪石嶙峋。拂面的山风中时不时传来阵阵狼嚎
声。路边隐隐可以见到磷磷白骨。透过山雾，隐约间可看见西南方向不远处有一座
断塔。
LONG);
        set("type","road");
        set("exits",([
                "northdown":__DIR__"ehugang",
                "southup":__DIR__"shanlu4",
                "southwest":__DIR__"undertower",
        ]) ); 
        set("outdoors", "bawang");
    set("coor/x",200);
    set("coor/y",-210);
    set("coor/z",60); 
        setup();
        replace_program(ROOM);
}
