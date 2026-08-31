#include <sys_defs.h>
#include <sys_levels.h>

#pragma strict_types
#pragma save_types

int iIdleC, iImmortal, iMortal;

string level(object oOb) {
    int iLegend, iLevel;

    if((int)oOb->IMM)
        iImmortal++;
    else
        iMortal++;

    iLevel = (int)oOb->query_level();
    iLegend = (int)oOb->query_legend_level();
    if(oOb->TESTP)
        return capitalize((string)oOb->TESTP)[0..3];
    else if(iLegend && !oOb->IMM) {
        if(iLegend < 10)
            return "L "+iLegend;
      else
            return "L"+iLegend;
    }
    else
        return ""+iLevel;
/*
  else {
    switch(lv) {
      case -1..L_PLAYER:
        return rightAlign(iLevel+"", maxlvlchr);
        break;
      case L_APPR..L_NEWWIZ-1:
        return "App";
        break;
      case L_NEWWIZ..L_WIZ-1:
        return "New";
        break;
      case L_WIZ..L_SAGE-1:
        return "Wiz";
        break;
      case L_SAGE..L_RETD-1:
        return "Sge";
        break;
      case L_RETD..L_ELDER-1:
        return "Rtd";
        break;
      case L_ELDER..L_ARCH-1:
        return "Eld";
        break;
      case L_ARCH..L_GOD-1:
        return "Arc";
        break;
      case L_GOD:
        return "God";
        break;
      default:
        return "?";
        break;
    }
  }
*/
}

string idle(object oOb) {
    string sStr;
    int    i, j;

    i = query_idle(oOb);
    switch(i) {
        case 0..59:
            sStr = " - ";
            break;
        case 60..3599:
            j = i/60;
            iIdleC++;
            sStr = sprintf("%dm", j);
            break;
        default:
            j = i/3600;
            iIdleC++;
            sStr = sprintf("%dh", j);
            break;
    }
    return sStr;
}

string sex(object oOb) {
    int iGender;

    iGender = (int)oOb->query_gender();
    if(iGender == 1)
        return " m ";
    else if(iGender == 2)
        return " f ";
    else
        return " x ";
}

string guild(object oOb) {
    int iGuild;

    iGuild = (int)oOb->query_real_guild();
    return capitalize((string)GM->query_name(iGuild));
}

string race(object oOb) {
    string sRace;

    sRace = (string)oOb->query_race();
    if(!sRace || sRace == "")
        sRace = "-";

    if((string)oOb->query_real_name() == "thorm")
        return ":)";
    else
       return capitalize(sRace);
}

int main() {
    int    i, j, iMax;
    object *oUs;

    oUs = sort_array(users(), lambda(({'oOb1, 'oOb2}),
                                     ({#'>,
                                         ({#'query_ip_number, 'oOb1}),
                                         ({#'query_ip_number, 'oOb2})
                                     })));
    iMax = sizeof(oUs);
    iIdleC = iImmortal = iMortal = 0;
    if(iMax == 1) {
        printf("%|'='78s\n",
               sprintf(" %s: %s ", MUD_NAME, ctime()));
        printf("%-3s %-10s Idl Sex %-4s %-10s\n",
               "Lvl", "Name", "Gld", "Race");
    }
    else {
        printf("%|'='78s\n",
               sprintf(" %s: %s ",MUD_NAME,ctime()));
        printf("%4s %-10s Idl Sex %-4s %-9s %4s %-10s Idl Sex %-4s %-9s\n",
               "Lvl", "Name", "Gld", "Race",
               "Lvl", "Name", "Gld", "Race");
    }
    printf("%|'-'78s\n", "-");
    for(i = 0; i < iMax; i += 2) {
        printf("%4s %-10s %3s %-3s %-4s %-9s",
               level(oUs[i]),
               ((string)oUs[i]->CRNAME)[0..9],
               idle(oUs[i]),
               sex(oUs[i]),
               guild(oUs[i])[0..3],
               race(oUs[i])[0..8]);
        if(i+1 < iMax)
            printf(" %4s %-10s %3s %-3s %-4s %-9s",
                   level(oUs[i+1]),
                   ((string)oUs[i+1]->CRNAME)[0..9],
                   idle(oUs[i+1]),
                   sex(oUs[i+1]),
                   guild(oUs[i+1])[0..3],
                   race(oUs[i+1])[0..8]);
        write("\n");
    }
    printf("%|'='78s\n",
           sprintf(" %d player%s online (%d active)%s ",
                   iMax, (iMax == 1 ? "" : "s"), iMax-iIdleC,
                   iMax > 1 ?
                       sprintf(": %s immortal%s, %s mortal%s",
                               (iImmortal ? ""+iImmortal : "no"),
                               (iImmortal == 1 ? "" : "s"),
                               (iMortal ? ""+iMortal : "no"),
                               (iMortal == 1 ? "" : "s")) :
                       ""));
  return 1;
}
