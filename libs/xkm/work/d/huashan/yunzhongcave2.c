// 2002-8-27

inherit ROOM;


void create()
{
	object ob;
        set("short", "山洞");
        set("long", @LONG
这个山洞里伸手不见五指，只有出口处透进一丝光线。
LONG
        );
        set("exits", ([
            "out" : __DIR__"yunzhongcave",
]));
	set("cost", 1);
        setup();
	set("no_clean_up", 1);
        //replace_program(ROOM);
        ob=new("/clone/armor/jinshe-beixin");
        if(ob)
        ob->move(__DIR__"yunzhongcave2");
}
