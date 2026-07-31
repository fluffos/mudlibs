// /d/zhuojun/xiaoxiang.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "岳麓书院");
	set("long", @LONG
全国四大书院之首的岳麓书院，位于岳麓山清风峡入
口处，历千年而不衰，这与名家主讲、帝王题赐及楚人
擅学有很大关系。书院由门、堂、亭、台、楼、阁、轩
、斋、祠、庙组成，门联"唯楚有材，于斯为盛"晓喻古
今；大厅朱熹手书"忠孝廉节"石刻闻名于世；清康熙、
乾隆皇帝手书"学达性天"、"道南正脉"匾至今历历在目
；"岳麓书院"相传为宋真宗手迹。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
                "west"  :__DIR__"beidajie1",
	]));
	
      set("objects",([
            "/clone/npc/man":2,
                  "/d/wudujiao/npc/xuetong": 3,
                  "/d/wudujiao/npc/xiansheng": 1,
            ]));
       setup();
	replace_program(ROOM);
}	
