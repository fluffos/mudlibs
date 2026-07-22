#include <ansi.h>
inherit ITEM;

#define RUMORCENTER "/d/wiz/rumorcenter"

object room;

void create()
{
set_name("水晶球", ({"shuijing qiu","crystal","ball","qiu"}));
set_weight(200);
set("unit", "只");
set("long", "一只鎏光四溢的水晶球。(detect)\n");
set("no_drop",1);
set("no_get",1);
set("no_give",1);
set("value", 10000);
setup();
room=load_object(RUMORCENTER);
set("room",room);
}

void init() 
{
add_action("do_detect","detect");
}


int do_detect(string arg)
{
mapping rumor;
int number;
object ob,me = this_player();
ob = this_object();

if (! arg || sscanf(arg, "%d", number)!=1) 
        return notify_fail("用法：detect(1-10) \n");
if (number<1 || number>10) 
        return notify_fail("用法错误！\n");
if ( !present(ob,me) )
        return 0;
if (!room) 
        {
        set("value",0);
        write("这只水晶球已经失去神力了。\n");    
        write("水晶球化成一滩清水流了一地。\n");
        destruct(this_object());
        return 1;
        }
if ( me->query("mana")<100 )
        return notify_fail("你的法力不够，无法与水晶球沟通。\n");
if ( !me->pay_money(10000) )
        {
        if ( me->query("balance")<10000 )
                return notify_fail("你钱庄的钱财不够1两黄金。\n");
        me->add("balance",-10000);
        tell_object(me,"你使用"+name()+"花费了一两黄金，已从你钱庄的帐户上自动扣除。\n");
        me->save();
        }
else    tell_object(me,"你花费一两黄金使用了"+name()+"。\n");
                
rumor=room->reveal(number);
set("rumor",rumor);
me->add("mana",-10);
message_vision(HIG"$N捧着水晶球，口中喃喃自语。\n"NOR,me);
  
if (!rumor) 
        {
        tell_object(me,"可是什么也没有发生。\n");
        return 1;
        }
tell_object(me,CYN"你请教水晶球：刚才「"+rumor["body"]+"」是谁说的？\n"NOR);
if (!rumor["disclose"])
        tell_object(me,HIB"水晶球回答你：天机不可泄露。\n"NOR);
else    {
        tell_object(me,MAG"水晶球缓缓的转动着，你仿佛从中看到了一个身影。\n"); 
        tell_object(me,HIR"人影越来越清晰，你仔细一看，原来是"HIW+rumor["name"]+HIR"("+rumor["id"]+")！\n"NOR);
        }
return 1;
} 

