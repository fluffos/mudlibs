// guangchang.c 广场
// by Xiang
inherit ROOM;
void create()
{
        set("short", "武当广场");
        set("long",
"这是一个由大石板铺成的广场，是武当弟子学习武功和互\n"
"相切磋的地点。周围种满了梧桐树，一到秋天就是满地的落叶。\n"
"一个年纪轻轻的道童正在打扫。北边是灵霄宫三清殿。\n"
        );
        set("outdoors", "wudang");
        set("exits", ([
                "eastdown" : "/d/wudang/tyroad1",
                "southdown" : __DIR__"zixiao",
                "north" : __DIR__"sanqing",
                "northwest" : __DIR__"jiaochang1",
                "west" : __DIR__"jiaochang2",
                "southwest" : __DIR__"jiaochang3",
                "northeast" : __DIR__"jiaochang4",
                "east" : __DIR__"jiaochang5",
                "southeast" : __DIR__"jiaochang6"
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/daotong2" : 2,
                CLASS_D("wudang") + "/chongxu" : 1]));
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me,string dir)
{       
	mapping fam=(mapping)me->query("family"),exits=query("exits");
	object env,item;
  
  if(strsrch(exits[dir],"jiaochang")>=0) {
  	if(!(env=find_object(exits[dir])))
  		env=load_object(exits[dir]);
  	foreach(item in deep_inventory(env))
  		if(userp(item)&&item->query_temp("quest_zhenfa/prac_zhenfa"))
  			return notify_fail("房间中已经有人在演习阵法，请等对方演习结束再进去吧。\n");
  }
  
  if ((int)me->query("score")>500) 
    return ::valid_leave(me,dir);
  
  if ((fam && fam["family_name"]=="武当派" && !(int)me->query_temp("下山")&& dir=="southdown"))
    return notify_fail("没有掌门的同意，你怎可私自下山？\n");
 
  this_player()->delete_temp("下山");
  return ::valid_leave(me,dir);
}
