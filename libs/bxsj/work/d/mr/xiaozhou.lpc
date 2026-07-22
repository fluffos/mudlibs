// /u/beyond/mr/xiaozhou.c 
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "渡船");
	set("long", @LONG
你从听雨居的活动机关中掉到了一艘小舟上，船上的船夫对你说：“坐稳
了”，咱们这就到曼佗罗山庄去。
LONG
	);
	set("outdoors", "慕容");
        set("no_fight",1);
	setup();
}

void run(object ob)
{
	if (!ob)
		return;

	if (environment(ob) == this_object()){
		ob->move(__DIR__"xiaozhou1", 1);
		tell_object(ob, "\n船夫把船驶进了一片一望无际的荷花荡。一眼望去, 满湖荷叶, 菱叶, 芦苇, \n"
			"茭白, 都是一模一样, 兼之荷叶, 菱叶在水面漂浮, 随时一阵风来, 便即变化\n"
			"百端, 就算此刻记得清清楚楚, 霎时间局面便全然不同。\n\n");
	}
}

void init()
{
	object ob = this_player();
	call_out("run", 5, ob);
}
