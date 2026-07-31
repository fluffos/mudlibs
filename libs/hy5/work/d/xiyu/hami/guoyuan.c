// guoyuan.c   果园
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "果园");
    set( "long", @LONG
一片果园，空气在灼热的阳光下颤抖闪光，而这里的植物确长得还可以。一
眼看过去，最有名的哈密瓜，葡萄…………等等，有不少水果，在架上的，在树
上的，都是那么的诱人。果园里好象还有一个守园人。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"shiban03",
]) );
    set( "outdoors", "西域" );
    set( "objects", ([
    __DIR__"npc/mmaiti" : 1,
]) );
    setup();
}

