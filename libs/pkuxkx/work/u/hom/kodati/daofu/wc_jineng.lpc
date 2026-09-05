// wc_jineng 藏艺阁

inherit ROOM;

void init() {
    add_action("do_read", "read");
    add_action("do_fadai", "fadai");
}


void create() {
    set("short", "藏艺阁");
    set("long",
@TEXT    这是一间极为宽大的房间，不见烛火，却十分明亮。除屋子正中拜访着一部
石书，别无其他家具。四壁均为石质，似乎刻着什么东西。
TEXT);

    set("no_fight", 1);

    set("objects", ([
        "/d/xiakedao/obj/xkd_book" : 1,
    ]));

    set("exits", ([
        "west" : __DIR__"wuchang",
    ]));

    setup();
}

int do_read(string arg) {
    object me = this_player();
    string book;
    int times;

write(arg);
    if (arg && (sscanf(arg, "%s %d", book, times) < 1)) {
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
    }

    return 0;
}

int do_fadai() {
    object me = this_player();
    me->set("qi", me->query("max_qi"));
    me->set("jing", me->query("max_jing"));
    me->set("neili", me->query("max_neili"));
    me->set("jingli", me->query("max_jingli"));
    return 1;
}
