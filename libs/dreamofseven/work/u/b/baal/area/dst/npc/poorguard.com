#include <ansi.h>
inherit NPC;
void create()
{
        set_name("暗斯德塔守衛", ({ "dark side tower guard","guard" }) );
        set("level", 10);
        set("race","人類");
        set("gender","女性");
        set("age",35);
        set_skill("parry", 14);
        set_skill("unarmed", 24);
        set_skill("dodge", 15);
        set_skill("sword",22);
        set("long","一位形容憔悴的守衛，令你吃驚的是...是一位「她」！！\n");
        set("chat_chance_combat",15);
        set("chat_msg_combat", ({
  (: command,"..." :),
  (: command,"sigh" :),
  (: command,"say 奉城主阿特尼斯‧拉貝撒之令，阻止任何人打擾暗斯德塔安寧！！" :),
  (: command,"shout Alert！！Dark Side Tower is under attack！！" :),
}));
        setup();

}
void init()
{
        object me;
        ::init();
        add_action("do_kill","kill");
        me=this_player();
        if(!this_object()->visible(this_player())) return;
        call_out("callhlvguard", 1, me);
}

void callhlvguard(object ob)
{
  object me,obj;
  me=this_player();
  obj=this_object();
  if(me->query_temp("DST/basicdie")>0)
  {
    command("say It's a good day to die！！");
    obj->kill_ob(me);
  }
  else {
    if(me->query_temp("DST/basicdie")>0)
    {
      command("say Interser will damn you！！Go hell！！");
      obj->kill_ob(me);
    }
  }
}
void do_kill(string arg)
{
        object ob,me,*obs;
        me=this_player();
        ob=this_object();
        if (!arg) return;
        if(!objectp(present(arg, environment(me)))) return;
        
        if( is_fighting(me) ) return;
        message_vision("$N說：哈！！吾神之力將與吾同往！！廢物去死吧！！\n",this_object());
        obs = all_inventory(environment());
        for(int i=0;i<sizeof(ob);i++)
        {
                obs[i]->guard_assist(this_object(), me);
        }
}


void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i=ob->query_temp("DST/basicdie");
        ob->set_temp("DST/basicdie",i+1);
        if(ob->query_temp("DST/basicdie")==0) 
message_vision(HIR"暗斯德塔守衛死前悽厲大喊：Alert！！Dark Side Tower is under attack！！\n\n"NOR,ob);

        ::die();
        return;
}

void guard_assist(object alert, object me)
{
        if( alert==this_object()
        ||      !living(this_object())
        ||      is_fighting(me) )
                return;
        switch(random(4)) {
        case 0: command("say 吹號角！告訴塔內那些...法師們...衝啊！"); break;
        case 1: command("say 我們遭到攻擊了！！攻擊！！"); break;
        case 2: command("say 蠢蛋！受死吧！！"); break;
        case 3: command("say 這是個受死的好日子！"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

