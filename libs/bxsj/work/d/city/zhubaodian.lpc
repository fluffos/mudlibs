// Room: /d/city/zhubaodian.c

#define KICK_TO	__DIR__"xidajie1"

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "珠宝店");
	set("long", @LONG
这是一家装饰豪华的珠宝店。厅内摆满了各种金银玉器，将四周映得金碧
辉煌。几个富商模样的人正在低头仔细地挑拣着，老板在不厌其烦地推销着。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xidajie1",
	]));

        set("objects", ([
		__DIR__"npc/zhu" : 1,
        ]));
        set("no_clean_up", 0);

	set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
	quarter_pass();
}

void kick_all()
{
	object *ob;
    int i;

	tell_room(this_object(), "老板看了看天色，轻声说道：“该回家啦。”\n", ({}));
	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++) {
		if (userp(ob[i])) {
			if (!living(ob[i])) message_vision("老板把$N扔出了珠宝店。\n", ob[i]);
			else message_vision("听了老板的话，$N只好走出了珠宝店。\n", ob[i]);
			ob[i]->move(KICK_TO);
			if (!living(ob[i])) tell_room(KICK_TO, ob[i]->name() + "被扔出了珠宝店。\n", ({ob[i]}));
			else tell_room(KICK_TO, ob[i]->name() + "从珠宝店中依依不舍地走了出来。\n", ({ob[i]}));
		}
	}
}

void quarter_pass()
{
	mixed *local;
// object *ob;
// int i,paytime;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) kick_all();
	call_out("quarter_pass", 30);
}

