// Room: workroom.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是风儿偷偷建的为了偷懒少走路的秘密通道，通向所有的公告板。

扬州客店  -A1 扬州武庙  -A2 扬州茶馆  -A3 北京客店  -A4 成都客店  -A5
苏州客店  -A6 杭州客店  -A7 福州客店  -A8 襄阳客店  -A9 一品堂大院-A0
少林大雄殿-B1 少林山门  -B2 武当三清殿-B3 峨眉华藏庵-B4 青城松风观-B5
嵩山峻极院-B6 泰山日观峰-B7 华山不为轩-B8 衡山祝融殿-B9 恒山白云庵-B0
大理王府  -C1 丐帮破庙  -C2 丐帮小屋  -C3 明教广场  -C4 日月神教  -C5
天地会    -C6 血刀门山洞-C7 侠客岛大厅-C8 归云庄    -C9 红花会    -C0 
全真重阳宫-D1 古墓正厅  -D2 桃花岛大厅-D3 白驼大厅  -D4 神龙岛大厅-D5
中条山小屋-D6 逍遥青草坪-D7 灵鹫峰大厅-D8 星宿海    -D9 雪山寺大殿-D0
天堂      -E1 地狱      -E2 巫师会客厅-E3 巫师休息室-E4 武道场    -E5 
LONG
	);
	set("exits", ([
		"out" : __DIR__"workroom",
		"a1"  : "/d/city/kedian",
		"a2"  : "/d/city/wumiao",
		"a3"  : "/d/city/chaguan",
		"a4"  : "/d/city2/kedian",
		"a5"  : "/d/city3/kedian",
		"a6"  : "/d/suzhou/kedian",
		"a7"  : "/d/hangzhou/kedian",
		"a8"  : "/d/fuzhou/rongcheng",
		"a9"  : "/d/xiangyang/kedian",
		"a0"  : "/d/lingzhou/yipindayuan",

		"b1"  : "/d/shaolin/dxbdian",
		"b2"  : "/d/shaolin/guangchang1",
		"b3"  : "/d/wudang/sanqingdian",
		"b4"  : "/d/emei/hcaguangchang",
		"b5"  : "/d/qingcheng/songfengguan",
		"b6"  : "/d/songshan/chanyuan",
		"b7"  : "/d/taishan/riguan",
		"b8"  : "/d/huashan/buwei3",
		"b9"  : "/d/henshan/zhurongdian",
		"b0"  : "/d/hengshan/baiyunan",

		"c1"  : "/d/dali/wangfugate",
		"c2"  : "/d/city/pomiao",
		"c3"  : "/d/city/gbxiaowu",
		"c4"  : "/d/mingjiao/square",
		"c5"  : "/d/heimuya/chengdedian",
		"c6"  : "/d/city2/dating",
		"c7"  : "/d/xuedao/shandong3",
		"c8"  : "/d/xiakedao/dating",
		"c9"  : "/d/guiyun/qianyuan",
		"c0"  : "/d/hangzhou/liuhed",

		"d1"  : "/d/quanzhen/datang1",
		"d2"  : "/d/gumu/zhengting",
		"d3"  : "/d/taohua/dating",
		"d4"  : "/d/baituo/dating",
		"d5"  : "/d/shenlong/dating",
		"d6"  : "/d/huashan/xiaowu",
		"d7"  : "/d/xiaoyao/qingcaop",
		"d8"  : "/d/lingjiu/dating",
		"d9"  : "/d/xingxiu/xxh2",
		"d0"  : "/d/xueshan/dadian",

		"e1"  : "/d/death/god2",
		"e2"  : "/d/death/gate",
		"e3"  : "/d/wizard/guest_room",
		"e4"  : "/d/wizard/wizard_room",
		"e5"  : "/d/city/wudao4",
	]));
	set("valid_startroom","1");
	setup();
	replace_program(ROOM);
}
