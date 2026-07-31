
inherit ROOM;

void create()
{
      set("short", "马厩");
      set("long", @LONG
这里是中州城英豪酒楼后的马厩，常年供应新鲜草料。中
州城自古乃军事要地，民风淳朴，马夫们会把马牵到马厩好生
照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人
上路。马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
      set("outdoors", "zhongzhou");
      set("no_fight", 1);
      set("objects", ([
              "/d/city/npc/zaohongma": 1,
              "/d/city/npc/huangbiaoma": 1,
              "/d/city/npc/ziliuma": 1,
              "/d/city/npc/mafu": 1,
      ]));
      set("exits",([
              "west" : __DIR__"yinghao",
      ]));
      set("coor/x", -210);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
      replace_program(ROOM);
}
