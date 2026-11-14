/*
************************************************
* hallen.h					*
** Die Hallen der Shardin         		*
** Irrgartensystem            			*
** date: 10-03-97 by Sargola@Silberland     	*
** Email: a9504778@unet.univie.ac.at         	*
*************************************************
*/ 


#define HALLEN								\
  AddDetail( ({"halle","hallen"}), 					\
	"Du verfluchst die Hallen hier. Es ist kuehl, feucht, es "	\
	"stinkt und Du moechtest ins Dorf und einen ordentlichen "	\
	"Drink nehmen.");						\
									\
  AddDetail( "mief", 							\
	"Sowas zu untersuchen ist schwierig. Riech doch einfach "	\
	"mal!");							\
									\
  AddDetail( ({"gaenge","gang", "stollen"}),				\
	"Es sind grob gehauene Stollen, die nicht darauf "		\
	"schliessen lassen wuerden, dass hier jemand wohnt. "		\
	"Vielleicht schaust Du schnell wieder, dass Du hier raus "	\
	"kommst.");							\
									\
  AddDetail( ({"felsen","fels"}), 					\
	"Der Fels ist kuehl und sehr rauh. Er gehoert wohl zum "	\
	+"Almandin-Gebirge.");						\
									\
  AddDetail( ({"almandin gebirge","gebirge"}),				\
	"Das Almandin-Gebirge erstreckt sich westlich des Kristll"	\
	"waldes. Genau genommen stehst Du unter seinen "		\
	"Berggipfeln.");						\
									\
  AddDetail( ({"gipfel","berggipfel"}),					\
	"Sie muessen irgendwo ueber Dir sein.");			\
									\
  AddDetail( "boden",							\
	"Der Boden ist uneben und steinig. Einzelne Steine liegen "	\
	"verstreut herum, eine Schicht von Staub bedeckt den "		\
	"Boden.");							\
  AddDetail( ({"stein","steine"}),					\
	"Sie muessen von den Waenden abgebroeckelt sein.");		\
									\
  AddDetail( ({"wand","waende"}),					\
	"Die Waende sind genauso schlampig und grob aus dem Fels "	\
	"gearbeitet wie die Decke.");					\
									\
  AddDetail( ({"decke"}),						\
	"Die Felsen an der Decke haengen unregelmaessig herunter - "	\
	"Du musst aufpassen, dass Du Dir nicht den Kopf stoesst!");	\
									\
  AddDetail( ({"kopf"}),						\
	"Dein Kopf und vor allem Dein Orientierungssinn sind das, "	\
	"was Du hier am meisten brauchst!");				\
									\
  AddDetail( ({"orientierungssinn", "sinn"}),				\
	"Ohne ihn kommst Du hier nie wieder raus.");			\
									\
  AddDetail( ({"mensch"}),						\
	"Du kannst weder Spuren noch sonst Anzeichen von anderen "	\
	"Abenteurern entdecken.");					\
									\
  AddDetail( ({"anzeichen","zeichen"}),					\
	"Schritte im Staub oder sowas in der Art haettest Du "		\
	"schon gern gehabt.");						\
									\
 AddDetail( ({"abenteurer"}),						\
	"Du scheinst der erste seit langer Zeit zu sein, der "		\
	"sich hier rein traut.");					\
									\
 AddDetail( ({"zeit"}),							\
	"Du wuerdest sie lieber woanders verbringen.");			\
									\
 AddSmell(DEFAULT_SMELL,						\
	"BUAAEEHH! Der Staub und der Mief hier drin - "			\
	"fuerchterlich!\n");						\
									\
 AddSmell( "staub",							\
	"HUST! Am Staub riechen! Was fuer eine Idee!\n");		\
									\
 AddSmell("mief",							\
	"Rieche Mief! Sowas faellt doch nur einem Script ein, "		\
	"oder?\n");							\
									\
 AddSound (DEFAULT_SOUND,						\
	"Es ist absolut still hier drin.\n");


#define SPUREN								\
  AddDetail( ({"staub","schicht","schichte","staubschicht"}),			\
	"Der Boden ist mit einer dichten Schichte Staub ueberzogen. "	\
	"Hmm... Wenn doch nur Spuren hier waeren...");			\
									\
  AddDetail( ({"spur","spuren"}),					\
	"Die gibt es hier leider nicht. Doch Halt! Vielleicht ist "	\
	"es ja nur Einbildung, aber Du glaubst, dass Du feine "		\
	"Eindruecke im Staub siehst.");        				\
									\
  AddDetail("einbildung",						\
	"Ob Du Dir das nur ausdenkst?");				\
									\
  AddDetail( ({"eindruck","eindruecke"}),				\
	"Sie kommen aus dem "+CAP(DIR_ZURUECK)+" und fuehren in den "	\
	+CAP(DIR_VOR)+"...\n");						
	 
 
#define KEINE_SPUREN							\
  AddDetail( ({"staub","schicht","schichte","staubschicht"}),			\
	"Der Boden ist mit einer dichten Schichte Staub ueberzogen.");	\
									\
  AddDetail( ({"spur","spuren"}),					\
	"Die gibt es hier leider nicht.");
	 
	 

