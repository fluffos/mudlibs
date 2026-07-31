inherit ROOM;
void create()
{
        set("short", "曲桥");
        set("long", @LONG
浣花溪成葫芦状，在此一曲飞桥连接两岸。至黄昏偶驻，远处灯火万点，间以星影
萤光，错落难辨。深秋时，霜风初起，枫林渐染黄碧，野岸衰柳芙蓉，掩映水际，芦苇
中鸿雁群集，嘹呖干云，哀声动人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"bridge1",
  "south" : __DIR__"bridge3",
  
]));
   
	set("outdoors","huanhua");
        set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
