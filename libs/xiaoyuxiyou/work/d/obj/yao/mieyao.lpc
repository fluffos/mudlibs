//负责存放妖。

#include <ansi.h>
#define SHILI_D "/adm/daemons/shili"
#define YAODIR_ "/d/obj/yao/"

string* listxian=({
    "yao-moon",
    "yao-fangcun",
    "yao-putuo",
    "yao-dragon",
    "yao-wzg",
    "yao-kunlun",
    "yao-jjf",
});

string* listyao=({
    "yao-hell",
    "yao-wudidong",
    "yao-xueshan",
    "yao-gumu",
    "yao-pansi",
});


string *dirs = ({
        "baoxiang", 
        "biqiu",
        "chechi",
        "fengxian",
        "jinping",
        "jisaiguo",
        "nuerguo",
        "tongtian",
        "qinfa",
        "tianzhu",
        "wudidong",
        "wuji",
        "yuhua",
        "zhuzi",
});

string add_new_yao( object me);

void create()
{
        seteuid(getuid());
}

string query_family_type(string fam)
{
        if( fam=="东海龙宫" || fam=="方寸山三星洞" || fam=="五庄观"
         || fam=="将军府" || fam=="月宫"||fam=="南海普陀山" )
                return "xian";
        return "yao";   
}


string add_new_yao(object me)
{
        string loc,fam,pos;
        string mytype,yaotype,postype;
        object yao;
        string str="";
        int lvl=me->query_temp("mieyao/level");
        string yaoid;
        string yaoname,*yaoids;
        if ( !me ) return 0;
       
        me->delete("mieyao");
        pos=dirs[random(sizeof(dirs))];
        loc="/d/qujing/"+pos;
        mytype=query_family_type(me->query("family/family_name"));
//      fam=SHILI_D->query("family");
        fam=SHILI_D->query_family(pos);
        postype=query_family_type(fam);
        if(mytype=="xian")yaotype="yao";
        else yaotype="xian";
        if(yaotype=="xian") 
                yao=new(YAODIR_+listxian[random(sizeof(listxian))]);
        else    yao=new(YAODIR_+listyao[random(sizeof(listyao))]);
        
        yaoname=yao->query("name");
        yaoids=yao->parse_command_id_list();
        yaoid=me->query("id")+"'s "+yaoids[0];
        yaoids=({yaoid})+explode(yaoid," ");
        yao->set_name(yaoname,yaoids);
        yao->set("pos",pos);
   
        str=yao->invocation(me,lvl,loc);
        if( !str || !stringp(str) )  return "太平盛世，无事发生";
        if(yaotype=="xian") {
                if(mytype!=postype) 
                        str=str+"一带护法。\n你速去扰乱他们的部署！\n";
                else if(fam==me->query("family/family_name"))
                        str=str+"居然在一带积德行善。\n你速去吃了这个狂人。\n";
                else    str=str+"替"+fam+"救济贫民,\n你去给这个狂徒点颜色看看。\n";
                }
        else    {
                if(mytype!=postype) 
                        str=str+"一带护法。\n你速去扰乱他们的部署！\n";
                else if(fam==me->query("family/family_name"))
                        str=str+"一带扰乱。\n你速去消灭之。\n";
                else    str=str+"一带扰乱。\n你速去助"+fam+"消灭之。\n";
                }
        me->set("mieyao/name",yaoname);
        me->set("mieyao/place",SHILI_D->query_chinese(pos));
        return str;
}

