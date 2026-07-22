// Room: home.c

inherit ROOM;

void create()
{
        set("short", "琼音阁");
	set("long", @LONG
    这是雪儿和麦芽儿的小屋，虽然地方不大，可是非常整洁，显然女主人时常
打扫。墙边立着一个书架(book_shelf)，书架的一边斜立着一把六弦琴(guitar)。
春日的夜晚，常从窗口飘出优雅的琴音，伴着一缕甜美的女声，隐约是那首<<斯
镇的颂歌>>(Scarborough Fair)，轻柔地荡漾在房屋四周的草坪之上。
LONG
	);

	set("no_die", 1);
	set("valid_startroom",1);

	set("exits", ([
              "west":__DIR__"melodies_room",
              "east":__DIR__"sunrise",
		"ts" : "/d/taishan/fengchan",
		"sl" : "/d/shaolin/dxbdian",
                "dm" : "/d/shaolin/damodong",
                "dx" : "/d/city2/daxiao",
		"td" : "/d/city2/dating",
		"bt" : "/d/baituo/dating",
		"wg" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
                "xs" : "/d/xueshan/dadian",
                "lj" : "/d/lingjiu/dating",
                "xy" : "/d/xiaoyao/qingcaop",
                "ss" : "/d/shenlong/dating",
		"th" : "/d/taohua/dating",
		"hg" : "/d/city2/tian_anm",
		"gb" : "/d/city/gbxiaowu",
		"wz" : "/d/wizard/wizard_room",
		"ct" : "/d/city/guangchang",
		"qz" : "/d/quanzhou/zhongxin",
		"hs" : "/d/huashan/buwei1",
	]));
	setup();
	replace_program(ROOM);
}

