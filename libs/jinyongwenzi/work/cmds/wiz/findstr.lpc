//Created by emnil 2000 03 03

inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
   string str,where,dir,fn,ff;
   string * line;
   mixed* files;
   int j,pp,f,i;
   string * wr=({"","","","","","","","","",""});
   int * pos=({0,0,0,0,0,0,0,0,0,0});

  
   
   
   

   if( !arg || sscanf(arg, "%s from %s", str, where)!=2 )
     return notify_fail ("指令格式: findtstr <string> from <path>(如:/d) \n");
   
   pp=0;
   f=0;
   while(1)
   {
        if(where!="/")
   	dir=where+"/";
        else
        dir=where;
	files=get_dir(dir,-1);
	for(j=f;j<sizeof(files);j++)
	{
		fn=dir+(string)files[j][0];
		if((int)files[j][1]==-2)
		{		 
			wr[pp]=where;
			pos[pp]=j+1;
			where=fn;
			f=0;
			pp=pp+1;
			break;
		}
		else
		{
			ff=read_file(fn);
			line = explode(ff, "\n");
			for(i=0;i<sizeof(line);i++)
			{
                if(strsrch(line[i],str,0)!=-1)
				{
					write(sprintf("发现%s在%s的第%d行。\n",str,fn,i+1));
				}
			}
		}
	}
	if(j>=sizeof(files))
   	{
		if(pp>0)
		{
			pp=pp-1;
			where=wr[pp];
			f=pos[pp];
		}
		else
			break;
   	}
   }	
        write("查找完毕。\n");
   return 1;
}

int help (object me)
{
        write(@HELP
        指令格式 : findstr str from path(如:/d/city)
 
可列出包含有str的所有文件的名字及str所在的行数。
 
HELP
);
        return 1;
} 

