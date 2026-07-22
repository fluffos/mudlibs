// Room: yixianglou.c

inherit ROOM;

void create()
{
	set("short", "溢香楼");
	set("long", @LONG
这里是家小小的酒馆，房间四壁被长年的油烟熏得全成了黑色，桌椅早被
摩擦得失去了漆色，坐上去会摇晃着发出吱拗吱拗的怪响。柜台边上摆着个大
酒缸，里面盛的是这里远近闻名的青稞烧酒，散发出一股刺鼻的酒气。这里的
老板好象是从中原搬到这里来的，就是凭着这手酿酒的绝活，在这里生活了多
年。西墙上挂着个写着毛笔字的木牌(sign)。
LONG
	);

	set("exits", ([
		"west" : __DIR__"jiedao2",
	]));

        set("no_sleep_room",1);
        set("item_desc",([
           "sign" : 
        "青稞烧酒(shaojiu)：每瓶八十文。
         大王肉饼(roubing)：每个二百文。
         店小利微，概不赊欠。\n",     
           ]));
        set("objects", ([
         __DIR__"npc/hu" : 1,
        ]));
	set("coor/x",-210);
  set("coor/y",110);
   set("coor/z",0);
   setup();

}
