// museum_d.c this daemon will handle the data structure of museum
// By fire@sgz, June 2000
#include <mudlib.h>
#include <security.h>

#define MAXWIDTH 15
#define MAXHEIGHT 8
#define ENTRYROOM "7_7_0"

#define C_BLOCK 0   // default is block
#define C_DOOR 1
#define C_OPEN 2

#define SAVE_FILE "/data/daemons/museum"
#define HEADBAR "   Ａ   Ｂ   Ｃ   Ｄ   Ｅ   Ｆ   Ｇ   Ｈ   Ｉ   Ｊ   Ｋ  Ｌ   Ｍ   Ｎ   Ｏ"
inherit M_ACCESS;

private mapping rooms;
private mapping npcs;

int room_exist(int x,int y,int f);
// Npc part //////////////////////////////////////////////////////
void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE, 1 :));
        return;
}

private mixed trans_to_active_npc(string id) {
        mixed old_data;
		string m_id=id+" npc";
        old_data=get_char(id,"");
		CHAR_D->add_char(m_id);
        foreach(string par,mixed val in old_data) {
                if(par[0..5]=="museum") continue;
				
                CHAR_D->set_char(m_id,par,val);
        }
		CHAR_D->set_char(m_id,"museum_npc",1);
		CHAR_D->set_char(m_id,"birth_time",time());
        CHANNEL_D->deliver_tell("rumor","system",
 CHAR_D->get_char(m_id,"name")+
"雄心再起，决心以ＮＰＣ身份重返官场效命。");
        return 1;
}


mixed active_npc(string p_id) {
	if(!mapp(npcs[p_id])) return p_id+ " is not a npc yet\n";
	if(CHAR_D->char_exist(p_id+ " npc")) return p_id + "is active now\n";
	if((this_object()->get_char("active_npc")>16)) return "Too many active npc now\n";
	return trans_to_active_npc(p_id);
}
mixed auto_active_npc() {
	string *list=this_object()->get_char("list");
	if(sizeof(list)) {
		return active_npc(list[random(sizeof(list))]);
	}
}
mixed get_char(string p_id,string para_name)
{
	switch(p_id) {
	case "active_npc":
		return sizeof(CHAR_D->check_char("museum_npc",1));
	case "list":
		return keys(npcs);
	case "all":
		return npcs;
	}
    
	if (!mapp(npcs[p_id]))   return 0;
    if((!para_name)||(para_name=="")) para_name="all";
    switch(para_name)
    { 
      case "list" : return keys(npcs[p_id]);
      case "all": return npcs[p_id];		
      default : return npcs[p_id][para_name];      
    }
}
mixed trans_to_museum(string id) {
        mixed old_data;
        mixed new_data;
        mixed * exp_array=({"lc","nc","ps","ranklocal","hon","lo",
                "myarmy","status","h","type","ranknation","nation"});
        if(!CHAR_D->char_exist(id))
                return "don't have char of "+id+".\n";
        if(CHAR_D->get_char(id,"type")!=TYPE_PLAYER)
                return id+" is a npc now, hoho.\n";
        if(CHAR_D->get_char(id,"ranknation")==R_KING)
                return "king can't be npc now\n";
        if(CHAR_D->get_char(id,"task"))
                return id+" now is busying for some task, wait when he finish\n";

        old_data=CHAR_D->get_char(id);
        new_data=([]);
        foreach(string par,mixed val in old_data) {
                if(member_array(par,exp_array)!=-1) continue;
                if(par[0..4]=="catch") continue;
                new_data[par]=val;
        }
        npcs[id]=new_data;
        save_data();
        CHANNEL_D->deliver_tell("rumor","system",
 CHAR_D->get_char(id,"name")+
"厌倦官场争斗，决定归隐山林，但因劳苦功高，其事迹将载入"+mud_name()+
"典藏馆。");
        CHAR_D->remove_char(id);
        return 1;
}

mixed trans_back(string id) {
        mixed old_data;
        mixed new_data;

        if(!mapp(npcs[id])) return id + " is not in the museum.";
		if(CHAR_D->char_exist(id+" npc")) return id + " is an active npc char now\n";
        old_data=get_char(id,"");
        new_data=([]);
        foreach(string par,mixed val in old_data) {
                if(par[0..5]=="museum") continue;
                new_data[par]=val;
        }
        map_delete(npcs,id);
        save_data();
        CHAR_D->new_player_back_char(id,new_data);
        CHANNEL_D->deliver_tell("rumor","system",
 CHAR_D->get_char(id,"name")+
"不甘心于"+mud_name()+"典藏馆中的寂寞生活，决定重返江湖。");
        return 1;


}
int char_exist(string id) {
        return mapp(npcs[id]);
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        if( !rooms || !mapp(rooms) ) rooms = ([ ]);
        if( !npcs || !mapp(npcs) ) npcs = ([ ]);
        return;
}

string get_string_index(int x,int y, int f) {
        return x+"_"+y+"_"+f;
}
int *get_num_index(string id) {
        string *ids;
        ids=explode(id,"_");
        if(sizeof(ids)!=3) return ({-1,-1,-1});
        return ({to_int(ids[0]),to_int(ids[1]),to_int(ids[2])});

}
mixed set_room_num(int x,int y,int f,string par,mixed val) {
        string id;
        if(!room_exist(x,y,f)) return "No such room in the museum\n";
        id=get_string_index(x,y,f);
        if(!mapp(rooms[id])) rooms[id]=([]);
        if(par=="e") return set_room_num(x+1,y,f,"w",val);
        if(par=="s") return set_room_num(x,y+1,f,"n",val);

        if(val==0) {
                map_delete(rooms[id],par);
                save_data();
                return "ok";
        }
        rooms[id][par]=val;
        save_data();
        return "ok";

}

mixed set_room(string id,string par,mixed val) {
        int *ids=get_num_index(id);
        return set_room_num(ids[0],ids[1],ids[2],par,val);
}

mixed get_room_num(int x,int y,int f,string par) {
        string id;
        if(!room_exist(x,y,f)) return "No such room in the museum\n";
        id=get_string_index(x,y,f);
        if((!par)||(par==""))
                return rooms[id];
        if(par=="e") return get_room_num(x+1,y,f,"w");
        if(par=="s") return get_room_num(x,y+1,f,"n");
        return rooms[id][par];

}
mixed get_room(string id,string par) {
        int *ids=get_num_index(id);
        if((!id)||(id=="")) return rooms;
        return get_room_num(ids[0],ids[1],ids[2],par);
}
int get_connect_type (int x,int y,int f,string d) {
        string p_id=get_string_index(x,y,f);

        if(y<0) return C_OPEN;

        if(x>=MAXWIDTH) {
                if(y>=MAXHEIGHT) return C_OPEN;
                if(d=="w") return C_BLOCK;
                if(d=="n") return C_OPEN;
        }

        if(y>=MAXHEIGHT) {
                if(d=="w") return C_OPEN;
                if(d=="n") return C_BLOCK;
        }
        if(!mapp(rooms[p_id])) rooms[p_id]=([]);

        switch(d) {
        case "e":
                return get_connect_type(x+1,y,f,"w");
        case "n":
                return rooms[p_id]["n"];
        case "w":
                return rooms[p_id]["w"];
        case "s":
                return get_connect_type(x,y+1,f,"n");
        }
}

string show_room_wall1(int x,int y,int f) {
        int c1=get_connect_type(x,y-1,f,"w");
        int c2=get_connect_type(x,y,f,"n");
        string ret;
        ret="|";
        if(c1==C_OPEN)
                ret=" ";
        if(c2==C_BLOCK)
                return ret+"____";
        if(c2==C_OPEN)
                return ret+"    ";
        return ret+"_  _";

}
string show_room_wall3a(int x,int y,int f,int m_x,int m_y) {
        string ext;
        int c=get_connect_type(x,y,f,"w");
        ext=get_room_num(x,y,f,"l2");
        if(!stringp(ext)||(sizeof(ext)>4))
                ext="    ";

        if((x==m_x)&&(y==m_y)) ext=" %^H_RED%^●%^RESET%^ ";
        if(c==C_BLOCK) return "|"+ext;
        return " "+ext;

}

string show_room_wall2(int x,int y,int f) {
        string ext;
        int c=get_connect_type(x,y,f,"w");
        ext=get_room_num(x,y,f,"l1");
        if(!stringp(ext)||(sizeof(ext)>4))
                ext="    ";
        if(c==C_OPEN) return " "+ext;
        return "|"+ext;

}
string show_room_wall3(int x,int y,int f) {
        string ext="    ";
        int c=get_connect_type(x,y,f,"w");
        ext=get_room_num(x,y,f,"l2");
        if(!stringp(ext)||(sizeof(ext)>4))
                ext="    ";
        if(c==C_BLOCK) return "|"+ext; // need show line1 name, add later
        return " "+ext;

}
string show_mapa(int f,int x,int y) {
        string ret="";
        string w1,w2,w3;
        int i,j;
        for(i=0;i<=MAXHEIGHT;++i) {
                w1=" ";
                w2=" ";
                w3=(i+1)+"";
                if(i==MAXHEIGHT)
                        w3=" ";
                for(j=0;j<=MAXWIDTH;++j) {
                        w1+=show_room_wall1(j,i,f);
                        w2+=show_room_wall2(j,i,f);
                        w3+=show_room_wall3a(j,i,f,x,y);
                }
                if(i==MAXHEIGHT)
                        w2=HEADBAR;
                ret+=w1+"\n"+w2+"\n"+w3+"\n";
        }
        return ret;

}
string show_map(int f) {
        string ret="";
        string head;
        string w1,w2,w3;
        int i,j;
        object o=this_body();

        head=mud_name()+"典藏馆第"+chinese_number(f+1)+"层平面图\n";

        if(objectp(o)&&(o->query_room()->is_in_museum())) {
                int *ids;
                ids=o->query_room()->get_pos();
                if(f==ids[2]) 
                        return head+show_mapa(f,ids[0],ids[1]);
        }
        for(i=0;i<=MAXHEIGHT;++i) {
                w1=" ";
                w2=" ";
                w3=(i+1)+"";
                if(i==MAXHEIGHT)
                        w3=" ";

                for(j=0;j<=MAXWIDTH;++j) {
                        w1+=show_room_wall1(j,i,f);
                        w2+=show_room_wall2(j,i,f);
                        w3+=show_room_wall3(j,i,f);
                }
                if(i==MAXHEIGHT)
                        w2=HEADBAR;
                ret+=w1+"\n"+w2+"\n"+w3+"\n";
        }
        return head+ret;
}
int room_exist(int x,int y,int f) {
        if(f!=0) return 0; // now disable other floors
        if((x<0)||(x>=MAXWIDTH)) return 0;
        if((y<0)||(y>=MAXHEIGHT)) return 0;
        return 1;
}
string get_enter_room() {
        return ENTRYROOM;
}

