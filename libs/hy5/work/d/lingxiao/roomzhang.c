// Room: roomzhang.c

inherit ROOM;
void create()
{
        set("short","居室");
        set("long",@LONG 
走进这里，出现在你眼前的是大大小小的药罐。在这里住的
是凌霄城的六代弟子张万年，他为人厚道，所以白自在放心地把
管理凌霄城一些稀世药物的任务交给了他。不过据说他跟王万仞
向来交好，经常把一些珍贵的药酒给那家伙喝。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                __DIR__"npc/zhang" : 1,
                __DIR__"obj/icesword" : 3,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

