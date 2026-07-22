// cracked by vikee 2/09/2002   vikee@263.net
#include <ansi.h>
inherit NPC;

int bianhua(string);
int bianback();
void announce_success(object);
string begin_chasing();
void gohome();
void greeting(object);

void create()
{
        set_name("二郎真君", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "他是赤城昭惠英灵圣，显化无边号二郎。
力伏八怪声名远，义结梅山七圣行。\n");
        set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "男性");
        set("title", "昭惠灵显王");
        set("str", 40);
        set("int", 40);
        set("per", 30);
        set("con", 30);
        set("max_kee",3000);
        set("max_sen", 3000);
        set("combat_exp", 1500000);
        set("daoxing",2500000);
        set("force", 4000);
        set("max_force", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 150);
        set("mana_factor", 120);
        
        set_skill("unarmed", 200);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("spear", 200);
        set_skill("moyun-shou", 200);
        set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
        set_skill("dao",200);
        set_skill("wuxiangforce",200);
        map_skill("force","wuxiangforce");
        map_skill("spells","dao");
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();

      for (int i=0;i<random(20);i++) carry_object("/d/obj/drug/jinchuang");
  set("inquiry", ([
        "name": "我乃二郎神杨戬是也。",
        "here": "我奉玉帝谕旨，正要兴兵捉拿反出天宫的齐天大圣。",
        "齐天大圣": (:begin_chasing :),
        "me": (:begin_chasing :),
      ]) );

}

string begin_chasing() {
  object ob=this_player();
  object me=this_object();
  string *id=ob->parse_command_id_list();

  if (me->query_temp("target")==ob) {
       kill_ob(ob);
       return "快快投降，饶你一命！\n";
  }
  if (me->query_temp("target")) return "我正捉拿"
     +me->query_temp("target")->query("name")+"，你可知道他的行踪？\n";

  if (ob->query("dntg/erlang")=="done") {
     me->command("fear "+id[0] );
     return RANK_D->query_respect(ob)+"的神通，小神早已领教过了。\n";
  }
  
//  if (ob->query("daoxing")<500000) 
  if (ob->query("daoxing")<100000) 
     return "齐天大圣道行高你百倍！\n";

  me->set_temp("target",ob);
  set("eff_kee",4000);
  set("max_kee",4000);
  set("kee",4000);
  set("sen",4000);
  set("eff_sen",4000);
  set("max_sen",4000);
  set("mana",4000);
  ob->set_temp("erlang","begin");
  tell_object(ob,"二郎真君正盯着你看，不知道打些什么主意。\n");
  me->command("jump");
  me->command("say 我正愁拿你不到，你却送上门来，真是天助我也！");
  me->set_leader(ob);
  message_vision("$N决定开始跟随$n一起行动。\n",me,ob);
  kill_ob(ob);
  return "嘿嘿。。\n";
}

void init() {
  object me,ob,env;
 
  ::init();
  bianback();
  ob=this_player();
  me=this_object();
  if ( ob==me->query_temp("target") ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }           
}

void greeting(object ob) {
  object me=this_object();
  object env=environment(me);
  string *id=ob->parse_command_id_list();
  string name=ob->name();
  string stage=ob->query_temp("erlang");
  if (env->query("no_fight")) {
     command("sigh2");
     command("loser "+id[0]);
     me->delete_temp("target");
     ob->delete_temp("erlang");
     gohome();
     return;
  }
  if (name=="麻雀" && stage=="begin") {
    me->bianhua("queying");
    ob->set_temp("erlang","maque");
  }
  if (name=="鹚鹄" && stage=="maque") {
    me->bianhua("haihe");
    ob->set_temp("erlang","cihu");
  }
  if (name=="鱼儿" && stage=="cihu") {
    me->bianhua("yuying");
    ob->set_temp("erlang","fish");
  }
  if (name=="水蛇" && stage=="fish") {
    me->bianhua("huihe");
    ob->set_temp("erlang","shuishe");
  }
  if (name=="花鸨" && stage=="shuishe") {  
    ob->set_temp("erlang","erlang");
 
  }
}

void die()
{
  object target=this_object()->query_temp("target");
  if( environment() ) {
        message("sound", "\n\n二郎神怒道：你莫要猖狂，待我上天告御状去！\n\n", environment());
        message("sound", "\n二郎神搭上白云，径往南天门飞去。。。\n\n", environment());
        }
  command("drop all");
 
  if (target) {
     if (target->query_temp("erlang")=="erlang")  
        announce_success(target);
     target->delete_temp("erlang");
  }
  destruct(this_object());
}
// void unconcious() {die();}

void announce_success(object ob) {
   object me=this_object();

   if (ob->query("dntg/erlang") == "done") return;
   me->set("name","二郎真君");
   command("chat "+ob->query("name")+
            "武艺高强，法术超群，杨戬不是对手，甘拜下风！");
   ob->set("dntg/erlang","done");
   ob->set("cor",(int)ob->query("cor")+2);
   message_vision(HIW"$N打败二郎神，迎风傲立，觉得胆识大增！\n"NOR,ob);
   log_file("dntg",sprintf("%s(%s) passed erlang shen and won 2-point cor on %s\n",
             ob->name(1), geteuid(ob), ctime(time()) ) );

}
void kill_ob(object sb) {
  object me=this_object();
  object target=me->query_temp("target");

  if (!target) ::kill_ob(sb);
  else {
     if (target!=sb && environment(me)==environment(target)) {
           command("sneer");
           command("say 倚多取胜？"+target->query("name")+
                    "好大的名头，原来不过如此！");
           command("bye");
           message_vision(HIG"$N化做一道清烟，霎时间失去了踪影。\n"NOR,me);
           target->delete_temp("erlang");
           destruct(me);
           return;
      }
      ::kill_ob(sb);
  }
}
        
int bianhua(string id) {
    object me=this_object();    
    string name,long;
    mapping id_name=(["queying":"雀鹰",
                     "haihe":"海鹤",
                     "yuying": "鱼鹰",
                     "huihe": "灰鹤",
                    ]);

   if (name=id_name[id]) {
      message_vision(HIY "$N手捻口诀，念动真言，摇身一变，变成一只"
                      +name+"！\n" NOR,me);
      me->set("name",name); 
      me->delete("title");
      me->set("looking","变成了一只"+name+"模样。");
    }
    return 1;
}
int bianback()  {
    object me=this_object();
    
    if (me->query("name")!="二郎真君") {
      me->set("name","二郎真君");
      message_vision(HIY "$N口念咒语，身形一晃，现了真身。\n"
            NOR,me);
      set("title", "昭惠灵显王");
      set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
    }
    return 1;
}

void heart_beat() {
    object me=this_object();
    object ob=me->query_temp("target");
    object env;
    
    if (ob) {
       env=environment(ob);
       if (ob->is_ghost()) {
           me->delete_temp("target");
           me->set_leader(0);
           me->gohome();
       }
       // tell_object(ob,"hi.\n");
      if ( (!env->query("no_fight")) && environment(me)!=env 
            && random(3)==1) {
           message_vision("$N急急忙忙地离开了。\n",me);          
           me->move(env);     
           message_vision("$N走了过来。\n",me);
       }
     if (!query_temp("weapon")) set("force_factor",300);
    set("force",4000);
  if (query("eff_kee")<query("max_kee")) command("eat yao");
  if (env->query("no_fight")) delete_temp("target");
     }
    ::heart_beat();
}
void gohome() {
   object me=this_object();

   me->bianback();
   message_vision("$N急急忙忙地离开了。\n",me);          
   //me->move("/d/city/center");     
   //message_vision("$N走了过来。\n",me);
   destruct(me);
}

varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  object target=query_temp("target");

  if (!target) return ::receive_damage(type,damage,who);
  if (target->query_temp("erlang")!="erlang") return 1;
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) {
  me->command("exert recover");

}


