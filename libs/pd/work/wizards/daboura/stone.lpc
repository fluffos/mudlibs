// MP REGEN STONE... seeker
/* 12-11-2000
 *     Found a problem in stones where the heart beats were not turned
 *     off in the un-used stones and filled up the heartbeat processing
 *     which in turn lagged the living crap out of the mud. It should be
 *     fine now since i re-wrote it so the first object is the ONLY one 
 *     that has a heart beat and it controls the following 3 stones,
 *     and the rest just sit there. The heart_beat is passed on to the 
 *     second stone if the first one is move()'d or remove()'d from the
 *     player. Also there is no heart beat if the owner is non-living.
 *     [seeker]
**/
// Modified to be inherited by Nightshade
#include <std.h>
inherit OBJECT;
int MANA;
int quick=0;
object owner;
void do_mana(int quickly);
string _RemoveMsg, *_Levels, _Action, _RubMsg;
void create()
{
    ::create();
    _Levels = ({"Disappearing"});
    _RemoveMsg = "It disappears.";
    set_no_clean(1);
    _Action = "rub";
    _RubMsg = "You feel the mana fill your body.";
    MANA = random(3800)+3800;
}
int set_id(string *str) {
  str += ({"stonecheck"});
  return ::set_id(str);
}
void set_remove_mess(string str) { _RemoveMsg = str; }
void set_use_mess(string str) { _RubMsg = str; }
void set_action(string str) { _Action = str; }
void set_levels(string *str) { _Levels = str; }
int query_mana() { return MANA; }
int query_quick() { return quick; }
int set_mana(int x) { MANA = x; return x; }
int add_mana(int x) { MANA += x; }
int set_heart()     { set_heart_beat(1); }

void init()
{
    owner = environment(this_object());
    ::init();
    if (owner)
        if (present("stonecheck", owner)==this_object()) 
            set_heart_beat(1);
    add_action("rub", _Action);
}

int rub(string str)
{
    if (environment(this_object())!=this_player())
        return 0;
    
    if (!str) return 0;
    
    if (!(member_array(str,this_object()->query_id())+1)) return
        notify_fail(capitalize(_Action)+" what?\n");
        
    if (this_player()->query_paralyzed()) return notify_fail("You cannot do that "
        "while paralyzed.\n");
          
    if (this_player()->query_disable()) {
       write("You are busy.");
       return 1;
    }
    
    write(_RubMsg);
    this_player()->set_disable();
    quick = 1;
    return 1;
}

string query_short()
{
    string str;
    int i;
    str = ::query_short()+" (";
    i = sizeof(_Levels);
    if (MANA >= 5000) {
        str += _Levels[i-1];
        return str+")";
    }
    for(int x = i - 2;x >= 0;x--) {
        if (MANA >= (5000*(x))/(i-1)) {
            str += _Levels[x];
            break;
        }
    }
    return str+")";
}

void heart_beat()
{
    object ob2,ob3;
    owner = environment(this_object());
    if (!owner) return;
    if ((present("stonecheck", owner)!=this_object()) || 
      (!owner->is_living()))
    {
        set_heart_beat(0);
        return;
    }
    ob2 = present("stonecheck 2", owner);
    ob3 = present("stonecheck 3", owner);
    /* --- Give mana to the player --- */
    do_mana(quick);
    if (ob2) ob2->do_mana(quick);
    if (ob3) ob3->do_mana(quick);
}

void do_mana(int quickly)
{
    owner = environment(this_object());
    if (!owner->is_living())
    {
        if (random(100) > 50)
            MANA -= 5;
        if (MANA > 0) return;
    }
    if (MANA <= 0)
    {
        message("info", _RemoveMsg, owner); 
        this_object()->remove();
        return;
    }
    if (random(100) > 15 )
        if (quickly && owner->query_mp() < owner->query_max_mp())
        {
            if (random(100) < 25)
            {
                owner->add_mp(155);
                MANA -= 200;
            }
            else
            {
                if (random(100) < 35)
                    owner->add_mp(70);
                else
                    owner->add_mp(50);
                MANA -= 100;
            }
            if (owner->query_mp() >= owner->query_max_mp())
                quickly = 0;
            return;
        }
    if (random(100) > 50)
    {
       owner->add_mp(15);
        MANA -= 20;
    }
}
int move(mixed dest)
{
    owner = environment(this_object());
    if (!owner) return ::move(dest);
    if (present("stonecheck 2", owner) && owner->is_living())
        present("stonecheck 2", owner )->set_heart();
    return ::move(dest);
}
int remove()
{
    owner = environment(this_object());
    if (!owner) return ::remove();
    if (present("stonecheck 2", owner) &&
      owner->is_living())
        present("stonecheck 2", owner )->set_heart();
    return ::remove();
}
int query_heart() { return query_heart_beat(this_object()); }

