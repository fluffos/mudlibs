/* if you're using a standard guild object with functions all
   in it, this stuff goes right smack in it */

#define SHADOW "/open/stark/lightob"

int Lighted;

status light_spell(string str)
{
    object shadow;
    if(str) return 0;
    if(Lighted)
    {
      notify_fail("You are currently enjoying the powers of this spell...\n");
      return 0;
    }
    write("You cast a spell of Light...\n");
    tell_room(environment(this_player()), 
     (string)this_player()->query_name() + " casts a spell of Light...\n", ({ this_player() }));
    shadow = clone_object(SHADOW);
    shadow->start_shadow(this_player());
    Lighted = 1;
    return 1;
}

mixed Lighted(int x) 
{
    if(!x) return Lighted;
    Lighted = x; 
}
