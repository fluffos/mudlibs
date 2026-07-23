// /d/yazhang/kezhan.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "客栈");
	set("long", @LONG
厅堂里摆放着四五张桌子，几个客人在那里用饭，门旁横放着一大
柜台，掌柜的坐在柜台后，眯着眼睛在那儿品茶，一个小伙计忙来忙去
招呼客人。
LONG
	);
set("exits", ([
                 "west" : __DIR__"beidajie1",  
                  "up" : __DIR__"kezhanup",  
	]));
	set("objects",([
	__DIR__"npc/xiaoer4":1,
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(!ob->query_temp("gived_money")&&dir=="up")
  return notify_fail("恩，不给钱想白住啊？！\n");
  return ::valid_leave(ob,dir);
}
