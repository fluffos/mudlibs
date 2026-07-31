//modified by vikee
//2000.12.11
inherit F_CLEAN_UP;

int cast(object me)
{
int time,i,k,flag=0;
object *inv,target; 
return notify_fail("暂未开放。\n");    
if( !me->is_fighting() )
        return notify_fail("你只有在战斗中才能使用复活术。\n");
if(me->query("family/family_name")!="阎罗地府")
        return notify_fail("你不是地府弟子，不能使用这项技能！\n"); 
inv = all_inventory(environment(me));
k = me->query_skill("gouhunshu",1);
time/= 3;
if ( time<15 ) time = 15;
k/= 150;
if ( k>5 ) k = 5;
if ( k<sizeof(inv) ) k = sizeof(inv);
if( (int)me->query("mana")<100*k ) 
        return notify_fail("你的法力不够！\n");
message_vision("$N口中喃喃念了几句咒语，",me);
for(i=0;i<k;i++)
        {
        if ( inv[i]->is_corpse() )
                {
                message_vision("$n抽搐了几下竟站了起来！\n",me,inv[i]); 
                inv[i]->animate(me,time);
                me->add("mana",-100);
                flag++;
                }       
        }
if ( flag<=0 )
        message_vision("结果什么反应也没有。\n",me);
return 8;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        法术名称：复活术
        法术所属：勾 魂 术
        法术效果：战斗中复活在场的尸体，使之帮助战斗
                  冷却 8 秒
        法术条件：
                  每复活一个尸体消耗法力100点
LONG;
me->start_more(str);
return 1;
}       
