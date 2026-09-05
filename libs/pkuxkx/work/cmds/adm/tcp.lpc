inherit F_CLEAN_UP; 

int do_telnet(string arg,object me);
void create()  
{  
        seteuid(getuid());  
} 

int main(object me,string arg) 
{ 
        object ob; 
        object linkob;         
        
        me=this_player(); 
         if(!arg) return notify_fail("你要连线去哪里？\n");
        do_telnet(arg,me);//连线

        ob->do_command(""); 
        //me->save(); 
        //linkob->save(); 
        call_out("do_dest",2,me); 
        call_out("do_dest",2,linkob); 
        return 1; 
} 
void do_dest(object ob) 
{ 
        destruct(ob); 
} 


int do_telnet(string arg,object me)
{

        object ob; 
        object linkob; 
        string telnetip,*file,letterip,ip;
        mapping ip_mapping=([]);
        int i;
                
///////////ip解析///////////////////
	telnetip=read_file("/clone/misc/telnetip.data");
	if(!telnetip){
	    assure_file("/clone/misc/telnetip.data");
	    if(!write_file("/clone/misc/telnetip.data","bbs.pku.edu.cn@#@162.105.203.245\n",1));
		return 0;
	    telnetip="bbs.pku.edu.cn@#@162.105.203.245\n";
	//省却下面还要判断有没有file这个文件的麻烦
	} 
	file=explode(telnetip,"\n");
	ip_mapping=allocate_mapping(sizeof(file));
	for(i=0;i<sizeof(file);i++){
	    //if(all_password[i][0]=='#'||
	      if(sscanf(file[i],"%s@#@%s",letterip,ip)!=2) continue;
		ip_mapping[letterip]= ip;//bbs.pku.edu.cn(letterip) 162.105.203.245(ip)
	}
	if(ip_mapping[arg]) {
		arg=ip_mapping[arg];//转换
	        arg+=" 23";
	}	
        if( strsrch(arg," ")==-1) arg+=" 5000";

        ob=new("/clone/misc/tcp");
        linkob = me->query_temp("link_ob"); 
        linkob->save();
        me->save();
        exec(ob,me); 
        ob->do_telnet(arg); 
        ob->do_command(""); 
        call_out("do_dest",2,me); 
        call_out("do_dest",2,linkob); 
        return 1; 
} 
