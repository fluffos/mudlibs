//Write By Leeyao
#include <ansi.h>
inherit F_CLEAN_UP;
string fill_blank(string type, int num)
{
        string bak;
        int i, j;

        bak="";
        i=strlen(type);
        for (j=0; j<num-i; j++ )
                bak+=" ";
        return bak;
}
string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD });
                        
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}

string inventory_weapon(object ob)
{
        string name;
        name = ob->query("name");
        if (ob->query("equipped"))
                     name=RED+name+NOR;
                    else
                        name = ob->query("name");
        if( mapp(ob->query("weapon_prop")))
        return sprintf("%s%s"NOR,
                name,
                fill_blank(remove_ansi(name), 8)
                );
}
string inventory_armor(object ob)
{
        string name;
        name = ob->query("name");
        if (ob->query("equipped"))
                     name=RED+name+NOR;
                    else
                        name = ob->query("name");
        if( !mapp(ob->query("weapon_prop")) && mapp(ob->query("armor_prop")) ){
        return sprintf("%s%s"NOR,
                name,
                fill_blank(remove_ansi(name), 8)
                );
        }
}

string inventory_money(object *ob)
{
        string name;
        name = ob->query("name");
        if( !mapp(ob->query("weapon_prop")) && !mapp(ob->query("armor_prop")) && ob->query("money_id"))
        return sprintf("%s%s%d"NOR,
                name,
                fill_blank(remove_ansi(name), 8),
                ob->query_amount()?ob->query_amount():1
                );
}
string inventory_item(object ob)
{
        string name;
        name = ob->query("name");
        if( !mapp(ob->query("weapon_prop")) && !mapp(ob->query("armor_prop")) && !ob->query("money_id"))
        return sprintf("%s%s"NOR,
                name,
                fill_blank(remove_ansi(name), 8)
                );
}

int main(object me,string arg,object env)
{
        int i, j, k, ii;
        string dir,str,file2;
        mixed *file,*inv;
        object ob;
        if(!arg) 
        return notify_fail("指令格式 : checknpc 目录\n");
        sscanf(arg, "%s", arg);
        dir = resolve_path(arg);
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ){
        if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
        else
                return notify_fail("没有任何目录。\n");
        }
        i = sizeof(file);
        while(i--) {
        if (file[i][1]==-2) file[i][0] += "/   ";
                }
        str="";
        if (sizeof(file) ){
        for(i=0, j = sizeof(file),k=0; i<j; i++,k++){
                if (! (int)SECURITY_D->valid_read(dir + file[i][0],me) ) { k--;continue; }
                if (file[i][1]==-2) { k--;continue; }
        file2 = resolve_path(file[i][0]);
        ii = sizeof(file[i][0]);
        // ob = new(arg+"/"+file2[0..ii-3]+".c");
        ob = new(arg+"/"+file2[0..i-3]+".c");
        if(!ob->is_character())continue;
        inv = all_inventory(ob);
        str += sprintf("%s%-8s|%-18s|%5d|%8s|"NOR,
                ((i)%2)?CYN"":YEL"",
                ob->query("name"),
                ob->query("id"),
                ob->query("level"),
                ob->query("family/family_name"),
                        );      
        if( sizeof(inv)) {
        inv -= ({ 0 });}
        str += sprintf("%8s",
                implode(map_array(inv, "inventory_weapon", this_object()),""));
        str += sprintf("%8s",
                implode(map_array(inv, "inventory_armor", this_object()),""));
        str += sprintf("%8s",
                implode(map_array(inv, "inventory_money", this_object()),""));
        str += sprintf("%8s\n",
                implode(map_array(inv, "inventory_item", this_object()),""));
        destruct(ob);
        }
        if (!k)  write("没有符合条件的文件或目录。\n");
                else    
        write("目录：" + dir + "\n");
        me->start_more(str);
        } else write("    没有任何档案。\n");    
        return 1;   
}

int help(object me)
{
    write(@HELP
这指令是用来查看某一npc目录的npc的设置，巫师专用。
指令格式（例如）：checknpc /d/ly/npc
HELP
    );
    return 1;
}
