// SilberLand MUDlib
//
// sys/verben.h -- Std. Verben fuer Kommandos, von Ronja@SL
//
// $Date: 2003/11/15 14:44:26 $
/* $Revision: 1.7 $
 * $Log: verben.h,v $
 * Revision 1.7  2003/11/15 14:44:26  Feyaria
 * CMD_SCHLIESSEN
 *
 * Revision 1.6  2003/10/17 13:26:35  Cirion
 * CMD_GEBEN
 *
 * Revision 1.5  2003/10/09 09:57:27  Cirion
 * CMD_ERKLIMMEN
 *
 * Revision 1.4  2000/07/13 11:29:34  Zordan
 * CMD_UNTERSUCHEN um betr/betracht/betrachte erweitert
 *
 * Revision 1.3  2000/05/17 09:01:11  Ronja/Crea
 * some typo fixing...
 *
 * Revision 1.2  2000/05/12 08:59:12  Zordan
 * nur einmal includen, __CMD_VERBEN_H__ eingefuehrt
 *
 * Revision 1.1  2000/05/12 07:59:18  Angrox
 * Initial revision
 *

*/

#ifndef __CMD_VERBEN_H__
#define __CMD_VERBEN_H__

#define CMD_KLETTERN     ({"kletter","klettere","klettre","steig","steige"})
#define CMD_ERKLIMMEN    ({"erklimm", "erklimme"})
#define CMD_NEHMEN       ({"nehm","nimm","nehme"})
#define CMD_GEBEN        ({"geb","gib","gibe","gebe"}) // gibe ist in der mudlib implementiert !?
#define CMD_GREIFEN      ({"greif","greife","fass","fasse"})
#define CMD_WERFEN       ({"wirf","werfe","werf"})
#define CMD_DURCHSUCHEN  ({"wuehl","wuehle","durchwuehl","durchwuehle", \
                           "durchsuch","durchsuche"})
#define CMD_OEFFNEN      ({"oeffne"})
#define CMD_SCHLIESSEN   ({"schliess", "schliesse"})
#define CMD_KRAXELN      ({"kraxel","kraxle","kraxl","kraxele"})
#define CMD_VERRIEGELN   ({"verriegel","verriegle"})
#define CMD_ENTRIEGELN   ({"entriegel","entriegle"})
#define CMD_SAGEN        ({"'",",","sag","sage","sprech","spreche","sprich"})
#define CMD_UNTERSUCHEN  ({"unt","untersuch","untersuche","schau","schaue", \
                           "betr","betracht","betrachte"})
#define CMD_KAUFEN       ({"kauf","kaufe","ersteh","erstehe"})
#define CMD_SPRINGEN     ({"spring","springe","huepf","huepfe"})
#define CMD_BETRETEN     ({"betret","betrete","betritt","besteige","besteig"})
#define CMD_TRINKEN      ({"trink","trinke","sauf","saufe"})
#define CMD_ESSEN        ({"ess","iss","esse"})
#define CMD_LESEN        ({"lies","les","lese"})
#define CMD_ZWAENGEN     ({"zwaeng","zwaenge","schluepf","schluepfe"})
#define CMD_LAUFEN       ({"lauf","laufe","geh","gehe"})
#define CMD_GEHEN        ({"lauf","laufe","geh","gehe"})
#define CMD_KRIECHEN     ({"kriech","krieche","krabbel","krabbele","rob","robbe"})
#define CMD_ZERBRECHEN   ({"zerbrech","zerbreche","zerbrich"})
#define CMD_SCHREIBEN    ({"schreib","schreibe","kritzel","kritzele","kritzle"})
#define CMD_SETZEN       ({"setz","setze","sitz","sitze"})
#define CMD_DRUECKEN     ({"drueck","druecke"})
#define CMD_KLOPFEN      ({"klopf","klopfe"})
#define CMD_SCHWIMMEN    ({"schwimm","schwimme"})
#define CMD_BADEN        ({"bad","bade"})

#endif

