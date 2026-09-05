//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "杂役处");
        set("long", 
"这里是杂役处，新入宫的公公都要在这里接受皇家礼仪的培训才能允许正式\n入宫，门上贴着规矩(rules)。\n"
        

        );
        set("exits", ([
                
              
                
                "out" : __DIR__"chengtianmen",
                
                
        ]));
        set("item_desc", ([ 
        "rules" : "新入宫者，必须抄写宫规三日方可离宫，准备(ready)好后，开始抄写(chao)。\n", 
            ]));
        set("no_yizhang",1);
        set("real_dark",1);
        set("no_sleep_room",1);
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
    object me=this_player();
	me->set("startroom", base_name(this_object()));
    add_action("do_ready","ready");
    add_action("do_chao","chao");
}

int do_chao(string arg)
{
    object me=this_player();
    int points=1+random(3);
    if (!me)
    {
        return 1;
    }
    if (!me->query_temp("tj/ready"))
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!arg)
    {
        return notify_fail("你要抄写什么？\n");
    }
    if (arg!=me->query_temp("tj/sentence"))
    {
        tell_object(me,"好像你抄错了一段宫规！\n");
        me->add_temp("tj/rulescomplete",-1);
        return 1;
    }
    else
    {
        tell_object(me,"你核对了一下，完全无误。\n");
        me->delete_temp("tj/sentence");
        me->add("combat_exp",points);
        tell_object(me,"你被奖励了"+chinese_number(points)+"点经验。\n");
        me->add_temp("tj/rulescomplete",2);
        return 1;
    }
    
}

int tjrules(object me)
{
    int i,n;
    string rules;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    string* rules1=({"司礼监掌内外奏章，御前勘合。","内宫监掌宫室、陵墓等营造。","御用监司御用物什。","司设监管理，掌仪仗、卤簿。",
        "御马监掌御马房、象房。","神宫监司太庙洒扫，香灯。","尚膳监掌御膳及宫中饮食。","尚宝监掌宝玺、敕符、印信公文。",
        "尚绶监掌铁券、诰敕、勘合。","直殿监掌皇宫殿院、廊庑洒扫。","尚衣监掌御用冠冕、袍服。","都知监御驾鞍前马后导警跸。",
        "惜薪司掌宫中薪炭之事。","钟鼓司掌出朝钟鼓及诸内戏。","宝钞司掌造粗细草纸。","混堂司掌宫中沐浴。",
        "兵仗局掌军器、火药制造。","银作局掌金银器皿打造。","浣衣局掌老年及罢宫女安置。","巾帽局掌宫中所用帽靴。",
        "内织造局掌宫中御用、内用缎匹染造。","针工局掌宫中御用、内用服饰。","酒醋面局掌宫中食用酒醋糖酱酿造。","司苑局掌蔬菜瓜果。"});
    string* rules2=({"不得随地大小便","不得调戏宫女","不许偷看娘娘洗澡","不许偷看皇上打炮","不许背后说Zine的坏话",
        "吃完饭不许剔牙","睡前不许不洗澡","不得在公共场合抠脚","不许横穿御道","不许随地丢垃圾","不许背后说Zine的坏话",
        "睡觉要熄灭蜡烛","吃东西前要洗手","不许背后说Zine的坏话","不许背后说Zine的坏话","不许背后说Zine的坏话","不许背后说Zine的坏话",
        "要尊敬老人","要爱护幼小","不要恶意揣测别人","要抵制日货"});
    if (me->query_temp("tj/rulescomplete")>40 && me->query("ming/tj/pin")<=7 && me->query("ming/tj/pin"))
    {
        me->set("ming/tj/gonggui",me->query("mud_age"));
        tell_object(me,HIW"你抄写宫规无误，可以去从事其他工作了。\n"NOR);
        return 1;
    }
    if (me->query_temp("tj/rulescomplete")>300)
    {
        me->set_temp("tj/finish",1);
        tell_object(me,HIW"你抄写宫规无误，可以找李公公成为一名正式的、光荣的小太监。\n"NOR);
        return 1;
    }
    if (random(1000)>499)
    {
        rules=rules1[random(sizeof(rules1))];
    }
    else
    {
        rules=rules2[random(sizeof(rules2))];
    }
    tell_object(me,BLINK+color1+rules+"\n"+NOR);
    me->set_temp("tj/sentence",rules);
    remove_call_out("tjrules");
    call_out("tjrules",10,me);
    return 1;
}

int do_ready()
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query("ming/tj/pin"))
    {
        return notify_fail("你不是大明的内廷官员，不可以偷看宫规。\n");
    }
    if (me->query_temp("tj/ready"))
    {
        return notify_fail("你已经开始抄写了，就安心抄完吧。\n");
    }
    else
    {
        me->set_temp("tj/ready",1);
        tell_object(me,"你拉开一条长凳，趴在桌上，准备开始抄写(chao)宫规。\n");
        tell_object(me,"翻开宫规后，你要抄写每一条。\n");
        remove_call_out("tjrules");
        call_out("tjrules",5,me);
        return 1;
    }
}

int valid_leave(object me,string dir)
{
    if (dir=="out")
    {
        if (me->query("ming/tj/pin")>7)
        {
            if (!me->query_temp("tj/finish"))
            {
                return notify_fail("你还没有抄写完宫规，不许离开！\n");
            }
        }
    }
	return ::valid_leave(me, dir);
}
