#define GEBIET "central"

#define DB(x) if(find_player("ronja")) tell_object(find_player("ronja"), "\nXXX "+x+"\n\n")

#include "../def.h"

#define UMASTER "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/master"
#define DHRKIONMASTER "/d/unterwelt/zordan/dhrkion/master/dhrkion"
#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))
#define WRITELOG(x) write_file("/log/d/unterwelt/kills.log",ctime()+":"+x+".\n")
#define BSI(x,y) break_string(x,78,y,1)

#define DROWNPCLOG(x,y,z,p) write_file("/log/d/unterwelt/drownpc.log", \
  ctime()+":"+x->Name(WER)+"("+file_name(x)+") "+y+" "+ \
  z->name(WEN)+"("+file_name(z)+") von "+CAP(getuid(p))+".\n")

#define KILLLOG(x,y) write_file("/log/d/unterwelt/kills.log", \
  ctime()+":"+x+" hat gerade "+y+" umgebracht.\n")

//--------------------------------------------------------------------------

#define SPINNEN_REGION ({ROOM "01-10-01" \
                        ,ROOM "01-09+00" \
                        ,ROOM "01-09-01" \
                        ,ROOM "01-09-02" \
                        ,ROOM "01-08-01" \
                        })

#define DHRKIONGANG ({ROOM "00-09-04" \
                     ,ROOM "00-10-04" \
                     ,ROOM "01-11-04" \
                     ,ROOM "02-12-04" \
                     ,ROOM "02-13-03" \
                     })

#define GNOM_REGION ({ROOM "00+07+02" \
                     ,ROOM "00+07+03" \
                     ,ROOM "00+07+04" \
                     ,ROOM "00+07+05" \
                     ,ROOM "00+06+05" \
                     ,ROOM "00+05+05" \
                     })

#define SEE_REGION ({ROOM "00-03+02" \
                    ,ROOM "00-07+03" \
                    ,ROOM "00-07+04" \
                    ,ROOM "00-08+04" \
                    ,ROOM "00-09+03" \
                    ,ROOM "00-10+03" \
                    })

#define BAT_REGION ({ROOM "00+03-06" \
                    ,ROOM "00+03-07" \
                    ,ROOM "00+04-05" \
                    ,ROOM "00+04-06" \
                    ,ROOM "00+04-07" \
                    ,ROOM "00+05-05" \
                    ,ROOM "00+05-06" \
                    })


#define REGION1 ({ROOM "00+00+10" \
                 ,ROOM "00+01+10" \
                 ,ROOM "00+02+10" \
                 ,ROOM "00+03+08" \
                 ,ROOM "00+03+09" \
                 ,ROOM "00+04+07" \
                 ,ROOM "00+04+08" \
                 ,ROOM "00+05+05" \
                 ,ROOM "00+05+08" \
                 ,ROOM "00+06+05" \
                 ,ROOM "00+06+08" \
                 ,ROOM "00+07+00" \
                 ,ROOM "00+07+01" \
                 ,ROOM "00+07+02" \
                 ,ROOM "00+07+03" \
                 ,ROOM "00+07+04" \
                 ,ROOM "00+07+05" \
                 ,ROOM "00+07+08" \
                 ,ROOM "00+08+03" \
                 ,ROOM "00+08+05" \
                 ,ROOM "00+08+06" \
                 ,ROOM "00+08+07" \
                 ,ROOM "00+09+04" \
                 ,ROOM "00+09+08" \
                 ,ROOM "00+10+04" \
                 ,ROOM "00+10+08" \
                 ,ROOM "00+10+09" \
                 ,ROOM "00+10+10" \
                 ,ROOM "00+11+04" \
                 ,ROOM "00+11+11" \
                 ,ROOM "00+11+12" \
                 })

#define REGION2 ({ROOM "00+00-07" \
                 ,ROOM "00+00-09" \
                 ,ROOM "00+00-10" \
                 ,ROOM "00+00-13" \
                 ,ROOM "00+01-08" \
                 ,ROOM "00+01-09" \
                 ,ROOM "00+01-11" \
                 ,ROOM "00+01-12" \
                 ,ROOM "00+02-08" \
                 ,ROOM "00+02-13" \
                 ,ROOM "00+03-06" \
                 ,ROOM "00+03-07" \
                 ,ROOM "00+03-14" \
                 ,ROOM "00+04-05" \
                 ,ROOM "00+04-06" \
                 ,ROOM "00+04-07" \
                 ,ROOM "00+04-14" \
                 ,ROOM "00+05-05" \
                 ,ROOM "00+05-06" \
                 ,ROOM "00+05-15" \
                 ,ROOM "00+06-01" \
                 ,ROOM "00+06-03" \
                 ,ROOM "00+06-04" \
                 ,ROOM "00+07-02" \
                 ,ROOM "01+04-06" \
                 ,ROOM "00-01-06" \
                 })

#define REGION3 ({ROOM "00-01-13" \
                 ,ROOM "00-01-14" \
                 ,ROOM "00-02-12" \
                 ,ROOM "00-02-15" \
                 ,ROOM "00-03-12" \
                 ,ROOM "00-04-10" \
                 ,ROOM "00-04-11" \
                 ,ROOM "00-05-07" \
                 ,ROOM "00-05-08" \
                 ,ROOM "00-05-09" \
                 ,ROOM "00-06-01" \
                 ,ROOM "00-06-02" \
                 ,ROOM "00-06-06" \
                 ,ROOM "00-07-01" \
                 ,ROOM "00-07-02" \
                 ,ROOM "00-07-03" \
                 ,ROOM "00-07-04" \
                 ,ROOM "00-07-05" \
                 ,ROOM "00-07-06" \
                 ,ROOM "00-08-03" \
                 ,ROOM "00-08-04" \
                 ,ROOM "00-08-05" \
                 ,ROOM "00-08+02" \
                 })

#define REGION4 ({ROOM "00-01+11" \
                 ,ROOM "00-01+12" \
                 ,ROOM "00-02+13" \
                 ,ROOM "00-03+13" \
                 ,ROOM "00-04+06" \
                 ,ROOM "00-04+07" \
                 ,ROOM "00-04+13" \
                 ,ROOM "00-05+06" \
                 ,ROOM "00-05+07" \
                 ,ROOM "00-05+12" \
                 ,ROOM "00-06+05" \
                 ,ROOM "00-06+08" \
                 ,ROOM "00-06+12" \
                 ,ROOM "00-07+00" \
                 ,ROOM "00-07+03" \
                 ,ROOM "00-07+04" \
                 ,ROOM "00-07+08" \
                 ,ROOM "00-07+09" \
                 ,ROOM "00-07+12" \
                 ,ROOM "00-08+01" \
                 ,ROOM "00-08+04" \
                 ,ROOM "00-08+10" \
                 ,ROOM "00-08+11" \
                 ,ROOM "00-09+03" \
                 ,ROOM "00-09+12" \
                 ,ROOM "00-10+03" \
                 ,ROOM "00-10+12" \
                 ,ROOM "00-10+13" \
                 ,ROOM "00-10+14" \
                 ,ROOM "00-10+15" \
                 ,ROOM "00-10+16" \
                 ,ROOM "00-11+12" \
                 ,ROOM "00-12+12" \
                 ,ROOM "00-13+12" \
                 ,ROOM "00-14+12" \
                 ,ROOM "00-15+12" \
                 ,ROOM "00-15+13" \
                 ,ROOM "00-16+12" \
                 ,ROOM "00-17+11" \
                 ,ROOM "00-17+12" \
                 ,ROOM "00-18+10" \
                 ,ROOM "00-19+09" \
                 ,ROOM "00-20+08" \
                 ,ROOM "00-21+07" \
                 ,ROOM "00-22+07" \
                 ,ROOM "01-01+11" \
                 })


