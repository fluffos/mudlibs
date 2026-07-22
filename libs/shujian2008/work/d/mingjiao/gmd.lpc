// gmd.c  光明顶
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"光明顶"NOR);
       set("long", "
    这里就是明教光明顶。你走到这里就可看见三个鲜红色大字。明教，少林，\n"+
"丐帮中明教是最大的教，少林是最大的门派，而丐帮则是最大帮派。明教自由\n"+
"波斯总教传至中原已有百多年的历史了。明教始终都以反元抗胡，行善去恶及\n"+
"除暴安良为自已的宗旨。但由于明教太大，门下教众难免莨莠不齐，至使被名\n"+
"门正派称为魔教。正中央一面红色火焰的大旗。北边是练武场，南边是巨木旗\n"+
"的所在地。\n\n"HIR"\t\t\t光    明    顶\n\n"NOR);
	set("exits", ([
		"northup" : __DIR__"wu3",
		"southdown" : __DIR__"muqi",			
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/yin" : 1,
                CLASS_D("mingjiao") + "/wulu" : 1,
                __DIR__"npc/m-dizi" : 2,
	]));
        set("outdoors", "明教光明顶");
        set("valid_startroom", 1);
        set("coor/x",-290);
  set("coor/y",170);
   set("coor/z",110);
   set("coor/x",-290);
 set("coor/y",170);
   set("coor/z",110);
   setup();        
        call_other("/clone/board/mingjiao_b","???");
}
