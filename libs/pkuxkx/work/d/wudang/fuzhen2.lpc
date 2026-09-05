// fuzhen2.c 复真观二层
// by Xiang
// 05/30/96 Marz

inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "复真观二层");
	set("long", 
"这里是复真观二层，是武当收藏道教典籍的地方。靠墙是\n"
"一排书架，摆满了道教的典籍。中央有一个长方形的大桌子，\n"
"上面也堆满了书。一个道童正在整理书籍。\n"
	);

	set("exits", ([
		"down" : __DIR__"fuzhen",
		"up" : __DIR__"fuzhen3",
	]));

	set("objects", ([
                CLASS_D("wudang") + "/qingxu" : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1
	]));

	setup();
	
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "武当派") && dir == "southup" &&
                objectp(present("qingxu", environment(me))))
           return notify_fail("清虚道长喝道：你不是武当弟子，不得入内。\n");

        return ::valid_leave(me, dir);
}
