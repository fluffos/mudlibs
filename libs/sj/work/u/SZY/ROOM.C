inherit ROOM;
#include <ansi.h>

void create()
{       
set("short", "水中游的工作室");
set("long", @LONG       
这里是水中游的工作室。温馨的音乐在房间里飘荡，一台赛羊正在嗡嗡地工作。
屋里有一大片空地，据说是为安放音响而预留的。书架(shelf) 上全是小说，其中一本
是水中游自己的作品。墙上有一副对联(duilian).
LONG    );      
set("valid_startroom",1);
set("no_steal", "1");
        set("exits", ([
                "room":__DIR__"room1",
                "budui" : "/d/budui/kezhan1",
                "huang" : "/d/huang/huangong",
                "city" : "/d/city/dongdajie1",
                "biwu" : "/d/biwu/shendian",
                "death" : "/d/death/road1",
                "fenghuang" : "/d/fenghuang/fenghuang/guangchang",
                "earth" : "/d/earth/gate",
                "jianyu" : "/d/jianyu/jianyu_do",
                "shendao" : "/d/shendao/kafe",
                "shendian" : "/d/shendian/luxingchu",
                "taikong" : "/d/taikong/zongshu",
                "wiz" : " /d/wizard/wizard_room",
                





        ]));

set("item_desc", ([
                "shelf" : HIC "\n酒盈杯，书满架，名利不将心挂。\n" NOR,
                "duilian" : HIG "\n给我一个温柔的陷阱\n" NOR + HIC "还你一腔燃烧的爱情\n" NOR,
        ]));
setup();
}


