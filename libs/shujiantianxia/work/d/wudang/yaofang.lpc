// /d/wudang/yaofang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"药房"NOR);
        set("long", @LONG
这是武当山脚下的一间小药房，一名武当道童正在不停拉着风箱。房屋的
墙上贴着一张纸（paper)，中间有一个丹炉(lu)，里面散发出浓浓的药味，似
乎刚有人熬过什么丹药。
LONG
        );
        set("no_fight",1);

        set("objects",([
           __DIR__"danlu/lu" : 1,
                __DIR__"npc/daotong2" : 1,
        ]));

        set("exits", ([
           "east" : __DIR__"zoulang3",
        ]));

        set("item_desc", ([
           "paper": "熬药方法如下：\n"
"\n\t\t① 打开盖子"HIC"<--->(open lid)\n"NOR
"\t\t② 添加药材"HIC"<--->(add 药材名 in lu)\n"NOR
"\t\t③ 添加清水"HIC"<--->(pour 容器 in lu)\n"NOR
"\t\t④ 关闭盖子"HIC"<--->(close lid)\n"NOR
"\t\t⑤ 点燃火折"HIC"<--->(dianhuo)\n"NOR
"\t\t⑥ 点燃柴火"HIC"<--->(burn coal)\n"NOR
"\t\t⑦ 煎熬药材"HIC"<--->(aoyao)\n"NOR
"\t\t⑧ 扑灭丹炉"HIC"<--->(miehuo)\n"NOR
"\t\t⑨ 取出药材"HIC"<--->(qu 药材名 from lu)\n"NOR,
        ]));

        setup();
}
