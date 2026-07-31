inherit ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是客店后的马厩，常年供应新鲜草料。扬州民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到
客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
      set("outdoors", "jingzhou");
      set("no_fight", "1");
      set("no_beg", "1");
      set("no_clean_up", 0);
      set("objects", ([
               "/d/city/npc/zaohongma": 1,
               "/d/city/npc/huangbiaoma": 1,
               "/d/city/npc/ziliuma": 1,
               "/d/city/npc/mafujingzhou": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
客人们只要给马夫十两白银的租金就可以雇到一匹马了。

前往      扬州城:  yz
          昆明城:  km
          成都城:  cd

TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"kedian",
      ]));
      setup();
      replace_program(ROOM);
}

