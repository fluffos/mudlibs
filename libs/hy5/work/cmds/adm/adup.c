// last modified by xiha@sdxl.2000

#include "/doc/help.h"

inherit F_CLEAN_UP;

int updatefile(object me,string file);

int main(object me, string arg)
{

	int i, j;
	string dir;
	mixed *file;
	seteuid( geteuid(me) );

	dir = resolve_path(me->query("cwd"), arg);
 
        return notify_fail("Õâ¸öÃüÁîÄ¿Ç°²»¿ª·Å¡£\n");
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += 
"/";
		file = get_dir(dir, -1);
	if( !sizeof(file) ) {
		if (file_size(dir) == -2) return 
notify_fail("Ä¿Â¼ÊÇ¿ÕµÄ¡£\n");
	else
		return notify_fail("Ã»ÓĞÕâ¸öÄ¿Â¼¡£\n");
	}

	i = sizeof(file);

	while(i--) {
	if (file[i][1]==-2) file[i][0] += "/";

	}
	write("Ä¿Â¼£º" + dir + "\n");

	reset_eval_cost();
	if (sizeof(file))
	for(i=0, j = sizeof(file); i<j; i++) {
		  if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")
			 && file[i][0][strlen(file[i][0])-1]=="c"[0]
			 && file[i][0][strlen(file[i][0])-2]=="."[0])
		  updatefile(me,dir+file[i][0]);
		  else if (file[i][1]==-2) call_other(__FILE__,"main", 
me,dir+file[i][0]);
		}
	else write("Ã»ÓĞÈÎºÎµµ°¸¡£\n");
	reset_eval_cost();
	write("\n");

	return 1;
}



int updatefile(object me,string file)
{
	object obj,*inv;
	int i;
	string err,file1;
	me->set("cwf", file);

	reset_eval_cost();
	if (obj = find_object(file)) {
		if( obj==environment(me) ) {
			if( file_name(obj)==VOID_OB )
		return notify_fail("Äã²»ÄÜÔÚ VOID_OB 
ÀïÖØĞÂ±àÒë VOID_OB¡£\n");
	inv = all_inventory(obj);
	i = sizeof(inv);
	while(i--)
	if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
		else inv[i] = 0;
	}
	destruct(obj);
}
	if (obj)
		return 
notify_fail("ÎŞ·¨Çå³ı¾É³ÌÊ½Âë¡£\n");

	write("ÖØĞÂ±àÒë " + file + "£º");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "·¢Éú´íÎó£º\n%s\n", err );
	else {
		write("³É¹¦£¡\n");
// file1¼ÇÒäÎÄ¼şÃû£¬½«Ô´ÎÄ¼şÉ¾³ı
             file1 = file;
		rm(file);
		write_file(file1,"¿´²»¶®¾Í²»Òª¿´");
if( (i=sizeof(inv)) && (obj = find_object(file))) {
		while(i--)
			if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
}

int help(object me)
{
write(@HELP
Ö¸Áî¸ñÊ½: adup [<Â·¾¶Ãû>]

½«Ä¿Â¼ÏÂËùÓĞµÄ×ÓÄ¿Â¼¼°µµ°
¸, Èç¹ûÃ»ÓĞÖ¸¶¨Ä¿Â¼, 
ÔòÊ¹ÓÃµ±Ç°Ä¿Â¼


·¶Àı:
adup /adm 
»á½«ËùÓĞÎ»ì¶¸ù/admÄ¿Â¼ÏÂµÄµ
µ°¸±àÒë¸üĞÂ.

HELP
);
return 1;
}
