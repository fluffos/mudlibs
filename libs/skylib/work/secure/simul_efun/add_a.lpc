#if !efun_defined(vowel)
/**
 * Determine if the input is a vowel.
 * @param i the int to check for vowelness
 * @return 1 if the int is a vowel, 0 if not
 */
int vowel( int i ) {
    switch( i ) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return 1;
      default:
        return 0;
    }
} /* vowel() */
#endif

#if !efun_defined(add_a)
/**
 * This method adds the 'a' or 'an' determinate to the input word.
 * @param str the string to add a/an to
 * @return the input string along with a/an prefix
 * @see /std/basic/desc->a_short()
 * @see /std/basic/desc->the_short()
 * @see /std/basic/desc->one_short()
 */
string add_a( string str ) {
    int i;

    while( str[i] == ' ')
        i++;

    if( vowel(str[i]) )
        return "an "+str[i..];
    return "a "+str[i..];

} /* add_a() */
#endif
