/*
**  Header fuer service.c
**
**  (c) 1999 by Cirion@Silberland
**
**
**  20/09/1999 Release
**
*/

#define VERSION "v0.02"
#define DATE "21.09.1999"

/* Erlaubte Flags fuer den Error-Aufruf */
#define FL_LOG 1
#define FL_MAG 2
#define FL_DEB 4
#define FL_MAS 8

#define ERR_FLAGS ({FL_LOG,FL_MAG,FL_DEB,FL_MAS})

#define SERVHOME "/gilden/nekromanten/service"
#define SERVTOOL SERVHOME"/tools/servtool"
#define SERVOBJ SERVHOME"/obj/service"

/* Properties zum Speichern */
#define P_SEC_ACCESS "sec_access"
#define P_SEC_LOGFILES "sec_logfiles"