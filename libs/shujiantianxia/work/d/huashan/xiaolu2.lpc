// Room: /d/huashan/xiaolu2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "小山路");
        set("long", @LONG
这里是华山的一条小山路，地势较为平缓，不似其它地方那么险峻。你走
在这里，四周静悄悄的，你就象走进了一个世外桃源。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                "southeast" : __DIR__"xiaolu1",
                "westup" : __DIR__"siguoya",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "华山" );

        set("coor/x",50);
  set("coor/y",50);
   set("coor/z",60);
   setup();
}

void init()
{
        object me = this_player();
        if( me->query("family")
         && me->query("family/family_name") != "华山派"
         && me->query("fengset")){
          me->delete("fengset");
        }
}
