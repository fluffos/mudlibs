// baling/shuyuan
// Room in 龟兹 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐
在太师椅上讲学，南朝的大儒杨先生了。战乱的时代他逃到这里，在他
的两侧坐满了求学的学生。一张破烂的的大书案放在朱先生的前面，案
上摆着几本翻开了的线装书籍。朱先生的身后是一个书架(shujia)讲堂
内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在讲堂前左
壁的学规(xuegui)。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
   
        "south" : __DIR__"dongdajie1",
]));
        set("objects",([
          __DIR__"npc/zhu":1,
          ]));
        set("item_desc",([
         "shujia":"这是一个大书架，上面放了很多书籍。\n",
         "xuegui":"交费上学。\n",
         ]));
	setup();
	replace_program(ROOM);
}
