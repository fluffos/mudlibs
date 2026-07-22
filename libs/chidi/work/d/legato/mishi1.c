inherit ROOM;

void create()
{
      set("short", "铁人巷");
      set("long", @LONG
这里是一间密室，里面暗淡无光，不知有多大，门的两旁有两个山庄
弟子站在那里，据说这里是雁山老人为了躲避前来寻仇的武林人士修建
的，只是现在什么也看不清，也不知道通向哪儿...
LONG
      );

      set("objects", ([
               "/d/yandang/npc/dizi": 2,
      ]));

      setup();
      replace_program(ROOM);
}

