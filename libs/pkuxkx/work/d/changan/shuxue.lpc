//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();

void create()
{
        set("short", "书学");
        set("long", @LONG
书学有两名博士，面向八品以下官员子弟和普通百姓，教授四书五经和
君子六艺的一般知识，书院大门边上贴着一张告示(gaoshi)。
LONG);
        set("exits", ([
           "west" : __DIR__"guozijian",
           "north" : __DIR__"shuxue-boshi1",
           "south" : __DIR__"shuxue-boshi2",
        ]));
        
        set("item_desc", ([
		       "gaoshi" : (:look_gaoshi:),
	      ]));
        
        set("locate_level",0);
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

string look_gaoshi()
{
	string msg;
	
	msg="本学院供无爵位或者有爵位初入学者学习。目前提供课程有四书五经入门、\n"+
	    "音律入门、琴入门、琵琶入门、筝入门、箫入门、横笛入门、鼓入门、铜钹\n"+
	    "入门等基础课程，偶尔会教授高山流水、梅花三弄、汉宫秋月、胡笳十八拍、\n"+
	    "阳春白雪等乐谱的弹奏技巧，幸运的话还会听到讲授夕阳箫鼓、渔樵问答、\n"+
	    "广陵散、十面埋伏等乐谱的弹奏技巧。博士每节课讲授15分钟，每听一分钟\n"+
	    "缴纳少量银子。";	
	return msg;
}