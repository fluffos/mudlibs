// Room: menghuying.c

inherit ROOM;

void create()
{
	set("short", "猛虎营");
	set("long", @LONG
这里驻扎的是吐蕃国皇家的亲兵卫队，负责皇城内外的防务。营内中间有一
大快平整的教练场，一个威风凛凛的将官正大声吆喝着训练一小队士兵。营门右
首的墙上贴着张微微泛黄的告示(gaoshi)。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao1",
	]));

        set("item_desc",([
           "gaoshi" : 
		"
		 由于口粮不足，即日起暂停征兵。已报名者速来应征。

                 明日午间处决奸细两名。
                 城内严防奸细活动，举报者有重赏，知情不报者同罪！\n",

           ]));
        set("outdoors", "雪山");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 6,]));

	set("coor/x",-230);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}
