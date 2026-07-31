// Updated by zjb@TY /02/09/03/
#include <ansi.h>;
inherit NPC;
inherit F_SAVE;
int begin_paimai(string name,int value ,int paimai_count,int m);
int go_paimai(string id,string name,int value,int num,int m);
int report_paimai(object buyer,int money,int num);
int finish_paimai(int num,int sign);
int rm_ob(object me);
int pay_back(string id, int amount);
int delete_ob(int num);
string to_ch(int money);
string query_save_file()
{
        return DATA_DIR + "paimai";
}

void create()
{
  seteuid(getuid());
    if (!restore()) {
        set_name("ÅÄÂôÊ¦", ({ "paimai shi", "ji", "shi" }) );
              set("nickname", HIW "ÌìÑÄµÚÒ»´¸" NOR);
        set("gender", "ÄĞĞÔ");
        set("age", 45);
        set("no_get", 1);
        set("long",
                "ÕâÊÇÒ»Î»Êİ¸ßµÄÖĞÄêÈË£¬ÒòÎª¹«ÕıÎŞË½¶ø±»ÍÆÎªÌìÏÂµÚÒ»ÅÄÂôÊ¦¡£\n");
        set("combat_exp",600000);
        set("shen", 0);
            set("attitude", "friendly");

        set("apply/attack", 100);
        set("apply/defense", 100);

      set("max_jingli", 800);
       set("max_neili", 800);
        
        set_skill("force", 300);
        set_skill("unarmed", 300);
     set("quest_npc",1);
        set_skill("sword",300);
        set_skill("parry",300);
        set_skill("dodge", 300);

            setup();

       carry_object("/clone/cloth/cloth")->wear();
}    else { 
        set_name("ÅÄÂôÊ¦", ({ "paimai shi", "ji", "shi" }) );
              set("nickname", HIW "ÌìÑÄµÚÒ»´¸" NOR);
        set("gender", "ÄĞĞÔ");
        set("age", 45);
        set("no_get", 1);
        set("long",
                "ÕâÊÇÒ»Î»Êİ¸ßµÄÖĞÄêÈË£¬ÒòÎª¹«ÕıÎŞË½¶ø±»ÍÆÎªÌìÏÂµÚÒ»ÅÄÂôÊ¦¡£\n");
        set("combat_exp",600000);
        set("shen", 0);
            set("attitude", "friendly");

        set("apply/attack", 100);
        set("apply/defense", 100);

      set("max_jingli", 800);
       set("max_neili", 800);
        
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("sword",300);
        set_skill("parry",300);
        set_skill("dodge", 300);

            setup();

       carry_object("/clone/cloth/cloth")->wear();

}
}


void init()
{
        ::init();
        add_action("do_paimai", "paimai");
                add_action("do_paimailist", "paimailist");
                add_action("do_yao", "yao");
        
}
int do_paimai(string arg)
{
        object who,ob;
        int money,clone_number,paimai_count,i,value,sale_price,zjb;
        string id,file_name;
        mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,opaimai,spaimai;
        string* terms;
        
      if ( !this_object()->query("rm")&&this_object()->query("rm")<time() )
        this_object()->rm_ob(this_object());
        fpaimai = query("fpaimai");
        vpaimai = query("vpaimai");
        ipaimai = query("ipaimai");
        npaimai = query("npaimai");
        lpaimai = query("lpaimai");
        opaimai = query("opaimai");
        spaimai = query("opaimai");
        
        who=this_player();
        zjb=who->query("zjb_money");
        
        if( who->is_busy() )
         return notify_fail("ÄãµÄ¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÌá½»ÎïÆ·½øĞĞÅÄÂô¡£\n");
    if( !arg || sscanf(arg, "%s with %d",id, money)!=2 )
                return notify_fail("Ö¸Áî¸ñÊ½£ºpaimai <ÎïÆ·id> with <µ×¼Û(silverÎªµ¥Î»)> \n");
        if( !ob=present(id, who))
                return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
        if( ob->query("money_id") )     
                return notify_fail("ÄãÒªÅÄÂô¡¸Ç®¡¹£¿\n");
         if (ob->query("no_sell")&&!ob->query("can_auction"))               return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÕâÑù¶«Î÷²»ÄÜÅÄÂôÁË£¡\n");

/*
        if (ob->query("value")<10 || money==0)
                return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÕâ¼ş¶«Î÷²»ÖµÇ®£¬Äã¾Í±ğÂôÁË£¡\n");
*/
          if(who->query_temp("paimai_time")&& time() < who->query_temp("paimai_time")+30)
                 return notify_fail("Äã¸Õ¸ÕÅÄÂôÍê¶«Î÷£¬Ä¿Ç°²»ÄÜ²ÎÓëÅÄÂô¡£\n");
       if (ob->query("age"))
           return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÄãÏë··ÂôÈË¿Ú°¡£¡\n");
        if (ob->query("no_drop")&&!ob->query("can_auction"))
                return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÈÓ²»µôµÄ¶«Î÷ÏëÀ´Âô£¬Äãµ±ÎÒÕâÀïÊÇÀ¬»ø¶Ñ°¡£¡\n");
        if( ob->query_unique() && !ob->query("can_auction") )
                return notify_fail("ÅÄÂôÊ¦ËµµÀµÄËµ£ºÕâÊÇ¹ÂÆ·°¡£¬ÎÒÃÇÕâÀï¿É²»¸Ò³Ğ½ÓÕâ¸öÂòÂôÁË£¡\n");
   if(money<(10+ob->query("value")/10000)|| money < 101)
                return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÄúÏë×öÅâ±¾ÉúÒâ£¬ºÙºÙ£¬Äú²Æ´óÆø´ÖÎŞËùÎ½£¬Ğ¡µêµÄÉùÓş¿ÉÊÇÒªÊÜËğµÄ¡£\n");
   if(money<0||money>100000000)
    return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÄã³öµÄ¼Û¸ñÊÇ·Ç·¨µÄ£¬Èç¹ûÏë³ö´ó¼ÛÇ®ÇëÓÃĞÇ¿Õ±Ò¡£\n"); //·ÀÖ¹Òç³ö
        if (who->query("money")<10000)
                return notify_fail("ÅÄÂôÊ¦ËµµÀ£ºÄãÕËºÅÀïµÄÇ®²»¹»Ö§¸¶ÊÖĞø·Ñ£¡\n");
   
        who->add("money",-10000);
        command("sys "+who->query("name")+"("+who->query("id")+")"+NOR+ob->query("name")+HIC+"½øĞĞÅÄÂô¡£\n"NOR);
        command("chat "+"ÓĞÈËÌá½»"+NOR+ob->query("name")+HIC+"½øĞĞÅÄÂô£¬ÇëÊ¹ÓÃ"+HIG"¡¾ºÍÆøÉú²Æ¡¿"NOR+HIC"ÆµµÀ£¨£Ó£Á£Ì£Å£©ÁË½â¾ßÌåÇé¿ö¡£"NOR);
    who->set_temp("paimai_time",time());
        sscanf(file_name(ob),"%s#%d",file_name,clone_number);

        if( mapp(fpaimai) &&  sizeof(fpaimai) )
                add("total_number",1);
        else
                set("total_number",0);
        
        value = ob->query("value");
        sale_price= ob->query_temp("sale_price");
        if (sale_price>0)
                sale_price= sale_price>value?value:sale_price;

        this_object()->set("fpaimai/"+ sprintf("%d",query("total_number")),file_name);
        set("vpaimai/"+sprintf("%d",query("total_number")), money);
        set("ipaimai/"+sprintf("%d",query("total_number")), who->query("id"));
        set("npaimai/"+sprintf("%d",query("total_number")), ob->query("name"));
        set("lpaimai/"+sprintf("%d",query("total_number")), 1);
        set("opaimai/"+sprintf("%d",query("total_number")), who->query("id"));
        set("spaimai/"+sprintf("%d",query("total_number")), sale_price);
        
        if (query("total_number")==0 || query("lpaimai/"+sprintf("%d",query("number")))==0)
        {
                set("value",money);
                set("pnum",0);
                set("number",query("total_number")>0?query("number")+1:0);
                call_out("begin_paimai",5,ob->query("name"),money,query("number"),0);
        }
        
        if(!ob->query_unique())
                destruct(ob); 
        else
        {
                ob->move(this_object());
                call_out("destobj",700,ob);
        }
        this_object()->save();
        return 1;
}
void destobj(object ob)
{
        if(!ob)
                return;
    destruct(ob); 
}
int begin_paimai(string name,int money,int num,int m)
{
        string mon;
        m+=1;
        if (m==1)
        {
                command("sale "+"ÏÖÔÚ¿ªÊ¼ÅÄÂô "NOR+name+HIG+" µÄËùÓĞÈ¨¡£"+NOR);
        }
        set("on_paimai",1);
        mon = to_ch(money);
        command("sale "+NOR+name+HIG+"µ×¼Û"+mon+"µÚ"+chinese_number(m)+"´Î");
        command("sale "+name+HIG"ÊÇ±¾µêµÚ¡º"+chinese_number(num)+"¡»ºÅÅÄÂôÆ·£¬ÓĞÒâÕßÇëÊ¹ÓÃ£Â£É£ÄÃüÁî½øĞĞ¾ºÂò¡£\n"NOR);

        if (!(m==3))
                call_out("begin_paimai",20,name,money,num,m);
        else
                call_out("finish_paimai",2,num,0);      
}
int finish_paimai(int num,int sign)
{
        string id,owner_id;
        object buyer,owner;
        int i;

        
        id=query("ipaimai/" + sprintf("%d", num));
        owner_id=query("opaimai/" + sprintf("%d", num));
        set("lpaimai/"+sprintf("%d",num), 0);
                
        buyer=find_player(id);
        owner=find_player(owner_id);
        if (sign==0)
        {
                command("sale "+query("npaimai/" + sprintf("%d", num))+HIG+" µÄËùÓĞÈ¨ÅÄÂôÁ÷±êÁË¡£"+NOR);
                if(owner)
                        tell_object(owner,HIR"ÄãµÄ¶«Î÷Ã»ÓĞÂô³öÈ¥£¬ÇëÔÚÊ®·ÖÖÓÄÚÀ´ÅÄÂôÎİÀ´È¡»Ø×Ô¼ºµÄÎïÆ·¡£\n"NOR);
        }
        else            
        {
        if(!buyer->query_temp("invisibility_buyer"))
        {
                command("sale  ³É½»!"+buyer->query("id")+"»ñµÃÁË "+NOR+query("npaimai/" + sprintf("%d", num))+HIG+" µÄËùÓĞÈ¨¡£"+NOR);
        }
        else
        {
                command("sale ³É½»! ÓĞÈË»ñµÃÁË "+NOR+query("npaimai/" + sprintf("%d", num))+HIW+" µÄËùÓĞÈ¨¡£"+NOR);
                command("sys  ³É½»!"+buyer->query("id")+"»ñµÃÁË "+NOR+query("npaimai/" + sprintf("%d", num))+HIG+" µÄËùÓĞÈ¨¡£"+NOR);
        }
                if (buyer)
                        tell_object(buyer,HIR"Äã»ñµÃÁË "+NOR+query("npaimai/" + sprintf("%d", num))+HIR+" µÄËùÓĞÈ¨£¬ÇëÔÚÊ®·ÖÖÓÄÚÀ´ÑïÖİÖĞÑë¹ã³¡È¡»ØÄãÂòµÄ¶«Î÷¡£\n"NOR);
                if (owner)
                        tell_object(owner,HIR"ÄãµÄ"+NOR+query("npaimai/" + sprintf("%d", num))+HIR+"ÂôÁË"
                        +chinese_number(query("vpaimai/" + sprintf("%d", num)))+"Á½Òø×Ó£¬ÒÑ¾­¼ÓÈëÄãµÄ»§Í·ÁË¡£\n"NOR);     
//          owner->add("money",query("vpaimai/" + sprintf("%d",num))*100);
        }
    if(buyer)
          buyer->apply_condition("auction_forbindden",1+random(10));
        set("on_paimai",0);
        
        if (query("pnum"))
            pay_back(owner_id,query("vpaimai/" + sprintf("%d", num))*100);
        
        call_out("delete_ob",600,num);

        num=num+1;
        if (query("lpaimai/" + sprintf("%d", num))==1)
        {
                set("value",query("vpaimai/" + sprintf("%d", num)));
                set("number",num);
               set("pnum",0);
        call_out("begin_paimai",5,query("npaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num)),num,0);
 }
        this_object()->save();
     return 1;
 }
  int report_paimai(object buyer,int money,int num)
{
      string mon;
      remove_call_out("begin_paimai");
      remove_call_out("finish_paimai");
         remove_call_out("go_paimai");
       
        if(query("pnum")) // pnumÊÇÅĞ¶ÏÊÇ·ñÓĞÈËÍ¶±êµÄ±êÖ¾¡¡
   {
                pay_back(query("ipaimai/" + sprintf("%d", num)),query("vpaimai/" + sprintf("%d", num))*100);//¹é»¹Ç°Ò»¸ö¾ºÂòÕßµÄÇ®¡
               add("pnum",1);
      }
    if (money*100>buyer->query("money")){
    buyer->add("zjb_money",-((money / 1000000)+1) );
tell_object(buyer,HIR"ÄãµÄ´æ¿î²»¹»£¬ÏµÍ³×Ô¶¯°ÑÄãµÄĞÇ¿Õ±Ò»»³É´æ¿îÁË£¡\n"NOR);
        buyer->add("money",((money / 1000000)+1)*100000000-(money*100));
    }

else
      buyer->add("money",(0-money*100));
      set("vpaimai/"+sprintf("%d",num), money);
     set("ipaimai/"+sprintf("%d",num), buyer->query("id"));
     set("value",money);
     mon =to_ch(money);
          if(!buyer->query_temp("invisibility_buyer"))
      {
          if (!query("pnum"))
              add("pnum",1);
                command("sale  "+buyer->query("id")+" ³ö¼Û "+mon+"¹ºÈë"+NOR+query("npaimai/" + sprintf("%d", num))+HIG"µÄËùÓĞÈ¨¡£");
      call_out("go_paimai",5,buyer->query("name")+"("+buyer->query("id")+")",query("npaimai/" + sprintf("%d", num)),money,num,0);
   }
     else
     {
          if (!query("pnum"))
         add("pnum",1);
       command("sys  "+buyer->query("id")+" ³ö¼Û "+mon+"¹ºÈë"+NOR+query("npaimai/" + sprintf("%d", num))+HIG"µÄËùÓĞÈ¨¡£");
       command("sale  ÓĞÈË³ö¼Û "+chinese_number(money)+"Á½Òø×Ó ¹ºÈë"+NOR+query("npaimai/" + sprintf("%d", num))+HIG"µÄËùÓĞÈ¨¡£");
       call_out("go_paimai",5,"Ä³ÈË",query("npaimai/" + sprintf("%d", num)),money,num,0);
        }
        this_object()->save();
        return 1;
}
int pay_back(string id, int amount)
{
    object who;

    who=find_player(id);
    if(who)
        {
                who->add("money",amount);
tell_object(who,HIR"Äã¸Õ²Å²Î¼ÓÅÄÂôµÄÇ®ÏÖÔÚ»¹¸øÄú£¡\n"NOR);
                if(!who->save(1)) 
                {
                        log_file("paimai_log","Failed to return "+amount+
                                " coin to "+id+"\n");
                        return 0;
                }
        log_file("paimai_log","pay "+amount+" to "+id+"\n");
        return 1;
    } 
        else
        {
                who=new(USER_OB);
                who->set("id",id);
                if(!who->restore())
                {
                        log_file("paimai_log","Failed to return "+amount+
                                " coin to "+id+"\n");
                        destruct(who);
                        return 0;
                }

                else 
                {
                        who->add("money",amount);
                        if(!who->save(1))
                        { // save(1) will not erase autoload.
                                log_file("paimai_log","Failed to return "+amount+
                                        " coin to "+id+"\n");
                                destruct(who);
                                return 0;
                        } 
                        log_file("paimai_log","pay "+amount+" to "+id+"\n");
                        destruct(who);
                        return 1;
                }
    }
}
int go_paimai(string id,string name,int money,int num,int m)
{
        string mon;
        m+=1;
        mon = to_ch(money);
        command("sale "+id+" ³ö¼Û "+mon+"¹ºÈë "+NOR+name+HIG+" µÄËùÓĞÈ¨£¬µÚ"+chinese_number(m)+"´Î");
        command("sale "+name+HIG"ÊÇ±¾µêµÚ¡º"+chinese_number(num)+"¡»ºÅÅÄÂôÆ·£¬ÓĞÒâÕßÇëÊ¹ÓÃ£Â£É£ÄÃüÁî½øĞĞ¾ºÂò¡£\n"NOR);
        if (!(m==3))
                call_out("go_paimai",20,id,name,money,num,m);

        else
                call_out("finish_paimai",5,num,1);      
}
int do_paimailist()
{
        int i;
        
       for(i=query("number");;i++)
        {
                if (query("lpaimai/" + sprintf("%d", i))==1)
                {
                        printf("%-10s£º µ×¼Û %-3d Á½Òø×Ó \n",query("npaimai/" + sprintf("%d", i)),query("vpaimai/" + sprintf("%d", i)));
                }
                else
           { this_object()->save();
                        return 1;
                    }
        }
             this_object()->save();
        return 1;
}
int do_yao()
{
        mapping fpaimai,vpaimai,ipaimai,npaimai,lpaimai,spaimai;
        string* terms;
        string id;
        object ob;
        int i;

        fpaimai = query("fpaimai");
        vpaimai = query("vpaimai");
        ipaimai = query("ipaimai");
        npaimai = query("npaimai");
        lpaimai = query("lpaimai");
        spaimai = query("spaimai");
        
        if( mapp(fpaimai) &&  sizeof(fpaimai) )
        {
                terms=keys(fpaimai);
        
                for(i=0;i<sizeof(terms);i++)
                {
                        if (ipaimai[terms[i]]==this_player()->query("id") && lpaimai[terms[i]]==0)
                        {
                                ob=new(fpaimai[terms[i]]);
                                if (spaimai[terms[i]]>0)
                                        ob->set_temp("sale_price",spaimai[terms[i]]);
                                ob->move(this_player());
                                if(ob->query_unique()||ob->query("can_auction"))
                                        ob->set("can_auction",0);
                                ipaimai[terms[i]]="paimai shi";
                                message_vision(CYN+"ÅÄÂôÊ¦½«"+NOR+npaimai[terms[i]]+CYN+"½»¸ø$N¡£\n"NOR, this_player(),this_object());
                                return 1;

                        }
                }
        }
        tell_object(this_player(),"ÕâÀïÃ»ÓĞÊôÓÚÄãµÄÎïÆ·¡£\n");
        return 1;
}
int delete_ob(int num)
{
        delete("npaimai/"+sprintf("%d",num));
        delete("ipaimai/"+sprintf("%d",num));
        delete("vpaimai/"+sprintf("%d",num));
        delete("lpaimai/"+sprintf("%d",num));
        delete("fpaimai/"+sprintf("%d",num));
        delete("spaimai/"+sprintf("%d",num));
             this_object()->save();
        
        return 1;
}

string to_ch(int money)
{
        int gold,silver;
        string mon;
        gold = money/100;
    if(gold)
                mon =chinese_number(gold)+"Á½»Æ½ğ";

        silver = money-gold*100;
        if(silver) 
                mon +="ÓÖ"+chinese_number(silver)+"Á½°×Òø";
        mon +="("+sprintf("%d",money)+" silver)";
    set_temp("price",mon);
             this_object()->save();
    return mon;
}

int rm_ob(object me)
{
      if ( this_object()->query("rm")<time() ) {
      rm("/data/paimai.o");
      me->set("rm",time()+72000);
      me->save();
      command("sys ÅÄÂôÏµÍ³¸üĞÂÍê±Ï£¡");
      }
}
