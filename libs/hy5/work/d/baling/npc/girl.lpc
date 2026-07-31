#include <ansi.h>
inherit NPC;
int do_kiss(string arg);
int do_sleep(string arg);
void create()
{
   set_name("桃红",({ "tao hong","tao","hong" }) );
        set("gender", "女性" );
        set("age", 22);
   set("long", "这是百花苑的姑娘桃红。\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("per", 28);
   set("attitude", "friendly");
   set("chat_chance",50);
   set("chat_msg",({
    "桃红微微笑道：谁喜欢我，可以亲亲（qin tao）我啊！\n",
    "桃红笑道：如果你够帅，我可以免费和你睡觉（shuijiao tao）的！\n",
   }));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
  add_action("do_kiss","qin");
  add_action("do_sleep","shuijiao");
}
//this is a joke. :-)
int do_kiss(string arg)
{
  object me,ob;string str;
  me=this_player();
  if(!arg)
  return notify_fail("你趴在地上，舔了桃红的脚一下。\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("恩，有这个人吗？！\n");
  if(ob!=this_object())
  return notify_fail("桃红喊道：嘿，你干什么呢？！\n");
  if(me->query("gender")=="女性")
  return notify_fail("桃红一笑：你找错对象了！\n");
  if(me->query("jing")<200)
  return notify_fail("桃红笑道：看你样子，没什么精神，等会吧！\n");
  if(me->is_busy())
  return notify_fail("桃红一笑：你还是歇歇吧，真是贪心啊！\n");
  if(me->is_fighting())
  return notify_fail("桃红往旁边一闪：你还是先打仗吧！\n");
  if(me->query_per()<10)
  return notify_fail("桃红一皱眉：你长得好恶心啊，离我远点！\n");
  if(me->query_per()<20)
  return notify_fail("桃红微微一皱眉：看你相貌，你还是走吧！\n");
  if(me->query_per()<26)
  str="桃红朝$N微微一笑："+RANK_D->query_respect(me)+",你好坏啊！";
  if(me->query_per()<31)
  str="桃红脸上微微一红，朝$N嗔道："+RANK_D->query_respect(me)+",你坏，你坏！\n";
  else str="桃红一脸红晕，羞答答地对$N说:能认识"+RANK_D->query_respect(me)+"这样的人，是我的福气。\n";
  message_vision(str,me);
  message_vision("$N侧过身来，$n在$N的脸上亲了一口。\n",ob,me);
  me->add("jing",-200);
  me->start_busy(2);
  return 1;
}

int do_sleep(string arg)
{
  object me,ob;string str;
  me=this_player();
  if(!arg)
  return notify_fail("你趴在地上，舔了桃红的脚一下。\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("恩，有这个人吗？！\n");
  if(ob!=this_object())
  return notify_fail("桃红喊道：嘿，你干什么呢？！\n");
  if(me->query("gender")=="女性")
  return notify_fail("桃红一笑：你找错对象了！\n");
  if(me->query("jing")<200||me->query("qi")<200)
  return notify_fail("桃红笑道：看你样子，没什么精神，等会吧！\n");
  if(me->is_busy())
  return notify_fail("桃红一笑：你还是歇歇吧，真是贪心啊！\n");
  if(me->is_fighting())
  return notify_fail("桃红往旁边一闪：你还是先打仗吧！\n");
  if(me->query_per()<10)
  return notify_fail("桃红一皱眉：你长得好恶心啊，离我远点！\n");
  if(me->query_per()<20)
  return notify_fail("桃红微微一皱眉：看你相貌，你还是走吧！\n");
  if(MONEY_D->player_pay(me,5000)==0||
     MONEY_D->player_pay(me,5000)==2)
     return notify_fail("没钱？没钱来干什么？滚吧！！\n");
  if(me->query_per()<26)
  str="桃红朝$N微微一笑："+RANK_D->query_respect(me)+",你好坏啊！";
  if(me->query_per()<31)
  str="桃红脸上微微一红，朝$N嗔道："+RANK_D->query_respect(me)+",你坏，你坏！\n";
  else str="桃红一脸红晕，羞答答地对$N说:能认识"+RANK_D->query_respect(me)+"这样的人，是我的福气。\n";
  message_vision(str,me);
  message_vision(CYN"$n拥抱着$N，给了$N一个深深的吻！\n"+
                "$N依偎在$n的怀里，眼中含情脉脉，脸上娇羞无限．\n"NOR,me,ob);
  call_out("step2",2,me,ob);
        return 1;
}

int step2(object me, object who)
{
        if(me->query("gender") == "男性" ) 
            message_vision(YEL"$N紧紧地抱住$n，两个人的心在一起跳动，感情在一起升温！！\n"NOR,me,who);
        else
            message_vision(YEL"$N紧紧地抱住$n，两个人的心在一起跳动，感情在一起升温！！\n"NOR,who,me);

        call_out("remove_cloth",1,me);
        call_out("remove_cloth",1,who);
        call_out("step3",3,me,who);
        return 1;
}

int step3(object me, object who)
{
        message_vision(MAG"$N和$n沉浸在幸福的海洋里＃＠＃％＆＆＊＆％￥＃\n"NOR,me,who);
        call_out("step4",2,me,who);
        return 1;
}

int step4(object me, object who)
{
        if(me->query_condition("xxx"))
                me->clear_condition("xxx");
        if(who->query_condition("xxx"))
                who->clear_condition("xxx");

        me->receive_damage("jing",me->query("max_jing")/2);
        me->receive_damage("qi",me->query("max_qi")/2);

        who->receive_damage("jing",who->query("max_jing")/2);
        who->receive_damage("qi",who->query("max_qi")/2);
       message_vision(HIW"终于一切又恢复了平静．\n"NOR,me,who);
       
        return 1;
}

int remove_cloth(object me)
{
        object *inv;
        string str;
        int i;
        // remove all staff before sleepping :P
        inv = all_inventory(me);
        for(i=0; i < sizeof(inv); i++ ) {
            if( inv[i]->query("equipped") == "worn" ) {
                if( inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("remove_msg")) )
                        switch(inv[i]->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N将$n脱了下来。\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N将$n从伤口处拆了下来。\n" NOR;
                                        break;
                                default:
                                        str = YEL "$N卸除$n的装备。\n" NOR;
                        }
                message_vision(str, me, inv[i]);
                }
            } else if ( inv[i]->query("equipped") == "wielded" ) {
                if(inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("unwield_msg") )) 
                        str = YEL "$N放下手中的$n。\n" NOR;
                message_vision(str, me, inv[i]);
                }
            }
        }
}
