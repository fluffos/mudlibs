// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96
// modified by Zine 21 oct 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "日月洞");
        set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上端坐着
星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。
洞两侧竖立兵器架，上面排列的大多是各种棍棒。丁春秋背后的珠帘(zhulian)
有些诡异。
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zhulian" : "一扇珠帘，不知道通向何处，你可以尝试卷(juan)开它。\n",
                "zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　 ※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　 ※※※※
※※※※※※※※※※※※※※※※※
" 
        
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiegun" : 1,
                __DIR__"obj/huoyan" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        

}

void init()
{
	add_action("do_juan", ({ "juan" }));
}

int do_juan(string arg)
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query("emnewbiejob_miejue_task")==1&&me->query("family/family_name")=="峨嵋派")//em新手任务交换生免疫
    {
        tell_object(me,"你卷起珠帘，眼前柳暗花明，来到了星宿后山。\n");
        me->move(__DIR__"wenjinting");
        tell_room(this_object(),HIC+me->name()+"卷起珠帘一闪身就不见了。\n"NOR);
        
        return 1;
    }
    if (me->query("family/family_name")!="星宿派")
    {
        tell_object(me,"卷帘后一个淡淡的声音，阁下不是我星宿派弟子，请回吧。\n");
        return 1;
    }
    if (!arg||(arg!="帘" && arg!="珠帘" && arg!="zhu lian" && arg!="zhulian"))
    {
        tell_object(me,"你想要卷起什么？\n");
        return 1;
    }
    else
    {
        tell_object(me,"你卷起珠帘，眼前柳暗花明，来到了星宿后山。\n");
        me->move(__DIR__"wenjinting");
        tell_room(this_object(),HIC+me->name()+"卷起珠帘一闪身就不见了。\n"NOR);
        
        return 1;
    }
}