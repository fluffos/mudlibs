// by arnzh 97.1.24
inherit ROOM;
void create()
{
        set("short", "凌霄宫");
        set("long",
"在你的面前是一座道观，上面写着“凌霄宫”三个朱红色\n"
"的大字，由此往内就是武当的庙产了，现在进香的人明显少了，\n"
"而穿不同服色的道士确不断进进出出，诵经的声音隐隐传来。\n"
"西侧有一条小路通向山麓的另一边。\n"
        );
        set("outdoors", "wudang");
        set("exits", ([
                "southdown" : __DIR__"xuanwu",
                "northup" : __DIR__"guangchang",
                "westup" : __DIR__"shijie16",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/zhike" : 1]));
        setup();
}
/*
int valid_leave(object me,string dir)
{       mapping fam=(mapping)me->query("family");
        {
	if ((int)me->query("score")>500) 
        return ::valid_leave(me,dir);
       if ((fam && fam["family_name"]=="武当派" && !(int)me->query_temp("下山")&& dir=="southdown"))
        return notify_fail("没有掌门的同意，你怎可私自下山？\n");
         this_player()->delete_temp("下山");
        return ::valid_leave(me,dir);
        }
}
*/
