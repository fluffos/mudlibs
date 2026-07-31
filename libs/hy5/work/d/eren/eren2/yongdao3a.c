#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小石洞");
        set("long",  @LONG
石壁上一块凹进的地方，约摸有一丈高，两丈见方，点着一盏油灯，放着几个
木箱和一张床，地上胡乱丢着几柄长剑，还有些没吃完的食物。四壁阴暗潮湿，长
满了青苔。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao3",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
                __DIR__"npc/guarda1" : 1,
                
        ]) );
        set("item_desc", ([
        "青苔" : "暗色的青苔布满了洞壁。\n",
        "moss" : "暗色的青苔布满了洞壁。\n",
        "油灯" : "一盏油灯，似乎没有什么特别的地方。\n",
        "lamp" : "一盏油灯，似乎没有什么特别的地方。\n",
        "木箱" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "box" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "床" : "一张断了一条腿的木床，是守卫轮值休息时用的。仔细看去，床头似乎有个按钮（push）。\n",
        "bed" : "一张断了一条腿的木床，是守卫轮值休息时用的。仔细看去，床头似乎有个按钮（push）。\n",
    ])); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("trap",1);
        setup();
        
} 
void init(){
        add_action("do_push", "push");
} 
int do_push(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "button" && arg != "按钮")) {
                return 0;
        }
        if (guard=present("lieutenant",this_object()))
                return notify_fail("小头目大喝一声，“偷偷摸摸地想干什么！“\n");
        if (guard=present("guardian",this_object()))
                return notify_fail(guard->query("name")+"大喝一声，“偷偷摸摸地想干什么！“\n");
        if(query("trap")) {
                tell_object(me,HIW"你小心翼翼地碰了碰按钮，洞壁后传来一阵咔咔的响声，而后又静了下来。\n"NOR);
                this_object()->set("trap",0);
        } else {
                tell_object(me,HIW"你小心翼翼地碰了碰按钮，什么动静也没有。\n"NOR);
                }
        return 1;
} 
void reset()
{
        ::reset();
        set("trap",1);
        
}       
