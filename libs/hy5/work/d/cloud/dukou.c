
// Room: /u/cloud/dukou.c

inherit ROOM;

void create()
{
        set("coor",({2100,3700,0}));
	set("short", "江北渡口");
        set("long",
"这是个虽说不大却过客甚多的渡口。往北去是通往绮云镇里的青石道，南面就是无风亦起浪\n"
"的泓水了。向南望去，隐约可见对岸日照山的轮廓，山顶有袅袅炊烟升起。\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",

]));



        set("outdoors", "cloud");

        setup();
}
