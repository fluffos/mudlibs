// Room: /d/baituo/jiashan.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "假山");
	set("long", 
              "这是一座颇有南方园林特色的假山，堆砌假山用的石料都是上等\n"
          "的太湖石，从那么远运到这里，不知主人是真爱石呢还是真有钱！\n"
          "    透过假山石的孔洞，可以看到绕过这座假山，东北方是一池清澈\n"
          "的湖水，波光粼粼，使得到了这里的人感到心境平和！\n"   
	);
	set("exits", ([ /* sizeof() == 1 */
           "west"      : __DIR__"xiaojing", 
           "northeast" : __DIR__"xiaohu",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
