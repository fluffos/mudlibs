// /u/chen/murong/zhou-sx-1.c
//  by chen

inherit ROOM;
void create()
{
	set("short", "小舟");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。船尾放着一根竹篙。
LONG
	);
        set("no_fight",1);


	setup();
}
void run(object ob)
{
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"zhou-sx-2", 1);
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
