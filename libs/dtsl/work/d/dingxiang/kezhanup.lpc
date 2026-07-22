// /d/yazhang/kefangup.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "客栈二楼");
	set("long", @LONG
你顺着楼梯登上客栈的二楼，房文门紧闭着，仔细听可以听见屋内
睡觉的呼噜声。
LONG
	);
set("exits", ([
                 "south" : __DIR__"shuifang",  
                  "down" : __DIR__"kezhan",  
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(dir=="down")
  ob->delete_temp("gived_money");
  return ::valid_leave(ob,dir);
}
