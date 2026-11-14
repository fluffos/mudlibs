//  Projekt   : Barry's Pfeifenladen
//  Objekt    : Sequenz fuers Suedsternrauchen
//  Erstellt  : 02.06.2001 (Orw)
//  Geaendert : -

#define KRAFTTIER ({"Kartoffelkaefer","Leguan","Regenwurm", \
                    "Ameisenbaer","Grashuepfer","Kuckuck", \
                    "Ochsenfrosch","Panther","Pinguin", \
		    "Loewe","Schimpanse","Kater", \
		    "Alligator","Gorilla","Hirtenhund", \
		    "Stier","Esel","Salamander", \
		    "Igel","Wolf","Leopard", \
		    "Elephant","Weberknecht","Uhu" })
int art = random(24);

int sternrauchen1(object raucher)
{
  if(raucher)
  {
    write(BS("Mit jedem Zug schwinden Deine Sinne ein klein wenig mehr.\n"
          "Du verlierst Dich in Gedanken.\n\n"));
    say  (BS(raucher->name()+" raucht genuesslich "+raucher->QueryPossPronoun(MALE,WEN)+
              " Suedstern.\n"));
    raucher->SetProp(P_PARALYZED,
      ([PARALYZE_TIME:-1,
        PARALYZE_MSG:"Du bist zu benebelt von der Wirkung des Suedsterns.\n",
        PARALYZE_MSG_OTHER:"Benommen taumelt %s herum.\n",
        PARALYZE_END:"Langsam kehrt die Kontrolle ueber Deinen Koerper zurueck.\n",
        PARALYZE_END_OTHER:"%s erwacht aus dem Trancezustand.\n"]));
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert);
    }
    call_out("sternrauchen2", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen2(object raucher)
{
  if(raucher)
  {
    write(BS("Du schliesst Deine Augen und entspannst Deinen Koerper.\n\n"));
    say  (BS(raucher->name()+" schliesst "+raucher->QueryPossPronoun(FEMALE,WEN)+
              " Augen und entspannt sich total.\n"));
    call_out("sternrauchen3", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen3(object raucher)
{
  if(raucher)
  {
    write(BS("Ein wohlig warmes Gefuehl breitet sich in Dir aus und Du "
          "faellst in eine Art Trancezustand.\n\n"));
    say  (BS(raucher->name()+" pafft laechelnd "+raucher->QueryPossPronoun(FEMALE,WEN)+
              " Pfeife.\n"));
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert);
    }
    call_out("sternrauchen4", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen4(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Laessig blaest Du "+RINGERL[formringerl]+" und starrst dabei "
          "ein Loch in die Luft.\n\n"));
    say  (BS(raucher->name()+" blaest "+RINGERL[formringerl]+".\n"));
    call_out("sternrauchen5", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen5(object raucher)
{
  if(raucher)
  {
    write(BS("Tief in Trance versunken findest Du Dich ploetzlich auf einer "
          "Lichtung im Dschungel wieder. Erschrocken drehst Du Dich um als "
          "Du ein Geraeusch hinter Dir vom Rand der Lichtung hoerst.\n\n"));
    say  (BS(raucher->name()+" dreht sich mit erschrockenem Blick um.\n"));
    call_out("sternrauchen6", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen6(object raucher)
{
  if(raucher)
  {
    write(BS("Aus dem Dickicht taucht ploetzlich ein Tier auf. Du erkennst "
          "es, es ist Dein Krafttier... ein "+KRAFTTIER[art]+".\n\n"));
    say  (BS(raucher->name()+" benimmt sich merkwuerdig.\n"));
    call_out("sternrauchen7", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen7(object raucher)
{
 if(raucher)
 {
  if(raucher->QueryProp(P_POISON)>0)
  {
    write(BS("Der "+KRAFTTIER[art]+" guckt Dich grinsend an.\n"
          "Der "+KRAFTTIER[art]+" sagt: Hallo "+raucher->name()+"! Oh, Du bist ja "
          "vergiftet!\n"
          "Der "+KRAFTTIER[art]+" sagt: Lass mich Dir helfen...\n\n"));
    say  (BS(raucher->name()+" entspannt sich wieder.\n"));
    call_out("sternrauchen8", 15+random(5),raucher);
    return 1;
  }
  if(raucher->QueryProp(P_HP)<raucher->QueryProp(P_MAX_HP))
  {
    write(BS("Der "+KRAFTTIER[art]+" guckt Dich grinsend an.\n"
          "Der "+KRAFTTIER[art]+" sagt: Hallo "+raucher->name()+"! Oh, Dir gehts aber "
          "nicht gut...!\n"
          "Der "+KRAFTTIER[art]+" sagt: Lass mich Dir helfen...\n\n"));
    say  (BS(raucher->name()+" entspannt sich wieder.\n"));
    call_out("sternrauchen8", 15+random(5),raucher);  
  }
  else
  {
    write(BS("Der "+KRAFTTIER[art]+" guckt Dich grinsend an.\n"
          "Der "+KRAFTTIER[art]+" sagt: Hallo "+raucher->name()+"! Freut mich Dich gesund "
          "anzutreffen.\n"
          "Der "+KRAFTTIER[art]+" sagt: Wenns Dir mal nicht gut geht "
          "kannst Du mich hier besuchen.\n\n"));
    say(BS(raucher->name()+" entspannt sich wieder.\n"));
    call_out("sternrauchen9", 15+random(5),raucher);
  }
 }
 else
 {
   pfeifeangezuendet=0;
   return 1;
 }
}

int sternrauchen8(object raucher)
{
  if(raucher)
  {
    write(BS("Der "+KRAFTTIER[art]+" beginnt eine leise Melodie zu summen.\n"
          "Du fuehlst Dich ploetzlich viel besser.\n\n"));
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->AddPoison(-(5+random(4)));
      raucher->heal_self(pfeifenwert+art+random(50));
    }
    else
    {
      raucher->AddPoison(-(1+random(4)));
      raucher->heal_self(pfeifenwert+art);
    }
    say  (BS(raucher->name()+" laechelt benommen.\n"));
    call_out("sternrauchen9", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int sternrauchen9(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    raucher->SetProp(P_PARALYZED,0);
    write(BS("Du wachst wieder auf, blaest noch "+RINGERL[formringerl]+" und "
          "dann ist der ganze Suedstern auch schon wieder aufgeraucht. "
          "Zufrieden steckst Du die Pfeife wieder weg.\n\n"));
    say  (BS(raucher->name()+" blaest noch "+RINGERL[formringerl]+" und steckt die Pfeife "
          "wieder weg.\n"));
    SetProp(P_SHORT, pfeifenname);
    SetProp(P_NODROP, 0);
    SetProp(P_NEVERDROP, 0);
    pfeifegestopft_stern=0;
    pfeifeangezuendet=0;
    return 1;
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}
