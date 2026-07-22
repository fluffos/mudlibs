// look.c
// modified by xingyun 加入移动动态小地图

#include <room.h>
#include <ansi.h>
inherit F_CLEAN_UP;
#define TIME_TICK1 ((time()-900000000)*24)
string draw_map(string *dirs,mapping exits,object me);
string *all_exits = ({
    "east",
    "south",
    "west",
    "north",
    "eastup",
    "southup",
    "westup",
    "northup",
    "eastdown",
    "southdown",
    "westdown",
    "northdown",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "enter",
    "out",
});

string *look_level_boy = ({
 BLU "眉歪眼斜，瘌头癣脚，不象人样" NOR,
 BLU "呲牙咧嘴，黑如锅底，奇丑无比" NOR,
 BLU "面如桔皮，头肿如猪，让人不想再看第二眼" NOR,
 HIB "贼眉鼠眼，身高三尺，宛若猴状" NOR,
 HIB "肥头大耳，腹圆如鼓，手脚短粗，令人发笑" NOR,
 NOR "面颊凹陷，瘦骨伶仃，可怜可叹" NOR,
 NOR "傻头傻脑，痴痴憨憨，看来倒也老实" NOR,
 NOR "相貌平平，不会给人留下什么印象" NOR,
 YEL "膀大腰圆，满脸横肉，恶形恶相" NOR,
 YEL "腰圆背厚，面阔口方，骨格不凡" NOR,
 RED "眉目清秀，端正大方，一表人才" NOR,
 RED "双眼光华莹润，透出摄人心魄的光芒" NOR,
 HIY "举动如行云游水，独蕴风情，吸引所有异性目光" NOR,
 HIY "双目如星，眉梢传情，所见者无不为之心动" NOR,
 HIR "粉面朱唇，身姿俊俏，举止风流无限" NOR,
 HIR "丰神如玉，目似朗星，令人过目难忘" NOR,
 MAG "面如美玉，粉妆玉琢，俊美不凡" NOR,
 MAG "飘逸出尘，潇洒绝伦" NOR,
 MAG "丰神俊朗，长身玉立，宛如玉树临风" NOR,
 HIM "神清气爽，骨格清奇，宛若仙人" NOR,
 HIM "一派神人气度，仙风道骨，举止出尘" NOR,
});

string *look_level_girl = ({
  BLU "丑如无盐，状如夜叉" NOR,
  BLU "歪鼻斜眼，脸色灰败，直如鬼怪一般" NOR,
  BLU "八字眉，三角眼，鸡皮黄发，让人一见就想吐" NOR,
  HIB "眼小如豆，眉毛稀疏，手如猴爪，不成人样" NOR,
  HIB "一嘴大暴牙，让人一看就没好感" NOR,
  NOR "满脸疙瘩，皮色粗黑，丑陋不堪" NOR,
  NOR "干黄枯瘦，脸色腊黄，毫无女人味" NOR,
  YEL "身材瘦小，肌肤无光，两眼无神" NOR,
  YEL "虽不标致，倒也白净，有些动人之处" NOR,
  RED "肌肤微丰，雅淡温宛，清新可人" NOR,
  RED "鲜艳妍媚，肌肤莹透，引人遐思" NOR,
  HIR "娇小玲珑，宛如飞燕再世，楚楚动人" NOR,
  HIR "腮凝新荔，肌肤胜雪，目若秋水" NOR,
  HIW "粉嫩白至，如芍药笼烟，雾里看花" NOR,
  HIW "丰胸细腰，妖娆多姿，让人一看就心跳不已" NOR,
  MAG "娇若春花，媚如秋月，真的能沉鱼落雁" NOR,
  MAG "眉目如画，肌肤胜雪，真可谓闭月羞花" NOR,
  MAG "气质美如兰，才华馥比山，令人见之忘俗" NOR,
  HIM "灿若明霞，宝润如玉，恍如神妃仙子" NOR,
  HIM "美若天仙，不沾一丝烟尘" NOR,
  HIM "宛如"+HIW+"玉雕冰塑"+HIM+"，似梦似幻，已不再是凡间人物" NOR,
});
int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string cdir( string dir );
string cterrain( string terrain );
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
        {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

string clean_color(string arg)
{
        if(!arg)
                return "";
        arg = replace_string(arg, BLK, "");
        arg = replace_string(arg, RED, "");
        arg = replace_string(arg, GRN, "");
        arg = replace_string(arg, YEL, "");
        arg = replace_string(arg, BLU, "");
        arg = replace_string(arg, MAG, "");
        arg = replace_string(arg, CYN, "");
        arg = replace_string(arg, WHT, "");
        arg = replace_string(arg, HIR, "");
        arg = replace_string(arg, HIG, "");
        arg = replace_string(arg, HIY, "");
        arg = replace_string(arg, HIB, "");
        arg = replace_string(arg, HIM, "");
        arg = replace_string(arg, HIC, "");
        arg = replace_string(arg, HIW, "");
        arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BLINK,"");
        return arg;
}

int sort_exits(string str1,string str2)
{
    int i,j;
     if (strcmp(str1,"a")<0 && strcmp(str2,"a")<0){
         if (strlen(str1) < strlen(str2)) return -1;
         if (strlen(str1) == strlen(str2)) return strcmp(str1,str2);
         return 1;
     }else{
         i=member_array(str1, all_exits);
         j=member_array(str2, all_exits);
         if (i>0 && j>0) return i-j;
         else return strcmp(str1,str2);
     }
}

int look_room(object me, object env)
{
    int i,amount;
    object obj,room;
//        mixed *cmds;
    mapping exits,my;
    string str, *dirs,str2;
    if( !env ) {
        write("你的四周灰蒙蒙地一片，什麽也没有。\n");
        return 1;
    }


    if (!objectp(present("fire", me))
     && environment(me)->query("outdoors") 
     && NATURE_D->outdoor_room() && !wizardp(me) )
    {
     str = sprintf( HIC"%s"+NOR+HIC+"\n　　天太黑了，什么都看不清。\n"+NOR+"",
        env->query("short"));
     if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += "　　这里没有任何明显的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "　　这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else{
            dirs = sort_array(dirs,"sort_exits");
            str += sprintf("　　这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                              implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
      }else
            str += "　　这里没有任何明显的出路。\n";
        write(str);
        return 1;
    }
        if(env->query("outdoors",1))
                str2 = NOR+HIC"室外"NOR;
        if(!env->query("outdoors",1))
                str2 = NOR+HIC"室内"NOR;
    if (wizardp(me) && !me->query("env/show_room"))
    str = sprintf( HIC"〖"HIW"%s"HIC"〗　%s-"HIR"%s"
                 +NOR+" - "+RED+"%s\n"+NOR+"    %s",
        env->query("short"),str2,
        cterrain( (string)env->query("terrain") ),
        SECURITY_D->valid_read(file_name(env),me)? file_name(env): "",
        env->query("long"));
    else 
    str = sprintf(  HIC"〖"HIW"%s"HIC"〗  %s-"HIR"%s"+NOR+"\n    %s",
        env->query("short"),str2,cterrain( (string)env->query("terrain") ),
        env->query("long"));
    str+= env->query("outdoors")? NATURE_D->outdoor_room_description() : "";
    if( wizardp(me) && mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
             dirs[i] = 0;
        dirs -= ({ 0 });
        if( mapp(exits) ){
            str +="　　这里的出口有：\n";
            for (i=0;i<sizeof(dirs);i++){
                if (!room=find_object(exits[dirs[i]]))
                room=load_object(exits[dirs[i]]);
            if (room)   str+=sprintf(BOLD"　　%-12s"+NOR+YEL+" --> "+CYN+"%-10s"+RED+"%s.c\n"+NOR,cdir( dirs[i] ),room->query("short"),exits[dirs[i]]);
            else    str+=sprintf(BOLD"　　%-12s"+NOR+YEL+" --> "+RED+"没有正常出口。\n"+NOR,cdir( dirs[i] ));
            }}}else

    if( !wizardp(me) && mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
              dirs[i] = 0;
        dirs -= ({ 0 });
      if( mapp(exits) ){
            str +="　　这里的出口有：";
            for (i=0;i<sizeof(dirs);i++)
            str += HIW+dirs[i]+"  "NOR;
            str += "\n"NOR;
            str+=draw_map(dirs,exits,env);
       }}else

            str += "　　这里没有任何明显的出路。\n";

    i=0;
    foreach (obj in all_inventory(env)){
    if (!wizardp(me) && obj->query("no_show")) continue;
        if (!obj->is_character() && (i++)>99) continue;
        if (obj==me || !me->visible(obj) ){
            continue;
        }
        if (obj->query("money_id") 
            || !obj->query("unit")
            || obj->is_character()){
                if(!wizardp(me)){str+=sprintf("    %-12s\n",obj->short());}
                if(wizardp(me)){str+=sprintf("　　%-28s" + YEL":"NOR + RED"%s" + ".c"NOR+ "\n",obj->short(),base_name(obj));}
            continue;
        }
        if (!mapp(my))
            my=([obj->query("unit")+obj->short():1]);
        else{
            amount=my[obj->query("unit")+obj->short()];
            my[obj->query("unit")+obj->short()]=amount+1;
        }
    }
    if (mapp(my)){
        dirs=keys(my);
        for (i=0;i<sizeof(my);i++)
                str+=sprintf("　　%s%s\n",
my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),
my[dirs[i]]==1?dirs[i][2..]:dirs[i]);
    }
    write(str);
    return 1;
}


string draw_map(string *dirs,mapping exits,object env)
{
      string str="";
      object room;
      string dir1="",dir2="",dir3="",dir4="",
                  dir5="",dir6="",dir7="",dir8="";
      string sign1="",sign2="",sign3="",sign4="",
                  sign5="",sign6="",sign7="",sign8=""; 

      if( member_array("northwest",dirs)!=-1 )
      {
       if (!room=find_object(exits["northwest"]))
                   room=load_object(exits["northwest"]);
       if (room)
                   dir1=clean_color(room->query("short"));
              else
                   dir1=RED"没有正常出口。"NOR;

       sign1=HIW"\\"NOR;
      }
      if( member_array("up",dirs)!=-1 )
      {
       if (!room=find_object(exits["up"]))
                   room=load_object(exits["up"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northup",dirs)!=-1 )
      {
       if (!room=find_object(exits["northup"]))
                   room=load_object(exits["northup"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["northdown"]))
                   room=load_object(exits["northdown"]);
       if (room)
                   dir2=clean_color(room->query("short"));
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }                   
      if( member_array("north",dirs)!=-1 )
      {
       if (!room=find_object(exits["north"]))
                   room=load_object(exits["north"]);
       if (room)
                   dir2=clean_color(room->query("short"));                  
              else
                   dir2=RED"没有正常出口。"NOR;

       sign2=HIW"|"NOR;
      }
      if( member_array("northeast",dirs)!=-1 )
      {
       if (!room=find_object(exits["northeast"]))
                   room=load_object(exits["northeast"]);
       if (room)
                   dir3=clean_color(room->query("short"));
              else
                   dir3=RED"没有正常出口。"NOR;

       sign3=HIW"/"NOR;
      }
      if( member_array("out",dirs)!=-1 )
      {
       if (!room=find_object(exits["out"]))
                   room=load_object(exits["out"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;       
      }
      if( member_array("westup",dirs)!=-1 )
      {
       if (!room=find_object(exits["westup"]))
                   room=load_object(exits["westup"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("westdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["westdown"]))
                   room=load_object(exits["westdown"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("west",dirs)!=-1 )
      {
       if (!room=find_object(exits["west"]))
                   room=load_object(exits["west"]);
       if (room)
                   dir4=clean_color(room->query("short"));
              else
                   dir4=RED"没有正常出口。"NOR;

       sign4=HIW"—"NOR;
      }
      if( member_array("enter",dirs)!=-1 )
      {
       if (!room=find_object(exits["enter"]))
                   room=load_object(exits["enter"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("eastup",dirs)!=-1 )
      {
       if (!room=find_object(exits["eastup"]))
                   room=load_object(exits["eastup"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("eastdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["eastdown"]))
                   room=load_object(exits["eastdown"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }                   
      if( member_array("east",dirs)!=-1 )
      {
       if (!room=find_object(exits["east"]))
                   room=load_object(exits["east"]);
       if (room)
                   dir5=clean_color(room->query("short"));
              else
                   dir5=RED"没有正常出口。"NOR;

       sign5=HIW"—"NOR;
      }
      if( member_array("southwest",dirs)!=-1 )
      {
       if (!room=find_object(exits["southwest"]))
                   room=load_object(exits["southwest"]);
       if (room)
                   dir6=clean_color(room->query("short"));
              else
                   dir6=RED"没有正常出口。"NOR;

       sign6=HIW"/"NOR;
      }
      if( member_array("down",dirs)!=-1 )
      {
       if (!room=find_object(exits["down"]))
                   room=load_object(exits["down"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      } 
      if( member_array("southup",dirs)!=-1 )
      {
       if (!room=find_object(exits["southup"]))
                   room=load_object(exits["southup"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("southdown",dirs)!=-1 )
      {
       if (!room=find_object(exits["southdown"]))
                   room=load_object(exits["southdown"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("south",dirs)!=-1 )
      {
       if (!room=find_object(exits["south"]))
                   room=load_object(exits["south"]);
       if (room)
                   dir7=clean_color(room->query("short"));
              else
                   dir7=RED"没有正常出口。"NOR;

       sign7=HIW"|"NOR;
      }
      if( member_array("southeast",dirs)!=-1 )
      {
       if (!room=find_object(exits["southeast"]))
                   room=load_object(exits["southeast"]);
       if (room)
                   dir8=clean_color(room->query("short"));
              else
                   dir8=RED"没有正常出口。"NOR;

       sign8=HIW"\\"NOR;
      }


     str = sprintf("        %s"HIG"%-12s"NOR, str, dir1);
     str = sprintf("%s   "HIG"%-12s"NOR, str, dir2);
     str = sprintf("%s   "HIG"%-12s\n"NOR, str, dir3);
     str = sprintf("%s                   %-2s", str, sign1);
     str = sprintf("%s     %-2s", str, sign2);
     str = sprintf("%s       %-2s\n", str, sign3);
     str = sprintf("%s        "HIG"%-12s"NOR, str, dir4);
     str = sprintf("%s%-2s", str, sign4);
     str = sprintf("%s "HIR"%-12s"NOR, str,env->query("short")); 
     str = sprintf("%s%-2s", str,sign5);
     str = sprintf("%s  "HIG"%-12s\n"NOR, str,dir5);
     str = sprintf("%s                   %-2s", str, sign6);
     str = sprintf("%s     %-2s", str, sign7);
     str = sprintf("%s       %-2s\n", str, sign8);
     str = sprintf("%s        "HIG"%-12s"NOR, str, dir6);
     str = sprintf("%s   "HIG"%-12s"NOR, str, dir7);
     str = sprintf("%s   "HIG"%-12s\n"NOR, str, dir8);

     return str;
}

int look_item(object me, object obj)
{
    mixed *inv;
    if (!me->visible(obj))
    { write("你要看什么？\n"); return 1; }

    me->start_more(obj->short() + HIW"："NOR + obj->long());
    inv=all_inventory(obj);
    if( sizeof(inv) ) {
    inv = map_array(inv, "inventory_look", this_object() );  
    message("vision", sprintf("里面有：\n  %s\n",
            implode(inv, "\n  ") ), me);
    }
    return 1;
}
int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}
int look_living(object me, object obj)
{
    int per_temp,i,j;
    string str, pro,*skills_name;
    mixed *inv;
    mapping my_fam, fam,skills;
    if( me!=obj )
        message("vision", me->name() + "正盯著你看，不知道打些什麽主意。\n", obj);
    if (!objectp(present("fire", me))  && environment(me)->query("outdoors") && NATURE_D->outdoor_room() && !wizardp(me) ){
    str = sprintf( HIC"\n    你看到前面似乎有个人影，可天太黑了，看不清。\n"NOR);
        write(str);
        return 1;
    }
    str = obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
    if( (string)obj->query("race")=="人类"
    &&  intp(obj->query("age")) )
        str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));
    per_temp= (obj->query_per()>=30)?20:(obj->query_per()-10);
    if (per_temp<0) per_temp=0;
    if ( (string)obj->query("race")=="人类" ) {
    if ( (string)obj->query("gender") == "女性")
        str += sprintf("%s长的%s。\n", pro, look_level_girl[per_temp]);
    else
        str += sprintf("%s长的%s。\n", pro, look_level_boy[per_temp]);
    skills=obj->query_skills();
    if (!sizeof(skills))
        str+=sprintf("%s看起来似乎不会任何武功。\n", pro);
    else{
        skills_name=sort_array( keys(skills), (: strcmp :) );
        i=random(sizeof(skills_name));
                if (SKILL_D(skills_name[i])->type()=="knowledge")
            str+=sprintf("%s看起来似乎不会任何武功。\n", pro);
        else
              str+=sprintf("%s的武功看起来似乎%s。\n", pro,"/cmds/skill/skills"->skill_level(SKILL_D(skills_name[i])->type(), skills[skills_name[i]]));
    }
    }
    // If we both has family, check if we have any relations.
    if( obj!=me
    &&  mapp(fam = obj->query("family"))
    &&  mapp(my_fam = me->query("family")) 
    &&  fam["family_name"] == my_fam["family_name"] ) {
    
        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "男性" )
                str += sprintf( pro + "是你的%s%s。\n",
                    my_fam["master_id"] == fam["master_id"] ? "": "同门",
                    my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
            else
                str += sprintf( pro + "是你的%s%s。\n",
                    my_fam["master_id"] == fam["master_id"] ? "": "同门",
                    my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
        } else if( fam["generation"] < my_fam["generation"] ) {
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "是你的师父。\n";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "是你的同门长辈。\n";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "是你的师伯。\n";
            else
                str += pro + "是你的师叔。\n";
        } else {
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "是你的同门晚辈。\n";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "是你的弟子。\n";
            else
                str += pro + "是你的师侄。\n";
        }
    }
    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";
    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s的遗体上有:\n%s\n" : "%s%s\n",
                            pro, implode(inv, "\n") );
        if (!obj->query_temp("armor/cloth") && obj->query("race")=="人类" )
            str+=pro+"光着"+YEL+"身子"+NOR+"，什么也没穿！\n";
    }   else    str += sprintf( obj->is_corpse() ? "%s的遗体上什么也没有。\n" : (obj->query("race")=="人类"?"%s光着"+YEL+"身子"+NOR+"，什么也没穿！\n":"它的身上没有任何东西。\n"),pro);
    if (strlen(str)>8192)
    me->start_more(str);
    else     message("vision", str, me);
    if( obj!=me && living(obj)){
        i=obj->query("shen");
        j=me->query("shen");
        if ((i<-1000 && j>1000 ) || (i>1000 && j<-1000 ) ){
            write( obj->name() + "突然转过头来瞪你一眼。\n");
            COMBAT_D->auto_fight(obj, me, "berserk");
        }
    }
    return 1;
}

string inventory_look(object obj, int flag)
{
    string str;
     if( !flag )
          return "      "+obj->short();
    if( obj->query("equipped") ){
            switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":   str = "身穿";break; break;
                case "boots":   str = "脚穿";break; break;
                case "head":    str = "头戴";break;
                case "neck":    str = "颈围";break;
                case "finger":  str = "手指上戴着";break;
                case "hands":   str = "手上拿着";break;
                case "waist":   str = "腰间绑着";break;
}
}
}
string cdir( string dir )
{
        switch( dir ) {
                case "east":
                        return "东方(e)";
                case "west":
                        return "西方(w)";
                case "south":
                        return "南方(s)";
                case "north":
                        return "北方(n)";
                case "up":
                        return "上方(u)";
                case "down":
                        return "下方(d)";
                case "northeast":
                        return "东北方(ne)";
                case "southeast":
                        return "东南方(se)";        
                case "southwest":
                        return "西南方(sw)";        
                case "northwest":
                        return "西北方(nw)";
                case "eastup":
                        return "东上方(eu)";        
                case "eastdown":
                        return "东下方(ed)";        
                case "westup":
                        return "西上方(wu)";        
                case "westdown":
                        return "西下方(wd)";                
                case "southup":
                        return "南上方(su)";
                case "southdown":
                        return "南下方(sd)";        
                case "northup":
                        return "北上方(nu)";
                case "northdown":
                        return "北下方(nd)";        
                case "out":
                        return "出口(out)";        
                case "enter":
                        return "进口(ENTER)";                        
                default:
                        return dir;
        }
}
string cterrain( string terrain )
{
        switch( terrain ) {
                case "plain":
                        return "平地";
                case "hill":
                        return "丘陵";
                   case "shop":
                         return "商店";
                case "mountain":
                        return "山岳";
                case "river":
                        return "河川";
                case "ocean":
                        return "海洋";
                case "atmosphere":
                        return "大气圈";
                case "space":
                        return "宇宙空间";
                default:
                        return "平地";
        }
}
int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
参考: vl, sl
HELP
);
        return 1;
}
