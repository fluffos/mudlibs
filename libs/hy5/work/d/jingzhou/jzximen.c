// Room: /d/jingzhou/jzximen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "荆州西门" );
        set("long", @LONG
你来到荆州的西门，荆州历来都是军事要地，因此城墙坚实无比，城
楼高高耸立，出了西门，就踏上了艰险的蜀道，一直向天俯之国而去，路
上多有险阻，如果你要去的话，务必多加小心。入了城门，进入荆州，你
就等于到了中原了。
LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
 ]));

        set("exits", ([
  
 "east": __DIR__"xidajie2",
 "west": __DIR__"shudao1",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

