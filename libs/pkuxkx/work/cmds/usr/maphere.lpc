#include <ansi.h>
inherit F_CLEAN_UP;

string *all_room_around(object proom,int num);
string map_short_format(string str);
int draw_all_map();
mixed *map;
string *tempmap=({});

int main(object me, string arg)
{
        
        object proom;
        string filename,rname,str;
        int i,j;
        
        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
        
        if(me->query("jing")<10)
                return notify_fail("你举目凝神打量周围的地势，却觉得一阵阵的头晕，看来真的吃不消了。\n");
        
        if(!wizardp(me))        me->start_busy(2);
        
        message_vision("$N停下来，环顾四周的地形地势。\n",me);
        me->receive_damage("jing",10);
        
        map=({});
        tempmap=({});
        
        map=allocate(9);
        
        proom=environment(me);
        
        map[4]=all_room_around(proom,4);
        
        for(i=0;i<9;i++)
        {
                if(i==4) continue;
                if(stringp(map[4][i]) 
                        && (objectp(proom=find_object(map[4][i]))
                                || objectp(proom=load_object(map[4][i]))))
                        map[i] = all_room_around(proom,i);
        }
        for(i=0;i<9;i++)
        {
                if(i==4) continue;
                map[4][i]=0;
        }
        
        draw_all_map();
        return 1;
}

string *all_room_around(object proom,int num)
{
        string *room_files,*ename,efile;
        int i;
        
        room_files=allocate(10);
        if(!proom || !objectp(proom) || !mapp(proom->query("exits")) || sizeof(proom->query("exits"))==0
                || !arrayp(ename=keys(proom->query("exits"))))
                return room_files;
        room_files[4]=file_name(proom);
        
        for(i=0;i<sizeof(ename);i++)
        {
                efile=proom->query("exits")[ename[i]];
                switch(ename[i])
                {
                        case "north":   room_files[1]=efile;
                                        break;
                        case "south":   room_files[7]=efile;
                                        break;
                        case "east":    room_files[5]=efile;
                                        break;
                        case "west":    room_files[3]=efile;
                                        break;
                        case "northeast":       room_files[2]=efile;
                                        break;
                        case "northwest":       room_files[0]=efile;
                                        break;
                        case "southeast":       room_files[8]=efile;
                                        break;
                        case "southwest":       room_files[6]=efile;
                                        break;
                        default:        room_files[9]="other";
                                        break;
                                                
                }
        }
        if(num!=4) room_files[8-num]=0;
        for(i=0;i<sizeof(room_files);i++)
        {
                if(i==4) continue;
                if(member_array(room_files[i],tempmap)==-1)
                        tempmap +=({room_files[i]});
                else room_files[i]=0;
        }
        return room_files;
}

int draw_all_map()
{
        string *mapstr,str,strall,rsh;
        string *cstr=({"＼","｜","／"," "," "," ","／","｜","＼"});
        int i,j;
        mapstr=allocate(17);
        str = "        ";
        strall="";
        for(i=0;i<17;i++)
        {
                mapstr[i]=sprintf("%80s\n",""); 
        }
        for(i=0;i<9;i++)
        {
                if(!arrayp(map[i]))
                                continue;
                for(j=0;j<3;j++)
                {
                        if(stringp(map[i][j]) && stringp(rsh=map[i][j]->query("short")))
                                mapstr[(i/3)*6][((i%3)*24+(j%3)*8)..((i%3)*24+(j%3)*8+7)]
                                        = map_short_format(rsh);        
                }
                for(j=3;j<6;j++)
                {
                        if(stringp(map[i][j]) && stringp(rsh=map[i][j]->query("short")))
                        {       
                                mapstr[(i/3)*6+2][((i%3)*24+(j%3)*8)..((i%3)*24+(j%3)*8+7)]
                                        = sprintf("%-8s",map_short_format(rsh));
                                
                        }
                        if(i!=4 && j==4)
                        {
                                for(int z=0;z<9;z++)
                                {
                                        if(z==3 || z==4 || z==5) continue;
                                        if(stringp(map[i][z]))
                                                mapstr[(i/3)*6+(z/3)+1][((i%3)*24+6+(z%3)*5)..((i%3)*24+6+(z%3)*5+2)]
                                                        = cstr[z];
                                                
                                }       
                        }
                        if(i==4 && j==4)
                        {
                                for(int z=0;z<9;z++)
                                {
                                        if(z==3 || z==4 || z==5) continue;
                                        if(arrayp(map[z]))
                                                switch(z)
                                                {
                                                        case 0:
                                                        case 6: mapstr[(i/3)*6+(z/3)+1][((i%3)*24+6+(z%3)*5-12)..((i%3)*24+6+(z%3)*5+2)]
                                                                        = cstr[z]+"-----------"+cstr[z];
                                                                break;
                                                        case 2:
                                                        case 8: mapstr[(i/3)*6+(z/3)+1][((i%3)*24+6+(z%3)*5)..((i%3)*24+6+(z%3)*5+14)]
                                                                        = cstr[z]+"-----------"+cstr[z];
                                                                break;
                                                        default:mapstr[(i/3)*6+(z/3)+1][((i%3)*24+6+(z%3)*5)..((i%3)*24+6+(z%3)*5+2)]
                                                                        = cstr[z];
                                                                break;
                                                                
                                                                
                                                }
                                                
                                }       
                        }
                }       
                for(j=6;j<9;j++)
                {
                        if(stringp(map[i][j]) && stringp(rsh=map[i][j]->query("short")))
                                mapstr[(i/3)*6+4][((i%3)*24+(j%3)*8)..((i%3)*24+(j%3)*8+7)]
                                        = sprintf("%-8s",map_short_format(rsh));  
                }               
        }
        for(i=0;i<17;i++)
        {
                if(i==8)
                {
                        strall +=mapstr[i][0..31]
                                +HIY+BLINK+mapstr[i][32..39]+NOR
                                +mapstr[i][40..80]+"\n";
                }
                else
                        if(mapstr[i]!=sprintf("%80s\n",""))
                                strall += mapstr[i];                    
        }
        write("\n"+strall+"\n"+NOR);
        return 1;
}

string map_short_format(string str)
{
        string strtemp="        ";
        int sl;
        if((sl=sizeof(str))>=8)
                strtemp = str[0..7];
        else    strtemp[((8-sl)/2)..((8-sl)/2+sl)] = str;
        return strtemp;
}

int help(object me)
{
write(@HELP
指令格式 : maphere
察看当前地点附近的地形地势?
HELP
);
return 1;
}
