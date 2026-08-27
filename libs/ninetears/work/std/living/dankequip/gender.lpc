int gender;

int query_gender() { return gender; }

int query_female() { return gender == 2; }
int query_male() { return gender == 1; }
int query_asexual() { return !gender; }
int query_bisexual() { return gender == 3; }

  /* The next function is soley for compatibility with old code. */
  /* It should not be used in new source files. */
int query_neuter() { return !gender; }

string query_gender_string() {
  switch (gender) {
    case 0: return "asexual";
    case 1: return "male";
    case 2: return "female";
    case 3: return "bisexual";
  }
}

string query_gender_title() {
  switch (gender) {
    case 1: return "Sir";
    case 2: return "Lady";
    default: return "Creature";
  }
}
 
string query_objective() {
  switch (gender) {
    case 1: return "him";
    case 2: return "her";
    default: return "it";
  }
}
 
string query_possessive() {
  switch (gender) {
    case 1: return "his";
    case 2: return "her";
    default: return "its";
  }
}
 
string query_pronoun() {
  switch (gender) {
    case 1: return "he";
    case 2: return "she";
    default: return "it";
  }
}

// Bugfix by Aragorn 22/1/94
void set_gender(mixed arg) {
  if (stringp(arg)) {
    if (arg == "male" || arg == "1")
      gender = 1;
    else if (arg == "female" || arg == "2")
      gender = 2;
    else if (arg == "bisexual" || arg == "3")
      gender = 3;
    else
      gender = 0;
  } else {
    if (gender < 0)
      gender = 0;
    else if (gender > 3)
      gender = 3;
    else
      gender = arg;
  }
}
