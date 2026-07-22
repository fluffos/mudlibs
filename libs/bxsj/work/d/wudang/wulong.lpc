// /area/jiangbei/wudang/wulong.c 五龙宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"五龙宫"NOR);
        set("long", @LONG
五龙宫背靠五龙顶，是武当山古建筑群中最早的建筑单元。修练之士到这
里隐居最早亦可追朔到汉代，是武当道教的发祥圣地，历史上被誉为灵应之地。
道教认为这块地域是群仙神龙居住的地方。所以，这儿立有一块碑，上面刻着
“洞天在近，过往低声”。以此告诫人们，这儿一面接着天庭，一面连着神府，
在此过往要静肃低声，以免惊扰神灵。 
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"yxyan",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/daotong" : random(2)+1,
        ]));

        set("outdoors", "武当");

        setup();
}
