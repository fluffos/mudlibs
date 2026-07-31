//stey

#pragma save_binary
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
int ttimes=0;
mapping weapon_s=([]);


void create()
{
        seteuid(getuid());
        if( !restore() )
        {
                weapon_s=([]);

        }
        else
        {
                if( !mapp(weapon_s) ) weapon_s = ([]);

        }
        set_heart_beat(10);
        ttimes=0;

}
string query_save_file()
{
        return DATA_DIR+"weapon_saved";

}
void set_save_file(object me,object weapon,string w_num)
{
    int i,k,j;
    string save_file,id;
    id=me->query("id");
    weapon->set("owner_id",id);
    weapon->set("save_id",(id+w_num));
     save_file=sprintf(DATA_DIR"sweapon/%c/%s%s",id[0],id,w_num);
    weapon->set("weapon_file",save_file);

}
void record_weapon(object me,object weapon,string w_num)
{
    int i,j,k;
    string wp_file,id,ids,name;

    mapping swf;



    id=me->query("id");
    if(undefinedp(weapon_s[id]))
    {swf=([]);}
    else swf=weapon_s[id];
    wp_file=base_name(weapon);
    name=weapon->name();

    ids=weapon->query("id");

    swf[w_num]=(["file":wp_file,"obj":file_name(weapon),"name":name,"id":ids,]);
    weapon_s[id]=swf;
    
    set_save_file(me,weapon,w_num);
    weapon->weapon_save();

}

void set_settings(object weapon,string id,string w_num)
{
      int i;
      string *kk,wp_fileids,name,save_file;
     

      

      weapon_s[id][w_num]["obj"]=file_name(weapon);

      save_file=sprintf(DATA_DIR"sweapon/%c/%s%s",id[0],id,w_num);
      weapon->set("weapon_file",save_file);
      weapon->weapon_restore();
}


int check_weapon(string id,string w_num)
{
     if( find_object(weapon_s[id][w_num]["obj"]))
      return 1;
      else return -1;
}
object get_weapon(string id,string w_num)
{
      int i,k,j;
     string save_file;
      object weapon;
      if( weapon=find_object(weapon_s[id][w_num]["obj"]))
       return weapon;

        weapon =new(weapon_s[id][w_num]["file"]);

        weapon->set("owner_id",id);
        weapon->set("save_id",(id+w_num));

        save_file=sprintf(DATA_DIR"sweapon/%c/%s%s",id[0],id,w_num);
        weapon->set("weapon_file",save_file);
        weapon->weapon_restore();
        weapon_s[id][w_num]["obj"]=file_name(weapon);
        return weapon;

}


mapping query_my_weapon(string id)
{
      return weapon_s[id];
}

void get_all_weapon_save()
{
       int i,k;
       string *ff,*ww;
       object weapon;
       if ((ttimes %2)!=1) return;
       ff=keys(weapon_s);
       for(i=0;i<sizeof(ff);i++)
       {
          ww=keys(weapon_s[ff[i]]);
         for(k=0;k<sizeof(ww);k++)
          {

           if( weapon=find_object( weapon_s[ff[i]][ww[k]]["obj"]) )
             weapon->weapon_save();
           }
        }


}


private void heart_beat()
{

  ttimes ++;
  get_all_weapon_save();
  save();
}
