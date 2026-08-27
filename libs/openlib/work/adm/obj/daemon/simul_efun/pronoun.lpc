#include <gender.h>

varargs
string
pronoun(object ob, int possessive)
{
  int sex = ob->query_gender();

  if(possessive) {
    switch(sex) {
    case GENDER_NEUTRAL:
      return "its";
    case GENDER_FEMALE:
      return "her";
    case GENDER_MALE:
      return "his";
    }
  } else {
    switch(sex) {
    case GENDER_NEUTRAL:
      return "it";
    case GENDER_FEMALE:
      return "she";
    case GENDER_MALE:
      return "he";
    }
  }

}
