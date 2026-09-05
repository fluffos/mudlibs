//laxiangd.c 自助蜡像资料存储
//by all@pkuxkx, 2012/11/11
//提供记录、读取房间文件里写入生成npc位置的函数

inherit F_DBASE;
inherit F_SAVE;

#include <ansi.h>
#include <localtime.h>

/*
nosave mapping families = ([
    "slp":({"少林派",1}),
    "wdp":({"武当派",1}),
    "emp":({"峨嵋派",1}),
    "hsp":({"华山派",1}),
    "xxp":({"星宿派",1}),
    "slj":({"神龙教",1}),
    "bts":({"白驼山",1}),
    "ljg":({"灵鹫宫",1}),
    "gb":({"丐帮",1}),
    "qzp":({"全真派",1}),
    "gmp":({"古墓派",1}),
    "tls":({"天龙寺",1}),
    "ct":({"朝廷",1}),
    "tdh":({"天地会",1}),
    "thd":({"桃花岛",1}),
    "xsp":({"雪山派",1}),
    "mj":({"明教",1}),
    "rysj":({"日月神教",1}),
    "gsmr":({"姑苏慕容",1}),
    "dls":({"大轮寺",1}),    
    "bx":({"百姓",0}),
    "tong":({"铜像",0}),    
    "yin":({"银像",0}),    
    "jin":({"金像",0}),    
    "baijin":({"白金像",0}),                
]);
*/

string query_save_file()
{
    return "/data/laxiangd";
}

void create()
{
    seteuid(getuid());
    restore();
}

void add_location(string family,int amount)
{		
    add("laxiang_location/"+family,amount);
    save();    	
}

void set_location(string family,int amount)
{		
    set("laxiang_location/"+family,amount);
    save();	
}

int get_location(string family)
{		
    return query("laxiang_location/"+family);	
}
