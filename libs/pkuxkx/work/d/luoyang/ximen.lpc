//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
#include <title.h>
inherit ROOM;
void create()
{
        set("short", "洛阳西门");
        set("long", @LONG
洛阳西门高三丈，宽约二丈有余，尺许厚的城门上镶满了如拳头般大小的柳
钉。门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满了悬赏捉拿之类
的官府通谍，一条笔直的青石板大道向东西两边延伸，东去就是洛阳内城了，向
西一桥高高跨过洛阳城护城河。向北是名满天下的门派演武会场，南面一处空场，
官府设立了各种排行榜以彰武林义士。
LONG
        );

        set("exits", ([
               "westup" : __DIR__"chengxiqiao", 
               "east" : __DIR__"xidajie2",            
               "north" : "/biwu/gate",
               "south" : __DIR__"bang",
        ]));
        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));

        set("outdoors", "luoyang");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="north"&&!userp(me))
    {
        return notify_fail("你老兄哪能出去呀？\n");
    }
    //比武场卸除易容术效果
    //else if ( me->is_mask() )
    //{
    //	  me->restore_face(FACE_FACT);
    //	  return notify_fail("走向名满天下的门派比武场，心怀着崇敬，你卸除了脸上的易容效果。\n");
    //}
    
	if (dir=="south"&&!userp(me))
	{
		return notify_fail("");
	}
	return ::valid_leave(me, dir);
}