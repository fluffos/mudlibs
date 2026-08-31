// defines.h
// 010194: Beast: defines.h

#define ABS(_x)         ((_x)>=0?(_x):-(_x))
#define MAX(_x,_y)      ((_x)>=(_y)?(_x):(_y))
#define MIN(_x,_y)      ((_x)<=(_y)?(_x):(_y))
#define RETURN_INT1(_s) {write(_s); return 1;}
#define RETURN_INT0(_s) {write(_s); return 0;}
#define RETURN_VOID(_s) {write(_s); return;}
#define FAIL_INT0(_s)   {notify_fail(_s); return 0;}

#define PATH            "/players/beast/"
#define GM              "guild/master"
#define GUILDN          GM->query_number

#define TP              this_player()
#define TO              this_object()
#define PO              previous_object()
#define ENV             environment
#define CAP             capitalize
#define TELL            tell_object
#define TELLR           tell_room
#define MOVE            move_object
#define MOVEP           move_player

#define STR             query_str()
#define INT             query_int()
#define WIS             query_wis()
#define DEX             query_dex()
#define CON             query_con()
#define CHA             query_chr()
#define LEVEL           query_level()
#define ALIGN           query_alignment()
#define SP              query_sp()
#define MAXSP           query_max_sp()
#define HP              query_hp()
#define MAXHP           query_max_hp()
#define MONEY           query_money()
#define WORN            query_worn()
#define WIEL            query_wielded()
#define GUILD           query_guild()
#define IMMORTAL        query_immortal()
#define ATTACK          query_attack()
#define NAME            query_name()
#define SNAME           query_short_name()
#define RNAME           query_real_name()
 
#define ADDHP(x)        reduce_hit_point(-(x))
#define ADDSP(x)        restore_spell_points(x)

// end of defines.h
