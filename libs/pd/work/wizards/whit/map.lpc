#include <std.h>
#include <daemons.h>

inherit OBJECT;

#define ALPHABET ({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"})

void create() {
   ::create();
   set_name("map");
   set_short("map");
}

void init() {
   ::init();
   add_action("show", "show");
}

int show() {
   int i, x, *c;
   string sym, out="", *b, *d;
   mapping a=([]);
   c=copy(environment(this_player())->query_coords());
   if(!c) return notify_fail("Your not in the sky.");
   c[0]=c[0]+4;
   c[1]=c[1]-2;
   for(i=0; i<5; i++) {
//     a[i]= "("+(c[0]+i)+", "+c[1]+")";
    
     a[i]=SKY_D->get_line( ({ c[0], c[1]+i }), 9);
//write(a[i]);
   }
   i=sizeof(a);
   a[2][4..4]="*";
   for(i=0; i<sizeof(a); i++) 
     out += a[i]+"\n";
   b=explode(out, "\n");
   i=sizeof(b);
   d=({});
   while(i--) {
     x=sizeof(b[i]);
     sym="";
     while(x--)
       sym += b[i][x..x];
     b[i]=sym;
   }
   out=implode(b, "\n");
   i=sizeof(ALPHABET);
   while(i--) {
     out=replace_string(out, ALPHABET[i], "^");
   }
   out=replace_string(out, "^", "%^MAGENTA%^%^BOLD%^^%^RESET%^");
   out=replace_string(out, "+", "%^YELLOW%^+%^RESET%^");
   out=replace_string(out, "*", "%^GREEN%^%^BOLD%^*%^RESET%^");
   out=replace_string(out, "-", "%^BOLD%^%^CYAN%^+%^RESET%^");
   out=replace_string(out, "%%", "%^BOLD%^%^BLACK%^+%^RESET%^");
   out=replace_string(out, "#", "%^CYAN%^+%^RESET%^");
   write(out);
   return 1;
}

