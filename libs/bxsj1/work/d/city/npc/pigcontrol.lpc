// 圣诞猪发放器
// created by campsun 2003/12/22
#include <ansi.h>

inherit ITEM;
string get_place(string str);
object get_rnd_place();
int check(object);

int do_start();

void create()
{
    set_name(CYN "猪控制器" NOR, ({ "control"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个产生圣诞猪的控制器，每用一次将会产生十五只不同门派的圣诞猪(Start)。\n");
		set("value", 10);
		set("no_give",1);
		set("no_drop",1);
		set("qiao",1);
		set("egg",1);
		set("material", "paper");
             }
	setup();
}
void init()
{
   	add_action("do_start", "start");
}

int do_start()
{
	int i;
	object where;
	object piggy;
	string *str_menpai = ({ "wd","hs",
							"ss","gm",
							"gb","tz",
							"dls","mr",
							"sld","xx",
							"em","mj",
							"thd","tls",
							"sl",
							
						});
	object me,ob;
	me=this_player();
	ob=this_object();
	for (i=0;i<sizeof(str_menpai);i++)
	{
		piggy = new("/d/city/npc/pig");
		piggy->set("party",str_menpai[i]);
		where = get_rnd_place();
		piggy->move(where);
		write(piggy->query("id") +" " + base_name(where) + "\n");
	}
	return 1;

}

object get_rnd_place()
{
	object *living;
	object target,objwhere;
	string str;
	int i,j;
    living = livings();
    for (i=0;i < sizeof(living);i++){
    	j = random(sizeof(living));
        if (!j || j == sizeof(living) -1) continue;
        if(check(living[j]) ){
        	target = living[j];
            objwhere = environment(target);
            str = objwhere->query("short");
            if (!sizeof(objwhere->query("exits"))
            	|| str == "武僧堂"
                || str == HIR"心禅堂"NOR
                || str == "金刚伏魔圈" ) continue;
                if( get_place(base_name(environment(target)))!="" ) break;
        }
    }
    return environment(target);
}

string *no_kill_list = ({
         "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

string get_place(string str)
{
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":    str = "西域白陀山";  break;
                        case "hj":      str = "西域回疆"; break;
                        case "mingjiao":  str = "西域明教"; break;
                        case "shaolin":   str = "少林"; break;
                        case "songshan":  str = "嵩山"; break;
                        case "wudang":    str = "武当山"; break;
                        case "xingxiu":   str = "星宿海"; break;
                        case "city":      str = "扬州城"; break;
                        case "emei":      str = "峨嵋山"; break;
                        case "fuzhou":    str = "福州"; break;
                        case "jiaxing":   str = "嘉兴"; break;
                        case "taishan":   str = "山东泰山"; break;
                        case "dali":      str = "大理国"; break;
                        case "tls":       str = "天龙寺"; break;
                        case "tiezhang":  str = "铁掌山"; break;
                        case "kunlun":    str = "";break;
                        case "fairyland": str = "西域昆仑山"; break;
                        case "gumu":      str = ""; break;
                        case "chengdu":   str = "成都"; break;
                        case "huashan":   str = "华山"; break;
                        case "xiangyang": str = "襄阳"; break;
                        case "xueshan":   str = "大雪山"; break;
                        case "wizard":    str = ""; break;
                        case "death":     str = ""; break;
                        case "gaibang":   str = "丐帮分舵"; break;
                        case "hz":      str = "杭州"; break;
                        case "village":   str = "陕西小村"; break;
                        case "wuguan":    str = "襄阳武馆"; break;
                        case "thd":       str = "桃花岛"; break;
                        case "gaibang":   str = "丐帮分舵"; break;
                        case "mr":      str = "燕子坞"; break;
                        case "suzhou":    str = "苏州县城"; break;
                        case "sld":       str = "北海神龙岛"; break;
        }
        return str;
}


int check(object ob)
{
        object room;
        string room_name;

        if(!objectp(ob)
         || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
         || ob->query("env/invisibility")
         || ob->query("no_quest")
         || member_array(ob->query("id"), no_kill_list) != -1
         || userp(ob)
         || ob->query("attitude")=="aggressive"
         || ob->query("have_master")
         || !objectp(room=environment(ob))
         || room->query("no_fight")
         || room->query("outdoors") == "昆仑翠谷"
         || room->query("short") == "地下黑拳市"
         || strsrch(room_name = file_name(room),"/d/") != 0
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
         || strsrch(room_name, "/d/kunlun/") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/wudang/") == 0
         || strsrch(room_name, "/d/shaolin/liwu") == 0
         || strsrch(room_name, "/d/shaolin/houyuan") == 0
         || strsrch(room_name, "/d/huashan/jiabi") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/shaolin/xinchan") == 0
         || strsrch(room_name, "/d/mingjiao/yuanzi") == 0
         || strsrch(room_name, "/d/mingjiao/wxiang") == 0
         || strsrch(room_name, "/d/baituo/") == 0
         || strsrch(room_name, "/d/thd/") == 0
         || strsrch(room_name, "/d/sld/") == 0)
         return 0;
        return 1;
}