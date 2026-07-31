// ²è¿Íå /d/city/chuzhou/npc/chake.c
// by lala, 1997-12-14

inherit NPC;

string *name = ({
"ÖÜÑÓÈå", "Ç®ÏóÀ¤", "ÎÂÌåÈÊ", 
     });
void create()
{
    set_name( name[random(sizeof(name))], ({ "cha ke", "chake", }) );
    set( "gender", "ÄĞĞÔ" );
    set( "age", 45 );
    set( "long", @LONG
ÕâÊÇ±¾³ÇµÄÒ»Î»ÏĞ¾ÓµÄÏçÉğ£¬ÒÔÇ°×ö¹ıĞ©Ğ¡¹Ù£¬ÏÖÔÚ¼ÒÎŞÊÂ£¬Ã¿ÈÕÀ´Åİ²è¹İ¡£Ëû
ÃÇÕâĞ©ÈËµÄÏûÏ¢×îÊÇÁéÍ¨¡£
LONG
    );
    set("combat_exp", 5000);
    set("social_exp", 15000);
    set("positive_score", 500);
    set("negative_score", 100);
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);

    setup();
          
    carry_object( "/clone/misc/cloth")->wear();
    add_money( "coin", 100 + random(50) );
}          

void init()
{
   object me = this_player();
   object ob = this_object();
   int relative;

   if ( userp( me )
     && relative = me->query_marks( "marks/chuzhou/" + ob->query("name") ) 
        > 0 )
        call_out( "greeting", 2, me, ob, relative );
}

void greeting( object me, object ob, int relative )
{
    string str;

    switch( random( relative/10 ) )
    {
        case 0:
            str = "$NÒ»×ªÍ·£¬¿´¼û$n×ß½øÀ´£¬µãµãÍ·£¬ËãÊÇ´òÕĞºôÁË¡£\n";
            break;
        case 1:
            str = "$NÕıÂñÍ·ºÈ²è£¬Ò»Ì§Í·£¬¿´¼û$nÕ¾ÔÚËûÃæÇ°£¬Ğ¦ÁËÒ»Ğ¦¡£\n";
            break;
        case 2:
            str = "$nÒ»×ß½ø²èËÁ£¬¾Í¿´¼û$NÕıÔÚ¶Ô×Ô¼º´òÕĞºô£º¡°ºÃ¾Ã²»¼û°¡¡±\n";
            break;
        case 3:
            str = "$N¿´¼û$n×ß½øÀ´£¬¸ÏÃ¦Õ¾ÆğÀ´Ëµ£º¡°½ñÈÕÏà·ê£¬ĞÒ»áĞÒ»á£¡¡±\n";
            break;
        case 4:
            str = "$NÒ»¿´¼û$n£¬¾ÍÉÏÇ°ĞĞÀñ£º¡°°¥Ñ½£¬ÔõÃ´½ñÌìÄúÓĞ¿ÕÀ´°¡£¡¡±\n";
            break;
        default:
            str = "$NÒ»°Ñ×¥×¡$nµÄĞä×Ó£¬´óÉùµÄËµ£º¡°Ñ½£¬ÕâÊÇÊ²Ã´·ç°ÑÄã´µÀ´À²£¿£¡¡±\n";         
            break;
    }
    message_vision( str, ob, me );
}
