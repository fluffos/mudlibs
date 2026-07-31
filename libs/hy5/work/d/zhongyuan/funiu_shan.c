inherit ROOM;
void create()
{
  set("short","伏牛山");
  set("long",@LONG
地势渐高，四周都是茂密的树林，一条小路南北延伸。近来官府政纪松涣，
赋税加重，一些贫苦农民纷纷落草为寇。于是山上常有强盗出没，威胁过往客
商。一到晚上，行人都不敢从山上经过；就是白天上山，心里也是惴惴不安的，
担心强盗会来抢劫。
LONG);
  set("exits",([
    "northeast"   : __DIR__"tulu4",
    "southeast"  : "/d/nanyang/beimen",
  ]));
  set("outdoors","zhongyuan");
  setup();
}

