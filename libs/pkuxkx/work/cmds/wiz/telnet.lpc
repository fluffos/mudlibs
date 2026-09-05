inherit F_CLEAN_UP; 
  
void create() 
{ 
        seteuid(getuid()); 
} 
  
int main(object me,string arg) 
{ 
        object ob; 
        object linkob; 
        object *tcpip; 
        int i; 
        me=this_player(); 
  
        if( strsrch(arg," ")==-1) arg+=" 23"; 
        tcpip=children("/adm/daemons/network/tcpip");
        ob=new("/adm/daemons/network/tcpip"); 
        linkob = me->query_temp("link_ob"); 
        exec(ob,me); 
        ob->do_telnet(arg); 
        ob->do_command(""); 
        me->save(); 
        linkob->save(); 
        call_out("do_dest",2,me); 
        call_out("do_dest",2,linkob); 
        return 1; 
} 
void do_dest(object ob) 
{ 
        destruct(ob); 

} 
  

