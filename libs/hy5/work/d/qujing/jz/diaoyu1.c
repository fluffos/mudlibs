inherit ROOM;
void create()
{
  set ("short", "荒野小路");
  set ("long", @LONG

这条小路不知道通往什么地方，但是再向前走能碰到一个白胡子老大爷，
传说这位老大爷能上通天文，下晓地理，民间凡事不无知晓。听说谁要是
能跟这位神秘人物见上一面，将是难得的修来的福气。
LONG);
        set("exits", ([
        "northup": __DIR__"sgate",
        "south": __DIR__"diaoyu2",
]));
    set("outdoors", "xy1");
  setup();
}
