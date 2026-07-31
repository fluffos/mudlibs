// hubian.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIB "轩辕古墓"NOR);
        set("long", @LONG
一座很大的坟墓出现在你的眼前，在长安城南的一片荒地中
显得格外的阴森恐怖，一座墓碑(tombstone)矗立在坟前，周
围密密麻麻地堆了好几十个坟头。有些坟前还有些祭祀，烧纸
的痕迹,几只寻食的野狗在四周转悠，却始终不敢靠近好像这坟
墓里有什么恐怖的怪物，偶而几声狼嚎更让人觉得毛骨悚然。
LONG );
        set ("item_desc", ([
                "tombstone" : "女娲座下九天玄女 狐精妲姬 之墓。\n"
        ])  ) ;
        set("exits", ([ /* sizeof() == 2 */
                "south" : "d/changan/fendui",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xiaoyao" );
        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_zuan",({"zuan","enter"}));
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="tombstone") return 0;
        write("你运力双臂，双手扶着墓碑向左旋转一下，随即向右旋转\n");
       if(random((int)me->query("kar")) < 10 )
              if(random((int)me->query("str")) < 10 )
                {
                write("晃动晃动了一下，但是一晃即回。\n");
                return 1;
                };
        write("向右转到一半时，只听“咔嗒”一声墓碑后露出一个三尺来高的洞穴(hole)。\n");
        me->set_temp("marks/push",1);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!me->query_temp("marks/push")) return 0;
        if ( arg != "hole") return 0;
        message_vision("$N左右环顾，觉得四周并无危险，便一闪身钻入古墓之中。碑后洞穴自动合闭。\n", me);
        me->move(__DIR__"yongdao1.c");
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("marks/push") ) me->delete_temp("marks/push");
        return ::valid_leave();
}

