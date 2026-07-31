// Room: /qingcheng/qiandian.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "松风观");
	set("long", @LONG
这里是松风观前殿。松风观是青城派总所，青城派威镇川中，以其
人才辈出之故。当今掌门人余沧海道长，虽其貌不扬，身形矮小，却是
青城一代宗师。殿中左右分列四大天王，手中分执剑、琵琶、伞、蛇四
样法器(faqi)，代表了风调雨顺的凡民宿愿。
LONG );
	set("item_desc", ([
		"faqi" : "
以剑锋之锋的谐音喻“风”
以琵琶需常调弦通“调”
以伞为雨具推及“雨”意
以蛇之灵动顺畅寓“顺”之韵

",
	]));
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("exits", ([
		"southdown" : __DIR__"shangqing",
		"north"     : __DIR__"zhongmen",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/yu" : 1,
	"/quest/menpai/newmp/shi4" : 1,
	"/d/qingcheng/npc/dizi" : 4,
	"/d/biwu/champion_qc" : 1,	
	]));
	set("coor/x", -8080);
	set("coor/y", -870);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}