#define BSI(x,y) break_string(x,78,y,1)
#define DB(x) if(find_player("ronja")) tell_object(find_player("ronja"), "\nXXX "+x+"\n\n")
#define LW(x) (sizeof(x)==1 ? x[0] : implode(x[0..<2],", ")+" und "+x[<1])
#define KMASTER "/d/ebene/Midas/room/kaesemaster"
#define SAVEFILE "/d/ebene/Midas/room/kaeseladen"
#define CHEESE "/d/ebene/obj/div/"
#define WRITELOG(x) write_file("/log/d/ebene/midas/kaeseladen.log",ctime()+":"+x+".\n")
#define TPUID capitalize(getuid(this_player()))

#define KAESEKOSTEN 800
#define KAESEZEIT (3600+random(3600))

#define MISSING_NOTHING 0
#define MISSING_MILK 1
#define MISSING_LAB 2
#define MISSING_MONEY 4

#define MISSING_MILK_LAB 3
#define MISSING_MILK_MONEY 5
#define MISSING_LAB_MONEY 6
#define MISSING_MILK_LAB_MONEY 7

