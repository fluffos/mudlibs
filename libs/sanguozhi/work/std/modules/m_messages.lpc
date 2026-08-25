// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <sanguo.h>

/* General message handling.  Inherit it in anything that needs it.
 *
 * -Beek
 */

//:MODULE
// The message module.  The correct way to compose and send any messages
// To users is using this module, as it will automatically get the grammar
// right for each person involved.

/* More simul conversion fall out */
string punctuate(string);

#define A_SHORT(x) (objectp(x) ? x->a_short() : "一个" + x)
//#define SHORT(x) (objectp(x) ? x->short() : x)
#define SHORT(x) (objectp(x) ? x->query_chinese_id() : x)
mapping messages = ([]);
mapping def_messages = ([]);

void set_def_msgs(string type) {
    if (!(def_messages = MESSAGES_D->get_messages(type)))
        error("No messages of that type\n");
}

void add_msg(string cls, string msg) {
    if (!messages) messages = ([]);
    if (pointerp(messages[cls]))
        messages[cls] += ({ msg });
    else if (messages[cls]) {
        messages[cls]=({ messages[cls], msg });
    } else
        messages[cls]=msg;
}

string query_msg(string which) { return messages[which] || def_messages[which]; }

void set_msgs(string cls, string *msgs) {
    if (!messages) messages = ([]);
    if(!msgs || !sizeof(msgs))  {
         map_delete(messages, cls);
        return;
    }
    messages[cls] = msgs;
}

void clear_messages() {
    messages = ([]);
}

string *query_msg_types() {
    return keys(messages) + keys(def_messages);
}

//:FUNCTION compose_message
//The lowest level message composing function; it is passed the object
//for whom the message is wanted, the message string, the array of people
//involved, and the objects involved.  It returns the appropriate message.
//Usually this routine is used through the higher level interfaces.
// 
varargs string compose_message(object forwhom, string msg, object *who, 
                               mixed *obs...) {
    mixed ob;
    mixed *fmt;
    string res;
    int i;
    int c;
    int ch;
    int num, subj;
    string str;
    string bit;
    mapping has = ([]);
    int is_rumor=0;
    if(msg[<13..<1]=="~rumorstring~")
    {
       msg=msg[0..<14];
       is_rumor=1;
    }

    fmt = reg_assoc(msg, ({ "\\$[OoMmNnTtRrCcSs][a-z0-9]*" }), ({ 1 }) );
    fmt = fmt[0]; // ignore the token info for now

    res = fmt[0];
    i=1;
    while (i<sizeof(fmt)) {
        c = fmt[i][1];
        if (fmt[i][2] && fmt[i][2]<'a') {
            if (fmt[i][3] && fmt[i][3] < 'a') {
                subj = fmt[i][2] - '0';
                num = fmt[i][3] - '0';
                str = fmt[i][4..<0];
            } else {
                subj = 0;
                num = fmt[i][2] - '0';
                str = fmt[i][3..<0];
            }
        } else {
            subj = 0;
	    num = ((c == 't' || c == 'T' || c == 'c' || c == 'r' || c == 'R'
	    	  || c=='C' || c == 'm') ? 1 : 0); // target defaults to 1, not zero
            str = fmt[i][2..<0];
        }
        switch (c) {
        case 'O': // absolute name for obj added by fire with unit
            ob = obs[num];
            if (nullp(ob)) break;
            bit = "一"+ob->query_unit()+SHORT(ob);
            has[ob]++;
            break;
        case 'o':
            ob = obs[num];
            if (objectp(ob) && has[ob]) bit = "它";
            else {
                bit = SHORT(ob);
                has[ob]++;
            }
            break;
        case 't':
            if (str=="") str = "o";     // o means name first, pronoun next
        case 'T':
            /* Only difference between $n and $t is that $t defaults to $n1o */
            /* Fall through */
            if (str=="") str = "n";     // n for proper name.
        case 'n':
            if (str=="") str = "o";     // o means name first, pronoun next
        case 'N':
            if (str=="") str = "n";     // n for proper name.
            ch = str[0];
            if (ch != 'n' && ch != 'm') {
	        if (ch == 'c') {	// $N12c 中 2 相对于 1 的亲昵称呼
	            bit = CHENGHU_D->query_chenghu_c(who[subj],who[num]);
	            break;
	        }
	        if (ch == 'a') {	// $N1r 中 1 的尊称
	            bit = CHENGHU_D->query_chenghu_R(who[subj],who[num]);
	            break;
	        }
	        if (ch == 'h') {	// $N1q 中 1 的谦称
	            bit = CHENGHU_D->query_chenghu_s(who[num]);
	            break;
	        }
	        if (ch == 'r') {	// $N1m 中 1 的蔑称
	            bit = CHENGHU_D->query_chenghu_r(who[subj],who[num]);
	            break;
	        }
	        if (who[num]==forwhom) {
                    if (ch=='o' && has[who[num]]) bit = "你自己";
                    else bit = "你";
		    has[who[num]]++;
        	    break;
                }
	        if ((ch == 'p' || ch == 'o') && has[who[num]]) {
	            if (ch == 'o' && who[num] == who[subj]) 
	                bit = who[num]->query_pronoun() + "自己";
	            else bit = who[num]->query_pronoun();
		    if(!who[num]->is_living()) bit="它";
		    has[who[num]]++;
	            break;
	        }
	    }
            if (who[num]==forwhom && ch != 'm') {
                bit = "你";
                has[who[num]]++;
                break;
            }
            has[who[num]]++;
            if(is_rumor&&(num==0))
	    {
		bit="某人";
		break;
	    }
            bit = who[num]->query_chinese_id();
            break;
	case 'C' :
		bit=CHENGHU_D->query_chenghu_C(who[subj],who[num]);//表示亲近的自我称呼，通常在对话中
		break;
	case 'c' :
		bit=CHENGHU_D->query_chenghu_c(who[subj],who[num]);//表示亲近的对方称呼，通常在对话中
		break;
	case 'S' :
		bit=CHENGHU_D->query_chenghu_S(who[num]);//正常的自我称呼，通常在对话中
		break;
	case 's' :
		bit=CHENGHU_D->query_chenghu_s(who[num]); //谦卑的自我称呼，通常在对话中
		break;
	case 'R' :
		bit=CHENGHU_D->query_chenghu_R(who[subj],who[num]); //正常的对方称呼
		break;
	case 'r' :
		bit=CHENGHU_D->query_chenghu_r(who[subj],who[num]); //辱骂的对方称呼。
		break;
	case 'M' :
	case 'm' :
		bit=SHORT(who[num]); 
		break;

        }
        // hack to prevent errors.
        if (!bit) bit = "";
//### Hack to avoid inheriting a mixin.  Better one needed.
        if (fmt[i+1][0] == '.')
            res += M_GRAMMAR->punctuate(bit) + fmt[i+1][1..];
        else
            res += bit + fmt[i+1];
        i+=2;
    }
    return res;
}

//:FUNCTION action
//Make the messages for a given group of people involved.  The return
//value will have one array per person, as well as one for anyone else.
//inform() can be used to send these messages to the right people.
//see: inform

varargs string *action(object *who, mixed msg, mixed *obs...) {
    int i;
    string *res;

    if (pointerp(msg))
        msg = msg[random(sizeof(msg))];
    res = allocate(sizeof(who)+1);
    for (i=0; i<sizeof(who); i++) {
        res[i] = compose_message(who[i], msg, who, obs...);
    }
    res[sizeof(who)]=compose_message(0, msg, who, obs...);
    return res;
}

//:FUNCTION inform
//Given an array of participants, and an array of messages, and either an
//object or array of objects, deliver each message to the appropriate
//participant, being careful not to deliver a message twice.
//The last arg is either a room, in which that room is told the 'other'
//message, or an array of people to recieve the 'other' message.
void inform(object *who, string *msgs, mixed others) {
    int i;
    mapping done = ([]);
    for (i=0; i<sizeof(who); i++) {
        if (done[who[i]]) continue;
        done[who[i]]++;
        tell(who[i], msgs[i]);
    }
    if (pointerp(others))
    {
        map_array(others - who, (: tell($1, $(msgs[<1])) :));
    }
    else if (others)
    {
        tell_from_inside(others, msgs[sizeof(who)], MSG_INDENT, who);
    }
}

//:FUNCTION simple_action
//Generate and send messages for an action involving the user and possibly
//some objects
varargs void simple_action(mixed msg, mixed *obs...) {
    string us;
    string others;
    object *who;

    if( !sizeof( msg )) return;
    /* faster to only make who once */
    who = ({ this_object() });
    if (pointerp(msg))
        msg = msg[random(sizeof(msg))];
    if ( msg[<1] != '\n' )
        msg += "\n";

    us = compose_message(this_object(), msg, who, obs...);
    others = compose_message(0, msg, who, obs...);

    tell(this_object(), us, MSG_INDENT);
    tell_environment(this_object(), others, MSG_INDENT, who);
}

//:FUNCTION my_action
//Generate and send a message that should only be seen by the person doing it
varargs void my_action(mixed msg, mixed *obs...) {
    string us;
    object *who;

    if (!sizeof( msg )) return;
    who = ({ this_object() });
    if (pointerp(msg))
        msg = msg[random(sizeof(msg))];
    us = compose_message(this_object(), msg, who, obs...);
    tell(this_object(), us, MSG_INDENT);
}

//:FUNCTION other_action
//Generate and send a message that should only be seen by others
varargs void other_action(mixed msg, mixed *obs...) {
    string others;
    object *who;

    if( !sizeof(msg)) return;
    who = ({ this_object() });
    if (pointerp(msg))
        msg = msg[random(sizeof(msg))];
    others = compose_message(0, msg, who, obs...);
    tell_environment(this_object(), others, MSG_INDENT, who);
}

//:FUNCTION targetted_action
//Generate and send a message involving the doer and a target (and possibly
//other objects)
varargs void targetted_action(mixed msg, object target, mixed *obs...) {
    string us, them, others;
    object *who;

    if( !sizeof(msg)) return;
    who = ({ this_object(), target });
    if (pointerp(msg))
        msg = msg[random(sizeof(msg))];
    us = compose_message(this_object(), msg, who, obs...);
    them = compose_message(target, msg, who, obs...);
    others = compose_message(0, msg, who, obs...);
    tell(this_object(), us, MSG_INDENT);
    tell(target, them, MSG_INDENT);
    tell_environment(this_object(), others, MSG_INDENT, who);
}
