// Room: /d/gumu/xiaoting.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "小厅");
        set("long", @LONG
   这是一间小石厅，布置得很整齐。靠北有一个小石椅，
椅上坐着位少女，正在讲她的江湖经历。她的身旁是几个古墓
弟子，正在津津有味地听着。你要不要听听?

LONG
        );
        set("no_sleep_room", 1);
	set("no_fight", "1");
        set("no_steal", "1");       
  set("exits", ([ 
    "south"  : __DIR__"mudao5",
]));

	  set("objects",([__DIR__"npc/luwushuang":1,]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
