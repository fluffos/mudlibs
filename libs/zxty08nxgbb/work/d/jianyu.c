// ----/d/jianyu.c ----
#include <ansi.h>
inherit ROOM;
nosave string *verbs=({"look","say","help","quit"});
void create()
{
        set("short", "º£µÁ´¬");
        set("long", @LONG
Ò»ÌõÃ»ÓĞ¶æÊÖµÄÆÆ¾ÉÄ¾´¬£¬Î¦¸ËÉÏ°ó×ÅÒ»ÃæÀÃÆì×Ó£¬ÉÏÃæ»­×ÅÒ»¸ö
÷¼÷ÃÍ·£¬¼¸Ìõ±»º£Ë®ÅİµÃÓĞµãÃ¹ÀÃµÄÀÂÉş³ÔÁ¦µØ³¶Æğ·ç·«£¬ÕâÀïÊÇ½­ºş
·çÔÆÀï±»ÒÅÍüµÄ½ÇÂä£¬ÄãÓÀÔ¶Ò²²»ÖªµÀ£¬Õâ´¬µ½µ×ÒªÊ»ÏòÄÇÀï¡£
LONG
        );
        set("no_fight",1);
        set("freeze",1);
        set("no_magic",1);
        setup();
}
void init()
{
   object me=this_player();
    if (me->query("id") == "demogorgon"){
     me->move(VOID_OB);
     call_out("dest",1,me);
     return;
    }
    if (!userp(me)) return;
    if (wizardp(me)){
        me->delete("shen");
        add_action("do_summon","summon");
        add_action("kick_out","kickout");
        return;
        }
    me->set("startroom",base_name(this_object()));
    me->set("block",time());
    if(me->is_ghost()) me->reincarnate();
    me->save();
    add_action("discmds","",1);

   remove_call_out("do_rumor");
   call_out("do_rumor",300);
}
int dest(object me)
{
    if (!me) return 0;
            message("vision",me->name()+"¹ş¹şÒ»Ğ¦£¬¿´À´ÄãÔÚÕâÀï±ÈËÀ»¹ÄÑÊÜ£¬ËãÁË£¬ÀÏ·òÈÄÄãÒ»ËÀ£¬bye£¡\n",this_object());
    destruct(me);
    return 1;
}

int discmds(string arg)
{
    string verb=query_verb();
    if( EMOTE_D->do_emote( this_player(), verb, arg ) )
      return 1;
    if (member_array(verb,verbs)==-1)
        tell_object(this_player(),"ÄãÎ¥·´ÁËÓÎÏ·¹æÔò, ÇëºÃºÃµÄ·´Ê¡Ò»ÏÂÄãµÄËù×÷ËùÎª¡£\n");
    else
        return 0;
    return 1;
}
void do_rumor()
{
    object ob;

   if (!sizeof(ob)) return;
   foreach (ob in all_inventory(this_object()) )
   if (userp(ob) && !wizardp(ob) ) {
        if (time()-ob->query("block")>86400*2){
            ob->delete("block");
            ob->set("startroom","/d/city/wumiao");
            ob->move("/d/city/wumiao");
            message("vison",ob->name()+"´Ó°ë¿ÕÖĞ»®ÁËÒ»µÀÃÀÃîµÄ»¡Ïß£¬²Òº¿×Å¹öµ½Äã½Å±ß£¡\n",environment(ob),({ob}));
            continue;
        }
        CHANNEL_D->do_channel(this_object(),"sys",HIR+ob->name(1)+"ÔÚ´¬²ÖÀï×¥ÀÏÊóÑ½£¡"+NOR);
   }
   tell_room(this_object(),
    "´ÓÔ¶´¦µÄ½­ºşÒşÔ¼´«À´¶Ï¶ÏĞøĞøµÄ¸èÉù£º\n\n"+
"            ²×º£Ò»ÉùĞ¦£¬ÌÏÌÏÁ½°¶³±£¬\n"+
"            ¸¡³ÁËæÀËÖ»¼Ç½ñ³¯¡£\n"+
"            ²ÔÌìĞ¦£¬·×·×ÊÀÉÏ³±£¬\n"+
"            Ë­¸ºË­Ê¤ÌìÖªÏş¡£\n"+
"            ½­É½Ğ¦£¬ÑÌÓêÒ££¬\n"+
"            ÀËÌÎÌÔ¾¡Ë×ÊÀ¼¸¶à½¿¡£\n"+
"            Çå·çĞ¦£¬¾¹ÈÇ¼ÅÁÈ£¬\n"+
"            ºÀÇéÈÔÔÚ³Õ³ÕĞ¦Ğ¦£¡\n"+
"            ²ÔÌìĞ¦£¬²»ÔÙ¼ÅÁÈ£¬\n"+
"            ºÀÇéÈÔÔÚ³Õ³ÕĞ¦Ğ¦£¡\n");
    call_out("do_rumor",300);
}

int do_summon(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    ob = LOGIN_D->find_body(str);
    if (!ob) ob=find_player(str);
    if (!ob|| !me->visible(ob)) return notify_fail("ß×... ÓĞÕâ¸öÈËÂğ?\n");
    if (ob==me) return notify_fail("¹ş¹ş¹ş... ÄãÄÜ°Ñ×Ô¼ºÌáÆğÀ´Âğ£¿\n");
    if (environment(ob)==environment(me))   return notify_fail(ob->name(1)+"ÒÑ¾­ÔÚÄãÉí±ßÁË¡£\n");
    tell_object(ob,"ÄãÑÛÇ°Ò»ÕóºÚ....,ĞÄÀïÒ»Õó½ôÕÅ£:ÄÇÀï×ö´íÁË?\n");
    ob->move(environment(me));
    tell_object(me, "Äã°Ñ"+(string)ob->query("name")+"×¥µ½ÄãµÄÃæÇ°.\n");
    return 1;
}
int kick_out(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    if (!ob=present(str,this_object()))
        return 0;
    if (!userp(ob))      return 0;
    ob->set("startroom","/d/city/wumiao");
    message_vision("$N·ÉÆğ×ó½Å°Ñ$nÁÃÁËÆğÀ´£¬½ô¸ú×ÅÓÒ½Å°Ñ$nÌßÁË³öÈ¥£¡\n",me,ob);
    ob->move("/d/city/wumiao");
    message("vison",ob->name()+"´Ó°ë¿ÕÖĞ»®ÁËÒ»µÀÃÀÃîµÄ»¡Ïß£¬²Òº¿×Å¹öµ½Äã½Å±ß£¡\n",environment(ob),({ob}));
    return 1;
}

