#define TIME 500

object shadowee;

void start_shadow(object ob)
{
    shadow(ob, 1);
    shadowee = ob;
    call_out("i_disappear", TIME);
}

void end_shadow()
{
    if(shadowee)
      shadow(shadowee, 0);
    destruct(this_object());
}

mixed move_player(string str)
{
    set_light(5);
    shadowee->move_player(str);
    set_light(-5);
}

mixed look(string str, int remote)
{
    set_light(5);
    shadowee->look(str, remote);
    set_light(-5);
}

void i_disappear()
{
    tell_object(shadowee, "Your luminous sight fades...\n");
    end_shadow();
}
