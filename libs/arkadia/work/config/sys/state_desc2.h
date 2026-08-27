/*
   sys/state_desc2.h

   Holds all textual descriptions of state descriptions of livings.
   
   Here local changes are made to the arrays defined in
   /sys/state_desc.h
*/

/*
   If you insert changes you are recommended to copy /sys/state_desc.h
   to here and make changes. It is important that the below define is
   defined afterwards:
  
#ifndef SD_DEFINED
#define SD_DEFINED
#endif

*/

/*
 * SD_AV_TITLES
 * 
 * The mortal 'level' titles.
 */
#define SD_AV_TITLES ({ "kompletny zoltodziob",			\
			"ktos kto jeszcze niewiele widzial",	\
			"ktos kto niewiele wie o swiecie",	\
			"ktos kto widzial juz to i owo",	\
			"ktos kto niejedno widzial",		\
			"doswiadczona osoba",			\
			"ktos kto wiele przeszedl",		\
			"osoba ktora zwiedzila caly swiat",	\
			"wielce doswiadczona osoba" })

#define SD_AVG_TITLES	({ "kompletnego zoltodzioba",			\
			   "kogos, kto jeszcze niewiele widzial",	\
			   "kogos, kto niewiele wie o swiecie",		\
			   "kogos, kto widzial juz to i owo",		\
			   "kogos, kto niejedno widzial",		\
			   "doswiadczona osobe",			\
			   "kogos, kto wiele przeszedl",		\
			   "osobe, ktora zwiedzila caly swiat",		\
			   "wielce doswiadczona osobe",	})
