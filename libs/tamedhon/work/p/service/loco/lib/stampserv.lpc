#define M_NR 0
#define M_SIZE 1
#define M_PRICE 2
#define M_NAME 3
#define M_SHORT 4
#define M_LONG 5

#define SAVE save_object(object_name(this_object()))
#define SECURITY (member(({"loco","cadra"}),geteuid(this_interactive()))!=-1)
mapping stamps;


create() {
  seteuid(getuid());
  stamps=([
           "10" : -1; 25; 10; "Steinbeisser";"einen Steinbeisser";
	   "Ein kleiner gruener Steinbeisser, wahrscheinlich Boings.",
           "20" : -1; 25; 20; "Urmel";"Professor Habakuk Tibatong und das Urmel";
	   "Der Professor macht ein nachdenkliches Gesicht.",
           "30" : -1; 20; 30; "Friedhofs";"das Friedhofstor";
	   "Auch auf der Zeichnung wirkt es noch alt und strahlt eine etwas unheimliche Stimmung aus.",
           "40" : -1; 20; 40; "Nachtfall";"den Nachtfall";"",
           "50" : -1; 20; 50; "Port Vain";"den Marktplatz von Port Vain";
	   "Na ja, besonders interessant sieht er ehrlich gesagt nicht aus",
           "60" : -1; 16; 60; "Boing";"ein Portrait von Boing";"",
           "80" : -1; 16; 80; "Jof";"ein Portrait von Jof";"", 
           "100": -1; 20;100; "Rumata";"ein Portrait von Rumata";"",
           "150": -1; 12;150; "Hilbertturm";"den Hilbertturm";"Der Turm ist schlank und hoch und aus Stein gebaut.",
           "200": -1; 12;200; "Lofoten";"die Landschaft der Lofoten bei Svolvaer";
	   "Einfach faszinierend. Aber dieses winzige Bildchen kann es doch nur sehr schlecht wiedergeben",
           "300": -1; 10;300; "Schloss";"Zwackelmanns Schloss";"",
           "400": -1;  8;400; "Robin Hood";"ein Bild von Robin Hood und Marian";"",
           "500": -1;  8;500; "Koenigs";"die Insignien des Zwergenkoenigs";""
           ]);

  restore_object(object_name(this_object()));
}

string conv(string in) {
  if (in[0]=='@') return in[1..];
  return in;
}

QueryStampPrice(in) { 
  return stamps[conv(in),M_PRICE]; 
}
QueryStampSize(in) {
  return stamps[conv(in),M_SIZE];
}
QueryStampName(in) {
  return stamps[conv(in),M_NAME];
}
QueryStampShort(in) {
  return stamps[conv(in),M_SHORT];
}
QueryStampLong(in) {
  return stamps[conv(in),M_LONG];
}

QueryStampList() {
  mixed list;
  int i;
  list=m_indices(stamps);
  for (i=sizeof(list)-1;i>=0;--i) if (!stamps[list[i],M_NR]) list=list-({list[i]});
  list=sort_array(list,"comp_price",this_object());
  return list;
}

QueryFullStampList() {
  mixed list;
  int i;
  list=sort_array(m_indices(stamps),"comp_price",this_object());
  return list;
}

comp_price(a,b) {
  return (stamps[a,M_PRICE]>stamps[b,M_PRICE]);
}

IssueStamp(string index,int sheets,int size,int price,string name,string short,string long) {
  if (!SECURITY) return;
  if (stamps[index]) return write("Index gibts schon.\n");
  stamps+=([index:sheets;size;price;name;short;long]);
  SAVE;
  return index;
}

PrintSheet(index) {
  if (!SECURITY) return;
  stamps[index,M_NR]++;
  return 1;
}

DeleteStamp(index) {
  if (!SECURITY) return;
  stamps=m_delete(stamps,index);
  SAVE;
  return index;
}

OrderSheet(index) {
  if (!stamps[index,M_NR]) return notify_fail("Diese Marke ist ausverkauft.\n");
  if (stamps[index,M_NR]>0) stamps[index,M_NR]--;
  SAVE;
  return stamps[index,M_SIZE];
}

