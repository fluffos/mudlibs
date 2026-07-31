 inherit ROOM;
 
void create()
{
        set("short", "空地");
        set("long",@LONG
这是一片空地,四周都是乱石,杂草丛生。北边是一条山道。
LONG);
        set("exits", ([
        "northup"   : __DIR__"renjiandao1",
        "east" : __DIR__"anbian",
    ]) );
        set("objects", ([
            __DIR__"npc/dizi": 1+random(2),
        ]) );
        set("outdoors", "bat");
        set("coor/x",3290);
        set("coor/y",0);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
