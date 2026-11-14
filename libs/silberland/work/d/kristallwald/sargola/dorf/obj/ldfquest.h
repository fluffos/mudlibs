/*
**************************************************
** 
** Quest-Item Headerfile
** von der Land der Ferne Quest
**
**
**************************************************
*/

int *wert=({0,0,0,0,0,0,0,0,0,0,0,0,0});	//Startinitialisierung 0
int *beschreibungen
=({"STARTQUEST","FLASCHE","MANTEL","FADEN","SCHERE","WOLLE","GARN","ERLAUBNIS","ZUCKER","ESSEN","TRINKEN","BERGHINWEIS","SCHWERT"});
//beschreibungen nur fuer die debug-print-ausgabe

#define STARTQUEST 0	// 1:Quest begonnen

#define FLASCHE 1	// 1:man hat danch gefragt
			// 2:man hat Flasche bekommen
			// 3:man hat Klang in der Flasche
			
#define MANTEL 2	// 1:man hat den Mantel bekommen (mit Loch)
			// 2:man hat Mantel repariert

#define FADEN 3		// 1:man hat den Naehfaden bekommen (aus Lade)

#define SCHERE 4	// 1:man hat die Schere bekommen

#define WOLLE 5		// 1:man hat schmutzige Wolle
			// 2:man hat die Wolle gewaschen
			// 3:man hat die Wolle gekaemmt
			
#define GARN 6		// 1:man hat das Garn gefunden

#define ERLAUBNIS 7	// 1:man hat die Erlaubnis vom Koenig

#define ZUCKER 8	// 1:man hat Zucker bekommen
			// 2:man hat Miramis gefuettert

#define ESSEN 9		// 1:man hat Eno was zu essen gegeben
#define TRINKEN 10	// 1:man hat Eno was zu trinken gegeben

#define BERGHINWEIS 11	// 1:man hat den Hinweis von Eno, wo der Stollen ist

#define SCHWERT 12	// 1:man hat das Schwert bekommen


			 
