
/* defines for the fighters */


mixed call;

void reset(int flag)
{
    if (flag == 0)
       call = (: call_other :);
}

#define _tp   this_player()
#define _tpn  evaluate(call,_tp,"query_name")
#define _tpr  evaluate(call,_tp,"query_real_name")
#define _tpp  evaluate(call,_tp,"query_possessive")
#define _tpl  evaluate(call,_tp,"query_level")
#define _tpo  evaluate(call,_tp,"query_pronoun")
#define _tps  evaluate(call,_tp,"query_sp")
#define _tph  evaluate(call,_tp,"query_hp")
#define _tpw  evaluate(call,_tp,"query_wis")
#define _tpd  evaluate(call,_tp,"query_dex")
#define _tpst evaluate(call,_tp,"query_str")
#define _tpi  evaluate(call,_tp,"query_int")
#define _tpc  evaluate(call,_tp,"query_con")
#define _e   environment
#define _gm  "/guild/master"

