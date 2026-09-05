// Room: /d/baituo/xiaojing.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "花园小径");
	set("long", 
            "这里是花园中的一条小径，连接着牡丹园的入口和假山，路两边\n"
        "满是各种不同品种的红玫瑰，真是漂亮极了！说也奇怪不知道是为什\n"
        "么，这里一年四季都有牡丹在开放，看来花匠必有他的过人之处！\n"
         
	);
	set("no_clean_up", 0);
        set("exits",([
            "west" : __DIR__"huayuan",
            "east" : __DIR__"jiashan",
           ]));
        set("objects",([
            __DIR__"npc/gardener" : 1 ,
           ]));
	setup();
	replace_program(ROOM);
}
