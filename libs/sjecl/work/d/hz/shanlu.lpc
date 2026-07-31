 // /d/hz/shanlu.c 山路

inherit ROOM;
void create()
{
        set("short","山路");
        set("long", @LONG
你走在山路上，不远处就能看到黄龙洞，你走进古色古香的山门，沿着
古树修竹夹峙的石级上行，来到第二道门，这里又一垛随坡而筑的黄色粉墙，
墙上整齐地排列着“九龙窗”，门两侧又有鹤鹿雕窗，东侧竹木园中松竹交
翠，显示了园林风格。望东面是雷峰塔，北面就是宝塔山。
LONG
        );
	set("objects",([
		NPC_D("tiao-fu") : 2,
	]));
	set("outdoors", "杭州");
        set("exits", ([
		"eastup" : __DIR__"leifengta",
//		"north" :  __DIR__"shanlu1",
		"southup" : __DIR__"baoshuta",
		"northup" : __DIR__"huanglong",
	]));
	setup();
}
