//create by smile 12/8/98
// room: /d/qujing/baigudong/shanshipo.c

inherit ROOM;

void create ()
{
  set ("short", "山石坡");
  set ("long", @LONG

    终于走出了山石路，望眼而去是一片起伏不平的山坡田。
四周远远都是山峦，山坡坡度不大，两边的山坡田都已干
裂，天气确实炎热。走在山坡上静悄悄，烈阳高照，让人
心浮气躁,隐约听到有人呼喝声。

LONG);

  set("exits", ([
        "east"  : "/d/qujing/huangfeng/huangfeng8",
        "westdown"       : __DIR__"xiapolu1",
        "northeast"  : __DIR__"sroad7",
      ]));
  set("objects", ([
        __DIR__"obj/baigu"   : 1,
      ]));
  set("outdoors",__DIR__"");

  setup();
}

