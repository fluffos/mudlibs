// Room: /d/dali/xueshan.c
// bbb 1997/06/10 
//cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "轿子雪山");
	set("long", @LONG
这里位于禄劝县境内，有峨嵋山的雄伟、黄山的秀丽华山的险峻，自然景
观十分独特。山上有明镜般的高山湖泊、高山草甸、七彩瀑布和变幻莫测的云
层、雪花、阳光。春季，几十种杜鹃漫山开遍，五彩缤纷；冬季，银装素裹，
雾松、冰湖、冰瀑、雪原等景观壮丽雄奇。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "northdown" : __DIR__"nj",
	]));

	set("coor/x",-360);
  set("coor/y",-440);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xueshan",1);
      }
}
