inherit "/u/zjb/suoha/suoha3";

void create()
{
  set("short", "¸ß¼¶Ëó¹ş¶şÊÒ");
        set("long", @LONG
ÕâÀï²¼ÖÃµÃÊ®·ÖºÀ»ªÆøÅÉ£¬µ±ÖĞÒ»ÕÅ¿í´óµÄÓñ×Á·½×À£¬·Å×ÅÒ»
¸±Õ¸ĞÂµÄÖ½ÅÆ¡£Á½±ßÊÇ¿í´óµÄôÃÆ¤Ä¾ÒÎ¡£Ò»¸ö¾«¸ÉµÄ»ï¼ÆÕ¾ÔÚ×ÀÅÔ
¸ºÔğ·¢ÅÆ¡£Ç½ÉÏ¹Ò×Å¼òµ¥µÄ¹æÔò(ruler)¡£
LONG
        );
    set("no_learn",1);
    set("no_fight",1);
        set("exits", ([ 
           "north" : "/u/zjb/suoha/roomnnn",
             "south" : "/u/zjb/suoha/roomn",]));
    set("item_desc",([
        "pai":(:look_pai:),
        "ruler":"\n¡¡¡¡×øÏÂ(sit)¿ªÊ¼,²»Ïë´òÁË¾ÍÀë¿ª(leave)\n"
"¡¡¡¡Ëµ»°·½Ñº(ya)£¬¸ú»°·½¸ú(gen)£¬²»Ñº(buya)¾ÍÊÇÈÏÊä\n"
"¡¡¡¡×îºóÒ»ÅÆ¿ÉÒÔÈ«Ëó(showhand)£¬¾ßÌåÇëhelp suoha\n\n",
    ]));

        setup();
}

void init()
{
    object me=this_player();
    add_action("buyma","buyma");
    add_action("do_yazhu","ya");
    add_action("do_gen","gen");
    add_action("do_buya","buya");
    add_action("do_da","da");
    add_action("do_sit","sit");
    add_action("do_leave","leave");
    add_action("do_quansuo","showhand");
    add_action("check_chouma","chakan"); 
    add_action("duihuan","duihuan");}

int buyma(string arg)
{
 int money;
    object me = this_player();

if (!arg) return notify_fail("ÄãÒªÄÃĞÇ¿Õ±ÒÂò¶àÉÙ¸ö³ïÂë!\n");
    else    if(!sscanf(arg, "%d", money))
return notify_fail("buyma <ÊıÁ¿>!\n") ;  
if (money<1)  return notify_fail("ÖÁÉÙÒªÂòÒ»¸ö³ïÂë!\n");
if (money>500) return notify_fail("Ò»´Î×î¶àÖ»ÄÜÂò500¸ö³ïÂëÒ!\n");
if (me->query("zjb_money",1) < 1)  return notify_fail("ÄãÃ»ÓĞÕâÃ´¶àĞÇ¿Õ±ÒÀ´Âò!\n");
if (money>me->query("zjb_money",1)) return notify_fail("ÄãÃ»ÓĞÕâÃ´¶àĞÇ¿Õ±ÒÀ´Âò³ïÂë!\n");

            me->add("zjb_money",-money);
me->add_temp("duchang_chouma",money);  
return notify_fail(HIB"ÄãÈ¡³ö"+money+"Ã¶ĞÇ¿Õ±Ò£¬»»ÁË³ïÂë£¬×¼±¸"HIR"Ëó¹ş"HIB"!\n");
} 
int duihuan(string arg)
{
 int money;
 object me = this_player();

if (!arg) return notify_fail("ÄãÒªÄÃ¶àÉÙ¸ö³ïÂë»»³ÉĞÇ¿Õ±Ò!\n");
    else    if(!sscanf(arg, "%d", money))
return notify_fail("duihuan <ÊıÁ¿>!\n") ;  
if (money<1)  return notify_fail("ÖÁÉÙÒª¶Ò»»Ò»¸ö³ïÂë!\n");
if (me->query_temp("duchang_chouma",1) < 1)  
return notify_fail("ÄãÃ»ÓĞÕâÃ´¶à³ïÂëÀ´»»ò!\n");
if (money>me->query_temp("duchang_chouma",1)) 
return notify_fail("ÄãÃ»ÓĞÕâÃ´¶à³ïÂëÀ´»»!\n");
if (me->query_temp("suoha"))
return notify_fail("ÄãÕıÔÚËó¹ş£¬»»²»ÁËÇ®!\n");


me->add("zjb_money",money);
me->add_temp("duchang_chouma",-money);  
return notify_fail(HIG"ÄãÈ¡³ö"+money+"¸ö"HIW"³ïÂë"HIG"£¬»»³ÉÁË"HIB"ĞÇ¿Õ±Ò"HIG"!\n");
} 


