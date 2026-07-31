// By zjb@ty ÓÃÀ´×ªµµÓÃµÄÖ¸Áî
inherit F_CLEAN_UP; 
#define ZJB       "/u/zjb/"
int zjb(string file,string oldstr,string newstr);
int help(object me);
int main(object me, string arg)
{
string str, a, b, id, aa;

 if (me!=this_player(1))     return 0;
   seteuid( getuid(me) );
   a=wizhood(me);

   if(!arg || arg == "")  return help(me);

  if(sscanf(arg, "%s to %s", a, b) != 2 &&
     sscanf(arg, "%s %s", a, b) !=2)         return help(me);

   if( file_size(ZJB + "login/" + a[0..0] + "/" +a + __SAVE_EXTENSION__)<0 )
      return notify_fail("Ã»Õâ¸öIDµÄµµ¡£\n"); 

   if( file_size(DATA_DIR + "login/" + b[0..0] + "/" +b + __SAVE_EXTENSION__)>0 )
       return notify_fail("ÒÑ¾­ÓÐÕâ¸öIDµÄµµÁË£¬Ïë¸²¸ÇÇëÏÈÉ¾³ý¸ÃidµÄµµ¡£\n"); 

aa = ZJB + "login/" + a[0..0] + "/" + a + __SAVE_EXTENSION__;
id = DATA_DIR + "login/" + b[0..0] + "/" + b + __SAVE_EXTENSION__;

cp(aa,id); 
zjb(id,a,b); 
rm(aa);
write("" + aa + " ---> " + id + "   login...ok.rm"+aa+"  ok.\n");
  
aa = ZJB + "user/" + a[0..0] + "/" + a + __SAVE_EXTENSION__;
id = DATA_DIR + "user/" + b[0..0] + "/" + b + __SAVE_EXTENSION__;

cp(aa,id); 
zjb(id,a,b); 
rm(aa);
write("" + aa + " ---> " + id + " user...ok.rm"+aa+"  ok.\n");

return 1;
}


int zjb(string file,string oldstr,string newstr)
{
   string *text,*strings,line;
   int i,j;   
   
   j=0;
   if(file_size(file)<1) return 0;
   text=explode(read_file(file),"\n");
   rm(file);
   for(i=0;i<sizeof(text);i++)
   {
     if(strsrch(text[i],oldstr)==-1) {
          write_file(file,text[i]+"\n");
     }
     else {
          strings=explode(text[i],oldstr);
          line=implode(strings,newstr)+"\n";
          if(strsrch(text[i],oldstr)==0) line=newstr+line;
          write_file(file,line);
          j++;
     } 
   }
   write(file+",  "+oldstr+"µÄidÃû³É¹¦×ª»»³É"+newstr+"\n");
   return 1;
}

int help(object me)
{
  write(@TEXT 
HD ÃüÁî By Zjb@TY 2002/5/10
ÓÊ¼þ£ºwlzjb@163.com

½«MUDÀïµÄÒ»¸öIDµÄµµ¸´ÖÆµ½ÁíÒ»¸öIDµÄµµÉÏ£¬¶øÇÒ
Ö±½ÓÉ¾³ýµÚÒ»¸öIDµÄµµ
¸ñÊ½:HD <Ô­ID> <ÐÂID>û>
TEXT);
  return 1;
}


