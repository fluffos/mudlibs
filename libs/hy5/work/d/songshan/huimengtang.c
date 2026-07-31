// Room: /d/songshan/huimengtang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "会盟堂");
	set("long", @LONG
这里原来是峻极禅院的大雄宝殿，自五岳剑派百年前在此歃血为盟
以来，这里就成了五岳剑派中枢所在了。堂上正中放着一张黄绸太师敞
椅，那是盟主的宝座。两边雁形排列着泰、华、衡、恒的青呢、白缎、
红罗、黑绫座椅，椅后插着各派的五色旗。
LONG );
	set("exits", ([
		"south" : __DIR__"zhongmen",
		"north" : __DIR__"jianchi",
	]));
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
		CLASS_D("songshan")+"/zuo" : 1,
	"/quest/menpai/newmp/shi2" : 1,
"/d/songshan/npc/dizi":4,		
"/d/biwu/champion_ss":1,		
	]));
	set("coor/x", -20);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
