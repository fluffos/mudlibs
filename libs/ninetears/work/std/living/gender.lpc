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
    case 1: return "varon";
    case 2: return "mujer";
    case 3: return "hermafrodita";
  }
}

string query_gender_title() {
  switch (gender) {
    case 1: return "Sir";
    case 2: return "Lady";
    default: return "Criatura";
  }
}
 
string query_objective() {
  switch (gender) {
    case 1: return "el";
    case 2: return "ella";
    default: return "ello";
  }
}
 
string query_possessive() {
  return "su";
/*  switch (gender) {
    case 1: return "su";
    case 2: return "su";
    default: return "su";
  } */
}
 
string query_pronoun() {
  switch (gender) {
    case 1: return "el";
    case 2: return "ella";
    default: return "ello";
  }
}

// Bugfix by Aragorn 22/1/94
void set_gender(mixed arg) {
  if (stringp(arg)) {
    if (arg == "varon" || arg == "1")
      gender = 1;
    else if (arg == "mujer" || arg == "2")
      gender = 2;
    else if (arg == "hermafrodita" || arg == "3")
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

string query_vocal() { return (gender==2?"a":"o"); }