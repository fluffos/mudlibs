// Room: /d/hainan/jingtang
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "观音堂");
  set ("long", @LONG
白云庵的佛殿,只在正中的供桌上摆了一座白衣观音.下面的水磨石 
地上摆了个蒲团.旁边是一个小小的木鱼.此外一无所有,自然有一种威严 
气氛.想不到武林传中的圣地居然是这样子的. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master.c" : 1,
  __DIR__"npc/dizi" : 4,
"/d/biwu/champion_hn" : 1,
"/quest/menpai/newmp/shi10" : 1,	

]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
set("valid_startroom",1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"baiyunan",
  "west" : __DIR__"shutang",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "白衣观音" : "一尊陶瓷的白衣观音,高二尺许.左手端托净瓶,右手斜向右 
下角,拇指中指暗扣宝瓶印. 
",
]));
	create_door("south", "庵门", "north", DOOR_CLOSED);
  setup();

}

int valid_leave(object me, string dir)
{
	object ob;
	if ((dir=="west") && me->query("family/family_name")!="白云庵")
	{
		ob = present("fan yin", this_object());
	if(objectp(ob)&&!userp(ob)&&living(ob))
		{
			message_vision("\n$N伸手把$n拦住说：本派密室,贵客自重！\n", ob, me);
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
