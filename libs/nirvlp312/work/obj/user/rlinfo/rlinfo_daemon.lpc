#define RLINFO "obj/user/rlinfo/rlinfo_save"

mixed *characters;
mixed *ages;
mixed *genders;
mixed *names;
mixed *locations;
mixed *emails;
mixed *favorites;
mixed *quotes;
mixed *wwws;
mixed *ims;
mixed *miscs;
mixed *occupations;

mixed * initialize_abc_array(mixed *x);

void reset(int x)
{
  if(!restore_object(RLINFO))
  {
    characters = initialize_abc_array(characters);
    ages = initialize_abc_array(ages);
    genders = initialize_abc_array(genders); 
    names = initialize_abc_array(names); 
    locations = initialize_abc_array(locations); 
    emails = initialize_abc_array(emails); 
    favorites = initialize_abc_array(favorites); 
    quotes = initialize_abc_array(quotes);
    wwws = initialize_abc_array(wwws);
    ims = initialize_abc_array(ims);
    occupations=initialize_abc_array(occupations);
    miscs=initialize_abc_array(miscs);
  }
}

void save_me()
{
  save_object(RLINFO);
}

mixed * initialize_abc_array(mixed *x)
{
  int i;
  x = ({ });
  
  for(i = 0; i < 26; i ++)
  {
    x += ({ ({ }) });
  }
  
  return x;
}

int let(mixed x)
{
  return x[0]-97;
}

#define my_char(x) characters[let(x)]
#define my_age(x) ages[let(x)]
#define my_gender(x) genders[let(x)]
#define my_name(x) names[let(x)]
#define my_location(x) locations[let(x)]
#define my_email(x) emails[let(x)]
#define my_favorite(x) favorites[let(x)]
#define my_quote(x) quotes[let(x)]
#define my_www(x) wwws[let(x)]
#define my_im(x) ims[let(x)]
#define my_misc(x) miscs[let(x)]
#define my_occupation(x) occupations[let(x)]

int query_index(mixed nm)
{
  if(!nm) return -1;
  if(!my_char(nm)) return -1;
  return member_array(nm,my_char(nm));
}

mixed query_age(mixed nm)
{
  return (my_age(nm))[query_index(nm)];
}

mixed query_gender(mixed nm)
{
  return my_gender(nm)[query_index(nm)];
}

mixed query_name(mixed nm)
{
  return my_name(nm)[query_index(nm)];
}

mixed query_location(mixed nm)
{
  return my_location(nm)[query_index(nm)];
}

mixed query_email(mixed nm)
{
  return my_email(nm)[query_index(nm)];
}

mixed query_favorite(mixed nm)
{
  return my_favorite(nm)[query_index(nm)];
}

mixed query_quote(mixed nm)
{
  return my_quote(nm)[query_index(nm)];
}

mixed query_www(mixed nm)
{
  return my_www(nm)[query_index(nm)];
}

mixed query_im(mixed nm)
{
  return my_im(nm)[query_index(nm)];
}

mixed query_misc(mixed nm)
{
  return my_misc(nm)[query_index(nm)];
}

mixed query_occupation(mixed nm)
{
  return my_occupation(nm)[query_index(nm)];
}

void add_character(mixed nm)
{
  if(query_index(nm) == -1)
  {
    my_char(nm) += ({ nm });
    my_age(nm) += ({ 0 });
    my_gender(nm) += ({ 0 });
    my_name(nm) += ({ 0 });
    my_location(nm) += ({ 0 });
    my_email(nm) += ({ 0 });
    my_favorite(nm) += ({ 0 });
    my_quote(nm) += ({ 0 });
    my_www(nm) += ({ 0 });
    my_im(nm) += ({ 0 });
    my_misc(nm) += ({ 0 });
    my_occupation(nm) += ({ 0 });
    save_me();
  }
}

void delete_character(mixed nm)
{
  int i;
  if((i = query_index(nm)) > -1)
  {
    characters[let(nm)] = a_delete(i, characters[let(nm)]);
    ages[let(nm)] = a_delete(i, ages[let(nm)]);
    genders[let(nm)] = a_delete(i, genders[let(nm)]);
    names[let(nm)] = a_delete(i, names[let(nm)]);
    locations[let(nm)] = a_delete(i, locations[let(nm)]);
    emails[let(nm)] = a_delete(i, emails[let(nm)]);
    favorites[let(nm)] = a_delete(i, favorites[let(nm)]);
    quotes[let(nm)] = a_delete(i, quotes[let(nm)]);
    wwws[let(nm)] = a_delete(i, wwws[let(nm)]);
    
    save_me();
  }
}

string * query_wwws() { return wwws; }
void add_age(mixed nm, mixed age)
{
  my_age(nm)[query_index(nm)] = age;
  save_me();
}

void delete_age(mixed nm)
{
  my_age(nm)[query_index(nm)] = 0;
  save_me();
}

void add_gender(mixed nm, mixed gender)
{
  my_gender(nm)[query_index(nm)] = gender;
  save_me();
}

void delete_gender(mixed nm)
{
  my_gender(nm)[query_index(nm)] = 0;
  save_me();
}

void add_location(mixed nm, mixed location)
{
  my_location(nm)[query_index(nm)] = location;
  save_me();
}

void delete_location(mixed nm)
{
  my_location(nm)[query_index(nm)] = 0;
  save_me();
}

void add_name(mixed nm, mixed name)
{
  my_name(nm)[query_index(nm)] = name;
  save_me();
}

void delete_name(mixed nm)
{
  my_name(nm)[query_index(nm)] = 0;
  save_me();
}

void add_email(mixed nm, mixed email)
{
  my_email(nm)[query_index(nm)] = email;
  save_me();
}

void delete_email(mixed nm)
{
  my_email(nm)[query_index(nm)] = 0;
  save_me();
}

void add_favorite(mixed nm, mixed favorite)
{
  my_favorite(nm)[query_index(nm)] = favorite;
  save_me();
}

void delete_favorite(mixed nm)
{
  my_favorite(nm)[query_index(nm)] = 0;
  save_me();
}

void add_quote(mixed nm, mixed quote)
{
  my_quote(nm)[query_index(nm)] = quote;
  save_me();
}

void delete_quote(mixed nm)
{
  my_quote(nm)[query_index(nm)] = 0;
  save_me();
}

void add_www(mixed nm, mixed www)
{
  my_www(nm)[query_index(nm)] = www;
  save_me();
}

void delete_www(mixed nm)
{
  my_www(nm)[query_index(nm)] = 0;
  save_me();
}

void add_im(mixed nm, mixed im)
{
  my_im(nm)[query_index(nm)] = im;
  save_me();
}

void delete_im(mixed nm)
{
  my_im(nm)[query_index(nm)] = 0;
  save_me();
}

void add_misc(mixed nm, mixed misc)
{
  my_misc(nm)[query_index(nm)] = misc;
  save_me();
}

void delete_misc(mixed nm)
{
  my_misc(nm)[query_index(nm)] = 0;
  save_me();
}

void add_occupation(mixed nm, mixed occupation)
{
  my_occupation(nm)[query_index(nm)] = occupation;
  save_me();
}

void delete_occupation(mixed nm)
{
  my_occupation(nm)[query_index(nm)] = 0;
  save_me();
}
