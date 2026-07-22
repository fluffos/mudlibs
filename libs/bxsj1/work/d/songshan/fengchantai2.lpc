// Room: /u/swl/songshan/fengchantai.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"封禅台"NOR);
        set("long", @LONG
封禅台为大麻石所建，每块大石都凿得极是平整，当年帝皇为了祭天
祀福，不知驱使几许石匠，始成此巨构。封禅出下是可以容纳数千人的广
场，登临于此，可以望见大熊峰、小熊峰、双主峰、三尖峰和少林寺所在
的少室山，不禁让人想起杜甫“齐鲁青未了”的绝句。
LONG);
        set("exits", ([ 
            "southdown" : __DIR__"peitian-fang",
   
        ]));
        set("objects", ([ 
   CLASS_D("songshan") + "/zuo2" : 1,
            __DIR__"npc/ssdizi" : 3,
        ]));
        set("outdoors", "嵩山");
        setup();
        
}

int do_enter(string arg)
{
        mapping fam;
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="ri" ){
 if((fam = me->query("family")) && fam["family_name"] == "嵩山派" ) {
               message("vision",me->name() + "整了整衣服,向观日峰走了过去。\n",environment(me), ({me}) );
               me->move("/d/songshan/guanrifeng");
               message("vision",me->name() + "从封禅台走了过来。\n",environment(me), ({me}) );
               return 1;
           }
           else return notify_fail("那边太阳好大,你不怕晒黑吗?！\n");
        }       
}

void init()
{
        
        add_action("do_enter","guan");
        
}