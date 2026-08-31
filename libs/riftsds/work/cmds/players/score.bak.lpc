#include <lib.h>

inherit LIB_DAEMON;

#define MAX_BAR_COLS 55

string bargraph(int gauge, int max, int flag) {
    string borg;
    int i, columns;

    if (!max) max = 1;
    columns = (MAX_BAR_COLS * gauge) / max - 1;

    if (flag) {
        switch (to_int(columns)) {
            case -100..6: borg = "%^FLASH%^%^B_RED%^%^YELLOW%^"; break;
            case 7..14: borg = "%^B_RED%^%^YELLOW%^"; break;
            case 15..30: borg = "%^YELLOW%^"; break;
            case 31..45: borg = "%^BLUE%^BOLD%^"; break;
            case 46..54: borg = "%^GREEN%^%^BOLD%^"; break;
            default: borg = ""; break;
        }
    } else {
        switch (to_int(columns)) {
            case -100..6: borg = ""; break;
            case 7..14: borg = "%^BOLD%^GREEN%^"; break;
            case 15..30: borg = "%^BOLD%^BLUE%^"; break;
            case 31..45: borg = "%^YELLOW%^"; break;
            case 46..50: borg = "%^B_RED%^%^BOLD%^"; break;
            default: borg = "%^FLASH%^%^B_RED%^%^YELLOW%^"; break;
        }
    }

    for (i = 0; i < MAX_BAR_COLS; i++) borg += (i <= columns ? "*" : " ");

    return borg;
}

string dashes = "----------------------------------------------------------------------";

int cmd_score(string who) {
    object tp, op;
    string title, alerts, hand2, ccatch, age3;
    string *attrib;
    int hp, max_hp, mp, max_mp, sp, max_sp, level, intox, qp, age2;

    tp = this_player();
    attrib = ({ "", "", "", "", "", "", "", "", });

    if (!who) {
        op = tp;
    } else if (!wizardp(tp)) {
        return 0;
    } else if (!(op = find_living(who))) {
        return 0;
    }

    level = op->GetLevel();
    title = op->GetShort();
    hp = op->GetHealthPoints();
    max_hp = op->GetMaxHealthPoints();
    mp = op->GetPPE();
    max_mp = op->GetMaxPPE();
    sp = op->GetStaminaPoints();
    max_sp = op->GetMaxStaminaPoints();
    ccatch = op->GetProperty("catch");

    age2 = op->GetAge();
    qp = op->GetQuestPoints();

    if (age2 > 86400) age3 = (age2 / 86400) + " Days";
    else if (age2 > 3600) age3 = (age2 / 3600) + " Hours";
    else age3 = (age2 / 60) + " Min";

    hand2 = "Unknown Handedness";

    attrib[0] = sprintf("%d", level);
    attrib[1] = op->GetRace() ? capitalize(op->GetRace()) : "N/A";
    attrib[2] = age3;
    attrib[3] = sprintf("%d", op->GetProperty("dev points"));

    intox = op->GetIntox();
    switch (intox) {
        case 420..10000: attrib[4] = "FUBAR"; break;
        case 300..419: attrib[4] = "Smashed"; break;
        case 180..299: attrib[4] = "Roaring drunk"; break;
        case 90..170: attrib[4] = "Drunk"; break;
        case 36..89: attrib[4] = "Tipsy"; break;
        case 1..35: attrib[4] = "Buzzed"; break;
        default: attrib[4] = "Sober"; break;
    }

    intox = op->GetDrink();
    switch (intox) {
        case 420..10000: attrib[5] = "Liquid Blob!"; break;
        case 300..419: attrib[5] = "Bloated"; break;
        case 180..299: attrib[5] = "Full"; break;
        case 90..170: attrib[5] = "Satisfied"; break;
        case 36..89: attrib[5] = "Thirsty"; break;
        case 1..35: attrib[5] = "Parched"; break;
        default: attrib[5] = "Dehydrated"; break;
    }

    intox = op->GetFood();
    switch (intox) {
        case 420..10000: attrib[6] = "Glutton!"; break;
        case 300..419: attrib[6] = "Distended"; break;
        case 180..299: attrib[6] = "Full"; break;
        case 90..170: attrib[6] = "Satisfied"; break;
        case 36..89: attrib[6] = "Hungry"; break;
        case 1..35: attrib[6] = "Malnourished"; break;
        default: attrib[6] = "Starving"; break;
    }

    attrib[7] = op->GetClass() ? capitalize(op->GetClass()) : "";
    alerts = op->GetPoison() ? "Poison " : " ";

    message("info", "%^BOLD%^%^WHITE%^" + sprintf("%|72s\n", title), tp);
    message("info", "%^BLUE%^" + sprintf("%s\n", dashes), tp);
    message("info", "%^BLUE%^       +------------------------------------------------------------+%^RESET%^\n", tp);
    message("info", "    HP %^BLUE%^|%^RESET%^" + bargraph(hp, max_hp, 1) + "%^RESET%^%^BLUE%^|%^RESET%^ " + hp + "\n", tp);
    message("info", "   SP %^BLUE%^|%^RESET%^" + bargraph(sp, max_sp, 1) + "%^RESET%^%^BLUE%^|%^RESET%^ " + sp + "\n", tp);
    message("info", "   MP %^BLUE%^|%^RESET%^" + bargraph(mp, max_mp, 1) + "%^RESET%^%^BLUE%^|%^RESET%^ " + mp + "\n", tp);
    message("info", "%^BLUE%^       +------------------------------------------------------------+\n", tp);
    message("info", "%^BLUE%^" + sprintf("%s\n", dashes), tp);
    message("info", "%^BLUE%^ Level: %^RESET%^" + sprintf("%-15s", attrib[0]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^GREEN%^          WEALTH\n", tp);
    message("info", "%^BLUE%^  Race: %^RESET%^" + sprintf("%-15s", attrib[1]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^" + sprintf("%12s:  %11i\n", "Credits", op->GetCurrency("credits")), tp);
    message("info", "%^BLUE%^   Age: %^RESET%^" + sprintf("%-15s", attrib[2]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n", tp);
    message("info", "%^BLUE%^ State: %^RESET%^" + sprintf("%-15s", attrib[4]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n", tp);
    message("info", "%^BLUE%^Thirst: %^RESET%^" + sprintf("%-15s", attrib[5]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|--------------------------\n", tp);
    message("info", "%^BLUE%^Hunger: %^RESET%^" + sprintf("%-15s", attrib[6]) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^ Experience:  " + sprintf("%12i\n", op->GetExperiencePoints()), tp);
    message("info", "%^BLUE%^Catch:  %^RESET%^" + sprintf("%-15s", ccatch) + "%^BLUE%^|%^RESET%^" + "                   " + "%^BLUE%^|%^RESET%^\n", tp);
    message("info", "%^BLUE%^Alerts: %^RESET%^" + sprintf("%-15s", alerts) + "%^RESET%^%^BLUE%^|                   |%^RESET%^\n", tp);
    message("info", sprintf("%-21s", hand2) + "  %^BLUE%^|%^RESET%^                   " + "%^BLUE%^|%^RESET%^\n", tp);
    message("info", "%^BLUE%^" + sprintf("%s\n", dashes) + "%^RESET%^", tp);

    return 1;
}

int help() {
    write(@HELP
Syntax:  score [person]
This command gives you information about your character.

See also: status, biography, skills, stats, money, inventory
HELP
    );
    return 1;
}
