//jinling  fuzimiao。c
inherit ROOM;

void create()
{
        set("short", "夫子庙");
        set("long", @LONG
为孔庙俗称，又称文庙，是供奉和祭祀孔子的地方,以其“青砖小瓦马头墙、
回廊挂落花格窗”的建筑风格称颂一时。游人学子络绎不绝。无不想瞻仰下孔子的
风貌。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"nanjie2",

]));
set("objects", ([
              __DIR__"npc/xuezi" : 1,
              __DIR__"npc/wulinren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}