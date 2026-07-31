inherit ROOM;
void create()
{
  set("short","官道");
  set("long",@LONG
这是朝廷为传公文，调军队，役使数十万民工修成的大道。南面是高高的秦
岭山脉翻山过去可达汉中平原，北面是著名的黄土坡“五丈原”：三国时期，诸
葛亮六出祁山伐魏的最后一次就不幸病逝在这里；至今，坡上还建有诸葛武候祠
以表纪念。路上不时有身着官服的人策马飞奔而过。行人见了，都远远避过一边。
    向西去有一条平整的驿道，直通秦州府。    
LONG);
  set("exits",([
    "east"   : __DIR__"guandao2",
    "west"   : "/d/xibei/yidao1",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

