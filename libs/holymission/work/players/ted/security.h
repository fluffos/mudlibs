/* wizard level catagories */
#define SENIOR 300
#define SPONSOR 100
#define HIGH_WIZARD 100
#define ELDER 500
#define ADMIN 700
#define GOD 10000
#define APPRENTICE 30
#define WIZARD 31
#define CREATOR 40

/* standard security */
#define EXPLORE 30
#define CREATE 31
#define TITLE 31
#define INVIS SPONSOR
#define STAT CREATE
#define OUT_OF_BODY SPONSOR
#define CONTROL SENIOR
#define SNOOP SENIOR
#define DAMAGE SENIOR
#define ITEM_OVER SENIOR
#define ECHO SPONSOR
#define SHUTDOWN GOD
#define EDIT_STANDARD ADMIN
#define ALL_POWER GOD

/* invisability */
#define NO_SHORT 20
#define CAN_NO_SHORT 60
#define NO_WHO 30
#define CAN_NO_WHO 70
#define SOMEONE 40
#define CAN_SOMEONE 75
#define INVIS_TELEPORT 50
#define CAN_INVIS_TELEPORT 80
#define INVIS_ACTION 60
#define CAN_INVIS_ACTION 85
#define NO_ID 500
#define CAN_NO_ID 300
#define NO_PEOPLE 100
#define CAN_NO_PEOPLE 500
#define COMPLETELY_GONE 120
#define CAN_COMPLETELY_GONE 10000
/* to make life easier */
#define INV1 NO_SHORT
#define CINV1 CAN_NO_SHORT
#define INV2 NO_WHO
#define CINV2 CAN_NO_WHO
#define INV3 SOMEONE
#define CINV3 CAN_SOMEONE
#define INV4 INVIS_TELEPORT
#define CINV4 CAN_INVIS_TELEPORT
#define INV5 INVIS_ACTION
#define CINV5 CAN_INVIS_ACTION
#define INV6 NO_ID
#define CINV6 CAN_NO_ID
#define INV7 NO_PEOPLE
#define CINV7 CAN_NO_PEOPLE
#define INV8 COMPLETELY_GONE
#define CINV8 CAN_COMPLETELY_GONE


/* file access */
#define ED_OTHERS   SENIOR
#define ED_LOG	    ELDER
#define READ_OTHERS STAT


/* object access */
#define private if (this_player() != this_object()) return 0
