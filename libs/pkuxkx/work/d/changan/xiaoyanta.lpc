//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "小雁塔");
        set("long", @LONG
荐福寺内的小雁塔远近闻名，清晨小雁塔的钟声响彻10里，
雁塔晨钟是著名的关中八景之一。整个塔高15层，塔中存放着一
口三人高的大钟。
大唐皇帝陛下为祈福添喜，特在长安小雁塔设下天下比武擂台，
愿天下群雄共襄盛会。
放眼看去，发现四周按照小雁塔的层数搭建了很多擂台。
LONG);
        set("exits", ([
           "west" : __DIR__"jianfosi"
        ]));
		set("objects", ([
                __DIR__"npc/peixingjian" : 1,
        ]));       
		set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}