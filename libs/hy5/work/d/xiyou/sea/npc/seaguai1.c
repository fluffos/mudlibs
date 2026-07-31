// Created by kuku@sjsh 2003.5.17
 
inherit NPC; 
#include <ansi.h>
       
void create() 
{ 
        if(random(2)==0)  
                set_name( "老妖怪", ({"old guai","guai"})); 
        else  
                set_name( "小妖怪", ({"small guai","guai"})); 
        set("age", 50+random(100)); 
        set("gender", random(2)?"男性":"女性"); 
        set("attitude", "aggressive"); 
        set("per", random(20)+1); 
        set("str", 100); 
        set("cor", 40); 
        set("con", 40); 
        set("int", 40); 
        set("spi", 40); 
        set("cps", 40); 
        set("kar", 40); 
        set("max_gin", 1000);
        set("kee", 5000); 
        set("max_kee", 5000); 
        set("eff_kee", 5000); 
        set("sen", 5000); 
        set("max_sen", 5000); 
        set("eff_sen", 5000); 
      
        create_family("南海普陀山",2 , "弟子");
        set("title",HIM"人精"NOR);
        set("class", "bonze");
        set("no_steal",1); 
        set("taskguai",1); 
        

        
        setup();

}

