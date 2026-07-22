//Cracked by Roath
//yugan.c
#include <ansi.h>
inherit ITEM;
void create()
{
set_name("鱼竿", ({"yu gan"}));
set_weight(1000);
set("unit", "把");
set("value", 50);
set("material", "wood");
set("wield_msg", "$N把$n握在手中．\n");
setup();
}

void init()
{
add_action("do_fish", "fish");        
}

int do_fish()
{
object me=this_player();
string env;
if( me->query("fish") )
        return notify_fail("你现在不正在钓吗？\n");
if ( time() - me->query("last_fish") < 6 )
        return notify_fail("我看你还是过会再来钓吧。\n");
if(me->is_busy())
        return notify_fail("你正忙着呢！\n");
if(base_name(environment(environment()))!="/d/jz/sgate" )
        return notify_fail("这位客官是不是头脑发热？\n");
if((int)me->query("kee") <80)
        return notify_fail("你现在精神状况不好，是钓不上来鱼的！\n");
me->set("fish");
message_vision( CYN "$N穿好鱼饵，用力一甩，把钩子甩到了河中间。\n" NOR, me);
me->start_busy(5);
remove_call_out("zhai1");
call_out("zhai1",1,me);
remove_call_out("zhai2");
call_out("zhai2",3+random(2),me);
remove_call_out("finish_zhai");
call_out("finish_zhai",5,me);
return 1;
}

void zhai1(object me)
{
message_vision( GRN "$N盯着鱼浮，但是它好象根本就没有动过。\n"NOR, me);
}

void zhai2(object me)
{
message_vision( YEL "$N看到鱼浮好象动了一下，仔细看！有鱼上钩了！\n", me); 
}

void finish_zhai(object me)
{
object ob;    
if ( random(3) == 1) 
        {
        tell_object(me,"真倒霉，你什么也没有钓上来。\n");
        return;  
        }
switch(random(30)) 
        {
        case 0 :
        case 1 :
        case 29:
        case 28:
                ob = new("/d/jz/obj/fish3");
                break;
        case 5 :
        case 10:
        case 15:
        case 20:
        case 25:
                ob = new("/d/jz/obj/fish2");            
                break;
        default:
                ob = new("/d/jz/obj/fish2");            
        }   
if ( ob && ob->move(me) )
        tell_object(me,"你钓上了一条" + ob->query("name") +"。\n");
else    tell_object(me,"你什么也没钓到。\n");   
me->delete("fish");
me->set("last_fish",time());
}             
