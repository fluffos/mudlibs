// Cyanide
// 15 March 2000
// This efun capitzlizes the first letter in every word in the string.

#define EXCLUDE ({ "of" })

string cap_all_words( string str ) {    
    string *words;
    int i, sz;

    words = explode(str, " ");
    sz = sizeof(words);

    for (i=0; i<sz; i++) {
        if (member_array(words[i], EXCLUDE) != -1) continue;

        str = replace_string(str, words[i], capitalize(words[i]));
    }

    return str;
}                   