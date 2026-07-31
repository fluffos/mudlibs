//ROOM: /d/yanziwu/huanshi.c

inherit ROOM;

void create()
{
	set("short", "还施水阁");
	set("long",@LONG
阁中满是书架，架上摆着许多颇古旧的书籍，架上均贴有标签(sign)。
这就是慕容世家历经数代才收集积累而成的武学宝库。
LONG );
	set("exits", ([
	    "out": __DIR__"lanyue",
	]));
	set("objects", ([
	    "/clone/book/book-bamboo": random(2),
	    "/clone/book/book-iron": random(2),
	    "/clone/book/book-paper": random(2),
	    "/clone/book/book-silk": random(2),
	    "/clone/book/book-stone": random(2),
	]));
	set("item_desc",([
	    "sign" : "大部分密籍都被封存了。\n"
	]));
	setup();
}
