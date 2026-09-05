inherit ROOM;
void create()
{
   set("short","花圃");
   set("long",@LONG
你的眼前出现了一个美丽的花园，花园里种着一些花,花从中隐约可见
飘渺的倩影，那是宫中的姐妹们在玩耍.
LONG );
    set("exits",([
      "south" : __DIR__"zhengting",
      "north" : __DIR__"xiaolu",
       ]));
    set("outdoors", "lingjiu");
    set("objects",([
__DIR__"npc/dizi":random(3),    
__DIR__"npc/zhang" : 1,
    ]));
 //  set("no_clean_up", 0);
    setup(); 
}