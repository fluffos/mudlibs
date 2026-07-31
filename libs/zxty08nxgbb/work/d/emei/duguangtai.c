// Room: /d/emei/duguangtai.c 峨嵋派 睹光台
// create by host dec,20 1997
inherit ROOM;


void create()
{
	set("short", "睹光台");
	set("long", @LONG
这是一个宽大的广场，从这里可以看到峨嵋的全貌，每日当朝霞初升，
如果站在睹光台上，在你身后将幻出一轮光环，景色瑰丽多彩。在广场两
边有两排架子，上面插满了兵器。在广场上有一些峨嵋弟子正在那里或练
习武功、或相互讨教。
LONG
	);

          set("outdoors", "emei");
	set("exits", ([
               "northdown" : __DIR__"jinding",
               "east":__DIR__"huazangan",
	]));
        set("objects",([
                 CLASS_D("emei") + "/jingxu": 1,
          "/d/shaolin/npc/mu-ren" : 2,
	]));
	setup();

}

