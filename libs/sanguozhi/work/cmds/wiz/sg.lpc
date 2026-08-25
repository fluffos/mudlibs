// sg.c by fire on Apri 1998
inherit CMD;
private void main(string arg)
{
   string fname = arg;
   mapping map_list=([]);
   map_list["sg"]= PDOMAIN;
   map_list["area"]=PAREA;
   map_list["txt"]= PTXT;  
   map_list["module"]= PMODULES;  
   map_list["obj"]= POBJ;  
   map_list["map"]= PMAP;  
   map_list["help"]=PHELP ;  
   map_list["about"]= PABOUT;  
   map_list["other"]=POTHER ;  
   map_list["city"]= PCITY;  
   map_list["town"]= PTOWN;  
   map_list["guan"]= PGUAN;  
   map_list["changan"]= PCHANGAN;  
   map_list["luoyang"]= PLUOYANG;
   map_list["anding"]=PANDING ;
   map_list["xiakou"]=PXIAKOU ;
   map_list["hongnong"]=PHONGNONG;
   map_list["general"]=PGENERAL ;
   map_list["keeper"]= PKEEPER;
   map_list["king"]=PKING ;
   map_list["moshi"]=PMOSHI ;
   map_list["book"]=PBOOK;
   map_list["eat"]=PFOODANDDRINK;
   map_list["money"]=PMONEY;
   map_list["cloth"]=PCLOTH;
   map_list["horse"]=PHORSE;
   map_list["weapon"]=PWEAPON;
   map_list["armor"]=PARMOR;
   map_list["breast"]=PBREAST;
   map_list["hand"]=PHAND;
   map_list["hat"]=PHAT;
   map_list["pants"]=PPANTS;
   map_list["shoe"]=PSHOE;
   map_list["torso"]=PTORSO;
   map_list["blade"]=PBLADE;
   map_list["hammer"]=PHAMMER;
   map_list["ji"]=PJI;
   map_list["sword"]=PSWORD;
   map_list["event"]=PEVENT;
   map_list["cmd"]=PCMD;
  map_list["job"]=PJOB;
    if ( !fname )
    {
        fname = "sg";
    }
      
	fname=map_list[fname];
    if(!stringp(fname))
    {
	    printf("没有此路径\n");return;
    }
    this_body()->query_shell_ob()->set_pwd(fname);
    printf("当前目录: %s\n",fname);
}
