//===========================================================================
//  parse_command() Support
//
// LPMud has a builtin support for parsing complex commands.
// It does this by requesting several types of ids from the objects
// The same queried functions are also in the master to provide decent
// defaults, especially for generic ids like 'all the blue ones'.
//
// Each of the functions has to return an array of string (with the exception
// of parse_command_all_word), each string being one of the ids for that type
// of id.
//
//===========================================================================

//---------------------------------------------------------------------------
string *parse_command_id_list ()

// Return generic singular ids.

{
  return ({ "one", "thing" });
}

//---------------------------------------------------------------------------
string *parse_command_plural_id_list ()

// Return generic plural ids.

{
  return ({ "ones", "things", "them" });
}


//---------------------------------------------------------------------------
string *parse_command_adjectiv_id_list ()

// Return generic adjective ids.
// If there are non (like here), return some junk which islikely never
// typed.

{
  return ({ "iffish" });
}


//---------------------------------------------------------------------------
string *parse_command_prepos_list ()

// Return common prepositions.

{
  return ({
      "in", "from", "on", "under", "behind", "of", "for", "to",
      "with", "at", "off", "out", "down", "up", "around", "over",
      "into", "about", "inside",
  });
}


//---------------------------------------------------------------------------
string parse_command_all_word ()

// Return the one(!) 'all' word.

{
  return "all";
}

