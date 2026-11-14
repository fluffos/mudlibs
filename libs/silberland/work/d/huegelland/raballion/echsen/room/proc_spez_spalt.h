// /d/huegelland/raballion/echsen/room/proc_spez_spalt.h
// 2004-07-15  raballion@
//             Spalten gibt es ab und an und hier ist der Code zum reingreifen

int greife(string str)
{
string leidertxt;
string zufall1;
string zufall2;
string zufall3;
object obj;

leidertxt = "Leider kannst Du hier nichts finden.\n";
zufall1 = "Zufaellig findest Du etwas in eine";
zufall2 = "und holst es heraus.\n";
zufall3 = " holt etwas aus eine";

write ("blub: "+str+"b\n");
write ("blub: spalt "+spalt+"\n");
write ("blub: kluft "+kluft+"\n");
write ("blub: riss "+riss+"\n");
write ("blub: OBJ "+OBJ+"\n");

  notify_fail("In was willst Du greifen?\n");
  if( !str ) return 0;
  notify_fail("In sowas kannst Du nicht greifen.\n");

  if( str =="in spalt" || str=="in spalte" || str=="in spalten")
  {
    if(spalt)
    {
      write(zufall1 + "m Spalt " + zufall2);
      say(CAP_TPN+zufall3+"m Spalt.\n");
      CLONE( OBJ "rolle", TP);
      spalt--;
    }
    else
      write(leidertxt);
    return 1;
  }

  if( str=="in kluft" || str=="in kluefte")
  {
    if(kluft)
    {
      write(zufall1 + "r Kluft " + zufall2);
      say(CAP_TPN+zufall3+"r Kluft.\n");
      CLONE( OBJ "rolle", TP);
      kluft--;
    }
    else
      write(leidertxt);
    return 1;
  }

  if( str=="in riss" || str=="in risse")
  {
    if(riss)
    {
      write(zufall1 + "m Riss " + zufall2);
      say(CAP_TPN+zufall3+"m Riss.\n");
      CLONE( OBJ "rolle", TP);
      kluft--;
    }
    else
      write(leidertxt);
    return 1;
  }
  return 0;
}

void reset()
{
  ::reset();
// variablen, ob man etwas findet
// variablenobj, welchen Typ man findet
  spalt = random(10)/1;
  spaltobj = random(3);
  kluft = random(10)/1;
  kluftobj = random(3);
  riss = random(10)/1;
  rissobj = random(3);
}





