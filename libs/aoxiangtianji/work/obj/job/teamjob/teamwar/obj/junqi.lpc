//战场军旗
#include <ansi.h>
inherit ITEM;

int do_camp();
int do_assign(string arg);
int do_sos();
int do_retreat(string arg);
int do_kaixuan();
int do_help(string arg);
int do_status();
void teamjob_reward();

void create()
{
  set_name("军令旗", ({"leader flag","junling flag", "flag"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "个");
    set("long", "一面军令旗．\n");
    set("no_sell", 1);
    set("drop_des", 1);
    set("no_give", 1);
    set("no_put", 1);
    set("start_time",time());
  }
}

void init()
{
  object env=environment();

  if(!clonep())
    return;

  if(!objectp(env) ||
     !playerp(env) ||
     !environment(env) ||
     !env->query_temp("teamwar/in_warfield") ||
     env != env->query_temp("teamwar/leader") ||
     env != query("leader") ||
     query("owner") != env->query("id"))
  {
    call_out("self_destroy",1);
    return;
  }

  add_action("do_camp",({"camp","zhaying"}));
  add_action("do_assign",({"assign","fenpai"}));
  add_action("do_sos",({"sos","qiujiu"}));
  add_action("do_retreat",({"retreat","chetui"}));
  add_action("do_help",({"help","bangzhu"}));
  add_action("do_kaixuan",({"kaixuan","success"}));
  add_action("do_status",({"status","chakan"}));
  return;
}

void self_destroy()
{
  object env;

  if (!this_object())
    return;

  env = environment();

  if(env)
  {
    if(env->is_character())
    {
      tell_object(env,"这令旗与你无用，兵马大元帅下令收回。\n");
    }
  }
  destruct(this_object());
  return;
}

object find_qob()
{
  object qob, *obs;

  if (! find_object(TEAMJOB_D))
    return 0;
  obs = children("/obj/quest/teamjob/teamwar");
  if (!arrayp(obs) || sizeof(obs) < 1)
    return 0;
  foreach (qob in obs)
  {
    if (qob->name() == "团队战争" && qob->query("live_time") > 1)
      break;
  }
  return qob;
}

object get_owner()
{
  object env = environment();

  if(!objectp(env) ||
     !playerp(env) ||
     !environment(env) ||
     !environment(env)->is_warfield() ||
     !env->query_temp("teamwar/in_warfield"))
    return 0;

  if (query("owner") != env->query("id") ||
      env != env->query_temp("teamwar/leader") ||
      env->query_temp("teamwar/failure") ||
      !find_qob())
    return 0;
  return env;
}

string conv_status(string arg)
{
  if (!stringp(arg))
    return "[等待扎营]";
  if (arg == "mass")
    return "[扎营]";
  if (arg == "ready")
    return "[战斗准备]";
  if (arg == "combat")
    return "[战斗中]";
  if (arg == "finish")
    return "[结束]";
  return "[等待扎营]";
}

void return_city(object ob)
{
  object retreat_p;
  string p_str;
  string *fix_p = ({
    "/d/city/scenter",
    "/d/city/ncenter",
    "/d/city/ecenter",
    "/d/city/wcenter",
  });

  p_str = (string)ob->query_temp("teamwar/retreat_p");
  retreat_p = 0;
  if (stringp(p_str))
  {
    retreat_p = find_object(p_str);
    if (!objectp(retreat_p))
      retreat_p = load_object(p_str);
  }
  if (objectp(retreat_p))
    ob->move(retreat_p,1);
  else
    ob->move(element_of(fix_p));
  if (ob->query_temp("teamwar/success"))
  {
    message_vision("$N凯旋回来了！\n",ob);
    tell_object(ob,"你从战场胜利回来了！\n");
    return;
  }
  if (ob->query_temp("teamwar/failure"))
  {
    message_vision("$N满脸尘土的奔逃了回来！\n",ob);
    tell_object(ob,"你从战场撤退了！\n");
  }
  return;
}

int do_camp()
{
  object ob,*obs;
  int i;
  string msg, *ks;
  mapping exit, def_place;
  object leader, dir;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if (leader->is_fighting() || leader->is_busy())
    return notify_fail("你正忙着呢！\n");

  if (stringp(leader->query_temp("teamwar/stage")))
    return notify_fail(sprintf("你已经扎过营了，目前处于 [%s] 状态！\n",
                       conv_status(leader->query_temp("teamwar/stage"))));

  if (!environment(leader)->is_warfield())
    return notify_fail("这里并不适合扎营！\n");

  exit = environment(leader)->query("exits");
  if (!mapp(exit) || sizeof(exit) < 4)
    return notify_fail("这里出口太少，不适合扎营！\n");

  ks = keys(exit);
  for (i=0;i<sizeof(ks);i++)
    if (exit[ks[i]] == base_name(environment(leader)))
      return notify_fail("这里道路情况复杂，不适合扎营！\n");

  if (environment(leader)->query("camp"))
    return notify_fail("这里已经有人扎营了！\n");

  obs = TEAMJOB_D->query_member(find_qob());
  if (!arrayp(obs) || sizeof(obs) < 5)
     return notify_fail("有成员离开了，成员不够，无法扎营！\n");

  foreach (ob in obs)
  {
    if (ob == leader)
      continue;
    if (environment(leader) != environment(ob))
    {
      write("人员不齐，无法扎营！如果人员无法聚集整齐，请考虑撤退(retreat)\n");
      return 1;
    }
  }

  def_place = ([]);
  ks = keys(exit);
  for (i = 0;i < sizeof(ks); i++)
  {
    dir = find_object(exit[ks[i]]);
    if (!objectp(dir))
      dir = load_object(exit[ks[i]]);
    if (objectp(dir))
      def_place += ([exit[ks[i]] : 0,]);
  }

  if (sizeof(def_place) < 4)
    return notify_fail("周围的环境有点问题，这里并不适合扎营！\n");

  message_vision("$N一挥手中军令旗，下令在此扎营！\n",leader);
  foreach (ob in obs)
  {
    ob->set_temp("teamwar/stage","mass");
    ob->set_temp("teamwar/camp_p",base_name(environment(leader)));
  }
  environment(leader)->set("camp",1);
  remove_call_out("env_rec");
  call_out("env_rec",900,environment(leader));
  set("def_place",def_place);
  set("camp_p",base_name(environment(leader)));
  msg = HIW"〖" + HIR"战火纷飞" HIW"〗" HIW"："NOR;
  msg += sprintf(HIW"%s" HIW" 率军出征，在[" HIM"%s" HIW"]扎下了营地！\n"NOR,
                  leader->name(),
                  environment(leader)->short());
  message("system",msg,users());
  return 1;
}

void env_rec(object env)
{
  if (objectp(env))
    env->delete("camp");
}

int do_assign(string arg)
{
  object leader, mem;
  string dir;
  string msg, name;

  object lingpai, where;
  mapping def_place, exits, dp_exits;
  string *kp;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if (leader->is_fighting() || leader->is_busy())
    return notify_fail("你正忙着呢！\n");

  if (!stringp(leader->query_temp("teamwar/stage")))
    return notify_fail("请先扎营！\n");

  if ((string)leader->query_temp("teamwar/stage") != "mass")
    return notify_fail(sprintf("你现在处于 %s 状态，怎么开始扎营呢？\n",
                        conv_status(leader->query_temp("teamwar/stage"))));

  if (!arg)
    return notify_fail("你要给谁分派任务？\n");

  def_place = query("def_place");
  if (!mapp(def_place) || sizeof(def_place) < 1)
    return notify_fail("奇怪，你扎营了嘛？\n");

  if (sscanf(arg,"%s defend %s",name,dir) != 2)
  {
    write("命令格式：assign <id> defend <方向> ！\n");
    return 1;
  }

  mem = present(name,environment(leader));
  if (!objectp(mem) || !playerp(mem))
    return notify_fail("这里没有这个人！\n");

  if (!TEAMJOB_D->is_teamjob_member(mem, find_qob()))
    return notify_fail("这个人不是你的成员！\n");

  if ((string)mem->query_temp("teamwar/stage") != "mass")
    return notify_fail("这个人目前不处于[扎营]状态！\n");

  if (mem == leader)
    return notify_fail("你无需安排自己！\n");

  if (stringp(mem->query_temp("teamwar/place")))
    return notify_fail("你已经安排了他需要守卫的位置！你可以assign -cancel [id]来调整！\n");

  dir = DIR_D->abbrdir(dir);
  exits = environment(leader)->query("exits");
  if (!mapp(exits) || sizeof(exits) < 1)
    return notify_fail("有这个方位吗？\n");

  kp = keys(exits);
  if (member_array(dir,kp) == -1)
    return notify_fail("这里没有这个方位需要守护！\n");

  where = find_object(exits[dir]);
  if (!objectp(where))
    where = load_object(exits[dir]);
  if (!objectp(where))
    return notify_fail("那个方位的文件有问题，需要wiz调整！\n");

  if (def_place[exits[dir]] && stringp(def_place[exits[dir]]))
    return notify_fail("那个方位你安排了 " + def_place[exits[dir]] + " 守卫！\n");

  lingpai = new(__DIR__"lingpai");
  lingpai->set("owner",mem->query("id"));
  lingpai->set("leader",leader);
  lingpai->move(mem,1);

  msg = HIY"$N" HIY"拿出了一个令牌，交给了$n" HIY"，命令到：\n"NOR;
  msg += sprintf(HIR"你负责守卫 [%s] 方向的 [%s] \n"NOR,
                  DIR_D->cdir(dir),
                  (string)where->query("short"));
  msg += HIR"请记住，没有我的命令，绝不允许擅自离开阵地，人在阵地在，阵亡人做鬼！\n"NOR;
  message_vision(msg,leader,mem);
  tell_object(mem,"关于令牌的使用，请help lingpai！\n");
  mem->set_temp("teamwar/place",exits[dir]);
  def_place[exits[dir]] = mem->query("id");
  set("def_place",def_place);
  dp_exits = where->query("exits");
  dir = DIR_D->oppdir(dir);
  if (stringp(dp_exits[dir]))
    dp_exits[dir] = base_name(environment(leader));
  else
    dp_exits += ([dir : base_name(environment(leader))]);
  where->set("exits",dp_exits);
  tell_object(mem,"你已经获得元帅安排的守卫地点，请立刻前往指定地点作战斗准备(ready)。\n");
  return 1;
}

int do_sos()
{
  object leader;
  object ob, *obs;
  int t = time();

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if ((string)leader->query_temp("teamwar/stage") != "combat")
  {
    write("你目前不处于" HIR"[战斗]"NOR "阶段，给谁发求救信号？\n");
    return 1;
  }

  if (t - (int)leader->query_temp("teamwar/last_war_sos") < 2)
  {
    write("你刚刚发出了求救信号，等等吧！\n");
    return 1;
  }

  if (leader->query_temp("teamwar/sos"))
  {
    write("你已经发出了求救的信号！耐心等待援兵吧！\n");
    return 1;
  }

  obs = TEAMJOB_D->query_member(find_qob());
  obs -= ({leader});
  obs = filter_array(obs, (: !$1->is_ghost() &&
                              living($1) &&
                             (string)$1->query_temp("teamwar/stage") == "combat" &&
                             objectp(environment($1)) &&
                             environment($1)->is_warfield() &&
                             base_name(environment($1)) == $1->query_temp("teamwar/place") :));
  foreach (ob in obs)
  {
    if (environment(ob) == environment(leader))
      obs -= ({ob});
  }
  obs -= ({0});

  message_vision("$N眼见敌人潮水般的攻入了大营之中，只得发出求救信号！\n",leader);
  if (!arrayp(obs) || sizeof(obs) < 1)
    return notify_fail("可惜没有成员可以听到你的求救信号了！\n");
  TEAMJOB_D->message_team(find_qob(),BLINK + HIR"中军驻地传来了求救信号！\n"NOR);
  TEAMJOB_D->message_team(find_qob(),HIW"如果中军营地失守，本次任务失败！\n"NOR);
  leader->set_temp("teamwar/sos",1);
  foreach (ob in obs)
    ob->set_temp("teamwar/leader_sos",1);
  leader->set_temp("teamwar/last_war_sos",t);
  return 1;
}

int do_retreat(string arg)
{
  object camp_o, leader;
  object ob , *obs;
  string msg, camp;
  int douzhi;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if (stringp(arg))
  {
    ob = find_player(arg);
    if (!objectp(ob) ||
        !ob->query_temp("teamwar/in_warfield") ||
        (string)ob->query_temp("teamwar/stage") != "combat" ||
        !environment(ob)->is_warfield() ||
        !ob->query_temp("teamwar/retreat_req"))
    {
      write("没有这个玩家，或者这个玩家是你的成员，或者这个玩家没有申请撤退！\n");
      return 1;
    }
    ob->set_temp("teamwar/can_retreat",1);
    TEAMJOB_D->message_team(find_qob(),CYN"领军同意了" + ob->name() +
                                       CYN"撤退请求！\n"NOR);
    return 1;
  }

  if (leader->is_fighting() || leader->is_busy())
    return notify_fail("你正忙着呢！\n");

  message_vision("$N一看战斗不利，决定撤退，以避免更大的损失！\n",leader);

  obs = TEAMJOB_D->query_member(find_qob());
  obs = TEAMJOB_D->query_member(find_qob());
  obs = filter_array(obs,(: playerp($1) &&
                            !$1->is_ghost() &&
                            objectp(environment($1)) &&
                            environment($1)->is_warfield() :));

  TEAMJOB_D->message_team(find_qob(),CYN"本次任务领军决定撤退了！本次任务失败了！\n"NOR);
  if (arrayp(obs) && sizeof(obs) > 0)
  {
    foreach (ob in obs)
    {
      ob->set_temp("teamwar/can_retreat",1);
      douzhi = (int)ob->query("douzhi");
      douzhi = douzhi/2;
      ob->set("douzhi",douzhi);
      tell_object(ob,"你现在可以使用retreat撤退！\n");
    }
  }
  camp = query("teamwar/camp_p");
  if (stringp(camp))
  {
    camp_o = find_object(camp);
    if (!objectp(camp_o))
      camp_o = load_object(camp);
    camp_o->delete("camp");
  }
  msg = HIW"〖" + HIG"出师不利" HIW"〗" HIW"："NOR;
  msg += sprintf(HIW"%s" HIW" 率军出征，在[" HIM"%s" HIW"]大败而回！\n"NOR,
                  leader->name(),
                  environment(leader)->short());
  message("system",msg,users());
  leader->set_temp("teamwar/failure",1);
  return_city(leader);
  destruct(this_object());
  return 1;
}

int do_help(string arg)
{
  object leader;
  object member;
  int help_num;
  string msg;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if (!arg || arg == "junqi")
  {
    msg = HIW"\n军旗的使用说明：\n"NOR;
    msg += HIY"================\n\n"NOR;
    msg += HIW"\t1。camp/zhaying 选择一个合适的地点扎营！扎营同时决定了防卫的方向！！\n"NOR;
    msg += HIW"\t2。assign/fenpai 指定每个成员去守卫某个方向！\n"NOR;
    msg += HIW"\t3。sos/qiujiu 求救。当扎营地点收到敌人的直接攻击后，领军如果无法自己抵挡了，可以用此向成员求救！\n"NOR;
    msg += HIW"\t4。retreat/chetui 撤退。一但使用了这个命令，将宣告本次任务失败！\n"NOR;
    msg += HIW"\t5。help/bangzhu 不带参数或参数是junqi的，将看到本帮助信息。否则为领军对某个具体的成员帮助。\n"NOR;
    msg += HIW"\t  但某个成员发出了sos信息后，领军可以使用此命令对其帮助。但每次任务的帮助总次数限制为5次。\n"NOR;
    msg += HIW"\t  每次帮助，将消耗领军的一定内力，而帮助对象的精神和气血恢复全满。\n"NOR;
    msg += HIW"\t6。success/kaixuan 当本次战役时间到了，领军将可用此发出胜利凯旋的信号，所有成员将凯旋回城。\n\n"NOR;
    msg += HIW"\t7。status/chakan 查看成员的状态。\n"NOR;
    msg += HIY"===FINISH====\n\n"NOR;
    write(msg);
    return 1;
  }

  member = find_player(arg);
  if (!objectp(member) ||
      !member->query_temp("teamwar/in_warfield") ||
      (string)member->query_temp("teamwar/stage") != "combat" ||
      !environment(member)->is_warfield())
    return 0;

  if (leader->is_fighting() || leader->is_busy())
  {
    write("你正忙着呢！\n");
    return 1;
  }

  if (!TEAMJOB_D->is_teamjob_member(member, find_qob()))
  {
    write("你没有这个战斗成员，无法提供帮助！\n");
    return 1;
  }

  if (!member->query_temp("teamwar/sos"))
  {
    write(member->name() + "并没有向你求救啊！\n");
    return 1;
  }

  if (!living(member))
  {
    write("可惜你的救助行动迟了一步，" + member->name() +
          "已经昏迷，守卫的阵地马上就要丢了！\n");
    return 1;
  }

  if (!member->is_fighting())
  {
    write(member->name() + "现在不处于战斗中，无需救助！\n");
    return 1;
  }

  help_num = (int)leader->query_temp("teamwar/help_num");
  if (help_num >= 5)
  {
    write("你现在已经无法提供帮助了！每次战役过程中，领军最多能够使用help帮助成员五次！\n");
    return 1;
  }

  if (leader->query("force") < 500)
  {
    write("你自己的内力都要消耗完毕了，也只能是心有余而力不足！\n");
    return 1;
  }

  TEAMJOB_D->message_team(find_qob(),sprintf(HIW"%s受到了%s的求救信号后，决定给与帮助！\n"NOR,
                                             leader->name(),member->name()));
  leader->add("force",-200);
  member->set("kee",(int)member->query("max_kee"));
  member->set("eff_kee",(int)member->query("max_kee"));
  member->set("sen",(int)member->query("max_sen"));
  member->set("eff_sen",(int)member->query("max_sen"));
  member->set("force",(int)member->query("force"));
  member->clear_condition(0);
  tell_object(member,leader->name() + "对你采取了救助行动，你的伤势恢复了！\n");
  member->delete_temp("teamwar/sos");
  help_num++;
  leader->set_temp("teamwar/help_num",help_num);
  tell_object(leader,"你对" + member->name() + "采取了救助行动！\n");
  tell_object(leader,"你目前已采取了" + chinese_number(help_num) + "次救助，你最多只能提供五次！\n");
  if (!leader->is_busy())
    leader->start_busy(1+random(2));
  return 1;
}

int do_kaixuan()
{
  object leader;
  string msg;
  object ob , *obs;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if ((string)leader->query_temp("teamwar/stage") != "finish")
    return notify_fail("还有成员尚未交令，怎么可以凯旋呢！\n");

  if ((string)query("camp_p") != base_name(environment(leader)))
    return notify_fail("你必须到营地才可以下命令凯旋！\n");
  message_vision("$N大声宣布，本次任务胜利结束了，立刻凯旋回京，接受嘉奖！\n",leader);

  obs = TEAMJOB_D->query_member(find_qob());
  if (!arrayp(obs) || sizeof(obs) < 1)
    return 0;
  foreach (ob in obs)
  {
    ob->set_temp("teamwar/success",1);
    return_city(ob);
  }
  msg = HIW"〖" + HIG"胜利凯旋" HIW"〗" HIW"："NOR;
  msg += sprintf(HIW"%s" HIW" 率军出征，在[" HIM"%s" HIW"]痛击敌人，凯旋而回！\n"NOR,
                  leader->name(),
                  environment(leader)->short());
  message("system",msg,users());
  teamjob_reward();
  leader->set_temp("teamwar/stage","jobend");
  destruct(this_object());
  return 1;
}

void teamjob_reward()
{
  object leader, ob , obs;
  int cap_num, total, total_cap;
  int exp, pot;

  leader = get_owner();
  if(!objectp(leader))
    return;

  obs = TEAMJOB_D->query_member(find_qob());
  if (!arrayp(obs) || sizeof(obs) < 1)
    return;

  total = 0;
  total_cap = 0;
  foreach (ob in obs)
  {
    if (ob == leader)
      continue;
    cap_num = ob->query_temp("teamwar/capture_num");
    if (!cap_num)
      continue;
    total_cap += cap_num;
    exp = cap_num*200;
    pot = exp/3;
    total += exp;
    ob->add("office_number",cap_num);
    GIFT_D->bonus(ob, ([ "exp"     : exp ,
                         "pot"     : pot ,
                         "mar"     : random(1 + pot/3*2),
                         "weiwang" : 3 + random(3),
                         "score"   : 2 + random(2),
                         "prompt"  : "胜利完成团队守卫任务之后" ]),"teamwar");
    ob->delete_temp("teamwar");
  }
  exp = total*30/100;
  pot = exp/3;
  leader->add("office_number",total_cap/4);
  GIFT_D->bonus(leader, ([ "exp"     : exp ,
                           "pot"     : pot ,
                           "mar"     : random(1 + pot/3*2),
                           "weiwang" : 3 + random(3),
                           "score"   : 2 + random(2),
                           "prompt"  : "领导团队胜利完成守卫任务之后" ]),"teamwar");
}

int all_ready_task(object leader)
{
  object ob, *obs;

  obs = TEAMJOB_D->query_member(find_qob());
  if (!arrayp(obs) || sizeof(obs) < 1)
    return 0;
  foreach (ob in obs)
  {
    if (ob == leader)
      continue;
    if ((string)ob->query_temp("teamwar/stage") != "ready")
      return 0;
  }
  return 1;
}

void ready_task(object ob)
{
  object leader;


  leader = get_owner();
  if(!objectp(ob) ||
     !objectp(leader))
    return;

  if (!TEAMJOB_D->is_teamjob_member(ob, find_qob()))
    return;

  tell_object(leader,"你收到了" + ob->name() + "传来的信息，他已经做好了战斗准备！\n");
  TEAMJOB_D->message_team(find_qob(),sprintf(HIW"%s已经做好了战斗准备！\n"NOR,
                                             ob->name()));

  if (all_ready_task(leader))
  {
    leader->set_temp("teamwar/stage","ready");
    tell_object(leader,"看来所有成员都已经做好了战斗准备了！\n");
    TEAMJOB_D->message_team(find_qob(),HIW"所有战斗成员已经做好了战斗准备！\n");
    find_qob()->set_heart_beat(1);
  }
}

int all_finish_task(object leader)
{
  object ob, *obs;

  obs = TEAMJOB_D->query_member(find_qob());
  if (!arrayp(obs) || sizeof(obs) < 1)
    return 0;
  foreach (ob in obs)
  {
    if (ob == leader)
      continue;
    if ((string)ob->query_temp("teamwar/stage") != "finish")
      return 0;
  }
  return 1;
}

void finish_task(object ob)
{
  object leader;


  leader = get_owner();
  if(!objectp(ob) ||
     !objectp(leader))
    return;

  if (!TEAMJOB_D->is_teamjob_member(ob, find_qob()))
    return;

  if (all_ready_task(leader))
  {
    leader->set_temp("teamwar/stage","finish");
    TEAMJOB_D->message_team(find_qob(),"所有成员交令完毕！\n");
  }
}

int do_status()
{
  object leader, ob , *obs;
  string msg, name, id, status;

  leader = get_owner();
  if(!objectp(leader))
    return 0;

  if (leader->is_fighting() || leader->is_busy())
    return notify_fail("你正忙着呢！\n");

  obs = TEAMJOB_D->query_member(find_qob());
  obs = filter_array(obs,(: !$1->is_ghost() &&
                            environment($1)->is_warfield() :));

  obs -= ({leader});
  obs -= ({0});
  if (!arrayp(obs) || sizeof(obs) < 1)
    return notify_fail("目前没有成员的状态可以查看！\n");

  msg = "\n";
  msg += HIW"成员名字   成员ｉｄ   成员状态   当前敌人 立功数目 气血％ 精神％ 内力％ 斗志％\n"NOR;
  msg += HIY"------------------------------------------------------------------------------\n"NOR;
  foreach (ob in obs)
  {
    name = ob->name();
    id = ob->query("id");
    status = ob->query_temp("teamwar/stage");
    msg += sprintf(HIW"%-10s %-10s %-10s %-8d %-8d %-4d％ %-4d％ %-4d％ %-4d％\n"NOR,
                   COLOR_D->clean_color(name),
                   id,
                   conv_status(status),
                   arrayp(ob->query_enemy()) ? sizeof(ob->query_enemy()) : 0,
                   ob->query_temp("teamwar/capture_num"),
                   ob->query("eff_kee")*100/ob->query("max_kee"),
                   ob->query("eff_sen")*100/ob->query("max_sen"),
                   ob->query("force")*100/2*ob->query("max_force"),
                   ob->query("douzhi")*100/ob->query("eff_douzhi"));
  }
  msg += HIY"------------------------------------------------------------------------------\n"NOR;
  write(msg);
  return 1;
}