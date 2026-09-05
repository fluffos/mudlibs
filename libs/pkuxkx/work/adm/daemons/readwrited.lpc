//bye yuer

string *write_name = ({
        "/hslj/order",
        "/hslj/huashanlunjian",
	"/d/xinfang/temproom",
         "/u/icer/obj/xitangok",

});

string *rm_name = ({
        "/data/board/hslj_b.o",
        "/data/board/temp.o",
});


int file_write( string file, string str, int flag )
{
                if( member_array(file, write_name)!=-1 ) 
                {
			seteuid(ROOT_UID);
                write_file(file,str,flag);
                return 1;
                }
                else            
                {
                write("对不起，你没有权限。\n");
                return 0;
                }
      return 0;
}

int file_rm(string file)
{

        if( member_array(file, rm_name)!=-1 ) 
                {
			seteuid(ROOT_UID);
                rm(file);
                return 1;
                }
                else    
                {
                write("对不起，你没有权限。\n");
                return 0;
                }
   return 0;
}
void dest_ob(object ob)
{
        seteuid(ROOT_UID);
        destruct(ob);
}
