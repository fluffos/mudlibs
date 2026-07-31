// Room: /d/jingzhou/nanshilu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "碎石路" );
        set("long", @LONG
这是一条由碎石铺成的路，虽然有些颠簸，却很宽阔，再往南去
就是长江了。
LONG
        );
        set("exits", ([
  
  "north" :__DIR__"jznanmen",
  "south" :__DIR__"nanshilu1",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

