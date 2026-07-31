
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me); 
string *deep_file_list(string dir, string opt);

int main(object me, string arg)
{
        string file, opt;
        string sname;
        mixed *dir;
        int i, total;

     //   if (! SECURITY_D->valid_grant(me, "(admin)"))
    //            return 0; 

        seteuid(geteuid(this_player(1)));

        if (! arg || (arg != "all" && arg != "pfm" && arg != "skl")) 
                return help(me); 
        
        opt = arg;  
        total = 0;     
        
        dir = deep_file_list("/kungfu/skill/", opt);
        for(i = 0; i < sizeof(dir); i++)
        {
                reset_eval_cost();
                if (file_size(dir[i]) > 0)
                {
                        file = read_file(dir[i]);
                        if (opt == "pfm" || opt == "all")
                        {                               
                               //write(file_size(dir[i]) +" 。\n");
                                if (file[0..57] == "// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
                                {
                                        //rm(dir[i]);
                                        total++;
                                        write(dir[i] +" 被删除。\n");
                                        continue;
                                }
                        }
                        
                        if (opt == "skl" || opt == "all")
                        {
                                
                                //write(file_size(dir[i]) +" 。\n");
                                if (file[0..57] == "// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
                                {
                                        /*
                                        if (sscanf(dir[i], "/kungfu/skill/%s.c", sname))
                                                SKILLS_D->remove_skill_from_skills(me, sname); 
                                        */
                                        rm(dir[i]);
                                        total++;
                                        write(dir[i] +" 被删除。\n");
                                        continue;
                                }
                        }
                        
                }
        }
        
        write("\n技能目录中所有自创文件共 " + total + " 个被删除。\n");
        return 1;               
}

string *deep_file_list(string dir, string opt)
{
        int i;
        string *flist, *result = ({ }), file;
        
        flist = get_dir(dir);

        for (i = 0; i < sizeof(flist); i++)
        {
                file = dir + flist[i];
                
                if (opt == "skl")
                {
                        if (file_size(file) > 0)
                                result += ({ file });
                } else
                if (opt == "pfm")
                {                       
                        if (file_size(file + "/") == -2)
                                result += deep_file_list(file + "/", opt);
                        else 
                        if (dir != "/kungfu/skill/")
                                result += ({ file });
                } else
                if (opt == "all")
                {
                        if (file_size(file + "/") == -2)
                                result += deep_file_list(file + "/", opt);
                        else
                                result += ({ file });
                }                         
        }
        return result;
}

int help(object me) 
{ 
write(@HELP

指令格式: clearinvent [pfm] | [skl] | [all]
本指令可让你把自创武功或自创绝招文件全部删除。
注意：本命令比较危险，请小心使用。

HELP);
return 1;
}
