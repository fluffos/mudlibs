// Room: /d/city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学，那就是当今大儒朱先生了。在他的两侧坐满了求学的学生。一张古
意盎然的书案放在朱先生的前面，案上摆着几本翻开了的线装书籍。朱先生的
身后是一个书架(shujia)讲堂内多历代楹联石刻，足见书院历史的悠久。值得
一提的是嵌在讲堂前左壁的学规(xuegui)。书院老夫子刚奉了圣旨颁发学位，
就在门口树着书院新立的学位公告板(board)。
LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	求学需缴学费五十两。\n",
		"board": "
       本书院奉圣上恩旨自即日起封授学位：
  0       文盲
 10       童生
 20       秀才
 30       举人
 40       解元
 50       贡士
 60       会元
 70       进士
 80       探花
 90       榜眼
100       状元
110       翰林院士
120       翰林硕士
130       翰林博士
140       翰林院编修
150       庶吉士
160       学士
170       内阁大学士
180       内阁首辅
190       文学大宗师
200       圣人\n" 
	]));
	set("exits", ([ /* sizeof() == 2 */
		"up"    : __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));
	set("roomif","$botten#查看|购买|学习:list|buy <物品选取>|give 50 silver to zhu$#");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhu" : 1,
	]));
//	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
