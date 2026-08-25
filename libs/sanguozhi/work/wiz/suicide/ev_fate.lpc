#define LOG  "/wiz/suicide/fate.log"
inherit M_ACCESS;
void start()
{ mixed * tz_info;
  string filename,season,msg;
  int adjust;
  mixed * p_date;
  p_date = DAY_D->query_date(); 
if (p_date[3]!=FATE_D->get_create_year())
FATE_D->create_tz_table(p_date[3]);
  switch (p_date[2]) 
  {
   case 1:
   case 2:
   case 3:
        season="spring";
        break;
   case 4:
   case 5:
   case 6:
        season="summer";
        break;
   case 7:
   case 8:
   case 9:
        season="autumn";
        break;
   case 10:
   case 11:
   case 12:
        season="winter";
        break;
  }
   
    
  tz_info = ("/wiz/suicide/fate_d")->query_tz_info(season);
  if (!sizeof(tz_info)) SGSYS("天灾信息遗失!\n");
  foreach(mixed *info in tz_info){
        filename = "/wiz/suicide/ev_fate/ev_"+info[1];
        //SGSYS(filename);
        
        if (adjust=(filename)->can_do_fate(info[0]))
          {
           (filename)->do_fate(info[0],adjust);
            msg = sprintf("%s 发生 %s at %s\n",info[0],info[1],ctime(time()));
            unguarded(1, (: write_file, LOG,msg:));
          }
        else
           {SGSYS(sprintf("%s躲过了%s的fate\n",info[0],info[1]));
            msg = sprintf("%s 发生 %s at %s\n",info[0],info[1],ctime(time()));
            unguarded(1, (: write_file, LOG,msg:));
            }
 }   
}
 
