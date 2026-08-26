// An attempt to put all the grammar/gender related stuff in one file.  -Beek
// 0 = neuter, 1 = male, 2 = female.  Anything else, you're weird.

int gender;

//:FUNCTION set_sex
//Set the object's sex.  0 == neuter, 1 == male, 2 == female
void set_sex(int sex)
{
/*
   if (this_body() && (this_body() != this_object()) && (wizardp(this_body()->query_userid()) < 3))
   {
      error("Invalid attempt to set " + this_object()->short() + "'s sex from " + gender + " to " + sex + ".\n");
   }
*/

   gender = sex;
}

//:FUNCTION set_gender
//Set the object's sex.  0 == neuter, 1 == male, 2 == female
void set_gender(int sex)
{
   set_sex(sex);
//   error("Use set_sex instead!");
}

//:FUNCTION query_sex
//Query an object's sex
int query_sex() { return gender; }

//:FUNCTION query_gender
//Query an object's sex
int query_gender() { return gender; }

//:FUNCTION query_sex_string
//Query the string representation of an objects sex
string query_sex_string()
{
   switch(gender)
   {
      case 1: return "male";
      case 2: return "female";
      default: return "neuter";
   }
}

//:FUNCTION query_gender_string
//Query the string representation of an objects sex
string query_gender_string()
{
   switch(gender)
   {
      case 1: return "male";
      case 2: return "female";
      default: return "neuter";
   }
}

//:FUNCTION query_pronoun
//Return the (subjective) pronoun of a object (he, she, it)
string query_pronoun()
{
   switch (gender)
   {
      case 0: return "it";
      case 1: return "he";
      case 2: return "she";
   }
}

//:FUNCTION query_objective
//return the objective pronoun of an object (it, him, her)
string query_objective()
{
   switch (gender)
   {
      case 0: return "it";
      case 1: return "him";
      case 2: return "her";
   }
}


//:FUNCTION query_subjective
//return the subjective pronoun of an object (he, she, it)
string query_subjective() { return query_pronoun(); }

//:FUNCTION query_possessive
//return the possessive pronoun of an object (his, her, its)
string query_possessive()
{
   switch (gender)
   {
      case 0: return "its";
      case 1: return "his";
      case 2: return "her";
   }
}

//:FUNCTION query_named_possessive
//return the named possessive of an object (Foo's)
string query_named_possessive()
{
   string res;
   res = this_object()->query_name();

   if (res[<1]=='s') { return res + "'"; }
   else { return res + "'s"; }
}

//:FUNCTION query_reflexive
//return the reflexive pronoun of an object (himself, herself, itself)
string query_reflexive()
{
   switch(gender)
   {
      case 0: return "itself";
      case 1: return "himself";
      case 2: return "herself";
   }
}