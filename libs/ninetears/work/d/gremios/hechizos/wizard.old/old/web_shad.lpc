/* shadows things that are webbed! */
object shadowed;
int strength;

void setup_shadow(object ob, int s)
{
  shadowed = ob;
  strength = s;
  shadow(shadowed, 1);
}

void dest_web_shadow()
{
  destruct(this_object());
}

int set_strength(int i) { return strength = i; }

int move_player(string dir, string dest, varargs mixed message)
{
  strength -= (int)this_player()->query_str();
  if(strength < 0) {
    write("You finally break your bonds, and clamber to your feet.\n");
    say((string)shadowed->query_cap_name() + " bursts from the web fibres " 
      "binding " + (string)shadowed->query_objective() + ".\n");
    shadowed->move_player(dir, dest, message);
    dest_web_shadow();
    return 1;
  }
  write("You struggle against your bonds, but you have trouble standing up, " 
    "let alone walking right out of here!\n");
  say((string)shadowed->query_cap_name() + " struggles against the web " 
    "that binds " + (string)shadowed->query_objective() + ".\n");
}

