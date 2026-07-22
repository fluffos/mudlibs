// Room: /u/zqb/tiezhang/shanjiao.c

inherit ROOM;

void create()
{
        set("short", "山脚下");
        set("long", @LONG
这里已到了山脚下，此处近看，但见五座山峰峭兀突怒，确似五根手指竖
立在半空之中。居中一峰尤见挺拔，笔立指天，耸入云表，下临深涧。山侧生
着一片松林，松梢留雪，树身尽皆向南弯曲，想见北风极烈。
LONG
        );

        set("outdoors", "tiezhang");

        set("exits", ([ 
              "northup" : __DIR__"shanmen",
              "southeast" : __DIR__"road-3",
        ]));

           set("objects",([
           __DIR__"npc/keshang":1,
           ]));
        set("no_clean_up", 0);
        set("coor/x",-330);
  set("coor/y",-300);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="northup" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("山上荆棘丛生，骑马不宜上山。\n");
        }
        return ::valid_leave(me, dir);
}

