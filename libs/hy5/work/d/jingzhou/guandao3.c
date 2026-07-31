// Room: /d/jingzhou/guandao3.c
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "青石道" );
        set("long", @LONG
接近荆州，路由黄土变成了青石铺路，两旁渐渐可以看见一些农舍，
农田肥沃，稻香四飘。古称荆州为军事要地，地理为其一，肥沃为其二
啊！往西望去，可见荆州的城楼了.
LONG
        );
        set("exits", ([
  "east" : __DIR__"guandao2",
  "west" : __DIR__"jzdongmen",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

