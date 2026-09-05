/*
  易容工具的标准处理函数集
*/
#include <ansi.h>

//给自己化妆的函数，化妆会导致容貌有浮动，但是不会显著影响整体对外形象
//引入属性dress_level，设定该属性则判断易容术等级，否则调用默认的valid_disguise函数
//引入属性dress_effect，表明化妆的效果范围，化妆范围为[-dress_effect/2,dress_effect/2]
int dress_me(object owner)
{
  object ob=this_object();
  int rand_per, pre_per, base_dress;
  
  base_dress=ob->query("dress_effect");
  if ( (!ob->query("dress_level") &&
        !DISGUISE_D->valid_disguise(ob, owner)) ||
       (ob->query("dress_level") &&
        owner->query_skill("disguise",1)<ob->query("dress_level")) ) 
  {
    message_vision("$N伪装技能不足，无法使用"+ob->name()+"对自己进行化妆。\n",owner);
    return 0;
  }
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( !ob->query_amount() && 
      ob->query("used_times")>=6 )
  {
    write("工具包中有些材料使用光了，无法进行化妆了。\n");
    destruct(ob);
    return 0;
  }
  
  if(owner->query("jing")<=100)
  {
    write("你的精神不足，无法专心进行化妆。\n");
    return 0;
  }
  
  if(owner->query_temp("dress/personality"))
  {
    tell_object(owner, "你先清洗掉已有的化妆效果以后再重新进行化妆。\n");
    return 0;
  }

  rand_per=random(base_dress)-base_dress/2;
  if ( rand_per>0 )
    write("你用工具包对自己画了画妆，掩饰了自己脸上的一些小缺陷。\n");
  else if ( !rand_per )
    write("你用工具包对自己的脸上涂涂抹抹费了很大的力气，发现一点变化也没有。\n");
  else
    write("你用工具包对自己很随意地进行化妆，似乎比以前还不如。\n");

  owner->add_temp("apply/personality", rand_per);
  owner->set_temp("dress/personality", rand_per);
  owner->add("jing", -100);
  if ( !ob->query_amount() )
  {
    ob->add("used_times",1);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-1);
  }
  return 1;
}

//给别人化妆的函数，化妆会导致容貌有浮动，但是不会显著影响整体对外形象
//引入属性dress_level，设定该属性则判断易容术等级，否则调用默认的valid_disguise函数
//引入属性dress_effect，表明化妆的效果范围，化妆范围为[-dress_effect/2,dress_effect/2]
int dress_target(object owner, object target)
{
  object ob=this_object(), *team;
  int rand_per, pre_per, base_dress;
  
  base_dress=ob->query("dress_effect");  
  if ( (!ob->query("dress_level") &&
        !DISGUISE_D->valid_disguise(ob, owner)) ||
       (ob->query("dress_level") &&
        owner->query_skill("disguise",1)<ob->query("dress_level")) ) 
  {
    message_vision("$N伪装技能不足，无法使用"+ob->name()+"对自己进行化妆。\n",owner);
    return 0;
  }
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( !ob->query_amount() && 
      ob->query("used_times")>=6 )
  {
    write("工具包中有些材料使用光了，无法进行化妆了。\n");
    destruct(ob);
    return 0;
  }
  
  if(owner->query("jing")<=200)
  {
    write("你的精神不足，无法专心进行化妆。\n");
    return 0;
  }
  
  if( !target ||
      environment(target)!=environment(owner) )
  {
    tell_object(owner, "你要化妆的对象不存在或者和你不在一个房间。\n");
    return 0;
  }
  
  team=owner->query_team();
  if ( !arrayp(team) ||
       sizeof(team)<2 ||
       member_array(target, team)<0 )
  {
    tell_object(owner, "你要化妆的对象和你必须在一个队伍中。\n");
    return 0;
  }
  
  if(target->query_temp("dress/personality"))
  {
    tell_object(owner, target->name()+"必须清洗掉已有的化妆效果以后才能重新进行化妆。\n");
    return 0;
  }

  rand_per=random(base_dress)-base_dress/2;
  if ( rand_per>0 )
    message_vision("$N用工具包对$n画了画妆，掩饰了$n脸上的一些小缺陷。\n", owner, target);
  else if ( !rand_per )
    message_vision("$N用工具包对$n的脸上涂涂抹抹费了很大的力气，发现一点变化也没有。\n", owner, target);
  else
    message_vision("$N用工具包对$n很随意地进行化妆，似乎比以前还不如。\n", owner, target);

  target->add_temp("apply/personality", rand_per);
  target->set_temp("dress/personality", rand_per);
  target->add("jing", -200);
  if ( !ob->query_amount() )
  {
    ob->add("used_times",1);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-1);
  }
  return 1;
}

//临摹他人的形象作为伪装的素材
//输入参数：paint_level=0，仅能临摹NPC
//          paint_level=1，可以临摹玩家
int paint_face(object me, object target, int paint_level)
{
  object ob=this_object();
  
  if ( !target->is_character() || 
       (!paint_level && userp(target) ) ||
       target->query("race")!="人类"  )
  {
    if ( !paint_level )
      tell_object(me, "临摹对象仅限定于NPC。\n");
    else
      tell_object(me, "临摹对象仅限定于NPC或者玩家。\n");
    return 0;
  }
  
  if ( !DISGUISE_D->valid_disguise(ob, me) ) 
  {
    message_vision("$N伪装技能不足，无法使用"+ob->name()+"将别人临摹下来。\n", me);
    return 0;
  }
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( !ob->query_amount() && 
      ob->query("used_times")>=6 )
  {
    write("工具包中有些材料使用光了，无法进行临摹了。\n");
    destruct(ob);
    return 0;
  }
  
  if(me->query("jing")<=100)
  {
    write("你的精神不足，无法专心进行临摹。\n");
    return 0;
  }
  
  if( ob->query("paint") )
  {
    write("你发现工具箱里面已经保存了一幅临摹好的头像，无法再进行临摹了。\n");
    return 0;
  }
  
  if( target->query("combat_exp")*2/3>=me->query("combat_exp") ||
      target->query_skill("dodge")*2/3>=me->query_skill("dodge") )
  {
    tell_object(me, "你拿起笔正要临摹"+target->query("name")+"就被发现了。\n");
    return 0;
  }
  
  ob->set("paint/name", target->query("name"));
  ob->set("paint/id", target->query("id"));
  ob->set("paint/long", target->query("long"));
  ob->set("paint/age", target->query("age"));
  ob->set("paint/shen", target->query("shen"));
  ob->set("paint/class", target->query("class"));
  ob->set("paint/gender", target->query("gender"));
  if ( !target->query("title") )
    ob->set("paint/title", NOR);
  else
    ob->set("paint/title", target->query("title"));
  ob->set("paint/family", target->query("family/family_name"));
  if ( userp(target) )
  	ob->set("paint/userflag", 1);
  else
  	ob->set("paint/userflag", 0);
  tell_object(me, "你偷偷的将"+target->query("name")+"的形象临摹了下来存放到工具箱中，可以用它进行伪装了。\n");
  me->add("jing", -100);
  if ( !ob->query_amount() )
  {
    ob->add("used_times",1);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-1);
  }
  
  return 1;
}

//给自己伪装的函数，伪装前必须使用paint_face函数临摹下一个头像
//mask_id为伪装代码，代表不同类型的伪装
int disguise_me(object me, string mask_id)
{
  object ob=this_object();
  mapping mask;
  int complex;
  
  if ( !DISGUISE_D->valid_disguise(ob, me) ) 
  {
    message_vision("$N伪装技能不足，无法使用"+ob->name()+"进行伪装。\n", me);
    return 0;
  }
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( !ob->query_amount() && 
      ob->query("used_times")>=6 )
  {
    write("工具包中有些材料使用光了，无法进行伪装了。\n");
    destruct(ob);
    return 0;
  }
  
  if(me->query("jing")<=100)
  {
    write("你的精神不足，无法专心进行伪装。\n");
    return 0;
  }
  
  if( !ob->query("paint") )
  {
    write("你没有临摹下来任何人的头像，也就无法进行伪装。\n");
    return 0;
  }
  
  if ( me->is_busy() )
  {
    write("你现在正忙着。\n");
    return 0;
  }
  
  if ( me->is_mask() )
    mask=me->check_mask(0);

  if( mask &&
      (mask["mask"]==mask_id ||
       mask["mask"]=="mask") )
  {
    message_vision("无法在目前的伪装基础上再多画一重妆。\n",me);
    return 0;
  }
  
  complex=DISGUISE_D->query_complex(ob, me);
//复杂度越高伪装效果越好
  if( complex<180 )
  {
    message_vision("$N对照临摹到的头像悄悄修改自己的容貌，发现和画像中的人物居然一模一样。\n",me);
    me->set_face(mask_id, ob->query("paint/name"), 0, complex, 
                 (["long": ob->query("paint/long"),
                   "age": ob->query("paint/age")]));
  }
  else if ( complex<250 )
  {
    message_vision(HIC"$N对照临摹到的头像悄悄修改自己的容貌，发现和画像中的人物居然一模一样。\n"NOR,me);
    me->set_face(mask_id, ob->query("paint/name"), 0, complex,
                 (["long": ob->query("paint/long"),
                    "age": ob->query("paint/age"),
                    "title": ob->query("paint/title"),
                    "family": ob->query("paint/family")]));
  }
  else if ( complex<300 )
  {
    message_vision(HIY"$N对照临摹到的头像悄悄修改自己的容貌，发现和画像中的人物居然一模一样。\n"NOR,me);
    me->set_face(mask_id, ob->query("paint/name"), 0, complex,
                 (["long": ob->query("paint/long"),
                    "age": ob->query("paint/age"),
                    "title": ob->query("paint/title"),
                    "family": ob->query("paint/family"),
                    "gender": ob->query("paint/gender")]));
  }
  else
  {
    message_vision(HIM"$N对照临摹到的头像悄悄修改自己的容貌，并且一举一动都完全模仿了对方的行为。\n"NOR,me);
    me->set_face(mask_id, ob->query("paint/name"), ob->query("paint/userflag")?0:ob->query("paint/id"), complex,
                 (["long":ob->query("paint/long"),
                   "age":ob->query("paint/age"),
                   "title":ob->query("paint/title"),
                   "family":ob->query("paint/family"),
                   "gender":ob->query("paint/gender"),
                   "class":ob->query("paint/class"),
                   "shen":ob->query("paint/shen")]));
  }

  if ( complex > ob->query("min_level") &&
       complex <= ob->query("max_level") + ob->query("add_level") )
    DISGUISE_D->improve_disguise(0, complex, me);
  me->add("jing", -100);
  if ( !ob->query_amount() )
  {
    ob->add("used_times",1);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-1);
  }
  if ( objectp(ob) )
    ob->delete("paint");
  
  return 1;
}

//给别人伪装的函数，伪装前必须使用paint_face函数临摹下一个头像
//mask_id为伪装代码，代表不同类型的伪装
//disg_level是伪装级别，0-简单伪装 1-复杂伪装
int disguise_target(object me, object target, string mask_id, int disg_level)
{
  object ob=this_object(), *team;
  mapping mask;
  int complex;
  
  if ( !DISGUISE_D->valid_disguise(ob, me) ) 
  {
    message_vision("$N伪装技能不足，无法使用"+ob->name()+"进行伪装。\n", me);
    return 0;
  }
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( (!ob->query_amount() && 
       ob->query("used_times")>=5) ||
      ( ob->query_amount() &&
        ob->query_amount()<2 ) )
  {
    write("工具包中有些材料使用光了，无法进行伪装了。\n");
    destruct(ob);
    return 0;
  }
  
  if(me->query("jing")<=200)
  {
    write("你的精神不足，无法专心进行伪装。\n");
    return 0;
  }
  
  if( !ob->query("paint") )
  {
    write("你没有临摹下来任何人的头像，也就无法进行伪装。\n");
    return 0;
  }
  
  if ( me->is_busy() )
  {
    write("你现在正忙着。\n");
    return 0;
  }
  
  if( !target ||
      environment(target)!=environment(me) )
  {
    tell_object(me, "你要易容的对象不存在或者和你不在一个房间。\n");
    return 0;
  }
  
  team=me->query_team();
  if ( !arrayp(team) ||
       sizeof(team)<2 ||
       member_array(target, team)<0 )
  {
    tell_object(me, "你要易容的对象和你必须在一个队伍中。\n");
    return 0;
  }
  
  if ( !userp(target) )
  {
    write("只能给玩家进行易容。\n");
    return 0;
  }
  
  if ( !living(target) || 
       target->is_busy() )
  {
    write("对方似乎不适合进行易容啊。\n");
    return 0;
  }
  
  if ( target->is_mask() )
    mask=target->check_mask(0);

  if( mask &&
      (mask["mask"]==mask_id ||
       mask["mask"]=="mask") )
  {
    message_vision("无法在目前的伪装基础上再多画一重妆。\n",me);
    return 0;
  }
  
  complex=DISGUISE_D->query_complex(ob, me);
//复杂度越高伪装效果越好
  if( complex<180 || !disg_level )
  {
    message_vision("$N对照临摹到的头像悄悄修改$n的容貌。\n",me,target);
    target->set_face(mask_id, ob->query("paint/name"), 0, complex);
  }
  else if( complex<250 )
  {
    message_vision(HIC"$N对照临摹到的头像悄悄修改$n的容貌。\n",me,target);
    target->set_face(mask_id, ob->query("paint/name"), 0, complex, 
                 (["long": ob->query("paint/long"),
                   "age": ob->query("paint/age")]));
  }
  else if ( complex<300 )
  {
    message_vision(HIG"$N对照临摹到的头像悄悄修改$n的容貌。\n"NOR,me,target);
    target->set_face(mask_id, ob->query("paint/name"), 0, complex,
                 (["long": ob->query("paint/long"),
                    "age": ob->query("paint/age"),
                    "title": ob->query("paint/title"),
                    "family": ob->query("paint/family")]));
  }
  else if ( complex<400 )
  {
    message_vision(HIY"$N对照临摹到的头像悄悄修改$n的容貌。\n"NOR,me,target);
    target->set_face(mask_id, ob->query("paint/name"), 0, complex,
                 (["long": ob->query("paint/long"),
                    "age": ob->query("paint/age"),
                    "title": ob->query("paint/title"),
                    "family": ob->query("paint/family"),
                    "gender": ob->query("paint/gender")]));
  }
  else
  {
    message_vision("$N对照临摹到的头像悄悄修改$n的容貌。\n",me,target);
    target->set_face(mask_id, ob->query("paint/name"), ob->query("paint/userflag")?0:ob->query("paint/id"), complex,
                 (["long":ob->query("paint/long"),
                   "age":ob->query("paint/age"),
                   "title":ob->query("paint/title"),
                   "family":ob->query("paint/family"),
                   "gender":ob->query("paint/gender"),
                   "class":ob->query("paint/class"),
                   "shen":ob->query("paint/shen")]));
  }
  target->start_busy(10);
  me->start_busy(10);
  me->add("jing", -200);
  
  if ( !ob->query_amount() )
  {
    ob->add("used_times",2);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-2);
  }
  
  if ( objectp(ob) )
    ob->delete("paint");
  
  return 1;
}

//清楚脸部的所有化妆或者伪装效果
varargs int clean_face(object me, string mask_id, object target)
{
  object ob=this_object(), cln, *team;
  mapping mask;
  int dress;

  if ( objectp(target) )
  {
    if( environment(target)!=environment(me) )
    {
      tell_object(me, "你要卸妆的对象和你不在一个房间。\n");
      return 0;
    }
  
    team=me->query_team();
    if ( !arrayp(team) ||
         sizeof(team)<2 ||
         member_array(target, team)<0 )
    {
      tell_object(me, "你要卸妆的对象和你必须在一个队伍中。\n");
      return 0;
    }
    
    cln=target;
  }
  else
    cln=me;
  
  dress=cln->query_temp("dress/personality");
  
  //如果非COMBINED类易容工具，最多只能使用6次
  if( !ob->query_amount() && 
      ob->query("used_times")>=6 )
  {
    write("工具包中有些材料使用光了，无法进行卸妆了。\n");
    destruct(ob);
    return 0;
  }
  
  if ( cln->is_mask() )
    mask=cln->check_mask(0);

  if( ((mask &&
        mask["mask"]!=mask_id)||
       !mask) &&
      !dress )
  {
    message_vision("$N没有使用工具包进行伪装或者化妆也就无所谓卸妆了。\n",cln);
    return 0;
  }
  
  if ( dress )
  {
    cln->add_temp("apply/personality",-dress);
    cln->delete_temp("dress/personality");
  }

  if ( me==cln )
    message_vision("$N使用工具包将自己的化妆痕迹都清除了。\n",me);
  else
    message_vision("$N使用工具包将$n的化妆痕迹都清除了。\n",me, cln);

  if ( mask &&
       mask["mask"]==mask_id  )
    cln->uncover_mask();
    
  if ( !ob->query_amount() )
  {
    ob->add("used_times",1);
    ob->set("value",0);
  }
  else if ( ob->query_amount()>0 )
  {
    ob->add_amount(-1);
  }
  return 1;
}