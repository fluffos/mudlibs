/*  -*- LPC -*-  */

inherit COMMAND_BASE;

#include <login_handler.h>

int playercompare(object p1, object p2);

int cmd(string guild_name) {
    int i;
    int countcre;
    int countplay;
    int counttest;
    int countloginq;
    int countlogins;
    string obtyp;
    string tmp;
    object *arr;
    string nam;
    string cres;
    string plays;
    string testers;
    string *login_q;
    string logins;

    countcre = 0;
    countplay = 0;
    counttest = 0;
    cres = "";
    plays = "";
    testers = "",
    logins = "";
    arr = sort_array(users(), (: playercompare :));
    arr = filter(arr, (: !$1->query_invis() ||
        $1->query_visible(this_player()) :) );

    if (guild_name) {
        // Do weird filtering!
        arr = "/cmds/player/who"->filter_users(arr, guild_name);
        if (!sizeof(arr)) {
            add_failed_mess("Unable to find any members of " + 
              guild_name + ".\n");
            return 0;
        }
    }

    for(i=0;i<sizeof(arr);i++) {
        nam = arr[i]->query_cap_name();
        switch (arr[i]->query_invis()) {
        case 0:
            break;
        case 1:
            nam = "[" + nam + "]";
            break;
        case 2:
            nam = "[{" + nam + "}]";
            break;
        case 3:
            nam = "[<" + nam + ">]";
            break;
        default:
            nam = "?" + nam + "?";
            break;
        }
        obtyp = arr[i]->query_object_type();
        switch(obtyp) {
        case "X":
            break;
        case " ":
            break;
        case "C":
            nam += "(%^CYAN%^C%^RESET%^)";
            if ( DOMAIN_H->query_member("liaison",(string)arr[i]->query_name())) {
                nam += "(%^YELLOW%^l%^RESET%^)";
            }
            break;
        case "S":
            nam += "(%^BOLD%^%^CYAN%^S%^RESET%^)";
            if ( DOMAIN_H->query_member("liaison",(string)arr[i]->query_name())) {
                nam += "(%^YELLOW%^l%^RESET%^)";
            }
            break;
        case "A":
            nam += "(%^BOLD%^%^RED%^A%^RESET%^)";
            if ( DOMAIN_H->query_member("liaison",(string)arr[i]->query_name())) {
                nam += "(%^YELLOW%^l%^RESET%^)";
            }
            break;
        case "L":
            nam += "(%^RED%^L%^RESET%^)";
            if ( DOMAIN_H->query_member("liaison",(string)arr[i]->query_name())) {
                nam += "(%^YELLOW%^l%^RESET%^)";
            }
            break;
        default:
            break;
        }
        if (creatorp(arr[i])) {
            countcre++;
            cres = cres + " " + nam;
        } else if (obtyp == "p") {
            counttest++;
            testers = testers + " " + nam;
        } else if(arr[i]->query_login_ob()) {
            countlogins++;
            logins = logins + " " + nam;
        } else {
            countplay++;
            plays = plays + " " + nam;
        }
    }

    login_q = map(LOGIN_HANDLER->query_login_queue(),
      (: $1->query_cap_name() :));
    login_q = filter(login_q, (: $1 :));
    login_q = sort_array(login_q, 1);
    countloginq = sizeof(login_q);

    write("%^BOLD%^" + countcre + " Creators:%^RESET%^" + cres + "\n");
    if (guild_name != "creator" && guild_name != "creators") {
        switch (counttest) {
        case 0:
            break;

        case 1:
            write("%^BOLD%^" + counttest + " Playtester:%^RESET%^" + testers + "\n");
            break;

        default:
            write("%^BOLD%^" + counttest + " Playtesters:%^RESET%^" + testers + "\n");        
            break;
        }

        write("%^BOLD%^" + countplay + " Players:%^RESET%^" + plays + "\n");
        if (countlogins < countloginq) {
            countlogins = countloginq;
        }
        if (countlogins-countloginq) {
            logins = replace(logins, ({ "[", "", "]", ""}));
            if(countloginq) {
                foreach(tmp in login_q) {
                    logins = replace(logins, tmp+" ", "");
                }
            }
            write("%^BOLD%^" + (countlogins - countloginq) +
              " Logging in:%^RESET%^" + logins + "\n");
        }

        if(countloginq) {
            write("%^BOLD%^" + countloginq + " Queued:%^RESET%^ " +
              implode(login_q, " ") + "\n");
        }
    } else {
        countlogins = 0;
        counttest = 0;
        countplay = 0;
    }

    write("%^BOLD%^" + (countcre + counttest + countplay + countlogins) +
      " Total%^RESET%^\n");

    return 1;
} /* cmd() */

int playercompare(object p1, object p2) {
    return strcmp(p1->query_name(), p2->query_name());
} /* playercompare() */

mixed *query_patterns() {
    return ({ "", (: cmd(0) :),
      "<string'guild name'>", (: cmd($4[0]) :) });
} /* query_patterns() */
