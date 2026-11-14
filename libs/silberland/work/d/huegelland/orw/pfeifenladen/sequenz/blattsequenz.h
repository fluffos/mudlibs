//  Projekt   : Barry's Pfeifenladen
//  Objekt    : Sequenz fuers Langgrundblattrauchen
//  Erstellt  : 19.03.2001 (Orw)
//  Geaendert : -



int blattrauchen1(object raucher)
{
  if(raucher)
  {
    write(BS("Kleine Rauchwoelkchen kommen aus Deiner Pfeife und Du fuehlst Dich\n"
          "so richtig wohl.\n"));
    say  (raucher->name()+" fuehlt sich richtig wohl.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert);
    }
    call_out("blattrauchen2", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int blattrauchen2(object raucher)
{
  if(raucher)
  {
    write(BS("Du paffst entspannt Deine Pfeife und versuchst kleine Ringe in der\n"
          "Luft entstehen zu lassen.\n"));
    say  (raucher->name()+" raucht entspannt Pfeife.\n");
    call_out("blattrauchen3", 25+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int blattrauchen3(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Nach einigen Versuchen schaffst Du es "+RINGERL[formringerl]+
          " zu blasen.\n"));
    say  (raucher->name()+" schafft es "+RINGERL[formringerl]+" zu blasen.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert);
    }
    call_out("blattrauchen4", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }   
}

int blattrauchen4(object raucher)
{
  if(raucher)
  {
    formringerl=random(7);
    write(BS("Du versuchst es weiter und schaffst "+RINGERL[formringerl]+
          ".\n"));
    say  (raucher->name()+" versucht es weiter und schafft "+RINGERL[formringerl]+".\n");
    call_out("blattrauchen5", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int blattrauchen5(object raucher)
{
  if(raucher)
  {
    write(BS("Lustig fliegen die Rauchwoelkchen durch die Luft.\n"));
    say  (raucher->name()+" laesst lustige Rauchwoelkchen durch die Luft fliegen.\n");
    if (raucher->QueryProp(P_RACE)=="Hobbit")
    {
      raucher->heal_self(pfeifenwert);
    }
    call_out("blattrauchen6", 15+random(5),raucher);
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}

int blattrauchen6(object raucher)
{
  if(raucher)
  {
    write(BS("Leider ist die Pfeife auch schon wieder leer...\n"));
    say  (raucher->name()+" steckt die Pfeife wieder weg.\n");
    SetProp(P_SHORT, "Eine kleine Pfeife");
    SetProp(P_NODROP, 0);
    SetProp(P_NEVERDROP, 0);
    pfeifegestopft_blatt=0;
    pfeifeangezuendet=0;
    return 1;
  }
  else
  {
    pfeifeangezuendet=0;
    return 1;
  }
}