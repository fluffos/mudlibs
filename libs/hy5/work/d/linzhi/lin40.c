// Room: /d/linzhi/lin40.c

inherit ROOM;

void create()
{
	set("short", "老虎嘴瀑布");
	set("long", @LONG
你来到这里，只见凌空而泻的瀑流，像银河倒悬，坠至半空，
忽被峭石拦腰斩断，霎时雪浪飞溅，宛如千万串断线的珍珠，纷
纷扬扬坠入不见底的深渊。而河水却像猛兽在咆哮，发出震耳欲
聋的吼声，仿佛整个峡谷都在颤抖。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lin39",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
