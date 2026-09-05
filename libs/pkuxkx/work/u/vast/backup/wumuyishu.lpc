//武穆遗书
#include <ansi.h>
inherit ITEM;
// int do_study(string arj);

void create()
{
     	set_name(MAG "武穆遗书" NOR, ({ "wumu yishu", "yishu" }));
        set_weight(200);
        set("unit", "本");
	set("long", "这是岳飞生前的一本兵书，上面记载着岳飞带兵打仗时所用的兵法，是稀世珍宝.(你可以study yishu),你还可以参拜它(canbai)\n");
        set("value", 5000000);
        set("no_sell",1);
        set("no_drop",0);
        set("no_get",0);
        set("material", "paper");
       	set("userid","male");
    	set("canbai",0);
setup();
}

void init()
{
add_action("do_study","study");
add_action("do_canbai","canbai");
}
int do_canbai(string arg)
{
object me;
me=this_player();

if(arg!="yishu")
{
write(HIW"你想参拜什么？\n"NOR);
return 1;
}
if(me->is_busy())
{
write(HIW"你不是正忙着么？\n"NOR);
return 1;
}
if(me->query("neili")<0)
{
write(HIW"你体力太差，无法参拜！\n");
return 1;
}
if(me->query("shen")<10000000) me->add("shen",100);
if(me->query("neili")>=me->query("max_neili")&&me->query("max_neili")>5000)
{
	write(HIW"你面对武穆遗书，对岳王爷的敬畏之情油然而生，将遗书放在供位上参拜起来...\n"NOR);
 this_object()->add("canbai",1);
}
else
{
	write(HIW"你面对武穆遗书，将遗书放在供位上参拜起来，对岳王爷的敬畏之情油然而生...\n"NOR);
this_object()->set("canbai",0);
}
me->add("neili",-100);
if(this_object()->query("canbai")>20&&this_object()->query("userid")!=me->query("id")&&me->query("yishu"))
{
this_object()->set("userid",me->query("id"));
write(HIR"突然天空传来一个威严的声音：孺子可教！\n同时武穆遗书好像通了灵一样跃入你的手中！\n"NOR);
this_object()->set("canbai",0);
}
me->start_busy(1);
return 1;
}
int do_study(string arg)
    {
        object me;
me = this_player();
if(arg == "yishu"||arg=="wumu")
{
if( (int)me->query("shen")<-100000)
    {
            write("你正气太低,还是不看为妙!武穆遗书落到奸人之手将会后患无穷!\n");
                return 1;
}
if(this_object()->query("userid")!=me->query("id"))
{
  write("他人之物，读来何用？\n");
return 1;
}
if(me->is_busy())
{
write("你不是正在读么?待会吧!\n");
return 1;
}
if ( (int)me->query_int() < 80)
        {
                write("你悟性太差,难以看懂武穆遗书的含义。\n");
                return 1;
        }
if(!me->query("yishu"))
{
                write("没有劳动，哪来收成？老老实实挖墓吧！\n");
           return 1;
}
if ( (int)me->query_skill("force", 1) < 300)
        {
                write("你在基本内功方面的修为不够,武穆遗书对你没有用处!\n");
                return 1;
        }

if((int)me->query("jing")>100)
{
if(me->query("neili")<me->query("con")*15000*(100+random(100))/200)
{
me->add("jing",-200);
// me->start_busy(1);
write("你看了武穆遗书上的文字,不禁热血沸腾,感觉内力充盈! \n");
if(me->query("shen")>0)
{
me->add("neili",30+random(20));
}
else
{
me->add("neili",15+random(20));
}
}
else
{
write("你觉得你的内力蠢蠢欲动,身体好像轻盈了许多,结果你感觉你的你的内力有了较大的提高!\n");
me->set("neili",0);
me->add("max_neili",50);
}
}
else 
{
  write("你现在有些疲倦，无法专心下来研读新知. \n");
}
}
else
{
write("你要读什么?说清楚啊?\n");
}
 return 1;
}
