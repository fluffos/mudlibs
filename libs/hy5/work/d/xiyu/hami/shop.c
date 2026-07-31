// shop.c   羊肉馆
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "羊肉馆");
    set( "long", @LONG
一家哈密当地人开的小馆子，这里的桌子是长条形的，可以四个人对座谈话
饮酒。老板娘是一位三十开外的妇女。这里地处偏僻，但是因为小镇上就这么一
家小馆子，远来西域的人们路过这里都是在这里打尖休息，一洗身上的风尘。可
以说，在这里让远离故土的人们有了一点点慰籍。
LONG );
    set( "item_desc", ([
    "south" : "那儿是里间，远客休息之所在。\n",
]) );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shoproom",
    "east" : __DIR__"street",
]) );
    set( "objects", ([
    __DIR__"npc/laoban" : 1,
]) );
    setup();
}

int valid_leave(object me, string dir)
{
    if( dir == "south" )
      if( !me->query_temp("hami/sleep") )
        return notify_fail("你没有给钱，怎么能去里间休息呢？\n");
    return :: valid_leave(me,dir);
}
