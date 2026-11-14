inherit "std/thing";
#include <properties.h>
#include <language.h>

string str;
string cstr;

int throw_it(string str);

void init()
{
  ::init();
  call_out("farben",0);
  add_action("throw_it","wirf");
  add_action("ww", "ww");
     
}

void farben()
{
  int colour;
  colour = random(8);
  if (colour==0) cstr = "grünes";
  if (colour==1) cstr = "rotes";
  if (colour==2) cstr = "blaues";
  if (colour==3) cstr = "gelbes";
  if (colour==4) cstr = "schwarz-weiß-kariertes";
  if (colour==5) cstr = "orange-pink-gestreiftes";
  if (colour==6) cstr = "lila-grün-getüpfeltes";
  if (colour==7) cstr = "silbergraues";
}

varargs string short()
{
  return "Ein " + cstr + " Kissen\n";
}

varargs string long()
{
  return "Dies ist ein wunderschönes, " + cstr + " Kissen.\n"+
          "Du kannst versuchen es zu werfen.\n";
}

void create()
{
  int colour;
  if (!clonep(this_object())) return;
  ::create();
  AddId("kissen");
  SetProp(P_WEIGHT, 1);
  SetProp(P_NAME, "Kissen");
  SetProp(P_SHORT,"Ein Kissen");
  colour = random(8);
  if (colour==0) cstr = "grünes";
  if (colour==1) cstr = "rotes";
  if (colour==2) cstr = "blaues";
  if (colour==3) cstr = "gelbes";
  if (colour==4) cstr = "schwarz-weiß-kariertes";
  if (colour==5) cstr = "orange-pink-gestreiftes";
  if (colour==6) cstr = "lila-grün-getüpfeltes";
  if (colour==7) cstr = "silbergraues";
  SetProp(P_VALUE,1);

    
}

int ww(string str)
{
  if (str)
    return throw_it("kissen nach "+str);
  else
  {
    object *all, *liv;
    int i;

    all=all_inventory(environment(this_player()));
    for (i=0; i<sizeof(all); i++)
      if (query_once_interactive(all[i]))
        if (!liv)
	  liv = ({all[i]});
        else
          liv = liv+({all[i]});
    i = random(sizeof(liv));
    return throw_it("kissen nach "+lower_case(liv[i]->query_real_name()));
  }
}

int throw_it(string str)
{
  int treffer;
  string victim_name,werfer_name;
  string victim_string,werfer_string;
  string was,at,wen;
  int fehler;
  object victim;

  if (!str) return 0;
  fehler = 0;
  if (sscanf(str,"%s %s %s",was,at,wen) != 3)
    fehler = 1;
  if (at != "nach"&&at!="auf")
    fehler = 1;
  if (fehler)
  { notify_fail("Zum Werfen: wirf kissen nach <spielername>\n");
    return 0;
  }
  victim = find_living(wen);
  if (victim==this_player())
     {
      write("Kissen kannst Du nur nach anderen Spielern werfen.\n");
      return 1;
     } 
  if (!query_once_interactive(victim))
     {
      write("Du kannst das Kissen nur nach Spielern werfen!\n");
      return 1;
     } 
  if (!victim || !present(victim,environment(this_player())))
    { write("Dieser Spieler ist nicht hier!\n");                                
      return 1;                                                                 
    }                                                                           
  victim_name = capitalize(victim->query_real_name());
  werfer_name = capitalize(this_player()->query_real_name());
  treffer = random(5);
  write("Du schmeißt ein Kissen nach " + victim_name +".\n");
  say(werfer_name + " wirft ein Kissen nach " + victim_name + ".\n");
  if (treffer==0)
  {
    werfer_string = "Du verfehlst " + victim_name + " meilenweit.\n";
    victim_string = werfer_name + " verfehlt Dich meilenweit.\n";
    this_object()->move(environment(this_player()));
  }
  if (treffer==1)
  {
    werfer_string = "Das Kissen streift " + victim_name + " am Ohrläppchen.\n";
    victim_string = "Das Kissen streift Dich am Ohrläppchen.\n";
  }
  if (treffer==2)
  {
    werfer_string = "PAFF! Du triffst " + victim_name + " mitten ins Gesicht.\n";
    victim_string = "PAFF! Das Kissen trifft Dich mitten im Gesicht!\n";
  }
  if (treffer==3)
  {
    werfer_string = "WUSCH! Das Kissen trifft " + victim_name + "'s Bauch mit voller Wucht.\n";
    victim_string = "WUSCH! Das Kissen fliegt mit voller Wucht gegen Deinen Bauch.\n";
  }
  if (treffer==4)
  {
    werfer_string = victim_name + " versucht wegzurennen, doch das Kissen trifft den Hinterkopf.\n";
    victim_string = "Du versuchst wegzurennen, aber das Kissen trifft Dich am Hinterkopf.\n";
  }
  write(werfer_string);
  tell_object(victim,victim_string);
  if (treffer) this_object()->move(victim);
  return 1;
}

