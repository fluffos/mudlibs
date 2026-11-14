// Seherhaus von Sengir 
//
// Progged by Sengir +(Kara)
//
// 1998-02-14                      
//
// last updated: 1998-03-18
//

inherit "std/room";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <defines.h>
#include <moredef.h>


create()
{
  ::create();
  
  SetProp( P_INT_SHORT, "Sengirs Schlupfwinkel" );
  SetProp( P_INT_LONG, BS
     ("Das ist Sengirs geheimer Schlupfwinkel.\n"
      "Du siehst das File 'sengir.c' vor Dir.\n" 
      "Der Boden besteht aus einer flauschigen weissen Wolkenschicht.\n "
      "Durch die hell lodernde Feuerwand ist das Zimmer aussergewoehnlich "
      "hell beleuchtet. Ueber Dir siehst du einen klaren Sternenhimmel.\n "
      "Eine alte schwarze Ledercouch steht ziemlich zentral gelegen "
      "in der Mitte des Raumes. Hinter der Couch steht noch ein "
      "schoener Obsidiantisch.\n"
      "Also eine typische Zwergenhoehle ist das nicht, oder?\n"));

  SetProp( P_LIGHT, 1 ); 
  SetProp( P_INDOORS, 1 );
  SetProp(P_ENVIRONMENT,([ENV_TEMPERATURE: 20]) );

AddDetail( ("schlupfwinkel"),
   "Du weisst doch. Dort wo man sich verschlupfen kann, wenn man seine "
   "Ruhe haben will.\n");
AddDetail( ("ruhe"),
   "Jeder braucht das ab und zu.\n");
AddDetail( ({"file","sengir.c"}),
   "Ohne 'sengir.c' wuerdest Du jetzt im luftleerem Nichts stehen.\n");
AddDetail( ({"nichts","nix","niente","vakuum","leere"}),
   "Nichts, einfach Nichts. Nix. Gar nix. Niente. Null. Vakuum. Leere.\n");
AddDetail( ({"null","0"}),   
   "                                  0\n");                      
AddDetail( ({"boden","wolkenschicht","wolkendecke"}),   
   "Du siehst eine gewoehnliche Wolkendecke zu deinen Fuessen.\n"
   "Trotzdem musst Du Dir keine flauschigen Fuesse holen, weil "
   "mehrere Tierfelle auf den Wolken verteilt sind.\n");
AddDetail( ("fuesse"),
   "Fuesse? - noch nie gehoert, gell?  ;)\n");
AddDetail( ({"wolken","wolke"}),
   "Ein kleines Present von Dante, ein Freund Sengirs.\n");
AddDetail( ({"tierfelle","felle"}),
   "Es liegen mehrere Tierfelle zu Deinen Fuessen.\n"
   "Du erkennst ein Wolfsfell, ein Pumafell, ein Tigerfell, "
   "ein Jaguarfell und ein Grizzlybaerenfell.\n");
AddDetail( ({"wolfsfell","pumafell","tigerfell","jaguarfell"}),
   "Schoene weiche Tierfelle, die Dir das Stehen auf den Wolken "
   "angenehmer machen.\n");
AddDetail( ("grizzlybaerenfell"),
   "Schoene weiche Tierfelle, die Dir das Stehen auf den Wolken "
   "angenehmer machen.\n");
AddDetail( ({"present","geschenk"}),
   "Die Wolken sind ein Geschenk von Dante.\n");
AddDetail( ("dante"),
   "Ein fieser, boeser, sadistischer, gemeiner und ekelhafter Magier.\n");
AddDetail( ("magier"),
   "Sengir will nie Magier werden.\n");
AddDetail( ({"feuerwand","wand","feuer"}),
   "Eine Feuerwand umringt diesen Raum. Obwohl die Wand aus Feuer "
   "besteht, strahlt sie keine Hitze aus. Trotzdem waere es keine gute "
   "Idee die lodernde Feuerwand zu beruehren.\n" 
   "Ansonsten faellt Dir nix Besonderes an der magischen Wand auf.\n");
AddDetail( ({"raum","zimmer"}),
   "Raum = Zimmer; Hier Sengirs Raum, (Zimmer)!\n");
AddDetail( ("hitze"),
   "Vielleicht kaltes Feuer, wer weiss? So etwas soll es auch geben.\n"
   "Mit Magie laesst sich einiges bewerkstelligen.\n");
AddDetail( ("magie"),
   "Ohne Magie waere das Silberland genauso aufregend wie Quake "
   "auf einem 286er ;) \n");
AddDetail( ("silberland"),
   "Das sollest nicht nach dem Silberland forschen, sondern IM "
   "Silberland forschen.\n");
AddDetail( ({"quake","286","286er","gasbaelle","universum","laufbahn"}),
   "Sowas interessiert einen echten Mudder nicht.\n");
AddDetail( ("besonderes"),
   "An dem Besonderen ist wirklich nichts Besonderes.\n"); 
AddDetail( ({"sternenhimmel","sternennacht"}),  
   "Obwohl Du Dich tief unten in Felonia befindest, kannst du ueber Dir " 
   "eine wolkenlose Sternennacht bewundern. Unzaehlige Sterne erhellen " 
   "die Nacht.\n" 
   "Anscheinend hat jemand einen tiefen Stollen in den Berg gegraben, " 
   "damit Sengir diese tolle Aussicht geniessen kann.\n");
AddDetail( ({"felonia","zwergenstadt"}),
   "Felonia ist die Zwergenstadt, in der sich diese Hoehle befindet.\n");
AddDetail( ({"sterne","stern"}),
   "Sterne sind hell leuchtende Gasbaelle im Universum, die am Ende "
   "ihrer Laufbahn manchmal in einer Supernova explodieren.\n"
   "Unsere Sonne ist auch ein Stern, wird aber nicht in einer Nova "
   "explodieren, weil sie nicht genug Masse besitzt.\n"
   "Ob Sterne in einem Fantasyland genauso erklaert sind, entzieht "
   "sich meinen Kenntnissen.  :> \n");
AddDetail( ({"nova","supernova","masse","sonne"}),
    "Sowas interessiert einen echten Mudder nicht.\n");               
AddDetail( ("fantasyland"),
    "Das Silberland ist doch eins, oder?\n");
AddDetail( ({"stollen","berg"}),
    "Das war sicher eine menge Arbeit, um diesen Stollen in den "
    "Berg zu graben.\n"
    "Vielleicht war aber auch ein bisschen Magie im Spiel.\n");
AddDetail( ("aussicht"),
    "Die Aussicht ist fuer eine Hoehle doch wirklich echt super toll.\n");
AddDetail( ({"hoehle","zwergenhoehle"}),
    "Du befindest Dich in einer.\n");
AddDetail( ({"ledercouch","couch"}),
    "Ziemlich abgenuetzt diese alte schwarze Couch. Dafuer wahnsinnig "
    "bequem.\n" 
    "Sengirs grosser Hintern duerfte sie oefters strapaziert haben, "
    "wenn er von langen Reisen durch das Silberland zurueckkehrte um "
    "sich in seiner Hoehle zu erholen und zu kraeftigen.\n"
    "Du wuerdest es nie wagen dieses Heiligtum zu entweihen indem Du " 
    "Deinen Allerwertesten auf diese Ledercouch waelzt.\n");
AddDetail( ({"hintern","allerwertester",}),
    "Jeder hat ihn. Mancher groesser, mancher kleiner.\n"
    "Aber alle erfuellen die gleichen Funktionen.  ;)\n");
AddDetail( ("funktionen"),
    "Aehm!!!\n");
AddDetail( ("reisen"),
    "Metzeln, toeten, pluendern, metzeln, forschen, metzeln, wandern, "
    "metzeln, klettern, metzeln, schwimmen, metzeln " 
    "und vieles mehr...\n");
AddDetail( ("heiligtum"),
    "Knie nieder und wuerdige dieses Heiligtum. Naa, nur ein Scherz.\n");
AddDetail( ({"obsidiantisch","tisch"}),
    "Ein kostbarer schwarzer Tisch steht auf seinen vier Beinen " 
    "unauffaellig hinter der Ledercouch.\n"
    "Du kannst mehrere Gegenstaende auf dem Obsidiantisch erkennen.\n");
AddDetail( ("gegenstaende"),
    "Eine kleine Axt, eine Drachenschuppe, eine hoelzerne Floete "
    "ein Etwas, ein Mondsteinei, ein Trauschein und "
    "ein kleines Bild.\n"
    "Es wuerde deinen Kopf kosten, solltest du versuchen eins dieser "
    "Stuecke zu stehlen.\n");
AddDetail( ("beine"),
    "Pass auf, dass der Tisch nicht davonrennt.\n");
AddDetail( ({"axt","zwergenaxt"}),
    "Du siehst ne kleine Zwergenaxt auf dem Tisch liegen. Sengirs erste "
    "ernstzunehmende Waffe. Er ist wahnsinnig stolz auf sie.\n");
AddDetail( ("waffe"),
    "Jaja, auch eine kleine Zwergenaxt kann ne gefaehrliche"
    " Waffe sein.\n"
    "Trotzdem verlaesst sich heute Sengir mehr auf seine Todesaxt.\n");
AddDetail( ({"todesaxt","instrument"}),
    "Sengir hat seine Todesaxt immer bei sich. "
    "Ein Instrument des Todes!\n"); 
AddDetail( ({"drachenschuppe","schuppe"}),
    "Diese Schuppe stammte von Sengir erstem erlegten Drachen.\n"
    "Es ist nicht leicht so ein riesiges Monster zu toeten.\n"
    "Die Drachenschuppe schimmert leicht blaeulich.\n"); 
AddDetail( ({"drache","monster"}),
    "Gross, maechtig, gefaehrlich und fast unverwundbar.\n" 
    "Aber nicht unzerstoerbar, wie es die Schuppe beweist!\n");
AddDetail( ({"floete","blasinstrument"}),
    "Diese Floete half Sengir bei einer Quest. Sie ist aber keine "
    "gewoehnliche hoelzerne Floete. Ein bissi Magie wurde benutzt um "
    "dieses schoene Blasinstrument zu basteln.\n"
    "Die Heilerin Shardin half ihm beim Bau dieser Floete.\n");
AddDetail( ("quest"),
    "Man muss jede Menge Quest's loesen um im Silberland gross und "
    "maechtig zu werden. Bei dieser Quest wurde einem Schmied im "
    "Kristallwald das Gehoer wiedergegeben.\n");
AddDetail( ({"heilerin","shardin"}),
    "Du kannst sie irgendwo im Kristallwald finden. Sie hilfe Dir gerne "
    "bei der einen Quest.\n"
    "Ausserdem kann sie Dich heilen und kurieren. Falls Du mal taub, "
    "blind oder ein Frosch sein solltest, geh zu Shardin.\n");
AddDetail( ({"schmied","eesthil","gehoer"}),
    "Ich glaube, dass er Eesthil hiess, Eesthil der Schmied. Er verlor "
    "sein Gehoer, aber durch ein schoenes Lied durch diese Floete "
    "konnte er wieder hoeren.\n");
AddDetail( ("kristallwald"),
    "Der Kristallwald ist ein Ort vieler Geheimnisse.\n");
AddDetail( ("geheimnisse"),
    "Versuch doch die Geheimnisse zu finden und sie zu entraetseln!\n");
AddDetail( ("lied"),
    "Spiel mir das Lied vom ...\n");
AddDetail( ("etwas"),
    "An dem Etwas ist nix Besonderes. Aber Du denkst Dir, dass es "
    "irgendwie mit einem Zaubertrank zu tun haben koennte.\n");
AddDetail( ({"zaubertrank","trank"}),
    "Sengir kennt 19 Zaubertrankverstecke, 10 Zaubertraenke sind "
    "fuer Dich bestimmt!\n");
AddDetail( ({"zaubertrankverstecke","verstecke","zaubertrankversteck"}),
    "Die musst Du schon selber finden. Sie sind im ganzen Silberland "
    "verteilt.\n");
AddDetail( ({"mondstein","mondsteinei","ei"}),
    "Das Mondsteinei liegt im Kristallwald versteckt. Sengir versucht "
    "schon lange das Raetsel um das Ei zu loesen.\n"
    "Angeblich soll das Mondsteinei ein Zaubertrankversteck sein.\n"
    "Leider kann Sengir das nicht bestaetigen.\n"
    "Solltest Du mal das Raetsel loesen, koenntest Du bitte Sengir "
    "einen kleinen Tip geben.\n");
AddDetail( ({"raetsel","loesung"}),
    "Gibt es denn ueberhaupt eine Loesung zu dem Raetsel?\n");
AddDetail( ("trauschein"),
    "Sengir ist verheiratet, hast Du das nicht gewusst?\n"
    "Kara, die Fee ist die Glueckliche. Sie wandern oft gemeinsam "
    "durch das Silberland und sie haben sogar schon oefters zusammen "
    "eine Quest geloest.\n");
AddDetail( ({"kara","ehefrau","begleitung"}),
    "Kara ist die Ehefrau von Sengir. Manchmal nervt sie ihn, aber "
    "ansonsten ist sie wahnsinnig lieb. Sie kaempft nicht so gerne.\n"
    "Kara durchforscht viel lieber mit ihrem Meerschweinchen das "
    "Silberland und quiekt dabei froehlich durch die Gegend.\n");
AddDetail( ({"meerschweinchen","nagetier","begleiter"}),
    "Du wirst Kara nie ohne ihrem Meerschweinchen sehen. Das kleine "
    "Nagetier ist ein treuer Begleiter von der kleinen Fee.\n" 
    "Wenn Dir Kara einmal auf ihren Streifzuegen begegnen sollte, "
    "frag sie doch einfach nach ihrem Meerschweinchen.\n");
AddDetail( ("fee"),
    "Kleines fliegendes Ding. Sehr intelligent. Immer froehlich.\n"
    "Sehr geschickt. Oft hilfsbereit. Liebt Meerschweinchen ;)\n");
AddDetail( ({"streifzug","streifzuege"}),
    "Kannst Du Dir darunter nix vorstellen?\n");
AddDetail( ("bild"),
    "Der Rahmen besteht aus kunstvoll bearbeiteten Silber.\n"
    "Auf diesem kleinen Bild kannst Du Sengirs Ehefrau erkennen.\n"
    "Sie hat eine kleine Stupsnase und einen pumeligen Koerper. Kara " 
    "hat schoene braune gelockte Haare. Zwei haselnussbraune Augen "
    "funkeln Dich froehlich an.\n" 
    "Ausserdem traegt sie einen kleinen Beutel am Ruecken und dabei "
    "laechelt sie Dich suess an.\n"
    "Wenn Du nicht wuesstest, dass sie eine Fee ist, wuerdest Du "
    "sagen, dass sie ein kleines Meerschweinchen ist.\n");
AddDetail( ({"rahmen","silber"}),
    "Der silberne Rahmen umgibt das kleine Bild.\n"); 
AddDetail( ({"stupsnase","nase"}),
    "Eine kleine suesse Stupsnase. Manchmal sieht die Nase einem "
    "Meerschweinchennaeschen zum Verwechseln aehnlich.\n"
    "Kara sieht manchmal einem Meerschweinchen aehnlicher als einer Fee.\n");
AddDetail( ({"meerschweinchennaeschen","naeschen"}),
    "Diese kleinen putzigen Tierchen haben ebenfalls ein suesses "
    "Naeschen zum Schnuffeln und Knuddeln.\n");
AddDetail( ("koerper"),
    "Ein knuddeliger pumpeliger Koerper zum Reinkuscheln und Anschmiegen.\n"
    "Du denkst. o O( Kara scheint wirklich ein Meerschweindi zu sein ).\n");
AddDetail( ("haare"),
    "Langes welliges und gelocktes Haar, das sich sanft ueber ihre "
    "Schultern legt. Ein atemberaubender Anblick.\n");
AddDetail( ("anblick"),
    "Du bist von ihrem Anblick einfach ueberwaeltigt.\n" 
    "Sengir kann einfach nur gluecklich sein, so eine hinreissende "
    "Fee (oder ein Meerschweinchen) zu haben.\n"); 
AddDetail( ("augen"),
    "Wenn Dich jemand mit solchen Augen um irgendetwas anfleht, kann "
    "man einfach nicht 'Nein' sagen.\n" 
    "( Ich spreche aus Erfahrung ;> )\n");
AddDetail( ("erfahrung"),
    "Jetzt wirds aber persoenlich. Meine Erfahrungen werden nicht weiter "
    "untersucht!\n");
AddDetail( ("schultern"),
    "Die beiden Dinger unter deinem Hals.\n");
AddDetail( ("hals"),
    "Das Ding unter Deinem Kopf.\n");
AddDetail( ("kopf"),
    "Jetzt wird's ma aber zu bloed. Schluss. Aus. Ende.\n");
AddDetail( ("beutel"),
    "Du wirst im Silberland kaum jemanden antreffen, der keinen kleinen "
    "Beutel bei sich hat.\n"
    "Man kann viele Dinge in so einem Beutel unterbringen. " 
    "Echt praktisch.\n");
AddDetail( ("ding"),
    "Man kann dieses Ding praktischerweise fuer viele Dinge verwenden, "
    "wenn man bestimmte Dinge nicht naeher beschreiben will oder kann.\n"
    "Wirklich sehr nuetzlich so ein Ding.\n");
AddDetail( ("sengir"),
    "Er ist derzeit nicht daheim. Wahrscheinlich haengt er gerade in "
    "irgendsoeiner Kneipe herum, oder er metzelt sich durch das SL "
    "durch.\n"
    "Er ist sogar fuer einen Zwerg relativ klein, dafuer hat er immer "
    "eine riesige und schwere Todesaxt bei sich.\n"
    "Meistens sieht man ihn in Begleitung einer kleinen Fee, aber "
    "oefters sitzt er auch gemeinsam mit seinen Saufkumpanen in "
    "einer verrauchten Kneipe und prahlt mit seinen Geschichten "
    "ueber furchteregende Ungeheuer und gefaehrlichen Bestien, die "
    "er schon gekillt hat.\n");
AddDetail( ({"zwerg","zwerge"}),
    "Sengir ist so einer. Man sagt ihnen nach das sie stinken und doof "
    "sind. Aber unterschaetze nie einen Zwerg. Hoerst Du... NIE!\n"); 
AddDetail( ("kneipe"),
    "Meistens findet man in einer Kneipe auch Alk.\n"
    "Das ist eigentlich der Hauptgrund fuer Sengirs Interesse an "
    "Kneipen.\n");
AddDetail( ({"hauptgrund","grund","alk","interesse"}),
    "ALK, davon wird Sengir magisch angezogen. Wahrscheinlich braucht "
    "er ihn um zu ueberleben. Koennte man mal vermuten...\n");
AddDetail( ({"saufkumpanen","nacht"}),
    "Es finden sich immer ein paar Freunde, mit denen Sengir eine "
    "feucht-froehliche Nacht verbringt.\n");
AddDetail( ("freunde"),
    "Da Sengir ueber 50 Freunde hier hat, wird es nie langweilig in den "
    "beruehmt-beruechtigten Kneipen vom Silberland.\n");
AddDetail( ("geschichten"),
    "Sengir erzaehlt nur wahre Geschichten, er wuerde es nie wagen ein "
    "bissi zu flunkern, obwohl die Geschichte ueber den Fraggle, den "
    "er ganz ALLEINE gekillt haben soll, naja... klingt unwahrscheinlich.\n");
AddDetail( ("fraggle"),
    "Eine wahnsinnig gefaehrliche, ueberdimensional grosse Bestie mit " 
    "rasiermesserscharfen Krallen, die Dich aufschlitzen.\n"
    " Buaaaaaaahhhhhh\n");
AddDetail( ({"ungeheuer","bestien","bestie"}),
    "Der garantierte Tod fuer unvorsichtige Spieler.\n");
AddDetail( ({"tod","sensenmann","gevatter","namen"}),
    "Tod, Sensenmann, Gevatter...., er hat viele Namen.\n");
AddCmd( ({ "beruehre"}), "beruehre_was");
AddCmd( ({ "stehle" }), "stehle_was");      

AddSound( DEFAULT_SOUND,
"Du hoerst das Quieken eines imaginaeren Meerschweinchens. \n");
AddSmell( DEFAULT_SMELL, 
"Es riecht hier nach einen milden Fruehlingsabend. \n");

}

stehle_was (string str)
     
{
  notify_fail("Was willst Du stehlen ?\n");
  if ((str == "axt") || (str == "trauschein") || (str == "mondsteinei") || (str == "floete")  || (str  == "drachenschuppe") || (str == "etwas") || (str == "bild"))
    { 
  write( "Bei dem klaeglichen Versuch einen Gegenstand von dem "   
         "Obisidiantisch zu stehlen, ertoent eine grollende Stimme:\n"
         "Moege Dich Sengirs ZORN treffen fuer Deinen Frevel!\n"); 
            TP->reduce_hit_point(40);
       say (this_player()->name(WER,2)+" wurde fuer einen boesen Gedanken bestraft.\n"); 
          return 1;
        }
  return 0;
}  


beruehre_was (string str) 
{
  notify_fail( "Was willst Du beruehren ?\n" );
  if ((str == "feuer" || str == "feuerwand" || str == "wand")) 
       
       {
          write("Du beruehrst wagemutig die Feuerwand.\n"
                "Obwohl die lodernde Feuerwand keine Hitze von sich "
                "strahlt, verbrennst Du Dir Deine Hand beim "
                "Beruehren der Wand. Die Flammen sind extrem heiss zu "
                "Deiner Ueberraschung.\n"
                "Mit schmerzverzerrten Gesicht bruellst Du: WWWWWUUUAAAAAAAAHHHH!\n");
          TP->reduce_hit_point(15); 
          say(this_player()->name(WER,2)+" bruellt ploetzlich lauthals herum:\n"
              "       WWWWWUUUAAAAAAAAHHHH!\n");
          return 1;
        }
return 0;
}  
  

