//¿ª·ÅÖÁ£«13µÄ×°±¸ add by luoyun 2007/01/11 
//Ôö¼ÓºÏ³É¼ÇÂ¼ add by luoyun 2007/01/11 
#include <ansi.h>
inherit ITEM;

int get_baoshi(int sta,string mess1);
private string  create_file(object item_temp);
private int     save_item_file(string filename, string content);
private string  prop_segment(mapping p, string path);

void create()
{
        set_name(HIM"½ø»¯ºÏ³ÉÌ¨(tai)"NOR, ({"tai"}) );
        set("short", HIM"½ø»¯ºÏ³ÉÌ¨(tai)"NOR);
        set_max_encumbrance(5000);
        set("temperature",25);
        set_temp("max_temp",25);
        set_temp("min_temp",25);
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Ú");
                set("no_get", 1);
                set("no_put", 1);
	set ("long", @LONG
ÕâÊÇºÏ³É½ø»¯×°±¸µÄµØ·½¡£
------------------------------------------
×£¸£ŒšÊ¯: ÓÃÓÚºÏ³É£«1ÖÁ£«2µÄ×°±¸    ³É¹¦ÂÊ60£¥
ì`»êŒšÊ¯£ºÓÃÓÚºÏ³É£«1ÖÁ£«4µÄ×°±¸    ³É¹¦ÂÊ45£¥
„“ÔìŒšÊ¯£ºÓÃÓÚºÏ³É£«1ÖÁ£«7µÄ×°±¸    ³É¹¦ÂÊ55£¥
ÌìÊ¹Ö®ĞÄ£ºÓÃÓÚºÏ³É£«1ÖÁ£«9µÄ×°±¸    ³É¹¦ÂÊ50£¥
ÌìÉñÖ®œI£ºÓÃÓÚºÏ³É£«1ÖÁ£«12µÄ×°±¸   ³É¹¦ÂÊ50£¥
ÜŞ@Ô­Ê¯£ºÓÃÓÚºÏ³É£«1ÖÁ£«13µÄ×°±¸   ³É¹¦ÂÊ45£¥
-------------------------------------------
ÔÚÕâÀïÄã¿ÉÒÔÓÃÈçÏÂÃüÁîºÏ³É½ø»¯×°±¸:
-----------------------------------
init   : ×âÓÃ½ø»¯ºÏ³ÉÌ¨(20000ÔªÈËÃñ±Ò)
add    : °Ñ±¦Ê¯ºÍ×°±¸·ÅÈë½ø»¯ºÏ³ÉÌ¨    
finish : ½áÊøºÏ³É(Ê§”¡ËùÓĞÎïÆ·ÏûÊ§)    
-----------------------------------
LONG);               

                set("value", 50);
        }
}

int is_container() { return 1; }

void init()
{
	add_action("do_init", "init");
	add_action("do_add","add");
	add_action("do_finish", "finish");
	add_action("do_get","get");
	add_action("do_put","put");	
}

int do_init()
{
   	object me = this_player();
   	object obj,ob = this_object();   
   	     
       if (me->query("rmb")<20000) return notify_fail("½ø»¯ºÏ³ÉÌ¨ĞèÒª2ÍòÔªÈËÃñ±ÒÒ»´Î£¡\n");  
       if (me->query_temp("checking"))
      return notify_fail("ÄãÒÑ¾­×âÓÃÁË½ø»¯ºÏ³ÉÌ¨¡£\n");
     	if(ob->query_temp("user") && ob->query_temp("user") != me->query("id"))
     	{
     		if ( time()-ob->query_temp("init_time")<300 && ((obj=present(ob->query_temp("user"))) || (obj = present(ob->query_temp("user"), environment(me))))) 
   			return notify_fail(obj->name()+"ÕıÔÚÓÃÄØ£¬ÇëµÈÎå·ÖÖÓÔÙÊÔÊÔ£¡\n");      
   	}
       me->add("rmb",-20000);
	reload_object(ob);
	ob->set_temp("init_time",time());
       ob->set_temp("user",me->query("id"));
       me->set_temp("checking",1);
       message_vision("$N»¨ÁË·¡ÍòÔªÈËÃñ±Ò×âÓÃÁË"+ob->name()+"×¼±¸ºÏ³É½ø»¯×°±¸¡£\n",me);
       //message("channel:chat",HIM"¡¾¿ÕÑ¨À´·ç¡¿£ºÌıËµ"+me->name()+"¿ªÊ¼ºÏ³É½ø»¯×°±¸¡£\n"NOR,users());
       remove_call_out("do_temperature");
       remove_call_out("do_checking");
       call_out("do_temperature", 2);
       call_out("do_checking", 60);
       return 1;		
}

int do_add(string arg)
{
	 string item_name;        
        object me = this_player();
        object ob = this_object();
        object item;
        mixed *inv;
        int i;
        inv = all_inventory(ob);

	if (ob->query_temp("user") != me->query("id")) 
               return notify_fail("Äã×âÓÃÁË½ø»¯ºÏ³ÉÌ¨ÁËÂğ£¿\n");
       if(!arg) 
               return notify_fail("ÄãÒª½«Ê²Ã´¶«Î÷·ÅÈë½ø»¯ºÏ³ÉÌ¨Àï£¿\n");
       if( sscanf(arg, "%s in tai", item_name)!=1 )
                return notify_fail("ÓÃ·¨£ºadd <> in tai¡£\n");
       item=present(item_name, me);       
       if (! present(item_name, me)) 
               return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâ¶«Î÷¡£\n");       
     	if (sizeof(all_inventory(ob))>=2) 
               return notify_fail(ob->name()+"ÀïÃæÒÑ¾­·ÅÂúÁË¡£\n");
       if ((string)item->query("express")!="can_shenghua")  
              return notify_fail("ÄãÖ»ÄÜ·Å¿É½ø»¯ÎïÆ·½øÈ¥¡£\n"); //ÅĞ¶Ï·ÅÈëÎïÆ·ÊÇ·ñ¿É½ø»¯ 
       if(!sizeof(inv)) 
       {
               message_vision( "$N½«Ò»"+item->query("unit")+item->query("name")+"·Å½ø"+ob->name()+"¡£\n",me);
               item->move(ob);      
}
               for(i=0; i<sizeof(inv); i++) 
       if( inv[i]->query("material") != "baoshi" )//Ì¨ÄÚÎïÆ·ÊÇ×°±¸
     {
   	      if (item->query("material") != "zhuangbei" )//·ÅÈëÎïÆ·²»ÊÇ×°±¸ 
   	 {
   	     message_vision( "$N½«Ò»"+item->query("unit")+item->query("name")+"·Å½ø"+ob->name()+"¡£\n",me);
            item->move(ob);      
   	}else{
return notify_fail("ÄãÏÖÔÚÖ»ÄÜ·Å½ø»¯±¦Ê¯½øÈ¥¡£\n");
  }
}
else
       if( inv[i]->query("material") != "zhuangbei" )//Ì¨ÄÚÎïÆ·ÊÇ±¦Ê¯
     {
   	      if (item->query("material") != "baoshi" )//·ÅÈëÎïÆ·²»ÊÇ±¦Ê¯ 
   	 {
   	     message_vision( "$N½«Ò»"+item->query("unit")+item->query("name")+"·Å½ø"+ob->name()+"¡£\n",me);
            item->move(ob);      
   	}else{
return notify_fail("ÄãÏÖÔÚÖ»ÄÜ·Å½ø»¯×°±¸½øÈ¥¡£\n");
  }
}
       return 1;
                
}

int do_get(string arg)
{
	string item_name;
        object me = this_player();
        object ob = this_object();
        if(!arg) return notify_fail("ÄãÒª¸ÉÊ²Ã´£¿\n");
        if( sscanf(arg, "%s from tai", item_name)==1 && ob->query_temp("user") != me->query("id"))
                return 1;
        return 0;
                
}

int do_put(string arg)
{
	string item_name;
        if(!arg) return notify_fail("ÄãÒª¸ÉÊ²Ã´£¿\n");
        if( sscanf(arg, "%s in tai", item_name)==1 )
                return 1;
        return 0;
                
}
int do_finish()
{
   object me = this_player();
   object ob = this_object();
   object baoshi;object zhuangbei;
   mixed *inv;
   string mess,filename,id;
   int i,lvl,sh_lvl,sj_lvl,suss,suss1,suss2,point; //staÎªÁ¶Íê×´Ì¬£¬0£ºÊ§°Ü£¬ÎïÆ·ÏûÊ§£»1£ºÊ§°Ü£¬ÎïÆ·²»ÏûÊ§£»
   		//2£º³É¹¦£¬µÃµ½£«1ºÏ³ÉÑb‚ä£»3¡¢³É¹¦£¬µÃµ½´óÓÚ£«2¡«£«7ºÏ³ÉÑb‚ä
      
   if (ob->query_temp("user") != me->query("id")) return notify_fail("Äã×âÓÃÁË½ø»¯ºÏ³ÉÌ¨ÁËÂğ£¿\n");
           remove_call_out("do_temperature");
  
   mess="";
   inv = all_inventory(ob);
   if( !sizeof(inv) ) 
	return notify_fail("½ø»¯ºÏ³ÉÌ¨ÀïÊ²Ã´¶¼Ã»ÓĞ£¬ÄãÏë¸ÉÊ²Ã´°¡£¿\n"); 
 
   if( sizeof(inv)<=1) 
       return get_baoshi(1,mess);//ëbÓĞÒ»·N–|Î÷²»ÄÜÓÃÀ´ºÏ³É  

                   for(i=0; i<sizeof(inv); i++)
  if (inv[0]->query("material")=="baoshi")
{
   baoshi=inv[0];
   zhuangbei=inv[1];
}else{
   zhuangbei=inv[0];
   baoshi=inv[1];
}
              for(i=0; i<sizeof(inv); i++)
                 lvl=baoshi->query("lvl");
                 sh_lvl=zhuangbei->query("sh_lvl"); 
                 sj_lvl=zhuangbei->query("sj_lvl");                      
          if (lvl <= sj_lvl || sj_lvl >= 13){        
   		 mess=HIC+"ºÏ³ÉµÄÅä·½ºÃÏñ²»Œ¦£¨ŒšÊ¯ÅcÑb‚äµÄµÈ¼‰²»·û£©¡£\n"+NOR;	
               return get_baoshi(1,mess);
}
        id = me->query("id");
	filename = ITEM_DIR + id[0..0] + "/" + id + 
		   "-" +me->query("id")+"'"+zhuangbei->query("id")+ ".c";
	if (file_size(filename) != -1)
	{
                mess=HIC+"ÄãÒÑ¾­ÓµÓĞÕâ¸ö×°±¸£¬±ğÌ«Ì°ĞÄÁË¡£¡£\n"+NOR;		
		return get_baoshi(1,mess);             
	 }
   /*---(·Ö×Ó/·ÖÄ¸) µ±·Ö×Ó>·ÖÄ¸Ôò³É¹¦ºÏ³É×°Åä--*/
   point=baoshi->query("point");   
   suss1=100-point;//·ÖÄ¸£¨µÈ¼¶Ô½¸ßÔò³É¹¦ÂÊÔ½µÍ£©
   suss=random(100); //·Ö×Ó
   if (sj_lvl >= 4 && sj_lvl <= 7)
     suss=random(90); //×°±¸µÈ¼¶>=4²¢ÇÒ<=7Ôò³É¹¦ÂÊÏÂ½µ5%
     suss -=suss/20;if (suss <=0) suss=1; 
else
   if (sj_lvl >= 7 && sj_lvl <= 9 )
     suss=random(80); ;//×°±¸µÈ¼¶>=7²¢ÇÒ<= 9Ôò³É¹¦ÂÊÏÂ½µ10%   
     suss -=suss/10;if (suss <=0) suss=1;
else
  if (sj_lvl >= 9 && sj_lvl <= 12 )
     suss=random(80); //×°±¸µÈ¼¶>=9²¢ÇÒ<= 12Ôò³É¹¦ÂÊÏÂ½µ5%    
     suss -=suss/20;if (suss <=0) suss=1; 
else
  if (sj_lvl >= 12 && sj_lvl <= 13 )
     suss=random(80); //×°±¸µÈ¼¶>=12²¢ÇÒ<= 13Ôò³É¹¦ÂÊÏÂ½µ3%  
     suss -=suss/30;if (suss <=0) suss=1; 
else
      suss=random(100); //×°±¸µÈ¼¶>=0²¢ÇÒ<= 3Ôò³É¹¦ÂÊ²»ÏÂ½µ  
 
   tell_object(me,HIY"³É¹¦ÂÊ£º"+(suss)+"/"+(suss1)+"\n"NOR);	      
   if (suss >= suss1) return get_baoshi(2,mess);//µÈ¼¶>=³É¹¦ÂÊ£¬Ôò³É¹¦ºÏ³É×°±¸
       else return get_baoshi(0,mess);//ºÏ³ÉÊ§°Ü£¬ËùÓĞéx³ÉÎïÆ·ÏûÊ§

}
int get_baoshi(int sta,string mess1)
{
   object me = this_player();
   object obj,ob = this_object();
   object baoshi;
   object zhuangbei;
   string mess, me_name,ob_name,zhuangbei_id;
   string item_filename;
   int i,k,sum,lvl,sjlvl,*kind=({0,0});
   mixed *inv;   

   me_name=me->name();
   ob_name=ob->name();
   inv = all_inventory(ob);
   mess=HIG+me_name+"¾õµÃ²î²»¶àÁË£¬ÊÕÆğÉñ¹¦£¬ÆÁ×¡ºôÎü£¬Ğ¡ĞÄÒíÒíµØ´ò¿ª"+ob_name+"\n";
   switch(sta)
   {
   	case 0://ºÏ³ÉÊ§°Ü
   		mess+=HIG+"µ«ÊÇ"+ob_name+HIG+"ÀïÃæ¿Õ¿ÕÈçÒ²£¬Ê²Ã´¶¼Ã»ÓĞ¡£\n"+NOR;
   		     for (k=0;k<sizeof(inv);k++)
          if (inv[0]->query("material")=="baoshi")
            {
              baoshi=inv[0];
              zhuangbei=inv[1];
                  }else{
              zhuangbei=inv[0];
              baoshi=inv[1];
                             }     
         zhuangbei_id = zhuangbei->query("id");       
         me->delete("can_summon/"+zhuangbei_id);//É¾³ı×°±¸ÕÙ»½¹¦ÄÜ       
         if (zhuangbei->query("sh_lvl")>0){            
            rm(base_name(zhuangbei)+ ".c");//É¾³ı×°±¸ÎÄ¼ş
	     DBASE_D->clear_object(zhuangbei);//É¾³ıÊı¾İ¿â¼ÇÂ¼
            }
                        destruct(zhuangbei);
                        destruct(baoshi); 
                me->add("ºÏ³É×°±¸/Ê§°Ü´ÎÊı",1);            
                //message("channel:chat",HIM"¡¾¿ÕÑ¨À´·ç¡¿£ºÌıËµ"+me_name+"ºÏ³É½ø»¯×°±¸Ê§°Ü£¬ËùÓĞ²ÄÁÏ¸¶Ö®Ò»¾æ¡£\n"NOR,users());
   		break;
      case 1://ºÏ³É²ÄÁÏ²»·ûºÏ
   		mess+=HIG+"·¢ÏÖÔ­À´ºÏ³ÉµÄ²ÄÁÏ»¹ÔÚÀïÃæ£¬Ö»ºÃÓÖŞÏŞÎµØÄÃÁË³öÀ´¡£\n"+NOR;
   		for (k=0;k<sizeof(inv);k++)
   			inv[k]->move(me);
              //message("channel:chat",HIM"¡¾¿ÕÑ¨À´·ç¡¿£ºÌıËµ"+me_name+"ºÏ³É½ø»¯×°±¸Ê§°Ü£¬»¹ºÃ£¬²ÄÁÏ»¹ÔÚ¡£\n"NOR,users());
   		break;
   	case 2://ºÏ³ÉÁ¶ÖÆ³É¹¦   		
   		 for (k=0;k<sizeof(inv);k++)
          if (inv[0]->query("material")=="baoshi")
            {
              baoshi=inv[0];
              zhuangbei=inv[1];
                  }else{
              zhuangbei=inv[0];
              baoshi=inv[1];
                             }
       obj=zhuangbei;
       lvl=zhuangbei->query("sh_lvl",1);
       lvl += 1;  
       if (lvl > 13) lvl=13;
       obj->set("item/wield_msg", zhuangbei->query("wield_msg"));
	obj->set("item/wear_msg", zhuangbei->query("wear_msg"));
	obj->set("item/unwield_msg", zhuangbei->query("unwield_msg"));
	obj->set("item/remove_msg", zhuangbei->query("remove_msg"));
	obj->set("item/name",   zhuangbei->query("name")+"[5m[1;32m¡¼ÒÑßM»¯¡½[2;37;0m");
	obj->set("item/id",  me->query("id")+"'"+zhuangbei->query("id"));
       obj->set("item/name1",   zhuangbei->query("name"));
	obj->set("item/id1", zhuangbei->query("id"));
       obj->set("item/unit",  zhuangbei->query("unit"));
	obj->set("item/point",  zhuangbei->query("point"));	
       obj->set("item/wscale", 3);       
       obj->set("item/stype", zhuangbei->query("stype"));
       obj->set("item/ctype", zhuangbei->query("ctype"));
       obj->set("item/value", zhuangbei->query("value"));
       obj->set("item/express", zhuangbei->query("express"));
       obj->set("item/sh_lvl", lvl);
       obj->set("item/type", zhuangbei->query("type"));
       obj->set("item/long", zhuangbei->query("long"));
       obj->set("material", zhuangbei->query("material"));
	obj->set("item/owner_name", me->query("name"));
	obj->set("item/owner_id", me->query("id"));
       if (zhuangbei->query("sj_lvl")){
       obj->set("item/sj_lvl", zhuangbei->query("sj_lvl"));      
       rm(base_name(zhuangbei)+ ".c");}
/*--------------------------------------ŒÙĞÔ»ù”µ---------------------------------------------*/
if (zhuangbei->query("armor"))
       obj->set("item/armor",  zhuangbei->query("armor"));
if (zhuangbei->query("attack1"))
       obj->set("item/attack1",  zhuangbei->query("attack1"));
if (zhuangbei->query("defense1"))
	obj->set("item/defense1", zhuangbei->query("defense1"));
if (zhuangbei->query("intelligence"))
	obj->set("item/intelligence",  zhuangbei->query("intelligence"));
if (zhuangbei->query("dexerity"))
	obj->set("item/dexerity",  zhuangbei->query("dexerity"));
if (zhuangbei->query("constitution"))
	obj->set("item/constitution",  zhuangbei->query("constitution"));
if (zhuangbei->query("strength"))
	obj->set("item/strength",  zhuangbei->query("strength"));
if (zhuangbei->query("karma"))
	obj->set("item/karma",  zhuangbei->query("karma"));
if (zhuangbei->query("personality"))
	obj->set("item/personality",  zhuangbei->query("personality"));
if (zhuangbei->query("dodge"))
	obj->set("item/dodge",  zhuangbei->query("dodge"));
if (zhuangbei->query("force"))
	obj->set("item/force",  zhuangbei->query("force"));
/*-----------------------------------------END------------------------------------------------*/
            if (item_filename = create_file(obj))
	{
                // clear the old item's data
                DBASE_D->set_object_data(obj, 0);
		destruct(obj);
                catch(call_other(item_filename, "???"));
		obj= find_object(item_filename);                
                if (! obj)
                {
                        message_vision("$NÒ»´ô£¬¶Ô$nµÀ£º±§Ç¸±§Ç¸£¡³öÁËÒ»Ğ©ÎÊÌâ£¡\n",
                                       this_object(), me);
                } else {
/*-----------------------------------ÌØÊâŒÙĞÔÙxÖµ---------------------------------------*/          
if (obj->query("armor"))
       obj->set("armor_prop/armor",  obj->query("armor")*lvl );
if (obj->query("attack1"))
       obj->set("armor_prop/attack1",  obj->query("attack1")*lvl );
if (obj->query("defense1"))
	obj->set("armor_prop/defense1", obj->query("defense1")*lvl );
if (obj->query("intelligence"))
	obj->set("armor_prop/intelligence",  obj->query("intelligence")*lvl );
if (obj->query("dexerity"))
	obj->set("armor_prop/dexerity",  obj->query("dexerity")*lvl );
if (obj->query("constitution"))
	obj->set("armor_prop/constitution",  obj->query("constitution")*lvl );
if (obj->query("strength"))
	obj->set("armor_prop/strength",  obj->query("strength")*lvl );
if (obj->query("karma"))
	obj->set("armor_prop/karma",  obj->query("karma")*lvl );
if (obj->query("personality"))
	obj->set("armor_prop/personality",  obj->query("personality")*lvl );
if (obj->query("dodge"))
	obj->set("armor_prop/dodge",  obj->query("dodge")*lvl );
if (obj->query("force"))
	obj->set("armor_prop/force",  obj->query("force")*lvl );
/*----------------------------------------END------------------------------------------*/
                obj->set("sj_lvl",lvl);//½ø»¯µÈ¼¶
	         obj->move(me);
                obj->save();             // Create the record in dbase               
		 log_file("static/item", sprintf("%s %s created  %s(%s)\n",
		          log_time(), log_id(me),
                 filter_color(obj->name(1)), obj->query("id")));
                 for (k=0;k<sizeof(inv);k++) 
                 destruct(inv[k]);
               me->add("ºÏ³É×°±¸/³É¹¦´ÎÊı",1);            
   		 mess+=HIG+"·¢ÏÖÀïÃæÒ»"+obj->query("unit")+obj->name()+HIG+"ÉÁÉÁ·¢¹â¡£\n";
   		 mess+=me_name+"ÆÈ²»¼±´ıµØÒ»°Ñ×¥ÁË³öÀ´¡£\n"+NOR;
                // message("channel:chat",HIM"¡¾¿ÕÑ¨À´·ç¡¿£ºÌıËµ"+me_name+"½ø»¯×°±¸³É¹¦£¬Á¶³ÉÁË"+obj->name()+"¡£\n"NOR,users());
		 break;
                }
          } 
  }
   mess+=mess1;
   tell_room(environment(me),mess);
   reload_object(ob);
   me->delete_temp("checking");
   return 1;	
}

// Éú³ÉµÀ¾ßÎÄµµ, ĞèÒªÒ»¸öµÄµÀ¾ßÔ­ÁÏ¶ÔÏó
// Éú³ÉÒÔºó½¨Á¢ ITEM_DIR/???.c È»ºóÉ¾³ı¾ÉµÄÔ­ÁÏ¶ÔÏó, Éú³ÉÒ»¼şĞÂµÄµÀ¾ß£¬·µ»ØÎÄ¼şÃû

// ¹ØÓÚÔ­ÁÏ¶ÔÏó¸÷¸öÊôĞÔµÄËµÃ÷(item/)
// ------ ÓÃ»§¿ÉÒÔÃèÊöµÄÊôĞÔ
// name		µÀ¾ßµÄÃû³Æ£¬ ±ØĞëÒª
// id			µÀ¾ßµÄID£¬   ±ØĞëÒª
// long		µÀ¾ßµÄÃèÊö£¬ÏµÍ³»áÔÚÉú³ÉµÀ¾ßÊ±×Ô¶¯Ìí¼Ó¹ØÓÚÁ¶ÖÆÔ­ÁÏµÄÃèÊö
// wield_msg		×°±¸ÎäÆ÷µÄÃèÊö£¬Èç¹ûÃ»ÓĞÏµÍ³»á×Ô¶¯Éú³É
// unwield_msg	ÊÕ»ØÎäÆ÷Ê±µÄÃèÊö
// wear_msg		´©ÉÏ»¤¼×Ê±µÄÃèÊö
// unwear_msg		ÍÑµô»¤¼×Ê±µÄÃèÊö

// ------ ²»ÊÇÓÃ»§ÃèÊöµÄÊôĞÔ
// owner_id		ÖÆÔìÕßµÄID
// owner_name       ÖÆÔìÕßµÄÃû×Ö
// unit		µ¥Î»
// type		µÀ¾ßµÄÀàĞÍ weapon »ò armor
// stype		µÀ¾ßµÄ×ÓÀà±ğ weapon Îª sword, blade, whip, stick £» armor Îª armor
// ctype		µÀ¾ßµÄÀà±ğµÄÖĞÎÄÃû weapon Îª ½£¡¢µ¶¡¢±Ş¡¢ÕÈ £» armor Îª »¤¼×
// value		µÀ¾ßµÄ¼ÛÖµ
// point             ÉËº¦Á¦

// ------ ËµÃ÷ÊÇÓÃ»§×ÔÁ·µÄµÀ¾ßµÄÊôĞÔ
// item_make		1

private string create_file(object item_temp)
{
	string	buf;			// Éú³ÉÎÄ¼şµÄ»º³åÇø
	string	filename;
       string  desc;
	int	i,desc_name,desc_id;
       mapping info;
       mapping apply;
       string  ih;
       string  id;
       string  mess;

	// Éú³ÉÎÄ¼şÃû
     if (!item_temp->query("item/sj_lvl"))//µÚÒ»´ÎºÏ³É
     {
       id = item_temp->query("item/owner_id");
	filename = ITEM_DIR + id[0..0] + "/" + id + 
		   "-" + item_temp->query("item/id") + ".c";
     }else{ 
       id = item_temp->query("item/owner_id");
	filename = ITEM_DIR + id[0..0] + "/" + id + 
		   "-" + item_temp->query("item/id1") + ".c";
        }
	if (file_size(filename) != -1)
	{
		write("ÎŞ·¨Éú³Éµµ°¸£¬ÇëÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		return 0;         
	}
        assure_file(filename);
	buf = "// ITEM Made by player(" + item_temp->query("item/owner_name") +
              ":" + item_temp->query("item/owner_id") + ") " + filename + 
	      "\n// Written by GAN JIANG(Doing Lu 1998/11/2)\t" + ctime(time()) + "\n";
        info = item_temp->query("item");
        ih = up_case(info["stype"]);
        apply = item_temp->query("armor_prop");      

	if (info["type"] == "weapon")//•º•r²»é_·ÅÎäÆ÷µÀ¾ß£¬Òò´ËÔÚÔ­Ê¼µÀ¾ß²»•şÔOÖÃtype=weapon£¬ß@˜ÓÎäÆ÷µÀ¾ßÎÄ¼şÒ²Ÿo·¨Éú³É¡£
	{
		// Éú³ÉÎäÆ÷µÀ¾ßÎÄ¼ş
		desc = "ÕâÊÇÓÉÁ¶ÖÆ¶ø³ÉµÄÒ»" +
		       info["unit"] + info["sh_lvl"] + "¡£\n";

                desc += info["long"];
                if (desc[strlen(desc) - 1] != '\n')
                        desc += "\n";

		desc += info["ctype"] + "±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º" +
		        info["owner_name"] + "(" + info["owner_id"] + ")\n";

		// ×Ô¶¯²¹³ä¿ÕĞÅÏ¢
		if (info["wield_msg"] == "")
		{
			info["wield_msg"] = HIC "$N" HIC "Ò»ÉùÇåĞ¥£¬¶¶³öÒ»" +
					    info["unit"] + HIC "$n" HIC "¡£" NOR;
		}

		if (info["unwield_msg"] == "")
		{
			info["unwield_msg"] = "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£";
		}
		buf += "#include <ansi.h>\n";
		buf += "#include <weapon.h>\n\n";
		buf += "inherit " + ih + ";\n";
                buf += "inherit F_NEWITEM;\n\n";
                buf += "void create()\n{\n";
		buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n", 
				info["name"], info["id"]);
		buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight() * item_temp->query("item/wscale") / 100);
		buf += sprintf("\tset(\"item_make\", 1);\n");
		buf += sprintf("\tset(\"unit\", \"%s\");\n", info["unit"]);
		buf += sprintf("\tset(\"long\", \"%s\");\n", desc);
		buf += sprintf("\tset(\"value\", %d);\n", info["value"]);
		buf += sprintf("\tset(\"point\", %d);\n", info["point"]);
		buf += sprintf("\tset(\"material\", \"%s\");\n", item_temp->query("material"));
		buf += sprintf("\tset(\"wield_msg\", \"%s\\n\");\n", info["wield_msg"]);
		buf += sprintf("\tset(\"unwield_msg\", \"%s\\n\");\n", info["unwield_msg"]);
		buf += sprintf("\trestore();\n");//È¡Ïû¸ÃÏî£¬ÒòÎª²»ÄÜautoload
		buf += sprintf("\tinit_%s(apply_damage());\n", info["stype"]);
                buf += prop_segment(info["prop"], "");
		buf += sprintf("\n\tsetup();\n}\n\n");
		// Éú³ÉÎäÆ÷µÀ¾ßÎÄ¼şÍê±Ï
	} else
	{
		// Éú³É·À»¤µÀ¾ßÎÄ¼ş

if (!info["sj_lvl"])//µÚÒ»´ÎºÏ³É
     {
		desc = HIR"ß@ÊÇÒÑ½›³É¹¦ßM»¯µÄÒ»" +
		       info["unit"] + info["ctype"]+ "¡£\n"NOR;

             desc += info["long"];
                if (desc[strlen(desc) - 1] != '\n')
                        desc += "\n";

		desc += info["ctype"] + "ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º" +
		        info["owner_name"] + "(" + info["owner_id"] + ")\n";

             desc_name = info["name"];
             desc_id = info["id"];
} else{  
             desc =info["long"]; 
             desc_name = info["name1"];
             desc_id = info["id1"];
}

		// ×Ô¶¯²¹³ä¿ÕĞÅÏ¢
		if (info["wear_msg"] == "")
		{
			info["wear_msg"] = YEL "$N" YEL "×°±¸" +
					   info["name"] + YEL "¡£" NOR;
		}
		if (info["remove_msg"] == "")
		{
			info["remove_msg"] = YEL "$N" YEL "ÍÑÏÂÁË" +
					     info["name"] + YEL "¡£" NOR;
		}
		buf += "#include <ansi.h>\n";
		buf += "#include <armor.h>\n\n";
		buf += "inherit " + ih + ";\n";
              buf += "inherit F_NEWITEM;\n\n";
              buf += "void create()\n{\n";
		buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n", 
				desc_name, desc_id);
		buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight() * item_temp->query("item/wscale") / 100);
              buf += sprintf("\tif( clonep() )\n\tset_default_object(__FILE__);\n\telse {\n");
		buf += sprintf("\tset(\"item_make\", 1);\n");
		buf += sprintf("\tset(\"unit\", \"%s\");\n", info["unit"]);
		buf += sprintf("\tset(\"long\", \"%s\");\n", desc);
		buf += sprintf("\tset(\"value\", %d);\n", info["value"]);
		buf += sprintf("\tset(\"point\", %d);\n", info["point"]);
		buf += sprintf("\tset(\"express\", \"%s\");\n", info["express"]);
		buf += sprintf("\tset(\"type\", \"%s\");\n", info["type"]);
                buf += sprintf("\tset(\"stype\", \"%s\");\n", info["stype"]);
                buf += sprintf("\tset(\"ctype\", \"%s\");\n", info["ctype"]);              
		buf += sprintf("\tset(\"sh_lvl\", %d);\n", info["sh_lvl"]);          
              //buf += sprintf("\tset(\"owner\", \"%s\");\n", info["owner_name"]);
              //buf += sprintf("\tset(\"user\", \"%s\");\n", info["owner_id"]);	
	        buf += sprintf("\tset(\"material\", \"%s\");\n", item_temp->query("material"));
		buf += sprintf("\tset(\"wear_msg\", \"%s\");\n", info["wear_msg"]);
		buf += sprintf("\tset(\"remove_msg\", \"%s\");\n", info["remove_msg"]);
		buf += sprintf("\trestore();\n");
           if (info["attack1"])
		buf += sprintf("\tset(\"attack1\", %d);\n", info["attack1"]);
           if (info["defense1"])
		buf += sprintf("\tset(\"defense1\", %d);\n", info["defense1"]);
           if (info["intelligence"])
		buf += sprintf("\tset(\"intelligence\", %d);\n", info["intelligence"]);
           if (info["dexerity"])
		buf += sprintf("\tset(\"dexerity\", %d);\n", info["dexerity"]);
           if (info["constitution"])
		buf += sprintf("\tset(\"constitution\", %d);\n", info["constitution"]);
           if (info["strength"])
		buf += sprintf("\tset(\"strength\", %d);\n", info["strength"]);
           if (info["armor"])
		buf += sprintf("\tset(\"armor\", %d);\n", info["armor"]);
           if (info["karma"])
		buf += sprintf("\tset(\"karma\", %d);\n", info["karma"]);
           if (info["personality"])
		buf += sprintf("\tset(\"personality\", %d);\n", info["personality"]);
           if (info["dodge"])
		buf += sprintf("\tset(\"dodge\", %d);\n", info["dodge"]);
           if (info["force"])
		buf += sprintf("\tset(\"force\", %d);\n", info["force"]);
              buf += sprintf("\t}\n");
		buf += sprintf("\n\tsetup();\n}\n\n");
		// Éú³É·À»¤µÀ¾ßÎÄ¼şÍê±Ï
	}
        buf += sprintf("string long() { return query(\"long\") + item_long(); }\n");

	if (save_item_file(filename, buf) == 1)
		return filename;

	return 0;
}

void do_temperature()
{
	if (this_object()->query("temperature") > 25) 
	{
		this_object()->add("temperature",-1);
	}	   
	else if (this_object()->query("temperature") < 25)
	{
		this_object()->add("temperature",1);
	}
	call_out("do_temperature", 2);
	
}
void do_checking()
{
	if (this_player()->query_temp("checking")) 
	{
		this_player()->delete_temp("checking");
              tell_object(this_player(),HIW"Äã·´Ó¦Ì«³Ù¶ÛÁË£¬ÏÂ´ÎÔÙÀ´ºÏ³É×°±¸°É£¡\n"NOR);
	}	   
	remove_call_out("do_checking");	
}

// add mapping
private string prop_segment(mapping p, string path)
{
        string buf;
        string *ks;
        int i;

        buf = "";
        if (! p) return buf;

        ks = keys(p);
        for (i = 0; i < sizeof(ks); i++)
        {
                // check the paramter's type
                if (mapp(p[ks[i]]))
                {
                        path += ks[i] + "/";
                        buf += prop_segment(p[ks[i]], path);
                } else
                        buf += sprintf("\tset(\"%s\", %s);\n",
                                       path + ks[i], (string)p[ks[i]]);
        }

        return buf;
}

// filename ÊÇĞ´ÈëÎÄµµµÄÃû³Æ£¬ÒÑ¾­°üº¬ÓĞÂ·¾¶
// content ÊÇĞ´ÈëÎÄµµµÄÄÚÈİ
private int save_item_file(string filename, string content)
{
	rm(filename);
	if (write_file(filename, content))
	{
                VERSION_D->append_sn(filename);
		return 1;
	} else
	{
		write("Ğ´Èëµµ°¸(" + filename + ")Ê±³ö´í£¬ÇëÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		return 0;
	}
}

