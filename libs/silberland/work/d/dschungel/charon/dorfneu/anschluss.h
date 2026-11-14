/*** Questspezifische Defines ***/
#define KANNIBALENDORFQUEST    "1000 Qualen im Dorf der Kannibalen"
#define KANNIBALENDORFQUESTLOG "/log/quests/kannibalendorf"
//#define KANNIBALENDORFQUESTLOG2 KANNIBALEN_DORF("log/kannibalendorf.log")

#define BUSCH "/d/dschungel/trintrasil/dorfneu/room/busch"

#define KDQ_BOLZENSCHNEIDER_GEFUNDEN 0x01
#define KDQ_CAROLINA_BEFREIT         0x02
#define KDQ_HAARE_ABGESCHNITTEN      0x04

#define KDQSTRING ([0x01: "Bolzenschneider gefunden", \
                    0x02: "Carolina befreit",\
                    0x04: "Haare des Waechters abgeschnitten",\
                    ])
                    
#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),x);
#endif                 
