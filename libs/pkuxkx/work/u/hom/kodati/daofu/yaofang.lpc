// yaofang 药房
#include <ansi.h>

inherit ROOM;

string* yaos = ({
    "/d/shaolin/obj/puti-zi",
    "/d/shaolin/obj/dahuan-dan",
    "/d/shaolin/obj/xiaohuan-dan",
    "/d/xingxiu/obj/sanxiaosan",
    "/d/xingxiu/obj/goushi",
    "/d/xingxiu/obj/xxqingxi",
//    "/d/xingxiu/obj/xxqingxin-san",
    "/d/xingxiu/obj/xuelian",
    "/d/xiakedao/obj/hlgrass",
});

void init() {
    add_action("do_search", "search");
    add_action("do_tou", "tou");
}

void create() {
    set("short", "药房");
    set("long",
@TEXT    走进屋内，除了扑鼻而来的药香，还可看到一张桌子(desk)和几个倚墙而立
的木柜。木柜大多是药屉形制，只有木桌后的一面架子(mujia)上整整齐齐地码
着许多青瓷药瓶。
TEXT);

    set("item_desc", ([
        "desk" : "桌上放着药杵、药臼、铜称等物，此外还有几本医书(book)。\n",
        "mujia" : "仔细看去，每个药瓶上都有标签，写着“清心散”、“菩提子”、“还灵水草”等字样。\n",
    ]));

    set("exits", ([
        "east" : __DIR__"woshi",
    ]));

    set("book_count",1);
    set("yao_count",18);
    setup();
}

int do_search(string arg) {
    object me = this_player();
    object book;

    if (!arg || arg != "book") {
        return notify_fail("你要找什么？\n");
    }
    if (!query("book_count")) {
        return notify_fail("书已经被人拿走了。\n");
    }
    if ( me->query_temp("daofu/yaofang_book")) {
        return notify_fail("一本就够看了吧？\n");
    }
    book = new(__DIR__"obj/book-lingshu");
    book->move(me);
    book = new(__DIR__"obj/book-suwen");
    book->move(me);
    set("book_count",0);
    message_vision("$N从桌上找到两本医书。\n",me);
    me->set_temp("daofu/yaofang_book",1);
    return 1;
}

int do_tou(string arg) {
    object me = this_player();
    object yao;

    if (!arg || arg != "yao") {
        write("你要干嘛？\n");
        return 0;
    }
    if (!query("yao_count")) {
        return notify_fail("你翻到一张字条：“宵小横行，人心不古。”汗。。\n");
    }
    if (me->query_temp("daofu/yaofang_yao") >= 3) {
        return notify_fail("好了吧，你要拿多少？\n");
    }
    me->add_temp("daofu/yaofang_yao", 1);
    add("yao_count", -1);
    yao = new(yaos[random(sizeof(yaos))]);
    yao->move(me);
    message_vision("$N找到一" + yao->query("unit") + yao->query("name") + "！\n", me);
    return 1;
}
