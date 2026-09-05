// npc.c

#include <command.h>
#include <ansi.h>

inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
        object ob;

        if( !objectp(ob = new(file)) ) return 0;
        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/clone/money/" + type);
        if( !ob ) return 0;
        ob->set_amount(amount);
}

int accept_fight(object who)
{
        string att;

        att = query("attitude");

        if( is_fighting() )     switch(att) {
                case "heroism":
                        command("say 哼！出招吧！\n");
                        break;
                default:
                        command("say 想倚多为胜，这不是欺人太甚吗！\n");
                        return 0;
        }

        if( (int)query("jing") * 100 / (int)query("max_jing") >= 90
        &&      (int)query("qi") * 100 / (int)query("max_qi") >= 90 ) {
                switch(att) {
                        case "friendly":
                                command("say " + RANK_D->query_self(this_object())
                                        + "怎么可能是" + RANK_D->query_respect(who)
                                        + "的对手？\n");
                                return 0;
                        case "aggressive":
                        case "killer":
                                command("say 哼！出招吧！\n");
                                break;
                        default:
                                if( !is_fighting() )
                                        command("say 既然" + RANK_D->query_respect(who)
                                                + "赐教，" + RANK_D->query_self(this_object())
                                                + "只好奉陪。\n");
                }
                return 1;
        } else
                return 0;
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;
        int i;

        if(!environment()) return 0;
        if(sizeof(environment()->query("exits")) == 0) return 0;
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        i = random(sizeof(dirs));
        if( !environment()->valid_leave(this_object(), dirs[i]) ) return 0;
        if(0 == command("go " + dirs[i])) return notify_fail("");// if go command returns with a value of 0, it will report an error. Zine 2014/7/30
		return 1;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        //如果是新房即使没出口
        if( (!living(this_object())
        ||      is_fighting()
        ||      !mapp(environment()->query("exits")))
        &&  (base_name(environment()) != "/d/xinfang/xinfang") ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());
        delete_temp("reset/times");
        delete_temp("reset/place");
        return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;

        if( !environment() || !living(this_object()))
                return 0;
        if ( query("neili") > 100 && living(this_object()) )
        {
                //added by jpei for busy no_exert
                if( (int)query_temp("no_exert") || is_busy() )
                        return 0;
                if( (int)query("eff_jing")<(int)query("max_jing") )
                        SKILL_D("force")->exert_function(this_object(), "inspire");
                if( (int)query("qi")*100/((int)query("eff_qi")+2) < 80 )
                        SKILL_D("force")->exert_function(this_object(), "recover");
                if( (int)query("jing")*100/((int)query("eff_jing")+2) < 70 )
                        SKILL_D("force")->exert_function(this_object(), "regenerate");
        }

        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0;

        if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
                if ( is_fighting() && time() - query_temp("last_chattime")<=1 )  //战斗过程中，随机发招频率不高于每2秒1招
                  return 0;
                
                if( random(100) < chance ) {
                        if (sizeof(msg) == 0)
                                return 0;
                        
                        set_temp("last_chattime", time() );
                        
                        rnd = random(sizeof(msg));
                        if( stringp(msg[rnd]) )
                                say(msg[rnd]);
                        else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}

// Default chat function: Let the npc cast his/her enabled spells
/*void cast_spell(string spell)
{
        string spell_skill;

        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}*/

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;
        int disorder;
        //added by whuan for no_exert
        //added by jpei for busy no_exert

        if( !func || query_condition("no_exert") || query_temp("no_exert")|| is_busy() )
                return 0;

//紊乱效果，有几率exert失败
        disorder=query_temp("apply/disorder_percent");
        if ( disorder && random(100)<disorder )
        {
        	start_busy(1);
        	return 0;
        }

        if( stringp(force_skill = query_skill_mapped("force")))
                SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with
// his/her enabled martial art
int perform_action(string action)
{
    object me;
    string martial_skill, skill, act;
    int disorder, result = 0;

    me = this_object();

    //added by whuan for no_perform
    //added by jpei for busy no_perform
    if( !action || query_condition("no_perform") || is_busy() || query("no_pfm"))
        return 0;
    if( !living(me) )
        return 0;
    if ( sscanf(action, "%s.%s", martial_skill, act) != 2 )
        return 0;
    //紊乱效果，有几率perform失败
    disorder=query_temp("apply/disorder_percent");
    if ( disorder && random(100)<disorder )
    {
        start_busy(1);
        return 0;
    }

    skill = query_skill_mapped(martial_skill);
    if( stringp(skill) && me->query_skill(skill, 1) )
    {
        result = SKILL_D(skill)->perform_action(me, act);
    }
    else if ( file_size(SKILL_D(martial_skill))>0 && me->query_skill(martial_skill, 1) )
    {
        result = SKILL_D(martial_skill)->perform_action(me, act);
    }

    return result;
}
/*int accept_object(object who,object obj)
{
   object me = this_object();
   mapping quest;
   if(undefinedp(quest = who->query("quest")))
      return 0;
   if(obj->query("name")==HIG"信"NOR && !userp(obj)
      && me->query("name") == quest["quest"] && quest["quest_type"] == "送" )
      {
         remove_call_out("accept_ok");
         call_out("accept_ok",0,me,who,obj);
         return 1;
      }
   else
      return 0;
}

void accept_ok(object me,object who,object obj)
{
  who->set_temp("quest_finish",1);
  message_vision("$N愉快的接受了$n送来的信。\n"
       +me->query("name")+"说：“快回去向你师父复命吧。”\n",me,who);
  destruct(obj);
}
*/

