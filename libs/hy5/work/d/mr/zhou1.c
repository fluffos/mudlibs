// /u/beyond/mr/zhou1.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长竹
篙，正在船尾吃力地撑着船。
LONG
	);
        set("no_fight",1);

	setup();
}
void run(object ob)
{
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"zhou2", 1);
	write("\n小舟驶进一片一望无际的荷花荡。一眼望去, 满湖荷叶, 菱叶, 芦苇, 茭白,\n"
"都是一模一样, 兼之荷叶, 菱叶在水面漂浮, 随时一阵风来, 便即变化百端，\n"
"就算此刻记得清清楚楚, 霎时间局面便全然不同。小船在荷花溏中缓缓而行，\n"
"转过一排垂柳, 远远看见水边小居的一角屋檐。两只飞燕从头顶掠过。\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
