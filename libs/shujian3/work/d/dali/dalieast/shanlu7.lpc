// Room: 山路 7
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
                "northeast" : __DIR__"road1",
                "west" : "/d/dali/dongmen",
                "southeast" : __DIR__"xs1",
        ]));
        set("outdoors", "大理");

	set("coor/x",-270);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="west" ){
        if( me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("山上荆棘丛生，骑马不宜上山。\n");
        }
        return ::valid_leave(me, dir);
}
