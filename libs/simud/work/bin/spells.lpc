#include <const.h>
#include <magic.h>

string mana_color(string type) {
  switch (type) {
    case "spirit": return "~CBRT"; // white
    case "dark": return "~[050"; // dark magenta
    case "fire": return "~[090"; // bright red
    case "earth":return "~[030"; // brown
    case "ice":  return "~[140"; // bright cyan
    case "wind": return "~[100"; // bright green
    case "order":return "~[070"; // light gray
    case "chaos":return "~[130"; // bright magenta
    case "water":return "~[100"; // bright blue
    case "lightning":return "~[110"; // yellow
  }
  return "~[151";	// oops!
}

int main() {
  string buf = "~CTITYou know the following spells:~CDEF";
  string line;
  mapping spells = this_player()->query_known_spells();
  if (sizeof(spells) == 0) {
    msg("You don't know any spells yet.");
    return 1;
  }
  if (member(spells, 0))
    spells -= ([ 0 ]);
  foreach ( line : sort_array(m_indices(spells), #'>) ) {
    string spell, type;
    int cost;
    spell = MAGIC_DAEMON->query_spell(line);
    if (!spell) {
      spells -= ([ line ]);
      msg("~CTITYou had an unknown spell ~CREF"+line+"~CTIT, removing it.");
      this_player()->set_known_spells( spells );
      continue;
    }
    type = spell->query_type();
    cost = MAGIC_DAEMON->query_cost(type,spell->query_cost());
    buf += "\n  "+mana_color(type)+pad(line,25,JUST_LEFT)+" "+pad(cost+"",3,JUST_RIGHT)+" "+pad(type,12,JUST_LEFT)+"~CDEF ["+spell->query_level()+"] ";
    if (this_player()->query_level() >= WIZLEVEL)
      buf += "("+pad(sprintf("%.2f",to_float(spells[line])),6,JUST_RIGHT)+")";
  }
  msg(buf);
  return 1;
}
