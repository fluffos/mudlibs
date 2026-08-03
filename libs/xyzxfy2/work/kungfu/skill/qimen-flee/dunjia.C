// drift_sense.c
#include <ansi.h>
//inherit SSERVER;
int conjure(object me, object target)
{
        object ob,*obj;
        int i;
    if (me->is_fighting())
         return notify_fail("战斗中你没有时间御剑飞行,呵呵！\n");
		if (me->query_skill("taoism",1)<800||
				me->query_skill("qimen-flee",1)<300||
				me->query_skill("buddhism",1)<650)
				return notify_fail("你的修为不够，无法使用神通！\n");
    if (present("biao yin",me)) return notify_fail("你身上带着镖银，无法使用神通！\n");
      if (present("xin",me)) return notify_fail("你身上带着信件，无法使用神通！\n");

     obj=deep_inventory(me);
     for (i=0;i<sizeof(obj);i++)
           if (obj[i]->id("illicit salt"))
         return notify_fail("你身上带着私盐，无法使用神通！\n");
if (file_name(environment(me))=="/d/city/jianyu")
return notify_fail("监狱里无法使用神通！\n");

    ob=first_inventory(me);
    while(ob){
        if (ob->is_character() && !ob->is_corpse() )
            return notify_fail(ob->name()+"不能和你一起御剑飞行！\n");
        ob=next_inventory(ob);
    }
if(me->query_condition("killer"))
return notify_fail("你正在逃命,哪有精力御剑飞行！\n");
    if( me->query("jing") < 30 || me->query("jingli") < 75 )
        return notify_fail("你的精力不够！\n");
    if( target )
        return notify_fail("奇门遁术只能自己使用！\n");
write("你要飞遁到哪一个人身边？？\n");
    input_to( (: call_other, __FILE__, "select_target", me :));
    return 1;
}
void select_target(object me, string name)
{
    object ob;
mapping exits;
    if( !name || name=="" ) {
        write("中止施法。\n");
        return;
    }
    ob = find_player(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
        ob = find_living(name);
    if( !ob || !me->visible(ob) || !living(ob) || wizardp(ob) ) {
        write("你无法感受到这个人的精力 ....\n");
        return;
    }
  if(random(me->query("jing"))<30 || random(me->query("jingli"))<20)
  {write("你无法感觉到对方的存在\n");return;}
  if (me->query("quest/quest_type")=="杀"
    && (string)me->query("quest/quest")==ob->short()
       && me->query("quest/task_time")<time())
    {
        write("你无法感受到这个人的精力 ....\n");
        return;
     }
   if(ob->query("id")=="salt seller")
  {write("你无法感受到这个人的精力 ....\n");return;}

    if( me->is_fighting() ) {
        write("战斗中你没有时间御剑飞行,呵呵！\n");
        return;
    } else if( me->query("jingli") < 75 ) {
        write("现在你的精神状态不太好，歇会吧！\n");
        return;
    }
    me->add("jingli", -75);
    me->receive_damage("jing", 30);
    
    if( time() - me->query_temp("do_flee")<2) {
        message_vision( HIY "$N手捏剑诀，漫天飘起七彩花瓣一道剑光望空而去 ....\n" NOR, me);
        write("一股强大的煞气将你挡了回来.......！\n");
            message( "vision",HIY+me->name()+"纵升半空，一股强大的力量把"+me->name()+"强扯回地面，"+me->name()+"只觉脑中一片茫然！
\n" NOR, environment(me),({me}));
        return;
    }
     me->set_temp("do_flee",time());
    if( !environment(ob) ||
     environment(ob)->query("no_magic") || random(me->query_skill("qimen-flee",1)) < 30 ) {
        write("一股强大的煞气将你挡了回来.......！\n");
            message( "vision",HIY+me->name()+"纵升半空，一股强大的力量把"+me->name()+"强扯回地面，"+me->name()+"只觉脑中一片茫然！\n" NOR, environment(me),({me}));
        return;
    }
exits=environment(ob)->query("exits");
if (!mapp(exits) || !sizeof(exits) )
{
write("你撞到一堵石墙，不得不退了回来！\n");
message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地从洞里又钻了回来。\n" NOR, environment(me),({me}));
return;
}
  if ( domain_file(base_name(environment(ob)))=="shaolin"
    || domain_file(base_name(environment(ob)))=="wudujiao" 
    || domain_file(base_name(environment(ob)))=="shenlong" 
    || domain_file(base_name(environment(ob)))=="huashan"
    || domain_file(base_name(environment(ob)))=="quanzhen" 
    || domain_file(base_name(environment(ob)))=="death" ){
     write("一股强大的煞气将你挡了回来.......！\n");
            message( "vision",HIY+me->name()+"纵升半空，一股强大的力量把"+me->name()+"强扯回地面，"+me->name()+"只觉脑中一片茫然！\n" NOR, environment(me),({me}));
        return;
    }
  if ( domain_file(base_name(environment(ob)))=="player" ){
     write("那里是人家的家里，你想做贼吗？\n");
            message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }
if ( domain_file(base_name(environment(ob)))=="flypproom" ){
write("那里是人家的家里，你想做贼吗？\n");
message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
return;
}
  if ( domain_file(base_name(environment(ob)))=="party" ){
     write("那里是人家的家里，你想做贼吗？\n");
            message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }
  if ( domain_file(base_name(environment(ob)))=="kefang%d" ){
     write("那里是人家的睡觉的地方，你想做贼吗？\n");
            message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }
  if ( domain_file(base_name(environment(ob)))=="taohua" ){
     write("恭喜你，你掉进了大海里！\n");
            message( "vision",HIY+me->name()+"从口了吐出几口水大叫：好咸呀！\n" NOR, environment(me),({me}));
        return;
    }
if ( domain_file(base_name(environment(ob)))=="migong" ) {
write("那里太遥远了。\n");
message( 
"vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
return;
}
  if ( domain_file(base_name(environment(ob)))=="yihua" ){
     write("恭喜你，你掉进了茅坑里！\n");
            message( "vision",HIY+me->name()+"从口了吐出几口大粪大叫：好臭呀！好臭呀！\n" NOR, environment(me),({me}));
        return;
    }
    if ( domain_file(base_name(environment(ob)))=="xiakedao" ){
     write("恭喜你，你掉进了茅坑里！\n");
            message( "vision",HIY+me->name()+"从口了吐出几口大粪大叫：好臭呀！好臭呀！\n" NOR, environment(me),({me}));
        return;
    }

  if ( domain_file(base_name(environment(ob)))=="gaochang" ) {
     write("那里太遥远了。\n");
            message( 
 "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }

  if ( domain_file(base_name(environment(ob)))=="city3" ){
     write("那里太遥远了。\n");
            message( 
 "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }
  if ( domain_file(base_name(environment(ob)))=="changan" ){
     write("那里太遥远了。\n");
            message( 
 "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }

  if ( domain_file(base_name(environment(ob)))=="mingjiao" ){
     write("那里太遥远了。\n");
            message( 
 "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }



    if (!environment(ob) || wizardp(ob)){
            message_vision( HIY "$N手捏剑诀，漫天飘起七彩花瓣一道剑光望空而去 ....\n" NOR, me);
        write("你飞了半天，发现"+ob->name()+"似乎遥不可及 ....\n");
            message( "vision",HIY+me->name()+"一脸气急败坏，灰头灰脸地又飞了回来。\n" NOR, environment(me),({me}));
        return;
    }
message_vision( HIY "$N手捏剑诀道声 ∮=起=∮，漫天飘起七彩花瓣一道剑光望空而去 ....\n" NOR, me);
    if(file_size(file_name(environment(ob))+".c")<=0)
    {
     	write("但是，很快地你发现那里似乎并不存在，于是又灰头土脸地退了回来。\n");  	
     	return;
    }
    else me->move(environment(ob));
		message_vision( HIY "\n漫天飘起七彩花瓣，$N御行飞剑徐徐从空降了下来。\n\n" NOR, me);
        if (me->query_skill("taoism",1)>me->query_skill("qimen-flee",1))
        me->improve_skill("qimen-flee", random(me->query_skill("taoism")),0);
        else me->improve_skill("qimen-flee", random(me->query_skill("taoism")),1);
}

