// Room: /u/lin/d/guanzhong/tample.c

inherit ROOM;

void create()
{
        set("short", "华岳庙");
        set("long", @LONG
西岳华山，自古闻名。山下的老百姓
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"xiaolu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

