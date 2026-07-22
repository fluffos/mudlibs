inherit ROOM;
void create()
{
        set("short", "小舟");
        set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长竹
篙，正在船尾吃力地撑着船。
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"zhou3", 1);
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
