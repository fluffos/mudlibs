/* Prompt stuff by Cendor in 30th Aug 1997 */
#define TP this_player()


string prom;

string set_prom(string str) { return prom = str; }

string query_prom() { return prom; }



string parse_prompt(string msg) {

string rest; 

if(!msg) msg = ">";

while(sscanf(msg,"%s$hp%s", msg, rest))   msg += TP -> query_hp() + rest;

while(sscanf(msg,"%s$sp%s", msg, rest))   msg += TP -> query_sp() + rest;

while(sscanf(msg,"%s$spmax%s", msg, rest))   msg += TP -> query_max_sp() + rest;

while(sscanf(msg,"%s$hpmax%s", msg, rest))   msg += TP -> query_max_hp() + rest;

while(sscanf(msg,"%s$ep%s", msg, rest))   msg += TP -> query_ep() + rest;

while(sscanf(msg,"%s$epmax%s", msg, rest))   msg += TP -> query_max_ep() + rest;

while(sscanf(msg,"%s$level%s", msg, rest))   msg += TP -> level() + rest;


while(sscanf(msg,"%s$time%s", msg, rest))   msg += ctime(time()) + rest;  

set_prompt(msg);

return msg;  

}



