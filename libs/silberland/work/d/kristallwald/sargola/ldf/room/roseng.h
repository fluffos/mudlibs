/*
******************************
**
** STANDARD
** MAUER - Mauer rund um den Garten
** FUNC_MAUER - rassenspezifische func fuer mauer
**
******************************
*/


#define STANDARD							\
AddDetail("rosengarten","Nunja, Du stehst wohl im Rosengarten des "	\
  "Koenigs im Land der Ferne.");					\
AddDetail("koenig","Nur einem Koenig kann so ein herrlicher Rosen"	\
  "garten gehoeren.");							\
AddDetail("land der ferne","Das ist hier ueberall.");			\
AddDetail("boden","Feuchter, aber fester Boden - perfekt fuer Rosen. "	\
  "Viele Wege fuehren zwiwschen den Rosenstraeuchern durch.");		\
AddDetail("wege","Sie fuehren in alle Richtungen, der breiteste "	\
  "jedoch fuehrt in die Richtung des Schlosses und sind mit weissen "	\
  "Kieselsteinen ausgelegt.");						\
AddDetail(({"steine","kieselsteine"}),"Lauter kleine weisse Kiesel"	\
  "teine, die den Weg kennzeichnen - damit man nicht versehens "	\
  "in die Rosenstraeucher taumelt.");					\
AddDetail(({"gebaeude","schloss"}),"Schon aus der Ferne ist es ein "	\
  "imposantes, riesiges Gebaeude mit vielen Tuermen, Fenstern "		\
  "und Nischen.");							\
AddDetail("lilien","Weisse Lilien wachsen zwischen den Rosen.");	\
AddDetail(({"pappeln","silberpappeln"}),"Hohe Silberpappeln, die "	\
  "sich im Wind wiegen und dadurch ein feines Klingen wie Glocken "	\
  "verursachen. Ausserdem hoerst Du einen Vogel singen.");		\
AddDetail("klingen","Das kann man nur hoeren.");			\
AddDetail( ({"nischen","fenster"}),"Du bist zu weit entfernt, um "	\
  "etwas erkennen zu koennen.");					\
AddDetail(({"tuerme","turm"}),"Du kannst groessere und kleinere "	\
  "Tuerme erkennen, und alle haben ein kleines Daechlein mit einem "	\
  "spitzen Gibel.");							\
AddDetail(({"daecher","dach","daechlein","gibel"}),"Die sind zuweit weg, um "	\
  "etwas erkennen zu koennen. Dir faellt nur auf, dass sie im "		\
  "Sonnenlicht glaenzen.");						\
AddDetail(({"licht","sonnenlicht","sonne"}),"Die Sonne bringt das "	\
  "Schloss und den Rosengarten zum Leuchten und Erstrahlen.");		\
AddDetail( ({"leuchten","erstrahlen"}),"Hauptwoertlich gebrauchte "	\
  "Verben.");								\
AddDetail("verben","Ich erstrahle, Du erstrahlst usw ...");		\
AddDetail(({"rosenstraeucher","straeucher"}),				\
  "Du meinst die Rosen?");						\
AddDetail("rosen","Egal wohin Du blickst - Du siehst nur herrliche "	\
  "Rosen. Vor allem rote und weisse Rosen beherrschen das Bild. "	\
  "Zwischen ihnen wachsen weisse Lilien. Du bist umhuellt von ihrem "	\
  "herrlichen, blumigen Duft. Ausser den wunderschoenen Blueten "	\
  "haben Rosen aber auch Dornen...");					\
AddDetail("blueten","Fast alle sind schon aufgeblueht und verbreiten "	\
  "einen herrlichen Duft. Egal wo Du hinsiehst, rote und weisse "	\
  "Blueten wachsen hier, um den Besucher zu erfreuen.");		\
AddDetail("besucher","Das musst wohl Du sein. :)");			\
AddDetail("dornen","Die Rosen versinnbildlicht wie kaum eine andere"	\
  "Blume Schoenheit und Gefahr. Die Dornen erinnern Dich daran, "	\
  "dass Rosen nicht nur einfach schoen sind.");				\
AddDetail("schoenheit","Du musst wohl blind sein, wenn Du sie nicht "	\
  "erkennst.");								\
AddDetail("gefahr","Komisch ... die Rose symbolisiert Gefahr. Hier "	\
  "ist es doch so paradiesisch schoen ... Oder doch nicht?");		\
AddDetail("paradies","Du denkst . o 0 (Das ist hier)");			\
AddDetail("duft","Eigentlich kannst Du den nicht erkennen.");		\
AddDetail("bild","Es ist ziemlich romantisch.");			\
AddDetail("himmel","Der Himmel ist, bis auf ein paar kleine Schaef"	\
  "chenwolken wolkenlos.");						\
AddDetail(({"woelkchen","wolken"}),"Es handelt sich um Schaefchenwolken - glaubst "	\
  "Du jedenfalls. Auf jeden Fall sehen sie wie kleine weisse "		\
  "Schaefchen aus.");							\
AddDetail("schaefchenwolken","Kleine, weisse Wolken, die wie Schaef"	\
  "chen aussehen. \nDu kicherst bei dem Gedanken.");			\
AddDetail("schaefchen","Die sehen genauso aus, wie die Woelkchen "	\
  "am Himmel!");							\
AddDetail("gedanken","Oh! Kaum versuchst Du, ihn naeher zu unter"	\
  "suchen, ist er schon wieder weg ...");				\
AddDetail("mauer","Die Mauer fuehrt rund um den Rosengarten herum.");	

#define STANDARD1							\
AddSound(DEFAULT_SOUND, "Im Rosengarten herrscht wundersame Musik, "	\
  "so als ob tausend Glocken aus Glas auf einmal ertoenten. Voegel "	\
  "zwitschern ueberall um Dich herum.");				\
AddSound(({"klingen","glocken","musik"}),"Die Blaetter der "		\
  "Silberpappeln wiegen sich sanft im Wind und klingen wie viele "	\
  "Glocken aus Glas.");							\
AddDetail("wind","Der Wind faehrt sanft durch die Rosen und Pappeln.");	\
AddDetail("blaetter","Die Blaetter fliegen sanft im Wind.");		\
AddDetail("glocken","Es klingt nur so als ob.");			\
AddSound("voegel","Von allen Seiten hoerst Du froehliche Voegel "	\
  "lustige Lieder zwitschern. Und doch dringt eine traurige Melodie "	\
  "an Dein Ohr.");							\
AddSound("lieder","Die der anderen Voegel machen Dein Herz froh.");	\
AddSound("herz","Buummm... Buummm..."); 				\
AddSound(({"lied","melodie"}),"Sie kommt von der hoechsten Silberpappel. Auf "	\
  "ihr sitzt ein schwarzer Vogel der schon von Weitem zu erkennen "	\
  "ist. Er singt ein tieftrauriges Lied. Eigentlich komisch in "	\
  "der schoenen Gegend hier.");						\
AddSound("vogel","Sein Gesang ist so ganz anders als der der anderen "	\
  "Voegel. Er zwitschert ein unwirklich trauriges Lied, das Dich "	\
  "betruebt.");								\
AddSmell(DEFAULT_SMELL,"Der Duft der Rosen verzaubert Dich voellig.");	\
AddSmell("duft","Der Duft der Rosen.");					\
AddSmell("rosen","Es ist der feine Duft von bluehenden Rosen, der "	\
  "Dich so verzaubert.");						\
AddSmell("lilien","Sie verbreiten einen blumigen Duft, der Dich fast "	\
  "Deiner Sinne beraubt.");
  
#define MAUER								\
AddDetail("ziegel","Sie sind klein und klobig gefertigt. Es wirkt so, "	\
  "als ob die Ziegel von Hand gefertigt wurden - so ungleich sind "	\
  "sie. Aber das verstaerkt das romantische Gefuehl in Dir. Darauf "	\
  "kannst Du manchmal ein Wappen erkennen.");				\
AddDetail("gefuehl","Horch einfach in Dich hinein...");			\
AddDetail("verputz","Der weisse Verputz ist an einigen Stellen schon "	\
  "abgebroeckelt und es scheinen die Ziegel darunter hervor.");		\
AddDetail("stelle","Hie und da ist der Verputz schon von der Mauer "	\
  "gebroeckelt und man kann die Ziegel darunter erkennen.");		\
AddDetail("wappen","Es ist das Wappen vom Land der Ferne.");		\


#define FUNC_MAUER							\
string mauer()								\
{ string str, txt;							\
   txt = "Der weisse Verputz ist hie und da schon abgebroeckelt. "	\
     "Die Mauert wurde aus kleinen, klobigen Ziegeln gemauert an "	\
     "denen Du das Wappen vom Land der Ferne erkennen kannst.";		\
  str = TP->QueryProp(P_RACE);						\
  switch str								\
  {									\
     case "zwerg":							\
     case "hobbit":							\
     case "fee":							\
     {									\
	str = "Die Mauer ist klein und doch fuer einen "+cap(str)+	\
	  "Dich ziemlich hoch. Druebersehen kannst Du auf jeden "	\
	  "Fall nicht. ";						\
	break;								\
     }									\
     case "elf":							\
     case "troll":							\
     case "dunkelelf":							\
     case "oger":							\
     {									\
        str = "Die Mauer ist fuer einen "+cap(str)+" wie Dich doch "	\
        "recht niedrig geraten. ";					\
     }									\
     default:								\
     {									\
        str = "Die Mauer ist in etwa so hoch wie Du und so kannst "	\
        "Du auch ohne Probleme darueberblicken. ";			\
     }									\
  }									\
  return str + txt;							\
}
     
