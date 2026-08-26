
int gender;

int query_neuter(){ 
   return !gender;
} /* query_neuter() */

int query_male(){
 return gender==1;
} /* query_male() */

int query_female(){
   return gender == 2;
} /* query_female() */

int query_gender(){
   return gender; 
} /* query_gender() */

string query_gender_string() {

    switch(gender){
       case 1: return "male";
       case 2: return "female";
       default: return "neuter";
    }
} /* query_gender_string() */

string query_gender_title() {

    switch(gender){
       case 1: return "sir";
       case 2: return "madam";
       default: return "creature";
    }
} /* query_gender_title() */

string query_gender_name() {

    switch(gender){
       case 1: return "man";
       case 2: return "woman";
       default: return "neuter";
    }
} /* query_gender_name() */

string query_objective() {

    switch(gender){
       case 1: return "him";
       case 2: return "her";
       default: return "it";
    }
} /* query_objective() */

string query_possessive() {

    switch(gender){
       case 1: return "his";
       case 2: return "her";
       default: return "its";
    }
} /* query_possive() */

string query_pronoun() {
    switch(gender){
       case 1: return "he";
       case 2: return "she";
       default: return "it";
    }
} /* query_pronoun() */

void set_gender(mixed arg) {

  if(stringp(arg)){
    switch(lower_case(arg)){
       case "male":
          gender = 1;
          break;
       case "female":
          gender = 2;
          break;
       default:
          gender = 0;
          break;
    }
  }else{
    gender = arg;
  }
} /* set_gender() */
