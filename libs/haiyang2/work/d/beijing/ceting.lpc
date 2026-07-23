inherit ROOM;

string* books = ({
        "/clone/book/yljing",
        "/clone/book/yljing1",
        "/clone/book/yljing2",
//      "/clone/book/yljian",
//      "/clone/book/ylbian",
        "/clone/book/book-bamboo",
//      "/clone/book/book-paper",
        "/clone/book/book-silk",
        "/clone/book/book-stone",
        "/clone/book/book-iron",
        "/clone/book/quanpu",
        "/clone/book/dujing_1",
});


void create()
{
	set("short", "侧厅");
	set("long", @LONG
这里是侧厅，靠墙是一排书架，摆满了各种拳谱、书籍。墙角有一
张木床。天地会总舵主陈近南常常在这里读书、休息。
LONG );
	set("exits", ([
		"west" : __DIR__"dating",
	]));
        set("sleep_room", 1);   
	set("objects", ([
            "quest/menpai/yunlong/shi" : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
