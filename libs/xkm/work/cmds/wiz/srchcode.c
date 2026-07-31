//Seashore 
#include <ansi.h>
inherit F_CLEAN_UP; 
int main(object me, string arg) 
{ 
	int i, j; 
	string srchdir, srchcode, dir, content; 
	mixed *file;       

	if(!arg || sscanf(arg, "%s for %s", srchdir, srchcode)!=2 )
		return notify_fail("Ö¸Áî¸ñÊ½£ºsrchcode  <directory> for <code>\n");           

	seteuid( geteuid(me) ); 
	dir = resolve_path(me->query("cwd"), srchdir); 
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/"; 
	file = get_dir(dir, -1); 
	if( !sizeof(file) ) 
	{
		if (file_size(dir) == -2) 
			return notify_fail("Ä¿Â¼ÊÇ¿ÕµÄ¡£\n"); 
		else 
			return notify_fail("Ã»ÓĞÕâ¸öÄ¿Â¼¡£\n");
	} 
	i = sizeof(file); while(i--) 
	{ 
		if (file[i][1]==-2) file[i][0] += "/"; 
	} 
	write("Ä¿Â¼£º" + dir + "\n"); 
	if (sizeof(file)) 
	for(i=0, j = sizeof(file); i < j; i++) 
	{ 
             	if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")) 
                {
	  		content = read_file(dir+file[i][0]);
			if (strsrch(content,srchcode) >= 0) 
				write(HIR"OK! "+dir+file[i][0] + " is found!\n"NOR);
		}
/*		if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.h")
             		content = read_file(dir+file[i][0]+".h");
		if (strsrch(content,srchcode)>=0)
			write("OK! "+dir+file[i][0]+".c" + "found!\n");
*/		
		else if (file[i][1]==-2) 
		{
			write("searching subdirectory:"+dir+file[i][0]+"\n");
			call_other(__FILE__,"main", me,dir+file[i][0]+" for "+srchcode);
		}
	}
	else write("Ã»ÓĞÈÎºÎµµ°¸¡£\n"); 
    	return 1;
} 

int help(object me)
{ 
write(@HELP Ö¸Áî¸ñÊ½: Ö¸Áî¸ñÊ½£ºsrchcode  <directory> for <code>   
ÓÃÓÚÕÒ³öÖ¸¶¨Ä¿Â¼ÏÂº¬ÓĞÄ³¶ÎCODEµÄÄÇ¸öµµ°¸¡£ (¿ÉÒÔ´ø¿Õ¸ñ£¬Ôİ²»Ö§³Ö´ø"*")
[1;31mÇëÎğÓÃÓÚ²éÕÒº¬ÓĞºÜ¶àÏÂ¼¶Ä¿Â¼µÄÄ¿Â¼£¬Èç"/","/d",µÈ¡£[37;0m   
HELP ); 
return 1;
}  
