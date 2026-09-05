inherit NPC;
#include <ansi.h>
void try_move();
int do_eat(string arg);

void create()
{
        set_name("人参娃娃", ({"renshen wawa","wawa","baby"}) );
        set("gender", "女性");
        set("age", 1);
        set("attitude", "friendly");
        set("long","白白胖胖的一个人参娃娃,浑身散发着灵气,憨态可掬。\n");
        set("combat_exp", 1);
        set("str",3);        
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :)
                }));

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
}

void init()
{
        add_action("do_kill",({"kill","fight","steal"}));
        add_action("do_get","get");
        add_action("do_drop","drop");
        add_action("do_eat","eat");
}
int do_eat(string arg)
{
       object me;int i,j;string tf,tf2;
     mapping gift=([
        "str"           : "膂力",
        "int"           : "悟性",
        "spi"           : "灵性",
        "per"           : "容貌",
        "dex"           : "身法",
        "con"           : "根骨",
        "kar"           : "福缘",
]);

       me=this_player();
       if(!arg ||!me|| arg!="wawa" && arg!="baby") return 0;
       if(query("owner")!=me->query("id")) return notify_fail("这可不是你的娃娃!\n");
       
       message_vision(HIW "\n$N看那白胖胖的人参娃娃甚是可爱,三口两口把娃娃吞了下去。\n\n" NOR, me);
  me->set("eff_qi", (int)me->query("max_qi"));
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("qi", (int)me->query("max_qi"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("jingli", (int)me->query("max_jingli")*2);
  me->set("neli", (int)me->query("max_neili")*2);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());

  i=sizeof(gift);j=random(i-1);tf=keys(gift)[j];tf2=values(gift)[j];
  me->add(tf,1+random(2));
  write("你的"+tf2+"增加了!\n");
  destruct(this_object());
  return 1;
}

void disapper()
{
   message_vision("$N似乎受不了外界的浊气,身子都不灵活了！\n",this_object());
   call_out("disappear1",300);
}

void disapper1()
{
    message_vision(HIW"$N似乎手不了外界的浊气,全身发抖,要消失了！\n",this_object());
    call_out("disappear2",180);

}
void disappear2()
{
   message_vision(HIW"$N惨叫一声,浑身散为一片白光,消失不见了！\n",this_object());
   destruct(this_object());
}




int do_drop(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,who)!=me) return 0;
     if(me->move(env)) {
       message_vision("$N把$n从怀里放了下来。\n",who,me);
       return 1;
     }
     return 0;
}

int do_get(string arg)
{    object me=this_object(),who=this_player(),env;
     
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(who->query("id")==query("owner")) {
      if(me->move(who)) {
       message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
      } else {
       message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
      }
     } else {
      message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
     }
     return 1;
}

int do_kill(string arg)
{       
        object me,who;
        string name,verb,what,obj;
        if (!arg) return 0;
        verb=query_verb();
        me=this_player();
        
        if(verb=="steal") {
          if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
            return 0;
          }
        else obj=arg;

        if(!objectp(who=present(obj,environment(me))) 
           || !living(who)) return 0;
//      if(who->query("is_baby")) {
        if(who==this_object()) {
          switch(verb) {
            case "kill":
//            command("chat* "+
              tell_object(environment(this_object()),
                who->query("name")+"拼命地哭了起来：主人～～，"+
                me->query("name")+"要杀我．．．快回来呀！\n");
              break;
            case "fight":
//            command("chat* "+
              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人～～，"+
                me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
              break;
            case "steal":
//            command("chat* "+
              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人～～，"+
                me->query("name")+"要偷吃我的糖！\n");
              break;
          }
        }
        command(verb);
        return 0;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
                command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say 爹～～，娘～～，"  + ob->query("name") +
"打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                        break;
        case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  

                }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id")!=this_object()->query("owner"))
        {
                message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
                return;
        }

        //note, do not allow the order contain "chat", "tell"...
        //may need disable more later...
        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "hslj") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "newbie") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}

void relaying (string msg)
{//execute the order.
        command (msg);
}
