// Room: /d/dali/chexiang.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月26日，北京时间：19时13分58秒。

inherit ROOM;

void create()
{
	set("short", "车厢内");
	set("long", @LONG
你正躺在马车车厢内，车厢里的陈设极为豪华，波斯地毯，
上好的座椅，最妙的是有瓶五粮液在那里放着，你忍不住想喝
他几口。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/wuliangye" : 1,
]));
	set("no_clean_up", 0);

	setup();
}

int do_check()
{
    object *obj;
    int i;
    obj=all_inventory(this_object());
    if (!sizeof(obj))   return 1;
    for (i=0;i<sizeof(obj);i++)
        if (userp(obj[i]))  return 0;
    return 1;
}
