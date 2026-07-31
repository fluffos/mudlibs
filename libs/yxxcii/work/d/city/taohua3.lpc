// taohua3.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

string look_shibei();
void create()
{
	set("short", "桃花谷");
	set("long", @LONG
顺溪流而上，两边山势渐高，流水渐急，桃林也愈见密集，层层桃花
拥攒成一片晚霞，留心处，时时可见悬泉飞瀑，倒挂崖间。桃花溪水跳荡
起伏，青鳞赤鲤隐隐相戏。这里就是桃花谷了。谷口一个尺许高的小纂石
碑(shibei)斜侧路旁。
LONG );
	set("outdoors", "city");
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
	setup();

}

string look_shibei()
{
	return
	"※※※※※※※※※※※※※※※\n"
	"※※			  ※※\n"
	"※※	桃花村	※※\n"
	"※※			  ※※\n"
	"※※※※※※※※※※※※※※※\n";
}
