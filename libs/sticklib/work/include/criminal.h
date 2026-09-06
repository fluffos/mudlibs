/* Levels of crimes */

#define CR_DISTURBANCE	1
#define CR_THEFT	5
#define CR_SMUGGLING	6
#define CR_BURGLARY	7
#define CR_ASSAULT	9
#define CR_MANSLAUGHTER	15
#define CR_WITCHCRAFT	17
#define CR_MURDER	20

/* You MUST use this defination! */
#define CRIME_D "/secure/criminal"

/* Criminal daemon should be at /bin/daemons but save_object currently
   fails from there. It WILL be moved there, so DO USE the defination! */
