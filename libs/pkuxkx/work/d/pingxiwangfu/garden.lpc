inherit ROOM;
void create()
{
        set("short", "平西王府后花园");
        set("long", @LONG
平西王府之处在这里可略见一斑，四边花草甚多，但唯有牡丹最胜。那花不是寻
常玉楼春之类，乃“姚黄”“魏紫”有名异品，一本价值五千。那花正种在朱门对面，
周围以湖石拦之。其花大如丹盘，五色灿烂，光华夺目。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  
   "north" : __DIR__"corror3",
 "south" : __DIR__"corror2",

]));
    set("objects",([
    __DIR__"npc/huanong":1,
   ]));
         set("outdoors","pingxiwangfu");
		 set("no_newbie_task",1);
        setup();
        replace_program(ROOM);
}
