/* Experimental code to generate 'action' sequences for monsters */

/* Some internal stuff */
#define MSETUPD "/std/rfc/monster_setup"
#define PUSH MSETUPD->push()
#define TEST MSETUPD->test()
#define POP  MSETUPD->pop()
#define DATA MSETUPD->get_data()

/* Single line */
#define ADD_CALL(obj,fun,arg1,arg2) MSETUPD->add_call(obj,fun,arg1,arg2)
#define _ADD_CALL(fun,arg1,arg2) ADD_CALL(MSETUPD,"fun",arg1,arg2)
#define ADD_LOCAL_CALL(fun,arg) _ADD_CALL(do_call,file_name(this_object()+"\b"+fun",arg)
#define ADD_MONSTER_CALL(fun,arg) _ADD_CALL(do_call_back,"fun",arg);

#define BREAK _ADD_CALL(do_break,0,0)

#define SAY(str) ADD_MONSTER_CALL(say,str)
#define ECHO(str) ADD_MONSTER_CALL(emote,str)
#define EMOTE(str) ADD_MONSTER_CALL(echo,str)
#define COMMAND(str) ADD_MONSTER_CALL(init_command,str)
#define MSG(str) ADD_MONSTER_CALL(msg,str)
#define KILL(str) _ADD_CALL(do_kill,str,0)

/* Blocks */
#define BLOCK(EXIT) for(PUSH;TEST;POP,(EXIT))
#define _ADD_CALL2(fun,arg) MSETUPD->add_call2(MSETUPD,"fun",arg,DATA)

#define SET_RESPONSES(ob) for(MSETUPD->start(),PUSH;TEST;POP,ob->set_responses(DATA))
#define MATCH(str) BLOCK(_ADD_CALL2(do_match,MSETUPD->fix_match(str)))
#define RANDOM(chance) BLOCK(_ADD_CALL2(do_random,chance))
#define DELAY(seconds) BLOCK(_ADD_CALL2(do_delay,seconds))

