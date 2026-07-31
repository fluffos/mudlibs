// by baiwt 12/16/1998
// wu.h 武进士

#define DIRNAME "/d/huanggong/"

#define MYFILE "/d/huanggong/npc/wu??.lpc"

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "金榜",
  "银榜",
  "铜榜",
  "铁榜",
  "锡榜",
 });

string *positions = ({
  "状元",
  "榜眼",
  "探花",
 });

int *limits = ({
  1000000,
  500000,
  250000,
  90000,
  30000,
 });

string *rooms = ({
  "b",
  "a",
  "c",
 });

int get_category_int ();
int get_position_int ();

string get_position_str ()
{
  return chinese_number(get_position_int ());
}

string get_honor_str ()
{
  return categories[get_category_int()-1]+
         positions[get_position_int()-1];
}

string get_respect_str ()
{
  return get_honor_str ();
}

int save_record(object me, object ob)
{
  object *inv;
  mapping hp_status, skill_status, map_status;

  hp_status = ob->query_entire_dbase();

  me->set("str", hp_status["str"]);
  me->set("per", hp_status["per"]);
  me->set("int", hp_status["int"]);
  me->set("age", hp_status["age"]);

  me->set("max_gin",     hp_status["max_gin"]);
  me->set("eff_gin",     hp_status["eff_gin"]);
  me->set("gin",         hp_status["gin"]);
  me->set("max_kee",     hp_status["max_kee"]);
  me->set("eff_kee",     hp_status["eff_kee"]);
  me->set("kee",         hp_status["kee"]);
  me->set("max_sen",     hp_status["max_sen"]);
  me->set("eff_sen",     hp_status["eff_sen"]);
  me->set("sen",         hp_status["sen"]);
  me->set("max_force",   hp_status["max_force"]);
  me->set("force",       hp_status["force"]);
  me->set("max_mana",    hp_status["max_mana"]);
  me->set("mana",        hp_status["mana"]);
  //me->set("force_factor",hp_status["force_factor"]);
  me->set("gender",      hp_status["gender"]);
  me->set("combat_exp",  hp_status["combat_exp"]);

  me->set("eff_gin", me->query("max_gin"));
  me->set("gin",     me->query("max_gin"));
  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);
 me->set("force_factor",me->query("force_factor"));

  return 1;
}

int convert_identity (object me, object ob)
{
  if (ob->query("id") == "jin shi")
  {
    string current_player = ob->query("current_player");

    me->set("current_player",current_player);
    if (! current_player ||
        current_player == "none of us")
    {
      //me->set("short",me->get_honor_str()+"("+capitalize(me->query("id"))+")");
      return 1;
    }
    else
    {
      me->set("name", ob->query("name") );
      me->set("gender", ob->query("gender") );
      me->set("nickname", ob->query("nickname") );
      me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
    }
  }
  else
  {
    me->set("name", ob->query("name") );
    me->set("gender", ob->query("gender") );
      me->set("nickname", ob->query("nickname") );
    me->set("current_player",ob->query("id"));
    me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

    ob->set_temp("apply/short", ({ob->query("title")+" "+me->get_respect_str()+
                 " "+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
  }

	remove_call_out("do_clone");
	call_out("do_clone", 1, me, ob);
	save_record(me, ob);
  return 1;
}

int fully_recover (object me)
{
  object *inv;
  object ob;
  string player_name;
  object current_player;

  me->set("eff_gin", me->query("max_gin"));
  me->set("gin",     me->query("max_gin"));
  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);

  inv = all_inventory(me);
  while (inv && sizeof(inv))
  {
    destruct (inv[0]);
    inv = all_inventory(me);
  }

  if (me->query("weapon"))
  {
    ob = new(me->query("weapon"));
    if(ob) if(ob->move(me))
      ob->wield();  
  }

  if (me->query("armor"))
  {
    ob = new(me->query("armor"));
    if(ob) if(ob->move(me))
      ob->wear(); 
  }

  return 1;
}

int accept_fight(object ob)
{
  int i;
  object* inv;

  object me = this_object();
  object who = this_player();

  object huangpu = present("huangpu hui",environment(me));

  if (! huangpu)
  {
    command ("say 太史大人不在，如何比武也？\n");
    return notify_fail("还是请太史大人皇甫晖来吧。\n");
  }

  if ( who->query("combat_exp")/3 > me->query("combat_exp") )
  {
    command ("say 本进士不敢！\n");
    return notify_fail("你的榜次已经比这位武进士高了。\n");
  }
  if (me->query("current_player") == ob->query("id")) 
  {
    command ("say 进士不可与己较量！\n");
    return notify_fail("你就是这位武进士。\n");
  }
  if (me->is_fighting())
  {
    command ("say 进士失陪了！\n");
    return notify_fail("这位武进士尚在比武之中，请稍候。\n");
  }
  if (! interactive(ob))
  {
    command ("say 进士失陪了！\n");
    return notify_fail("You are a NPC.\n");
  }
  if (! huangpu->execute_approve_fight(who,me,get_position_int(),get_category_int()))
  {
    return notify_fail("看来太史大人不允许你比武。\n");
  }

  fully_recover (me);
  inv = all_inventory(who);
  for(i=0; i<sizeof(inv); i++)  {
     if( inv[i]->query_unique() ) {
       message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]);
       destruct(inv[i]);
     }
  }

  remove_call_out("check_result");
  call_out("check_result", 1, me, ob);
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
  
  return 1;
}

void huangpu_execute_fight_result (object huangpu, object me, object ob, int i)
{
  huangpu->execute_fight_result(me, ob, i);
}

int check_result(object me, object ob)
{
  object huangpu = present("huangpu hui",environment(me));
  int my_max_kee, his_max_kee;

  my_max_kee  = me->query("max_kee");
  his_max_kee = ob->query("max_kee");

  if (me->is_fighting())
  {
    call_out("check_result",1, me, ob);
    return 1;
  }

  if (huangpu == 0)
    huangpu = find_living ("huangpu hui");
  if (!present(ob, environment()))
  {
    remove_call_out ("huangpu_execute_fight_result");
    call_out("huangpu_execute_fight_result",1,huangpu,me,ob,0);
    return 1; 
  }

  if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
  {
    int previous_position;
    message_vision ("$N翻身下拜，连声佩服！\n",me);
    me->set("new_player",1);
    huangpu_execute_fight_result (huangpu,me,ob,1);
    convert_identity (me, ob);
    return 1;
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N将$n扶起。\n",me,ob);
  }

  call_out("huangpu_execute_fight_result",1,huangpu,me,ob,0);
  return 1;  
}

string query_save_file()
{
  return DATA_DIR+"huanggong/wu"+sprintf("%d%d",get_category_int(),get_position_int());
}

int do_bandage(string arg)
{
  object who = this_player();
  object me = present("jin shi",environment(who));

  if (! arg || me != present(arg, environment(me)))
    return 0;

  message_vision ("$N别有用心地要给$n包扎伤口。\n",who,me);
  call_out("no_bandage",2,who,me);
  return 1;
}

void no_bandage(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N摸摸索索地掏出什么法宝想祭一祭。\n",who);
  call_out("no_ji",2,who,me);
  return 1;
}

void no_ji(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N张开嘴，结结吧吧地念了几声咒语。\n",who);
  call_out("no_cast",2,who,me);
  return 1;
}

void no_cast(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "bloodsun jin shi" &&
      arg != "bloodsun jin" &&
      arg != "bloodsun shi" &&
      arg != "zhenqi")
    return 0;

  message_vision ("$N鬼鬼祟祟地一运气。\n",who);
  call_out("no_exert",2,who,me);
  return 1;
}

void no_exert(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N鬼鬼祟祟地一施外功。\n",who);
  call_out("no_perform",2,who,me);
  return 1;
}

void no_perform(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N伸出手，鬼鬼祟祟地想偷什么东西。\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if(!arg || present(arg,environment(me))!=me) return 0;
  //allow kill others. mon 2/16/98

  message_vision ("$N眼露凶光，看样子动了杀机！\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

void die()
{
  //fully_recover (this_object());
}

void unconcious()
{
  //fully_recover (this_object());
}

