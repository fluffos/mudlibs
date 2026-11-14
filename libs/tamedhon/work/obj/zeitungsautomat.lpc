inherit "/std/thing";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <defines.h>
#include <config.h>
#include <www.h>

#define SLP "/p/service/loco/obj/zeitung/slp"
// #define RENEW_NEWS

int get(mixed targ);

void create()
{
  if (!clonep(this_object())) return;
  ::create();
  SetProp(P_SHORT,"Eine Zeitung");
  SetProp(P_LONG, 
      "Du erblickst ein Exemplar der "+MUDNAME+"-Presse, kurz TDP, der "
      "Zeitung des "+MUDNAME+"s. "
      "Hier stehen immer die neuesten Nachrichten und Gerüchte drin.");
  SetProp(P_NAME,"Zeitung");
  AddId(({"zeitung","tdp"}));
  SetProp(P_GENDER, FEMALE);
  SetProp(P_ARTICLE, 1);
  SetProp(P_WEIGHT, 0);
  SetProp(P_NOGET, "");
  SetProp(P_MATERIAL, MAT_PAPER);
  SetProp(P_WWWINFO, "Man kann die Zeitung auch "+
      "<A HREF=\"http://"+SERVER+MUDWWW+"?"+REQ+"="+R_NEWS+"\">lesen</A>.\n");
}

varargs int move(mixed target,mixed method,mixed mess)
{
  if ((method & M_GET) && living(target))
    // Da sich das Objekt (der Automat) nach dem Nehmen nicht
    // im Inventory des Nehmers befindet, nimmt put_and_get::pick_obj()
    // an, dass das Nehmen nicht erfolgreich war. Wir bestaetigen das
    // hier einfach, da aber P_NOGET=="" ist, merkt der Spieler nix :)
    return get(target), ME_CANT_BE_TAKEN;
  else
    return ::move(target,method,mess);
}

int get(mixed targ)
{
  object ob;
  if (!targ || !interactive(targ) || targ != this_player())
    return 0;
  if (ob=present("zeitung", targ))
  {
#ifdef RENEW_NEWS
    ob->remove();
    clone_object(SLP)->move(targ, M_GET);
    write("Du wirfst Deine alte Zeitung weg und "
        "nimmst Dir ein neues Exemplar.\n");
    say(targ->Name(WER) + " wirft "+targ->QueryPossPronoun(FEMALE, WEN, SINGULAR)+
        " alte Zeitung weg und nimmt sich ein neues Exemplar.\n");
    return 1;
#else
    write("Du hast bereits eine Zeitung.\n");
    return ME_CANT_BE_TAKEN;
#endif
  }
  clone_object(SLP)->move(targ, M_GET);
  write("Du nimmst die Zeitung. "
      "Sofort erscheint auf unerklärliche Weise eine neue.\n");
  say(targ->Name(WER) + " nimmt die Zeitung.\n"
      "Sofort erscheint auf unerklärliche Weise eine neue.\n");
  return 1;
}
