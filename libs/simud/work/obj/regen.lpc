int size, speed;
string type;
object vict;

void set_size(int x) { size = x; }
void set_speed(int x) { speed = x; }
void set_type(string x) { type = x; }

void tick() {
   if (!vict->query_is_living())
      destruct(this_object());
   switch (type) {
      case "mana":      vict->add_mana(speed); break;
      case "endurance": vict->add_endurance(speed); break;
      default:          vict->add_hp(speed);
   }
   msg_object(vict,"You feel energy returning to your body.");
   size -= speed;
   if (speed >= size)
      speed = size;
   if (size <= 0)
      destruct(this_object());
   call_out("tick",5);
}

void start(object who) {
   vict = who;
   move_object(this_object(),vict);
   tick();
}
