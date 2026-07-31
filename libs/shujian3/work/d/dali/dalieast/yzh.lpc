// Room: /d/dali/yzh.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "阳宗海");
	set("long", @LONG
阳宗海位于宜良、呈贡和澄江三县间，古称明湖，宋、元大理国段氏在此
设强宗部，后强宗讹为阳宗，故叫阳宗海。阳宗海形如草，两头宽，中部略窄。
南北长约十二公里，东西宽三公里左右，湖面积为三十平方公里，最深为三十
米，仅次于抚仙湖和泸沽湖，为大理第三深水湖泊。东北面的汤池河为出水口，
汇南盘江，归南海。阳宗海景色秀丽，碧波粼粼，沿湖岩壑嶙峋，陡险峻美。
每遇消放，湖面显得非常恬静、动人。这时敛静影，碧水如镜，鱼船往来，宛
若图画。景谓“明湖澄碧”，阳宗海为高原断陷湖泊，湖内盛产有名的金线鱼
外，还产鲤鱼、青鱼、白鱼、杆条鱼等十多种鱼类。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "west" : __DIR__"chengj",
	]));

	set("coor/x",-250);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/yzh",1);
      }
}
