// 东山坳 /d/menpai/shennong/dong_shanao.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "山坳");
    set("long", @LONG
绕过小茅屋，小路又转了个弯，来到一个山坳。这里散布着许多乱石，显得
颇为荒凉。在西边山下隐隐能看见小屋的屋顶和山下的农田。一阵阵山风吹来，
你才发觉自己已经爬得很高了。
LONG
    );
    set("exits",    ([
        "north"     :   __DIR__"dong_shanyao",
        "westdown"  :   __DIR__"wuqian",
    ]) );
    set("outdoors", "wuliang");
    setup();
}
