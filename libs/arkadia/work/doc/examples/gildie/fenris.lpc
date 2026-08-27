/*
 *  Przyklad trenera umiejetnosci.
 *
 *  /doc/examples/trade/fenris.c
 *
 *  dzielo Silvathraeca 1997
 */

inherit "/std/monster";		/* Humanoidalny npc */
inherit "/lib/skill_raise";	/* Obsluga treningu umiejetnosci */

#include <macros.h>
#include <ss_types.h>
#include <stdproperties.h>
#include <tasks.h>

/* Definicje niestandardowych umiejetnosci */

#define SS_PYROTECH	101666	/* Patrz man skill_list - dodatkowa */
                                /* umiejetnosc domeny Wiz. :) */

/* Format - patrz /config/sys/ss_types2.h */

#define LOCAL_SKILLS ([ \
    SS_PYROTECH:							\
        ({"pirotechnika", "pirotechnike", "wysadzaniu przedmiotow, miejsc i osob",\
          100, ([TS_WIS:45, TS_DIS:60, SS_ALCHEMY:50]), 20}),		\
])

#define MAX_PYRO	100	/* Bedzie kilkakrotnie uzywane... */

object *przedstawieni = ({});

void
create_monster()
{
    ustaw_imie(({"fenris", "fenrisa", "fenrisowi", "fenrisa", "fenrisem",
                 "fenrisie"}), PL_MESKI_OS);

    set_title("Reidemeister, Naczelny Gnomi Pyrotechnik");

    ustaw_odmiane_rasy(PL_GNOM);

    dodaj_przym("podejrzliwy", "podejrzliwi");
    dodaj_przym("nerwowy", "nerwowi");

    set_long("Niski, lysawy gnom o kaprawych, rozbieganych oczkach lypiacych "
           + "podejrzliwie na wszystkie strony. Jego ubranie pokryte jest "
           + "jakimis tajemniczymi plamami woniejacymi zapachem chemikaliow, "
           + "z pomaranczowej, lekko przerzedzonej brody stercza pakuly i "
           + "inne dziwne smieci. Jego wyglad nasuwa podejrzenie, ze zajmuje "
           + "sie jakimis dziwnymi eksperymentami. Kto wie, moze zechcialby "
           + "podzielic sie z toba swoja wiedza?\n");

    set_gender(G_MALE);

    add_prop(CONT_I_WEIGHT, 49152);	/* 3 * 2^14, jesli ktos nie zauwazyl */
    add_prop(CONT_I_HEIGHT, 118);

    set_stats(({34, 66, 52, 98, 72, 48}));

    set_skill(SS_WEP_KNIFE, 35);
    set_skill(SS_DEFENCE, 13);
    set_skill(SS_ALCHEMY, 63);
    set_skill(SS_AWARENESS, 28);
    set_skill(SS_PYROTECH, 100);

    set_alignment(130);

    set_act_time(16);
    add_act("emote przyglada ci sie uwaznie.");
    add_act("splun od niechcenia");
    add_act("podrap sie");
    add_act("rozejrzyj sie z roztargnieniem");
    add_act("ziewnij przeciagle");
    add_act("emote zaczyna pogwizdywac, potwornie falszujac.");

    set_cact_time(16);
    add_cact("powiedz W twarz? W twarz?!");
    add_cact("powiedz Wyjdz, bo cie zabije!");
    add_cact("krzyknij Gwaltu! Mordercy!");
    add_cact("emote potyka sie o wlasna brode.");

    set_default_answer(VBFC_ME("default_answer"));

    sk_add_skills(LOCAL_SKILLS);	/* Niestandardowe umiejetnosci */

    sk_add_train(SS_ALCHEMY, 20);	/* Umozliwia trening do podanego */
    sk_add_train(SS_PYROTECH, MAX_PYRO);/* poziomu */
}

void
init_living()
{
    init_skill_raise();			/* Dodaje komende 'trenuj' */
    ::init_living();
}

string
default_answer()
{
    command("powiedz Czy mogl" + this_player()->koncowka("bys", "abys")
          + " wyrazac sie nieco jasniej, "
          + this_player()->koncowka("synku", "corus") + "? Nie mam "
          + "pojecia, o co ci chodzi.");
    command("popatrz z namyslem na " + OB_NAME(this_player()));
    command("powiedz Hmm... Nie wygladasz co prawda najinteligentniej, ale "
          + "jesli chcesz, moge cie czegos nauczyc.");

    return "";
}

void
add_introduced(string imie_mia, string imie_bie)
{
    set_alarm(2.0, 0.0, "return_introduce", find_player(imie_mia));
}

void
return_introduce(object ob)
{
    if (ob && environment(ob) == environment())
        if (member_array(ob, przedstawieni -= ({0})) != -1)
        {
            command("powiedz Witaj ponownie, " + ob->query_wolacz() + ".");
            command("usmiechnij sie do " + OB_NAME(ob));
        }
        else
        {
            przedstawieni += ({ob});
            command("przedstaw sie " + OB_NAME(ob));
            command("uklon sie " + OB_NAME(ob) + " z godnoscia");
        }
}

/* W zasadzie to juz wszystko, co jest potrzebne... Mozemy jednak sie jeszcze
   pobawic, roznicujac maksymalny poziom umiejetnosci dostepny dla graczy.
   Zauwazmy, ze identycznie mozemy postapic, jesli chcemy na przyklad trenowac
   czlonkow gildii zaleznie od ich statusu gildiowego. */

/*
 * Jak widac, Fenris lubi osoby o dlugim imieniu, ciekawe dlaczego... :)
 * Zamiast tego, moglibysmy uzaleznic maksymalny trenowany poziom od statu
 * gildiowego, zajmowanego stanowiska, jakiegos rodzaju gildiowego prestizu,
 * zrobionych questow, etc.
 */
int
sk_query_max(int snum)
{
    if (snum == SS_PYROTECH)
    {
        int temp = 10 * strlen(this_player()->query_real_name());

        return temp > MAX_PYRO ? MAX_PYRO : temp;
    }

    return ::sk_query_max(snum);
}

/*
 * Zmieniamy nieco standardowy tekst wyswietlany graczowi, gdy usiluje
 * szkolic sie ponad maksymalny poziom.
 */
int
sk_hook_improved_max(int snum, int level)
{
    if (snum == SS_PYROTECH && level < MAX_PYRO)
    {
        notify_fail(sk_answer("Obawiam sie, ze w tej dziedzinie nie naucze "
                            + "cie juz nic nowego. Co innego, gdyby twoje "
                            + "imie bylo nieco dluzsze... wtedy, byc moze, "
                            + "zechcialbym nauczyc cie wiecej."));
        return 0;
    }

    return ::sk_hook_improved_max(snum, level);
}