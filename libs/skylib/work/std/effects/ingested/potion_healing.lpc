#include <effect.h>

int beginning(object drinker, int strength, int id) {
  drinker->submit_ee(0, 1, EE_REMOVE);
  TCRE("shiannar", strength+" in beginning");
  return strength;
}

int merge(object drinker, int str_old, int str_new, int id) {
  TCRE("shiannar", str_old+str_new+" in merge");
  return str_old + str_new;
}

void end(object drinker, int strength, int id) {
  TCRE("shiannar", strength+" in end");
  tell_object(drinker, "Healing energy flows through you.\n"
              "If you don't like this message, deal.\n");
  drinker->adjust_hp(strength);
}
