// Room: /d/gumu/dating.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "大厅");
        set("long", @LONG
        这时一间很大的石厅，石厅的正北方是一个木桌，
桌旁有两个椅子，坐着两个人。木桌的上方挂着一幅画，画上画
着一个绝代佳人，依稀可以看见她眼里的幽怨之色。左边墙上也
挂了一幅画，画的是一个中年男子，双目炯炯，威武神气。不知
什么原因，画上有许多唾液.

LONG
        );
        set("no_sleep_room", 1);
	  set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mudao10",
]));
	  set("objects",([
CLASS_D("gumu")+"/longer":1,CLASS_D("gumu")+"/yang":1,]));
        set("no_clean_up", 0);
        call_other("/clone/board/gumu_b", "???");

        setup();
        replace_program(ROOM);
}
 
