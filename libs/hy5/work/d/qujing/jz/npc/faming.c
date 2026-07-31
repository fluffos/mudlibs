//Cracked by Roath
 
inherit NPC;
string ask_hanshan();
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("法明长老", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set("long",
                "法明长老是化生寺的主持，神色庄重，举止间自有一番威仪。
听说他有一身武艺，也能呼风唤雨，却不传授于寺里的和尚。\n");
   set("title", "主持");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 500);
        set("max_neili", 500);
        set("force_factor", 40);
        set("max_neili", 500);
        set("neili", 900);
        set("mana_factor", 30);
        set("combat_exp", 200000);
	set("combat_exp",200000);	
        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


     
        set("inquiry", ([
                "血书": (: ask_hanshan :),
                "汗衫": (: ask_hanshan :),
                ]));
        set("count",1);
        setup();
        initlvl((200+random(100)),1);
        carry_object("/d/obj/cloth/monkcloth")->wear();
}

string ask_hanshan()
{
        object ob=this_player();
        object me=this_object();
        object xueshu,hanshan;
       

        if (query("count") < 1)
                return "我这已经没有了。";
//判断是否dntg over by dragon
        if( ob->query("obstacle/jz") == "done" )
        {
        command("shake");
        return("贫僧不知。");
        }
       
        if( present("xue shu", ob) || present("han shan", ob) )
        return("你不是有吗？");

        xueshu = new("/d/qujing/jz/obj/xueshu");
        hanshan = new("/d/qujing/jz/obj/hanshan");
        switch ( random(2) ) {
        case 0:
        xueshu->move(ob);
        break;
        case 1:
        hanshan->move(ob);
        break;
        }  
      add("count",-1);
      return("这是当年从玄奘身上发现的，你拿去吧。");
}        
        
        
