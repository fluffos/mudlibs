// Room: /d/dali/hg3.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "海埂北");
	set("long", @LONG
这里被大理百姓称为“草海”，水平如镜，洲屿隐现，傍岸曲折，港汊纵
横，苹天苇地。堤上大树参云，垂柳拂波。这里眺望湖光山色，别有佳趣往南
行就到海埂了。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
		"south" : __DIR__"hg1",
	]));

	set("coor/x",-300);
  set("coor/y",-500);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/hg3",1);
      }
}
