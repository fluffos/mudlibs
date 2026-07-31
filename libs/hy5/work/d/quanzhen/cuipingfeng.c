// cuipingfeng.c 翠屏峰顶
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "翠屏峰顶");
        set("long", @LONG
这里是翠屏峰的峰顶。翠屏峰是终南山的第一峰，也是最矮的一
个山峰。悬崖边建有一个小亭子，你走进亭中凭拦远望，远处的山间
白云漂浮缭绕，好象修筑着什么建筑，山景清丽，可惜被白云尽遮住
了。几个游客也在亭中歇脚，正啧啧赞美着此地美景。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"baishulin3",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
