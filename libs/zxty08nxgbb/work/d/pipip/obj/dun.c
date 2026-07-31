#include <mudlib.h>
#include <command.h>
#define NULL_VALUE 0
inherit F_SAVE;
inherit F_DAMAGE;

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

inherit F_AUTOLOAD;
int query_autoload() { return 1; }

void create()
{
       seteuid(getuid());
       set("long",@LONG
               天鬼恶魔盾
※※※※※※※※※※※※※※※※※※※※※※※※※※
※命令名  ※    用  法      ※Note & description  ※
※※※※※※※※※※※※※※※※※※※※※※※※※※
※fill    ※fill <id>       ※用来恢复某人的精气  ※
※whereis ※whereis or<id>  ※列出所有线上人的位置※
※pk      ※pk<ob> with <id>※让某人杀某人        ※
※da      ※da<ob> with <id>※让某人打某人        ※
※xing    ※xing <id>       ※让某人苏醒          ※
※yun     ※yun  <id>       ※让某人晕倒          ※
※feng    ※feng <id>       ※封冻某人            ※
※jiefeng ※jiefeng <id>    ※解封某人            ※
※※※※※※※※※※※※※※※※※※※※※※※※※※
LONG
       );
       set("unit","面");
       set("no_get",1);
       set("material", "cloth");
       set("armor_prop/armor", 500);
       set("light",1);
       set("wear_msg", HIW""BLK "$N拿出一块散发着阵阵黑气的大盾持在手中。\n" NOR);
       set("unequip_msg",  HIW""BLK"$N把一块散发着阵阵黑气的大盾背回了背上。\n" NOR);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(HIW""BLK "天鬼恶魔盾" NOR, ({ "dun"}));
       if (this_player()->query("id") == "pipip") {
       add_action("full","fill"); 
       add_action ("whereis", "whereis"); 
       add_action ("pk_mob", "pk");       
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_disable_player","feng");
       add_action ("do_enable_player","jiefeng");
       add_action ("do_yao","yao");
       add_action ("do_da","da");
       this_player()->set_temp("heat",1);}
}

int whereis(string arg)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("魔鬼说到：“在网上好象没这个人呀！”\n");
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
       if (!me) return notify_fail ("魔鬼说道：对象错误: 找不到"+str+"\n");
       }
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_jingli");
  me->set("jingli",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_neili");
  me->set("eff_neili",max);
  me->set("neili",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
  message_vision( HIW""BLK"$N仰天狂叫：“地鬼天魔，永生不灭。”\n"NOR,
                  this_player());

  return 1;
}
int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("魔鬼说：你想让谁 PK 谁啊\n");
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

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("魔鬼说道：“ 没有"+str+"”\n");
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

  if (!str) return notify_fail ("魔鬼说：你不能把你自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("魔鬼说道：“ 没有"+str+"”\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
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
tell_object(ob,"有人在你耳旁说道：“波偌波偌密”，你又恢复了...\n");
  write("Ok.\n");
  return 1;
}
int do_yao(string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao 多少钱 钱币种类\n注：你首先必须有这种钱！");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("魔鬼说：你分文没有，摇个屁呀！\n");
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
int do_da(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("魔鬼说：你想让谁揍谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
         return notify_fail ("mobpk ob1 with ob2\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");

       message_vision(HIW ""+ob1->name()+"对着"+ob2->name()+"大叫道：照打，我早就想揍你一顿了。\n" NOR,
       this_player());
               ob1->fight_ob(ob2);
              return 1;
}


