mapping lightsaber_color_list = ([
   "blue" : "%^BLUE%^blue",
   "bright blue" : "%^BOLD%^%^BLUE%^bright blue",
   "icy blue" : "%^BOLD%^%^CYAN%^icy blue",
   "cyan" : "%^CYAN%^cyan",
   "green" : "%^GREEN%^green",
   "bright green" : "%^BOLD%^%^GREEN%^bright green",
   "magenta" : "%^MAGENTA%^magenta",
   "violet" : "%^MAGENTA%^violet",
   "orange" : "%^ORANGE%^orange",
   "pink" : "%^BOLD%^%^MAGENTA%^pink",
   "red" : "%^RED%^red",
   "blood red" : "%^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d",
   "bright red" : "%^BOLD%^%^RED%^bright red",
   "rainbow" : "%^BOLD%^RED%^r%^RESET%^%^ORANGE%^a%^RESET%^%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BOLD%^%^BLUE%^o%^MAGENTA%^w%^RESET%^",
   "silver" : "%^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r",
   "yellow" : "%^YELLOW%^yellow",
   "viridian" : "%^CYAN%^v%^GREEN%^i%^CYAN%^r%^GREEN%^i%^CYAN%^d%^GREEN%^i%^CYAN%^a%^GREEN%^n",
   "bright viridian" : "%^BOLD%^%^CYAN%^b%^GREEN%^r%^CYAN%^i%^GREEN%^g%^CYAN%^h%^GREEN%^t %^CYAN%^v%^GREEN%^i%^CYAN%^r%^GREEN%^i%^CYAN%^d%^GREEN%^i%^CYAN%^a%^GREEN%^n",
   "white" : "%^RESET%^white",
   "blinding white" : "%^RESET%^%^BOLD%^blinding white",
]);

string get_lightsaber_color_code(string color)
{
   if (lightsaber_color_list[color])
   {
      return lightsaber_color_list[color];
   }

   return color;
}

string *get_lightsaber_color_list()
{
   return keys(lightsaber_color_list);
}