/* 
** Die Eigenschaften der Rasse:                   2001-07-05 Orw@Silberland
** Frostzwerge
**
** Update              Version   Comments
** ------------------------------------------------------------------------
** 0000-00-00            1.0     Release
**
**
*/

#define ADJ(x)    eigenschaften[x, 0] // Adjektive
#define SHANDS(x) eigenschaften[x, 1] // Handsstring
#define ZHANDS(x) eigenschaften[x, 2] // Hands Zuschlag
#define DAMTYP(x) eigenschaften[x, 3] // Damagetypen fuer Hands
#define ZLVL(x)   eigenschaften[x, 4] // Levelzuschlag
#define ZHPS(x)   eigenschaften[x, 5] // Lebenspunktezuschlag
#define ZBODY(x)  eigenschaften[x, 6] // Bodyzuschlag
#define ZXPS(x)   eigenschaften[x, 7] // XP Zuschlag
#define ZSIZE(x)  eigenschaften[x, 8] // Zuschlag fuer Groesse
#define ZALIGN(x) eigenschaften[x, 9] // Align Zuschlag
#define WIMP(x)   eigenschaften[x,10] // Vorsicht in % der max HPs
#define SPRATE(x) eigenschaften[x,11] // Spellrate
#define RSTW(x)   eigenschaften[x,12] // Ruestungswert
#define NOMAG(x)  eigenschaften[x,13] // Zauberabwehrwert
#define AGGR(x)   eigenschaften[x,14] // Aggressivitaet

mapping eigenschaften = 
([ 1:"froehlich";"mit froehlicher Miene";0;({DT_BLUDGEON});
      0;  5;  0;    0;  0; 100;  0; 5; 3; 0; 0,
   2:"wendig";"mit schnellen Handkantenschlaegen";20;({DT_SLASH});
      2; 10;  5;  500;  0;   0;  0; 5; 3; 0; 0,
   3:"schmutzig";"mit dreckigen Fingernaegeln";0;({DT_RIP,DT_POISON});
      0;-10;  0;    0;  0;   0;  0; 5; 2; 0; 0,
   4:"haesslich";"mit blossen Haenden";0;({DT_BLUDGEON});
      0;  0;  0;    0;  0;   0;  0; 5; 3; 0; 0,
   5:"wuetend";"mit schrecklicher Wut";0;({DT_BLUDGEON,DT_TERROR});
      7;  0; 20; 1000;  0;   0;  0; 5; 4; 0;
      ([P_RACE:(["Elf":1.0,"Dunkelelf":1.0, 0:0.1])]),
   6:"grantig";"mit einem finsteren Blick";0;({DT_BLUDGEON});
      2;  0;  0;    0;  0;-300;  0; 5; 2; 0;
      ([P_RACE:(["Elf":0.5,"Dunkelelf":0.5, 0:0.1])]),
   7:"muskuloes";"mit gestaehltem Bizeps";50;({DT_BLUDGEON});
      8;100; 20; 2000; 15;   0;  0; 5; 3; 0; 0,
   8:"jung";"mit jugendlichem Leichtsinn";-10;({DT_BLUDGEON});
     -6;  0;  0; -100;-10;   0; 20; 3; 1; 0; 0,
   9:"frech";"mit frechem Grinsen";0;({DT_BLUDGEON});
      0;  0;  0;    0;  0;-150;  0; 5; 2; 0;
      ([P_RACE:(["Elf":0.1,"Dunkelelf":0.5, 0:0.0])]),
  10:"schlaefrig";"mit lautem Gaehnen";-15;({DT_BLUDGEON});
     -2;  0; -5; -100;  0;   0; 30; 3; 1; 0; 0,
  11:"brutal";"mit einem Schlag auf die Nase";30;({DT_BLUDGEON});
      3;  0;  0;  500;  0;-230;  0; 6; 4; 0;
      ([P_RACE:(["Elf":0.1,"Dunkelelf":1.0, 0:0.0])]),
  12:"eisig";"mit eiskaltem Blick";10;({DT_BLUDGEON,DT_COLD});
      2;  0; 10;  500;  0;   0;  0; 5; 3; 0; 0,
  13:"alt";"mit uralter Weisheit";0;({DT_BLUDGEON,DT_MAGIC});
     14;-20; -5;    0;  0;   0;  0;15; 3;10; 0,
  14:"dick";"mit schmierigen Haenden";-10;({DT_BLUDGEON});
      0;  0; 10;    0;  0; 150; 10; 5; 2; 0; 0,
  15:"kriegerisch";"nach feinster Kriegskunst";50;({DT_BLUDGEON});
     15;  0; 10; 2000;  5;   0;  0;10; 5; 0; 0,
  16:"rotbaertig";"mit dem langen roten Bart";0;({DT_SLASH});
      0;  0;  0;    0;  0;   0;  0; 5; 3; 0; 0,
  17:"klein";"mit putzigen Haenden";-10;({DT_BLUDGEON});
     -5;-20;-10;-1000;-15;   0; 40; 3; 1; 0; 0,
  18:"lustig";"mit breitem Laecheln";0;({DT_BLUDGEON});
      0;  0;  0;    0;  0; 300;  0; 5; 3; 0; 0,
  19:"irr";"mit wahnsinnigem Kichern";15;({DT_BLUDGEON,DT_TERROR});
      0;  0; 10;  500;  0;-300; 20; 9; 2; 0; 0.5,
  20:"muerrisch";"argelnd";0;({DT_BLUDGEON});
      0;  0;  0;    0;  0;-400;  0; 5; 3; 0; 0,
  21:"wild";"bruellend";30;({DT_BLUDGEON});
      5;  0;  0;  500;  0;-200;  0; 6; 4; 0;
      ([P_RACE:(["Elf":0.1,"Dunkelelf":1.0,"Troll":0.5,0:0.0])]),
  22:"schwaechlich";"zoegernd";-20;({DT_BLUDGEON});
     -6;  0;-10;-1000; -6;  50; 50; 2; 0; 0; 0,
  23:"kaltbluetig";"ohne Gewissen";30;({DT_BLUDGEON,DT_TERROR});
     10;  0;  0; 1000;  0;-500;  0;20; 5; 5; 0 ]);

