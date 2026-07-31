
inherit ROOM;
void create()
{
	set("short", "渡船");
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
if(!ob) return;
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"duchuan1", 1);
	write("\n船夫把船驶进了一片一望无际的荷花荡。一眼望去, 满湖荷叶, 菱叶, 芦苇, \n"
"茭白, 都是一模一样, 兼之荷叶, 菱叶在水面漂浮, 随时一阵风来, 便即变\n"
"化百端, 就算此刻记得清清楚楚, 霎时间局面便全然不同。\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 3, ob);
}



