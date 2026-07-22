#include <mudlib.h>
#include <conditions.h>
#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <net/daemons.h>
#include <move.h>
#include <priv.h>
#include <uid.h>
#include <body.h>
#include <logs.h>
#include <stats.h>

inherit OBJECT;

string book_color();
int living_check(object ob);
int object_check(object ob);
int wrong(int type);
int help();

string *specials = ({"fire","cold","electric","energy","mental",
                     "acid","poison","magic","evil","divine",
                     "none","scholar","monk"});
string *names = ({" 火系 "," 冰系 "," 电电 "," 能源 "," 精神 ",
                  " 酸系 "," 毒系 "," 魔法 "," 邪恶 "," 神圣 ",
                  "无属性"," 书生 "," 和尚 "});
                                                                              

void create()
{       
	set_name( "Ghost Book","鬼咒降魔录" );
	add( "id",({"book"}) );
	set_short(set_color("鬼咒降魔录","HIB"));
	set_long(@LONG

              一本记载著具有毁天灭地力量的魔界宝录。

LONG);
	set("unit","本");
	set("prevent_drop",1);
	set("light",1);
//	set("extra_look","@@book_color");
}
int query_auto_load() { return 1; }

void init()
{
        add_action("do_test_bs","test_bs");
        add_action("do_masterscan","masterscan");
        add_action("do_shot","shot");
        add_action("do_callmonster","callmonster");
	add_action("do_pcall","pcall");
	add_action("full_heal","heal");
        add_action("do_revive_ppl","re_ppl");
        add_action("do_ide","ide");
        add_action("do_list","listwiz");
        add_action("do_exp","exp");
//      add_action("do_make_dictionary","make_my_word");
}

int do_exp(string arg)
{
   object player;
   if ( !arg || arg=="" )
  
      return notify_fail("no string\n");
   if ( !player=find_player(arg) )
      return notify_fail("no such player\n");
   player->gain_experience(4000);
   return 1;      
}
int filter_wizards(object who)
{
   if( !wizardp(who) ) return 0;
      return 1;
}
int do_list(string arg)
{
   object *list_wiz;
   int i,invis;
              
   list_wiz = filter_array(users(), "filter_wizards", this_object());
   i = sizeof(list_wiz);
   write("\n线上巫师：\n");
   while( i-- ) {
      invis = (int)list_wiz[i]->query("invisible");
      if(invis == 2) write(set_color("(对巫师及玩家隐形)\t","HIW"));
      else if(invis == 1) write(set_color("(对玩家隐形)\t","HIG"));
      else write(set_color("(没有隐形)\t","HIC"));
      write(list_wiz[i]->query("name")+"\n");
   }
   return 1;
}
int wrong(int type)
{
  switch (type) {
    case 1 : write("这里没有这种东西。\n");
       break;
    case 2 : write("懒的写，以後再说。\n");
       break;
    case 3 : write("test3。\n");
       break;
    case 4 : write("test4。\n");
       break;     
    default :
  }

  return 1;
}

int help()
{
  write(@LONG
    笨蛋。
LONG);
  return 1;
}

int filter_name(object ob,string name)
{
  string *names;
  
  if (ob->query("name")==name)
    return 1;
  if (names = ob->query("id"))
    if (member_array(name,names) != -1)
      return 1; 
  return 0;
}

int do_ide(string arg)
{
  int order=0;
  string name;
  object ob,ienv,oenv,me,*iob,*oob;

  if (!arg || arg=="") return help();
  
  me = this_player();
  ienv = this_player();
  oenv = environment(this_player());

  if (sscanf(arg,"%s %d",name,order)!=2)
    name = arg;

  if (!ob=present(name,ienv))
    if (!ob=present(name,oenv))
      return wrong(1);
  if (order>0) {
    iob = filter_array(all_inventory(ienv),"filter_name",this_object(),name);
    oob = filter_array(all_inventory(oenv),"filter_name",this_object(),name);
    if (sizeof(iob)>0) {
      if (sizeof(iob) >= order)
        ob = iob[order-1];
      else if (sizeof(iob)+sizeof(oob)+1 > order)
        ob = oob[order-sizeof(iob)-1];
      else if (sizeof(oob)==0)
        return wrong(3);
      else    
       ob = oob[sizeof(oob)-1];
    }   
    else if (sizeof(oob)> order)
      ob = oob[order-1];
    else if (sizeof(oob)==0)
      return wrong(4);
    else
      ob = oob[sizeof(oob)-1];
  }
  
  if (living(ob)) living_check(ob);
  else object_check(ob);
  return 1;
}

int living_check(object ob)
{
  int i;
  int *aimv;
  string *aimk;
  mapping aimm;

  write(sprintf("『 %d 』%s\n",ob->query_level(),ob->query("c_name")));
  write(sprintf("一般防御能力:     AC : %d,     DB : %d.\n",
                 ob->query("armor_class"),ob->query("defense_bonus")));
  write("魔法防御能力:\n");
  for (i=0;i<sizeof(specials);i++) {
    write(sprintf("  『%s』: %4d",
          names[i],ob->query_special_defense(specials[i]) ) );
    if ( (i != 0) && !((i+1) % 3) )
      write("\n");
    else
      write(",");
  }
  if (ob->query("no_bleeding"))
    write("『不流血』");
  write("\n");
  aimm = ob->query("aim_difficulty");
  if (!mapp(aimm)||!keys(aimm))
    write("无任何(瞄准防御)之能力。\n");
  else {
    write("瞄准防御能力 : \n");
    aimk = keys(aimm);
    aimv = values(aimm);
    for (i=0;i<sizeof(aimk);i++) {
      write(sprintf("  『%s』: %4d,",aimk[i],aimv[i]));
    }
  }
  write("\n");

  return 1;
}

int object_check(object ob)
{
  wrong(2);
  return 1;
}

int do_test_bs(string arg)
{
  call_other("/d/thief/cmds/_backstab.c","cmd_backstab",arg);
  return 1;
}

int do_shot(string arg,int silent)
{
  string name;
  object vic, env, me;
 
  if (!arg) return notify_fail("To whom？\n");
  if (!(vic = find_player(arg)))
    if (!(vic = find_living(arg)))
       return notify_fail("No such person。\n");
 
  env = environment(vic);
  me = environment();
  name = vic->query("c_name");
  
  tell_room(env,sprintf("%s%s。\n",
    set_color("  砰!!  一枚鱼雷突然以迅雷不及掩耳的速度射中了","HIY"),
    set_color(name,"HIW")),vic);
  tell_object(vic,set_color(
"  砰!!  一枚鱼雷突然以迅雷不及掩耳的速度射了过来，并把你给击沈了。\n","HIY"));
  if (!silent) {
    tell_room(env,
      sprintf("只见%s躲在一旁得意地哈哈大笑。\n",me->query("c_name")));
    tell_object(me,"发射ok!!\n");
  }
  return 1;   
}

int check_person(object ob)
{
  if (userp(ob)||wizardp(ob)||living(ob))
    return 1;
  return 0;  
}

int do_masterscan()
{
  int i;
  string name;
  object *obj,env,me;
  
  me = environment();
  env = environment(me);
  tell_room(env,set_color("！！吧．．．．．哇！！\n
  主动声纳的震波憾动著你的身体，你才知道你已经被锁定了。\n","HIB"),me);   
  tell_object(me,"主动声纳启动！！\n");
  
  obj = filter_array(all_inventory(env),
                     "check_person",this_object());  
  for (i=1;i<sizeof(obj);i++)
    if (obj[i]->query("name")!="player") {
      name = obj[i]->query("name");
      do_shot(name,1);
    }  
  return 1;     
}

int do_callmonster(string arg)
{
  object mob1,mob2,mob3,env,vic,me;
  
  if (!arg) return notify_fail("To whom？\n");
  if (!(vic = find_player(arg)))
    if (!(vic = find_living(arg)))  
    return notify_fail("No such person。\n");
  
  seteuid(getuid());
  
  mob1 = new("/u/p/player/home/mob/helldog1");
  mob2 = new("/u/p/player/home/mob/ghost1");
  mob3 = new("/u/p/player/home/mob/ghoul1");
  
  me = environment();
  env = environment(vic);
  tell_room(env,sprintf("\n%s翻开了鬼咒降魔录的第一章，\n",me->query("c_name")));
  tell_room(env,
    sprintf("瞬间阴风四起，鬼哭神号，大地一裂为二，出现了可怕的怪物冲向%s\n",
      vic->query("c_name")) );

  mob1->move(env);
  mob2->move(env);
  mob3->move(env); 
  
  mob1->kill_ob(vic);
  mob2->kill_ob(vic);
  mob3->kill_ob(vic);
  return 1;
}

int do_make_dictionary(string arg)
{
  string eng,chi;
  if (sscanf(arg,"%s %s",eng,chi)==2) {
    CHINESE_D->add_translate(eng, chi);
    tell_object(this_player(),
      "嗯, 您需要的字汇  "+eng+"  "+chi+"  已经加入字典里了。\n");
    return 1;
  }
  else {
    tell_object(this_player(),
      "\n"+arg+"  "+eng+"  "+chi+"\n");
    return 0;
  }
}

int do_revive_ppl(string arg)
{  
  object obj;
  tell_object(this_player(),"wait！\n");
  obj=find_player(arg);
  obj->revive(0);
  tell_object(this_player(),"ok！\n");
  return 1;
}

int do_pcall(string arg)
{
  string who,what,kind,temp;
  int number;
  object ob,me;
   
  me = this_player(); 
  if (sscanf( arg,"%s %s %s %d",who,what,kind,number)!=4)
    return notify_fail("笨蛋。\n");
  if (!(ob=find_player(who)))
    if (!(ob=find_living(who)))
      return notify_fail("No such person on line。\n");
  switch (what) {
    case "set" :
           ob->set(kind,number);
           tell_object(me,"Set ok。\n");
           break;
    case "set_temp" :
           ob->set_temp(kind,number);
           tell_object(me,"Set_temp ok。\n");
           break;
    case "delete" :
           ob->delete(kind);
           tell_object(me,"Delete ok。\n");
           break;
    case "delete_temp":
           ob->delete_temp(kind);
           tell_object(me,"Delete_temp ok。\n");
           break;
    default :
          return notify_fail("No such function。\n");
  } 
  return 1;
} 


int full_heal(string arg)
{
	object target,owner;
	int stat;
	owner = environment();
	if( !arg || arg=="" )
		return notify_fail("Usage: ih <someone>\n");
	target=find_living(arg);
	if (!target)
		return notify_fail("你不能治疗一个不存在的人。\n");
	if( !living(target) )
		return notify_fail("Only living things can be healed!\n");
	target->set("hit_points",(int)target->query("max_hp"));
	target->set("spell_points",(int)target->query("max_sp"));
	target->set("talk_points",(int)target->query("max_tp"));
	target->set("force_points",(int)target->query("max_fp"));
	target->set("endurance_points",(int)target->query("max_ep"));
        
        if (target->query("blind"))
          target->delete("blind");
        target->set("medication_resistance",0);

        if (target->query("conditions/slow"))
          SLOW->remove_effect(target,1);
	if (target->query("conditions/bleeding"))
   	  BLEEDING->remove_effect(target,1);
 	if (target->query("conditions/simple_poison"))
          SIMPLE_POISON->remove_effect(target,1);
	if (target->query("conditions/confused"))
          CONFUSED->remove_effect(target,1);
        if (target->query("conditions/sick"))
          target->delete("conditions/sick");  
	if (target->query("conditions/weak"))
          WEAK->remove_effect(target,1);
	tell_object(owner,"Heal ok。\n");
	return 1;
}
string book_color()
{
  return set_color("$N手上拿著一本名为鬼咒降魔录的书\n","HIB");
}
