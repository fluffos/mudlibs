// Room: 山路 1
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "山路");
	set("long", @LONG
你正走在一条崎岖不平的山路上，偶尔听到一阵阵的野兽叫声，头顶有一
些不知名的小鸟在跳来跳去，四周丛林密布，鲜花绿草若隐若现，随着山谷里
吹来的阵阵清风，传来哗哗的松涛声和一些淡淡的花香，身临其境，古朴、幽
静之感油然而生。
LONG
	);
	set("exits", ([ 
          "north" : "/d/dali/nanmen",
          "southup" : __DIR__"xgf",
        ]));
        set("outdoors", "大理");

	set("coor/x",-310);
  set("coor/y",-480);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="southup" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("山上荆棘丛生，骑马不宜上山。\n");
        }
        return ::valid_leave(me, dir);
}
