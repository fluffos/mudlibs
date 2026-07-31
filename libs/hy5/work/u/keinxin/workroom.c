// Room: /u/keinxin/workroom.c

#include <ansi.h>
inherit ROOM;
string look_hua();
string look_duilian();
string clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "飞天剑斋");
	set("long", @LONG
这里就是「书剑贰」中传说的飞天剑斋，是绯雨剑心隐居的地方，豪华的书架上放满
了世界各国著名的经济学著作，墙上挂着一副画(hua)，左右是一副对联(duilian)，
屋子的正中央放着一张上古石桌。          
LONG );

	set("item_desc", ([ 
	"hua" : (: look_hua :),
        "duilian" : (: look_duilian :),
	]));
	set("exits", ([ 
	 	"gc": "/d/city/guangchang"
	]));

        set("objects", ([
        "/u/keinxin/jinyong" : 1 ]) );

        set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
}
string look_hua()
{
       return 
"\n       
"HIY"剑心作于2002年6月19日

\n"NOR;
}
string look_duilian()
{
	return
"\n	
"HIY"
              ——                ——
              *皇*                *不*  
              *朝*                *及*
              *霸*                *人*
              *业*                *生* 
              *笑*                *一*
              *谈*                *朝* 
              *中*                *醉* 
              ——                —— 
\n"NOR;           
}

