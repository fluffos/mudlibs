//  Projekt   : Barry's Pfeifenladen
//  Objekt    : Sequenz fuers Grottenkrautrauchen
//  Erstellt  : 19.03.2001 (Orw)
//  Geaendert : -



int krautrauchen1(object raucher)
{
  if(raucher)
  {
    write(BS("Kleine Rauchwoelkchen kommen aus Deiner Pfeife und Du fuehlst Dich\n"
          "so richtig wohl. Das Grottenkraut ist echt nicht schlecht.\n"));
    say  (raucher->name()+" raucht genuesslich "+
          raucher->QueryPossPronoun(NEUTER,WEN)+" Grottenkraut.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert+5);
    }
    else
    {
      raucher->heal_self(random(5));
    }
    call_out("krautrauchen2", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int krautrauchen2(object raucher)
{
  if(raucher)
  {
    write(BS("Du paffst entspannt Deine Pfeife und versuchst kleine Ringerl in der\n"
          "Luft entstehen zu lassen.\n"));
    say  (raucher->name()+" raucht entspannt "+raucher->QueryPossPronoun(FEMALE,WEN)+" Pfeife.\n");
    call_out("krautrauchen3", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int krautrauchen3(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Nach einigen Versuchen schaffst Du es "+RINGERL[formringerl]+
          " zu blasen.\n"));
    say  (raucher->name()+" schafft es "+RINGERL[formringerl]+" zu blasen.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert+5);
    }
    else
    {
      raucher->heal_self(random(5));
    }
    call_out("krautrauchen4", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int krautrauchen4(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Du versuchst es weiter und schaffst "+RINGERL[formringerl]+
          ".\n"));
    say  (raucher->name()+" versucht es weiter und schafft "+RINGERL[formringerl]+".\n");
    call_out("krautrauchen5", 15+random(5),raucher);
  }
  else
  {
   pfeifeangezuendet=0;
   return 1;
  }
}

int krautrauchen5(object raucher)
{
  if(raucher)
  {
    write(BS("Lustig fliegen die Rauchwoelkchen durch die Luft.\n"));
    say  (raucher->name()+" laesst lustige Rauchwoelkchen durch die Luft fliegen.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert+5);
    }
    else
    {
      raucher->heal_self(random(5));
    }
    call_out("krautrauchen6", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int krautrauchen6(object raucher)
{
  if(raucher)
  {
    write(BS("Leider ist das Grottenkraut auch schon wieder aus...\n"));
    say  (raucher->name()+" steckt die Pfeife wieder weg.\n");
    SetProp(P_SHORT, pfeifenname);
    SetProp(P_NODROP, 0);
    SetProp(P_NEVERDROP, 0);
    pfeifegestopft_kraut=0;
    pfeifeangezuendet=0;
    return 1;
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}