/* String manipulation code. #include this file into your objects if you
 * wish to make use of these functions.
 *
 * Available now:
 * ==============
 *
 * string pronoun_sub(object1, string1)
 *
 * Returns a string with the proper pronouns for object1 substituted for the
 * codes in string1. For example: "%N has lost %p marbles" becomes "Igor has
 * lost his marbles". The substitution is done for the following codes:
 * 
 * %a   absolute possessive     his, hers, its
 * %s   subjective              he, she, it
 * %o   objective               him, her, it
 * %p   possessive              his, her, its
 * %r   reflective              himself, herself, itself
 * %n   player's name
 *
 * Capitalizing these (like %N) will result in the substitution being 
 * capitalized too. 
 *
 *
 * string subst(string1, string2, string3)
 * 
 * Substitutes all occurrences of string2 with string3 in string1.
 * Example: subst("Big_hairy_taxman", "_", " ") will return 
 * "Big hairy taxman". You can nest subst at will, but you'll find the example
 * given in the code of pronoun_sub() hideous!
 * 
 *
 * int strfind(string1, string2)
 * 
 * Finds the first occurence of string2 in string1 and returns the relative
 * character position (Character 0 is first character. Returns the length of
 * string1 if string2 is not found.
 * Example: strfind("Bo smiles." "smiles") returns 3.
 */
 
 
subst(source, old, new){
    string result;
    
    source="#%^"+source+old;
    source=explode(source, old);
    source=implode(source, new);
    result=extract(source, 3);
    return result;
}

strfind(source, find){
    int position;
    
    for(position=0; strlen(source); position++)
        if(extract(source, position, strlen(find))==find) 
           return position;
    
    return position;
}        

pronoun_sub(who, source){
    string result, name, absolute, subjective, objective;
    string possessive, reflexive;
    int gender;
    
    name=who->query_cap_name();
    if(!name) name=who->query_name();
    if(!name && who->short()) name=capitalize(who->short());
    if(!name && query_ip_number(who)) name="Someone";
    if(!name) name="Something";
    gender=who->query_gender();
    if(!gender){
       absolute="its"; subjective="it"; objective="it"; 
       possessive="its"; reflexive="itself";
       }
    if(gender==1){   
       absolute="his"; subjective="he"; objective="him"; 
       possessive="his"; reflexive="himself";
       }
    if(gender==2){
       absolute="hers"; subjective="she"; objective="her"; 
       possessive="her"; reflexive="herself";
       }
    result=subst(subst(subst(subst(subst(subst(subst(subst(subst(subst
           (subst(subst(source, "%N", name), "%n", lower_case(name)), 
           "%a", absolute), "%A", capitalize(absolute)), "%s", subjective), 
           "%S", capitalize(subjective)), "%o", objective), 
           "%O", capitalize(objective)), "%p", possessive), 
           "%P", capitalize(possessive)), "%r", reflexive), 
           "%R", capitalize(reflexive));
    return result;
}    
