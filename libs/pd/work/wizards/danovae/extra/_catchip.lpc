
#include <std.h>
#include <daemons.h>

#define DEFAULT_SORT "i";


inherit DAEMON;

string list_users(string *ips, string order);

int cmd_catchip(string str) {
   string *ips;
   string order;
   int i;

   ips = ({});
   order = DEFAULT_SORT;
   if(str) {
      i = sizeof(args = explode(str, " "));
      while(i--) {
         if(args[i][0] == '-' && strlen(args[i]) > 1) order = args[i][1..1];
         else if(PLAYER_D->is_player(args[i])) ips += ({ args[i] });
      }
   }

string list_users(string *ips, string order) {
   object *who, *ims, *pls, *adm;
   string tmp, borg;
   int i, max, x;
   ims = ({});
   pls = ({});
   who = filter_array(users(), "which_users", this_object(), ips);
   for(x=0;x<sizeof(who);x++) {
      if(archp(who[x]))
      if(!adm) adm = ({ who[x] }); else adm += ({ who[x] });
 else if(wizardp(who[x]))
      if(!ims) ims = ({ who[x] }); else ims += ({ who[x] });
 else if(!pls) pls = ({ who[x] }); else pls += ({ who[x] });
   }
switch(order) {
   case "i":
            pls = sort_array(pls, "sort_by_ip", this_object());
            break;
   default:
      pls = sort_array(pls,"sort_by_ip", this object());
      break;


borg = "%^MAGENTA%^";
borg += "~~~~~~~~~~~~~~~~~~~~~~~~~~~";
borg += "%^BOLD%^[%^RESET%^ ";
borg += "Primal Darkness";
borg += "%^BOLD%^%^MAGENTA%^ ]%^RESET%^";
borg += "%^MAGENTA%^~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%^RESET%^";

   max = sizeof(adm);
if(max)
   for i=0; i<max; i++) {
      tmp = "%^BOLD%^%^RED%^[%^WHITE%^ Admin%^RED%^ ]%^RESET%^ ";
      if((string)adm[i]->query_ip())
         tmp+= (string)adm[i]->query_ip();
      else
         tmp += "("+capitalize((string)adm[i]->query_name())+")";
            tmp = arrange_string(tmp, 55);
            borg += "%^BOLD%^%^RED%^"+tmp;
            tmp = capitalize((string)adm[i]->query_position());
            tmp = arrange_string(tmp, 13);
            tmp += "\n";
            borg += "%^BOLD%^"+tmp;
   }
   max = sizeof(ims);
   if(max)
   for(i=0; i<max; i++) {
      tmp = "%^BOLD%^%^BLUE%^[%^WHITE%^Creator%^BLUE%^]%^RESET%^ ";
               if((string)ims[i]->query_ip())
                tmp+= (string)ims[i]->query_ip();
      else
                tmp += "("+capitalize((string)ims[i]->query_name())+")";
        tmp = arrange_string(tmp, 55);
        borg += "%^BOLD%^%^RED%^"+tmp;
        tmp = capitalize((string)ims[i]->query_position());
        tmp = arrange_string(tmp, 13);
        tmp += "\n";
        borg += ""+tmp;
   }

    max = sizeof(pls);
   if(max)
        for(i=0; i<max; i++) {
            tmp = "%^BOLD%^%^GREEN%^[%^WHITE%^Vulture%^GREEN%^]%^RESET%^";
            tmp = arrange_string(tmp, 9);
            borg += tmp;
            if((string)pls[i]->query_ip()) {
                tmp = (string)pls[i]->query_ip();
                tmp = arrange_string(tmp, 45);
      }
      else {
                tmp = "("+(string)pls[i]->query_cap_name()+")";
                tmp = arrange_string(tmp, 45);
      }
            borg += tmp;
            tmp=" %^BOLD%^";
"%^RESET%^%^MAGENTA%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   return borg;
}


int sort_by_ip(object alpha, object beta) {
   return strcmp((string)alpha->query_ip(), (string)beta->query_ip());
}

void help() {
   write(
      "Syntax: <catchip>\n\n"+
      "List players by IP, used to easily identify cheating.\n\n"
}

