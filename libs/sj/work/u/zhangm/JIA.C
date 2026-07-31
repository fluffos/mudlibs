#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;

string inputstr,verb;

void create()
{
       seteuid(getuid());
       set("long",@LONG
               飞花落叶甲
※※※※※※※※※※※※※※※※※※※※※※※※※※
※命令名 ※    用  法       ※Note & description  ※
== 未完继续 4% == (ENTER 继续下一页，q 离开，b 前一页)
※※※※※※※※※※※※※※※※※※※※※※※※※※
※fill  ※fill <id>        ※用来恢复某人的精气   ※
※nofill※nofill <id>      ※吸收某人的精气       ※
※yao   ※yao<genre><value>※只要身上有一点钱就可 ※
※      ※                 ※以变你想要的数量的钱 ※     
※※※※※※※※※※※※※※※※※※※※※※※※※※
※whereis ※whereis or<id>  ※列出所有线上人的位置※
※pk      ※pk<ob> with <id>※让某人杀某人        ※
※chuqiao ※chuqiao <id>    ※放剑杀某人          ※
※xing    ※xing <id>       ※让某人苏醒          ※
※yun     ※yun  <id>       ※让某人晕倒          ※
※qshs    ※qshs <id>       ※起死回生(恢复原武功)※
※feng    ※feng <id>       ※封冻某人            ※
※jiefeng ※jiefeng <id>    ※解封某人            ※
※gan     ※gan <id>        ※赶某人下线！        ※
※superdie※superdie        ※让所有线上人死亡××※
※quanjia ※quanjia <id>    ※让某人不再打架！    ※
※jizhu   ※jizhu<id>with<id>※pk id with id      ※ 
※ban     ※ban <id> <msg>  ※装扮某人说话。！    ※
※待续......                                      ※
LONG
       );
       set("unit","件");
       set("no_get",1);
       set("material", "cloth");
       set("armor_prop/armor", 300);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(HIY "飞花落叶甲" NOR, ({ "jia", "ander" }));
       add_action("do_change","change"); 
       add_action("full","fill"); 
       add_action("hun","nofill");
       add_action("wave","yao");  
       add_action ("whereis", "whereis"); 
       add_action ("pk_mob", "pk");       
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_die","chuqiao");
        add_action ("do_reincarnate","qshs");
       add_action ("do_disable_player","feng");
        add_action ("do_enable_player","jiefeng");
        add_action ("super_die","superdie");
       add_action ("do_gan","gan");
       add_action ("do_halt","quanjia");
       add_action ("do_killer","jizhu");
       add_action ("do_ban","ban");
       this_player()->set_temp("heat",1);
}

int do_change(string arg)
{
  object fd,me;
  me=this_player();
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("在网上好象没这个人呀！\n");
    }
  if (arg) {
    if(arg=="comm") return notify_fail("想死啊！\n");
    if(fd->query("gender")=="女性") fd->set( "gender", "男性" );
    else fd->set( "gender", "女性" );
    message("shout", HIC "【传言】：" + HIG + "听说" + me->query("name") + "成功的对" 
       + fd->query("name") + "进行了一次变性手术。\n" NOR,users());
    fd->save();
    write(HIC"手术完成了！\n"NOR);
    return 1;
  }
}

int whereis(string arg)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("飞叶说到：“在网上好象没这个人呀！”\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虚无飘藐间。\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

       if (!geteuid()) seteuid (getuid());
       if(!str)
       me=this_player();
       else   {
       me = LOGIN_D->find_body(str);
       if (!me) return notify_fail ("飞叶说道：对象错误: 找不到"+str+"\n");
       }
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_shen");
  me->set("eff_shen",max);
  me->set("shen",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
  message_vision( sprintf("$N对着天空大喊：永远不死。\n"),
                  this_player());

  return 1;
}
int hun(string str)
{
  int min;
  object me;

  if (!geteuid()) seteuid (getuid()); 
  me = LOGIN_D->find_body(str);
  if(!str)
    return notify_fail ("飞叶说：你想吸自己的血？不好吧？");
  else
    if (!me) return notify_fail ("飞叶说: 吸血对象错误: 找不到"+str+"\n");
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);
  min = me->query("min_jing");
  me->set("eff_jing",min);
  me->set("jing",min);
  min = me->query("min_qi");
  me->set("eff_qi",min);
  me->set("qi",min);
  min = me->query("min_shen");
  me->set("eff_shen",min);
  me->set("shen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);  
  me->clear_condition();
  message_vision( sprintf("$N对着身旁一个人扑了过去，顿时，那人全身没力了...\n"),
                  this_player());

  return 1;

}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <多少钱> <钱币种类>\n注：你首先必须有这种钱！");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("飞叶说：你分文没有，摇个屁呀！\n");
        if( amount < 1 )
                return notify_fail("呵呵，还是没有。\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf(HIY "$N使劲的掏别人的口袋，突然从袋子里掏出%s%s%s。\n" NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("孙老爷说：你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");

       message_vision(HIR ""+ob1->name()+"对着"+ob2->name()+"大喝一声：「拿命来」。\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (str!=NULL_VALUE) return notify_fail("usage:gei <id>\n");
  me = this_player();
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
     return 0;
  wiz = wizhood (me);
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 1)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("飞叶说：“我看还是别给他吧！”\n");
    return 1;
  }

  ob = present ("wiz cloak", me);
  if (!ob) write ("你没有这样东西。\n");
  who = find_player(whos);
  if (!who) write ("没有这个人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision (HIY "$N给$n一件绝世宝贝－「飞花落叶甲」。\n" NOR, me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("飞叶说道：“ 没有"+str+"”\n");
  }
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("飞叶说：你不能把你自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("飞叶说道：“ 没有"+str+"”\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  write("Ok.\n");
  return 1;
}

int do_die (string str)
{
  object ob;
  if (!str) return notify_fail("usage: chuqiao <oneself id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("没法出鞘，没这个人。\n");
  message_vision( sprintf(HIY "只见$N用手对着天空一指，大叫：“宝剑出鞘”，\n一把巨剑从$N身后的剑鞘里飞出，直冲云霄...\n" NOR),
         this_player());
  tell_room(environment(ob),"天空中忽然出现了一把巨大的宝剑，直向站在那边的"+                    
       (string)ob->query("name")+"射去。\n" , ob);
  tell_object(ob,"你忽然发现天空中一把闪闪发光的巨大宝剑向你射来..\n 你两眼一黑...");  
  ob->die();
  message_vision( sprintf( HIY "只见$N用手对着天空一指，大叫：“宝剑回鞘”，\n一把巨剑从天空中回到了$N身后的剑鞘里。\n" NOR),
         this_player());
  write("Ok.\n");
  return 1;
}

int do_reincarnate (string str)
{
  object ob;
  if (!str) return notify_fail("usage: qshs <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"对你进行全身检查中...\n");
       else 
           return notify_fail("咦...这个人好象是活的！\n");
  tell_object(ob,"检查完毕！你是鬼!需要让你复活！且保留上次的一切。\n");
  tell_room(environment(ob),"一道金光突然从天际射下，笼罩在"+
       (string)ob->query("name")+"的周围。\n", ob);
  tell_object(ob,"突然一个声音在你儿边响起，“复活吧....，从现在\n开始你再不是魂鬼了”，你突然感到一阵昏厥...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"很好！你又复活了！\n");
  write("Ok.\n");
  return 1;    
}

int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  tell_object(ob,"突然你的眼睛一片模糊...\n");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "<瞎眼中>" NOR);      
  write("Ok.\n");
  return 1;    
}

int do_enable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"有人在你儿旁说道：“波偌波偌密”，你又恢复了...\n");
  write("Ok.\n");
  return 1;
}

int do_gan (string str)
{
  object ob;
  seteuid(ROOT_UID);
  if (!str) return notify_fail("usage: gan <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("没找到这个人。\n");     
  if (ob->query("name")=="飞叶") {
       tell_object(ob,this_player()->query("id") + "这个痴呆要把你敢走！\n");
       return notify_fail(HIY "你连飞叶都想赶走？\n" NOR);   
       }  
  tell_object(ob,"「飞花落叶甲」告诉你：实在不好意思，请你下线去吧...\n");
  destruct(ob);
  if(ob) write("你无法将这个人赶走。\n");
        else write("Ok.\n");
  return 1;    
}

void super_die ()
{
//       if ( this_player()->query("name")!="飞叶" );
//       CHANNEL_D->do_channel( this_object(),"rumor",
//       sprintf(HIY "有人亲眼看见" + this_player()->query("name") + "用飞叶的宝贝杀了所有的人。" + NOR));
//  return notify_fail("危险功能！暂时不开放！\n");
//       users()->die();
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail("usage: quanjia <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("线上无此人！\n");       
  if( !ob->is_fighting() )
       return notify_fail("那人现在并没有打斗中。\n");        
  tell_room(environment(ob),HIY "天空中忽然出现了飞叶的身影。\n他和蔼的对"+                    
       (string)ob->query("name")+"说到：“得饶人处且饶人，我看这位"+RANK_D->query_respect(ob)+"还是算了吧！”\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIC "嗯！"+                    
       (string)ob->query("name")+"说到：“您说的对，我不想再打了。”\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"终于受到感召，决定不斗了！\n", ob);
  return 1;    
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("飞叶说：你想让谁和谁结仇啊?\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("jizhu <ob1> with <ob2>\n");
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail("找不到 "+st1+" 这个生物.\n");


        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail("找不到 "+st2+" 这个生物.\n");
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(HIC "飞叶说道：“嘻嘻！”\n" NOR);
       return 1;
}

int do_ban(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail ("你要装扮谁来说话？\n");
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail ("ban <id> say <message>\n");
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail("这里好象没有"+st1+"吧。\n");
       message("sound", HIG + ob1->name() + "说道：" + HIG +  st2 + "\n" NOR,
       environment(ob1), ob1);
       return 1;

}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

