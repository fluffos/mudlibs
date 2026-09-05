/* component stuff */
mapping component;

void reset(int arg)
{
    if(arg) return;
component = (["acid":0, "adder's venom":0, "arrow":0, "bell":0,
              "chalk":0, "crystal bead":0, "diamond":0, "dust":0,
              "fan":0, "feather":0, "fire fly":0, "flint":0,
              "glass bead":0, "granite":0, "green mold":0,
              "ice cube":0, "iron rod":0, "mercury":0,
              "moldy bread":0, "needle":0, "oil":0,
              "olive branch":0, "parchment":0, "pencil":0,
              "pork rind":0, "powdered iron":0, "spider web":0,
              "sulphur":0, "thread":0, "vampire blood":0,
              "vial of blood":0,
            ]);
}

query_quantity(str) { return component[str]; }
add_quantity(string str, int amount) { component[str] += amount; }
subtract_quantity(string str, int amount) {
  component[str] -= amount;
  if (component[str] < 0) component[str] = 0;
}

