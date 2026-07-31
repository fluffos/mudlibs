// Room: /dali/shuyuan.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学。在他的两侧坐满了求学的学生们。一张古意盎然的书案放在老先生
的前面，案上摆着几本翻开的线装书籍。讲堂内多历代楹联石刻，足见书院历
史的悠久。值得一提的是嵌在讲堂前左壁的学规(xuegui)。
LONG
	);

	set("exits", ([
           "west" : __DIR__"nanjie5",
	]));

	set("item_desc", ([
		"xuegui" : "日讲经书三起，日看纲目数页。"  
			"\n通晓时务物理，参读古文诗赋。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n",
	]));
	
	set("objects", ([
            __DIR__"npc/zhu": 1,
	]));

	set("coor/x",-280);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/shuyuan",1);
      }
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/literate", 0);
	return 1;
}
