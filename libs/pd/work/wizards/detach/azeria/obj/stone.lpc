#include <std.h>

inherit OBJECT;

int MANA;
int quick=0;
object owner;
void do_mana(int quickly);

void create()
{
    ::create();
    set_name("stone");
    set_mass(3);
set_short("%^BOLD%^%^BLUE%^S%^WHITE%^h%^YELLOW%^im%^RESET%^me%^YELLOW%^ri%^BOLD%^%^WHITE%^n%^BLUE%^g %^YELLOW%^S%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^n%^YELLOW%^e");
 set_long("This stone comes from the land of azeria it holds great power. "
          "To use the "          "power within the stone you must <rub> stone.");

 set_id( ({ "stone", "shimmering stone", "stonecheck" }) );

    MANA = random(12000)+12000;

}
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
    add_action("rub", "rub");
}

int rub(string str)
{
    if (environment(this_object())!=this_player())
        return 0;
    if (str!="stone") return notify_fail("rub what?\n");
    if (this_player()->query_paralyzed()) return notify_fail("You cannot do
that "
          "while paralyzed.\n");
    write("%^BOLD%^%^BLUE%^The stone floats above your head raining mana into your body!.");

    quick = 1;
    return 1;
}

string query_short()
{
 string str;

 str = ::query_short()+" ";
 if (MANA >= 11000)
   str += "(floating)";
  else
 if (MANA >= 10000)
   str += "(floating)";
  else
 if (MANA >= 9000)
   str += "(floating)";
  else
 if (MANA >= 8000)
   str += "(floating)";
  else
 if (MANA >= 7000)
  str += "(levitateing)";
 else
 if (MANA >= 6000)
  str += "(levitateing)";
 else
 if (MANA >= 5000)
  str += "(levitateing)";
 else
 if (MANA >= 4000)
  str += "(levitateing)";
 else
if (MANA < 3000)
  str += "(shimmering)";
 return str;
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
        message("info", "%^YELLOW%^The stone blows up raining spraks all over.", owner); 
        this_object()->remove();
        return;
    }
    if (random(100) > 40 )
        if (quickly && owner->query_mp() < owner->query_max_mp())
        {
            if (random(100) < 25)
            {
                owner->add_mp(500);
                MANA -= 500;
            }
            else
            {
                if (random(100) < 50)
                    owner->add_mp(300);
                MANA -= 300;
            }
            if (owner->query_mp() >= owner->query_max_mp())
                quickly = 0;
            return;
        }
    if (random(100) > 50)
    {
        owner->add_mp(20);
        MANA -= 20;
    }


}

int move(mixed dest)
{
    owner = environment(this_object());
    if (!owner) return ::move(dest);
    if (present("stonecheck 2", owner) &&
      owner->is_living())
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
